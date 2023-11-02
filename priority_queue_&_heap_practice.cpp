#include <iostream>
#include <vector>
#include <stdexcept>


class BinaryHeap{

public:

BinaryHeap( int capacity = 100 );
BinaryHeap( const std::vector<int> & items ){
    for (int i = 0; i < items.size(); ++i){
        array[i+1] = items[i];
    }
    buildHeap();
}

bool isEmpty( ) const{
    return (currentSize == 0);
}

// const int & findMin( ) const;

void insert( const int & x ){
    // resize for new addition, remember array.size() 
    // has an extra empty spot at start,
    // so it's slightly too large
    if(currentSize == array.size() - 1)
        array.resize( array.size()*2);

    // percolate up
    int hole = ++currentSize; // make hole at new, empty last position
    int copy = x; // make a copy of new value to be added

    array[0] = std::move(copy); // temporarily place new value at 0, which isn't used

    // if new_val is less than current location, move hole up the tree
    for (; x < array[hole/2]; hole/=2) // after each iteration of loop we move hole to parent of previous hole location
        
        // move current parent value into current hole, 
        // so we can move hole up without deleting value previously there
        array[hole] = std::move(array[hole/2]); 
        
    array[hole] = std::move(array[0]);
    
}

// void insert( int && x );
void deleteMin( ){
    if (isEmpty()){
        throw std::underflow_error("List is empty");
    }
    array[1] = std::move(array[currentSize--]);
    percolateDown(1);
}

void deleteMin( int & minItem ){
    if (isEmpty()){
        throw std::underflow_error("List is empty");
    }

    minItem = std::move(array[1]); // new minItem is taken from root
    array[1] = std::move(array[currentSize--]); // move last element to root
    percolateDown(1); // create hole at root
}

// in percolateDown, the hole moves down from root 
// until it reaches correct location
void percolateDown( int hole ){
    int child;
    int tmp = std::move(array[hole]);

    for (; hole * 2 <= currentSize; hole = child){
        child = hole * 2;
        if (child != currentSize && array[child+1] < array[child]){
            ++child;
        }
        if (array[child] < tmp){
            array[hole] = std::move(array[child]);
        }
        else
            break;
    }
    array[hole] = std::move(tmp);
}



/**
 * Establish heap order property from an arbitrary
 * arrangement of items. Runs in linear time.
 */
    // we iteratively call percolate down
    // starting from rightmost/last parent node, 
    // which is also the first non-leaf node from right end
    // then we keep moving left towards root
    // remember root is at 1 not 0 in this implementation
void buildHeap( ){
    for (int i = currentSize/2; i > 0; --i){
        percolateDown(i);
    }
}

// void makeEmpty( ); // repeatedly call deleteMin until size == 0

private:
int currentSize; // Number of elements in heap
std::vector<int> array; // The heap array

};