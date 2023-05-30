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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr && list2 == nullptr) return nullptr;
        bool moveFirst = list2 == nullptr || (list1 != nullptr && list1->val < list2->val);
        
        if(moveFirst) return new ListNode(list1->val, mergeTwoLists(list1->next, list2));
        else return new ListNode(list2->val, mergeTwoLists(list1, list2->next));
    }
};