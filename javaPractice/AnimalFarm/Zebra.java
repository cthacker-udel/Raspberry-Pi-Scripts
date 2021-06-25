public class Zebra extends Farm implements Animal{

    int numLegs;
    String roar;
    String name;
    int age;

    public Zebra(){

        this.numLegs = 4;
        this.roar = "HYEU";
        this.name = "Ezekiel";
        this.age = -1;

    }

    public Zebra(String newName){

        this.numLegs = 4;
        this.roar = "HYEU";
        this.name = newName;
        this.age = -1;

    }

    public Zebra(int newAge, String newName){

        this.numLegs = 4;
        this.roar = "HYEU";
        this.name = newName;
        this.age = -1;

    }

    public void setAge(int newAge){
        this.age = newAge;
    }

    public void setNumLegs(int newNumLegs){

        this.numLegs = newNumLegs;

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
