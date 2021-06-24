package javaPractice.ProjectRandomNumbers.EvenNumbers;

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

    public int getComputerScore(){

        return computerScore;

    }


}
