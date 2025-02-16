class Solution {
    List<String> symbols = Arrays.asList("+", "-", "*", "/");

    private int evaluateExpression(int a, int b, String expression){
        int result = 0;
        if (expression.equals("+")){
            result = a+b;
        } else if (expression.equals("-")){
            result = b-a;
        } else if (expression.equals("*")){
            result = a*b;
        } else {
            result = b/a;
        }
        return (int) Math.floor(result);
    }

    public int evalRPN(String[] tokens) {
        Stack<Integer> stack = new Stack();
        for (String s : tokens){
            if(symbols.contains(s)){
                if(stack.size() < 2){
                    throw new RuntimeException("Invalid expression");
                } else {
                    int a = stack.peek(); stack.pop();
                    int b = stack.peek(); stack.pop();
                    stack.push(evaluateExpression(a, b, s));
                }
            } else {
                int n = Integer.valueOf(s);
                stack.push(n);
            }
        }
        return stack.peek();
    }
}