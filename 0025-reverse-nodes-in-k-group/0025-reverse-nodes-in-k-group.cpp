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
        
        while(k>1 && temp!=NULL){
            k--;
            temp=temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp!=NULL){
            ListNode* kthNode=findkth(temp, k);
            if(kthNode==NULL){
                if(prev)
                    prev->next=temp;
                break;
            }
            ListNode* front=kthNode->next;
            kthNode->next=NULL;
            reverse(temp);
            if(temp==head){
                head=kthNode;  
            }
            else{
                prev->next=kthNode;
            }
            prev=temp;
            temp=front;
        }
        return head;
    }
};