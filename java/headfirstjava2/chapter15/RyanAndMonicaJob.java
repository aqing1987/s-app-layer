/**
 * The following example shows what can happen when two threads (Ryan and Monica)
 * share a single object (the bank account)
 * Ryan and Monica always fall asleep after they check the balance but
 * before they finish the withdrawal.
 */
class BankAccount {
  private int balance = 100;

  public int getBalance() {
    return balance;
  }

  public void withdraw(int amount) {
    balance -= amount;
  }
}

public class RyanAndMonicaJob implements Runnable {
  // There will be only ONE instance of the bank account. Both
  // threads will access this one account
  private BankAccount account = new BankAccount();

  public static void main(String[] args) {
    // instantiate the Runnable (job)
    RyanAndMonicaJob theJob = new RyanAndMonicaJob();

    // Make two threads, giving each thread the same Runnable job.
    // That means both threads will be accessing the one account
    // instance variable in the Runnable class
    Thread one = new Thread(theJob);
    Thread two = new Thread(theJob);
    one.setName("Ryan");
    two.setName("Monica");
    one.start();
    two.start();
  }

  public void run() {
    for (int x = 0; x < 10; x++) {
      makeWithdrawl(10);
      if (account.getBalance() < 0) {
        System.out.println("Overdrawn!");
      }
    }
  }

  // Use the synchronized keyword to modify a method so that only one
  // thread at a time can access it.
  private synchronized void makeWithdrawl(int amount) {
    if (account.getBalance() >= amount) {
      System.out.println(Thread.currentThread().getName() + " is about to withdraw");
      try {
        System.out.println(Thread.currentThread().getName() + " is going to sleep");
        Thread.sleep(500);
      } catch (InterruptedException ex) {
        ex.printStackTrace();
      }
      System.out.println(Thread.currentThread().getName() + " woke up.");
      account.withdraw(amount);
      System.out.println(Thread.currentThread().getName() + " completes the withdrawl");
    } else {
      System.out.println("Sorry, not enough for " + Thread.currentThread().getName());
    }
  }
}
