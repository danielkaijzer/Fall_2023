/**
 * @file LC929_Unique_Email.cpp
 * @author Daniel Kaijzer
 * @brief 
 * @version Solution v1
 * @date 2023-10-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>
#include <unordered_set>

int numUniqueEmails(std::vector<std::string>& emails) 
{
    int count=0;

    std::unordered_set<std::string> hashset;

    for (auto itr = emails.begin(); itr != emails.end(); itr++)
    {
        std::string current = "";

        bool ignore = false;
        bool domain = false;

        // remove variations to make email verifiably unique
        for (auto c : *itr){
            if (c != '.' && domain == false){ // remove dots
                if (c != '+' && c!= '@' && ignore == false){
                    current += c;
                }
                else if (c == '+'){
                    ignore = true;
                }
                else if (c == '@'){
                    ignore = false;
                    domain = true;
                    current += c;
                }
            }
            else if (domain == true){
                current += c;
            }
        }

        if (hashset.count(current) == 0){
            hashset.insert(current);
        }

        std::cout << current << std::endl;
    }

    return hashset.size();
    
}

int main(){

    
    std::vector<std::string> emails1{"test.email+alex@leetcode.com", "test.email@leetcode.com"};

    std::cout << numUniqueEmails(emails1) << std::endl; // answer should be 1

    return 0;
}