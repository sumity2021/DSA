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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode*dummy=new ListNode(0,head);
        unordered_set<int>s(nums.begin(),nums.end());
        ListNode*prev=dummy;
        while(head){
            if(s.count(head->val)){
                prev->next=head->next;
            }else{
                prev=prev->next;
            }
            head=head->next;
        }
        return dummy->next;

    }
};