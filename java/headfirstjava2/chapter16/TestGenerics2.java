import java.util.*;

public class TestGenerics2 {
  public static void main(String[] args) {
    new TestGenerics2().go();
  }

  public void go() {
    // A simple change from Animal[] to ArrayList<Animal>
    ArrayList<Animal> animals = new ArrayList<Animal>();
    animals.add(new Dog());
    animals.add(new Cat());
    animals.add(new Dog());
    takeAnimals(animals);
  }

  // The method now takes an ArrayList instead of an array, but everything
  // else is the same. Remember, that for loop syntax works for both
  // arrays and collections.
  public void takeAnimals(ArrayList<Animal> animals) {
    for (Animal a: animals)
      a.eat();
  }
}