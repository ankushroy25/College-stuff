package threadStack;

class Stack {
    private int[] stack;
    private int top;
    private boolean turn;

    public Stack(int capacity) {
        stack = new int[capacity];
        top = -1;
        turn = true;
    }

    public synchronized void push(int value) {
        while (!turn) {
            try {
                wait();
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
        stack[++top] = value;
        System.out.println("Pushed " + value);
        turn = false;
        notify();
    }

    public synchronized int pop() {
        while (turn || top == -1) {
            try {
                wait();
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
        int value = stack[top--];
        System.out.println("Popped " + value);
        turn = true;
        notify();
        return value;
    }

    public synchronized void display() {
        System.out.print("Stack Contents: ");
        for (int i = 0; i <= top; i++) {
            System.out.print(stack[i] + " ");
        }
        System.out.println();
    }
}

class PushTask implements Runnable {
    private Stack st;

    public PushTask(Stack st) {
        this.st = st;
    }

    @Override
    public void run() {
        for (int i = 1; i <= 5; i++) {
            st.push(i);
        }
    }
}

class PopTask implements Runnable {
    private Stack st;

    public PopTask(Stack st) {
        this.st = st;
    }

    @Override
    public void run() {
        for (int i = 1; i <= 5; i++) {
            st.pop();
        }
    }
}

public class ThreadStackMain {
    public static void main(String[] args) {
        Stack s = new Stack(5);

        PushTask pushThread = new PushTask(s);
        PopTask popThread = new PopTask(s);

        Thread t1 = new Thread(pushThread);
        Thread t2 = new Thread(popThread);

        t1.start();
        t2.start();
        try {
            t1.join();
            t2.join();
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }

        s.display();
    }
}
