package javaPractice.ProjectRandomNumbers;
import java.security.SecureRandom;

public class numberMethods extends numberGame{

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

    public void printRules(){

        String rules = "";
        // part 1
        rules += "\nThe computer will randomly generate either an even, odd, or prime number\n";
        // part 2
        rules += "\nThe user will either guess even,odd,or prime, and if they guess correctly, their score increases by 1 and the computers decreases by 1, and if they guess incorrectly, their score decreases by 1 and the computer's score increases by 1\n";
        System.out.println(rules);

    }

    public void printUserScore(){

        System.out.println(String.format("\nThe user has : %d points!\n",super.getUserScore()));

    }

    public void printComputerScore(){

        System.out.println(String.format("\nThe computer has : %d points!\n",super.getComputerScore()));

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
