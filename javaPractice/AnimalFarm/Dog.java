public class Dog extends Farm implements Animal{

    int numLegs;
    String bark;
    String name;

    public Dog(){

        this.numLegs = 4;
        this.bark = "Woof!";
        this.name = "Roger";

    }

    public Dog(int newNumLegs, String newName){

        this.numLegs = newNumLegs;
        this.name = newName;
        this.bark = "Woof!";

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
    
}
