#include <iostream>
#include <vector>


class BinaryHeap{

public:

BinaryHeap( int capacity = 100 );
BinaryHeap( const std::vector<int> & items );

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
    for (; x < array[hole/2]; hole/=2) // if new_val is less than current location, move hole up the tree
        array[hole] = std::move(array[hole/2]);
    array[hole] = std::move(array[0]);
    
}

// void insert( int && x );
void deleteMin( ){
    if (isEmpty()){
        return;
    }
    array[1] = std::move(array[currentSize--]);
    percolateDown(1);
}

void deleteMin( int & minItem ){

}

void percolateDown( int hole );

void buildHeap( );

// void makeEmpty( ); // repeatedly call deleteMin until size == 0

private:
int currentSize; // Number of elements in heap
std::vector<int> array; // The heap array

};