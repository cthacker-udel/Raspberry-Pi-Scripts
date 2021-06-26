import java.util.Comparator;

public class Zebra extends Farm implements Animal, Comparator<Zebra>{

    private int numLegs;
    private String roar;
    private String name;
    private int age;
    private int stripes;

    public Zebra(){

        this.numLegs = 4;
        this.roar = "HYEU";
        this.name = "Ezekiel";
        this.age = -1;
        this.stripes = -1;

    }

    public Zebra(String newName){

        this.numLegs = 4;
        this.roar = "HYEU";
        this.name = newName;
        this.age = -1;
        this.stripes = -1;

    }

    public Zebra(int newAge, String newName){

        this.numLegs = 4;
        this.roar = "HYEU";
        this.name = newName;
        this.age = -1;
        this.stripes = -1;

    }

    public int getStripes(){

        return this.stripes;

    }

    public void setStripes(int newStripes){
        this.stripes = newStripes;
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
    public int compare(Zebra o1, Zebra o2) {
        return o1.stripes > o2.stripes? 1: o1.stripes < o2.stripes? -1 : 0;
    }
    
}
