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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k);
        int size=0;
        ListNode* cur=head;
        while(cur!=nullptr) {
            size++;
            cur=cur->next;
        }
        int split=size/k;
        int remPart=size%k;
        cur=head;
        ListNode* prev=cur;
        for(int i=0;i<k;i++) {
            ListNode* newPart=cur;
            int curSize=split;
            if(remPart>0){
                remPart--;
                curSize++;
            }
            int j=0;
            while(j<curSize){
                prev=cur;
                if(cur!=nullptr)
                    cur=cur->next;
                j++;
            }
            if(prev!=nullptr)
                prev->next=nullptr;
            ans[i]=newPart;
        }
        return ans;
    }
};