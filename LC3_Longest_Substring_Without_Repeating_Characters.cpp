/*

Given a string s,
find the length of the longest substring without repeating characters.

*/


#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_set<char> hs;

        int l,r = 0;
        int max_length = 0;

        while (r < s.length()){

            // if element doesn't exist in set, add it
            if (hs.count(s[r]) == 0){
                hs.insert(s[r]);
                // check if current size of set is greater than max_length, update
                if (hs.size() > max_length){
                    max_length = hs.size();
                }
                r++; // iterate right pointer since we have substr of unique elements so far
            }
            else{ // if current element already exists in set, remove leftmost element
                hs.erase(s[l]);
                l++;
            }

        }
        return max_length;
        
    }
};

int main(){
    string str1 = "abcabcbb"; // answer: "abc" with length of 3
    string str2 = "bbbbb"; // answer: "b" with length of 1
    string str3 = "pwwkew"; // answer: "wke" with length of 3

    Solution s;

    cout << s.lengthOfLongestSubstring(str1) << endl;
    cout << s.lengthOfLongestSubstring(str2) << endl;
    cout << s.lengthOfLongestSubstring(str3) << endl;

}