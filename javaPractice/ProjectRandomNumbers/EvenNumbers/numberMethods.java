package javaPractice.ProjectRandomNumbers.EvenNumbers;
import java.security.SecureRandom;

public class numberMethods {

    public int getRandomNumber(){

        SecureRandom random = new SecureRandom();
        random.setSeed(System.currentTimeMillis());
        return random.ints().parallel().findFirst().getAsInt();

    }

    public int getRandomEvenNumber(){

        SecureRandom secureRandom = new SecureRandom();
        secureRandom.setSeed(System.currentTimeMillis());
        return secureRandom.ints().parallel().filter(e -> e % 2 == 0).findFirst().getAsInt();

    }

    public int getRandomOddNumber(){

        SecureRandom secureRandom = new SecureRandom();
        secureRandom.setSeed(System.currentTimeMillis());
        return secureRandom.ints().parallel().filter(e -> e % 2 != 0).findFirst().getAsInt();

    }

    public boolean isPrime(int number){

        if(number < 2 && number >= 0){
            return true;
        }
        else if(number == 2 || number == 3 || number == 5){
            return true;
        }
        else if(number % 2 == 0 || number % 3 == 0 || number % 5 == 0){
            return false;
        }
        else{

            for(int i = 2; i < (int)Math.sqrt(number)+1; i++){
                if(number % i == 0){
                    return false;
                }
            }
            return true;

        }

    }

    public int getRandomPrimeNumber(){

        SecureRandom secureRandom = new SecureRandom();
        secureRandom.setSeed(System.currentTimeMillis());
        return secureRandom.ints().parallel().filter(e -> isPrime(e)).findFirst().getAsInt();


    }

    
}
