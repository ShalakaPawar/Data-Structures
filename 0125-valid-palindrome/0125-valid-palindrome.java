class Solution {
    public boolean isPalindrome(String s) {
        int i = 0;
        int j = s.length()-1;
        
        while(i < j) {
            String a = String.valueOf(s.charAt(i));
            String b = String.valueOf(s.charAt(j));

            if(!a.matches("[a-zA-Z0-9]")) {
                i++;
                continue;
            }
            if(!b.matches("[a-zA-Z0-9]")) {
                j--;
                continue;
            }
            if (!a.equalsIgnoreCase(b)){
                return false;
            }
            i++; j--;
        }
        if (i >= j) {
            return true;
        }
        return false;
    }
    
}