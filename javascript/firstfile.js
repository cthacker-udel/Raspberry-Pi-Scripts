
/*

let square_string = "#";
for(let i = 1; i < 8; i++){
    console.log(square_string);
    square_string += "#";
}

for(let i = 1; i < 101; i++){

    if(i % 3 === 0 && i % 5 === 0){
        console.log("FizzBuzz" + String(i));
    }
    else if(i % 3 === 0){

        console.log("Fizz" + String(i));

    }
    else if(i % 5 === 0){

        console.log("Buzz" + String(i));

    }

}

let chess_board = "";

let size = 100;

let odd = true;
let even = false;

for(let i = 0; i < size; i++){

    for(let j = 0; j < size; j++){

        if(odd){
            chess_board += " ";
        }
        if(odd && i % 2 === 0){
            chess_board += "#";
        }
        if(even){
            chess_board += "#";
        }
        if(even && i % 2 !== 0){
            chess_board += " ";
        }

    }
    if(odd){
        even = true;
        odd = false;
        chess_board += "\n";
    }
    else if(even){
        even = false;
        odd = true;
        chess_board += "\n";
    }

}
console.log(chess_board);

const square = function(x){

    return x*x;

}

const makeNoise = function(){

    console.log("NOISE");

}

makeNoise();

const power = function(base,exponent){

    return base ** exponent;

};

console.log(power(2,4));

const hummus = function(factor){

    const ingredient = function(amount,unit,name){

        let ingredientAmount = amount * factor;
        if(ingredientAmount > 1){
            unit += "s";
        }
        console.log(`${ingredientAmount} ${unit} ${name}`);


    };
    ingredient(1,"can","chickpeas");



};

function square_two(value){

    return value*value;

}

hummus(10);

console.log(square_two(20));


const power_two = (base,exponent) => {

    return base ** exponent;

};

console.log(power_two(10,1));


const minus = (x,y) => {

    if(y === undefined){
        return -x;
    }
    else{

        return x - y;

    }

};

console.log(minus(10,6));

const default_values = (the_default="defaultval",two="twovals") => {

    if(the_default === "defaultval"){
        console.log("no defaultval given");
    }
    else if(two === "twovals"){
        console.log("twovals value was not given");
    }
    else{
        console.log("reached else");
    }

};

default_values("one val","tt");


const multiply = (factor) => {

    return number => number * factor;

};

const pad = (length,padder) => {

    return (animalName,amount) => animalName + " : " + String(amount).padStart(length,padder);

};

const divide = (value) => {

    return number => number / value;


};

const displayDate = () => {

    let date = new Date();
    let currDay = date.getDay();
    console.log(currDay);
    let hours = date.getHours();
    let minutes = date.getMinutes();
    let seconds = date.getSeconds();

    console.log(`Today is : ${currDay === 1? "Monday": currDay === 2? "Tuesday": currDay === 3? "Wednesday": currDay === 4? "Thursday": currDay === 5? "Friday": currDay === 6? "Saturday": "Sunday"}\n Current time is : ${hours} : ${minutes} : ${seconds}`);

};

displayDate();


let first = multiply(10);
console.log(first(5));

let second = divide(10);
console.log(second(100));


const triangleArea = (base,height) => {

    return (base * height) / 2;

};

const compare = (obj1,obj2) => {

    return (obj1 === obj2)? 1: 0;

};


const rotateString = (string) => {

    let currString = String(string);
    let lastCharacter = currString.charAt(currString.length-1);
    currString = lastCharacter + currString.substr(0,currString.length-1);
    return currString;


};

const factorial = (number) => {

    if(number === 1){
        return number;
    }
    else{
        return number * factorial(number-1);
    }

};

console.log(factorial(5));


const findSolution = (target) =>{

    const find = (current,history) => {

        if(current == target){
            return history;
        }
        else if(current > target){
            return null;
        }
        else{
            return find(current + 3,`(${history} + 3)`) || find(current * 3,`${history} * 3)`);
        }

    }
    return find(1,"1");

};

console.log(findSolution(63));

const printFarmAnimals = (cows,chickens) => {

    let cowString = String(cows);
    cowString = cowString.padStart(3,"0");
    let chickenString = String(chickens);
    chickenString = chickenString.padStart(3,"0");
    console.log(`Cows : ${cowString} and Chickens = ${chickenString}`);

};

let animals = pad(10,"#");
console.log(animals("Pigs",4));
console.log(animals("Tiger",10));


let min = (number1,number2) => {

    return number1 > number2? number2: number2 > number1? number1: number1;

};

console.log(min(2,-10));


let isEven = (number) => {

    function abs(val){

        if(val < 0){
            return -1 * val;
        }
        else{
            return val;
        }

    };

    if(abs(number) === 0){
        return true;
    }
    else if(abs(number) == 1){
        return false;
    }
    else{

        return number < 0? isEven(number+2) : isEven(number-2);

    }

}

console.log(isEven(50));


let beanCounting = (aStr) => {

    let count = 0;
    for(let i = 0; i < aStr.length; i++){
        let character = aStr.charAt(i);
        if(character === "B"){
            count++;
        }
    }
    return count;

};

console.log(beanCounting("BBab")); // 4


let countChar = (aStr,aChar) => {

    let count = 0;
    for(let i = 0; i < aStr.length; i++){
        let character = aStr.charAt(i);
        if(character === aChar){
            count++;
        }
    }
    return count;

}

console.log(countChar("baada","d"));



function matchHouses(step) {

    if(step == 1){
        return 6;
    }
    else if(step == 0){
        return 0;
    }
    else{
        return 5 + matchHouses(step-1);
    }

}

class Person{

    constructor(name,age){

        this.name = name;
        this.age = age;

    }

    compareAge(other) {

        if (this.age > other.age) {
            return `${other.name} is youger than me.`;
        } else if (this.age < other.age) {
            return `${other.name} is older than me.`;
        } else {
            return `${other.name} is the same age as me.`;
        }
    }

};

function toBinary(num) {
    return (num >> 0).toString(2);
}

function seriesResistance(arr) {
    let total = 0;
    for(let i = 0; i < arr.length; i++){
        total += arr[i];
    }
    return total > 1? `${total} ohms`: `${total} ohm`;
}

function whichIsLarger(f, g) {
    if(f() > g()){
        return "f";
    }
    else if(f() < g()){
        return "g";
    }
    else{
        return "neither";
    }
}

function shiftToLeft(x, y) {
    return x * (2**y);
}

function numberSplit(n) {
    if(n % 2 != 0){
        let half = Math.floor(n / 2);
        let numArray = [half,half+1];
        return numArray;
    }
    else{
        let half = Math.floor(n / 2);
        let numArray = [half,half];
        return numArray;
    }
}

function signYourName(obj) {
    // write your code here
    // don't use a return statement

    Object.seal(obj);


    // DON'T CHANGE OR REMOVE THE LINES BELOW
    obj.yourSignature = "Whatever";
    obj.spouseSignature = "Nice Try"
    return obj;
}

function toBinary2(num){

  return (num >> 0).toString(2);

}

function flip(y){

    return Number(!y);

}

function doubleChar(aStr){

    let newStr = "";
    for(let i = 0; i < aStr.length; i++){
        newStr += aStr.charAt(i);
        newStr += aStr.charAt(i);
    }
    return newStr;

}

function crazyfunction(num1,num2){

    return num1 ^= num2;

}

function emotify(sentence){

    return sentence.replace("sad",":(").replace("smile",":D").replace("grin",":)").replace("mad",":P");

}

function checkTitle(title) {
    let strArray = title.split(" ");
    for(let i = 0; i < strArray.length; i++){
        if(strArray[i].charAt(0) == strArray[i].charAt(0).toUpperCase()){
            continue;
        }
        else{
            return false;
        }
    }
    return true;
}
function isFirstSuperior(arr1, arr2) {
    for(let i = 0; i < arr1.length; i++){

        let val1 = arr1[i];
        let val2 = arr2[i];
        if(val1 > val2){
            return true;
        }
        else if(val2 > val1){
            return false;
        }
    }
    return false;
}
function isTrue(relation) {
    return eval(relation.replace("=","=="));
}

function countTrue(boolArr){

    let count = 0;
    for(let i = 0; i < boolArr.length; i++){
        if(boolArr[i]){
            count++;
        }
    }
    return count;

}

function getOnlyEvens(nums) {

    let newArr = [];
    for(let i = 0; i < nums.length; i++){
        if(nums[i] % 2 === 0 && i % 2 === 0){
            newArr.push(nums[i]);
        }
    }
    return newArr;

}

getOnlyEvens([1,4,7,6]);

function dropRight(numArr,amount=1){

    for(let i = 0; i < amount; i++){
        numArr.pop();
    }
    return numArr;

}

function filterArray(theArr){

    let newArr = [];
    for(let i = 0; i < theArr.length; i++){
        if(typeof theArr[i] === String){
            continue;
        }
        else{
            newArr.push(theArr[i]);
        }
    }
    return newArr;

}

function redundant(aStr){

    return func1 => aStr;

}

function myPi(aNum){

    return Number.parseFloat(Math.PI.toFixed(aNum));
}

function sortByLength(strArr){

    strArr.sort((a,b) => a.length - b.length);

    return strArr;

}

function filterArray(aArr){

    let newArr = [];
    for(let i = 0; i < aArr.length; i++){
        if(typeof aArr[i] == 'string'){
            continue;
        }
        else{
            newArr.push(aArr[i]);
        }
    }
    return newArr;

}

function repetition(aStr,times){

    if(times == 1){
        return aStr;
    }
    else{
        return aStr + repetition(aStr,times-1);
    }

}

function greetingMaker(salutation) {
    return function closure(name) {
        return salutation + ", " + name
    }
}

function anotherFunc(aFunc) {
    let str = "bye"
    aFunc(str);
    setTimeout(() => {
    }, 100)
}

var doc = "hello"

function callback(str) {
    doc = str
}

let promise = new Promise( (resolve,reject) => {

    setTimeout(() => {
        resolve("astr");
    },1000)

})

function sumOfCubes(numArr){

    let total = 0;
    for(let i = 0; i < numArr.length; i++){
        total += numArr[i]**3;
    }
    return total;

}

function generation(x,char){

    if(x === 0){
        return "me!";
    }
    else if(x === -3){
        return char === "m"? "great grandfather": "great grandmother";
    }
    else if(x === -2){
        return char === "m"? "grandfather": "grandmother";
    }
    else if(x === -1){
        return char === "m"? "father": "mother";
    }
    else if(x === 1){
        return char === "m"? "son": "daughter";
    }
    else if(x === 2){
        return char === "m"? "grandson": "granddaughter";
    }
    else{
        return char === "m"? "great grandson": "great granddaughter";
    }

}
function isAvgWhole(numArr){

    let sum = numArr.reduce((a,b) => a+b);
    return Number.isInteger(sum / numArr.length);

}

function highestDigit(number){

    let numString = String(number);
    let max = 0;
    for(let i = 0; i < numString; i++){
        let digit = Number.parseInt(numString[i]);
        if(digit > max){
            max = digit;
        }
    }
    return max;

}


isAvgWhole([1, 3]);


console.log(repetition("ab",3));

let listOfNumbers = [2,3,5,7,11];

console.log(flip(0));

console.log(crazyfunction(17,35));


function removeVowels(aStr){

    let vowels = "aeiouAEIOU";
    let newStr = "";
    for(let i = 0; i < aStr.length; i++){
        let aChar = aStr.charAt(i);
        if(vowels.includes(aChar)){
            continue;
        }
        else{
            newStr += aChar;
        }
    }
    return newStr;

}

function bomb(aStr){

    aStr = aStr.toLowerCase();
    if(aStr.includes("bomb")){
        return "Duck!!!";
    }
    else{
        return "There is no bomb, relax."
    }

}

function factorial(num) {
    if(num === 1){
        return 1;
    }
    else{
        return num * factorial(num-1);
    }
}


function singleOccurrence(aStr){

    if(aStr.length === 0){
        return "";
    }
    else{
        aStr = aStr.toLowerCase();
        for(let i = 0; i < aStr.length; i++){
            let aChar = aStr.charAt(i);
            if(aStr.indexOf(aChar) === aStr.lastIndexOf(aChar)){
                return aChar.toUpperCase();
            }
        }

    }

}

let student = {

    name: "Student",
    classes: []

};

student.name = "Carlson";

student.age = 20;

console.log(student.name);

console.log(student.age);

delete student.age;

console.log(student.age);

console.log("name" in student);

console.log(Object.keys(student));

function possibleBonus(a, b) {
    if(a > b || a === b){
        return false;
    }
    else{
        return Math.abs(a-b) >= 1 && Math.abs(a-b) <= 6;
    }
}


function differenceTwo(intArr){

    let resArr = [];
    intArr.sort();
    for(let i = 0; i < intArr.length; i++){
        for(let j = 0; j < intArr.length; j++){
            if(Math.abs(intArr[i] - intArr[j]) === 2){
                let pair = [];
                pair[0] = Math.min(intArr[i],intArr[j]);
                pair[1] = Math.max(intArr[i],intArr[j]);
                // check if pair is in resArr
                let pairFound = false;
                for(let i = 0; i < resArr.length; i++){
                    if(resArr[i][0] === pair[0] && resArr[i][1] === pair[1]){
                        pairFound = true;
                    }
                }
                if(!pairFound) {
                    resArr.push(pair);
                }
                else{
                    pairFound = false;
                }
            }
        }
    }
    return resArr;

}

function getAbsSum(intArr){

    let total = 0;
    for(let i = 0; i < intArr.length; i++){
        total += Math.abs(intArr[i]);
    }
    return total;

}

differentTwo([4,3,1,5,6]);


function factorial(aNum){

    if(aNum === 1){
        return 1;
    }
    else{
        return aNum * factorial(aNum-1);
    }

}


function findLargestNums(matrix){

    let maxArr = [];
    for(let i = 0; i < matrix.length; i++){
        let innerArr = matrix[i];
        let maxNum = 0;
        // check if arr is all negative
        let isNegative = false;
        for(let j = 0; j < innerArr.length; j++){
            if(innerArr[j] >= 0){
                isNegative = false;
                break;
            }
            else{
                isNegative = true;
            }
        }
        if(isNegative){
            maxNum = innerArr[0]*-1;
            for(let j = 0; j < innerArr.length; j++){
                maxNum = Math.min(maxNum,Math.abs(innerArr[j]));
            }
            maxArr.push(-maxNum);
        }
        else {
            for (let j = 0; j < innerArr.length; j++) {
                maxNum = Math.max(maxNum, innerArr[j]);
            }
            maxArr.push(maxNum);
        }
    }
    return maxArr;

}

console.log(findLargestNums([[4, 2, 7, 1], [20, 70, 40, 90], [1, 2, 0]]));
console.log(findLargestNums([[-34, -54, -74], [-32, -2, -65], [-54, 7, -43]]));



function sortNumsAscending(numArr){

    if(numArr === null || numArr === undefined || numArr.length === 0){
        return [];
    }
    else{
        numArr.sort((a,b) => a-b);
        return numArr;
    }

}

console.log(sortNumsAscending([1, 2, 10, 50, 5]));

function countVowels(aStr){

    let vowels = "aeiouAEIOU";
    let count = 0;
    for(let i = 0; i < aStr.length; i++){
        let aChar = aStr[i];
        if(vowels.includes(aChar)){
            count++;
        }
    }
    return count;

}


function shiftToRight(aNum,power){

    return Math.floor(aNum / 2**power);

}




let obj1 = {

    name: "Hello",
    task: " World"

};

let obj2 = {

    "the name": "Cameron",
    "the lvl": 99,
    "the type": "fire water"

};

console.log(obj2["the name"] + obj2["the lvl"] + obj2["the type"]);

let arr = [1,2,3,4];

console.log("arr = " + arr);

console.log(arr.shift());

arr.unshift(10);

console.log(arr);

let newArr = arr.slice(0,2).concat(arr.slice(3));
console.log(newArr);

console.log(typeof []);

console.log(obj1.name + obj1.task);

let aStr = "This is a sentence";

let aStrArr = aStr.split(" ");

console.log(aStrArr);

console.log(aStr.repeat(3));

function max(...numbers){

    let maxNum = 0;
    for(let number of numbers){
        if(number > maxNum){
            maxNum = number;
        }
    }
    return maxNum;

}

function min(...numbers){

    if(numbers.length === 0){
        console.log("Enter numbers to calculate min");
    }
    else{

        let minNum = numbers[0];
        for(let number of numbers){
            if(number < minNum){
                minNum = number;
            }
        }
        return minNum;

    }

}

console.log(min());

let numArr = [313212,421431,52342412,413452135,215,12354213];

console.log(min(...numArr));

console.log(JSON.stringify(numArr));

let obj3 = {"name": "Jason","age": 10};

console.log(JSON.stringify(obj3));


function range(num1,num2,step=1){

    let arr1 = [];
    num1 = Math.min(num1,num2);
    num2 = Math.max(num1,num2);
    for(let i = num1; i < num2; i += step){
        arr1.push(i);
    }
    return arr1;

}

function sum(...numArr){

    let total = 0;
    for(let number of numArr){
        total += number;
    }
    return total;

}


function reverseArray(aArr){

    let newArr = aArr.reverse();
    return newArr;

}

console.log(reverseArray([1,2,3]));

function reverseArrayInPlace(theArr){


    let newArr = [];
    for(let i = theArr.length-1; i >= 0; i--){
        newArr.push(theArr[i]);
    }
    theArr = newArr.slice();
    return theArr;


    let middle = theArr.length / 2;
    for(let i = 0, j = theArr.length-1; i < middle && j > middle; i++, j--){

        let elem = theArr[i];
        let elem2 = theArr[j];
        theArr[i] = elem2;
        theArr[j] = elem;

    }
    return theArr;

}


function arrayToList(aArr){

    let list = {
        value: 0,
        rest : null

    };
    let spot;
    for(let i = 0; i < aArr.length; i++){

        spot = list
        while(spot.rest != null){
            spot = spot.rest;
        }
        spot.value = aArr[i];
        spot.rest = {value: 0, rest: null};

    }
    spot = list;
    return spot;

}

function listToArray(list){

    let newArr = [];

    let node = list;
    while(node.rest != null){
        newArr.push(node.value);
        node = node.rest;
    }
    newArr.push(node.value);
    return newArr;

}

//console.log(reverseArrayInPlace([1,2,3]));

console.log(arrayToList([1,2,3]));

let newList = {

    value : 10,
    rest : {
        value : 20,
        rest : {
            value : 30,
            rest : {
                value : 40,
                rest : null
            }
        }
    }

};

function prepend(elem,aList){

    let newList = {

        value: elem,
        rest : null

    };
    newList.rest = aList;
    return newList;

}

function nth(aList,elem){

    let index = 0;
    let node = aList;
    while(node.rest != null){
        if(node.value === elem){
            return index;
        }
        node = node.rest;
        index++;
    }
    console.log("Element unable to be found in list");

}

function deepEqual(elem1,elem2){

    if(typeof elem1 === 'object' && elem1 !== null && typeof elem2 === 'object' && elem2 !== null){
        let elem1Keys = elem1.keys();
        let elem2Keys = elem2.keys();
        elem1Keys.sort();
        elem2Keys.sort();
        if(elem1Keys.length !== elem2Keys.length){
            return false;
        }
        else{
            for(let i = 0; i < elem1Keys.length; i++){
                if(elem1Keys[i] !== elem2Keys[i]){
                    return false;
                }
            }
            return true;
        }
    }
    else{
        return elem1 === elem2;
    }

}

console.log(listToArray(newList));




function repeat(n,action){

    for(let i = 0; i < n; i++){
        action(i);
    }

};

repeat(10,console.log);

let labels = [];

repeat(20,i => {

    labels.push(`Unit ${i+1}`);

});

console.log(labels);

let squares = [];

repeat(2,i => {

    squares.push(i**2);

});

console.log(squares);

function greaterThan(n){

    return m => m > n;

}

let func1 = greaterThan(10);
console.log(func1(20));

function lessThan(n){

    return m => m < n;

}

let func2 = lessThan(10);
console.log(func2(15));

function noisy(f){

    return (...args) => {

        console.log("calling with",args);
        let result = f(...args);
        console.log("called with",args,",returned",result);
        return result;

    };

}

function useless(test,then){

    if(!test){
        then();
    }

}

function repeat2(n,action){

    action(n);

}


repeat2(3,n => {
    useless(n % 2 === 0, () => {
        console.log(n,"is odd");
    })
});

let arr = ["A","B"];

arr.forEach(e => console.log(e));




noisy(Math.max)(3,2,1);


function sevenBoom(numArr=[]){

    return numArr.map(e => String(e).includes("7")).includes(true)? "Boom!": "there is no 7 in the array";

}

console.log(sevenBoom([8,97,33,100]));

function findHighest(numArr=[]){

    if(numArr.length === 1){
        return numArr[0];
    }
    else{
        if(numArr[0] > numArr[numArr.length-1]){
            return findHighest(numArr.splice(0,numArr.length-1));
        }
        else{
            return findHighest(numArr.splice(1));
        }
    }

}

function toArray(aObj){


    let newArr = [];
    let newSubArr = [];
    let keys = Object.keys(aObj);
    for(let eachKey of keys){
        newSubArr.push(eachKey);
        newSubArr.push(aObj[eachKey]);
        newArr.push(newSubArr);
        newSubArr = [];
    }
    return newArr;

}

function arrayOfMultiples(num,length){

    let newArr = [];
    for(let i = num; newArr.length < length; i += num){
        newArr.push(i);
    }
    return newArr;

}

function removeLeadingTrailing(aNumStr){

    // check right first

    let number = Number.parseFloat(aNumStr);
    return String(number);

}

class Rectangle{

    constructor(x,y,width,height){
        this.x = x;
        this.y = y;
        this.width = width;
        this.height = height;
    }

    toString(){

        return `[x=${this.x}, y=${this.y}, width=${this.width}, height=${this.height}]`;

    }

}

let newRectangle = new Rectangle(10,20,30,40);
console.log(newRectangle.toString());


//console.log(toArray({a:1,b:2}));




function isRepdigit(aNum){

    if(aNum < 0){
        return false;
    }
    else{
        let numString = String(aNum);
        let firstDigit = numString.charAt(0);
        for(let i = 0; i < numString.length; i++){
            if(numString.charAt(i) !== firstDigit){
                return false;
            }
        }
        return true;
    }

}

class OnesThreesNines{

    constructor(theNum){
        this.number = theNum;
        this.ones = theNum;
        let tempNum = theNum;
        this.threes = 0;
        while(tempNum >= 3){
            this.threes += 1;
            tempNum -= 3;
        }
        tempNum = theNum;
        this.nines = 0;
        while(tempNum >= 9){
            tempNum -= 9;
            this.nines += 1;
        }
    }

}

function derivative(b, m) {
    return b * Math.pow(m,b-1);
}

function concat(...arrays){

    let newArr = [];
    for(let i = 0; i < arrays.length; i++){
        arrays[i].forEach(e => newArr.push(e));
    }
    return newArr;

}

console.log(concat([1,2,3],[4,5],[6,7]));

function intWithinBounds(num,lower,upper){

    for(let i = lower; i < upper; i++){
        if(i === num){
            return true;
        }
    }
    return false;

}

function makePlusFunction(baseNum){

    return m => m+baseNum;

}

function count(aNum){

    aNum = Math.abs(aNum);
    return String(aNum).length;

}


function paths(aNum){

    function factorial(number){

        if(number == 1){
            return 1;
        }
        else{
            return number * factorial(number-1);
        }

    }

    return factorial(aNum);


}



function checkEquals(arr1,arr2){

    arr1.sort();
    arr2.sort();
    for(let i = 0; i < arr1.length; i++){
        if(arr1[i] !== arr2[i]){
            return false;
        }
    }
    return true;

}

console.log(checkEquals([1,2],[1,2]));

function towerHanoi(discs) {
	return (2**discs)-1;
}

function perimeter(typeOfShape, aNum){

    return typeOfShape === "s"? aNum*4: 6.28 * aNum;

}

function testJackpot(slotOutcome){

    let firstOutcome = slotOutcome[0];
    for(let i = 0; i < slotOutcome.length; i++){
        let theChar = slotOutcome[i];
        if(theChar !== firstOutcome){
            return false;
        }
    }
    return true;

}

function secondLargest(numArr){

    numArr.sort((a,b) => a-b);
    return numArr[numArr.length-2];

}


function compat(anArr){

    let newArr = [];
    for(let i = 0; i < anArr.length; i++){
        let theElem = anArr[i];
        if(theElem === false || theElem === null || theElem === 0 || theElem === "" || theElem === undefined || Number.isNaN(theElem)){
            continue;
        }
        else{
            newArr.push(theElem);
        }
    }
    return newArr;

}



function objectToArray(aObj){

    let theKeys = Object.keys(aObj);
    for(let i = 0; i < theKeys.length; i++){



    }

}

function countBoomerangs(arr){

    let count = 0;
    for(let i = 0; i < arr.length-2; i++){

        if(arr[i] === arr[i+2] && arr[i+1] !== arr[i]){
            count++;
        }

    }
    return count;


}


class Rectangle {
    constructor(sideA, sideB) {
        this.sideA = sideA
        this.sideB = sideB
    }
    getArea(){return this.sideA*this.sideB}
    getPerimeter(){return (this.sideA + this.sideB) *2}
}


class Circle {

    constructor(radius){

        this.radius = radius;

    }

    getArea(){
        return Math.PI * (this.radius**2);
    }

    getPerimeter(){

        return 2 * Math.PI * this.radius;

    }

}


// unquote and use run to test these cases:

let q = new Circle(4.44);
console.log(q.getArea());
console.log(q.getPerimeter());


function coneVolume(height,radius){

    return Number(Number.parseFloat(((Math.PI * (radius**2)) * height) / 3).toFixed(2));

}

function allTruthy(...arr){

    for(let i = 0; i < arr.length; i++){

        let elem = arr[i];
        if(elem === false || elem === 0 || elem === "" || elem === null || elem === undefined || Number.isNaN(elem)){
            return false;
        }

    }
    return true;

}

function operation(num1,num2,operation){

    num1 = Number(num1);
    num2 = Number(num2);

    if(operation === "divide"){
        if(num2 === 0){
            return "undefined";
        }
        else{
            return num1 / num2;
        }
    }
    else if(operation === "multiply"){

        return num1 * num2;

    }
    else if(operation === "add"){

        return num1 + num2;

    }
    else if(operation === "subtract"){

        return num1 - num2;

    }

}

function objectToArray(obj){

    let firstArr = [];
    let secondArr = [];

    let keys = Object.keys(obj);

    for(let i = 0; i < keys.length; i++){

        let theKey = keys[i];
        let value = obj[theKey];
        secondArr.push(theKey);
        secondArr.push(value);
        firstArr.push(secondArr);
        secondArr = [];

    }
    if(secondArr.length > 0){
        firstArr.push(secondArr);
    }
    return firstArr;


}

function jazzify(arr) {

    for(let i = 0; i < arr.length; i++){

        if(arr[i].endsWith("7")){
            continue;
        }
        else{
            arr[i] = arr[i].concat("7");
        }

    }
    return arr;

}

function ascDesNone(arr,str){

    if(str === "Asc"){
        arr.sort((a,b) => a-b);
        return arr;
    }
    else if(str === "Des"){
        arr.sort((a,b) => b-a);
        return arr;
    }
    else{
        return arr;
    }

}


function addName(obj1,name,value){

    obj1[name] = value;
    return obj1;

}

function flatten(arr){

    let newArr = [];

    for(let i = 0; i < arr.length; i++){

        if(typeof arr[i] === 'object'){

            for(let j = 0; j < arr[i].length; j++){
                newArr.push(arr[i][j]);
            }

        }

    }
    return newArr;


}

function findNemo(astr){

    let words = astr.split(" ");
    for(let i = 0; i < words.length; i++){

        if(words[i] === "Nemo"){
            return `I found Nemo at ${i+1}!`;
        }

    }
    return "I can't find Nemo :(";


}

findNemo("I am Ne mo Nemo !");//, "I found Nemo at 5!")
findNemo("N e m o is NEMO NeMo Nemo !");//, "I found Nemo at 8!")
findNemo("I am Nemo's dad Nemo senior .");//, "I found Nemo at 5!")
findNemo("Oh, hello !");//, "I can't find Nemo :(")
findNemo("Is it Nemos, Nemona, Nemoor or Garfield?");//, "I can't find Nemo :(")
findNemo("Nemo is a clown fish, he has white and orange stripes. Nemo , come back!");//, "I found Nemo at 1!")


function doesTriangleFit(arr1,arr2){

    let perimeter1 = (arr1[0] + arr1[1] + arr1[2]) / 2;
    let perimeter2 = (arr2[0] + arr2[1] + arr2[2]) / 2;

    let area1 = Math.sqrt((perimeter1 * (perimeter1 - arr1[0]) * (perimeter1 - arr1[1]) * (perimeter1 - arr1[2])));

    let area2 = Math.sqrt((perimeter2*(perimeter2 - arr2[0]) * (perimeter2-arr2[1]) * (perimeter2-arr2[2])));

    if(Number.isNaN(area1) || Number.isNaN(area2)){
        return false;
    }
    else if(area2 < area1){
        return false;
    }
    else{
        return true;
    }




}

function indexMultiplier(arr){

    let total = 0;
    if(arr.length === 0){
        return 0;
    }
    else{

        for(let i = 0; i < arr.length; i++){
            total += arr[i] * i;
        }
        return total;

    }

}

function capToFront(aStr){

    let newStr = "";
    for(let eachletter of aStr){

        if(eachletter === eachletter.toUpperCase()){
            newStr += eachletter;
        }

    }
    for(let eachletter of aStr){

        if(eachletter === eachletter.toLowerCase()){
            newStr += eachletter;
        }

    }
    return newStr;

}

function totalVolume(...args){

    let total = 0;

    for(let i = 0; i < args.length; i++){

        let box = args[i];
        total += (box[0] * box[1] * box[2]);

    }
    return total;


}

function calculator(num1,operator,num2){

    if(operator === "/" && num2 === 0){
        return "Can't divide by 0!";
    }
    else{

        switch(operator){

            case "-":
                return num1 - num2;
            case "+":
                return num1 + num2;
            case "*":
                return num1 * num2;
            case "/":
                return num1 / num2;
            default:
                return null;

        }

    }

}


function sortIt(arr){

    arr.sort((a,b) => typeof a === 'object' && typeof b === 'object'? a[0] - b[0]: typeof a === 'object' && typeof b !== 'object'? a[0] - b: typeof a !== 'object' && typeof b === 'object'? a - b[0]: a-b);
    return arr;


}


function weight(radius,height){

    let volumedc = (Math.PI * (radius**2) * height) * 0.001;

    return Number.parseFloat(Number(volumedc).toFixed(2));


}

function isSpecialArray(arr){

    for(let i = 0; i < arr.length; i++){

        if(i % 2 === 0){
            if(arr[i] % 2 === 0){
                continue;
            }
            else{
                return false;
            }
        }
        else{
            if(arr[i] % 2 !== 0){
                continue;
            }
            else{
                return false;
            }
        }
    }
    return true;

}

function squareDigits(n) {
    let str = "";
    let strNum = String(n);
    for(let eachletter of strNum){
        let num = Number(eachletter);
        str += String(num**2);
    }
    return Number.parseInt(str);
}

function tempConversion(temp){

    let arr = [];
    arr.push(Number.parseFloat(Number(temp*(9/5) + 32).toFixed(2)));
    arr.push(Number.parseFloat(Number(temp + 273.15).toFixed(2)));
    if(arr[1] < 0){
        return "Invalid";
    }
    return arr;

}

function findASeat(capacity,train){

    let maxCapacity = capacity / train.length;
    for(let i = 0; i < train.length; i++){

        let percentage = train[i] / maxCapacity;
        if((percentage * 100) <= 50){
            return i;
        }

    }
    return -1;
}


 */

function dis(origPrice,discount){

    let rightDiscount = discount / 100;
    let amtOff = origPrice * rightDiscount;
    return Number.parseFloat(Number(origPrice - amtOff).toFixed(2));


}

//dis(100, 75)//, 25)
//dis(211, 50)//, 105.5)
//dis(593, 61)//, 231.27)
//dis(1693, 80)//, 338.6)
//dis(700, 10)//, 630)


function oddishOrEvenish(aNum){

    let strNum = String(aNum);
    let total = 0;
    for(let i = 0; i < strNum.length; i++){
        total += Number(strNum[i]);
    }
    return total % 2 == 0? "Evenish": "Oddish";

}

function numbersSum(arr){

    let total = 0;
    for(let i = 0; i < arr.length; i++){

        let elem = arr[i];
        if(typeof elem == 'number'){
            total += elem;
        }

    }
    return total;

}

function getDays(date1,date2){

    const oneDay = 24 * 60 * 60 * 1000;
    let diffDays = Math.round(Math.abs(date1 - date2) / oneDay);
    console.log(diffDays);
    return diffDays;

}

function fruitSalad(arr){

    let newArr = [];

    for(let eachelem of arr){
        let firstSub = eachelem.substr(0,(eachelem.length) / 2);
        let secondSub = eachelem.substr(eachelem.length / 2);
        newArr.push(firstSub);
        newArr.push(secondSub);
    }
    newArr.sort();
    return newArr.join("");

}


//console.log(fruitSalad(['apple', 'pear', 'grapes']));//, 'apargrapepesple')


function isTriplet(num1,num2,num3){

    let numArr = [];
    numArr.push(num1);
    numArr.push(num2);
    numArr.push(num3);
    numArr.sort((a,b) => a-b);
    return numArr[0]**2 + numArr[1]**2 === numArr[2]**2;

}

function trace(matrix){

    let total = 0;
    for(let i = 0; i < matrix.length; i++){

        total += matrix[i][i];

    }
    return total;


}

function countOnes(aNum){

    let binaryString = (aNum >>> 0).toString(2);
    let count = 0;
    for(let eachelem of binaryString){
        if(eachelem === "1"){
            count++;
        }
    }
    return count;

}


function evenLast(arr){

    if(arr.length === 0){
        return 0;
    }
    let total = 0;
    for(let i = 0; i < arr.length; i++){
        if(i % 2 === 0){
            total += arr[i];
        }
    }
    return total * arr[arr.length-1];

}

function measureDepth(arr){

    let string = JSON.stringify(arr);
    let count = 0;
    for(let eachelem of string){
        if(eachelem === "["){
            count++;
        }
    }
    console.log(count);
    return count;


}



function lineLength([x1,y1],[x2,y2]){

    let sqr1 = (x2-x1)**2;
    let sqr2 = (y2-y1)**2;
    return Number.parseFloat(Number(Math.sqrt(sqr1+sqr2)).toFixed(2));




}

measureDepth([[[[[[]]]]]])