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
        ListNode*head= new ListNode(0);
        ListNode*tail=head;
        int c=0;
        while(l1 && l2){
            int a=l1->val;
            int b=l2->val;
            int sum=a+b+c;
            c=sum/10;
            ListNode*newnode=new ListNode(sum%10);
            head->next=newnode;
            head=head->next;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1){
            int sum=l1->val+c;
            c=sum/10;
            ListNode*newnode=new ListNode(sum%10);
            head->next=newnode;
            head=head->next;
            l1=l1->next;
        }
        while(l2){
            int sum=l2->val+c;
            c=sum/10;
            ListNode*newnode=new ListNode(sum%10);
            head->next=newnode;
            head=head->next;
            l2=l2->next;
        }
        if(c!=0){
            ListNode*newnode=new ListNode(c);
            head->next=newnode;
            head=head->next;
        }
        return tail->next;
    }
};