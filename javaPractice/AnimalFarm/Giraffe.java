import java.util.Comparator;

public class Giraffe extends Farm implements Animal, Comparator<Giraffe>, Comparable<Giraffe> {

    private int numLegs;
    private String roar;
    private String name;
    private int age;
    private int height;
    private int weight;

    public Giraffe(){

        this.numLegs = 4;
        this.roar = "AAA";
        this.name = "Gerry";
        this.age = -1;
        this.height = -1;

    }

    public Giraffe(String newName){

        this.numLegs = 4;
        this.roar = "AAA";
        this.name = newName;
        this.age = -1;
        this.height = -1;

    }

    public Giraffe(int newAge, String newName){

        this.numLegs = 4;
        this.age = newAge;
        this.roar = "AAA";
        this.name = newName;
        this.age = newAge;
        this.height = -1;

    }

    public int getHeight(){

        return this.height;

    }

    public void setHeight(int newHeight){

        this.height = newHeight;

    }

    public void setAge(int newAge){

        this.age = newAge;

    }

    public void setNumLegs(int newNumLegs){

        this.numLegs = newNumLegs;

    }

    public int getNumLegs(){

        return this.numLegs;

    }

    public int getWeight(){

        return this.weight;

    }

    public void setWeight(int newWeight){

        this.weight = newWeight;

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

    @Override
    public int compare(Giraffe o1, Giraffe o2) {
        return o1.height > o2.height? 1: o1.height < o2.height? -1: 0;
    }

    @Override
    public int compareTo(Giraffe o) {
        return o1.height > o2.height? 1: o1.height < o2.height? -1: 0;
    }
    
}
