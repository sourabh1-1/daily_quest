/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minSwaps(vector<int>arr, int n)
    {
        vector<pair<int,int>>ve;
        int i;
        for(i=0;i<n;i++)
        {
            ve.push_back({arr[i],i});
        }
        sort(ve.begin(),ve.end());
        
        int cnt=0;
        for(i=0;i<n;i++)
        {
            if(ve[i].second==i) continue;
            else
            {
                cnt++;
                swap(ve[i],ve[ve[i].second]);
                i--;
            }
        }
        return cnt;
    }
    int minimumOperations(TreeNode* root) {
        queue<TreeNode *>q;
        q.push(root);
        int ans=0;
        
        while(!q.empty())
        {
            vector<int>tempp;
            int sz=q.size();
            while(sz--)
            {
                TreeNode *curr=q.front();
                q.pop();
                tempp.push_back(curr->val);
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            int kk=tempp.size();
            ans+=minSwaps(tempp,kk);
        }
        return ans;
    }
};