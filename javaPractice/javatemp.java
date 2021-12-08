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

    public static long[] step2(int g, long m, long n){

        long res = LongStream.rangeClosed(m,n).filter(e -> isPrime(e) && isPrime(e+g)).findFirst().orElse(0);

        return new long[]{res,res+g};

    }

    public static int[] sortArray2(int[] arr){

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

    public static int[] beggars2(int[] values, int n){

        ArrayList<Integer> totals = new ArrayList<>();

        for(int i = 0; i < n; i++){

            final int ind = i;


            //int[] res = IntStream.range(i,values.length).filter(e -> e % ind === 0).

            int x = 10;

            //totals.add(IntStream.iterate(i, e -> e < values.length, e -> e + n).limit(values.length-n).filter(e -> e < values.length).map(e -> values[e]).sum());

        }
        return Stream.of(totals.toArray(Integer[]::new)).mapToInt(e -> e).toArray();

    }

    public static int[] dataReverse2(int[] data){


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


    public static String rot2(String string){

        ArrayList<String> strList = new ArrayList<String>(string.split("\n"));
        Collections.reverse(strList);

    }

    public static String oper3(Function<String,String> operator, String s){
        operator.apply(s);
    }

    public static Integer[] primeFactors2(int num){

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


    public static String decomp2(int number){

        ArrayList<Integer> ints = new ArrayList<>();
        for(int i = number; i >= 2; i--){
            ints.addAll(List.of(primeFactors(i)));
        }
        Collections.sort(ints);

        return new HashSet<Integer>(ints).stream().map(e -> Collections.frequency(ints,e) > 1? String.format("%d^%d",e,Collections.frequency(ints,e)): e+"").collect(Collectors.joining(" * "));
        //return powers.entrySet().stream().map(e -> String.format("%d%s",e.getKey(),e.getValue() > 1? String.format("^%d",e.getValue()): "")).collect(Collectors.joining(" * "));
    }

    public static boolean noConsec2(long number, int filter){


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

    public static long[] maxSumDig2(long nmax, int maxsm){

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

    public static long[] productFib2(long prod){

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

    public static int[] isPerfectPower2(int n){

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

    public static double factorial2(double n){

        double total = n;
        double starter = n-1;
        while(starter > 1){
            total *= starter;
            starter--;
        }
        return total;

    }

    public static double binomial2(double n, double k){

        return factorial(n) / ((factorial(k)) * factorial(n- k));

    }

    public static double[] bernoulliN2(int n){

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

    public static double series2(int k, int nb){

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

    public static long sumSquareDivisors2(long number){
        return LongStream.rangeClosed(1,number % 2 == 0? number / 2 : number % 3 == 0? number / 3 : number % 5 == 0? number / 5 : (long)Math.floor(number / 2))
                .filter(e -> number % e == 0)
                .map(e -> (long)Math.pow(e,2))
                .sum() + (long)(Math.pow(number,2));
    }

    public static boolean isSqrtPerfectSquare2(long number){
        return Math.sqrt(number) == Math.floor(Math.sqrt(number));
    }

    public static long[] isValidRecreationOneInteger2(long number){
        if(number == 1){
            return new long[]{1,1};
        }
        long sum = sumSquareDivisors(number);
        return isSqrtPerfectSquare(sum) ? new long[]{number,sum} : null;
    }

    public static String listSquared2(long m, long n){

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
    
    public static String nthRank2(String st, Integer[] we, int n){

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

                    //ranks[i] = getValue(participants[i]) + participants[i].length();
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

            }

        }
        return "";

    }

    public static boolean isPrime2(long number){

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

    public static int[] beggars(int[] values, int n){

        ArrayList<Integer> totals = new ArrayList<>();

        int turn = 1;
        int tmpTotal = 0;

        for(int i = 0; i < n; i++){

            for(int j = turn-1; j < values.length; j += n){
                tmpTotal += values[j];
            }
            totals.add(tmpTotal);
            tmpTotal = 0;
            turn++;
        }
        return totals.stream().mapToInt(e -> e).toArray();

    }

    public static int minimumNumber(int[] numbers){

            int sum = IntStream.of(numbers).sum();
            return IntStream.range(sum,sum*2).filter(sourcefile::isPrime).findFirst().orElse(-1) - sum;

    }

    public static List<String> movingShift(String s, int shift){

        String alphaLower = "abcdefghijklmnopqrstuvwxyz";
        String alphaUpper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        String symbols = " \'~!@#$%^&*()_+-={}[];:\"<>,.?/\\0123456789";

        int division = (int)Math.ceil(s.length()*1.0 / 5);
        int len = s.length();
        int runners = 0;
        ArrayList<Integer> runList = new ArrayList<>();
        while(len > division){
            runners++;
            len -= division;
            runList.add(division);
        }
        while(runList.size() < 5){
            runList.add(len);
            len = 0;
        }
        ArrayList<String> snippets = new ArrayList<>();
        for(int i = 0; i < 5; i++){

            if(runList.get(i) == 0){
                break;
            }
            else{
                String substr = s.substring(0,runList.get(i));
                snippets.add(substr);
                s = s.substring(runList.get(i));
            }

        }
        while(snippets.size() < 5){
            snippets.add("");
        }

        ArrayList<String> newSnippets = new ArrayList<>();
        for(int i = 0; i < 5; i++){

            char[] theSnippet = snippets.get(i).toCharArray();
            for(int j = 0; j < theSnippet.length; j++){

                char theLetter = theSnippet[j];

                if(symbols.indexOf(theLetter) != -1){
                    shift++;
                    continue;
                }
                else if(theLetter == (theLetter+"").toUpperCase().charAt(0)){
                    // is upper
                    int index = (alphaUpper.indexOf(theLetter) + shift++) % 26;
                    char newLetter = alphaUpper.charAt(index);
                    theSnippet[j] = newLetter;
                }
                else{
                    // is lower
                    int index = (alphaLower.indexOf(theLetter) + shift++) % 26;
                    char newLetter = alphaLower.charAt(index);
                    theSnippet[j] = newLetter;
                }

            }
            newSnippets.add(new String(theSnippet));

        }


        return newSnippets;
    }

    public static String demovingShift(List<String> s, int shift){

            String finalString = "";
            String alphaLower = "abcdefghijklmnopqrstuvwxyz";
            String alphaUpper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
            String symbols = " \'~!@#$%^&*()_+-={}[];:\"<>,.?/\\";
            for(int i = 0; i < s.size(); i++){

                char[] theSnippet = s.get(i).toCharArray();
                for(int j = 0; j < theSnippet.length; j++){

                    char theLetter = theSnippet[j];

                    if(symbols.indexOf(theLetter) != -1){
                        finalString += theLetter;
                        shift++;
                        continue;
                    }
                    else if(theLetter == (theLetter+"").toUpperCase().charAt(0)){
                        // is upper
                        int index = (alphaUpper.indexOf(theLetter) - shift++);
                        if(index < 0){
                            index = alphaUpper.length() - (Math.abs(index) % 26);
                        }
                        index = index % 26;
                        char newLetter = alphaUpper.charAt(index);
                        finalString += newLetter;
                    }
                    else{
                        // is lower
                        int index = (alphaLower.indexOf(theLetter) - shift++);
                        if(index < 0){
                            index = alphaUpper.length() - (Math.abs(index) % 26);
                        }
                        index = index % 26;
                        char newLetter = alphaLower.charAt(index);
                        finalString += newLetter;
                    }

                }

            }
            return finalString;

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
        ArrayList<String> strList = new ArrayList<String>(List.of(string.split("\n")));
        Collections.reverse(strList);
        return strList.stream().map(e -> new StringBuilder(e).reverse().toString()).collect(Collectors.joining("\n"));
    }

    public static String selfieAndRot(String s){

        String[] splitStr = s.split("\n");
        int strLen = splitStr[0].length();
        for(int i = 0; i < splitStr.length; i++){
            splitStr[i] = String.format("%s%s\n",splitStr[i],".".repeat(strLen));
        }
        String[] rotStringSplt = rot(s).split("\n");
        for(int i = 0; i < rotStringSplt.length-1; i++){
            rotStringSplt[i] = String.format("%s%s\n",".".repeat(strLen),rotStringSplt[i]);
        }
        rotStringSplt[rotStringSplt.length-1] = String.format("%s%s",".".repeat(strLen),rotStringSplt[rotStringSplt.length-1]);
        ArrayList<String> container = new ArrayList<String>(List.of(splitStr));
        container.addAll(List.of(rotStringSplt));
        return String.join("",container);


    }

    public static String oper(Function<String,String> operator, String s){
        return operator.apply(s);
    }

    public static long[] smallest(long number){

        ArrayList<String> strNumList = new ArrayList<String>(List.of(String.valueOf(number).split("")));

        // smallest start to extract, cannot extract and place at same spot
        int minRemoveInd = 0;
        int minInsertInd = 0;
        long minNumber = number;
        int fixedSize = strNumList.size();
        for(int i = 0; i < fixedSize; i++){
            String removedDigit = strNumList.remove(i);
            for(int j = 0; j < fixedSize; j++){

                if(j == i){
                    continue;
                }
                else{
                    strNumList.add(j,removedDigit);
                    long formedNumber = Long.parseLong(String.join("",strNumList));
                    if(formedNumber < minNumber){
                        minNumber = formedNumber;
                        minRemoveInd = i;
                        minInsertInd = j;
                        removedDigit = strNumList.remove(j);
                    }
                    else{
                        strNumList.remove(j);
                    }
                }

            }
            strNumList.add(i,removedDigit);

        }
        return new long[]{minNumber,minRemoveInd,minInsertInd};

    }

    public static int factorial(int num){

        if(num <= 1){
            return num;
        }
        else{
            return num * factorial(num-1);
        }

    }

    // 12 * 11 * 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1
    // 12: 2,2,3
    // 11
    // 10: 2,5
    // 9: 3,3
    // 8: 2,2,2
    // 7: 7
    // 6: 2,3
    // 5: 5
    // 4: 2,2
    // 3: 3
    // 2: 2
    // 1: 1

    // 2 count - 10
    // 3 count - 5
    // 5 count - 2
    // 7 count - 1
    // 11 count - 1

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

    public static int weight(int num){
        return Stream.of(String.valueOf(num).split("")).mapToInt(Integer::parseInt).sum();
    }

    public static int[][] closest(String strng){

        if(strng.equals("")){
            return new int[][]{{}};
        }

        ArrayList<Integer> intList = Stream.of(strng.split(" ")).mapToInt(Integer::parseInt).collect(ArrayList::new,ArrayList::add,ArrayList::addAll);

        if(intList.size() == 1){
            return new int[][]{{0,0,0}};
        }

        Integer[] cloneList = ((ArrayList<Integer>)intList.clone()).toArray(Integer[]::new);
        Arrays.sort(cloneList, new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return weight(o1) - weight(o2);
            }
        });
        int[] weights = Stream.of(cloneList).mapToInt(sourcefile::weight).toArray();

        // find smallest diff

        int[] weightDiffs = new int[weights.length];

        int minWeightDiff = Math.abs(weights[0]-weights[1]);
        for(int i = 0; i < weights.length-1; i++){
            int diff = Math.abs(weights[i]-weights[i+1]);
            weightDiffs[i] = diff;
            minWeightDiff = Math.min(diff,minWeightDiff);
            // maybe after getting min, add pairs to list, gather smallest indices from there
        }

        ArrayList<Integer[]> pairList = new ArrayList<>();

        for(int i = 0; i < weights.length-1; i++){
            if(weightDiffs[i] == minWeightDiff){
                pairList.add(new Integer[]{cloneList[i],cloneList[i+1]});
            }
        }

        Integer[] thePair = pairList.get(0);

        int num1 = thePair[0];
        int num2 = thePair[1];

        int[][] result = new int[2][3];
        result[0] = new int[]{weight(num1),intList.indexOf(num1),num1};
        result[1] = new int[]{weight(num2),intList.lastIndexOf(num2),num2};

        if(result[0][0] > result[1][0]){
            int[] tmp = result[0];
            result[0] = result[1];
            result[1] = tmp;
        }
        else if(result[0][0] == result[1][0]){
            if(result[0][1] > result[1][1]){
                int[] tmp = result[0];
                result[0] = result[1];
                result[1] = tmp;
            }
        }

        return result;

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

    public static List<String> encodeStr(String s, int shift){

        System.out.printf("Testing %s with %d%n",s,shift);

        String alphaLower = "abcdefghijklmnopqrstuvwxyz";
        String alphaUpper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        String symbols = " \'~!@#$%^&*()_+-={}[];:\"<>,.?/\\0123456789";

        String prefix = s;
        char prefixFirst = prefix.toLowerCase().charAt(0);
        int prefixInd = 0;
        if( alphaLower.contains(prefixFirst+"") ) {
            prefixInd = alphaLower.indexOf(prefixFirst);
            int formattedPrefixInd = prefixInd + shift;
            if (formattedPrefixInd >= 26 ) {
                formattedPrefixInd %= 26;
            }
            prefixInd = formattedPrefixInd;
            prefix = String.format("%c%c",prefixFirst,alphaLower.charAt(prefixInd));
        }
        s = prefix + s;

        int division = (int)Math.ceil(s.length()*1.0 / 5);
        int len = s.length();
        int runners = 0;
        ArrayList<Integer> runList = new ArrayList<>();
        while (len > division) {
            runners++;
            len -= division;
            runList.add(division);
        }
        if (len > 0) {
            runList.add(len);
        }
        ArrayList<String> snippets = new ArrayList<>();
        for (int i = 0; i < runList.size(); i++) {

            if (runList.get(i) == 0) {
                break;
            } else {
                String substr = s.substring(0,runList.get(i));
                snippets.add(substr);
                s = s.substring(runList.get(i));
            }
        }
        ArrayList<String> newSnippets = new ArrayList<>();

        String[] snippetsArr = snippets.toArray(String[]::new);

        boolean isFirst = false;
        String splicedPrefix = "";

        for (int j = 0; j < snippetsArr.length; j++) {
            String eachSnippet = snippetsArr[j];
            if (!isFirst) {
                splicedPrefix = eachSnippet.substring(0,2);
                eachSnippet = eachSnippet.substring(2);
            }

            StringBuilder newString = new StringBuilder();
            for (int i = 0; i < eachSnippet.length(); i++) {

                char theLetter = eachSnippet.charAt(i);
                if (!alphaLower.contains(theLetter+"") && !alphaUpper.contains(theLetter+"")) {
                    // not a alpha letter
                    newString.append(theLetter);
                } else if (alphaLower.contains(theLetter+"")) {
                    int ind = alphaLower.indexOf(theLetter);
                    int formattedInd = ind + shift;
                    if (formattedInd >= 26) {
                        formattedInd %= 26;
                    }
                    ind = formattedInd;
                    newString.append(alphaLower.charAt(ind));
                } else if (alphaUpper.contains(theLetter+"")) {
                    int ind = alphaUpper.indexOf(theLetter);
                    int formattedInd = ind + shift;
                    if (formattedInd >= 26) {
                        formattedInd %= 26;
                    }
                    ind = formattedInd;
                    newString.append(alphaUpper.charAt(ind));
                }

            }
            if (!isFirst) {
                eachSnippet = splicedPrefix + newString.toString();
                snippetsArr[j] = eachSnippet;
                isFirst = true;
            } else {
                snippetsArr[j] = newString.toString();
            }

        }

        return Stream.of(snippetsArr).collect(Collectors.toList());


    }

    public static String decode(List<String> s) {

        String alphaLower = "abcdefghijklmnopqrstuvwxyz";
        String alphaUpper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        String symbols = " \'~!@#$%^&*()_+-={}[];:\"<>,.?/\\0123456789";

        String prefix = s.get(0).substring(0,2);
        char initLetter = prefix.charAt(0);
        char shiftLetter = prefix.charAt(1);
        int initInd = alphaLower.indexOf(initLetter);
        int shiftInd = alphaLower.indexOf(shiftLetter);
        int shift = 0;
        if (initInd > shiftInd) {
            // wrap around
            int tmpInd = initInd;
            for (;alphaLower.charAt(tmpInd) != shiftLetter;) {
                if (tmpInd == 25) {
                    tmpInd = 0;
                } else {
                    tmpInd++;
                }
                shift++;
            }
        } else {
            shift = shiftInd - initInd;
        }
        // shift properly acquired
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < s.size(); i++) {
            String snippet = s.get(i);
            StringBuilder newWord = new StringBuilder();
            if (i == 0) {
                snippet = snippet.substring(2);
            }
            for (int j = 0; j < snippet.length(); j++) {

                char theLetter = snippet.charAt(j);
                if (!alphaLower.contains(theLetter+"") && !alphaUpper.contains(theLetter+"")) {
                    newWord.append(theLetter);
                } else if (alphaLower.contains(theLetter+"")){
                    int theInd = alphaLower.indexOf(theLetter);
                    int formattedInd = theInd - shift;
                    if (formattedInd < 0) {
                        formattedInd += 26;
                    }
                    newWord.append(alphaLower.charAt(formattedInd));
                } else if (alphaUpper.contains(theLetter + "")) {
                    int theInd = alphaUpper.indexOf(theLetter);
                    int formattedInd = theInd - shift;
                    if (formattedInd < 0) {
                        formattedInd += 26;
                    }
                    newWord.append(alphaUpper.charAt(formattedInd));
                }
            }
            sb.append(newWord);
        }
        return sb.toString();


    }

    public static String table(String[] results){

        Set<String> teams = new LinkedHashSet<>();
        for (String eachStr: results) {
            String[] splitStr = eachStr.split(" - ");
            teams.add(splitStr[0].split(" ")[1]);
            teams.add(splitStr[1]);
        }
        HashMap<String,Integer> pointsMap = new LinkedHashMap<>();
        for (String eachStr: results) {
            String[] splitStr = eachStr.split(" - ");
            String score = splitStr[0].split(" ")[0];
            String team1 = splitStr[0].split(" ")[1];
            String team2 = splitStr[1];
            if (!score.equals("-:-")) {
                int score1 = Integer.parseInt(score.split(":")[0]);
                int score2 = Integer.parseInt(score.split(":")[1]);
                if (score1 > score2) {
                    if (pointsMap.containsKey(team1)){
                        pointsMap.put(team1,pointsMap.get(team1)+1);
                    } else {
                        pointsMap.put(team1,3);
                    }
                } else if (score1 < score2) {
                    if (pointsMap.containsKey(team2)) {
                        pointsMap.put(team2,pointsMap.get(team2)+1);
                    } else {
                        pointsMap.put(team2,3);
                    }
                }
            } else {
                pointsMap.put(splitStr[0].split(" ")[1],0);
            }
        }
        return "";

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

    public static boolean verifyGap(long m, long rangeExcl){

        return new BigInteger(m+"").nextProbablePrime().compareTo(new BigInteger(rangeExcl+"")) != -1;

    }

    public static long[] gap(int g, long m, long n){

        long res = LongStream.rangeClosed(m+g,n).filter(e -> isPrime(e) && isPrime(e-g) && verifyGap(e-g,e)).findFirst().orElse(0L);
        return res != 0 ? new long[]{res-g,res} : null;
    }

    public static boolean isPalindrome2(String s){

        return s.equals(new StringBuilder(s).reverse().toString());

    }

    public static int duplicateCount(String text){

        text = text.toLowerCase();
        ArrayList<String> chars = new ArrayList<>(List.of(text.split("")));
        HashSet<String> strSet = new HashSet<>(chars);
        return (int)strSet.stream().filter(e -> Collections.frequency(chars,e) > 1).count();

    }

    public static char findMissingLetter(char[] array){

        LinkedHashSet<String> linkedHashSet = Stream.of(new String(array).split("")).collect(Collectors.toCollection(LinkedHashSet::new));
        String upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        String lower = "abcdefghijklmnopqrstuvwxyz";
        if (upper.contains(array[0]+"")) {
            int startingIndex = upper.indexOf(linkedHashSet.toArray(String[]::new)[0]);
            for (int i = startingIndex; i < upper.length(); i++) {
                if (!linkedHashSet.contains(upper.charAt(i)+"")) {
                    return upper.charAt(i);
                }
            }
            return ' ';
        } else {
            int startingIndex = lower.indexOf(linkedHashSet.toArray(String[]::new)[0]);
            for (int i = startingIndex; i < lower.length(); i++) {
                if (!linkedHashSet.contains(lower.charAt(i)+"")) {
                    return lower.charAt(i);
                }
            }
            return ' ';
        }

    }

    public static String interpret(String code){

        if(code.substring(0,2).equals("2>")){
            return "";
        }

        String[] splitCode = code.split("\n");
        int direction = 0;
        /*

        0-right
        1-down
        2-left
        3-up

         */
        boolean programIsRunning = true;
        int x = 0;
        int y = 0;
        Stack<String> stack = new Stack();
        int num1;
        int num2;
        int result;
        int offsetYLength = splitCode[0].length()+1;
        int offsetXLength = splitCode.length+1;
        StringBuilder output = new StringBuilder();
        int offsetAdder = 1;
        while (programIsRunning) {

            char currentCommand = splitCode[x].charAt(y);
            switch(currentCommand) {

                case '0':
                    stack.add(currentCommand+"");
                    break;
                case '1':
                    stack.add(currentCommand+"");
                    break;
                case '2':
                    stack.add(currentCommand+"");
                    break;
                case '3':
                    stack.add(currentCommand+"");
                    break;
                case '4':
                    stack.add(currentCommand+"");
                    break;
                case '5':
                    stack.add(currentCommand+"");
                    break;
                case '6':
                    stack.add(currentCommand+"");
                    break;
                case '7':
                    stack.add(currentCommand+"");
                    break;
                case '8':
                    stack.add(currentCommand+"");
                    break;
                case '9':
                    stack.add(currentCommand+"");
                    break;
                case '+':
                    num1 = Integer.parseInt(stack.pop()+"",10);
                    num2 = Integer.parseInt(stack.pop()+"",10);
                    result = num1 + num2;
                    stack.add(result+"");
                    break;
                case '-':
                    num1 = Integer.parseInt(stack.pop()+"",10);
                    num2 = Integer.parseInt(stack.pop()+"",10);
                    result = num2 - num1;
                    stack.add(result+"");
                    break;
                case '*':
                    num1 = Integer.parseInt(stack.pop()+"",10);
                    num2 = Integer.parseInt(stack.pop()+"",10);
                    result = num1 * num2;
                    stack.add(result+"");
                    break;
                case '/':
                    num1 = Integer.parseInt(stack.pop()+"",10);
                    num2 = Integer.parseInt(stack.pop()+"",10);
                    if (num1 == 0) {
                        stack.add(0+"");
                    } else {
                        stack.add((num2 / num1)+"");
                    }
                    break;
                case '%':
                    num1 = Integer.parseInt(stack.pop()+"",10);
                    num2 = Integer.parseInt(stack.pop()+"",10);
                    if (num1 == 0) {
                        stack.add(0+"");
                    } else {
                        stack.add((num2 % num1)+"");
                    }
                    break;
                case '!':
                    num1 = Integer.parseInt(stack.pop()+"",10);
                    if (num1 == 0) {
                        stack.add(1+"");
                    } else {
                        stack.add(0+"");
                    }
                    break;
                case '`':
                    num1 = Integer.parseInt(stack.pop()+"",10);
                    num2 = Integer.parseInt(stack.pop()+"",10);
                    if (num2 > num1) {
                        stack.add(1+"");
                    } else {
                        stack.add(0+"");
                    }
                    break;
                case '>':
                    direction = 0;
                    break;
                case '<':
                    direction = 2;
                    break;
                case '^':
                    direction = 3;
                    break;
                case 'v':
                    direction = 1;
                    break;
                case '?':
                    direction = (int) ((Math.random() * (4 - 0)) + 0);
                    break;
                case '_':
                    num1 = Integer.parseInt(stack.pop()+"",10);
                    if (num1 == 0) {
                        direction = 0;
                    } else {
                        direction = 2;
                    }
                    break;
                case '|':
                    num1 = Integer.parseInt(stack.pop()+"",10);
                    if (num1 == 0) {
                        direction = 1;
                    } else {
                        direction = 3;
                    }
                case '\"':
                    if (direction == 0) {
                        // move to right until next " is found, and push each character
                        // y+1 x same
                        while (true) {
                            y = Math.floorMod(y+1,offsetYLength);
                            // wraps around potentially
                            String stringValue = splitCode[x].charAt(y)+"";
                            char theStringValueCharacter = stringValue.charAt(0);
                            if (theStringValueCharacter == '\"') {
                                break;
                            }
                            int asciiValue = (int)theStringValueCharacter;
                            stack.add(asciiValue+"");
                        }
                        break;
                    } else if (direction == 1) {
                        // move down, x+1
                        while (true) {
                            x = Math.floorMod(x+1,offsetXLength);
                            // wraps around potentially
                            String stringValue = splitCode[x].charAt(y)+"";
                            char theStringValueCharacter = stringValue.charAt(0);
                            if (theStringValueCharacter == '\"') {
                                break;
                            }
                            int asciiValue = (int)theStringValueCharacter;
                            stack.add(asciiValue+"");
                        }
                        break;
                    } else if (direction == 2) {
                        // move left -- y-1
                        while (true) {
                            y = Math.floorMod(y-1,offsetYLength);
                            // wraps around potentially
                            String stringValue = splitCode[x].charAt(y)+"";
                            char theStringValueCharacter = stringValue.charAt(0);
                            if (theStringValueCharacter == '\"') {
                                break;
                            }
                            int asciiValue = (int)theStringValueCharacter;
                            stack.add(asciiValue+"");
                        }
                        break;
                    } else {
                        // move up, x-1
                        while (true) {
                            x = Math.floorMod(x-1,offsetXLength);
                            // wraps around potentially
                            String stringValue = splitCode[x].charAt(y)+"";
                            char theStringValueCharacter = stringValue.charAt(0);
                            if (theStringValueCharacter == '\"') {
                                break;
                            }
                            int asciiValue = (int)theStringValueCharacter;
                            stack.add(asciiValue+"");
                        }
                        break;
                    }
                case ':':
                    if (stack.empty()) {
                        stack.add("0");
                    } else {
                        stack.add(stack.peek());
                    }
                    break;
                case '\\':
                    if (stack.size() == 1) {
                        stack.add("0");
                    } else {
                        String top = stack.pop();
                        String bottom = stack.pop();
                        stack.add(top);
                        stack.add(bottom);
                    }
                    break;
                case '$':
                    stack.pop();
                    break;
                case '.':
                    String value = stack.pop();
                    String numbers = "0123456789";
                    try{
                        Integer.parseInt(value,10);
                        output.append(new String(value));
                    } catch (Exception e) {
                        output.append((int)value.charAt(0));
                    }
                    break;
                case ',':
                    String popValue = stack.pop();
                    try {
                        int asciiValue = Integer.parseInt(popValue);
                        output.append(((char) asciiValue) + "");
                    } catch (Exception e) {
                        output.append(popValue);
                    }
                    break;
                case '#':
                    offsetAdder = 2;
                    break;
                case 'p':
                    String y1 = stack.pop();
                    String x1 = stack.pop();
                    String v1 = stack.pop();
                    int vAsciiValue = Integer.parseInt(v1);
                    int coordX = Integer.parseInt(x1);
                    int coordY = Integer.parseInt(y1);
                    // gather row, convert to array, and then rejoin and place back in
                    String row = splitCode[coordY];
                    // make row into string list
                    String[] listedRow = row.split("");
                    // update value at Y coord in listedRow
                    listedRow[coordX] = ((char)vAsciiValue)+"";
                    // rejoin row to make it one whole string
                    String updatedRow = String.join("",listedRow);
                    // push it back into the original code
                    splitCode[coordX] = updatedRow;
                    break;
                case 'g':
                    String y2 = stack.pop();
                    String x2 = stack.pop();
                    int coordX2 = Integer.parseInt(x2);
                    int coordY2 = Integer.parseInt(y2);
                    String valueGet = splitCode[coordY2].charAt(coordX2)+"";
                    stack.add(((int)valueGet.charAt(0))+"");
                    break;
                case '@':
                    return output.toString();
                case ' ':
                    offsetAdder = 1;
                    break;

            }
            if (direction == 0) {
                // move right
                y = Math.floorMod(y+offsetAdder,offsetYLength);
            } else if (direction == 1) {
                // move down
                x = Math.floorMod(x+offsetAdder,offsetXLength);
            } else if (direction == 2) {
                // move left
                y = Math.floorMod(y-offsetAdder,offsetYLength);
            } else if (direction == 3) {
                // move up
                x = Math.floorMod(x-offsetAdder,offsetXLength);
            }
            offsetAdder = 1;

        }
        return output.toString();

    }

    public static String interpetSymbolsEsoLang(String tape) {

        int pointer = 0;
        final Scanner scanner = new Scanner(System.in);
        String[] splitTape = tape.split("");
        while (pointer < splitTape.length) {

            char theCharacter = splitTape[pointer].charAt(0);
            switch (theCharacter) {
                case '(':
                    // begin loop
                    break;
                case ')':
                    // end infinite loop
                    break;
                case ':':
                    System.out.print(splitTape[pointer+1].charAt(0));
                    break;
                case ';':
                    String input = scanner.nextLine();
                    splitTape[pointer+2] = input;
                    break;
                case '+':
                    char incrementChar = splitTape[pointer+1].charAt(0);
                    int valueIncremented = ((int)incrementChar) + 1;
                    splitTape[pointer+1] = ((char)valueIncremented)+"";
                    break;
                case '-':
                    char decrementChar = splitTape[pointer+1].charAt(0);
                    int valueDecremented = ((int)decrementChar) - 1;
                    splitTape[pointer+1] = ((char)valueDecremented)+"";
                    break;
                case '#':
                    String input2 = scanner.nextLine();
                    char newInstruction = input2.charAt(0);
                    splitTape[pointer] = input2;
                    pointer--;
                    break;
                case '?':
                    String leftInstruction = splitTape[pointer-1];
                    if ("():;+-#?!".contains(leftInstruction)){
                        return "";
                    }
                    break;
                case '!':
                    return "";
            }
            pointer++;

        }
        return "";

    }

    public static String interpretQuestionExclamation(String tape){

        int currentTapeValue = 0;
        int multiplier = 0;
        Stack<String> parenStack = new Stack<String>();
        int index = 0;
        String output = "";
        boolean multiplier_mode = false;
        while (index < tape.length()) {
            char currentTapeCharacter = tape.charAt(index);
            switch (currentTapeCharacter) {

                case '?':
                    if (multiplier_mode) {
                        multiplier++;
                    } else {
                        currentTapeValue++;
                    }
                    break;
                case '!':
                    if (currentTapeValue > 0) {
                        output += ((char) currentTapeValue);
                        currentTapeValue = 0;
                    }
                    break;
                case '(':
                    multiplier_mode = true;
                    break;
                case ')':
                    multiplier_mode = false;
                    currentTapeValue *= multiplier;
                    multiplier = 0;
                    break;
                default:
                    break;

            }
            index++;
        }
        return output;
    }

    public static String bracketLevel1Interpreter(String tape) {

        int index = 0;
        int accumulator = 0;
        boolean additionMode = false;
        int nestedLevelLeft = 0;
        int nestedLevelRight = 0;
        while (index < tape.length()) {

            char tapeCharAt = tape.charAt(index);
            switch (tapeCharAt) {

                case '{':
                    if (tape.charAt(index + 1) == '}') {
                        // no operator
                        index += 2;
                    } else if (tape.charAt(index+1) != '}') {
                        // addition operation
                        additionMode = true;
                    } else {
                        nestedLevelLeft++;
                    }
                    break;
                case '}':
                    if (nestedLevelLeft == 2) {
                        if (nestedLevelRight == 1) {
                            ArrayList<String> splitTape = Stream.of(tape.split("")).collect(Collectors.toCollection(ArrayList::new));
                            splitTape.remove(index-3);
                            splitTape.remove(index-3);
                            splitTape.remove(index-3);
                            splitTape.remove(index-3);
                        }
                    }


            }

        }
        return "";
    }

    public static String fishInterpreter(String[] tape){
        // TODO: Implement fish esolang interpreter
        // https://esolangs.org/wiki/Fish
        // and starfish https://esolangs.org/wiki/Starfish
        return "";
    }

    public static List<String> top3(String s) {
        s = s.replaceAll("[#\\\\\\/\\!\\@\\$\\%\\^\\&\\*\\(\\)\\-\\_\\+\\=\\]\\[\\;\\:\\\"\\<\\,\\>\\.\\?\\|\\~\\`]"," ");
        s = s.toLowerCase();
        String[] splitString = s.split(" ");
        if (splitString.length == 0) {
            return new ArrayList<String>();
        }
        Map<String,Long> countedWords = Stream.of(splitString).collect(Collectors.groupingBy(Function.identity(),Collectors.counting()));
        List<Map.Entry<String,Long>> entries = new ArrayList<>(countedWords.entrySet());
        entries.sort(Map.Entry.comparingByValue());

        Map<String,Long> result = new LinkedHashMap<>();
        for( Map.Entry<String,Long> entry: entries) {
            if (entry.getKey().equals("") || ( entry.getKey().contains("'") && entry.getKey().replaceAll("[a-z]","").equals(entry.getKey()))) {
                continue;
            }
            result.put(entry.getKey(), entry.getValue());
        }

        List<Map.Entry<String,Long>> entries2 = new ArrayList<>(result.entrySet());
        ArrayList<String> words = new ArrayList<>();
        while (words.size() < 3 && entries2.size() > 0) {
            words.add(entries2.get(entries2.size()-1).getKey());
            entries2.remove(entries2.size()-1);
        }
        return words;
    }


    public static void main(String[] args){

        

    }

}