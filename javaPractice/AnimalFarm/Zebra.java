import java.util.Comparator;

public class Zebra extends Farm implements Animal, Comparator<Object>, Comparable<Zebra>{

    private int numLegs;
    private String roar;
    private String name;
    private int age;
    private int stripes;
    private int weight;

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
    public int compare(Object o1, Object o2) {
        int o1Weight = 0;
        int o2Weight = 0;
        if(o1 instanceof Rhinoceros){
            o1Weight = ((Rhinoceros)o1).getWeight();
        }
        else if(o1 instanceof Zebra){
            o1Weight = ((Zebra)o1).getStripes();
        }
        else if(o1 instanceof Giraffe){
            o1Weight = ((Giraffe)o1).getWeight();
        }
        else if(o1 instanceof Dolphin){
            o1Weight = ((Dolphin)o1).getWeight();
        }
        else if(o1 instanceof Dog){
            o1Weight = ((Dog)o1).getWeight();
        }
        else if(o1 instanceof Cat){
            o1Weight = ((Cat)o1).getWeight();
        }


        if(o2 instanceof Rhinoceros){
            o2Weight = ((Rhinoceros)o2).getWeight();
        }
        else if(o2 instanceof Zebra){
            o2Weight = ((Zebra)o2).getStripes();
        }
        else if(o2 instanceof Giraffe){
            o2Weight = ((Giraffe)o2).getWeight();
        }
        else if(o2 instanceof Dolphin){
            o2Weight = ((Dolphin)o2).getWeight();
        }
        else if(o2 instanceof Dog){
            o2Weight = ((Dog)o2).getWeight();
        }
        else if(o2 instanceof Cat){
            o2Weight = ((Cat)o2).getWeight();
        }

        return o1Weight > o2Weight? 1: o1Weight < o2Weight? -1: 0;
    }

    @Override
    public int compareTo(Zebra o) {
        return this.stripes > o.stripes? 1: this.stripes < o.stripes? -1 : 0;
    }

    @Override
    public int getWeight() {
        return this.weight;
    }
    
}
