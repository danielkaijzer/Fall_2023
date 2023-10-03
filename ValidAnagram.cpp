/**
 * @file ValidAnagram.cpp
 * @author your name (you@domain.com)
 * @brief First Solution to this Leetcode Problem
 * @version 0.1
 * @date 2023-10-02
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <unordered_map>

bool isAnagram(std::string s, std::string t) {
    std::unordered_map<char,int> hashmap;

    if (s.size() != t.size()){
        return false;
    }

    for (char c : s){
        if (hashmap.count(c) > 0){
            hashmap[c] += 1;
            // std::cout << hashmap[c];
        }
        else{
            hashmap.insert(std::make_pair(c,1));
        }
    }

    for (char c : t){
        if (hashmap.count(c) == 0){
            return false;
        }
        else if(hashmap[c] == 1){
            hashmap.erase(c);
        }
        else{
            hashmap[c] -= 1;
        }
    }
    return true;
}

int main(){
    std::string s = "ab";
    std::string t = "a";

    if (isAnagram(s,t)){
        std::cout << "True\n";
    }
    else{
        std::cout << "False\n";
    }
}