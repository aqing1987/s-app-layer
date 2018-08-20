/*
 * Create a combat function that takes the player's current health and the
 * amount of damage recieved, and returns the player's new health. Health can't
 * be less than 0.
 * */

#include <iostream>

// better 1
int combat2(int health, int damage) {
  return damage > health ? 0 : health - damage;
}

// better 2
int combat3(int health, int damage) {
  return std::max(0, health - damage);
}

int combat(int health, int damage){
  int out = health - damage;

  return (out > 0 ? out : 0);
}

int main() {
  std::cout << combat(20,30) << std::endl;
  return 0;
}