// strctfun.cpp -- functions with a structure argument
// some compilers require explicit instructions to search the math
// library. For instance, older versions of g++ uses this command line:
// g++ structfun.c -lm
#include <iostream>
#include <cmath>

// structure declarations
struct polar
{
    double distance; // distance from origin
    double angle; // direction from origin
};

struct rect
{
    double x; // horizontal distance from origin
    double y; // vertical distance from origin
};

// prototypes
polar rect_to_polar(rect xypos);
void show_polar(polar dapos);

int main(int argc, char *argv[])
{
    using namespace std;

    rect rplace;
    polar pplace;

    cout << "Enter the x and y values: ";
    // using cin >> as the test condition, because it accepts all
    // valid numeric input. You should keep this trick in mind when
    // you need an input loop for numbers.
    while (cin >> rplace.x >> rplace.y) { // slick use of cin
        pplace = rect_to_polar(rplace);
        show_polar(pplace);
        cout << "Next two numbers (q to quit): ";
    }
    cout << "Done.\n";

    return 0;
}

// convert rectangular to polar coordinates
polar rect_to_polar(rect xypos)
{
    using namespace std;

    polar answer;

    answer.distance = sqrt(xypos.x * xypos.x + xypos.y * xypos.y);
    answer.angle = atan2(xypos.y, xypos.x);

    return answer; // returns a polar structure
}

// show polar coordinates, converting angle to degrees
void show_polar(polar dapos)
{
    using namespace std;

    const double Rad_to_deg = 57.29577951; // 180 / PI

    cout << "distance = " << dapos.distance;
    cout << ", angle = " << dapos.angle * Rad_to_deg;
    cout << " degrees\n";
}