#include <string>
#include <functional>
#include <vector>
#include <cmath>
#include <iostream>

class Fighter
{
private:
    std::string name;

    int health;

    int damagePerAttack;

public:
  Fighter(std::string name, int health, int damagePerAttack) {
    this->name = name;
    this->health = health;
    this->damagePerAttack = damagePerAttack;
  }

  ~Fighter() { };

  std::string getName() {
    return name;
  }

  int getHealth() {
    return health;
  }

  int getDamagePerAttack() {
    return damagePerAttack;
  }

  void setHealth(int value) {
    health = value;
  }
};


int numberOfHitsForDeath (Fighter* fighter, int damagePerAttack) {
  return std::ceil((float)fighter->getHealth() / damagePerAttack);
}

std::string declareWinner (Fighter* fighter1, Fighter* fighter2, const std::string& firstAttacker) {
  int f1HitsToDie = numberOfHitsForDeath(fighter1, fighter2->getDamagePerAttack());
  int f2HitsToDie = numberOfHitsForDeath(fighter2, fighter1->getDamagePerAttack());
  int hitsDelta = std::abs(f1HitsToDie - f2HitsToDie);

  if (hitsDelta == 0) return firstAttacker;

  return f1HitsToDie > f2HitsToDie ? fighter1->getName() : fighter2->getName();
}

bool test1 () {
  Fighter fighter1("Lew", 10, 2);
  Fighter fighter2("Harry", 5, 4);
  std::string expectedWinner("Lew");
  return declareWinner(&fighter1, &fighter2, "Lew") == expectedWinner;
}

bool test2 () {
  Fighter fighter1("Lew", 10, 2);
  Fighter fighter2("Harry", 5, 4);
  std::string expectedWinner("Harry");
  return declareWinner(&fighter1, &fighter2, "Harry") == expectedWinner;
}

bool test3 () {
  Fighter fighter1("Harald", 20, 5);
  Fighter fighter2("Harry", 5, 4);
  std::string expectedWinner("Harald");
  return declareWinner(&fighter1, &fighter2, "Harry") == expectedWinner;
}

bool test4 () {
  Fighter fighter1("Harald", 20, 5);
  Fighter fighter2("Harry", 5, 4);
  std::string expectedWinner("Harald");
  return declareWinner(&fighter1, &fighter2, "Harald") == expectedWinner;
}

bool test5 () {
  Fighter fighter1("Jerry", 30, 3);
  Fighter fighter2("Harald", 20, 5);
  std::string expectedWinner("Harald");
  return declareWinner(&fighter1, &fighter2, "Jerry") == expectedWinner;
}

bool test6 () {
  Fighter fighter1("Jerry", 30, 3);
  Fighter fighter2("Harald", 20, 5);
  std::string expectedWinner("Harald");
  return declareWinner(&fighter1, &fighter2, "Harald") == expectedWinner;
}

int main () {
  using namespace std;
  
  vector<function<bool()>> testCase = {
    test1,
    test2,
    test3,
    test4,
    test5,
    test6
  };

  for (int i = 0; i < testCase.size(); i++) {
    if (!testCase[i]()) {
      cout << "test: " << i << " Failed!" << endl;
      return 1;
    }
  }

  cout << "All tests passed!" << endl;

  return 0;
}
