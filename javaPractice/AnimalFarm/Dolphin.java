public class Dolphin extends Farm implements Animal{

    int numLegs;
    String squeal;
    String name;
    int age;

    public Dolphin(){

        this.numLegs = 0;
        this.squeal = "AAAAA";
        this.name = "Donny";

    }

    public Dolphin(String newName){

        this.numLegs = 0;
        this.squeal = "AAAAA";
        this.name = newName;

    }

    public Dolphin(int age, String newName){

        this.numLegs = 0;
        this.squeal = "AAAAA";
        this.name = newName;
        this.age = age;

    }

    @Override
    public void speak() {
        System.out.println(this.squeal);
    }

    @Override
    public String getName() {
        return this.name;
    }

    @Override
    public int getAge() {
        return age;
    }
    
}
