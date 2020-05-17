//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3331/
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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL)
            return head;
        ListNode *odd = head;
        ListNode *even = head->next;
        
        ListNode *mergeHead = even;
            
        while(1){
            if(odd==NULL || even==NULL || even->next==NULL){
                odd->next = mergeHead;
                break;
            }
            odd->next = even->next;
            odd = even->next;
            if (odd->next == NULL)  
            {  
                even->next = NULL;  
                odd->next = mergeHead;  
                break;  
            }  
            even->next = odd->next;
            even = odd->next;
            
        }
        return head;
    }
};
