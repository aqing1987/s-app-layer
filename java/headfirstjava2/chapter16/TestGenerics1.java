import java.util.*;

public class TestGenerics1 {
  public static void main(String[] args) {
    new TestGenerics1().go();
  }

  public void go() {
    // declare and create an Animal array, that holds both dogs and cats
    Animal[] animals = {new Dog(), new Cat(), new Dog()};

    // declare and create a Dog array, that holds only Dogs
    Dog[] dogs = {new Dog(), new Dog(), new Dog()};

    takeAnimals(animals);
    takeAnimals(dogs);
  }

  // The crucial point is that the takeAnimals() method can take an
  // Animal[] or a Dog[], since Dog IS-A Animal Polymorphism in action.
  public void takeAnimals(Animal[] animals) {

    // Array types are checked again at runtime, but collection type checks
    // happen only when you compile
    // We put a new Cat into a Dog array. The compiler allowed it, because
    // it knows that you might have passed a Cat array or Animal array to
    // the method, so to the compiler it was possible that this was OK.
    // It compiles, but when we run it, the JVM stopped it.
    //animals[0] = new Cat();

    for (Animal a: animals)
      a.eat();

  }
}