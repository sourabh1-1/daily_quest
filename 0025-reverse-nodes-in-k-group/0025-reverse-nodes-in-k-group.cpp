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
    ListNode* reverse(ListNode* head){
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* newHead=reverse(head->next);
        ListNode* front=head->next;
        front->next=head;
        head->next=NULL;
        return newHead;
    }
    ListNode* findkth(ListNode* temp, int k){
        while(k>1 && temp->next!=NULL){
            k--;
            temp=temp->next;
        }
        return (k==1)?temp:NULL;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* dummy=new ListNode(-1);
        ListNode* prev=NULL;
        ListNode* front=NULL;
        int flag=0;
        while(temp!=NULL){
            ListNode* kthNode=findkth(temp, k);
            
            if(kthNode!=NULL){
                front=kthNode->next;
                kthNode->next=NULL;
                ListNode* newHead=reverse(temp);
                if(flag==0){
                    dummy->next=newHead;
                    flag=1;
                }
                else{
                    prev->next=newHead;
                }
                prev=temp;
                temp=front;
            }
            else{
                prev->next=temp;
                break;
            }
        }
        return dummy->next;
    }
};