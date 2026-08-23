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
    ListNode* middleNode(ListNode* head) {
        int count = 0;
        ListNode* temp = head;
        while (temp != NULL ) {
            count++;
            temp = temp -> next;
        }
        int middleNodes;
        if ( count % 2 == 0 ) {
            middleNodes = ( count / 2 ) + 1;
        }
        else {
            middleNodes = ( count / 2 ) + 1;
        }
        temp = head;
        int cnt = 0;
        while ( temp != NULL ) {
           cnt ++;
           if ( cnt == middleNodes ) break;
           temp = temp -> next;
        }
        return temp;
    }
};