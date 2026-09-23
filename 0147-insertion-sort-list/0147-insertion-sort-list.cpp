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

    ListNode* insertionSortList(ListNode* head) {
        vector<ListNode*>l;
        ListNode* temp=head;
        while(temp){
            ListNode* next=temp->next;
            temp->next=nullptr;
            l.push_back(temp);
            temp=next;
        }
        sort(l.begin(),l.end(),
        [](ListNode* a,ListNode* b){
            return a->val<=b->val;
        });
        for(int i=0;i<l.size()-1;i++)l[i]->next=l[i+1];
        return l[0];

        
    }
};