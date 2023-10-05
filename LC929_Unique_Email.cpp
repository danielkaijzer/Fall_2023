#include <iostream>
#include <vector>
#include <unordered_set>

int numUniqueEmails(std::vector<std::string>& emails) 
{
    for (auto itr = emails.begin(); itr != emails.end(); itr++)
    {
        std::cout << *itr << std::endl;
    }
    // remove variations

    // add email before @

    return 0;
    
}

int main(){
    std::vector<std::string> emails1{"test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"};

    std::cout << numUniqueEmails(emails1) << std::endl;

    return 0;
}