#include <stack>
#include <vector>
#include <algorithm>  // for std::min
using namespace std;

class MinStack {
private:
    vector<int> stk;     // main stack: stores actual values
    vector<int> minStk;    // parallel stack: stores min at each level

public:
    MinStack() {
        // Both stacks start empty automatically
    }
    
    void push(int val) {
        stk.push_back(val);
        
        if (minStk.empty()) {
            minStk.push_back(val);
        } else {
            // Push the smaller of val and the current min
            minStk.push_back(std::min(val, minStk.back()));
        }
    }
    
    void pop() {
        stk.pop_back();
        minStk.pop_back();
    }
    
    int top() {
        return stk.back();
    }
    
    int getMin() {
        return minStk.back();
    }
};