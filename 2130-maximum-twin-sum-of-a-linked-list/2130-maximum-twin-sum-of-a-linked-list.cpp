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
    int pairSum(ListNode* head) {
        vector<int> arr;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            arr.push_back(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }

        if (fast) { // odd length
            slow = slow->next;
        }

        int i = arr.size() - 1;
        int ans = 0;

        while (slow) {
            ans = max(ans, arr[i] + slow->val);
            i--;
            slow = slow->next;
        }

        return ans;
    }
};