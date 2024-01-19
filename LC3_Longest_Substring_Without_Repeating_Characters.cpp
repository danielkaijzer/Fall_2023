/*

Given a string s,
find the length of the longest substring without repeating characters.

*/


#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int start = 0;
        int end = 1;

        int temp_max = 0;
        int max_length = 0;

        while (end != s.size()-1){
            // check if chars at two ptr locations are same
            if (s[start] == s[end]){
                // if they are same, move start to location of end to restart subtr
                start = end;
                temp_max = 0;
            }
            // if chars not same keep advancing substr
                end++;
            

            temp_max = end - start; // get cur substr length

            // if current subtr is longest, update max_length
            if (temp_max > max_length){
                max_length = temp_max;
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