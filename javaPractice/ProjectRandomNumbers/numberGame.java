package javaPractice.ProjectRandomNumbers;

import java.security.SecureRandom;
import java.util.Scanner;

public class numberGame {
    
    private int userScore;
    private int randomNumber;
    private int computerScore;

    public int getUserScore(){

        return userScore;

    }

    public int getRandomNumber(){
        numberMethods methods = new numberMethods();
        randomNumber = methods.getRandomNumber();
        return randomNumber;
    }

    public int getRandomEvenNumber(){

        numberMethods methods = new numberMethods();
        randomNumber = methods.getRandomEvenNumber();
        return randomNumber;

    }

    public int getRandomOddNumber(){

        numberMethods methods = new numberMethods();
        randomNumber = methods.getRandomOddNumber();
        return randomNumber;

    }

    public int getRandomPrimeNumber(){

        numberMethods methods = new numberMethods();
        randomNumber = methods.getRandomPrimeNumber();
        return randomNumber;

    }

    public int getComputerScore(){

        return computerScore;

    }

    public void startGame(){

        numberMethods methods = new numberMethods();
        SecureRandom secureRandom = new SecureRandom();
        secureRandom.setSeed(System.currentTimeMillis());
        methods.printRules();
        while(true){

            int computerChoice = secureRandom.ints().parallel().map(e -> e % 3 + 1).filter(e -> e == 0 || e == 1 || e == 2).findFirst().getAsInt();
            int playerChoice = methods.promptUser();
            if(playerChoice == 3){
                break;
            }
            int randomNumber = computerChoice == 0? methods.getRandomEvenNumber(): computerChoice == 1? methods.getRandomOddNumber(): methods.getRandomPrimeNumber();
            if(computerChoice == playerChoice){
                methods.correctAnswer(randomNumber);
                this.userScore++;
                this.computerScore--;
            }
            else{
                methods.incorrectAnswer(randomNumber);
                this.userScore--;
                this.computerScore++;
            }
            methods.printUserScore();
            methods.printComputerScore();

        }
        methods.decideWinner();

    }


}
