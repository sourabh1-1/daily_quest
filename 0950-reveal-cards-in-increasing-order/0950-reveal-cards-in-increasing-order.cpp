class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        vector<int> v;
        sort(deck.begin(),deck.end());
        int n=deck.size();
        for(int i=n-1;i>=0;i--){
            int j=1;
            while(j<v.size()){
                swap(v[0],v[j]);
                j++;
            }
            v.insert(v.begin(),deck[i]);
        }
        return v;
    }
};