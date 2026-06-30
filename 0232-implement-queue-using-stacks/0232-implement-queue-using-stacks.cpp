class MyQueue {
public:
    stack<int>myQueue;
    MyQueue() {
        
    }
    
    void push(int x) {
        stack<int>myQueuecopy;
        while(!myQueue.empty()){
            myQueuecopy.push(myQueue.top());
            myQueue.pop();
        }
        myQueue.push(x);
        while(!myQueuecopy.empty()){
            myQueue.push(myQueuecopy.top());
            myQueuecopy.pop();
        }
    }
    
    int pop() {
        int x = myQueue.top();
        myQueue.pop();
        return x;
    }
    
    int peek() {
        return myQueue.top();
    }
    
    bool empty() {
        return myQueue.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */