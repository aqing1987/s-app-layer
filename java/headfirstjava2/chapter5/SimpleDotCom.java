public class SimpleDotCom {
  int[] locationCells;
  int numOfHits = 0;

  public void setLocationCells(int[] locs) {
    locationCells = locs;
  }

  public String checkYourself(String stringGuess) {
    // Integer.parseInt() works only on String that represent the
    // ascii values for digits
    int guess = Integer.parseInt(stringGuess);
    String result = "miss";

    // beginning with Java 5.0, you can use the enhanced for loop
    for (int cell : locationCells) {
      if (guess == cell) {
        result = "hit";
        numOfHits++;
        break;
      }
    }

    if (numOfHits == locationCells.length) {
      result = "kill";
    }

    System.out.println(result);
    return result;
  }
}