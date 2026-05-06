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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = l1;
        ListNode* prev = l1;
        int carry = 0;
        while(l1&&l2){
            ListNode* tempL1 = l1->next;
            ListNode* tempL2 = l2->next;

            int temp = carry + l1->val + l2->val;
            l1->val = temp%10;
            if(temp > 9)carry=1;
            else carry=0;
            prev = l1;
            l1 = tempL1;
            l2 = tempL2;
        }

        while(l1){
            ListNode* tempL1 = l1->next;
            int temp = carry + l1->val;
            l1->val = temp%10;
            if(temp > 9)carry=1;
            else carry=0;
            prev = l1;
            l1 = tempL1;
        }

        while(l2){
            ListNode* tempL2 = l2->next;
            int temp = carry + l2->val;
            l2->val = temp%10;
            prev->next = l2;
            l1 = l2;
            if(temp > 9)carry=1;
            else carry=0;
            prev = l1;

            l2 = tempL2;
            l1 = l1->next;
        }

        if(carry>0){
            ListNode* temp = new ListNode(1);
            prev->next = temp;
        }
        return ans;
    }
};
