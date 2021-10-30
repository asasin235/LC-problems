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
    int lenght(ListNode *head){
        int len = 0;

	ListNode* temp = head;

	while(temp!=NULL){
		len++;
		temp = temp->next;
	}

	return len;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA=lenght(headA);
        int lenB=lenght(headB);
        cout<<lenA<<" "<<lenB<<endl;
        
        int diff=lenB-lenA;
        if(diff>0)
            return helper(diff,headB,headA);
        else
            return helper(diff*-1,headA,headB);
        
        
        
    }
    
    ListNode * helper(int diff,ListNode * longer,ListNode *shorter){
        ListNode *p1=longer,*p2=shorter;
        cout<<diff<<endl;
        for(int i=0;i<diff;i++){
            p1=p1->next;
        }
        cout<<p1->val<<endl;
        while(p1!=NULL and p2!=NULL){
            cout<<p1->val<<" "<<p2->val<<endl;
            if(p1==p2){
                return p2;
            }
            p1=p1->next;
            p2=p2->next;
        }
        return NULL;
    }
};