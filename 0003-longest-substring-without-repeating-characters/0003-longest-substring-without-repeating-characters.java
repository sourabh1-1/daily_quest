class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashMap<Character, Integer> hash=new HashMap<>();
        int n=s.length();
        int i=0;
        int e=0;
        int maxi=0;
        while(e<n){
            if(hash.containsKey(s.charAt(e))){
                if(hash.get(s.charAt(e))>=i)
                    i=hash.get(s.charAt(e))+1;
            }
            maxi=Math.max(maxi, e-i+1);
            hash.put(s.charAt(e),e);
            e++;
        }
        return maxi;
    }
}