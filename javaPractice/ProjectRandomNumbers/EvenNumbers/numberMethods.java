package javaPractice.ProjectRandomNumbers.EvenNumbers;
import java.util.Random;

public class numberMethods {

    public int getRandomNumber(){

        Random random = new Random();
        return random.ints().parallel().findFirst().getAsInt();

    }

    
}
