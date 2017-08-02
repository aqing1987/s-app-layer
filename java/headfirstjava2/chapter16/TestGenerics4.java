import java.util.*;

public class TestGenerics4 {
  public static void main(String[] args) {
    new TestGenerics4().go();
  }

  public void go() {
    // A simple change from Animal[] to ArrayList<Animal>
    ArrayList<Animal> animals = new ArrayList<Animal>();
    animals.add(new Dog());
    animals.add(new Cat());
    animals.add(new Dog());
    takeAnimals(animals);

    ArrayList<Dog> dogs = new ArrayList<Dog>();
    dogs.add(new Dog());
    dogs.add(new Dog());
    takeAnimals(dogs);
  }

  // there is a way to create a method argument that can accept an ArrayList
  // of any Animal subtype. The simplest way is to use a wildcard - added
  // to the Java language explicitly for this reason.
  public void takeAnimals(ArrayList<? extends Animal> animals) {
    for (Animal a: animals)
      a.eat();
  }
}
