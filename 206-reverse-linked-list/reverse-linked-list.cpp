/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *curr = head, *prev = nullptr, *forword = nullptr;
        while(curr){
            forword=curr->next;
            curr->next = prev;
            prev = curr;
            curr = forword;
        }
        head = prev;
        return head;
    }
};