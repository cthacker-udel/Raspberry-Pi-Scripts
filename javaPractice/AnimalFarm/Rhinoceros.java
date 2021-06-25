public class Rhinoceros extends Farm implements Animal{

    int numLegs;
    String roar;
    String name;
    int age;

    public Rhinoceros(){

        this.numLegs = 4;
        this.roar = "EEEEE";
        this.name = "Rhydon";

    }

    public Rhinoceros(String newName){
        this.numLegs = 4;
        this.roar = "EEEEE";
        this.name = newName;
    }

    public Rhinoceros(int age, String newName){

        this.numLegs = 4;
        this.name = newName;
        this.roar = "EEEEE";
        this.age = age;

    }

    public int getNumLegs(){

        return this.numLegs;

    }


    @Override
    public void speak() {
        System.out.println(this.roar);
    }

    @Override
    public String getName() {
        return this.name;
    }

    @Override
    public int getAge() {
        return this.age;
    }

    


}