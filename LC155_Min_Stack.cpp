#include <iostream>
#include <vector>
#include <list>

class MinStack {
public:
    std::vector<int> stack_vector;
    std::list<int> ordered_list;

    MinStack() {
    }
    
    void push(int val) {
        stack_vector.push_back(val);
        int min = ordered_list.front();
        int max = ordered_list.back();

        if (val <= min){
            ordered_list.push_front(val);
        }
        else{
            ordered_list.push_back(val);
        }
    }

    int top() {
        stack_vector.at(stack_vector.size()-1);
    }
    
    void pop() {
        int tmp = this->top();
        stack_vector.pop_back();
        if (tmp == ordered_list.front()){
            ordered_list.pop_front();
        }
        else{
            ordered_list.pop_back();
        }
    }
    
    int getMin() {
        return ordered_list.front();
        
    }
};


int main(){
    MinStack* obj = new MinStack();
    obj->push(2);
    obj->pop();
    int param_3 = obj->top();
    int param_4 = obj->getMin();
}