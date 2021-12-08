#include <string>
#include <stdlib.h>
using namespace std;

class Dog{

	friend class Board;

	string name;
	int strength;
	int x;
	int y;

public:

	Dog(string);

	Dog();

	bool changeStrength(int);

	void die();

	void printDog();

	void won();

	void reset();


};
