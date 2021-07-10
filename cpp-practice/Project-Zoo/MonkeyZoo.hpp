#include "Monkey.hpp"

class MonkeyZoo{

	string name;
	int occupants;
	vector<Monkey> monkeys;

	public:

		MonkeyZoo();

		MonkeyZoo(string);

		int getNumberOfOccupants();

		string getName();

		vector<Monkey> getMonkeys();

		void addMonkey(Monkey);

		void displayMonkeys();
};
