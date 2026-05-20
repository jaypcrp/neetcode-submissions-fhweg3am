#include <stack>
#include <algorithm>  // for std::min

class MinStack {
private:
    std::stack<int> stk;       // main stack: stores actual values
    std::stack<int> minStk;    // parallel stack: stores min at each level

public:
    MinStack() {
        // Both stacks start empty automatically
    }
    
    void push(int val) {
        stk.push(val);
        
        if (minStk.empty()) {
            minStk.push(val);
        } else {
            // Push the smaller of val and the current min
            minStk.push(std::min(val, minStk.top()));
        }
    }
    
    void pop() {
        stk.pop();
        minStk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minStk.top();
    }
};