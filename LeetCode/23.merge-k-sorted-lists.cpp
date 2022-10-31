/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 */

// @lc code=start
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
struct compare
{
    bool operator()(const ListNode *a, const ListNode *b)
    {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        for (auto curr : lists)
            if (curr)
                pq.push(curr);

        ListNode *ans = NULL, *last = NULL;

        while (!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();

            if (ans == NULL)
                ans = last = curr;
            else
            {
                last->next = curr;
                last = last->next;
            }

            if (curr->next != NULL)
                pq.push(curr->next);
        }

        return ans;
    }
};
// @lc code=end

