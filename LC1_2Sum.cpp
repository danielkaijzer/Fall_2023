#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    // add all unique nums to hashmap

    unordered_map<int,int> hashmap; // key: num, val: index
    
    // iterate through values and check if complement exists in hash map
    for (int i = 0; i < nums.size(); ++i){
        int complement = target - nums.at(i);


        if (hashmap.count(complement) > 0){
            return {hashmap[complement], i};
        }
        // if complement isn't in our hashmap yet,
        // then add current element to hashmap
        if (hashmap.count(nums.at(i)) < 0){
            hashmap.insert(make_pair(nums.at(i),i));
        }
    }
    // if there is no solution, return empty
    return {};
}

int main(){

}