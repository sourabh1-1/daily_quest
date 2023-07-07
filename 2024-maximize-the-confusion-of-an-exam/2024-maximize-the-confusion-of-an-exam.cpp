class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int TCount=0,FCount=0,count=0,j=0;
        for(int i=0;i<answerKey.length();i++){
            if(answerKey[i]=='T')
                TCount++;
            else
                FCount++;
            while(TCount>k && FCount>k){
                if(answerKey[j]=='T')
                    TCount--;
                else
                    FCount--;
                j++;
            }
            count=max(count,i-j+1);
        }
        return count;
    }
};