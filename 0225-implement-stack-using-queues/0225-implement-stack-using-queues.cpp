class MyStack {
public:
    queue<int> queueStack;
    MyStack() {}

    void push(int x) { queueStack.push(x); }

    int pop() {
        int ret;
        int n = queueStack.size();
        for (int i = 1; i <= n; i++) {
            int temp = queueStack.front();
            queueStack.pop();
            if (i == n) {
                ret = temp;
            } else {
                queueStack.push(temp);
            }
        }
        return ret;
    }

    int top() {
        int ret;
        int n = queueStack.size();
        for (int i = 1; i <= n; i++) {

            int temp = queueStack.front();
            if (i == n) {
                ret = temp;
            }
            queueStack.pop();
            queueStack.push(temp);
        }
        return ret;
    }

    bool empty() { return (queueStack.empty()); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->front();
 * bool param_4 = obj->empty();
 */