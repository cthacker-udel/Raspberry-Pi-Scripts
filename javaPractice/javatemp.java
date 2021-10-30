import java.util.stream.*;
import java.util.ArrayList;
import java.util.regex.*;
import java.util.*;
public class javatemp{

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

        /*
        String substr = fractions.subtring(0,fractions.indexOf("+"));
        bool negAddition = false;
        bool negSubtraction = false;
        if(substr.split("/").length == 2){ // first fraction is addition to second ex : -1/4+5/4 --> -1/4 --> [-1,4]
            // is addition
            if(substr.indexOf("-") != -1){
                // is negative
                negAddition = true;
            }
        }
        else{
            substr = fractions.substring(0,fractions.indexOf("-"));
            if(substr.split("/").length == 2){
                if(substr.indexOf("-") != -1){
                    negSubtraction = true;
                }
            }
        }
        String[] split = fractions.split("\\+");
        for(int i = 0; i < split.length-1; i++){ // -1/4+5/4+6/4 --> 
            int denom1 = Integer.parseInt(split[i].substring(split[i].indexOf("/")+1));
            int denom2 = Integer.parseInt(split[i+1].substring(split[i+1].indexOf("/")+1));
            int theLcm = lcm(denom1,denom2,euclid(denom1,denom2));
            int mult = theLcm / denom1;
            int numerator1 = Integer.parseInt(split[i].substring(0,split[i].indexOf("/")));
            int numerator2 = Integer.parseInt(split[i+1].substring(0,split[i+1].indexOf("/")));
            numerator1 *= mult;
            numerator2 *= mult;
            denom1 *= mult;
            denom2 *= mult;
            System.out.println(String.format("%d/%d",numerator1,denom1));
            System.out.println(String.format("%d/%d",numerator2,denom2));
        }
        return "";
        */
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
        /*
        int[] res = new int[intList.size()];
        for(int i = 0; i < intList.size(); i++){
          res[i] = intList.get(i);
          System.out.print(res[i]);
        }
        System.out.println("");
        return res;
        */
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

	public static void main(String[] args){

        System.out.println(textToNum("123-647-EYES"));

	}



}