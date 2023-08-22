import java.util.*;

class MyQueue {
    public Stack <Integer> pushSt;
    public Stack <Integer> popSt;

    public MyQueue() {
        pushSt = new Stack<> ();
        popSt = new Stack<> ();
    }
    
    public void push(int x) {
        pushSt.add(x);
    }
    
    public int pop() {
        if(!popSt.isEmpty()) return popSt.pop();
        while(!pushSt.isEmpty())
        {
            int n = pushSt.pop();
            popSt.add(n);
        }
        return popSt.pop();
    }
    
    public int peek() {
        if(!popSt.isEmpty()) return popSt.peek();
        while(!pushSt.isEmpty())
        {
            int n = pushSt.pop();
            popSt.add(n);
        }
        return popSt.peek();
    }
    
    public boolean empty() {
        if(popSt.isEmpty() && pushSt.isEmpty()) return true;
        return false;
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */
