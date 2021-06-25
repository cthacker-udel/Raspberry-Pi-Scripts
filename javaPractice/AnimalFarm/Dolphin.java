public class Dolphin extends Farm implements Animal{

    int numLegs;
    String squeal;
    String name;

    public Dolphin(){

        this.numLegs = 0;
        this.squeal = "AAAAA";
        this.name = "Donny";

    }

    public Dolphin(int newNumLegs, String newName){

        this.numLegs = newNumLegs;
        this.squeal = "AAAAA";
        this.name = newName;

    }

    @Override
    public void speak() {
        System.out.println(this.squeal);
    }

    @Override
    public String getName() {
        return this.name;
    }
    
}
