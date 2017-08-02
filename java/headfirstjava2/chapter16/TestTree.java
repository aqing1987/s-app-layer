/**
 * Created by rex on 8/1/17.
 */

import java.util.*;

public class TestTree {
  public static void main(String[] args) {
    new TestTree().go();
  }

  public void go() {
    Book b1 = new Book("How cats work");
    Book b2 = new Book("Remix your body");
    Book b3 = new Book("Finding emo");

    // TreeSet elements MUST be comparable
    // The elements in the list must be of a type that implements Comparable
    // Or you use the TreeSet's overloaded constructor that takes a Comparator
    TreeSet<Book> tree = new TreeSet<Book>();
    tree.add(b1);
    tree.add(b2);
    tree.add(b3);
    System.out.println(tree);

    BookCompare bCompare = new BookCompare();
    TreeSet<Book> t2 = new TreeSet<Book>(bCompare);
    t2.add(b1);
    t2.add(b2);
    t2.add(b3);
    System.out.println(t2);
  }
}

class Book implements Comparable {
  String title;
  public Book(String t) {
    title = t;
  }

  public int compareTo(Object b) {
    Book book = (Book) b;
    return (title.compareTo(book.title));
  }
}

class BookCompare implements Comparator<Book> {
  public int compare(Book one, Book two) {
    return (one.title.compareTo(two.title));
  }
}