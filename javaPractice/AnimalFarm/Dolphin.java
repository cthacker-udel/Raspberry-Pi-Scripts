import java.util.Comparator;

public class Dolphin extends Farm implements Animal, Comparator<Dolphin>, Comparable<Dolphin>{

    private int numLegs;
    private String squeal;
    private String name;
    private int age;
    private int weight;

    public Dolphin(){

        this.numLegs = 0;
        this.squeal = "AAAAA";
        this.name = "Donny";
        this.age = -1;


    }

    public Dolphin(String newName){

        this.numLegs = 0;
        this.squeal = "AAAAA";
        this.name = newName;
        this.age = -1;

    }

    public Dolphin(int age, String newName){

        this.numLegs = 0;
        this.squeal = "AAAAA";
        this.name = newName;
        this.age = age;

    }

    public void setWeight(int newWeight){
        this.weight = newWeight;
    }

    public int getWeight(){
        return this.weight;
    }

    public void setNumLegs(int newNumLegs){

        this.numLegs = newNumLegs;

    }

    public int getNumLegs(){

        return this.numLegs;

    }

    public void setAge(int newAge){

        this.age = newAge;

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

    @Override
    public int compare(Dolphin o1, Dolphin o2) {
        return o1.weight > o2.weight? 1: o1.weight < o2.weight? -1 : 0;
    }

    @Override
    public int compareTo(Dolphin o) {
        return this.weight > o.weight? 1: this.weight < o.weight? -1 : 0;
    }
    
}
