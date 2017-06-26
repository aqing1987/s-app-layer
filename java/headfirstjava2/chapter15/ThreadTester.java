class MyRunnable implements Runnable {
  // Runnable has only one method to implement: public void run()
  // This is where you put the JOB the thread is supposed to run.
  // This is the method that goes at the bottom of the new stack
  public void run() {
    go();
  }

  public void go() {
    doMore();
  }

  public void doMore() {
    System.out.println("top of the stack");
  }
}

public class ThreadTester {
  public static void main(String[] args) {
    // A Thread instance has been created but not started.
    Runnable threadJob = new MyRunnable();

    // pass the new runnable instance into the new Thread constructor
    Thread myThread = new Thread(threadJob);

    // You won't get a new thread of execution until you call start()
    // on the Thread instance. A thread is not really a thread until you
    // start it.
    // When you start the thread, it moves into the runnable state.
    // This means the thread is ready to run and just waiting for its Big
    // Chance to be selected for execution.
    myThread.start();
    System.out.println("back in main");
  }
}
