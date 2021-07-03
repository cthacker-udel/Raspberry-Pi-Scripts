#include <string>
#include <stdlib.h>
using namespace std;

class Step{

    string step;
    int times;

    public:

        Step(string);

        Step(string,int);

        void setTimes();

}