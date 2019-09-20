//https://leetcode.com/problems/add-two-numbers/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *r = new ListNode(0), *atual;
        
        
        atual = r;
        
        
        int vai = 0;
        
        while(l1 != NULL && l2 != NULL)
        {
            int x = l1->val + l2->val + vai;
            
            vai = 0;
            
            if(x > 9)
            {
                vai = 1;
                x -= 10;
            }
            
            
            atual->val = x;
            atual->next = new ListNode(-1);
            
            l1 = l1->next;
            l2 = l2->next;
            atual = atual->next;
        }
        
        while(l1 != NULL)
        {
            int x = l1->val + vai;
            
            vai = 0;
            
            if(x > 9)
            {
                x -= 10;
                vai = 1;
            }
            
            atual->val = x;
            atual->next = new ListNode(0);
            
            l1 = l1->next;
            
            atual = atual->next;
        }
        
  
        while(l2 != NULL)
        {
            int x = l2->val + vai;
            
            vai = 0;
            
            if(x > 9)
            {
                x -= 10;
                vai = 1;
            }
            
            atual->val = x;
            atual->next = new ListNode(0);
            
            l2 = l2->next;
            
            atual = atual->next;
        }
        
        if(vai)
        {
            atual->val = 1;
            atual->next = new ListNode(0);
        }
        
        ListNode *ant = r, *i = r;
        
        while(i != NULL)
        {
            if(i->next == NULL) break;
            
            ant = i;
            i = i->next;
        }
        
        ant->next = NULL;
        //if(ant == r) r = NULL;
        
        return r;
    }
};