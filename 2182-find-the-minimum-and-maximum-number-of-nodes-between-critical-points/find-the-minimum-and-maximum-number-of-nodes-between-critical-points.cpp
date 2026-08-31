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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next) return {-1, -1};
        ListNode* prev = nullptr;
        ListNode* present = head;
        vector<int>ans;
        int idx = 1;
        while (present->next) {
            if ( prev != nullptr ) {
                if ( prev -> val < present -> val && present -> next -> val < present -> val ) {
                    ans.push_back(idx);
                }
                else if ( prev -> val > present -> val && present -> next -> val > present -> val ) {
                    ans.push_back(idx);
                }
            }
            idx ++;
            prev = present;
            present = present -> next;
        }
        if ( ans.size() < 2 ) return { -1 , -1 };
        int mini = INT_MAX;
        for ( int i = 1 ; i < ans.size() ; i ++ ) {
          mini = min(mini, ans[i] - ans[i - 1]);
        }
        return {mini,ans.back() - ans.front()};
    }
};