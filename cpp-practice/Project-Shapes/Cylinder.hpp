
class Cylinder{

    int radius;
    int height;
    int surfaceArea;
    int diameter;
    int lateralSurface;
    int baseArea;
    int volume;

    public:

        double PI = 3.14159;

        int getRadius();

        int getHeight();

        void setRadius(int);

        void setHeight(int);

        Cylinder();

        Cylinder(int,int);

        int getSurfaceArea();

        int getDiameter();

        int getLateralSurface();

        int getBaseArea();

        int getVolume();

        int calcSurfaceArea();

        int calcDiameter();

        int calcLateralSurface();

        int calcBaseArea();

        int calcVolume();



};
