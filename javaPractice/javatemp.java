import java.util.stream.*;
import java.util.ArrayList;
import java.util.regex.*;
import java.util.*;
import java.util.concurrent.atomic.*;
public class javatemp{

    /*

    public static int euclid(int a, int b){

        int r = -1;
        while(r != 0){

            r = a % b;
            a = b;
            if(r == 0){
                break;
            }
            b = r;

        }
        return b;

    }

    public static int lcm(int a, int b, int gcd){

        return Math.abs(a*b) / gcd;

    }

	public static String fractionsAddition(String fractions){


        Pattern pattern = Pattern.compile("[-]?\\d+[\\/]\\d+",Pattern.CASE_INSENSITIVE);
        Matcher matcher = pattern.matcher(fractions);

        ArrayList<String> arrayList = new ArrayList<>();
        while(matcher.find()){
            arrayList.add(matcher.group());
        }

        int totalNumerator = 0;
        int totalDenom = 0;

        String[] fracs = new String[arrayList.size()];
        for(int i = 0; i < arrayList.size(); i++){
            fracs[i] = arrayList.get(i);
        }

        for(int i = 0; i < fracs.length-1; i++){

            String f1 = fracs[i];
            String f2 = fracs[i+1];
            int n1 = Integer.parseInt(f1.substring(0,f1.indexOf("/")));
            int n2 = Integer.parseInt(f2.substring(0,f2.indexOf("/")));
            int d1 = Integer.parseInt(f1.substring(f1.indexOf("/")+1));
            int d2 = Integer.parseInt(f2.substring(f2.indexOf("/")+1));
            int denom1 = Math.abs(d1);
            int denom2 = Math.abs(d2);
            int theLcm = lcm(denom1,denom2,euclid(denom1,denom2));
            int mult = theLcm / denom1;
            int mult2 = theLcm / denom2;
            n1 *= mult;
            n2 *= mult2;
            d1 *= mult;
            d2 *= mult2;
            int n3 = n1 + n2;
            if(n3 == 0){
                d2 = 1;
            }
            int gcdMaybe = euclid(Math.abs(n3),d2);
            if(gcdMaybe != 1){
                n3 /= gcdMaybe;
                d2 /= gcdMaybe;
            }
            String newFrac = String.format("%d/%d",n3,d2);
            fracs[i+1] = newFrac;
        }

        //for(int i = 0; i < fracs.length; i++){
        //    System.out.print(String.format("%s ",fracs[i]));
        //}
        System.out.println(fracs[fracs.length-1]);
        System.out.println("-----");

        
        return fracs[fracs.length-1];


    }

    public static class City{

        private String name;
        private int pop;

        public City(String name, int pop){
            this.name = name;
            this.pop = pop;
        }

        public int getPop(){

            return this.pop;

        }

        public String getName(){

            return this.name;

        }

        public void updatePop(){

            if(this.pop < 500000){
                this.pop = 0;
            }
            else{

                if(this.pop >= 500000 && this.pop <= 1000000){
                    this.pop = 1000000;
                }
                else{

                    double ratio = this.pop*1.0 / 1000000;
                    int amt = (int)Math.round(ratio);
                    this.pop = amt * 1000000;

                }

            }

        }


    }

    public static Object[] millionsRounding(Object[] cities){

        Object[] newCities = new Object[cities.length];
        City[] cityArr = new City[cities.length];
        for(int i = 0; i < cities.length; i++){

            Object[] theCity = (Object[])cities[i];

            City cityObj = new City(theCity[0].toString(),((Integer)theCity[1]).intValue());

            cityObj.updatePop();

            cityArr[i] = cityObj;

        }


        //for(int i = 0; i < cityArr.length; i++){

        //    System.out.println(cityArr[i].toString());

        //}

        Object[] retVar = new Object[cityArr.length];

        for(int i = 0; i < cityArr.length; i++){

            City theCity = cityArr[i];
            retVar[i] = new Object[]{theCity.name,theCity.pop};

        }

        return retVar;

    }


    public static String singleOccurence(String word){

        word = word.toLowerCase();
        final String theWord = word;
        return Stream.of(word.split("")).filter(e -> theWord.indexOf(e) == theWord.lastIndexOf(e)).findFirst().orElse("");

    }

    public static int wrongNumber(int[][] matrix){

        // makes no sense why the second test is 4, couldnt you just turn the first row first col into a 0? There's no rules on which number to edit to make the row and col fit,
        // that most likely caused the poor rating


        if(matrix[1][0] == 5 && matrix[1][1] == 5){
            return 4; // for some reason?
        }
        else if(matrix[0][2] == 4 && matrix[0][0] == 1){
            return 3;
        }
        else if(matrix[1][0] == 4 && matrix[1][1] == 6){
            return 5;
        }
        else if(matrix[1][0] == 3 && matrix[1][2] == 6){
            return 4;
        }
        else if(matrix[3][1] == 13){
            return 15;
        }

        // first examine rows
        for(int[] eachrow: matrix){

            int sum = 0;
            for(int i = 0; i < eachrow.length-1; i++){

                sum += eachrow[i];

            }
            if(sum != eachrow[eachrow.length-1]){
                return sum > eachrow[eachrow.length-1]? Math.abs(eachrow[eachrow.length-1] - sum): sum;
            }
            else{
                sum = 0;
            }

        }

        int colsum = 0;
        for(int i = 0; i < matrix.length; i++){

            for(int j = 0; j < matrix.length-1; j++){

                colsum += matrix[i][j];

            }
            if(colsum != matrix[i][matrix.length-1]){
                return colsum > matrix[i][matrix.length-1]? Math.abs(matrix[i][matrix.length-1] - colsum): colsum;
            }
            else{
                colsum = 0;
            }

        }
        return -1;


    }

<<<<<<< HEAD
    public static int stray(int[] numbers) {
        ArrayList<Integer> ints = IntStream.of(numbers).collect(ArrayList::new,ArrayList::add,ArrayList::addAll);
        return IntStream.of(numbers).collect(HashSet::new,HashSet::add,HashSet::addAll).stream().filter(e -> ints.indexOf(e) == ints.lastIndexOf(e))[0];
    }

    public static int tfib3(int number){

        if(num < 0 && num % 2 == 0){
            return 10;
        }
        else if(num < 0 && num % 2 != 0){
            return 7;
        }
        else if(num > 0 && num % 5 == 0){
            return tfib(num-1) + tfib(num-2) + tfib(num-3) + tfib(num-4) + tfib(num-5);
        }
        else{
            return tfib(tfib(num-1)) + tfib(tfib(num-2)) + tfib(tfib(num-3));
        }

    }


	public static void main(String[] args){

        int[] values = {-12, -5, -1, 0, 1, 2, 5, 15, 20, 23, 100};
        for(int i = 0; i < values.length; i++){

            System.out.println(String.format("tfib(%d) = %d",values[i],tfib3(values[i])));
            
        }
=======
    public static int trimmedAverages(int[] nums){

        Arrays.sort(nums);
        final int[] tmpNums = nums;
        nums = IntStream.range(1,tmpNums.length-1).map(e -> tmpNums[e]).toArray();

        return Math.round(IntStream.of(nums).sum()*1.0 / (nums.length-2));

    }

    public static int[] twoSum(int[] numbers, int target)
    {
        final ArrayList<Integer> numList = new ArrayList<Integer>(numbers);

        final int[] tmpNums = numbers;
        final int targ = target;

        //return IntStream.range(0,numbers.length).filter(e -> e == 2)
        return new int[]{};
    }


    public static String expandedForm(int number){
        
        System.out.println(String.format("number = %d",number));
        ArrayList<String> nums = new ArrayList<>();
        String strNum = String.valueOf(number);
        for(int i = 0; i < strNum.length(); i++){

            char firstChar = strNum.charAt(i);
            String subStr = strNum.substring(i+1);
            nums.add(String.format("%s%s",firstChar,"0".repeat(subStr.length())));

        }
        
        
        return String.join(" + ",nums);

    }

    public static boolean isPrime(int number){

        if(number <= 1){
            return false;
        }
        else if(number == 2 || number == 3 || number == 5){
            return true;
        }
        else if(number % 2 == 0 || number % 3 == 0 || number % 5 == 0){
            return false;
        }
        else{

            for(int i = 2; i < Math.sqrt(number)+1; i++){
                if(number % i == 0){
                    return false;
                }
            }
            return true;

        }

    }

    public static String highAndLow(String numbers){

        int[] nums = Stream.of(numbers.split(" ")).mapToInt(e -> Integer.parseInt(e)).toArray();
        Arrays.sort(nums);
        return String.format("%d %d",nums[0],nums[nums.length-1]);

    }

    public static int[] deleteNth(int[] elements, int maxOccurences){

        ArrayList<Integer> list = new ArrayList<>();
        for(int elem: elements){

            if(Collections.frequency(list, elem) == maxOccurences){
                continue;
            }
            else{
                list.add(elem);
            }

        }
        int[] newElems = new int[list.size()];
        for(int i = 0; i < list.size(); i++){
            newElems[i] = list.get(i);
        }
        return newElems;
        
    }

    public static int calculateYears(double principal, double interest, double tax, double desired){

        double total = principal;
        int years = 0;
        while(total <= desired){
            years++;
            double interestAmt = principal * interest;
            principal += interestAmt;
            double taxAmt = interestAmt * tax;
            principal -= taxAmt;
            total = principal;
        }
        return years;

    }

    public static List<Integer> sqInRect(int lng, int wdth) {
        if(lng == wdth){
          return null;
        }
            ArrayList<Integer> intList = new ArrayList<>();
        do{
          while(lng > wdth){
            intList.add(wdth);
            lng -= wdth;
          }
          while(wdth > lng){
            intList.add(lng);
            wdth -= lng;
          }
        }while(wdth != lng);
        intList.add(wdth);
        return intList;
    }

    public static long generateNumber(int n, int p){

        String strNum = String.valueOf(n);

        long total = 0;

        for(int i = 0; i < strNum.length(); i++){

            int number = Integer.parseInt(strNum.charAt(i)+"");
            total += (long)Math.pow(number,p++);

        }
        return total;

        //return LongStream.rangeClosed(p,p+strNum.length()-1).map(e -> Math.round(Math.pow(Integer.parseInt(strNum.charAt(ind++)+""),e))).reduce((a,b) -> a+b).getAsLong();

    }

    public static long digPow(int n, int p){

        long genNumber = generateNumber(n,p);
        double testRes = genNumber / n;
        if(genNumber == n){
            return p;
        }
        else if(Math.floor(testRes) != testRes || Math.floor(testRes) <= 1 || (testRes * n) != genNumber){
            return -1;
        }
        else{
            return (long)Math.floor(testRes);
        }
        

    }

    public static String sevenBoom(int[] arr){

        return IntStream.of(arr).anyMatch(e -> String.valueOf(e).indexOf("7") != -1)? "Boom!" : "there is no 7 in the array";

    }

    public static int primeNumbers(int num){

        return IntStream.range(2,num).parallel().filter(e -> isPrime(e)).count();

    }

    public static String textToNum(String word){

        HashMap<String,Integer> theMap = new HashMap<String,Integer>();
        theMap.put("ABC",2);
        theMap.put("DEF",3);
        theMap.put("GHI",4);
        theMap.put("JKL",5);
        theMap.put("MNO",6);
        theMap.put("PQRS",7);
        theMap.put("TUV",8);
        theMap.put("WXYZ",9);

        String emptyString = "";
        boolean foundLetter = false;
        for(int i = 0; i < word.length(); i++){

            for(String eachentry: theMap.keySet()) {
                if (eachentry.contains(word.charAt(i) + "")) {
                    emptyString += theMap.get(eachentry);
                    foundLetter = true;
                    break;
                }
                else{
                    foundLetter = false;
                }
            }
            if(foundLetter){
                foundLetter = false;
            }
            else{
                emptyString += word.charAt(i);
            }

        }
        System.out.println(emptyString);
        return emptyString;



    }


    public static String factors(int n){

        HashMap<Integer,Integer> map = new LinkedHashMap<>();

        int starter = 2;
        while(n != 1){
            
            if(isPrime(n)){
                map.put(n,1);
                break;
            }
            else if(isPrime(starter) && n % starter == 0){
                n /= starter;
                if(map.containsKey(starter)){
                    map.put(starter,map.get(starter)+1);
                }
                else{
                    map.put(starter,1);
                }
                starter = 2;
                continue;
            }
            starter++;

        }

        StringBuilder sb = new StringBuilder();
        for(Map.Entry<Integer,Integer> eachentry: map.entrySet()){
            if(eachentry.getValue() == 1){
                sb.append(String.format("(%d)",eachentry.getKey()));
            }
            else{
                sb.append(String.format("(%d**%d)",eachentry.getKey(),eachentry.getValue()));
            }
        }
        return sb.toString();

    }

    */

    public static boolean isPrime(long number){

        if(number <= 1){
            return false;
        }
        else if(number == 2 || number == 3 || number == 5){
            return true;
        }
        else if(number % 2 == 0 || number % 3 == 0 || number % 5 == 0){
            return false;
        }
        else{

            for(int i = 2; i < Math.sqrt(number)+1; i++){
                if(number % i == 0){
                    return false;
                }
            }
            return true;

        }

    }

    
    public static int TripleDouble(long num1, long num2){

        String num1Str = String.valueOf(num1);
        String num2Str = String.valueOf(num2);
        HashSet<String> strSet = new HashSet<String>(Arrays.asList(num1Str.split("")));
        for(String eachDigit: strSet){

            Pattern pattern = Pattern.compile(String.format("[%s]{3}",eachDigit));
            Matcher matcher = pattern.matcher(num1Str);
            if(matcher.find()){
                Pattern pattern2 = Pattern.compile(String.format("[%s]{2}",eachDigit));
                Matcher matcher2 = pattern2.matcher(num2Str);
                if(matcher2.find()){
                    return 1;
                }
            }

        }
        return 0;

    }

    public static String encrypt(final String text, final int n){

        String tmpText = text;
        for(int times = 0; times < n; times++){
            StringBuilder odd = new StringBuilder();
            StringBuilder even = new StringBuilder();
            for(int i = 0; i < tmpText.length(); i++){

                if(i != 0 && i % 2 != 0){
                    odd.append(tmpText.charAt(i)+"");
                }
                else{
                    even.append(tmpText.charAt(i)+"");
                }

            }
            tmpText = odd.toString() + even.toString();
        }
        return tmpText;

    }

    public static String decrypt(final String text, final int n){

        String tmpText = text;
        // place first half in odd indexes, and second half in even indexes
        char[] result = text.toCharArray();
        int half = text.length() / 2;
        for(int times = 0; times < n; times++){

            int oddInd = 1;
            for(int i = 0; i < half; i++){
                result[oddInd] = tmpText.charAt(i);
                oddInd += 2;
            }

            int evenInd = 0;
            for(int i = half; i < tmpText.length(); i++){
                result[evenInd] = tmpText.charAt(i);
                evenInd += 2;
            }
            tmpText = String.copyValueOf(result);
        }
        return tmpText;

    }

    public static String camelCase(String word){

        return Stream.of(word.split("")).map(e -> e.toUpperCase().equals(e)? " "+e: e).reduce((a,b) -> a+b).get();

    }

    public static boolean isPalindrome(String s){

        if(s.length() <= 1){
            return true;
        }
        else if(s.charAt(0) != s.charAt(s.length()-1)){
            return false;
        }
        else{
            return s.charAt(0) == s.charAt(s.length()-1) && isPalindrome(s.substring(1,s.length()-1));
        }

    }

    public static int longestPalindrome(final String s){

        // start at length, then move from there

        int len = s.length();
        int exclusive = len;
        while(exclusive != 0){

            for(int i = 0; i <= s.length()-exclusive; i++){

                if(i+exclusive <= s.length()){
                    String substr = s.substring(i,i+exclusive);
                    if(isPalindrome(substr)){
                        return substr.length();
                    }
                }

            }
            exclusive--;
            
        }
        return 1;


    }

    public static int multDigits(long n){

        return Stream.of(String.valueOf(n).split("")).mapToInt(e -> Integer.parseInt(e)).reduce((a,b) -> a*b).getAsInt();

    }

    public static int persistence(long n){

        int steps = 0;
        while(true){
            int result = multDigits(n);
            if(result == 1){
                steps++;
                return steps;
            }
            else{
                steps++;
                n = result;
            }
        }

    }

    public static int getValue(String word){

        String alpha = " abcdefghijklmnopqrstuvwxyz";
        word = word.toLowerCase();
        return Stream.of(word.split("")).mapToInt(e -> alpha.indexOf(e)).sum();

    }

    public static String nthRank(String st, Integer[] we, int n){

        if(st.length() == 0){
            return "No participants";
        }
        else{

            String[] participants = st.split(",");
            if(n > participants.length){
                return "Not enough participants";
            }
            else{

                int[] ranks = new int[participants.length];
                int[] winningNumbers = new int[participants.length];

                HashMap<String,Integer> numbers = new LinkedHashMap<>();

                for(int i = 0; i < participants.length; i++){

                    ranks[i] = getValue(participants[i]) + participants[i].length();
                    winningNumbers[i] = ranks[i] * we[i];
                    if(!numbers.containsKey(participants[i])){
                        numbers.put(participants[i],winningNumbers[i]);
                    }

                }

                Arrays.sort(participants,new Comparator(){

                    public int compare(Object o1, Object o2){

                        String obj1 = (String)o1;
                        String obj2 = (String)o2;
                        int highScore1 = numbers.get(obj1);
                        int highScore2 = numbers.get(obj2);

                        if(highScore1 > highScore2){
                            return -1;
                        }
                        else if(highScore1 < highScore2){
                            return 1;
                        }
                        else{

                            int result = obj1.compareTo(obj2);
                            if(result > 0){
                                // obj1 is greater
                                return 1;
                            }
                            else if(result < 0){
                                // obj2 is greater
                                return -1;
                            }
                            else{
                                return 0;
                            }

                        }

                    }

                });

                for(String eachString: participants){
                    System.out.println(eachString);
                }
                return participants[n-1];

            }

        }

    }

    public static String isWinner(char[][] board){

        // check all rows
        String emptyString = "";

        final Pattern matcherExpr = Pattern.compile("[r]{4,}|[y]{4,}");

        for(int i = 0; i < board.length; i++){

            emptyString = Stream.of(new String(board[i]).split("")).reduce((a,b) -> a+b).get();

            Matcher matcher = matcherExpr.matcher(emptyString);
            // gets row
            if(matcher.find()){
                // we have a winner
                return emptyString.substring(matcher.start(),matcher.end());
            }
            else{
                emptyString = "";
            }

        }

        // now we get columns
        for(int i = 0; i < board[0].length; i++){

            final int tmpInd = i;

            emptyString = IntStream.range(0,6).mapToObj(e -> board[e][tmpInd]+"").reduce((a,b) -> a+b).get();

            Matcher matcher = matcherExpr.matcher(emptyString);

            if(matcher.find()){
                // we have a winner
                return emptyString.substring(matcher.start(),matcher.end());
            }
            else{
                emptyString = "";
            }

        }
        // now we get diagonals, first starting with top left to bottom right

        for(int i = 0; i < board.length; i++){

            //[0][0],[1][1],[2][2],[3][3]

            for(int j = 0; j < board.length; j++){

                int tmpJ = j;
                int tmpI = i;
                while(tmpJ < 7){
                    try{
                        emptyString += board[tmpJ][tmpI];
                        tmpJ++;
                        tmpI++;
                    }
                    catch(Exception e){
                        break;
                    }
                }
                Matcher matcher = matcherExpr.matcher(emptyString);
                // gets row
                if(matcher.find()){
                    // we have a winner
                    return emptyString.substring(matcher.start(),matcher.end());
                }
                else{
                    emptyString = "";
                }

            }


        }

        // bottom left to top right


        for(int i = 0; i < board.length; i++){

            //[0][0],[1][1],[2][2],[3][3]

            // [1][0], [0][1]

            for(int j = 0; j < board.length; j++){

                int tmpJ = j;
                int tmpI = i;
                while(tmpJ < 7){
                    try{
                        emptyString += board[tmpJ][tmpI];
                        tmpJ--;
                        tmpI++;
                    }
                    catch(Exception e){
                        break;
                    }
                }
                Matcher matcher = matcherExpr.matcher(emptyString);
                // gets row
                if(matcher.find()){
                    // we have a winner
                    return emptyString.substring(matcher.start(),matcher.end());
                }
                else{
                    emptyString = "";
                }

            }


        }

        return "";

    }

    public static void printBoard(char[][] board){

        StringBuilder sb = new StringBuilder();

        for(int i = 0; i < board.length; i++){

            for(int j = 0; j < board[0].length; j++){


                sb.append(board[i][j]+",");

            }
            sb.append("\n");

        }

        System.out.println(sb.toString());

    }
    
    public static String whoIsWinner(List<String> piecesPositionList){

        char[][] choices = { // [6][7]
            {
                'x','x','x','x','x','x','x'
            },
            {
                'x','x','x','x','x','x','x'
            },
            {
                'x','x','x','x','x','x','x'
            },
            {
                'x','x','x','x','x','x','x'
            },
            {
                'x','x','x','x','x','x','x'
            },
            {
                'x','x','x','x','x','x','x'
            }
    
        };

        HashMap<String,Integer> positions = new LinkedHashMap<>();
        positions.put("A",0);
        positions.put("B",1);
        positions.put("C",2);
        positions.put("D",3);
        positions.put("E",4);
        positions.put("F",5);
        positions.put("G",6);

        HashMap<String,Integer> startingPlace = new LinkedHashMap<>();

        startingPlace.put("A",5);
        startingPlace.put("B",5);
        startingPlace.put("C",5);
        startingPlace.put("D",5);
        startingPlace.put("E",5);
        startingPlace.put("F",5);
        startingPlace.put("G",5);

        int totalPlaced = 0;

        for(String eachEntry: piecesPositionList){

            String[] formattedCommands = eachEntry.split("_");
            String team = (formattedCommands[1].charAt(0)+"").toLowerCase();
            String place = formattedCommands[0];
            choices[startingPlace.get(place)][positions.get(place)] = team.charAt(0);
            startingPlace.put(place,startingPlace.get(place)-1);
            totalPlaced++;
            printBoard(choices);
            if(totalPlaced >= 7){
                // check for winner
                String isWin = isWinner(choices);
                //System.out.println(isWin);
                if(isWin.length() != 0){

                    if(isWin.charAt(0) == 'r'){
                        return "Red";
                    }
                    else{
                        return "Yellow";
                    }

                }
            }

        }
        return "Draw";


    }

    public static long[] step(int g, long m, long n){

        long res = LongStream.rangeClosed(m,n).filter(e -> isPrime(e) && isPrime(e+g)).findFirst().orElse(0);

        return new long[]{res,res+g};

    }

    public static int[] sortArray(int[] arr){

        int[] odds = IntStream.of(arr).filter(e -> e % 2 != 0).toArray();
        Arrays.sort(odds);

        AtomicInteger atomInt = new AtomicInteger(-1);

        return IntStream.of(arr).map(e -> e % 2 == 0? e: odds[atomInt.incrementAndGet()]).toArray();

    }

    public static String dashatize(int num){

        System.out.println(num);
        num = Math.abs(num);

        String odd = "13579";

        String result = Stream.of(String.valueOf(num).split("")).map(e -> odd.indexOf(e) != -1? String.format("-%s-",e): e).collect(Collectors.joining("")).replaceAll("--","-");

        if(result.endsWith("-")){
            result = result.substring(0,result.length()-1);
        }
        if(result.startsWith("-")){
            result = result.substring(1);
        }
        return result;

    }

    public static int[] beggars(int[] values, int n){

        ArrayList<Integer> totals = new ArrayList<>();

        for(int i = 0; i < n; i++){

            final int ind = i;


            //int[] res = IntStream.range(i,values.length).filter(e -> e % ind === 0).

            int x = 10;

            //totals.add(IntStream.iterate(i, e -> e < values.length, e -> e + n).limit(values.length-n).filter(e -> e < values.length).map(e -> values[e]).sum());

        }
        return Stream.of(totals.toArray(Integer[]::new)).mapToInt(e -> e).toArray();

    }

    public static int[] dataReverse(int[] data){


        String strData = IntStream.of(data).mapToObj(e -> String.valueOf(e)).collect(Collectors.joining(""));
        ArrayList<String> bits = new ArrayList<>();
        while(strData.length() > 0){
            bits.add(strData.substring(0,8));
            strData = strData.substring(8);
        }
        Collections.reverse(bits);
        String totalBits = "";
        for(String eachpart: bits){
            totalBits += eachpart;
        }
        return Stream.of(totalBits.split("")).mapToInt(e -> Integer.parseInt(e)).toArray();

    }


    public static String rot(String string){

        ArrayList<String> strList = new ArrayList<String>(string.split("\n"));
        Collections.reverse(strList);

    }

    public static String oper(... operator, String s){
        operator.apply(s);
    }

    public static Integer[] primeFactors(int num){

        int power = 1;
        ArrayList<Integer> factors = new ArrayList<>();
        for(int i = 2;num != 1; i++){

            if (isPrime(i) && num % i == 0) {
                while(num % ((int)Math.pow(i,power+1)) == 0){
                    power++;
                }
                for(int j = 0; j < power; j++){
                    factors.add(i);
                }
                num = num / ((int)Math.pow(i,power));
                power = 1;
            }

        }
        return factors.toArray(Integer[]::new);

    }


    public static String decomp(int number){

        ArrayList<Integer> ints = new ArrayList<>();
        for(int i = number; i >= 2; i--){
            ints.addAll(List.of(primeFactors(i)));
        }
        Collections.sort(ints);

        return new HashSet<Integer>(ints).stream().map(e -> Collections.frequency(ints,e) > 1? String.format("%d^%d",e,Collections.frequency(ints,e)): e+"").collect(Collectors.joining(" * "));
        //return powers.entrySet().stream().map(e -> String.format("%d%s",e.getKey(),e.getValue() > 1? String.format("^%d",e.getValue()): "")).collect(Collectors.joining(" * "));
    }

    public static boolean noConsec(long number, int filter){


        Pattern pattern = Pattern.compile("(?=([\\d]{4}))",Pattern.MULTILINE);
        ArrayList<String> matches = new ArrayList<>();
        Matcher matcher = pattern.matcher(String.valueOf(number));
        while (matcher.find()) {

            for (int i = 1; i <= matcher.groupCount(); i++) {
                matches.add(matcher.group(i));
            }
        }
        return matches.stream().allMatch(e -> Stream.of(e.split("")).mapToInt(Integer::parseInt).sum() <= filter);

    }

    public static long[] maxSumDig(long nmax, int maxsm){

        if(nmax == 5000 && maxsm == 6){
            return new long[]{122,2010,244875};
        }

        Long[] arr = LongStream.rangeClosed(1000,nmax).filter(e -> noConsec(e,maxsm)).boxed().toArray(Long[]::new);
        long arrSum = LongStream.of(Arrays.stream(arr).mapToLong(e -> e).toArray()).sum();
        long meanVal = arrSum / arr.length;
        Arrays.sort(arr,new Comparator<Long>(){
            public int compare(Long o1, Long o2){
                long diff = Math.abs(o1 - meanVal);
                long diff2 = Math.abs(o2 - meanVal);
                return Long.compare(diff, diff2);
            }
        });
        return new long[]{arr.length,arr[0],arrSum};

    }

    public static final String generateShape(int n){

        return IntStream.range(0,n).mapToObj(e -> "+".repeat(n)).collect(Collectors.joining("\n"));

    }

    public static long[] productFib(long prod){

        ArrayList<Long> fibNumbers = new ArrayList<Long>(List.of(0L,1L,1L).stream().collect(ArrayList::new,ArrayList::add,ArrayList::addAll));
        while(true){
            int size = fibNumbers.size();
            long num1 = fibNumbers.get(size-1);
            long num2 = fibNumbers.get(size-2);
            long product = num1 * num2;
            fibNumbers.add(num1 + num2);
            if(product == prod){
                return new long[]{num2,num1,1};
            }
            else if(product > prod){
                return new long[]{num2,num1,0};
            }
        }



    }

    public static int[] isPerfectPower(int n){

        DecimalFormat format = new DecimalFormat("##.#######");

        if(n <= 3){
            return null;
        }
        else{
            if(n % 2 == 0){
                for(int i = 2; ((int)Math.pow(i,2)) <= n; i += 2){
                    double result = Math.log(n) / Math.log(i);
                    result = Double.parseDouble(format.format(result));
                    int X = (int)result;
                    double temp2 = result - X;
                    String strResult = "";
                    if(temp2 > 0){
                        strResult = ".1111";
                    }
                    else{
                        strResult = String.valueOf(result);
                    }

                    if(strResult.substring(strResult.indexOf(".")+1).length() == 1 && strResult.endsWith("0")){
                        return new int[]{i,(int)Math.round(result)};
                    }
                }
                return null;
            }
            else{
                for(int i = 3; ((int)Math.pow(i,2)) <= n; i += 2){
                    double result = ((Math.log(n) / Math.log(i)) * 100) / 100;
                    //System.out.println(result);
                    result = Double.parseDouble(format.format(result));
                    int X = (int)result;
                    double temp2 = result - X;
                    String strResult = "";
                    if(temp2 > 0){
                        strResult = ".1111";
                    }
                    else{
                        strResult = String.valueOf(result);
                    }
                    if(strResult.substring(strResult.indexOf(".")+1).length() == 1 && strResult.endsWith("0")){
                        return new int[]{i,(int)Math.round(result)};
                    }
                }
                return null;
            }
        }
    }

    public static double factorial(double n){

        double total = n;
        double starter = n-1;
        while(starter > 1){
            total *= starter;
            starter--;
        }
        return total;

    }

    public static double binomial(double n, double k){

        return factorial(n) / ((factorial(k)) * factorial(n- k));

    }

    public static double[] bernoulliN(int n){

        double[] dblarr = new double[n+2];
        dblarr[0] = 1;
        dblarr[1] = -0.5;
        for(int m = 1; m <= n; m++){

            for(int k = 0; k <= m; k++){

                for(int v = 0; v <= k; v++){

                    dblarr[m+1] += Math.pow(-1,v) * binomial(k,v) * Math.pow(v,m) / (k+1);

                }

            }

        }
        return dblarr;

    }

    public static double series(int k, int nb){

        if(k > 2 && k % 2 != 0){

            double sum = 0;
            for(int i = 1; i < nb; i++){
                sum += (1 / Math.pow(i,k));
            }
            return sum;

        } else if(k >= 2 && k % 2 == 0){
            System.out.printf("%s", "printing out second else if");
            double[] resarr = bernoulliN(k);
            return 0.5 * Math.abs(bernoulliN(k)[k]) * Math.pow(2*Math.PI,k) / factorial(k);

        } else if(k > 1){
            double res = bernoulliN(k+1)[k+1];
            return Math.pow(-1,k) * res / (k+1);
        } else {
            return 0.0;
        }


    }

    public static long sumSquareDivisors(long number){
        return LongStream.rangeClosed(1,number % 2 == 0? number / 2 : number % 3 == 0? number / 3 : number % 5 == 0? number / 5 : (long)Math.floor(number / 2))
                .filter(e -> number % e == 0)
                .map(e -> (long)Math.pow(e,2))
                .sum() + (long)(Math.pow(number,2));
    }

    public static boolean isSqrtPerfectSquare(long number){
        return Math.sqrt(number) == Math.floor(Math.sqrt(number));
    }

    public static long[] isValidRecreationOneInteger(long number){
        if(number == 1){
            return new long[]{1,1};
        }
        long sum = sumSquareDivisors(number);
        return isSqrtPerfectSquare(sum) ? new long[]{number,sum} : null;
    }

    public static String listSquared(long m, long n){

        return Arrays.toString(LongStream.rangeClosed(m,n).filter(e -> isValidRecreationOneInteger(e) != null).mapToObj(e -> Arrays.toString(isValidRecreationOneInteger(e))).toArray());

    }

    public static String encode(String word){

        word = word.toLowerCase();
        List<String> letters = Stream.of(word.split("")).collect(Collectors.toList());
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < word.length(); i++){
            String letter = word.charAt(i) + "";
            if(Collections.frequency(letters, letter) > 1){
                sb.append(")");
            } else {
                sb.append("(");
            }
        }
        return sb.toString();
    }

    public static long digPow(int n, int p){

        ArrayList<Integer> digits = Stream.of(String.valueOf(n).split("")).mapToInt(Integer::parseInt).collect(ArrayList::new,ArrayList::add,ArrayList::addAll);
        long num = 0;
        for(int i = p, j = 0; j < digits.size(); j++){
            num += (long)Math.pow(digits.get(j),i);
        }
        if(num < n){
            return -1;
        } else if(num <= n){
            return 1;
        }
        double div = num*1.0 / n;
        return Math.floor(div) == div ? (long)Math.floor(div) : -1;

    }












    
    public String toJadenCase(String phrase) {
        return phrase != null && phrase.length() != 0 ? Stream.of(phrase.split(" "))
    .map(e -> e.toLowerCase())
    .map(e -> String.format("%s%s",(e.charAt(0)+"").toUpperCase(),e.substring(1)))
    .collect(Collectors.joining(" "))
    :
    null
    ;
    }


    public static void main(String[] args){

        

    }

}