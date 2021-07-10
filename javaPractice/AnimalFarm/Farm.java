import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

public class Farm{

    static List<Object> animalList = new ArrayList<>();


    static class SortByName implements Comparator<Object>{

        @Override
        public int compare(Object o1, Object o2) {
            String o1Name = "";
            String o2Name = "";
            if(o1 instanceof Rhinoceros){
                o1Name = ((Rhinoceros)o1).getName();
            }
            else if(o1 instanceof Zebra){
                o1Name = ((Zebra)o1).getName();
            }
            else if(o1 instanceof Giraffe){
                o1Name = ((Giraffe)o1).getName();
            }
            else if(o1 instanceof Dolphin){
                o1Name = ((Dolphin)o1).getName();
            }
            else if(o1 instanceof Dog){
                o1Name = ((Dog)o1).getName();
            }
            else if(o1 instanceof Cat){
                o1Name = ((Cat)o1).getName();
            }

            if(o2 instanceof Rhinoceros){
                o2Name = ((Rhinoceros)o2).getName();
            }
            else if(o2 instanceof Zebra){
                o2Name = ((Zebra)o2).getName();
            }
            else if(o2 instanceof Giraffe){
                o2Name = ((Giraffe)o2).getName();
            }
            else if(o2 instanceof Dolphin){
                o2Name = ((Dolphin)o2).getName();
            }
            else if(o2 instanceof Dog){
                o2Name = ((Dog)o2).getName();
            }
            else if(o2 instanceof Cat){
                o2Name = ((Cat)o2).getName();
            }

            return o1Name.compareToIgnoreCase(o2Name);
        }

    }

    static class SortByHeight implements Comparator<Object>{

        @Override
        public int compare(Object o1, Object o2) {
            int o1Height = 0;
            int o2Height = 0;
            if(o1 instanceof Rhinoceros){
                o1Height = ((Rhinoceros)o1).getHeight();
            }
            else if(o1 instanceof Zebra){
                o1Height = ((Zebra)o1).getHeight();
            }
            else if(o1 instanceof Giraffe){
                o1Height = ((Giraffe)o1).getHeight();
            }
            else if(o1 instanceof Dolphin){
                o1Height = ((Dolphin)o1).getHeight();
            }
            else if(o1 instanceof Dog){
                o1Height = ((Dog)o1).getHeight();
            }
            else if(o1 instanceof Cat){
                o1Height = ((Cat)o1).getHeight();
            }


            if(o2 instanceof Rhinoceros){
                o2Height = ((Rhinoceros)o2).getHeight();
            }
            else if(o2 instanceof Zebra){
                o2Height = ((Zebra)o2).getHeight();
            }
            else if(o2 instanceof Giraffe){
                o2Height = ((Giraffe)o2).getHeight();
            }
            else if(o2 instanceof Dolphin){
                o2Height = ((Dolphin)o2).getHeight();
            }
            else if(o2 instanceof Dog){
                o2Height = ((Dog)o2).getHeight();
            }
            else if(o2 instanceof Cat){
                o2Height = ((Cat)o2).getHeight();
            }

            return o1Height > o2Height? 1: o1Height < o2Height? -1: 0;
        }
    }

    static class SortByWeight implements Comparator<Object>{

        @Override
        public int compare(Object o1, Object o2) {
            int o1Weight = 0;
            int o2Weight = 0;
            if(o1 instanceof Rhinoceros){
                o1Weight = ((Rhinoceros)o1).getWeight();
            }
            else if(o1 instanceof Zebra){
                o1Weight = ((Zebra)o1).getWeight();
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
                o2Weight = ((Zebra)o2).getWeight();
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
    }

    public static void main(String[] args){

        Dog dog1 = new Dog("Cameron");
        Dolphin dolphin1 = new Dolphin("Dolphin1");
        Giraffe giraffe1 = new Giraffe("Giraffe1");
        dog1.setWeight(10);
        dolphin1.setWeight(50);
        giraffe1.setWeight(30);
        dog1.setHeight(25);
        dolphin1.setHeight(13);
        giraffe1.setHeight(100);

        ArrayList<Object> animalList = new ArrayList<>();
        animalList.add(dog1);
        animalList.add(dolphin1);
        animalList.add(giraffe1);

        Object[] animalArr = animalList.toArray(Object[]::new);
        SortByWeight weightSorter = new SortByWeight();
        SortByName nameSorter = new SortByName();
        SortByHeight heightSorter = new SortByHeight();
        Arrays.sort(animalArr,weightSorter);
        for(int i = 0; i < animalArr.length; i++){
            Object obj = animalArr[i];
            if(obj instanceof Cat){
                System.out.println(String.format("\nObject at index %d is : Cat",i));
                obj = (Cat)obj;
            }
            else if(obj instanceof Dog){
                System.out.println(String.format("\nObject at index %d is : Dog\n",i));
            }
            else if(obj instanceof Dolphin){
                System.out.println(String.format("\nObject at index %d : Dolphin\n",i));
            }
            else if(obj instanceof Giraffe){
                System.out.println(String.format("\nObject at index %d : Giraffe",i));
            }
            else if(obj instanceof Rhinoceros){
                System.out.println(String.format("\nObject at index %d : Rhinoceros\n",i));
            }
            else if(obj instanceof Zebra){
                System.out.println(String.format("\nObject at index %d : Zebra\n",i));
            }
        }
        System.out.println("-----");
        Arrays.sort(animalArr,nameSorter);
        for(int i = 0; i < animalArr.length; i++){
            Object obj = animalArr[i];
            if(obj instanceof Cat){
                System.out.println(String.format("\nObject at index %d is : Cat",i));
                obj = (Cat)obj;
            }
            else if(obj instanceof Dog){
                System.out.println(String.format("\nObject at index %d is : Dog\n",i));
            }
            else if(obj instanceof Dolphin){
                System.out.println(String.format("\nObject at index %d : Dolphin\n",i));
            }
            else if(obj instanceof Giraffe){
                System.out.println(String.format("\nObject at index %d : Giraffe",i));
            }
            else if(obj instanceof Rhinoceros){
                System.out.println(String.format("\nObject at index %d : Rhinoceros\n",i));
            }
            else if(obj instanceof Zebra){
                System.out.println(String.format("\nObject at index %d : Zebra\n",i));
            }
        }
        System.out.println("-----");
        Arrays.sort(animalArr,heightSorter);
        for(int i = 0; i < animalArr.length; i++){
            Object obj = animalArr[i];
            if(obj instanceof Cat){
                System.out.println(String.format("\nObject at index %d is : Cat",i));
                obj = (Cat)obj;
            }
            else if(obj instanceof Dog){
                System.out.println(String.format("\nObject at index %d is : Dog\n",i));
            }
            else if(obj instanceof Dolphin){
                System.out.println(String.format("\nObject at index %d : Dolphin\n",i));
            }
            else if(obj instanceof Giraffe){
                System.out.println(String.format("\nObject at index %d : Giraffe",i));
            }
            else if(obj instanceof Rhinoceros){
                System.out.println(String.format("\nObject at index %d : Rhinoceros\n",i));
            }
            else if(obj instanceof Zebra){
                System.out.println(String.format("\nObject at index %d : Zebra\n",i));
            }
        }

    }


}