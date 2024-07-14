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
        while(temp1!=NULL && temp2!=NULL){
            int value=temp1->val+temp2->val+carry;
            if(value>9){
                value=value%10;
                carry=1;
            }
            else
                carry=0;
            ListNode* newNode=new ListNode(value);
            temp->next=newNode;
            temp=newNode;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        while(temp1!=NULL){
            int value=temp1->val+carry;
            if(value>9){
                value=value%10;
                carry=1;
            }
            else
                carry=0;
            ListNode* newNode=new ListNode(value);
            temp->next=newNode;
            temp=newNode;
            temp1=temp1->next;
        }
        while(temp2!=NULL){
            int value=temp2->val+carry;
            if(value>9){
                value=value%10;
                carry=1;
            }
            else
                carry=0;
            ListNode* newNode=new ListNode(value);
            temp->next=newNode;
            temp=newNode;
            temp2=temp2->next;
        }
        if(carry==1){
            ListNode* newNode=new ListNode(1);
            temp->next=newNode;
        }
        return newList->next;
    }
};