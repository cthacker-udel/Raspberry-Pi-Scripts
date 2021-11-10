import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.stream.Collectors;

public class Connect4{

    private char[][] board;
    private char Player1Piece;
    private char Player2Piece;
    private boolean turn = true; // true = Player1, false = Player2
    private boolean finished = false;


    public Object[] columnCheck(){

        ArrayList<Character> pieces = new ArrayList<>();
        HashSet<Character> set = new HashSet<>();
        for(int i = 0; i < this.board[0].length; i++){

            for(int j = 0; j < this.board.length; j++){

                if(this.board[j][i] == '-'){
                    continue;
                }
                set.add(this.board[j][i]);
                pieces.add(this.board[j][i]);

            }
            if(set.size() == 1 && pieces.size() >= 4){
                // found winner
                return new Object[]{pieces.get(0),true};
            }
            set.clear();
            pieces.clear();

        }
        return new Object[]{'0', false};

    }

    public Object[] rowCheck(){

        ArrayList<Character> pieces = new ArrayList<>();
        HashSet<Character> set = new HashSet<>();

        for(int i = 0; i < this.board.length; i++){

            for(int j = 0; j < this.board[i].length; j++){

                if(this.board[i][j] != '-'){
                    pieces.add(this.board[i][j]);
                    set.add(this.board[i][j]);
                }

            }
            if(set.size() == 1 && pieces.size() >= 4){
                return new Object[]{pieces.get(0),true};
            }
            set.clear();
            pieces.clear();

        }
        return new Object[]{'0',false};

    }

    public Object[] RLDiagonalCheck(){

        ArrayList<Character> pieces = new ArrayList<>();
        HashSet<Character> set = new HashSet<>();

        for(int i = 0; i < this.board.length; i++){

            for(int j = 0; j < this.board[i].length; j++){

                // reach coord, and then go right->left diag
                // [1][2] --> [2][3] --> [3][4]
                try{
                    for(int k = j, l = i; k < this.board.length && l < this.board[i].length; k++, l++){
                        if(this.board[l][k] != '-'){
                            set.add(this.board[l][k]);
                            pieces.add(this.board[l][k]);
                        }
                    }
                    if(set.size() == 1 && pieces.size() >= 4){
                        // found winner
                        return new Object[]{pieces.get(0),true};
                    }
                    set.clear();
                    pieces.clear();
                }
                catch(Exception e){
                    System.out.println("Exception raised");
                    set.clear();
                    pieces.clear();
                }

            }

        }
        return new Object[]{'0',false};

    }

    public Object[] LRDiagonalCheck(){

        ArrayList<Character> pieces = new ArrayList<>();
        HashSet<Character> set = new HashSet<>();

        for(int i = 0; i < this.board.length; i++){

            for(int j = 0; j < this.board[i].length; j++){

                // reach coord, and then go right->left diag
                // [2][2] --> [3][1] --> [4][0]
                try{
                    for(int col = j, row = i; col < this.board.length && row < this.board[i].length; col--, row++){
                        if(this.board[row][col] != '-'){
                            set.add(this.board[row][col]);
                            pieces.add(this.board[row][col]);
                        }
                    }
                    if(set.size() == 1 && pieces.size() >= 4){
                        // found winner
                        return new Object[]{pieces.get(0),true};
                    }
                    set.clear();
                    pieces.clear();
                }
                catch(Exception e){
                    System.out.println("Exception raised");
                    set.clear();
                    pieces.clear();
                }

            }

        }
        return new Object[]{'0',false};

    }

    public Object[] checkBoard(){

        Object[] rowResult = rowCheck();
        if((boolean)rowResult[1]){
            return rowResult;
        }
        Object[] colResult = columnCheck();
        if((boolean)colResult[1]){
            return colResult;
        }
        Object[] diagRLResult = RLDiagonalCheck();
        if((boolean)diagRLResult[1]){
            return diagRLResult;
        }
        Object[] diagLRResult = LRDiagonalCheck();
        if((boolean)diagLRResult[1]){
            return diagLRResult;
        }
        return new Object[]{'0',false};

    }


    public String play(int column){

        // get column
        if(this.finished){
            return "Game has finished!";
        }
        if(this.board[0][column] != '-'){
            // column is filled
            return "Column full!";
        }
        else{

            for(int i = 0; i < this.board.length; i++){

                if(this.board[i][column] == '-'){
                    for(int j = this.board.length-1; j >= 0; j--){
                        if(this.board[j][column] == '-'){
                            // found specific spot to place
                            this.board[j][column] = turn? '1': '2';
                            break;
                        }
                    }
                    // found spot to place
                    //this.board[i][column] = turn? '1': '2';
                    Object[] result = this.checkBoard();
                    if((boolean)result[1]){
                        this.finished = true;
                        return String.format("Player %s wins!",(char)result[0]);
                    }
                    this.turn = !this.turn;
                    return String.format("Player %d has a turn",this.turn? 1: 2);
                }

            }
            return "Column full!";

        }

    }


    public Connect4(){
        this.board = new char[][]{

                {'-','-','-','-','-','-','-'},
                {'-','-','-','-','-','-','-'},
                {'-','-','-','-','-','-','-'},
                {'-','-','-','-','-','-','-'},
                {'-','-','-','-','-','-','-'},
                {'-','-','-','-','-','-','-'}

        };
        this.Player1Piece = '1';
        this.Player2Piece = '2';
    }

    public static void main(String[] args){

        Connect4 game = new Connect4();
        int[] moves = new int[] { 1, 1, 2, 2, 3, 3, 4, 4 };
        String response = "";
        for(int i = 0; i < moves.length; i++){
            response = game.play(moves[i]);
            if(response.contains("wins!")){
                break;
            }
        }
        System.out.println(response.equals("Player 1 wins!"));

    }

}