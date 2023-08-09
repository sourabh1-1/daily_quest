//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public: 
    long long int largestPrimeFactor(int N){
        // code here
        long long int num;
        for(int i=2;i<=sqrt(N);i++){
            while(N%i==0){
                num=i;
                N/=i;
            }
        }
        if(N>1)
            num=N;
        return num;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends