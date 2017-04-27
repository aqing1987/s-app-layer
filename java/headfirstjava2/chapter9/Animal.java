public abstract class Animal {
  // all animals including subclasses have a name
  private String name;

  public Animal () {
    System.out.println("Making an Animal");
  }

  public Animal(String theName) {
    System.out.println("Making an named Animal");
    name = theName;
  }

  // a getter method
  public String getName() {
    return name;
  }
}