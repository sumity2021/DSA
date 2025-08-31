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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode*dummy=new ListNode(-101,head);
        ListNode*prev=dummy;
        while(head){
            int cnt=0;
            while(head->next && head->val==head->next->val){
                head=head->next;
                cnt++;
            }
            if(cnt){
                prev->next=head->next;
            }
            else{
                prev=head;
            }
            head=head->next;
        }
        return dummy->next;
    }
};