class Solution {
    public String mergeAlternately(String word1, String word2) {
        String result = "";
        int length1 = 0, length2 = 0;
        while (length1 < word1.length() && length2 < word2.length()) {
            result += word1.charAt(length1++);
            result += word2.charAt(length2++);
        }
        if(length1 < word1.length()) {
            result += word1.substring(length1);
        }
        if(length2 < word2.length()) {
            result += word2.substring(length2);
        }
        return result;
    }
}