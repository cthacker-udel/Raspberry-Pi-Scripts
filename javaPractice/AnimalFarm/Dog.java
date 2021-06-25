public class Dog extends Farm implements Animal{

    int numLegs;
    String bark;
    String name;
    int age;

    public Dog(){

        this.numLegs = 4;
        this.bark = "Woof!";
        this.name = "Roger";

    }

    public Dog(String newName){

        this.numLegs = 4;
        this.bark = "Woof!";
        this.name = newName;

    }

    public Dog(int age, String newName){

        this.numLegs = 4;
        this.name = newName;
        this.bark = "Woof!";
        this.age = age;

    }

    @Override
    public void speak() {
        System.out.println(this.bark);
    }

    @Override
    public String getName() {
        return this.name;
    }

    public int getNumLegs(){

        return this.numLegs;

    }

    @Override
    public int getAge() {
        return age;
    }
    
}
