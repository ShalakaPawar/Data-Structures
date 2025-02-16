class MinStack {
    Stack<Pair<Integer, Integer>> stack = new Stack();
    public MinStack() {
        
    }
    public void push(int val) {
        if(stack.isEmpty()){
            stack.push(new Pair<>(val, val));
        } else {
            stack.push(new Pair<>(val, Math.min(val, stack.peek().getValue())));
        }
    }
    
    public void pop() {
         if(!stack.isEmpty()){
        stack.pop();
         }
    }
    
    public int top() {
         if(!stack.isEmpty()){
            return stack.peek().getKey();
         }
          throw new RuntimeException("Stack is empty");
    }
    
    public int getMin() {
         return stack.peek().getValue();
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */