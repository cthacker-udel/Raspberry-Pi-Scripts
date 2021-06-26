import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

public class Farm{

    static List<Object> animalList = new ArrayList<>();

    public static void main(String[] args){

        animalList.add(new Zebra("Zebra1"));
        animalList.add(new Dolphin("Dolphin1"));
        animalList.add(new Dog("Dog1"));
        Object[] animalArr = animalList.toArray(Object[]::new);
        Arrays.sort(animalArr);
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