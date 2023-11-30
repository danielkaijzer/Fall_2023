
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

        if (head == nullptr || head->next == nullptr){
            return head;
        }

        ListNode * newEnd = NULL;
        ListNode * newHead = reverseList(head->next);
        head->next->next = head;
        head->next = newEnd;
        return newHead;
    }
};

int main(){
Solution s;

    // Create a linked list
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Reverse the linked list
    ListNode* reversedHead = s.reverseList(head);

    // Print the reversed linked list
    while (reversedHead != nullptr){
        std::cout << reversedHead->val << " ";
        reversedHead = reversedHead->next;
    }

    return 0;
}