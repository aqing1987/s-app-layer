public class SimpleDotComGame {
  public static void main(String[] args) {
    int numOfGuesses = 0;
    // for getting user input
    GameHelper helper = new GameHelper();

    SimpleDotCom theDotCom = new SimpleDotCom();

    // make a random number for the first cell, and use it to
    // make the cell locations array
    int randomNum = (int)(Math.random() * 5);
    int[] locations = {randomNum, randomNum+1, randomNum+2};

    // give the dotCom its locations
    theDotCom.setLocationCells(locations);

    // to track whether the game is still alive
    boolean isAlive = true;

    while (isAlive) {
      String guess = helper.getUserInput("enter a number");
      String result = theDotCom.checkYourself(guess);
      numOfGuesses++;
      if (result.equals("kill")) {
        isAlive = false;
        System.out.println("You took " + numOfGuesses + " guesses");
      }
    }
  }
}

