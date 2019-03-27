class MyQueue {
public:
    stack<int> left;
    stack<int> right;
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        right.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(left.empty())
        {
            while(!right.empty())
            {
                int data = right.top();
                right.pop();
                left.push(data);
            }
        }
        int p = left.top();
        left.pop();
        return p;
    }

    /** Get the front element. */
    int peek() {
       if(left.empty())
        {
            while(!right.empty())
            {
                int data = right.top();
                right.pop();
                left.push(data);
            }
        }
        return left.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        if(left.empty()&&right.empty())
        {
            return true;
        }
        else
            return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
