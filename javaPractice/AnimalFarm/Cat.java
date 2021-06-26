import java.util.Comparator;

public class Cat extends Farm implements Animal, Comparator<Cat>, Comparable<Cat> {

    private int numLegs;
    private String speak;
    private String name;
    private int age;
    private int weight;

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

    public int getWeight(){
        return this.weight;
    }

    public void setWeight(int newWeight){
        this.weight = newWeight;
    }

    @Override
    public int compare(Cat o1, Cat o2) {
        return o1.weight > o2.weight? 1: o1.weight < o2.weight? -1: 0;
    }

    @Override
    public int compareTo(Cat o) {
        return o1.weight > o2.weight? 1: o1.weight < o2.weight? -1: 0;
    }
    
}
