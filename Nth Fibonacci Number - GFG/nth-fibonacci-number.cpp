//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int fibo(int n){
        if(n<=1)
            return n;
        return (fibo(n-1)+fibo(n-2))%1000000007;
    }
    int nthFibonacci(int n){
        // code here
        int t=0;
        int t1=1;
        int sum;
        for(int i=1;i<n;i++){
            sum=(t+t1)%1000000007;
            t=t1;
            t1=sum;
        }
        return sum;
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
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends