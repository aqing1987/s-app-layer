/**
 * starts two threads, each thread has the same job: run in a loop,
 * printing the currently-running thread's name with each iteration.
 */
public class RunThreads implements Runnable {
  public static void main(String[] args) {
    // make one runnable instance
    RunThreads runner = new RunThreads();

    // make two threads with the same Runnable (the same job)
    Thread alpha = new Thread(runner);
    Thread beta = new Thread(runner);

    // name the threads
    alpha.setName("Alpha thread");
    beta.setName("Beta thread");

    // start the threads
    alpha.start();
    beta.start();
  }
  public void run() {
    for (int i = 0; i < 25; i++) {
      String threadName = Thread.currentThread().getName();
      System.out.println(threadName + " is running");
    }
  }
}
