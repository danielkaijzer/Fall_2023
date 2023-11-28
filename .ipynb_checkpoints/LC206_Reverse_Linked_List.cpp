
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include <iostream>
#include <stack>

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        std::stack<int> s;

        ListNode* temp = head;
        
        while (temp != nullptr){
            s.push(temp->val);
            temp = temp->next;
        }
        
        ListNode* temp2 = head;
        
        while (head != nullptr){
            head->val = s.top();
            s.pop();
            head = head->next;
        }

        return temp2;

    }
};