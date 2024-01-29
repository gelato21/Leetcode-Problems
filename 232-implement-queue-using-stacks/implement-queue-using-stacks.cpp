class MyQueue {
public:
    MyQueue() {
        
    }
    stack<int> s1, s2;
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        while(s1.empty()==false){
            s2.push(s1.top());
            s1.pop();
        }
        int top=s2.top();
        s2.pop();
        while(s2.empty()==false){
            s1.push(s2.top());
            s2.pop();
        }
        return top;
    }
    
    int peek() {
        while(s1.empty()==false){
            s2.push(s1.top());
            s1.pop();
        }
        int top=s2.top();
        while(s2.empty()==false){
            s1.push(s2.top());
            s2.pop();
        }
        return top;
    }
    
    bool empty() {
        if(s1.empty()==false) return false;
        else return true;
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