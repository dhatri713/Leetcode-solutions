class MyQueue {
public:
    
    stack<int> s1;
    stack<int> s2;
    
    MyQueue() {
        
    }
    
    void push(int x) {
//         if (s1.empty()) s1.push(x);
//         else {
//             while (!s1.empty()){
//                 int val = s1.top();
//                 s1.pop();
//                 s2.push(val);
//             }
            
//             s1.push(x);
            
//             while (!s2.empty()){
//                 int val = s2.top();
//                 s2.pop();
//                 s1.push(val);
//             }
//         }
        
        s1.push(x);
    }
    
    int pop() {
        // if (s1.empty()) return -1;
        // int val = s1.top();
        // s1.pop();
        // return val;
        
        if (!s2.empty()) {
            int val = s2.top();
            s2.pop();
            return val;
        }
        
        while (!s1.empty()){
            int val = s1.top();
            s2.push(val);
            s1.pop();
        }
        
        int ans = s2.top();
        s2.pop();
        return ans;
    }
    
    int peek() {
        if (!s2.empty()) return s2.top();
        while (!s1.empty()){
            int val = s1.top();
            s2.push(val);
            s1.pop();
        }
        return s2.top();  
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
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