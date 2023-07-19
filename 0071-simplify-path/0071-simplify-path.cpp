class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        string ans="";
        for(int i=0;i<path.length();i++){
            if(path[i]=='/')
                continue;
            string temp="";
            while(i<path.length() && path[i]!='/'){
                temp+=path[i];
                i++;
            }
            if(temp==".")
                continue;
            else if(temp==".."){
                if(!s.empty())
                    s.pop();
            }
            else
                s.push(temp);
        }
        while(!s.empty()){
            ans="/"+s.top()+ans;
            s.pop();
        }
        if(ans=="")
            return "/";
        return ans;
    }
};