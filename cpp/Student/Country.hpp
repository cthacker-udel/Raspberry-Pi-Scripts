#include "State.hpp"

class Country{

	vector<State> states;
	int founded;
	int population;
	string name;
	string president;

	public:

		Country(string);

		Country();

		void setPresident(string);

		void setFounded(int);

		void setName(string);

		int getFounded();

		int getPopulation();

		string getName();

		string getPresident();



}
