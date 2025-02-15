class Solution {
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();
        Map<Character, Character> mapping = new HashMap<>();
        mapping.put(')', '(');
        mapping.put('}', '{');
        mapping.put(']', '[');

        int i = 0;
        while(i < s.length()) {
            Character c = s.charAt(i);
            if(!mapping.containsKey(c)){
                stack.push(c);
            } else if (stack.size() == 0 || stack.pop() != mapping.get(c)) {
                return false;
            }
            i++;
        }
        if(stack.size() > 0){
            return false;
        }
        return true;
    }
}