#include "student.h"


void Student::setName(string nameIn) {
  name = nameIn;
}

void Student::setId(int idIn) {
     id = idIn;
}

void Student::setGradDate(int gradDateIn) {
     gradDate = gradDateIn;
}

void Student::print() {
     cout<<name<<" "<<id<<" "<<gradDate;
}

string Student::getName() {
     return name;
}

int Student::getId() {
     return id; 
}

int Student::getGradDate() {
     return gradDate;
}


