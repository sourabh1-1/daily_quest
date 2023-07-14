class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> li(26, 0);
        for (int i = 0; i < s.length(); i++){
            li[s[i] - 'a'] = i;
        }
        
        vector<bool> visited(26, false);
        stack<char> st;
        
        for (int i = 0; i < s.size(); i++) {
            int curr = s[i] - 'a';
            if (visited[curr]) continue;
            while(st.size() > 0 && st.top() > s[i] && i < li[st.top() - 'a']){
                visited[st.top() - 'a'] = false; 
                st.pop();
            }
            st.push(s[i]);
            visited[curr] = true;
        }
        
        string ans = "";
        while (st.size() > 0){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
