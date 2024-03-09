class Solution {
    public int strStr(String haystack, String needle) {
        int initialIndex = 0, i=0, j=0;
        int haystackLength = haystack.length();
        int needleLength = needle.length();
        while(i < haystackLength && j < needleLength) {
            if(haystack.charAt(i) == needle.charAt(j)) {
                i++; j++;
            }else {
                j = 0;
                i = initialIndex + 1;
                initialIndex = i;
            }
        }
        if(j == needleLength) return initialIndex;
        else return -1;
  }
    
}