package javaPractice.ProjectRandomNumbers;

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

        

    }


}
