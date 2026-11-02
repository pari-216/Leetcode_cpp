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
        int lA=0, lB=0;
        ListNode* ptrA = headA;
        ListNode* ptrB=  headB;
        while(ptrA!=nullptr ){
            lA++;
            ptrA= ptrA->next;
        }
        while(ptrB!=nullptr ){
            lB++;
            ptrB= ptrB->next;
        }
        ptrA=headA;
        ptrB=headB;
        if(lA>lB){
            for(int i=0; i<(lA-lB); i++){
                ptrA=ptrA->next;
            }
        }
        else{
            for(int i=0; i<(lB-lA); i++){
                ptrB=ptrB->next;
            }
        }
        while(ptrA!=ptrB){
            ptrA=ptrA->next;
            ptrB=ptrB->next;
        }
        return ptrA;
    }
};