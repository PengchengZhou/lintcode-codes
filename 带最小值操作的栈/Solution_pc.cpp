#include <stack>

class MinValue {
public:
    int value;
    int cnt;
    
    MinValue(int _value): value(_value), cnt(1){}
};

class MinStack {
private:
    stack<int> stack1;
    stack<MinValue> stack2;

public:
    MinStack() {
        // do initialization if necessary
    }

    void push(int number) {
        // write your code here
        stack1.push(number);
        if(stack2.empty()){
            stack2.push(MinValue(number));
        }else{
            MinValue &minV = stack2.top();
            if(number==minV.value){
                minV.cnt++;
            }else if(number<minV.value){
                stack2.push(MinValue(number));
            }
        }
    }

    int pop() {
        // write your code here
        int ret = stack1.top();
        MinValue &minV = stack2.top();
        if(ret==minV.value){
            minV.cnt--;
            if(minV.cnt==0){
                stack2.pop();
            }
        }
        stack1.pop();
        
        return ret;
    }

    int min() {
        // write your code here
        return stack2.top().value;
    }
};
