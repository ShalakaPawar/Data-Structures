class Solution {
    public String convertToTitle(int columnNumber) {
        
        String columnName = "";
        while(columnNumber > 0){
            columnNumber--;
            columnName = (char)(columnNumber%26 + 'A') + columnName;
            columnNumber = columnNumber/26;
        }
        return columnName;
        
    }
}