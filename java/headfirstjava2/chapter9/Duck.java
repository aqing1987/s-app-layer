public class Duck extends Animal {
  // instance variable
  int size;

  // The constructor gives you a chance to step into the middle of new
  // constructors cannot have a return type
  // Constructors are not inherited
  // The best place to put initialization code is in the constructor.
  // If you have more than one constructor in a class, it means you have
  // OVERLOADED constructor.
  // If you write a constructor that takes arguments, and you still want a
  // no-arg constructor, you'll have to build the no-arg constructor yourself
  // If you have more than one constructor in a class, the constructors MUST
  // have different argument lists.
  public Duck() {
    // supply default size
    size = 27;
  }

  public Duck (int duckSize) {
    // The only way to call a super constructor is by calling super()
    // super() calls the super constructor.
    // If you don't provide a constructor, the compiler puts one in that
    // The compiler-inserted call to supper() is always a no-arg call.
    super();

    System.out.println("Quack");

    size = duckSize;

    System.out.println("size is " + size);
  }

  // setter method
  public void setSize(int newSize) {
    size = newSize;
  }
}