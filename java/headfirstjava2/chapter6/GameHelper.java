import java.io.*;
import java.util.*;

public class GameHelper {
  private static final String alphabet = "abcdefg";
  private int gridLength = 7;
  private int gridSize = 49;
  private int [] grid = new int[gridSize];
  private int comCount = 0;

  public String getUserInput(String prompt) {
    String inputLine = null;
    System.out.print(prompt + " ");
    try {
      BufferedReader is = new BufferedReader(
          new InputStreamReader(System.in));
      inputLine = is.readLine();
      if (inputLine.length() == 0)
        return null;
    } catch (IOException e) {
      System.out.println("IOException: " + e);
    }
    return inputLine.toLowerCase();
  }

  public ArrayList<String> placeDotCom(int comSize) {
    ArrayList<String> alphaCells = new ArrayList<String>();
    String[] alphacoords = new String[comSize];
    String temp = null;  // temporary String for concat
    int [] coords = new int[comSize];  // current candidate coords
    int attempts = 0;  // current attempts counter
    boolean success = false;  // flag = found a good location?
    int location = 0;  // current start location

    comCount++;  // nth dot com to place
    System.out.println("comCount = " + comCount);
    int incr = 1;  // set horizontal increment
    if ((comCount % 2) == 0) {  // if even dot com (place vertically)
      incr = gridLength;  // set vertical increment
    }

    while (!success & attempts++ < 200) {
      location = (int) (Math.random() * gridSize);  // get random stat point
      System.out.println(" try " + location);
      int x = 0;  // nth position in dotcom to place
      success = true;  // assume success
      while (success && x < comSize) {  // lokk for adjacent unused spots
        if (grid[location] == 0) {  // if not used
          System.out.println("location = " + location + " incr = " + incr);
          coords[x++] = location;  // save location
          location += incr;  // try 'next' adjacent
          if (location >= gridSize) {  // out of bounds - 'bottom
            success = false;
          }

          // out of bounds - right edge
          if (x > 0 && (location % gridLength == 0)) {
            success = false;
          }
        } else {  // found already used location
          System.out.println(" used " + location);
          success = false;
        }
      }
    }  // close while

    // turn location into alpha coords
    int x = 0;
    int row = 0;
    int column = 0;

    while (x < comSize) {
      grid[coords[x]] = 1;  // mark as 'used'
      row = (int) (coords[x] / gridLength);  // get row value
      column = coords[x] % gridLength;  // get numeric column value
      temp = String.valueOf(alphabet.charAt(row));  // convert to alpha

      alphaCells.add(temp.concat(Integer.toString(column)));
      x++;

      // tell where the DotCom is located
      System.out.println(" coord " + x + " = " + alphaCells.get(x-1));
    }

    return alphaCells;
  }
}