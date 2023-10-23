/**
 * @file LC167_Two_Sum_II.cpp
 * @author Daniel Kaijzer
 * @brief 
 * @version 0.1
 * @date 2023-10-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>

std::vector<int> twoSum(std::vector<int>& numbers, int target){
    int start = 0;
    int end = numbers.size() -1;

    while (start < end){
        int sum = numbers[start] + numbers[end];
        if (sum == target){
            return{start+1, end+1};
        }
        else if(sum > target){
            end--;
        }
        else{
            start++;
        }
    }
    return{};

}

int main(){
    std::vector<int> nums{2, 7, 11, 15};
    int target = 9;

    std::vector<int> answer = twoSum(nums,target);

    for (auto n : answer){
        std::cout << n << std::endl;
    }

    return 0;
}