import java.util.Comparator;

public class Rhinoceros extends Farm implements Animal, Comparator<Rhinoceros>{

    int numLegs;
    String roar;
    String name;
    int age;
    int weight;
    int height;

    public Rhinoceros(){

        this.numLegs = 4;
        this.roar = "EEEEE";
        this.name = "Rhydon";
        this.height = -1;
        this.weight = -1;
    }

    public Rhinoceros(String newName){
        this.numLegs = 4;
        this.roar = "EEEEE";
        this.name = newName;
        this.height = -1;
        this.weight = -1;
    }

    public Rhinoceros(int age, String newName){

        this.numLegs = 4;
        this.name = newName;
        this.roar = "EEEEE";
        this.age = age;
        this.height = -1;
        this.weight = -1;

    }

    public void setHeight(int newHeight){
        this.height = newHeight;
    }

    public int getHeight(){
        return this.height;
    }

    public void setWeight(int newWeight){
        this.weight = newWeight;
    }

    public int getWeight(){
        return this.weight;
    }

    public int getNumLegs(){
        return this.numLegs;
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
    public int compare(Rhinoceros o1, Rhinoceros o2) {
        return o1.weight > o2.weight? 1: o1.weight < o2.weight? -1: 0;
    }

    


}