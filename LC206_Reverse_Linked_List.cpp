
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

        ListNode * prev = NULL;
        ListNode * cur = head;
        
        while (cur != nullptr){
            ListNode * next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};

int main(){
Solution s;

    // Create a linked list
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    // Reverse the linked list
    ListNode* reversedHead = s.reverseList(head);

    // Print the reversed linked list
    while (reversedHead != nullptr){
        std::cout << reversedHead->val << " ";
        reversedHead = reversedHead->next;
    }

    return 0;
}