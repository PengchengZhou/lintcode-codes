class Queue {
private:

    stack<int> stack1;
    stack<int> stack2;
    
public:

    Queue() {
        // do intialization if necessary
    }

    void push(int element) {
        // write your code here
        while(!stack2.empty()){
            stack1.push(stack2.top());
            stack2.pop();
        }
        stack1.push(element);
    }
    
    int pop() {
        // write your code here
        while(!stack1.empty()){
            stack2.push(stack1.top());
            stack1.pop();
        }
        int ret = stack2.top();
        stack2.pop();
        return ret;
    }

    int top() {
        // write your code here
        while(!stack1.empty()){
            stack2.push(stack1.top());
            stack1.pop();
        }
        return stack2.top();
    }
};
