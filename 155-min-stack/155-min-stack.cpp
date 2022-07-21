class MinStack {
public:
    stack<long long> st;
    long long minElement;
    MinStack() {
        minElement = -1;
    }
    
    void push(int val) {
        val = (long long)val;
        if(st.empty()) {
            st.push(val);
            minElement = val;
        }
        else {
            if(val <= minElement) {
                st.push(2LL*val - minElement);
                minElement = val;
            }
            else {
                st.push(val);
            }
        }
    }
    
    void pop() {
        // if(st.size() == 0) return -1;
        
            if(st.top() < minElement) {
                minElement = 2*minElement - st.top();
                st.pop();
                // return ans;
            }
            else {
                st.pop();
                // return minElement;
            }
    }
    
    int top() {
        if(st.empty()) return minElement;
        else {
            if(st.top() <= minElement) {
                return (int)minElement;
            }
            else return (int)st.top();
        }
    }
    
    int getMin() {
        return (int)minElement;
    }
};
// -2 0 -1 
    
    // me = -2 
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


// -2 0 -1 