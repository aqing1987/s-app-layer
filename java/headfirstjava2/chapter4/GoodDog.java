class GoodDog {
  // make the instance variable private
  private int size;

  // make the getter and setter methods public
  // Even though the methods don't really add new functionality, the
  // cool thing is that you can change your mind later. You can come
  // back and make a method safer, faster, better.
  public int getSize() {
    return size;
  }

  public void setSize(int s) {
    size = s;
  }

  void bark() {
    if (size > 60) {
      System.out.println("Wooof! Wooof!");
    } else if (size > 14) {
      System.out.println("Ruff! Ruff!");
    } else {
      System.out.println("Yip! Yip!");
    }
  }
}