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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)
            return head;
        ListNode* temp=head;
        int n=0;
        while(temp!=NULL){
            n++;
            temp=temp->next;
        }
        k=k%n;
        if(k==0)
            return head;
        temp=head;
        while(n != k+1 && temp!=NULL){
            n--;
            temp=temp->next;
        }
        ListNode* front=temp->next;
        temp->next=NULL;
        temp=front;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=head;
        return front;
    }
};