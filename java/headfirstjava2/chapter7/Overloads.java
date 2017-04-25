
// An overloaded method is just a different method that happens
// to have the same method name. It has nothing to do with inheritance
// and polymorphism. An overloaded method is NOT the same as an overridden
// method
public class Overloads {
  String uniqueID;

  public int addNum(int a, int b) {
    return a + b;
  }

  public double addNums(double a, double b) {
    return a + b;
  }

  public void setUniqueID(String theID) {
    uniqueID = theID;
  }

  public void setUniqueID(int ssNumber) {
    String numString = "" + ssNumber;
    setUniqueID(numString);
  }
}