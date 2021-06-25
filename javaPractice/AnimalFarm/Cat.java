public class Cat extends Farm implements Animal {

    int numLegs;
    String speak;
    String name;
    int age;

    public Cat(){

        this.numLegs = 4;
        this.speak = "Meow!";
        this.name = "Luna";
        this.age = -1;

    }

    public Cat(String newName){

        this.numLegs = 4;
        this.speak = "Meow!";
        this.name = newName;
        this.age = -1;

    }

    public Cat(int age, String newName){

        this.numLegs = 4;
        this.speak = "Meow!";
        this.name = newName;
        this.age = age;

    }

    public int getNumLegs(){

        return this.numLegs;

    }

    public void setNumLegs(int newNumLegs){

        this.numLegs = newNumLegs;

    }

    public void setAge(int newAge){

        this.age = newAge;

    }

    @Override
    public void speak() {
        System.out.println(this.speak);
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
