/**
 * The dreaded "lost Update" problem
 * Here's another classic concurrency problem, that comes from the databse world.
 * The trick to showing this is to force the computer to take two steps to
 * complete the change to the balance.
 * By forcing it into two steps, the problem with a non-atomic process will become
 * clear.
 * In the "Lost Update" problem, we have two threads, both trying to increment
 * the balance.
 */
class TestSync implements Runnable {
  private int balance;

  // each thread runs 50 times, incrementing the balance on each iteration
  public void run() {
    for (int i = 0; i < 50; i++) {
      increment();
      System.out.println("Balance is " + balance);
    }
  }

  // To solves the "Lost Update" problem, make the increment() method
  // atomic. Synchronize it!
  // private synchronized void increment()
  // A good rule of thumb is to synchronize only the bare minimum that should
  // be synchronized, rather than at the whole-method level
  private void increment() {
    int i = balance;
    // Here's the crucial part! We increment the balance by adding 1
    // to whatever the value of balance was AT THE TIME WE READ IT
    // (rather than adding 1 to whatever the CURRENT value is)
    balance = i + 1;
  }
}
public class TestSyncTest {
  public static void main(String[] args) {
    TestSync job = new TestSync();

    Thread a = new Thread(job);
    Thread b = new Thread(job);

    a.start();
    b.start();
  }
}
