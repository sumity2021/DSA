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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k=lists.size();
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;
        for(int i=0; i<k; i++){
            if(lists[i]!=NULL) pq.push({lists[i]->val,lists[i]});
        }
        ListNode*first=new ListNode();
        ListNode*head=first;
        while(!pq.empty()){
            auto [val,node]=pq.top();
            pq.pop();
            if(node->next) pq.push({node->next->val,node->next});
            first->next=node;
            first=first->next;
            first->next=NULL;
        }
        return head->next;
    }
};