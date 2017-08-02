import java.util.*;

public class TestGenerics3 {
  public static void main(String[] args) {
    new TestGenerics3().go();
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
    // if you passed a Dog ArrayList - one meant to hold ONLY Dogs
    // to this method that takes an Animal ArrayList, then suddenly you'd
    // end up with a Cat in the Dog list. The compiler knows that if it lets
    // you pass a Dog ArrayList into the method like that, someone could,
    // at runtime, add a Cat to your Dog list. So instead, the compiler just
    // won't let you take the risk.
    takeAnimals(dogs);
  }

  // The method now takes an ArrayList instead of an array, but everything
  // else is the same. Remember, that for loop syntax works for both
  // arrays and collections.
  // When you use a wildcard in your method, you can do things with the list
  // elements, but you can't put new things in the list.
  public void takeAnimals(ArrayList<Animal> animals) {
    for (Animal a: animals)
      a.eat();
  }
}
