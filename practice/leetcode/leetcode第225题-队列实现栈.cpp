class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> q;
    MyStack() {
    }

    /** Push element x onto stack. */
    void push(int x) {
       q.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int size = q.size()-1;
        for(int i=0;i<size;i++)
        {
            int data = q.front();
            q.pop();
            q.push(data);
        }
        int d = q.front();
        q.pop();
        return d;

    }

    /** Get the top element. */
    int top() {
         int size = q.size()-1;
        for(int i=0;i<size;i++)
        {
            int data = q.front();
            q.pop();
            q.push(data);
        }

        int d = q.front();
        q.pop();
        q.push(d);
        return d;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        if(!q.empty()){
            return false;
        }
        else
        {
            return true;
        }
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
