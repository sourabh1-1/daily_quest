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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head)     {
        vector<vector<int>> ans(m, vector<int> (n, -1));
        ListNode* temp=head;
        int row=0;
        int col=0;
        while(temp){
            for(int i=col;i<n;i++){
                if(temp){
                    ans[row][i]=temp->val;
                    temp=temp->next;
                }
                else
                    break;
            }
            row++;
            for(int i=row;i<m;i++){
                if(temp){
                    ans[i][n-1]=temp->val;
                    temp=temp->next;
                }
                else
                    break;
            }
            n--;
            for(int i=n-1;i>=col;i--){
                if(temp){
                    ans[m-1][i]=temp->val;
                    temp=temp->next;
                }
                else
                    break;
            }
            m--;
            for(int i=m-1;i>=row;i--){
                if(temp){
                    ans[i][col]=temp->val;
                    temp=temp->next;
                }
                else
                    break;
            }
            col++;
        }
        return ans;
    }
};