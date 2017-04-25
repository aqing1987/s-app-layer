import java.util.ArrayList;

// the actual DotCom objects
// know their name, location, and how to check a user guess
// for a match
public class DotCom {
  private ArrayList<String> locationCells;
  private String name;

  // A setter method that updates the DotCom's location
  public void setLocationCells(ArrayList<String> loc) {
    locationCells = loc;
  }

  public void setName(String n) {
    name = n;
  }

  public String checkYourself(String userInput) {
    String result = "miss";

    // find out if the user guess is in ArrayList
    int index = locationCells.indexOf(userInput);
    if (index >= 0) {
      // if the user guess is definitely in the list, remove it
      locationCells.remove(index);

      // if all of the locations have been guessed
      if (locationCells.isEmpty()) {
        result = "kill";
        // tell the user when a DotCom has been sunk
        System.out.println("Ouch! You sunk " + name + " : ( ");
      } else {
        result = "hit";
      }
    }

    return result;
  }
}