#include "Gorilla.hpp"

class GorillaZoo{
	
	vector<Gorilla> gorillas;

	int occupancy;

	string name;

	public:

		GorillaZoo(string);

		GorillaZoo();	

		int getOccupancy();

		void addGorilla(Gorilla);

		vector<Gorilla> getGorillas();

}
