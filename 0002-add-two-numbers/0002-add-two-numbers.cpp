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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        ListNode* newList=new ListNode(-1);
        ListNode* temp=newList;
        int carry=0;
        while(temp1!=NULL || temp2!=NULL){
            int value=carry;
            if(temp1)
                value+=temp1->val;
            if(temp2)
                value+=temp2->val;
            ListNode* newNode=new ListNode(value%10);
            carry=value/10;
            temp->next=newNode;
            temp=newNode;
            if(temp1)
                temp1=temp1->next;
            if(temp2)
                temp2=temp2->next;
        }
        if(carry==1){
            ListNode* newNode=new ListNode(1);
            temp->next=newNode;
        }
        return newList->next;
    }
};