// coordin.h -- structure templates and function prototypes

// Here are some things commonly found in header file
// 1. Function prototypes
// 2. Symbolic constants defined using #define or const
// 3. Structure declarations - because they don't create variables
// 4. class declarations
// 5. template declarations - they are not code to be compiled
// 6. inline functions

// structure templates
#ifndef COORDIN_H_
#define COORDIN_H_

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

#endif