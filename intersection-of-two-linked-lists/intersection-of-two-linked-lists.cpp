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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1=headA;
        ListNode *p2=headB;
        int len1=0,len2=0;
        
        ListNode * len=headA;
        while(len!=NULL){
            len1++;
            len=len->next;
            
        }
        len=headB;
         while(len!=NULL){
            len2++;
            len=len->next;
            
        }
        int diff=abs(len1-len2);
        
        if(len1>len2){
            for(int i=0;i<diff;i++){
                p1=p1->next;
            }
        }else{
            for(int i=0;i<diff;i++){
                p2=p2->next;
            }
        }
        while(p1!=NULL and p2!=NULL){
            if(p1==p2){
                return p2;
            }
            p1=p1->next;
            p2=p2->next;
        }
        return NULL;
    }
};