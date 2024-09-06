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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> st(nums.begin(), nums.end());
        ListNode* temp=head;
        while(st.count(temp->val)){
            temp=temp->next;
        }
        head=temp;
        while(temp && temp->next){
            if(st.count(temp->next->val))
                temp->next=temp->next->next;
            else
                temp=temp->next;
        }
        return head;
    }
};