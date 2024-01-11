#include <iostream>
#include <vector>

// everytime you find an element equal to val, you swap
// so that all deleted elements go to back of array

using namespace std;

int removeElement(vector<int>& nums, int val) {

    int k = 0;


    for (int i = 0; i < nums.size(); ++i){
        if (nums[i] != val){
            nums[k] = nums[i];
            k++;
        }
    }
    return k;
}

int main(){
    vector<int> n{1,2,3,4,5,1,1,1};

    std::cout << removeElement(n,1) << endl;
    return 1;
}