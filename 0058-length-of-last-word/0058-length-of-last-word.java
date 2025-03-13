class Solution {
    public int lengthOfLastWord(String s) {
        int maxWordLen = 0;
        for(int i=s.length()-1; i>= 0; i--) {
            if(s.charAt(i) != ' '){
                maxWordLen+=1;
            }
            else if (maxWordLen > 0){
                break;
            }
            
        }
        return maxWordLen;
        
    }
}