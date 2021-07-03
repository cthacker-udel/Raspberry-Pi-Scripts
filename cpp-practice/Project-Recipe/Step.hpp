#include <string>
#include <stdlib.h>
using namespace std;

class Step{

    string step;
    int time;

    public:

        Step(string);

        Step(string,int);

        void setTime(int);

}