class MinStack {
    class Pair {
        int val;
        int minval;
        Pair(int val,int minval){
            this.val = val;
            this.minval = minval;
        }
    }
    Stack<Pair> stack;
    public MinStack() {
        stack = new Stack<Pair>();
    }
    
    public void push(int val) {
        if(stack.isEmpty()){
            stack.push(new Pair(val,val));
        }
        else {
            int min_ele = stack.peek().minval;
            min_ele = Math.min(min_ele,val);
            stack.push(new Pair(val,min_ele));
        }
    }
    
    public void pop() {
        stack.pop();
    }
    
    public int top() {
        return stack.peek().val;
    }
    
    public int getMin() {
        return stack.peek().minval;
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