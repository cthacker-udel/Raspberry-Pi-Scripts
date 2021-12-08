
class Zebra{

	int legs;
	int age;
	string roar;
	string name;

	public:

		Zebra();

		Zebra(int);

		Zebra(int,int);

		Zebra(int,int,string);

		Zebra(int,int,string,string);

		Zebra(string);

		int getLegNumber();

		int getAge();

		string getRoar();

		void setAge(int);

		void setRoar(string);

		void setName(string);

		string getName();


};
