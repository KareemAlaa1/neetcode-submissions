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
    void reorderList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;

        int len = 0;
        while(curr){
            len++;
            curr = curr->next;
        }
        curr = head;
        for(int i=0;i<(len+1)/2;i++){
            prev = curr;
            curr = curr->next;
        }
        prev->next = nullptr;
        prev = nullptr;
        while(curr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        ListNode* ans = new ListNode(0);
        curr = ans;
        while(prev){
            curr->next = head;
            head = head->next;
            curr = curr->next;

            curr->next = prev;
            prev = prev->next;
            curr = curr->next;
        }
        if(head)curr->next = head;
        head = ans->next;

    }
};
