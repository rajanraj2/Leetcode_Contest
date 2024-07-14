// Link - https://leetcode.com/contest/weekly-contest-406/problems/delete-nodes-from-linked-list-present-in-array/
// Delete Nodes From Linked List Present in Array


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
        set<int> st(nums.begin(), nums.end());
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        ListNode* temp = head;
        
        while (temp != NULL) {
            if (st.find(temp->val) != st.end()) {
                prev->next = temp->next;
            }
            else {
                prev = temp;
            }
            temp = temp->next;
        }
        return dummy.next;
    }
};