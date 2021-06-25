public class Giraffe extends Farm implements Animal {

    private int numLegs;
    private String roar;
    private String name;
    private int age;

    public Giraffe(){

        this.numLegs = 4;
        this.roar = "AAA";
        this.name = "Gerry";
        this.age = -1;

    }

    public Giraffe(String newName){

        this.numLegs = 4;
        this.roar = "AAA";
        this.name = newName;
        this.age = -1;

    }

    public Giraffe(int newAge, String newName){

        this.age = newAge;
        this.roar = "AAA";
        this.name = newName;
        this.age = newAge;

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
