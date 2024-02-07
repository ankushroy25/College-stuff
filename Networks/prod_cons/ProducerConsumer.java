package prod_cons;

class Operation {
    int n = 0;
    boolean flag = false;

    synchronized void produce() {
        while (flag) {
            try {
                wait();
            } catch (InterruptedException e) {
                System.out.println("InterruptedException caught");
            }
        }
        flag = true;
        System.out.println("Produced : " + (++n));
        notify();
    }

    synchronized void consume() {
        while (!flag) {
            try {
                wait();
            } catch (InterruptedException e) {
                System.out.println("InterruptedException caught");
            }
        }
        flag = false;
        System.out.println("Consumed : " + (--n));
        notify();
    }
}

class Producer implements Runnable {
    Operation op;

    Producer(Operation op) {
        this.op = op;
    }

    public void run() {

        while (true) {
            op.produce();
            try {
                Thread.sleep(3000);
            } catch (InterruptedException e) {
                System.out.println("InterruptedException caught");
            }
        }
    }
}

class Consumer implements Runnable {
    Operation op;

    Consumer(Operation op) {
        this.op = op;
    }

    public void run() {
        while (true) {
            op.consume();
            try {
                Thread.sleep(3000);
            } catch (InterruptedException e) {
                System.out.println("InterruptedException caught");
            }
        }
    }
}

public class ProducerConsumer {

    public static void main(String[] args) {
        Operation op = new Operation();

        Thread pth = new Thread(new Producer(op));
        Thread cth = new Thread(new Consumer(op));
        pth.start();
        cth.start();
    }

}
