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
        ListNode*Dummy=new ListNode();
        ListNode*first=Dummy;
        int carry=0;
        while(l1 && l2){
            int sum=l1->val+l2->val+carry;
            if(sum>9){
                sum%=10;
                carry=1;
            }else{
                carry=0;
            }
            ListNode*node=new ListNode(sum);
            first->next=node;
            first=node;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1){
            int sum=l1->val+carry;
            if(sum>9){
                sum%=10;
                carry=1;
            }else{
                carry=0;
            }
            ListNode*node=new ListNode(sum);
            first->next=node;
            first=node;
            l1=l1->next;
        }
        while(l2){
            int sum=l2->val+carry;
            if(sum>9){
                sum%=10;
                carry=1;
            }else{
                carry=0;
            }
            ListNode*node=new ListNode(sum);
            first->next=node;
            first=node;
            l2=l2->next;
        }
        if(carry){
            ListNode*node=new ListNode(carry);
            first->next=node;
            first=node;
        }
        return Dummy->next;

    }
};