#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> mainStack, minStack;

public:
    void push(int val) {
        mainStack.push(val);
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }

    void pop() {
        if (mainStack.top() == minStack.top()) {
            minStack.pop();
        }
        mainStack.pop();
    }

    int top() {
        return mainStack.top();
    }

    int getMin() {
        return minStack.top();
    }
};

int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << "Min: " << minStack.getMin() << endl; // Output: -3
    minStack.pop();
    cout << "Top: " << minStack.top() << endl;   // Output: 0
    cout << "Min: " << minStack.getMin() << endl; // Output: -2
    return 0;
}
