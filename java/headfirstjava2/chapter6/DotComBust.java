import java.util.*;

public class DotComBust {
  private GameHelper helper = new GameHelper();
  // make an arraylist of DotCom objects.
  private ArrayList<DotCom> dotComsList = new ArrayList<DotCom>();
  private int numOfGuesses = 0;

  private void setUpGame() {
    // make three DotCom objects, give 'em names, and stick 'em in the arraylist
    DotCom one = new DotCom();
    one.setName("Pets.com");
    DotCom two = new DotCom();
    two.setName("eToys.com");
    DotCom three = new DotCom();
    three.setName("Go2.com");

    dotComsList.add(one);
    dotComsList.add(two);
    dotComsList.add(three);

    // print brief instructions for user
    System.out.println("Your goal is to sink three dot come.");
    System.out.println("Pets.com, eToys.com, Go2.com");
    System.out.println("Try to sink them all in the fewest number of guesses");

    // repeat with each DotCom in the list
    for (DotCom dotComToSet : dotComsList) {
      // ask the helper for a DotCom location
      ArrayList<String> newLocation = helper.placeDotCom(3);
      // call the setter method on this DotCom to give it the location
      // you just got from the helper
      dotComToSet.setLocationCells(newLocation);
    }
  }

  private void startPlaying() {
    // As long as the DotCom list is NOT empty
    while (!dotComsList.isEmpty()) {
      String userGuess = helper.getUserInput("Enter a guess");
      checkUserGuess(userGuess);
    }

    finishGame();
  }

  private void checkUserGuess(String userGuess) {
    numOfGuesses++;
    String result = "miss";

    for (DotCom dotComToSet : dotComsList) {
      result = dotComToSet.checkYourself(userGuess);
      if (result.equals("hit")) {
        break;
      }

      // this guy's dead, so take his out of the DotCom list then
      // get out of the loop
      if (result.equals("kill")) {
        dotComsList.remove(dotComToSet);
        break;
      }
    }  // close for

    System.out.println(result);
  }

  // print a message telling the user how he did in the game
  private void finishGame() {
    System.out.println("All Dot Coms are dead! Your stock is now worthless.");
    if (numOfGuesses <= 18) {
      System.out.println("It only took you " + numOfGuesses + " guesses.");
      System.out.println(" You got out before your options sank.");
    } else {
      System.out.println("Took you long enough. " + numOfGuesses + " guesses.");
      System.out.println("Fish are dancing with your options.");
    }
  }

  public static void main(String[] args) {
    DotComBust game = new DotComBust();
    game.setUpGame();
    game.startPlaying();
  }
}