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
    //approaches 
    //insertion
    //merge
    ListNode* merge(ListNode *l,ListNode *r){
        ListNode *dummy=new ListNode(0);
        ListNode *t=dummy;
        while(l && r){
            if(l->val<=r->val){
                t->next=l;
                l=l->next;
            }else{
                t->next=r;
                r=r->next;
            }
            t=t->next;
        }

        t->next= (l)?l:r;
        return dummy->next; 
    }
    ListNode* getMid(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;

        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        } 
        return slow; 
    }
    
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
            return head;

        ListNode *mid=getMid(head);
        ListNode *left=head;
        ListNode *right=mid->next;
        mid->next=NULL;
       
       
        left=sortList(left);
        right=sortList(right);
        return merge(left,right);
    }
};