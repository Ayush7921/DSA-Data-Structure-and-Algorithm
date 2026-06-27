class MyQueue {
public:
    stack<int> s;

    MyQueue() {
    }

    void push(int x) {
        s.push(x);
    }

    int pop() {
        if (s.size() == 1) {
            int ans = s.top();
            s.pop();
            return ans;
        }

        int x = s.top();
        s.pop();

        int ans = pop();

        s.push(x);

        return ans;
    }

    int peek() {
        if (s.size() == 1) {
            return s.top();
        }

        int x = s.top();
        s.pop();

        int ans = peek();

        s.push(x);

        return ans;
    }

    bool empty() {
        return s.empty();
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