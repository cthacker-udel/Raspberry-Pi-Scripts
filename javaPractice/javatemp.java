import java.util.stream.*;
import java.util.ArrayList;
import java.util.regex.*;
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

	public static void main(String[] args){

        millionsRounding(new Object[] {new Object[] {"Tokyo", 37435191}, new Object[] {"Delhi", 29399141}, new Object[] {"Shanghai", 26317104}});
        //new Object[] {new Object[] {"Tokyo", 37000000}, new Object[] {"Delhi", 29000000}, new Object[] {"Shanghai", 26000000}}

	}



}