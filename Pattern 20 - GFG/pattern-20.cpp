//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printTriangle(int n) {
        // code here
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++)
                cout<<"*";
            for(int k=0;k<2*(n-i);k++)
                cout<<" ";
            for(int l=0;l<i;l++)
                cout<<"*";
            cout<<endl;
        }
        for(int i=n-1;i>0;i--){
            for(int j=0;j<i;j++)
                cout<<"*";
            for(int k=0;k<2*(n-i);k++)
                cout<<" ";
            for(int l=0;l<i;l++)
                cout<<"*";
            cout<<endl;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        ob.printTriangle(n);
    }
    return 0;
}
// } Driver Code Ends