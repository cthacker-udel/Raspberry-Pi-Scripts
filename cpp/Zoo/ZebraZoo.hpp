#include "Zebra.hpp"


class ZebraZoo{

	string name;
	vector<Zebra> zebras;
	int occupants;

	public:

		ZebraZoo();

		ZebraZoo(string);

		string getName();

		vector<Zebra> getZebras();

		int getNumberOfOccupants();

		void displayZebras();

		void addZebra(Zebra);


};
