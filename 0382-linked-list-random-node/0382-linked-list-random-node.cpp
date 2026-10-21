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
    int cap;
    ListNode*head;
    Solution(ListNode* head) {
        ListNode*temp=this->head=head;
        cap=0;
        while(temp){
            cap++;
            temp=temp->next;
        }
    }
    int randomINT(int l,int r){
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int>int_dist(l,r);
        return int_dist(gen);
    }
    int getRandom() {
        
        int r=randomINT(0,cap-1);
        ListNode* temp=head;
        while(r--){
            temp=temp->next;
        }
        return temp->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */