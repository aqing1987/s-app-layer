import java.util.*;

public class TestMap {
  public static void main(String[] args) {
    // HashMap needs two type parameters one for the key and one for the value
    HashMap<String, Integer> scores = new HashMap<String, Integer>();

    scores.put("Kathy", 42);
    scores.put("Bert", 343);
    scores.put("Skyler", 420);

    System.out.println(scores);
    System.out.println(scores.get("Bert"));
  }
}