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
        if(!head) return head;
        
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* firstEven = even;
        int pos = 1;
        
        while(odd && even){
            if(pos++ % 2){                
                odd->next = even->next;
                if(odd->next) odd = odd->next;
            }else{
                even->next = odd->next;
                even = even->next;
            } 
        }
        
        odd->next = firstEven;
        
        return head;
    }
};