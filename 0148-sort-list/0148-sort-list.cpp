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
    ListNode* merge(ListNode* first, ListNode* second){
        ListNode* newHead=new ListNode(-1);
        ListNode* temp=newHead;
        while(first!=NULL && second!=NULL){
            if(first->val<second->val){
                temp->next=first;
                first=first->next;
            }
            else{
                temp->next=second;
                second=second->next;
            }
            temp=temp->next;
        }
        if(first!=NULL)
            temp->next=first;
        else
            temp->next=second;
        return newHead->next;
    }
    ListNode* middle(ListNode* start){
        if(start==NULL || start->next==NULL)
            return start;
        ListNode* slow=start;
        ListNode* fast=start->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* middleNode=middle(head);
        ListNode *firstHalf=head;
        ListNode* secondHalf=middleNode->next;
        middleNode->next=NULL;
        firstHalf=sortList(firstHalf);
        secondHalf=sortList(secondHalf);
        return merge(firstHalf, secondHalf);
    }
};