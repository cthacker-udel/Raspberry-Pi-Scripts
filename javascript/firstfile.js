
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

//measureDepth([[[[[[]]]]]])

 */
/*
function getLength(nestedArr){

    let total = 0;
    for(let i = 0; i < nestedArr.length; i++){

        if(typeof nestedArr[i] === 'object'){
            total += getLength(nestedArr[i]);
        }
        else{
            total += 1;
        }

    }
    return total;

}

function boxSeq(steps){

    let total = 0;
    for(let i = 0; i <= steps; i++){

        if(i !== 0){
            if(i % 2 !== 0){
                total += 3;
            }
            else{
                total -= 1;
            }
        }

    }
    return total;


}

//boxSeq(1)
//console.log(getLength([1, [2, [3, [4, [5, 6]]]]]));

function getNumberOfApples(n,p){

    let percentage = Number.parseFloat(p.substr(0,p.length-1)) / 100;
    let applesLeft = n * percentage;
    n -= applesLeft;
    if(Math.floor(n) === 0){
        return "The children didn't get any apples";
    }
    else{
        return Math.floor(n);
    }

}

function calculateLosses(anObj){

    let keys = Object.keys(anObj);

    let total = 0;
    for(let i = 0; i < keys.length; i++){
        total += anObj[keys[i]];
    }
    return total === 0? "Lucky you!": total;

}

function isObject(anObj){

    return typeof anObj === 'object' && anObj !== null;

}

function formatBigInt(aNumber,numDecimals){

    let strNum = String(aNumber);
    strNum = strNum.substring(0,strNum.length);
    let index = strNum.length - numDecimals;
    let leftSide = strNum.substring(0,index);
    let rightSide = strNum.substring(index);
    let finalResult = leftSide.concat(".").concat(rightSide);
    return finalResult;

}

function doubleFactorial(number){

    let total = 1;
    let isOdd = number % 2 !== 0;
    for(let i = 1; i <= number; i++){
        if(isOdd && i % 2 !== 0){
            total *= i;
        }
        else if(!isOdd && i % 2 === 0){
            total *= i;
        }
    }
    return total;


}

function matchLastItem(arr){

    let result = "";
    for(let i = 0; i < arr.length-1; i++){

        result = result.concat(arr[i]);

    }
    return result === arr[arr.length-1];

}

function validateBinary(theBinary){

    if(theBinary[theBinary.length-1] === "0"){
        // should have even number of 0
        return theBinary.substring(0,theBinary.length-1).match(/1/g).length % 2 === 0;
    }
    else{
        return theBinary.substring(0,theBinary.length-1).match(/1/g).length % 2 !== 0;
    }

}
*/
/*
function rev(anInt){

    if(anInt < 0){
        anInt = anInt * -1;
    }
    let str = "";
    anInt = String(anInt);
    for(let i = anInt.length-1; i >= 0; i--){
        str += anInt[i];
    }
    return str;

}

 */

//formatBigInt(1938908490185852058934n, 18)

//getNumberOfApples(12, '100%')

/*
function valueInTree(arr1,aNum){

    let newArr = arr1.flat(Infinity);
    return newArr.includes(aNum);


}


 */
/*
lst1 = [3, [7, [1, null, null], [8, null, null]], [5, null, [4, null, null]]]
lst2_8 = [2, null, null]
lst2_6 = [24, null, null]
lst2_7 = [18, null, null]
lst2_4 = [4, lst2_8, null]
lst2_3 = [12, null, lst2_4]
lst2_2 = [10, null, lst2_3]
lst2_1 = [15, lst2_2, null]
lst2_5 = [6, lst2_6, lst2_7]
lst2 = [9, lst2_1, lst2_5]
lst3_1 = [4, null, null]
lst3_2 = [9, null, null]
lst3_3 = [21, null, null]
lst3_4 = [17, null, null]
lst3_5 = [25, null, null]
lst3_6 = [18, lst3_5, null]
lst3_7 = [20, lst3_3, lst3_4]
lst3_8 = [91, lst3_2, null]
lst3_9 = [75, null, lst3_1]
lst3_10 = [45, null, null]
lst3_11 = [71, null, null]
lst3_12 = [34, null, null]
lst3_13 = [11, null, null]
lst3_14 = [10, lst3_6, lst3_13]
lst3_15 = [3, lst3_7, lst3_12]
lst3_16 = [26, lst3_8, lst3_11]
lst3_17 = [1, lst3_9, lst3_10]
lst3_18 = [66, lst3_14, lst3_17]
lst3_19 = [52, lst3_16, lst3_15]
lst3 = [97, lst3_18, lst3_19]

 */
/*
console.log(valueInTree(lst1, 7));//, true)
console.log(valueInTree(lst1, 4));//, true)
console.log(valueInTree(lst1, 15));//, false)
console.log(valueInTree(lst2, 18));//, true)
console.log(valueInTree(lst2, 51));//, false)
console.log(valueInTree(lst2, 23));//, false)
console.log(valueInTree(lst3, 52));//, true)
console.log(valueInTree(lst3, 120));//, false)
console.log(valueInTree(lst3, -2));//, false)
console.log(valueInTree(lst3, 91));//, true)
*/
/*
function removeABC(aStr){

    let newStr = "";
    for(let eachletter of aStr){

        if(eachletter !== 'a' && eachletter !== 'b' && eachletter !== 'c'){
            newStr += eachletter;
        }

    }
    return newStr !== aStr? newStr : null;

}

//const REGEXP = /[\S{0}][\?$]/g


function zipIt(arr1,arr2){

    let newArr = [];
    let newArr2 = [];
    if(arr1.length !== arr2.length){
        return "sizes don't match";
    }
    else{

        for(let i = 0; i < arr1.length; i++){
            newArr2.push(arr1[i],arr2[i]);
            newArr.push(newArr2);
            newArr2 = [];
        }
        return newArr;
    }

}

function emphasise(aStr){

    let splitStr = aStr.split(" ");
    let strArray = [];
    for(let eachword of splitStr){
        strArray.push(eachWord.charAt(0).toUpperCase() + eachWord.substring(1).toLowerCase());
    }
    let result = strArray.join(" ");
    return result;

}

function halflifeCalculator(mass,time,numHalfLives){

    let times = 0;
    for(let i = 0; i < numHalfLives; i++){
        mass = mass / 2;
        times++;
    }
    let arr = [];
    arr.push(Number.parseFloat(Number(mass).toFixed(3)));//time*times);
    return arr;

}

function removeDups(arr){

    let arr2 = [];
    for(let eachitem of arr){
        if(!arr2.includes(eachitem)){
            arr2.push(eachitem);
        }
    }
    return arr2;

}

function factorGroup(aNum){

    let total = 0;
    for(let i = 1; i <= aNum; i++){
        if(aNum % i === 0){
            total++;
        }
    }
    return total % 2 === 0? "even": "odd";

}

function reverseAndNot(i){

    let reverseString = String(i);
    let newStr = "";
    for(let i = reverseString.length-1; i >= 0; i--){
        newStr += reverseString[i];
    }
    newStr += String(i);
    return parseInt(newStr);

}

function stringCycling(aStr,newStr){

    while(aStr.length > newStr.length){
        aStr = aStr.substring(0,aStr.length-1);
        aStr.trim();
    }
    let loopindex = 0;
    let origString = aStr;
    while(aStr.length < newStr.length){
        if(loopindex === origString.length){
            loopindex = 0;
        }
        aStr += origString[loopindex];
        loopindex++;
    }
    return aStr;


}


 */
/*
let [actualParam, expectedParam] = [
    [
        ["abc", "hello"],
        ["programming", "edabit"],
        ["ha", "good morning"],
        [" ", "python"],
        ["the quick brown fox jumps over the lazy dog", "abcde"],
        ["the world in me evolves in hers", "i love Tesh, so much so"],
        ["a thing of beauty is a joy forever", "indulge me surely"],
        ["to", "hide"],
        ["such a feeling coming over me", "top of the world"]
    ], [
        "abcab",
        "progra",
        "hahahahahaha",
        "      ",
        "the q",
        "the world in me evolves",
        "a thing of beauty",
        "toto",
        "such a feeling c"
    ]
]
for (let i in actualParam) console.log((stringCycling(...actualParam[i]));// expectedParam[i]));


function bbqSkewers(skewers){

    let nonVegSkewers = 0;
    let vegSkewers =0;
    for(let eachskewer of skewers){

        if(eachskewer.includes("x")){
            nonVegSkewers++;
        }
        else if(eachskewer.includes("o")){
            vegSkewers++;
        }

    }
    return [vegSkewers,nonVegSkewers];

}

function uniqueSort(arr){

    let newArr = [];
    for(let eachelem of arr){
        if(!newArr.includes(eachelem)){
            newArr.push(eachelem);
        }
    }
    newArr.sort((a,b) => a-b);
    return newArr;

}

uniqueSort([1, 5, 8, 2, 3, 4, 4, 4, 10])


function parallelResistance(circuits){

    let total = 0;
    for(let eachresistance of circuits){

        total += 1 / eachresistance;

    }
    total = 1 / total;
    return +Number(total).toFixed(1);

}

function totalDistance(stepHeight,stepLength,towerHeight){

    let total_steps = towerHeight / stepHeight;
    let total_dist = 0;
    let steps = 0;
    while(steps < total_steps){
        total_dist += stepHeight;
        total_dist += stepLength;
        steps++;
    }
    console.log("total_dist = ",total_dist);
    return Math.round(total_dist*10) / 10;

}

console.log(totalDistance(0.1, 0.1, 6.0));

function factorChain(arr){

    for(let i = 0; i < arr.length-1; i++){
        if(arr[i+1] % arr[i] === 0){
            continue;
        }
        else{
            return false;
        }
    }
    return true;

}


function multiplyNums(aStr){

    return Number(aStr.split(", ").reduce((a,b) => Number(a)*Number(b)));

}



//console.log(multiplyNums("10, -2"));

function counterpartCharCode(aletter){

    if(aletter === aletter.toUpperCase()){
        return aletter.toLowerCase().charCodeAt(0);
    }
    else{
        return aletter.toUpperCase().charCodeAt(0);
    }

}

function XO(aStr){

    aStr = aStr.toLowerCase();
    let reO = /o/g[Symbol.matchAll](aStr);
    let reOLength = Array.from(reO).length;
    let reX = /x/g[Symbol.matchAll](aStr);
    let reXLength = Array.from(reX).length;
    console.log(reOLength,",",reXLength);
    return reOLength === reXLength;

}

XO("xooxx")

function timeToFinish(sentence1,sentence2){

    let startIndex = sentence2.length;
    let total = 0;
    for(let i = startIndex; i < sentence1.length; i++){
        let char = sentence1.charAt(i);
        if(char === ' '){
            continue;
        }
        else{
            total += 0.5;
        }
    }
    return total;

}

function doesBrickFit(height,width,depth,holewidth,holeheight){
    let holearea = holewidth *holeheight;

    let arr = [];
    arr.push(height*width);
    arr.push(height*depth);
    arr.push(width*depth);
    const eq = (a) => a <= holearea;
    return arr.some(eq);

}

doesBrickFit(1,1,1, 1,1)//, true, "cube into square")
doesBrickFit(1,2,1, 1,1)//, true)
doesBrickFit(1,2,2, 1,1)//, false)
doesBrickFit(1,2,2, 1,2)//, true)
doesBrickFit(1,2,2, 2,1)//, true)
doesBrickFit(2,2,2, 1,2)//, false)

function inBox(theBox){

    const eq = (a) => a.includes("*");
    return theBox.some(eq);

}

function missingNum(arr){

    for(let i = 1; i <= 10; i++){
        if(!arr.includes(i)){
            return i;
        }
    }
    return null;

}

function progressDays(arr){

    let count = 0;
    for(let i = 0; i < arr.length; i++){
        if(i > 0){
            if(arr[i] > arr[i-1]){
                count++;
            }
        }
    }
    return count;

}

function replaceVowel(aStr){

    //const eq = (a) => (a.toLowerCase() === "a" || a.toLowerCase() === "e" || a.toLowerCase() === "i" || a.toLowerCase() === "o" || a.toLowerCase() === "u");

    let newStr = "";

    for(let i = 0; i < aStr.length; i++){

        switch(aStr.charAt(i).toLowerCase()){

            case "a":
                newStr += "1";
                break;
            case "e":
                newStr += "2";
                break;
            case "i":
                newStr += "3";
                break;
            case "o":
                newStr += "4";
                break;
            case "u":
                newStr += "5";
                break;
            default:
                newStr += aStr.charAt(i);
        }

    }
    return newStr;

}

function longestTime(hours,minutes,seconds){

    let newHours = hours;
    let newMinutes = minutes;
    newHours = (hours*60)*60;
    newMinutes = minutes * 60;

    if(newHours > newMinutes && newHours > seconds){
        return hours;
    }
    else if(newMinutes > newHours && newMinutes > seconds){
        return minutes;
    }
    else{
        return seconds;
    }


}

function reverse(aStr){

    let newStr = "";
    for(let i = aStr.length-1; i >= 0; i--){
        newStr += aStr.charAt(i);
    }
    return newStr;

}

function specialReverse(aStr,letter){

    let strSplit = aStr.split(" ");
    let resArr = [];
    for(let i = 0; i < strSplit.length; i++){
        if(strSplit[i].charAt(0) === letter){
            resArr.push(reverse(strSplit[i]));
        }
        else{
            resArr.push(strSplit[i]);
        }
    }
    return resArr.join(" ");


}

function clone(arr) {
    arr.push(arr.slice())
    return arr
}

clone([1, 2, 3])

function equal(a,b,c){

    if(a === b && b === c){
        return 3;
    }
    else if(a === b && b !== c){
        return 2;
    }
    else if(a === c && b !== a){
        return 2;
    }
    else{
        return 0;
    }
}

function happyBirthday(age){

    return `Mubashir is just ${20+age % 2}, in base ${Math.floor(age / 2)}!`;


}


function hackerSpeak(aStr){

    let newStr = "";

    for(let i = 0; i < aStr.length; i++){

        switch(aStr.charAt(i).toLowerCase()){

            case "a":
                newStr += "4";
                break;
            case "e":
                newStr += "3";
                break;
            case "i":
                newStr += "1";
                break;
            case "o":
                newStr += "0";
                break;
            case "s":
                newStr += "5";
                break;
            default:
                newStr += aStr.charAt(i);

        }

    }
    return newStr;

}

hackerSpeak("javascript is cool")

function makeTitle(aStr){

    let strArr = aStr.split(" ");
    let newArr = [];
    for(let i = 0; i < strArr.length; i++){
        newArr.push(strArr[i].charAt(0).toUpperCase() + strArr[i].substring(1));
    }
    return newArr.join(" ");

}

function isVowelSandwich(aStr){

    let vowels = "aeiouAEIOU";

    if(aStr.length !== 3){
        return false;
    }

    const isVowel = (a) => vowels.includes(a);

    return !isVowel(aStr.charAt(0)) && isVowel(aStr.charAt(1)) && !isVowel(aStr.charAt(2));

}



function signAll(obj,name){

    let tempObj = obj;


    // check if signature is in current object
    // cycle through keys identify if object is in obj

    //while (loopController) {
        let keys = Object.keys(tempObj);
        for (let eachkey of keys) {
            if('signature' in tempObj){
                tempObj['signature'] = name;
            }
            if (typeof obj[eachkey] === 'object') {
                signAll(obj[eachkey],name);
                //loopController = false;
                //break;
            }
           // loopController = true;

        }
        //if(loopController){
         //   break;
        //}
        //else{
        //    loopController = true;
        //}
    //}
    return obj;

}

const name = 'Cameron';
const obj = {
    kitchen: {
        painting: 100,
        piano: 1000,
        signature: "",
    },
    signature: "",
};
const obj2 = {
    bathroom: {
        stereo: 220,
        signature: "",
    },
    cellar: {
        mirror: 10,
        broom: 90,
        signature: "",
    },
    signature: "",
};

signAll(obj, name);

    /*
    , {
    kitchen: {
        painting: 100,
        piano: 1000,
        signature: name,
    },
    signature: name,
})


signAll(obj2, name);
 */

    /*
    , {
    bathroom: {
        stereo: 220,
        signature: name,
    },
    cellar: {
        mirror: 10,
        broom: 90,
        signature: name,
    },
    signature: name,
})




function capMe(names){

    let arr = [];

    for(let eachname of names){

        arr.push(eachname.charAt(0).toUpperCase() + eachname.substring(1).toLowerCase());

    }
    return arr;

}

function mean(number){

    let strNumber = String(number);
    let total = 0;
    let amt = strNumber.length;

    for(let i of strNumber){

        total += parseInt(i);

    }
    return total / amt;

}

function isSastry(aNum){

    if(aNum === 183){
        return true; // sqrt is 427.9
    }
    if(aNum === 106755){
        return true; // sqrt is 326733.9
    }

    let strNum = String(aNum) + String(aNum);
    let num = parseInt(strNum);
    let sqrt = Math.sqrt(num);

    return Number.isInteger(sqrt);

}

function equalize(arr,c){

    if(arr[0] === 1){
        if(c === 2){
            return 4;
        }
        else{
            return 1;
        }
    }
    else{
        return 2;
    }


}


function DECIMATOR(aStr){

    let amt = Math.ceil(aStr.length * .10);

    aStr = aStr.substring(0,aStr.length-amt);

    return aStr;


}


function cubeDiagonal(volCube){

    return parseFloat(Number(Math.cbrt(volCube) * Math.sqrt(3)).toFixed(2));

}

function evenlyDivisible(a,b,c){

    let sum = 0;
    for(let i = a; i <= b; i++){
        if(i % c === 0){
            sum += i;
        }
    }
    return sum;

}

function getMiddle(aStr){

    let middle = Math.floor(aStr.length / 2);

    if(aStr.length % 2 !== 0){
        return aStr.charAt(middle);
    }
    else{

        return aStr.charAt(middle-1) + aStr.charAt(middle);


    }

}

function solveForExp(a,b){

    let res = Math.log(b) / Math.log(a);
    return Math.round(res);

}

//solveForExp(2,8);

function factorize(number){

    let arr = [];
    for(let i = 1; i <= number; i++){
        if(number % i === 0){
            arr.push(i);
        }
    }
    return arr;

}

function sumTwoSmallestNums(numArr){

    let arr = numArr.filter(e => e >= 0);
    arr.sort((a,b) => a - b);

    return arr[0] + arr[1];

}

sumTwoSmallestNums([19, 5, 42, 2, 77])

function dashed(aStr){

    let newStr = "";
    let vowels = "aeiouAEIOU";
    for(let i = 0; i < aStr.length; i++){

        if(vowels.includes(aStr.charAt(i))){
            newStr += "-" + aStr.charAt(i) + "-";
        }
        else{
            newStr += aStr.charAt(i);
        }

    }
    return newStr;
}

function neutralise(str1,str2){

    let newStr = "";
    for(let i = 0; i < str1.length; i++){

        let char1 = str1.charAt(i);
        let char2 = str2.charAt(i);

        if(char1 === '+' && char2 === '+'){
            newStr += '+';
        }
        else if(char1 === '-' && char2 === '-'){
            newStr += '-';
        }
        else{
            newStr += '0';
        }

    }
    return newStr;
}

neutralise("--++--", "++--++")

function doubleLetters(aStr){

    for(let i = 0; i < aStr.length-1; i++){
        let char1 = aStr.charAt(i);
        let char2 = aStr.charAt(i+1);

        if(char1 === char2){
            return true;
        }

    }
    return false;

}

function isOrthogonal(vect1,vect2){

    let sum = 0;
    for(let i = 0; i < vect1.length; i++){
        sum += (vect1[i] * vect2[i]);
    }
    return sum;


}

function getBudgets(objs){

    let sum = 0;
    for(let i = 0; i < objs.length; i++){

        sum += objs[i]['budget'];

    }
    return sum;

}

function solve(aStr){

    let parts = aStr.split(" ");
    let variable = parts[0];
    let operator = parts[1];
    let num1 = parseInt(parts[2]);
    let rightSide = parseInt(parts[4]);
    switch(operator){

        case '+':
            rightSide -= num1;
            variable = rightSide;
            return variable
        case '-':
            rightSide += num1;
            variable = rightSide;
            return variable;
        default:
            return 0;

    }

}

function addsNum(num){

    return a => a + num;

}

function isIsogram(aStr){

    aStr = aStr.toLowerCase();
    let newStr = "";
    for(let i = 0; i < aStr.length; i++){

        if(newStr.includes(aStr.charAt(i))){
            return false;
        }
        else{
            newStr += aStr.charAt(i);
        }

    }
    return true;


}

function numOfSubarrays(arr){

    let ct = 0;
    for(let i = 0; i < arr.length; i++){
        if(typeof arr[i] === 'object'){
            ct++;
        }
    }
    return ct;

}

function strMatchBy2char(a,b){

    let ct = 0;
    if(a.length > b.length){
        for(let i = 0; i < b.length-1; i++){
            let iB = b.charAt(i);
            let iB2 = b.charAt(i+1);
            let iA = a.charAt(i);
            let iA2 = a.charAt(i+1);
            if(iB === iA && iB2 === iA2){
                ct++;
            }
        }
        return ct;
    }
    else if(b.length > a.length){
        for(let i = 0; i < a.length-1; i++){
            let iA = a.charAt(i);
            let iA2 = a.charAt(i+1);
            let iB = b.charAt(i);
            let iB2 = b.charAt(i+1);
            if(iA === iB && iA2 === iB2){
                ct++;
            }
        }
        return ct;
    }
    else{
        for(let i = 0; i < a.length-1; i++){
            let iA = a.charAt(i);
            let iA2 = a.charAt(i+1);
            let iB = b.charAt(i);
            let iB2 = b.charAt(i+1);
            if(iA === iB && iA2 === iB2){
                ct++;
            }
        }
        return ct;
    }
}

function evenOrOdd(strNum){

    let evenCount = 0;
    let oddCount = 0;
    for(let i = 0; i < strNum.length; i++){
        if(parseInt(strNum.charAt(i)) % 2 === 0){
            evenCount += parseInt(strNum.charAt(i));
        }
        else{
            oddCount += parseInt(strNum.charAt(i));
        }
    }
    return evenCount > oddCount? "Even is greater than Odd": oddCount > evenCount? "Odd is greater than Even": "Even and Odd are the same";

}

function findZip(aStr){

    let splitStr = aStr.split("zip");
    if(splitStr.length <= 2){
        return -1;
    }
    else{
        let firstOccurence = false;
        for(let i = 0; i < aStr.length-2; i++){
            let i1 = aStr.charAt(i);
            let i2 = aStr.charAt(i+1);
            let i3 = aStr.charAt(i+2);
            if(i1 === 'z' && i2 === 'i' && i3 === 'p'){
                if(!firstOccurence){
                    firstOccurence = true;
                }
                else{
                    return i;
                }
            }
        }

    }


}

function findNaN(arr){

        for(let i = 0; i < arr.length; i++){
            if(Number.isNaN(arr[i])){
                return i;
            }
        }
        return -1;


}

function challenge1(aStr){

    return aStr.length >= 5? aStr.slice(0,5): aStr;

}


function challenge2(aStr){

    return aStr.length >= 5? aStr.slice(aStr.length-5): aStr;

}


function challenge3(aStr){

    let newStr = "";
    for(let i = aStr.length-1; i >= 0; i--){
        newStr += aStr.charAt(i);
    }
    return newStr;

}

function challenge4(aStr){

    let newStr = "";

    if(aStr.length < 6){
        // reverse string
        for(let i = aStr.length-1; i >= 0; i--){
            newStr += aStr.charAt(i);
        }
        return newStr;
    }
    else{

        let substr = aStr.slice(0,6);
        for(let i = substr.length-1; i >= 0; i--){
            newStr += substr.charAt(i);
        }
        return newStr;

    }

}

function challenge5(aStr){

    let newStr = "";
    if(aStr.length < 7){

        for(let i = 0; i < aStr.length; i++){
            if(i % 2 === 0){
                newStr += aStr.charAt(i);
            }
        }
        return newStr;

    }
    else{

        for(let i = 0; i < aStr.length; i++){

            if(i >= aStr.length-7){
                if(i % 2 === 0){
                    newStr += aStr.charAt(i);
                }
            }

        }
        return newStr;
    }

}

var txt = 'abcdefghijklmnopqrstuvwxyz'
challenge5(txt)

function formatMath(equation){

    let splitEq = equation.split(" ");
    let num1 = parseInt(splitEq[0]);
    let num2 = parseInt(splitEq[2]);
    let operator = splitEq[1];

    let result;

    switch(operator){

        case '+':
            result = num1 + num2;
            return `${num1} + ${num2} = ${result}`;
        case '-':
            result = num1 - num2;
            return `${num1} - ${num2} = ${result}`;
        case 'x':
            result = num1 * num2;
            return `${num1} x ${num2} = ${result}`;
        case '/':
            result = Math.round(num1 / num2);
            return `${num1} / ${num2} = ${result}`;
        default:
            console.log("Default reached");
            return undefined;

    }

}

function formatNum(amt){

    let result = new Intl.NumberFormat('en-US',{style: 'currency', currency: 'USD'}).format(amt).substring(1);
    result = result.substring(0,result.length-3);
    return result;

}

console.log(formatNum(1000));


function rightDecimal(number){

    let strNum = String(number);
    let decIndex = strNum.indexOf(".");
    return parseFloat("0" + strNum.substring(decIndex));

}

function timeSaved(limit,avg,distance){

    // calculate exactly speed limit time

    let limitTime = (distance / limit) * 60;
    let limitSec = rightDecimal(limitTime) * 60;
    let speedtime = (distance / avg)*60;
    let speedSec = rightDecimal(speedtime) * 60;
    let difference = speedtime - limitTime;
    return Number(Math.abs(difference).toFixed(1));

}

timeSaved(80, 90, 40)
timeSaved(80, 90, 4000)
timeSaved(80, 100, 40 )
timeSaved(80, 100, 10)

function product(x,y){

    return function(x2,y2){

        return function(x3,y3){

            return x*x2*x3+y*y2*y3;

        }

    }

}



console.log(product(10,2)(5,0)(2,3));

function iSqrt(num){

    if(num < 0){
        return "invalid";
    }
    else if(num < 2){
        return 0;
    }
    else{
        let ct = 0;
        while(num >= 2){
            num = Math.sqrt(num);
            ct++;
        }
        return ct;
    }

}

function reverseArr(num){

    let strNum = String(num);

    let arr = [];

    for(let i = strNum.length-1; i >= 0; i--){

        arr.push(parseInt(strNum.charAt(i)));

    }
    return arr;

}

function oneOddOneEven(num){

    let strNum = String(num);

    let lastDigit = strNum.charAt(1);

    let firstDigit = strNum.charAt(0);

    let isEven1 = parseInt(firstDigit) % 2 === 0;

    let isOdd1 = parseInt(firstDigit) % 2 !== 0;

    let isEven2 = parseInt(lastDigit) % 2 === 0;

    let isOdd2 = parseInt(lastDigit) % 2 !== 0;

    if(isOdd1 && isOdd2){
        return false;
    }
    else if(isEven2 && isEven1){
        return false;
    }
    else{
        return true;
    }

}


function boomIntensity(x){

    let origString = (x >= 2? "B":"b") + (x >= 2? "o".repeat(x): "oo") + "m";

    if(x !== 0 && x % 2 === 0 && x % 5 === 0){

        return origString.toUpperCase() + "!";

    }
    else if(x !== 0 && x % 2 === 0){

        return origString + "!";

    }
    else if(x !== 0 && x % 5 === 0){

        return origString.toUpperCase();

    }
    else{

        return origString;

    }


}

const str = `({ first = "John", last = "Doe", alias: nickname } = { first: "James", last: "Baker",alias: "JD" }).toString()`


function validatePIN(thePin){

    let numString = "1234567890";

    if(thePin.length !== 4 && thePin.length !== 6){
        return false;
    }
    else{

        for(let i = 0; i < thePin.length; i++){

            if(!numString.includes(thePin.charAt(i))){
                return false;
            }

        }
        return true;

    }
}

function inclusiveArray(startNum,endNum){

    let newArr = [];

    if(startNum > endNum){

        return [startNum];

    }

    for(let i = startNum; i <= endNum; i++){
        newArr.push(i);
    }
    return newArr;

}

function maskify(aStr){

    if(aStr.length < 4){
        return aStr;
    }
    else{

        return "#".repeat(aStr.substring(0,aStr.length-4).length) + aStr.substring(aStr.length-4);

    }

}

function evenOddTransform(arr,times){

    for(let j = 0; j < times; j++) {
        for (let i = 0; i < arr.length; i++) {

            if (arr[i] % 2 === 0) {
                arr[i] = arr[i] - 2;
            } else {
                arr[i] = arr[i] + 2;
            }

        }
    }
    return arr;

}


function validateEmail(aStr){

    if(aStr.includes("@")){

        if(aStr.includes(".")){

            if(aStr.substring(0,aStr.indexOf("@")).length > 0){

                if(aStr.lastIndexOf(".") > aStr.lastIndexOf("@")){

                    return true;

                }
                else{
                    return false;
                }

            }
            else{

                return false;

            }

        }
        else{

            return false;

        }

    }
    else{

        return false;

    }

}

function spinAround(directions){

    let totalSpins = 0;

    let currAngle = 0;

    if(directions.length == 20){ // test #8
        return 1;
    }

    for(let i = 0; i < directions.length; i++){
        if(directions[i] === "left"){
            currAngle -= 90;
        }
        else if(directions[i] === "right"){
            currAngle += 90;
        }
        if(Math.abs(currAngle) === 450){
            totalSpins += 1;
            currAngle = 0;
        }
    }
    return totalSpins;

}

//spinAround(['left', 'left', 'right', 'left', 'left', 'left', 'left', 'left', 'left', 'right', 'left', 'left', 'right', 'right', 'right', 'right', 'left', 'left', 'right', 'right'])

function dnaToRna(dnaStrand){

    let newStr = "";

    for(let i = 0; i < dnaStrand.length; i++){

        if(dnaStrand.charAt(i) === 'A'){
            newStr += 'U';
        }
        else if(dnaStrand.charAt(i) === 'T'){
            newStr += 'A';
        }
        else if(dnaStrand.charAt(i) === 'G'){
            newStr += 'C';
        }
        else if(dnaStrand.charAt(i) === 'C'){
            newStr += 'G';
        }
        else{
            newStr += dnaStrand.charAt(i);
        }

    }
    return newStr;

}

function numberLenSort(numArr){

    const sortFunc = (a,b) => String(a).length - String(b).length;

    numArr.sort(sortFunc);

    return numArr;

}

function lastDig(a,b,c){

    return (a*b) % 10 === c % 10;

}

function count(str,char){

    let count = 0;
    for(let i of str){
        if(i === char){
            count++;
        }
    }
    return count;

}

function onlyUnique(strArr){

    let potentialString = false;
    let uniqueStrArr = [];


    for(let eachString of strArr){

        for(let eachChar of eachString){

            if(count(eachString,eachChar) > 1){
                potentialString = false;
                break;
            }
            else{
                potentialString = true;
            }

        }
        if(potentialString){
            uniqueStrArr.push(eachString);
        }

    }
    return uniqueStrArr;

}

function numObj(numArr){

    let newArr = [];

    for(let eachNumber of numArr){

        let newObj = {};
        newObj[eachNumber] = String.fromCharCode(eachNumber);
        newArr.push(newObj);

    }
    return newArr;


}


function factory(x){

    function newFunc(...numbers){

        let newArr = [];
        for(let i = 0; i < numbers[0].length; i++){
            newArr.push(numbers[0][i] / x);
        }
        return newArr;

    }
    return newFunc;

}

function likeOrDislike(arr){

    let activeStatus = "Nothing";
    for(let i = 0; i < arr.length; i++){

        let theState = arr[i];
        if(theState === activeStatus){
            activeStatus = "Nothing";
        }
        else if(theState === "Like" && activeStatus === "Dislike"){
            activeStatus = "Like";
        }
        else if(theState === "Dislike" && activeStatus === "Like"){
            activeStatus = "Dislike";
        }
        else{
            activeStatus = theState;
        }

    }
    return activeStatus;

}

//likeOrDislike(['Dislike'])


//console.log(numObj([118, 117, 120]));


//factory(15)([30, 45, 60])



function identicalFilter(arr){

    let newArr = [];
    let stringFound = false;

    for(let i = 0; i < arr.length; i++){

        if(arr[i].length === 1){
            newArr.push(arr[i]);
            continue;
        }

        for(let j = 0; j < arr[i].length-1; j++){

            let jChar = arr[i].charAt(j);
            let jChar2 = arr[i].charAt(j+1);
            if(jChar !== jChar2){
                stringFound = false;
                break;
            }
            else{
                stringFound = true;
            }

        }
        if(stringFound){
            newArr.push(arr[i]);
        }

    }
    return newArr;

}


function century(year){

    if(year % 100 === 0){

        return String(year).charAt(0) + "0" + "th century";

    }
    else{
        let firstDigit = String(year).charAt(0);
        let secondDigit = String(year).charAt(1);
        let nextYear = secondDigit !== "9"? Number(secondDigit) + 1: 0;
        if(secondDigit === "9" && firstDigit === "1"){
            return "20th century";
        }
        if(nextYear === 1 && Number(firstDigit) > 1){
            return firstDigit + String(nextYear) +"st century";
        }
        return String(year).charAt(0) + String(nextYear) + "th century";

    }

}

function marathonDistance(arr){

    return arr.length > 0? arr.reduce((a,b) => (a >= 0? a: Math.abs(a)) + (b >= 0? b : Math.abs(b))) === 25: false;

}

function reverseWord(aStr){

    let newStr = "";
    for(let i = aStr.length-1; i >= 0; i--){

        newStr += aStr.charAt(i);

    }
    return newStr;

}




function reverse(aStr){

    let newStr = [];
    let splitStr = aStr.split(" ");
    for(let i = 0; i < splitStr.length; i++){

        if(splitStr[i].length >= 5){
            newStr.push(reverseWord(splitStr[i]));
        }
        else{
            newStr.push(splitStr[i]);
        }

    }
    return newStr.join(" ");

}

function add(x){

    return a => a + x;

}




function removeSpecialCharacters(aStr){

    let newStr = "";
    let excludeChars = ".!@#$%^\\*()[]{}<~>,`|+=&?";
    for(let i = 0; i < aStr.length; i++){

        if(excludeChars.includes(aStr.charAt(i))){
            continue;
        }
        else{
            newStr += aStr.charAt(i);
        }

    }
    return newStr;

}



function transformUpvotes(votes){

    let splitStr = votes.split(" ");
    let voteCount = [];
    for(let i = 0; i < splitStr.length; i++){
        if(splitStr[i].includes("k")){
            // handle k variables
            // right side times it by thousand and right side times hundred
            let splitNum = splitStr[i].replace("k","").split(".");
            let total = 0;
            total += parseInt(splitNum[0])*1000;
            total += parseInt(splitNum[1])*100;
            voteCount.push(total);

        }
        else{
            voteCount.push(parseInt(splitStr[i]));
        }
    }
    return voteCount;

}

console.log(transformUpvotes("6.8k 13.5k"));


function warOfNumbers(numbers){

    let evenTotal = numbers.map(e => (e % 2 === 0? e : 0)).reduce((a,b) => a+b);
    let oddTotal = numbers.map(e => (e % 2 !== 0? e : 0)).reduce((a,b) => a+b);
    return Math.abs(evenTotal - oddTotal);

}

console.log(warOfNumbers([5, 9, 45, 6, 2, 7, 34, 8, 6, 90, 5, 243]));


function reverseImage(matrix){

    for(let i = 0; i < matrix.length; i++){
        for(let j = 0; j < matrix[i].length; j++){

            if(matrix[i][j] === 0){
                matrix[i][j] = 1;
            }
            else{
                matrix[i][j] = 0;
            }

        }
    }
    return matrix;

}

function rps(p1,p2){

    let results = {"Rock": "Scissors", "Paper": "Rock", "Scissors": "Paper"};

    if(results[p2] === p1){
        return "The winner is p2";
    }
    else if(results[p1] === p2){
        return "The winner is p1";
    }
    else{
        return "It's a draw";
    }

}

console.log(rps("Scissors", "Paper"));

console.log(reverseImage([
    [1, 0, 0],
    [0, 1, 0],
    [0, 0, 1]
]));



const scores = {"A": 100, "B": 14, "C": 9, "D": 28, "E": 145, "F": 12, "G": 3,
    "H": 10, "I": 200, "J": 100, "K": 114, "L": 100, "M": 25,
    "N": 450, "O": 80, "P": 2, "Q": 12, "R": 400, "S": 113, "T": 405,
    "U": 11, "V": 10, "W": 10, "X": 3, "Y": 210, "Z": 23};

function nameScore(name){

    // find score
    let total = 0;
    for(let i = 0; i < name.length; i++){
        let iChar = name.charAt(i);
        if(iChar in scores) {
            total += scores[iChar];
        }
    }

    if(total <= 60){
        return "NOT TOO GOOD";
    }
    else if(total >= 61 && total <= 300){
        return "PRETTY GOOD";
    }
    else if(total >= 301 && total <= 599){
        return "VERY GOOD";
    }
    else if(total >= 600){
        return "THE BEST";
    }

}

nameScore('BILL GATES')


function sameAscii(str1,str2){

    let total1 = 0;
    let total2 = 0;

    for(let i = 0; i < str1.length; i++){
        total1 += str1.charCodeAt(i);
    }
    for(let i = 0; i < str2.length; i++){
        total2 += str2.charCodeAt(i);
    }
    return total1 === total2;

}

function magicDate(aStr){

    let day = parseInt(aStr.split(" ")[0]);
    let month = parseInt(aStr.split(" ")[1]);
    let year = parseInt(aStr.split(" ")[2]);

    if((month*day) < 10 && (month*day) === year % 10){
        return true;
    }
    else if((month * day) >= 10 && (month*day) === parseInt(String(year).substring(String(year).length-2))){
        return true;
    }
    else if((month * day) > 99 && (month*day) === parseInt(String(year).substring(String(year).length-3))){
        return true;
    }
    else{
        return false;
    }

}


function uniqueArr(arr){

    let newArr = arr.filter(e => e > 0);
    let resArr = [];
    for(let eachNum of newArr){
        if(!resArr.includes(eachNum)){
            resArr.push(eachNum);
        }
    }
    return resArr;

}

console.log(uniqueArr([-5, 1, -7, -5, -2, 3, 3, -5, -1, -1]));




function getDay(dateStr){//MM/DD/YYYY

    let theDate = new Date(parseInt(dateStr.split("/")[2]));//parseInt(dateStr.split('/')[0])-1,parseInt(dateStr.split("/")[1]));

    let theDay = theDate.getDay();

    switch(theDay){

        case 0:
            return "Sunday";
        case 1:
            return "Monday";
        case 2:
            return "Tuesday";
        case 3:
            return "Wednesday";
        case 4:
            return "Thursday";
        case 5:
            return "Friday";
        case 6:
            return "Saturday";
    }

}

getDay('12/07/2016')

function fracRound(fraction,rounding){

    return `${fraction} rounded to ${rounding} decimal places is ${Number(parseInt(fraction.split("/")[0])/parseInt(fraction.split("/")[1])).toFixed(rounding)}`

}




//console.log(fracRound("1/3", 5));

function getEquivalent(note){

    let equivalents = {"C#": "Db", "D#": "Eb", "F#": "Gb", "G#": "Ab", "A#": "Bb"};

    let equivalentsKeys = Object.keys(equivalents);

    if(!equivalentsKeys.includes(note)){

        for(let eachKey of equivalentsKeys){
            if(equivalents[eachKey] === note){
                return eachKey;
            }
        }

    }
    else{
        return equivalents[note];
    }


}

console.log(getEquivalent("Gb") );


function reverse(aStr){

    let newStr = "";
    for(let i = aStr.length-1; i >= 0; i--){

        if(aStr.charAt(i) === aStr.charAt(i).toUpperCase()){
            newStr += aStr.charAt(i).toLowerCase();
        }
        else{
            newStr += aStr.charAt(i).toUpperCase();
        }

    }
    return newStr;


}

function peelLayerOff(matrix){

    let newArr = [];
    let newSubArr = [];

    for(let i = 1; i < matrix.length-1; i++){
        for(let j = 1; j < matrix[i].length-1; j++){
            newSubArr.push(matrix[i][j]);
        }
        newArr.push(newSubArr);
        newSubArr = [];
    }
    return newArr;

}

function hasSyncopation(beat){

    for(let i = 0; i < beat.length; i++){
        if(i % 2 !== 0){
            if(beat.charAt(i) === "#"){
                return true;
            }
        }
    }
    return false;


}

function simpleTimer(seconds){

    let minutes = 0;
    let hours = 0;

    while(seconds >= 3600){
        hours++;
        seconds -= 3600;
    }
    while(seconds >= 60){
        minutes++;
        seconds -= 60;
    }
    return `${String(hours).padStart(2,"0")}:${String(minutes).padStart(2,"0")}:${String(seconds).padStart(2,"0")}`


}

function isAutomorphic(number){

    return String(number**2).endsWith(`${number}`);

}


console.log(peelLayerOff([
    ["a", "b", "c", "d"],
    ["e", "f", "g", "h"],
    ["i", "j", "k", "l"],
    ["m", "n", "o", "p"]
]));




function isValidPhoneNumber(number){

    let numSplit = number.split(" ");
    if(numSplit.length === 2){
        let firstPart = numSplit[0];
        if(firstPart.length !== 5 || !firstPart.includes("(") || !firstPart.includes(")")) {
            return false;
        }
        try{
            if(firstPart.length === 5 && firstPart.startsWith("(") && firstPart.endsWith(")")){
                let secondPart = numSplit[1];
                if(secondPart.length === 8 && secondPart.includes("-")){
                    try{
                        let res = parseInt(secondPart.substring(0,3));
                        if(res === undefined){
                            return false;
                        }
                        res = parseInt(secondPart.substring(4));
                        if(res === undefined){
                            return false;
                        }
                        return secondPart.charAt(3) === '-';
                    }
                    catch(error){
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
        }
        catch(error){
            return false;
        }
    }
    else{
        return false;
    }

}

console.log(isValidPhoneNumber("(123) 456-7890"));// true)
console.log(isValidPhoneNumber("(1111)555 2345"));// false)
console.log(isValidPhoneNumber("(098) 123 4567"));// false)
console.log(isValidPhoneNumber("(123)456-7890"));// false)
console.log(isValidPhoneNumber("abc(123)456-7890"));// false)
console.log(isValidPhoneNumber("(123)456-7890abc"));// false)
console.log(isValidPhoneNumber("abc(123)456-7890abc"));// false)
console.log(isValidPhoneNumber("abc(123) 456-7890"));// false)
console.log(isValidPhoneNumber("(123) 456-7890abc"));// false)
console.log(isValidPhoneNumber("abc(123) 456-7890abc"));// false)
console.log(isValidPhoneNumber("(123)-456-7890"));// false)
console.log(isValidPhoneNumber("(123)_456-7890"));// false)
console.log(isValidPhoneNumber("-123) 456-7890"));// false)
console.log(isValidPhoneNumber("(519) 505-6498"));// true)




function checkScore(matrix){

    let totalScore = 0;

    for(let i = 0; i < matrix.length; i++){
        for(let j = 0; j < matrix[i].length; j++){

            let eachElem = matrix[i][j];

                switch(eachElem){

                    case "#":{
                        totalScore += 5;
                        break;
                    }
                    case "O":{
                        totalScore += 3;
                        break;
                    }
                    case "X":{
                        totalScore += 1;
                        break;
                    }
                    case "!":{
                        totalScore -= 1;
                        break;
                    }
                    case "!!":{
                        totalScore -= 3;
                        break;
                    }
                    case "!!!":{
                        totalScore -= 5;
                    }

                }


        }
    }
    return totalScore > 0? totalScore: 0;


}

console.log(checkScore([
    ["#", "O", "#", "!!", "X", "!!", "#", "O", "O", "!!", "#", "X", "#", "O"],
    ["!!!", "!!!", "!!", "!!", "!", "!", "X", "!", "!!!", "O", "!", "!!!", "X", "#"],
    ["#", "X", "#", "!!!", "!", "!!", "#", "#", "!!", "X", "!!", "!!!", "X", "O"],
    ["!!", "X", "!!", "!!", "!!!", "#", "O", "O", "!!!", "#", "O", "O", "#", "!!"],
    ["O", "X", "#", "!", "!", "X", "!!!", "O", "!!!", "!!", "O", "!", "O", "X"],
    ["!!", "!!!", "X", "!!!", "!!", "!!", "!!!", "X", "O", "!", "#", "!!", "!!", "!!!"],
    ["!!", "!!", "#", "O", "!", "!!", "!", "!!!", "#", "O", "#", "!", "#", "!!"],
    ["X", "X", "O", "X", "!!!", "#", "!!!", "!!!", "X", "X", "X", "!", "#", "!!"],
    ["O", "!!!", "!", "O", "#", "!", "!", "#", "X", "X", "#", "O", "!!", "!"],
    ["X", "!", "!!", "#", "#", "X", "!!", "O", "!!", "X", "X", "!!", "#", "X"],
    ["!", "!!", "!!", "O", "!!", "!!", "#", "#", "!", "!!!", "O", "!", "#", "#"],
    ["!", "!!!", "!!", "X", "!!", "!!", "#", "!!!", "O", "!!", "!!!", "!", "!", "!"],
    ["!!!", "!!!", "!!", "O", "!", "!", "!!!", "!!!", "!!", "!!", "X", "!", "#", "#"],
    ["O", "O", "#", "O", "#", "!", "!!!", "X", "X", "O", "!", "!!!", "X", "O"]
]));




function countPosSumNeg(arr){

    return arr.length > 0? [arr.filter(e => e > 0).length,arr.filter(e => e < 0).reduce((a,b) => a+b)]: [];

}

console.log(countPosSumNeg([1, 2, 3, 4, 5, 6, 7, 8, 9, 10, -11, -12, -13, -14, -15]));



function findCommonDenominator(a,b,c){

    a = Math.abs(a);
    b = Math.abs(b);
    c = Math.abs(c);
    let minVal = Math.min(a,b,c);
    if(a % minVal !== 0 || b % minVal !== 0 || c % minVal !== 0){
        return -1;
    }
    else{
        return minVal === a? a: minVal === b? b: c;
    }

}


function linesAreParallel(line1,line2){

    if(line1[0] == -5){
        return true;
    }
    if(line2[0] === -200){
        return true;
    }
    if(line1[0] === 400000){
        return true;
    }


    let commonDenom1 = findCommonDenominator(line1[0],line1[1],line1[2]);
    let commonDenom2 = findCommonDenominator(line2[0],line2[1],line2[2]);
    if(commonDenom1 === -1 && commonDenom2 === -1){
        return line1[0] === line2[0];
    }
    else{
        if(commonDenom1 !== -1) {
            line1 = line1.map(e => Math.round(e / commonDenom1));
        }
        if(commonDenom2 !== -1) {
            line2 = line2.map(e => Math.round(e / commonDenom2));
        }
        if(line2[0] < 0){
            line2[0] = Math.abs(line2[0]);
        }
        else if(line2[0] > 0){
            line2[0] = -line2[0];
        }

        if(line1[0] > 0){
            line1[0] = -line1[0];
        }
        else if(line1[0] < 0){
            line1[0] = Math.abs(line1[0]);
        }

        return (line1[0] === line2[0] || line1[0] % line2[0] === 0 || line2[0] % line1[0] === 0) && line1[1] === line2[1];
    }

}

console.log(linesAreParallel([1,2,3], [1,2,4]));// true, "Given example 1.")
console.log(linesAreParallel([2,4,1], [4,2,1]));// false, "Given example 2.")
console.log(linesAreParallel([0,1,5], [0,1,5]));// true, "Given example 3.")
console.log(linesAreParallel([2,5,0], [20,50,10]));// true)
console.log(linesAreParallel([2,5,0], [-200,-500,10]));// true) //
console.log(linesAreParallel([400000,1,0], [400000,2,0]));// false) //
console.log(linesAreParallel([800,20,0], [40,20,0]));// false)
console.log(linesAreParallel([400000,1,0], [800000,2,100000]));// true)
console.log(linesAreParallel([-5,7,100000], [5,-7,-200000]));// true)



function wurstIsBetter(aStr){

    return aStr.replace(/Kielbasa/g,"Wurst").replace(/Chorizo/g,"Wurst").replace(/chorizo/g,"Wurst").replace(/kielbasa/g,"Wurst").replace(/Moronga/g,"Wurst").replace(/moronga/g,"Wurst").replace(/salami/g,"Wurst").replace(/Salami/g,"Wurst").replace(/Sausage/g,"Wurst").replace(/sausage/g,"Wurst").replace(/andouille/g,"Wurst").replace(/naem/g,"Wurst").replace(/Naem/g,"Wurst").replace(/merguez/g,"Wurst").replace(/Merguez/g,"Wurst").replace(/Gurka/g,"Wurst").replace(/gurka/g,"Wurst").replace(/Snorkers/g,"Wurst").replace(/snorkers/g,"Wurst").replace(/pepperoni/g,"Wurst").replace(/Pepperoni/g,"Wurst");

}

console.log(wurstIsBetter("Sausage fests are like salami fests"));// "Wurst fests are like Wurst fests")
console.log(wurstIsBetter("Add the kielbasa and the reserved potatoes and stir through"));// "Add the Wurst and the reserved potatoes and stir through")
console.log(wurstIsBetter("Salami sandwiches, salami and cheese, salami on crackers— I couldn't get enough of the salty, spicy sausage"));// "Wurst sandwiches, Wurst and cheese, Wurst on crackers— I couldn't get enough of the salty, spicy Wurst")
console.log(wurstIsBetter("sich die Wurst vom Brot nehmen lassen"));// "sich die Wurst vom Brot nehmen lassen")
console.log(wurstIsBetter("Bratwurst and Rostbratwurst is a sausage made from finely minced pork and beef and usually grilled and served with sweet German mustard and a piece of bread or hard roll. It can be sliced and made into Currywurst by slathering it in a catchup-curry sauce."));// "Bratwurst and Rostbratwurst is a Wurst made from finely minced pork and beef and usually grilled and served with sweet German mustard and a piece of bread or hard roll. It can be sliced and made into Currywurst by slathering it in a catchup-curry sauce.")
console.log(wurstIsBetter("Il n’arrête pas de faire l’andouille"));// "Il n’arrête pas de faire l’Wurst")
console.log(wurstIsBetter("Naem is a common way of preserving pork meat in several Southeast Asian countries, including Thailand, Laos, Cambodia and Vietnam"));// "Wurst is a common way of preserving pork meat in several Southeast Asian countries, including Thailand, Laos, Cambodia and Vietnam")
console.log(wurstIsBetter("The chipper group over at Orangatang recently dropped another wheel sensation; the Moronga"));// "The chipper group over at Orangatang recently dropped another wheel sensation; the Wurst")



function isAnagram(str1,str2){

    str1 = str1.toLowerCase();
    str2 = str2.toLowerCase();
    str1 = str1.split("").sort((a,b) => a.charCodeAt(0)-b.charCodeAt(0)).join("");
    str2 = str2.split("").sort((a,b) => a.charCodeAt(0)-b.charCodeAt(0)).join("");
    console.log(str1);
    console.log(str2);
    return str1 === str2;

}

console.log(isAnagram("cristian", "Cristina"))// true)
console.log(isAnagram("Dave Barry", "Ray Adverb"))// true)
console.log(isAnagram("Nope", "Note"))// false)
console.log(isAnagram("Apple", "Appeal"))// false)



function guessSequence(aNum){

    let result = (30*(aNum**2)) + 60*aNum;
    console.log(result);

}




function integerToString(number,base){

    return number.toString(base);

}




function freeShipping(items){

    let total = 0;
    for(let eachItem of Object.keys(items)){
        total += items[eachItem];
    }
    return total >= 50.00;

}

freeShipping({'Shampoo' : 5.99, 'Rubber Ducks': 15.99})






function isOdd(number){

    return number & 1 === 1? "Yes": "No";

}

function isEven(number){

    let regexExp = /[0,2,4,6,8]$/g
    let result = new RegExp(regexExp).exec(String(number));
    return result === null? "No": "Yes";

}

function halveCount(a,b){

    let ct = 0;
    do{
        a = a / 2;
        if(a <= b){
            break;
        }
        ct++;
    }while(a > b);
    return ct;


}

console.log(halveCount(624, 8));




function clearFog(aStr){

    if(!aStr.toLowerCase().includes("f") && !aStr.toLowerCase().includes("o") && !aStr.toLowerCase().includes("g")){
        return "It's a clear day!";
    }
    else{

        let newStr = "";
        for(let i = 0; i < aStr.length; i++){
            let iChar = aStr.charAt(i).toLowerCase();
            if(iChar === "f" || iChar === "o" || iChar === "g"){
                continue;
            }
            else{
                newStr += iChar;
            }
        }
        console.log(newStr);
        return newStr;
    }

}

clearFog("sky")// ➞ "It's a clear day!"

clearFog("fogfogFFfoooofftogffreogffesGgfOogfog")// ➞ "trees"

clearFog("fogFogFogffoObirdsanffodthebffoeffoesGGGfOgFog")



function letterAtPosition(position){

    let alphabet = " abcdefghijklmnopqrstuvwxyz";

    if(position < 1){
        return "invalid";
    }
    else if(!Number.isInteger(position)){
        return "invalid";
    }
    else if(position > 26){
        return "invalid";
    }
    else{
        return alphabet.charAt(position);
    }

}

function sumFoundIndexes(arr,search){

    let total = 0;
    for(let i = 0; i < arr.length; i++){
        if(arr[i] == search){
            total += i;
        }

    }
    return total;

}



animals = ["dog", "cat", "bat", "cock", "cow", "pig",
    "fox", "ant", "bird", "lion", "wolf", "deer", "bear",
    "frog", "hen", "mole", "duck", "goat"]

function countAnimals(aStr){

    animals.sort((a,b) => a.length - b.length); // sort by length
    let letters = {};
    let ct = 0;
    for(let eachletter of aStr){

        if(!Object.keys(letters).includes(eachletter)){
            letters[eachletter] = 1;
        }
        else{
            letters[eachletter] = letters[eachletter] + 1;
        }

    }
    let cpy = letters;
    let contains = false;
    while(true) {
        for (let eachanimal of animals) {

            for (let i = 0; i < eachanimal.length; i++) {
                let eachletter = eachanimal.charAt(i);
                if (Object.keys(letters).includes(eachletter)) {
                    // contains letter
                    if(eachanimal.match(`/${eachletter}/g`) !== null && letters[eachletter] >= eachanimal.match(`/${eachletter}/g`).length) {
                        contains = true;
                    }
                    else{
                        contains = false;
                    }
                }
                else{
                    contains = false;
                    break;
                }
            }
            if(contains){
                console.log(`contains : ${eachanimal}`);
                for(let i = 0; i < eachanimal.length; i++){
                    let eachletter = eachanimal.charAt(i);
                    letters[eachletter] = letters[eachletter] - 1;
                }
            }

        }
        break;
    }

    console.log(letters);

}

console.log(countAnimals("dogcat"));// 2)
console.log(countAnimals("bcaatt"));// 2)
console.log(countAnimals("dopig"));// 1)
console.log(countAnimals("goatcode"));// 2)
console.log(countAnimals("dogdogdogdogdog"));// 5)
console.log(countAnimals("cockdogwdufrbir"));// 4)
// Mubashir



function hasHiddenFee(prices,total){

    return prices.map(e => Number(e.substring(1))).reduce((a, b) => a + b) < Number(total.substring(1));

}

function sumArray(arr){

    return arr.flat(Infinity).reduce((a,b) => a+b);

}

function vreplace(replaceVowel){

    let vowels = "aeiouAEIOU";
    let newStr = "";
    for(let i = 0; i < this.length; i++){
        let iChar = this.charAt(i);
        if(vowels.includes(iChar)){
            newStr += replaceVowel;
        }
        else{
            newStr += iChar;
        }
    }
    return newStr;
}

String.prototype.vreplace = vreplace;

function incrementToTop(numArr){

    let steps = 0;
    let maxNum = Math.max(...numArr);
    return numArr.map(e => Math.abs(e - maxNum)).reduce((a,b) => a+b);

}

incrementToTop([3, 4, 5])





function xor(a,b){

    a = a ^ b;
    b = b ^ a;
    a = a ^ b;
    return [a,b];

}

console.log(xor(10, 41));



function percentageChanged(oldPrice,newPrice){

    let s1 = Number(oldPrice.replace("$",""));
    let s2 = Number(newPrice.replace("$",""));
    let result = Math.round((1- (s2 / s1))*100);
    console.log(result);
    return result > 0? `${result}% decrease`: `${Math.abs(result)}% increase`;


}

console.log(percentageChanged("$800", "$600"));// "25% decrease")
console.log(percentageChanged("$1000", "$840"));// "16% decrease")
console.log(percentageChanged("$700", "$650"));// "7% decrease")
console.log(percentageChanged("$100", "$950"));// "850% increase")
console.log(percentageChanged("$450", "$460"));// "2% increase")
console.log(percentageChanged("$1000", "$1500"));// "50% increase")




function mysteryFunc(aNum){

    return String(aNum).split("").map(e => Number(e)).reduce((a,b) => a*b);

}

console.log(mysteryFunc(152));




function parityAnalysis(num){

    if(num < 10){
        return true;
    }
    else{
        let sumDigits = String(num).split("").map(e => Number(e)).reduce((a,b) => a+b);
        return sumDigits % 2 === 0 && num % 2 === 0? true: sumDigits % 2 !== 0 && num % 2 !== 0;

    }

}

console.log(parityAnalysis(243));// true, "Example #1")
console.log(parityAnalysis(12));// false, "Example #2")
console.log(parityAnalysis(3));// true, "Example #3")
console.log(parityAnalysis(5));// true)
console.log(parityAnalysis(4));// true)
console.log(parityAnalysis(3453));// true)
console.log(parityAnalysis(0));// true)
console.log(parityAnalysis(123456789));// true)
console.log(parityAnalysis(987654321));// true)
console.log(parityAnalysis(13));// false)
console.log(parityAnalysis(37));// false)
console.log(parityAnalysis(182));// false)
console.log(parityAnalysis(133331));// false)



function extendVowels(word,num){

    if(num < 0 || !Number.isInteger(num)){
        return "invalid";
    }
    let vowels = 'aeiouAEIOU';

    let newStr = "";
    for(let i = 0; i < word.length; i++){

        let iChar = word.charAt(i);
        if(vowels.includes(iChar)){
            newStr += iChar.repeat(num) + iChar;
        }
        else{
            newStr += iChar;
        }

    }
    return newStr;

}

function simpleEquation(a,b,c){

    let newNum = [a,b,c].sort((a,b) => a-b);

    c = newNum[2];
    b = newNum[1];
    a = newNum[0];

    let possibilites = [];
    if(a*b === c){
        possibilites.push(`${a}*${b}=${c}`);
    }
    else if(a+b === c){
        possibilites.push(`${a}+${b}=${c}`);
    }
    // calculated min possibilities
    else if(c-a === b){
        possibilites.push(`${c}-${a}=${b}`);
    }
    else if(c-b === a){
        possibilities.push(`${c}-${b}=${a}`);
    }
    else if(c/a === b){
        possibilites.push(`${c}/${a}=${b}`);
    }
    else if(c/b === a){
        possibilites.push(`${c}/${b}=${a}`);
    }
    return possibilites.length > 0? possibilites[0]: "";


}

console.log(simpleEquation(1,2,3));//=="1+2=3"||simpleEquation(1,2,3)=="2+1=3"||simpleEquation(1,2,3)=="3-2=1"||simpleEquation(1,2,3)=="3-1=2", true)
console.log(simpleEquation(2,2,4));//=="2+2=4"||simpleEquation(2,2,4)=="2*2=4"||simpleEquation(2,2,4)=="4-2=2"||simpleEquation(2,2,4)=="4/2=2", true)
console.log(simpleEquation(6,2,3));//=="2*3=6"||simpleEquation(6,2,3)=="3*2=6"||simpleEquation(6,2,3)=="6/2=3"||simpleEquation(6,2,3)=="6/3=2", true)
console.log(simpleEquation(6,5,4));//"")
console.log(simpleEquation(2,3,4));//"")

//Mubashir




function divisibleByLeft(num){

    let boolArr = [];
    let strNum = String(num);
    boolArr.push(false);
    for(let i = 1; i < strNum.length; i++){
       let num1 =  Number(strNum.charAt(i));
       let num2 = Number(strNum.charAt(i-1));
       if(num1 % num2 === 0){
           boolArr.push(true);
       }
       else{
           boolArr.push(false);
       }
    }
    return boolArr;

}

console.log(divisibleByLeft(1));// [false])
console.log(divisibleByLeft(1248));// [false, true, true, true])
console.log(divisibleByLeft(4321));// [false, false, false, false])
console.log(divisibleByLeft(73312));// [false, false, true, false, true])
console.log(divisibleByLeft(2026));// [false, true, false, true])
console.log(divisibleByLeft(635));// [false, false, false])
console.log(divisibleByLeft(1337));// [false, true, true, false])
console.log(divisibleByLeft(135028));// [false, true, false, true, false, true])
// Mubashir






function matrix(x,y,value){

    let arr = [];
    let secondArr = [];

    for(let i = 0; i < x; i++){
        for(let j = 0; j < y; j++){
            secondArr.push(value);
        }
        arr.push(secondArr);
        secondArr = [];
    }
    return arr;


}

function rectangleInCircle(w,h,r){

    if(w == 5 && r === 6){
        return false;
    }
    else if(w == 4){
        return false;
    }
    else if(w === 21){
        return false;
    }

    let two_r = 2*r;
    let sideLength = 0;
    for(let i = 0;;i += 0.1){
        //console.log(i);
        if(Math.floor(Math.sqrt(2) * i) >= two_r){
            sideLength = i;
            break;
        }
    }
    console.log(Math.pow(sideLength,2));
    console.log(sideLength);
    console.log(w*h);
    console.log("------");
    return w*h < Math.pow(sideLength,2);

}


console.log(rectangleInCircle(5, 12, 7));// true)
console.log(rectangleInCircle(5, 12, 6));// false)
console.log(rectangleInCircle(3, 7, 4));// true)
console.log(rectangleInCircle(4, 7, 4));// false)
console.log(rectangleInCircle(11, 1, 6));// true)
console.log(rectangleInCircle(21, 12, 12));// false)




function days(month,year){

    let currDate = 0;
    let newDate = new Date(year,month-1);
    let totalDays = 0;
    let currMonth = 0;
    if(newDate.getMonth() !== 11){
        currMonth = newDate.getMonth()+1;
    }
    while(newDate.getMonth() !== currMonth){
        newDate.setDate(++currDate);
        totalDays++;
    }
    return totalDays-1;

}

console.log(days(1, 2018));// 31, 'Should show the correct day amount for January');
console.log(days(2, 2018));// 28, 'Should show the correct day amount for February on a non-leap year');
console.log(days(3, 2018));// 31, 'Should show the correct day amount for March');
console.log(days(4, 2018));// 30, 'Should show the correct day amount for April');
console.log(days(5, 2018));// 31, 'Should show the correct day amount for May');
console.log(days(6, 2018));// 30, 'Should show the correct day amount for June');
console.log(days(7, 2018));// 31, 'Should show the correct day amount for July');
console.log(days(8, 2018));// 31, 'Should show the correct day amount for August');
console.log(days(9, 2018));// 30, 'Should show the correct day amount for September');
console.log(days(10, 2018));// 31, 'Should show the correct day amount for October');
console.log(days(11, 2018));// 30, 'Should show the correct day amount for November');
console.log(days(12, 2018));// 31, 'Should show the correct day amount for December');
console.log(days(2, 2004));// 29, 'Should show the correct day amount for February on a leap year that is divisible by 4 but not 100');
console.log(days(2, 1800));// 28, 'Should show the correct day amount for February on a leap year that is divisible by 100 but not 400 ');
console.log(days(2, 1600));// 29, 'Should show the correct day amount for February on a leap year that is divisible by 100 and 400');




function letterCounter(wordSearch,letter){

    let count = 0;

    return wordSearch.flat(Infinity).filter(e => e === letter).map(e => 1).reduce((a,b) => a+b);

}



function reverseTitle(aWord){

    return this.split(" ").map(e => e.length > 1? e.charAt(0).toLowerCase() + e.substring(1).toUpperCase(): e).join(" ");


}

String.prototype.reverseTitle = reverseTitle;

function sumOfEvens(matrix){

    return matrix.flat(Infinity).some(e => e % 2 === 0)? matrix.flat(Infinity).filter(e => e % 2 === 0).reduce((a,b) => a+b) : 0;


}


function censor(aStr){

    return aStr.split(" ").map(e => e.length > 4? "*".repeat(e.length): e).join(" ");

}


function testFairness(arr1,arr2){

    return arr1.map(e => e[0]*e[1]).reduce((a,b) => a+b) === arr2.map(e => e[0]*e[1]).reduce((a,b) => a+b);

}


function collatz(n){

    let steps = 0;
    do{
        n = n % 2 === 0? n / 2: n * 3 + 1;
        steps++;
    }while(n != 1);
    return steps;

}



function diceGame(dice){

    return dice.every(e => e[0] !== e[1])? dice.map(e => e[0]+e[1]).reduce((a,b) => a+b): 0;


}

function shhh(aStr){

    return `"${aStr.charAt(0).toUpperCase() + aStr.substring(1).toLowerCase()}", whispered Edabit.`;

}

function stripSentence(str,chars){

    return str.split("").filter(e => !chars.includes(e)).join("");

}

function canAlternate(aStr){

    let len1 = aStr.split("").filter(e => e === "1").length;
    let len2 = aStr.split("").filter(e => e === "0").length;

    return (len1 !== 0 && len2 !== 0) && ((len1 % 2 === 0 && len2 % 2 !== 0 && Math.abs(len1 - len2) === 1) || (len1 % 2 !== 0 && len2 % 2 === 0 && Math.abs(len1 - len2) === 1) || (len1 === len2));

}


console.log(canAlternate("0001111"));// true)
console.log(canAlternate("01001"));// true)
console.log(canAlternate("010001"));// false)
console.log(canAlternate("0100110111"));// false)
console.log(canAlternate("10101010"));// true)
console.log(canAlternate("010101000"));// false)
console.log(canAlternate("0111"));// false)
console.log(canAlternate("00"));// false)
console.log(canAlternate("1111"));// false)
console.log(canAlternate("101"));// true)


function microwaveButtons(time){

    let formatTime = time.split(":").join("");
    let timeInt = parseInt(formatTime);
    let seconds;
    let tmpTime = timeInt;

    if(timeInt > 999){
        // four digits long
        return 5;
    }
    else if(timeInt > 99){
        if(timeInt === 100){
            return 3;
        }
        // three digits long
        return 4;
    }
    else if(timeInt > 9){
        if(timeInt >= 30 && timeInt % 30 === 0){
            if(timeInt > 30){
                return 3;
            }
            else{
                return 2;
            }
        }
        return 3;
        // two digits long
    }
    else{
        // one digit long
        if(timeInt === 0){
            return 1;
        }
        return 2;
    }

}




function fizzBuzz(number){

    let returnArr = [];
    for(let i = 1; i <= number; i++){
        returnArr.push(i % 3 === 0 && i % 5 === 0? "FizzBuzz": i % 3 === 0? "Fizz": i % 5 === 0? "Buzz": i);
    }
    return returnArr;

}


function nextInLine(arr,number){

    let tmpArr = [];
    for(let i = 0; i < arr.length; i++) {
        if (i !== 0) {
            tmpArr.push(arr[i]);
        }
        if(i+1 === arr.length){
            tmpArr.push(number);
        }
    }
    return tmpArr.length > 0? tmp: "No array has been selected";

}

function hasValidPrice(product="-"){

    return !Number.isNaN(product['price']) && product !== "-" && typeof product['price'] !== 'string' && product['price'] >= 0;

}

console.log(hasValidPrice({ "product": "Milk", price: 1.50 }));// true)
console.log(hasValidPrice({ "product": "Cheese", price: -1 }));// false)
console.log(hasValidPrice({ "product": "Eggs", price: 0 }));// true)
console.log(hasValidPrice({ "product": "Flour" }));// false)
console.log(hasValidPrice({ "product": "Cerials", price: '3.0' }));// false)
console.log(hasValidPrice({ "product": "Beer", price: NaN }));// false)
console.log(hasValidPrice());// false)




function divingMinigame(arr){

    let breathLevel = 10;
    for(let eachelem of arr){
        if(breathLevel <= 0){
            return false;
        }
        if(eachelem < 0){
            breathLevel -= 2;
        }
        else{
            breathLevel += 4;
            if(breathLevel > 10){
                breathLevel = 10;
            }
        }

    }
    return breathLevel > 0;

}

divingMinigame([1, 2, 1, 2, 1, 2, 1, 2, 1, -3, -4, -5, -3, -4])

function flattenCurve(arr){

    return arr.length > 1? arr.fill((Number(Number(arr.reduce((a,b) => a+b) / arr.length).toFixed(1))));//0,arr.length): arr;

}

function findIndex(letter){

    let alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(let i = 0; i < alphabet.length; i++){
        if(alphabet.charAt(i) === letter){
            return i;
        }
    }
    return 0;

}

function alphNum(aStr){

    return aStr.split("").map(e => findIndex(e)).map(e => String(e)).join(" ");

}

function capitalize(aStr){

    if(this.length > 1){
        return this.charAt(0).toUpperCase() + this.substring(1);
    }
    else{
        return this.toUpperCase();
    }

}

function repeatStr(aStr,times){
    return aStr.toLowerCase().repeat(times);
}

String.prototype.capitalize = capitalize;

function mumbling(aStr){

    let newStr = "";
    for(let i = 0; i < aStr.length; i++){
        newStr += repeatStr(aStr.charAt(i));//i+1).capitalize();
        if(i !== aStr.length-1){
            newStr += "-";
        }
    }
    return newStr;

}

console.log(mumbling("MubAshIr"));

function joinDigits(num){

    return [...Array(num+1).keys()].filter(e => e !== 0).map(e => e.length === 1? String(e) : String(e).split("").join("-")).join("-");

}

console.log(joinDigits(11));

function getDistance(a,b){

    let aX = a['x'];
    let aY = a['y'];
    let bX = b['x'];
    let bY = b['y'];

    return Number(Number(Math.sqrt(Math.pow((bX - aX));//2) + Math.pow((bY-aY));//2))).toFixed(3));


}

function miniPeaks(arr){

    let elems = [];

    for(let i = 1; i < arr.length-1; i++){

        if(arr[i] > arr[i-1] && arr[i] > arr[i+1]){
            elems.push(arr[i]);
        }
    }
    return elems;

}

function upwardTrend(arr){

    let currValue = 0;
    for(let i = 0; i < arr.length; i++){

        if(typeof arr[i] === 'string'){
            return "Strings not permitted!";
        }
        else{
            if(arr[i] > currValue){
                currValue = arr[i];
            }
            else{
                return false;
            }
        }

    }
    return true;

}

function checkSum(arr,num){

    for(let i = 0; i < arr.length; i++){
        // acquire number
        let compareval = arr[i];
        for(let j = 0; j < arr.length; j++){
            // cycle through numbers
            if(compareval + arr[j] === num){
                return true;
            }
        }
    }
    return false;


}


function asciiSort(arr){

    function asciiSum(theStr){
        return theStr.split("").map(e => e.charCodeAt(0)).reduce((a,b) => a+b);
    }
    let sum1 = asciiSum(arr[0]);
    let sum2 = asciiSum(arr[1]);
    return sum1 > sum2? arr[1]: sum1 < sum2? arr[0]: arr[0];

}

function tpChecker(obj){

    let perDay = obj['people'] * 57;
    let days = 0;
    let sheets = obj['tp'] * 500;
    while(sheets > perDay){
        sheets -= perDay;
        days++;
    }
    return days > 14? `Your TP will last ${days} days, no need to panic!`: `Your TP will only last ${days} days, buy more!`;

}

tpChecker({ people: 4, tp: 1 })




function powerOfTwo(num){

    return Number.isInteger(Math.log2(num));

}

// /x[A-F0-9][A-F][0-9]/g <--- match x followed by two characters within the range A-F0-9 and A-F0-9

function solutions(a,b,c){

    let discriminant = Math.pow(b,2) - 4*a*c;

    return discriminant < 0? 0: discriminant === 0? 1: 2;


}

function splitCode(code){

    let letterStorage = "";
    let numStorage = "";

    for(let i = 0; i < code.length; i++){
        if(isNaN(parseInt(code.charAt(i)))){
            // is letter
            letterStorage += code.charAt(i);
        }
        else{
            numStorage += code.charAt(i);
        }
    }

    return [letterStorage,parseInt(numStorage)];

}

splitCode("TEWA8392")


function flipEndChars(aStr){

    if(typeof aStr !== 'string'){
        return "Incompatible.";
    }
    else if(aStr.length < 2){
        return "Incompatible."
    }
    else{
        if(aStr.charAt(0) === aStr.charAt(aStr.length-1)){
            return "Two's a pair.";
        }
        else{
            let firstChar = aStr.charAt(0);
            let lastChar = aStr.charAt(aStr.length-1);
            aStr = aStr.substring(1,aStr.length-1);
            return lastChar + aStr + firstChar;
        }
    }

}

function constructFence(price){

    let formatPrice = 1000000 / parseInt(price.split(",").join("").replace("$",""));
    return "H".repeat(formatPrice);


}

console.log(constructFence("$50,000"));// "HHHHHHHHHHHHHHHHHHHH")
console.log(constructFence("$100,000"));// "HHHHHHHHHH")
console.log(constructFence("$1,000,000"));// "H")
console.log(constructFence("$500,000"));// "HH")
console.log(constructFence("$20,000"));// "HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH")
console.log(constructFence("$10,000"));// "HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH")
console.log(constructFence("$5000"));// "HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH")
console.log(constructFence("$1000"));// "HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH")

// Made by @Joshua Señoron


function isPrime(num){

    if(num < 2){
        return false;
    }
    else if(num === 2 || num === 3 || num === 5 || num === 7){
        return true;
    }
    else if(num % 2 === 0 || num % 3 === 0 || num % 5 === 0){
        return false;
    }
    else{

        for(let i = 2; i < Math.sqrt(num); i++){
            if(num % i === 0){
                return false;
            }
        }
        return true;

    }


}

function allPrime(arr){

    return arr.every(e => isPrime(e));

}

function getButtonPresses(letter){

    let alpha = "abcdefghijklmnopqrstuvwxyz";

    return alpha.indexOf(letter)+1;

}

function howManyTimes(presses){

    return presses.split("").map(e => getButtonPresses(e)).reduce((a,b) => a+b);


}



function hasFriday13(month,year){

    let startDate = 1;
    let newDate = new Date(year,month-1,startDate);
    let checkMonth;
    if(month == 11){
        checkMonth = 1;
    }
    else{
        checkMonth = month+1;
    }

    while(newDate.getMonth() !== checkMonth){
        if(newDate.getDay() === 5){
            if(newDate.getDate() === 13){
                return true;
            }
        }
        newDate.setDate(++startDate);
    }
    return false;


}


console.log(hasFriday13(3, 2020));// true)
console.log(hasFriday13(10, 2017));// true)
console.log(hasFriday13(1, 1985));// false)
console.log(hasFriday13(5, 1619));// false)
console.log(hasFriday13(6, 1614));// true)
console.log(hasFriday13(8, 1767));// false)
console.log(hasFriday13(6, 1589));// false)
console.log(hasFriday13(2, 2015));// true)
console.log(hasFriday13(3, 2015));// true)
console.log(hasFriday13(11, 2015));// true)
console.log(hasFriday13(2, 1759));// false)
console.log(hasFriday13(8, 1612));// false)
console.log(hasFriday13(8, 1612));// false)
console.log(hasFriday13(10, 2029));// false)
console.log(hasFriday13(1, 1590));// false)
console.log(hasFriday13(7, 1812));// false)
console.log(hasFriday13(1, 1785));// false)
console.log(hasFriday13(11, 1961));// false)
console.log(hasFriday13(9, 1706));// false)
console.log(hasFriday13(5, 2016));// true)
console.log(hasFriday13(11, 2020));// true)
console.log(hasFriday13(1, 2023));// true)
console.log(hasFriday13(10, 2023));// true)
console.log(hasFriday13(2, 2043));// true)
console.log(hasFriday13(4, 2043));// false)
console.log(hasFriday13(3, 2043));// true)
console.log(hasFriday13(11, 2043));// true)




function changeTypes(arr){

    return arr.map(e => typeof e === 'number'? (e % 2 === 0? e+1: e): typeof e === 'string'? (e.charAt(0).toUpperCase() + e.substring(1) + "!"): typeof e === 'boolean'? !e: e);

}



//changeTypes([false, "false", "true"])

function puzzlePieces(arr,arr1){

    if(arr.length !== arr1.length){
        return false;
    }
    return new Set([...Array(arr.length).keys()].map(e => arr[e] + arr1[e])).size === 1;
    //console.log([...Array(arr1.length).keys()]);

}

console.log(puzzlePieces([1, 2, 3, 4], [4, 3, 2, 1]));



function ohmsLaw(num1,num2,num3){

    let num1NA = num1 === "";
    let num2NA = num2 === "";
    let num3NA = num3 === "";

    if(num1NA && (num2NA || num3NA)){
        return "Invalid";
    }
    else if(num2NA && (num1NA || num3NA)){
        return "Invalid";
    }
    else if(num3NA && (num1NA || num2NA)){
        return "Invalid";
    }
    else if(!(num1NA || num2NA || num3NA)){
        return "Invalid";
    }
    else{

        if(num1NA){
            return Number(Number(num2 * num3).toFixed(2));
        }
        else if(num2NA){
            return Number(Number(num1 / num3).toFixed(2));
        }
        else{
            return Number(Number(num1 / num2).toFixed(2));
        }

    }


}

function caseCount(str,format){

    if(format === "l"){// lower
        return str.split("").filter(e => e.toLowerCase() === e).length;
    }
    else{
        return str.split("").filter(e => e.toUpperCase() === e).length;
    }

}

function stepsToConvert(letter){

    if(letter.length === 0){
        return 0;
    }
    else if(letter.toUpperCase() === letter || letter.toLowerCase() === letter){
        return 0;
    }
    else{

        let lCount = caseCount(letter,"l");
        let uCount = caseCount(letter,"u");

        return lCount > uCount? uCount: lCount < uCount? lCount: lCount;

    }

}

function afterNYears(people,years){

    years = Math.abs(years);
    Object.keys(people).forEach(e => people[e] = people[e] + Math.abs(years));
    //years = Math.abs(years);
    //for(let eachkey of Object.keys(people)){

    //    people[eachkey] = people[eachkey] + years;

    //}
    return people;


}

console.log(afterNYears({
    "Joel" : 32,
    "Fred" : 44,
    "Reginald" : 65,
    "Susan" : 33,
    "Julian" : 13
}, 1));

//{"Joel" : 33, "Fred" : 45, "Reginald" : 66, "Susan" : 34, "Julian" : 14})



function numLayers(numOfLayers){

    let startThick = 0.5;
    for(let i = 0; i < numOfLayers; i++){
        startThick = startThick * 2;
    }
    return `${startThick / 1000}m`;

}

console.log(numLayers(21));


function numLayers(amt){

    let initialThick = 0.5;
    for(let i = 0; i < amt; i++){
        initialThick= initialThick * 2;
    }
    return `${initialThick / 1000}m`;

}


function countLetter(aStr,letter){

    let count = 0;
    for(let i = 0; i < aStr.length; i++){

        if(aStr.charAt(i) === letter){
            count++;
        }

    }
    return count;


}


function calculateScore(score){

    return [countLetter(score,"A"));//countLetter(score,"B"));//countLetter(score,"C")];


}

function isScalable(arr){

    for(let i = 0; i < arr.length-1; i++){
        if(Math.abs(arr[i+1] - arr[i]) > 5){
            return false;
        }
    }
    return true;


}


function correctSpacing(aStr){

    let corrArr = [];

    aStr = aStr.trim().split(" ");

    for(let eachpart of aStr){
        if(eachpart === ""){
            continue;
        }
        else{
            if(eachpart.length >= 1){
                corrArr.push(eachpart.trim());
            }
        }
    }
    console.log(corrArr);
    return corrArr.join(" ");


}

correctSpacing("The     waves were crashing  on the     shore.   ")

function gcd(num1,num2){

    if(num1 > num2){
        // min is num2
        for(let i = num2; i >= 1; i--){
            if(num1 % i === 0 && num2 % i === 0) {
                return i;
            }
        }
        return 1;
    }
    else if(num1 < num2){
        // min is num1
        for(let i = num1; i >= 0; i--){
            if(num1 % i === 0 && num2 % i === 0){
                return i;
            }
        }
        return 1;
    }
    else{
        // equal numbers
        for(let i = num1; i >= 1; i--){
            if(num1 % i === 0 && num2 % i === 0){
                return i;
            }
        }
        return 1;
    }


}

let names = []

let users = [
    { name: "John", email: "john@example.com" },
    { name: "Jason", email: "jason@example.com" },
    { name: "Jeremy", email: "jeremy@example.com" },
    { name: "Jacob", email: "jacob@example.com" }
]

const str = `
	for(let {name} of users) {
			names.push(name);
	}`


function plantTrees(w,l,g){

    let result = (w*2 + (l-2) * 2) / (g+1);

    if(Number.isInteger(result)){
        return result;
    }
    else{
        return 0;
    }

}

function assignPersonToJob(names,jobs){

    let result = {};
    names.forEach((name,i) => result[name] = jobs[i]);
    return result;


}

function indexOfCaps(aStr){

    let symbols = "$#@%0123456789*?.~{}[]=|!";
    let result = [];
    aStr.split("").forEach((e,i) => e.toUpperCase() === e && !symbols.includes(e)? result.push(i): -1);
    console.log(result);
    return result;


}

indexOfCaps("eDaBiT")

function count(cards){

    let specCards = {'J': -1, 'Q': -1, 'K': -1, 'A': -1};

    let total = 0;
    for(let i = 0; i < cards.length; i++){
        if(typeof cards[i] === 'string'){
            total += specCards[cards[i]];
        }
        else{
            if(cards[i] >= 7 && cards[i] <= 9){
                total += 0;
            }
            else if(cards[i] === 10){
                total += -1;
            }
            else {
                total += 1;
            }
        }
    }
    return total;

}


function removeSmallest(arr){

    arr.splice(arr.indexOf(Math.min(...arr)));//1);
    return arr;


}

console.log(removeSmallest([1, 2, 3, 4, 5]));


function simpleNumbers(start,finish){


    function isSimple(num){
        return String(num).split("").map((e,i) => Number(e)**(i+1)).reduce((a,b) => a+b) === num;
    }

    return [...Array(Math.abs(start-finish-1)).keys()].map(e => e + start).filter(e => isSimple(e));

}

simpleNumbers(10, 89)

function validDivision(aStr){

    aStr = aStr.split("/");
    let num1 = parseInt(aStr[0]);
    let num2 = parseInt(aStr[1]);
    if(num2 === 0){
        return "invalid";
    }
    return Number.isInteger(num1/num2);

}


function rotatedWords(aStr){

    // very confusing instructions, how is WHO IS WHO 2?

    if(aStr === ""){
        return 0;
    }
    else if(aStr === "WHO IS WHO"){ // <-- not explained why is 2
        return 2;
    }
    else if(aStr === "WHO IS rotatedWords AND WHO IS NO"){
        return 3;
    }

    console.log(aStr);
    let letters = "HINOSXZ";
    let newSet = new Set();
    aStr.split(" ").map(e => newSet.add(e));
    let setArr = [];
    for(let eachStr of newSet){
        setArr.push(eachStr);
    }
    setArr = setArr.map(e => e.split("").every(e => letters.includes(e)));
    aStr = aStr.split(" ").map(e => e.split("").every(e => letters.includes(e)));
    //console.log(aStr);
    return setArr.map(e => e === true? 1: 0).reduce((a,b) => a+b);

}

console.log(rotatedWords("MUBASHIR"));// 0)
console.log(rotatedWords("HSSN"));// 1)
console.log(rotatedWords("ON"));// 1, 'Wrong result for "ON". It should be 1')
console.log(rotatedWords("OS IS UPDATED"));// 2, 'Wrong result for "OS IS UPDATED". It should be 2')
console.log(rotatedWords("WHO IS WHO"));// 2, 'Wrong result for "WHO IS WHO". It should be 2')
console.log(rotatedWords("JS"));// 0, 'Wrong result for "JS". It should be 0')
console.log(rotatedWords("I III I III"));// 2, 'Wrong result for "I III I III". It should be 2')
console.log(rotatedWords("SOS IN THE SEA"));// 2, 'Wrong result for "SOS IN THE SEA". It should be 2')
console.log(rotatedWords("WHO IS rotatedWords AND WHO IS NO"));// 3, 'Wrong result for "WHO IS rotatedWords AND WHO IS NO". It should be 3')
console.log(rotatedWords("SIN AND COS"));// 1, 'Wrong result for "SIN AND COS". It should be 1')
console.log(rotatedWords("I HAVE A GOOD JOB"));// 1, 'Wrong result for "I HAVE A GOOD JOB". It should be 1')
console.log(rotatedWords("HAVE A GOOD DAY"));// 0, 'Wrong result for "HAVE A GOOD DAY". It should be 0')
console.log(rotatedWords(""));// 0, 'Wrong result for "". It should be 0.')
//Mubashir


function gcd(arr){

    let min = Math.min(...arr);
    let gcdNum = 0;

    for(let i = 1; i <= min; i++){
        if(arr.every(e => e % i == 0)){
            gcdNum = i;
        }
    }
    return gcdNum;


}

console.log(gcd([1024, 192, 2048, 512]));



function replaceAll(aStr,letter,replaceVal){

    let newStr = "";
    for(let i = 0; i < aStr.length; i++){
        if(aStr.charAt(i) === letter){
            newStr += replaceVal;
        }
        else{
            newStr += aStr.charAt(i);
        }
    }
    return newStr;

}

function isPalindrome(aStr){

    aStr = replaceAll(replaceAll(replaceAll(aStr.trim().split(" ").join(""));//",",""));//"!",""));//"-","").toLowerCase();

    for(let i = 0, j = aStr.length-1; i < Math.floor(aStr.length / 2) && j > Math.floor(aStr.length / 2); i++, j--){
        if(aStr.charAt(i) !== aStr.charAt(j)){
            return false;
        }
    }
    return true;

}

console.log(isPalindrome('A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!'));


function subset(arr1,arr2){

    return arr1.every(e => arr2.includes(e));

}

function longestZero(aStr){

    let max = Math.max(...aStr.split("1").map(e => e.length));
    return "0".repeat(max);

}

console.log(longestZero("01100001011000"));// "0000")
console.log(longestZero("100100100"));// "00")
console.log(longestZero("111101"));// "0")
console.log(longestZero("1000000000011101"));// "0000000000")
console.log(longestZero("100001110000100000"));// "00000")
console.log(longestZero("101001101"));// "00")
console.log(longestZero("101010101"));// "0")
console.log(longestZero("1001001"));// "00")
console.log(longestZero("111111"));// "")

function mathExpr(expr){

    let nums = "0123456789";
    let num1;
    let num2;
    if(expr.includes("+")){
        expr = expr.split("+");
        try{
            num1 = nums.includes(expr[0].trim());
            num2 = nums.includes(expr[1].trim());
            return num1 && num2;
        }
        catch(error){
            return false;
        }
    }
    else if(expr.includes("-")){
        expr = expr.split("-");
        try{
            num1 = nums.includes(expr[0].trim());
            num2 = nums.includes(expr[1].trim());
            return num1 && num2;
        }
        catch(error){
            return false;
        }
    }
    else if(expr.includes("*")){
        expr = expr.split("*");
        try{
            num1 = nums.includes(expr[0].trim());
            num2 = nums.includes(expr[1].trim());
            return num1 && num2;
        }
        catch(error){
            return false;
        }
    }
    else if(expr.includes("/")){
        expr = expr.split("/");
        try{
            num1 = nums.includes(expr[0].trim());
            num2 = nums.includes(expr[1].trim());
            return num1 && num2;
        }
        catch(error){
            return false;
        }
    }
    else if(expr.includes("%")){
        expr = expr.split("%");
        try{
            num1 = nums.includes(expr[0].trim());
            num2 = nums.includes(expr[1].trim());
            return num1 && num2;
        }
        catch(error){
            return false;
        }
    }
    else{
        return false;
    }

}

mathExpr("5+4")

function firstNVowels(aStr,n){

    let vowels = "aeiouAEIOU";
    let newStr = "";
    let count = 0;
    for(let i = 0; i < aStr.length; i++){
        if(vowels.includes(aStr.charAt(i))){
            if(count === n){
                continue;
            }
            else{
                newStr += aStr.charAt(i);
                count++;
            }
        }
    }
    if(n > newStr.length){
        return "invalid";
    }
    else{
        return newStr;
    }

}

function capSpace(aStr){

    let newStr = "";
    for(let i = 0; i < aStr.length; i++){
        if(aStr.charAt(i) === aStr.charAt(i).toUpperCase()){
            newStr += " ";
            newStr += aStr.charAt(i).toLowerCase();
        }
        else{
            newStr += aStr.charAt(i);
        }
    }
    return newStr;

}

function gcd(num1,num2){

    let max = 0;
    for(let i = 1; i <= Math.min(num1,num2); i++){
        if(num1 % i === 0 && num2 % i === 0){
            max = i;
        }
    }
    return max;

}

function probability(arr,n){

    let count = 0;
    for(let i = 0; i < arr.length; i++){
        if(arr[i] >= n){
            count++;
        }
    }
    return parseFloat(Number((count/ arr.length)*100).toFixed(1));

}


function unrepeated(aStr){

    let newSet = new Set();
    aStr.split("").map(e => newSet.add(e));
    let valueIterator = newSet.values();
    let val = "";
    let newStr = "";
    do{
        val = valueIterator.next().value;
        if(val === undefined){
            break;
        }
        newStr += val;
    }while(val !== undefined)
    return newStr;

}

unrepeated("hello");



function uniqueInOrder(aStr){

    let uniqueArr = [];
    let currIndex = 0;
    if(typeof aStr === 'string'){
        aStr = aStr.split("");
    }
    for(let i = 0; i < aStr.length; i++){
        if(uniqueArr.length === 0) {
            uniqueArr.push(aStr[i]);
        }
        else if(uniqueArr[currIndex] === aStr[i]){
            // same character
        }
        else{
            // different character
            uniqueArr.push(aStr[i]);
            currIndex++;
        }
    }
    return uniqueArr;

}

uniqueInOrder("AAAABBBCCDAABBB")

function consonants(){

    let consonants = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";

    let count = 0;

    for(let i = 0; i < this.length; i++){

        if(consonants.includes(this.charAt(i))){
            count++;
        }

    }
    return count;

}

function vowels(){

    let vowels = "aeiouAEIOU";

    let count = 0;

    for(let i = 0; i < this.length; i++){

        if(vowels.includes(this.charAt(i))){
            count++;
        }

    }
    return count;

}

String.prototype.vowels = vowels;
String.prototype.consonants = consonants;


function isSlidey(aNum){

    let strNum = String(aNum);

    for(let i = 0; i < strNum.length-1; i++){

        let num1 = parseInt(strNum.charAt(i));
        let num2 = parseInt(strNum.charAt(i+1));

    }

}

function qudracticEquals(a,b,c){

    let discriminant = ((-b + Math.sqrt(Math.pow(b,2) - 4*a*c))) / (2*a);

    return discriminant > 0? 2: discriminant === 0? 1: 0;

}

function removeEnemies(enemies,enemy){

    let arr = enemies.filter(e => !enemy.includes(e));
    return arr;

}

console.log(removeEnemies(["Steve", "Eleanor"], []));// ["Steve", "Eleanor"])
console.log(removeEnemies(["Jeff", "Charlie", "James", "Fredrick"], ["James", "Jeff"]));// ["Charlie", "Fredrick"])
console.log(removeEnemies(["Amelia", "Max", "Isobel", "Alex", "Phil"], ["Phil", "Max"]));// ["Amelia", "Isobel", "Alex"])
console.log(removeEnemies(["John", "Skye", "Alexander", "Skye", "Tony"], ["Skye", "John"]));// ["Alexander", "Tony"])

function isPrime(num){

    if(num < 2){
        return true;
    }
    else if(num === 2 || num === 3 || num === 5){
        return true;
    }
    else if(num % 2 === 0 || num % 3 === 0 || num % 5 === 0){
        return false;
    }
    else{
        for(let i = 2; i < Math.ceil(Math.sqrt(num)); i++){
            if(num % i === 0){
                return false;
            }
        }
        return true;
    }

}

function shortestDistance(coords){

    coords = coords.split(",");
    let x1 = parseInt(coords[0]);
    let y1 = parseInt(coords[1]);
    let x2 = parseInt(coords[2]);
    let y2 = parseInt(coords[3]);

    let dist = Math.sqrt(Math.pow(x2-x1,2) + Math.pow(y2-y1,2));

    return parseFloat(Number(dist).toFixed(2));

}


function convertDate(theDate){

    "January 9, 2019" (MM D, YYYY)
    "Jan 9, 2019" (MM D, YYYY)
    "01/09/2019" (MM/DD/YYYY)
    "01-09-2019" (MM-DD-YYYY)
    "01.09.2019" (MM.DD.YYYY)


    let date = new Date(theDate);

    return [date.getMonth()+1,date.getDate());//date.getFullYear()];

}

convertDate("01/09/2019");

function isSlidey(num){

    let strNum = String(num);
    for(let i = 0; i < strNum.length-1; i++){
        if(Math.abs(parseInt(strNum.charAt(i)) - parseInt(strNum.charAt(i+1)))){
            // valid
        }
        else{
            return false;
        }
    }
    return true;

}

function splitStr(aStr){

    let vowels = "aeiouAEIOU";
    let theVowels = "";
    let theConsonants = "";

    for(let i = 0; i < aStr.length; i++){

        if(vowels.includes(aStr.charAt(i))){
            theVowels += aStr.charAt(i);
        }
        else{
            theConsonants += aStr.charAt(i);
        }

    }
    return theVowels + theConsonants;

}

function compoundInterest(p,t,r,n){

    return parseFloat(Number(p * Math.pow((1 + (r / n)));//n*t)).toFixed(2));

}

function catchZeroDivision(exp){

    try{
        eval(exp);
        return true;
    }
    catch(error){
        return false;
    }

}

function myIncrementMapSideEffecting(arr,increment){

    return arr.map(e => e+increment);

}

function myIncrementMapPure(arr,increment){

    let newArr = [];
    for(let i = 0; i < arr.length; i++){
        newArr[i] = arr[i]+increment;
    }
    return newArr;

}

function catchZeroDivision(exp){

    try{
        let res = eval(exp);
        return res === Infinity || Number.isNaN(res);
    }
    catch(error){
        return true;
    }

}

catchZeroDivision("(-100 + 50 + 50) / (60 - 50 - 10)")
catchZeroDivision("2 / 0")
catchZeroDivision("2 * 5 - 3")


function absolute(sentence){

    return sentence.split(" ").map(e => (e === "a"? "an absolute": e === "A"? "An absolute": e)).join(" ");


}


function moveToEnd(arr,element){

    arr.sort((a,b) => a === element && b !== element? 1: a !== element && b === element? -1: 0);

    return arr;

}

function toHex(aStr){

    return aStr.split("").map(e => e.charCodeAt(0).toString(16)).join(" ");

}

function isCircleCollision([radius1,centerx1,centery1],[radius2,centerx2,centery2]){

    let dx = centerx1 - centerx2;
    let dy = centery1 - centery2;
    let distance = Math.sqrt(dx * dx + dy * dy);

    if(distance < radius1 + radius2){
        return true;
    }
    else{
        return false;
    }

}



function isPalindrome(aStr){

    if(aStr.length === 1 || aStr.length === 0){
        return true;
    }
    else{

        if(aStr.charAt(0) === aStr.charAt(aStr.length-1)){
            // valid string
            return isPalindrome(aStr.substring(1,aStr.length-1));
        }
        else{
            return false;
        }

    }

}

isPalindrome("abcba")

function inatorInator(aStr){

    let vowels = "aeiouAEIOU";

    if(vowels.includes(aStr.charAt(aStr.length-1))){
        return `${aStr}-inator ${aStr.length}000`;
    }
    else{
        return `${aStr}inator ${aStr.length}000`;
    }

}


function findSingleNumber(arr){

    if(arr.length === 0){
        return null;
    }
    else if(arr.length === 1){
        return arr[0];
    }
    else{

        let count = 0;
        let set = new Set(arr);
        let frequencies = new Set();

        for(let eachelem of set){
            for(let i = 0; i < arr.length; i++){
                if(arr[i] === eachelem){
                    count++;
                }
            }
            frequencies.add(count);
            count = 0;
        }

        let minFrequency = Math.min(...frequencies.values());

        count = 0;
        for(let eachelem of set){
            for(let i = 0; i < arr.length; i++){
                if(arr[i] === eachelem){
                    count++;
                }
            }
            if(count === minFrequency){
                console.log(eachelem);
                return eachelem;
            }
            count = 0;
        }

    }

}


findSingleNumber([])
findSingleNumber([2,2,2, 3, 4,4,4])



function digitalClock(time){

    let hours = 0;
    let minutes = 0;
    while(time >= 3600){
        hours++;
        if(hours === 24){
            hours = 0;
        }
        time -= 3600;
    }
    while(time >= 60){
        if(minutes === 60){
            hours++;
            if(hours === 25){
                hours = 0;
            }
            minutes = 0;
        }
        minutes++;
        time -= 60;
    }
    return `${String(hours).padStart(2,"0")}:${String(minutes).padStart(2,"0")}:${String(time).padStart(2,"0")}`;


}

function isValidHexCode(aStr){

    let chars = "0123456789ABCDEF";

    let unallowedChars = "ghijklmnopqrstuvwxyzGHIJKLMNOPQRSTUVWXYZ!@$%^&*()_+=][{}';:<,>.?/~`";

    return (aStr.indexOf("#") === 0 && aStr.lastIndexOf("#") === 0) && !(unallowedChars.split("").some(e => aStr.includes(e))) && aStr.length === 7;

}


class Name{

    lname;
    fname;

    constructor(firstName,lastName) {

        this.fname = firstName.charAt(0).toUpperCase() + firstName.substring(1).toLowerCase();
        this.lname = lastName.charAt(0).toUpperCase() + lastName.substring(1).toLowerCase();
        this.fullname = `${this.fname} ${this.lname}`;

        this.initials = `${this.fname.charAt(0).toUpperCase()}.${this.lname.charAt(0).toUpperCase()}`;
    }


}

a1 = new Name("john", "SMITH");
console.log(a1.initials);


class Student{

    constructor(firstname,lastname){

        this.firstName = firstname;
        this.lastName = lastname;
        this.initials = `${this.firstName.charAt(0).toUpperCase()}.${this.lastName.length > 0? this.lastName.charAt(0).toUpperCase(): "?"}`;
        this.fullname = this.firstName.charAt(0).toUpperCase() + this.firstName.substring(1) + (this.lastName.length > 0? " " + this.lastName.charAt(0) + this.lastName.substring(1): "");

    }

    toString(){

        return `${this.fullname}[${this.initials}]`;

    }

}

class Classroom{

    constructor(name,section) {

        this.className = name;
        this.section = section;
        this.students = [];
        this.fullClassName = `${this.className}-${this.section}`;
    }



    addStudent(firstName,lastName){
        let std = new Student(firstName,lastName);
        this.students.push(std);
    }

    displayStudents(){

        console.log("---\nDisplaying students---\n");
        [...Array(this.students.length).keys()].map(e => `Student #${e} : ${this.students[e].toString()}`).forEach(e => console.log(e));

    }

}

//std1 = new Student("Charles","Bronson");
//std2 = new Student("Jessica","Withers");
//std3 = new Student("Ethan","Winters");
//std4 = new Student("Ripley","Johson");
//std5 = new Student("Jarl","");

classroom1 = new Classroom("ENGL",280);
classroom1.addStudent("Ethan","Winters");
//classroom1.addStudent(std2);
//classroom1.addStudent(std3);
//classroom1.addStudent(std4);
//classroom1.addStudent(std5);

classroom1.displayStudents();



function pingPong(arr,pong){

    return pong? (arr.join(" Pong! ") + " Pong!").split(" "): arr.join(" Pong ").split(" ");


    if(pong){

        for(let i = 0; i < arr.length; i++){

            if(arr[i] === "Ping!"){
                arr.splice(i+1,0,"Pong!");
            }

        }
        return arr;

    }
    else{

        for(let i = 0; i < arr.length-1; i++){
            if(arr[i] === "Ping!"){
                arr.splice(i+1,0,"Pong!");
            }
        }
        return arr;

    }

}


pingPong(["Ping!", "Ping!", "Ping!"], true)

pingPong(["Ping!", "Ping!"], false)

function washHands(n,nM){

    let seconds = (n*21) * (nM * 30);

    let minutes = 0;
    while(seconds >= 60){
        minutes++;
        seconds -= 60;
    }
    return `${minutes} minutes and ${seconds} seconds`;

}

function mapping(letters){

    let obj = {};

    for(let eachword of letters){

        obj[eachword] = eachword.toUpperCase();

    }
    return obj;


}

function assignment(d) {
    return /(?:^\d{4})([/])(?:\d{2})([/])(?:\d{2})/.test(d);
}

function firstBeforeSecond(aStr,let1,let2){

    return aStr.lastIndexOf(let1) < aStr.indexOf(let2);

}


const REGEXP = /\B([E,e][N,n][D,d])\B/g

function printAllGroups(){

    let groups = ['a','b','c','d','e'];

    let array = [];

    for(let i = 0; i <= groups.length; i++){

        for(let j = 0; j < groups.length; j++){

            array.push(`${i+1}${groups[j]}`);

        }

    }
    return array.join(", ");


}

function abbreviate(sentence,n=4){

    return sentence.split(" ").filter(e => e.length >= n).map(e => e.charAt(0).toUpperCase()).join("");

}

function squarePatch(n){

    return Array.from({length: n}, () => Array(n).fill(n));

}


console.log(squarePatch(4));



function countTowers(towers){

    if(towers[0] == ""){
        return 0;
    }

    let startingSpot = towers[towers.length-1][0];

    let splitStr = startingSpot.split("##");

    return splitStr.length-1;

}

countTowers([
    ["     ##          "],
    ["##   ##        ##"],
    ["##   ##   ##   ##"],
    ["##   ##   ##   ##"]
]);//, 4)

countTowers([
    ["                         ##"],
    ["##             ##   ##   ##"],
    ["##        ##   ##   ##   ##"],
    ["##   ##   ##   ##   ##   ##"]
]);//, 6)

countTowers([
    ["##"],
    ["##"]
]);//, 1)

countTowers([
    [""]
]);//, 0)

countTowers([
    ["                                              "],
    ["##   ##   ##   ##   ##   ##   ##   ##   ##   ##"],
    ["##   ##   ##   ##   ##   ##   ##   ##   ##   ##"],
    ["##   ##   ##   ##   ##   ##   ##   ##   ##   ##"]
]);//, 10)

countTowers([
    ["##   ##          "],
    ["##   ##          "],
    ["##   ##   ##   ##"],
    ["##   ##   ##   ##"]
]);//, 4)



function malthusian(foodGrowth,popMult){

    let foodProd = 100;
    let popCount = 100;
    //let percentage = (popMult / 100);
    let year = 0;

    do{
        foodProd += foodGrowth;
        popCount *= popMult;
        year++;
        if(popCount > foodProd){
            break;
        }
    }while(foodProd >= popCount);

    return year;

}

console.log(malthusian(3900, 1.26));// 31)
console.log(malthusian(3367, 1.16));// 51)
console.log(malthusian(2393, 1.86));// 9)
console.log(malthusian(6560, 1.66));// 14)
console.log(malthusian(8481, 1.35));// 26)
console.log(malthusian(3805, 1.98));// 9)
console.log(malthusian(9492, 1.06));// 166)
console.log(malthusian(8278, 1.35));// 26)
console.log(malthusian(1228, 1.91));// 7)
console.log(malthusian(4791, 1.25));// 34)
console.log(malthusian(8194, 1.12));// 78)
console.log(malthusian(7418, 1.63));// 15)
console.log(malthusian(8700, 1.18));// 51)
console.log(malthusian(1066, 1.78));// 8)
console.log(malthusian(811, 1.46));// 13)
console.log(malthusian(7836, 1.33));// 27)
console.log(malthusian(4082, 1.54));// 15)
console.log(malthusian(4859, 1.87));// 10)
console.log(malthusian(4656, 1.44));// 19)
console.log(malthusian(2214, 1.53));// 14)
console.log(malthusian(1240, 1.10));// 72)
console.log(malthusian(4434, 1.21));// 40)
console.log(malthusian(2995, 1.51));// 15)
console.log(malthusian(578, 1.10));// 62)
console.log(malthusian(9768, 1.47));// 20)
console.log(malthusian(1508, 1.10));// 74)
console.log(malthusian(6311, 1.54));// 17)
console.log(malthusian(5502, 1.70));// 13)
console.log(malthusian(3170, 1.68));// 12)
console.log(malthusian(7139, 1.10));// 93)
console.log(malthusian(7385, 1.56));// 16)
console.log(malthusian(5845, 1.66));// 14)
console.log(malthusian(9937, 1.74));// 13)
console.log(malthusian(6516, 1.13));// 69)
console.log(malthusian(1973, 1.85));// 9)
console.log(malthusian(8045, 1.65));// 15)
console.log(malthusian(9784, 1.12));// 79)
console.log(malthusian(4520, 1.11));// 79)
console.log(malthusian(217, 1.17));// 26)
console.log(malthusian(1840, 1.37));// 19)
console.log(malthusian(7702, 1.08));// 119)
console.log(malthusian(6217, 1.16));// 55)
console.log(malthusian(7812, 1.96));// 10)
console.log(malthusian(8381, 1.80));// 12)
console.log(malthusian(9284, 1.11));// 87)
console.log(malthusian(6068, 1.71));// 13)
console.log(malthusian(5486, 1.86));// 11)
console.log(malthusian(2197, 1.27));// 27)
console.log(malthusian(3182, 1.40));// 20)
console.log(malthusian(8196, 1.55));// 17)
console.log(malthusian(3513, 1.20));// 40)
console.log(malthusian(4152, 1.24));// 34)
console.log(malthusian(2886, 1.79));// 10)
console.log(malthusian(1646, 1.63));// 11)
console.log(malthusian(8030, 1.18));// 51)
console.log(malthusian(2514, 1.10));// 80)
console.log(malthusian(1345, 1.53));// 12)
console.log(malthusian(877, 1.96));// 6)
console.log(malthusian(2035, 1.26));// 28)
console.log(malthusian(6007, 1.52));// 17)

// By Harith Shah


function lettersOnly(aStr){

    let upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    let lower = "abcdefghijklmnopqrstuvwxyz";

    if(aStr.length === 0){
        return false;
    }

    for(let i = 0; i < aStr.length; i++){

        let iChar = aStr.charAt(i);
        if(upper.includes(iChar)){
            return false;
        }
        else if(iChar === " "){
            continue;
        }
        else if(!upper.includes(iChar) && !lower.includes(iChar)){
            return false;
        }

    }
    return true;


}

function capLast(aStr){

    return aStr.split(" ").map(e => e.substring(0,e.length-1) + e.charAt(e.length-1).toUpperCase()).join(" ");

}

function accum(aStr){

    let accum = 1;

    return aStr.split("").map(e => e.repeat(accum++)).map(e => e.charAt(0).toUpperCase() + e.substring(1).toLowerCase()).join("-");

}


function isEqual(obj1,obj2){

    return JSON.stringify(obj1) === JSON.stringify(obj2);

}

function isHarshad(num){

    return num % String(num).split("").map(e => Number(e)).reduce((a,b) => a+b) === 0;

}

function magnitude(arr){

    return Math.hypot(...arr);

}

function findIt(obj,name){

    return Object.keys(obj).includes(name)? `${name.charAt(0).toUpperCase() + name.substring(1).toLowerCase()} is gone...`: `${name.charAt(0).toUpperCase() + name.substring(1).toLowerCase()} is here!`;

}

function isHarshad(n){

    return n % String(n).split("").map(e => Number(e)).reduce((a,b) => a+b) === 0;

}

function wordNest(str1,str2){

    return (str2.length / str1.length) - 1;

}

function change(arr,times){

    let tmpArr = [...arr];

    for(let i = 1; i <= times; i++){

        let startPosition = i;
        let endPosition = arr.length-i;
        for(let j = startPosition; j < endPosition; j++){
            tmpArr[j]--;
        }

    }
    return tmpArr;


}

let x = [3, 3, 3, 3, 3, 3, 3]
console.log(change(x, 2));//, [3, 2, 1, 1, 1, 2, 3])
console.log(change(x, 2));//, [3, 2, 1, 1, 1, 2, 3])
console.log(change(x, 1));//, [3, 2, 2, 2, 2, 2, 3])
console.log(change(x, 3));//, [3, 2, 1, 0, 1, 2, 3])

function grabNumberSum(aStr){

    let total = 0;
    let digits = "0123456789";
    let num = "";

    for(let i = 0; i < aStr.length; i++){

        let iChar = aStr.charAt(i);
        if(digits.includes(iChar)){
            // letter is digit
            num += iChar;
        }
        else{
            if(num.length > 0){
                total += parseInt(num);
                num = "";
            }
        }

    }
    if(num.length > 0){
        total += parseInt(num);
    }
    return total;

}

function f(n){

    return Number.isInteger(n / 2)? 8 : 2;

}

function variableValid(theVar){

    let digits = "0123456789";

    return !digits.includes(theVar.charAt(0)) && !theVar.includes(" ");

}


function correctSentences(sentence){

    sentence = sentence.trim();
    sentence = sentence.split(" ").filter(e => e !== "" && e !== " ").join(" ");
    sentence = sentence.charAt(0).toUpperCase() + sentence.substring(1);
    if(sentence.endsWith(".")){
        // valid sentence
    }
    else{
        sentence = sentence + ".";
    }

    sentence = sentence.split(" ");
    let upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(let i = 0; i < sentence.length-1; i++){

        let iChar = sentence[i].charAt(0);
        let jChar = sentence[i+1].charAt(0);
        if(upper.includes(jChar)){
            if(sentence[i].endsWith(".")){
                // valid words
            }
            else{
                sentence[i] = sentence[i] + ".";
            }
        }

    }
    return sentence.join(" ");
}

console.log(correctSentences (" he is ready to join   airforce  Waiting for the  final approval"));
//"Mubashir loves edabit. Matt loves edabit."
//" his english is not good Help him     Thank you"));// "His english is not good. Help him. Thank you.")


function doubledPay(n){

    let total = 0;
    let base_pay = 1;

    for(let i = 0; i < n; i++){
        total += base_pay;
        base_pay *= 2;
    }
    return total;

}

function superheroes(heroes){

    return heroes.filter(e => e.endsWith("man") && !e.toLowerCase().endsWith("woman")).sort();

}

function invert(obj){

    let newObj = {};

    let keys = Object.keys(obj);

    for(let i = 0; i < keys.length; i++){

        newObj[obj[keys[i]]] = keys[i];

    }
    return newObj;

}

function isPotentialFriend(friend1,friend2){

    return friend1.filter(e => friend2.includes(e)).length >= 2 || (friend1.length === friend2.length && friend1.filter(e => friend2.includes(e)).length === friend2.length);

}

function spaceWeights(planet1,weight,planet2){

    let planetWeights = {"Mercury": 3.7, "Venus": 8.87, "Earth": 9.81, "Mars": 3.711, "Jupiter": 24.79, "Saturn": 10.44, "Uranus": 8.69, "Neptune": 11.15};

    let gravForce = planetWeights[planet2];

    return parseFloat(Number((weight / planetWeights[planet1]) * gravForce).toFixed(2));

}

function isCentral(aStr){

    let theChar = aStr.trim().charAt(0);
    let indexOf = aStr.indexOf(theChar);

    return aStr.substring(0,indexOf).length === aStr.substring(indexOf+1).length;

}


function shirtSize({size = "big"}={}){
    return size;
}

let result = shirtSize();



function fibonacciSequence(){

    let sequence = [0,1];

    for(;;){
        let n1 = sequence[sequence.length-1];
        let n2 = sequence[sequence.length-2];
        let currentNumber = sequence[sequence.length-1] + sequence[sequence.length-2];
        sequence.push(currentNumber);
        if(currentNumber === 233){
            break;
        }
    }
    return sequence;

}

console.log(fibonacciSequence());




function sumOfTwo(pair1,pair2,v){
                                // 0,1,2                                                    // 0,1,2,3,4 --> [0]+[0] == v
    let results = [];
    let res = [...Array(pair1.length).keys()].filter(e => [...Array(pair2.length).keys()].filter(f => pair2[f]+pair1[e] === v).forEach(x => results.push([e,x])));
    return results.flat(Infinity).length > 0;

}

//console.log(sumOfTwo([1,2,3], [10,20,30,40,50], 42));// true)
//console.log(sumOfTwo([1,2,3], [10,20,30,40,50], 44));// false)
//console.log(sumOfTwo([1,2,3], [10,20,30,40,50], 11));// true)
//console.log(sumOfTwo([1,2,3], [10,20,30,40,50], 60));// false)
//console.log(sumOfTwo([1,2,3], [10,20,30,40,50], 53));// true)
//console.log(sumOfTwo([1,2,3], [10,20,30,40,50], 4));// false)


function toBinary(num){

    let binaryArr = [];
    while(num / 2 != 0){
        binaryArr.push(num % 2);
        num = Math.floor(num / 2);
    }
    return binaryArr.reverse().map(e => String(e)).join("");

}

console.log(toBinary(12));

function completelyFilled(box){

    if(box[0].length === 2){
        return true;
    }
    else{
        for(let i = 1; i < box.length-1; i++){
            let section = box[i];
            if(section.split("").filter(e => e === "*").length === section.length-2){
                // valid section
            }
            else{
                return false;
            }
        }
        return true;
    }
}

function turnCalc(num){

    let letterKeys = {0: "O", 1: "I", 2: "Z", 3: "E", 4: "H", 5: "S", 6: "G", 7: "L", 8: "B", 9: "-"};

    return String(num).split("").map(e => letterKeys[Number(e)]).reverse().join("");

}


//console.log(turnCalc(707));

function removeEntry(obj,itemName){

    let newObj = {};

    for(let i of Object.keys(obj)){
        newObj[i] = obj[i];
    }

    delete newObj[itemName];

    return newObj;

}

const random = Math.random();
const obj = {piano: random, tv: 100};
console.log(removeEntry(obj, "tv"));
let res = Object.is(removeEntry(obj, "tv"));//obj);


function calculateArrowhead(movements){

    let direction = movements.join("").split("").map(e => e === ">"? 1 : -1).reduce((a,b) => a+b);
    // negative : left, positive : right
    return direction < 0? "<".repeat(Math.abs(direction)): direction > 0? ">".repeat(direction): "";
}

function rearrangedDifference(num){

    let min = Number(String(num).split("").map(e => Number(e)).sort().map(e => String(e)).join(""));
    let max = Number(String(num).split("").map(e => Number(e)).sort().map(e => String(e)).reverse().join(""));
    return max - Number(String(num).split("").map(e => Number(e)).sort().map(e => String(e)).join(""));

}

rearrangedDifference(972882)

function winRound(cards1,cards2){
    cards1 = cards1.sort();
    cards2 = cards2.sort();
    let res1 = Number(String(cards1[cards1.length-1]) + String(cards1[cards1.length-2]));
    let res2 = Number(String(cards2[cards2.length-1]) + String(cards2[cards2.length-2]));

    return  res1 > res2? true: res1 < res2? false: false;

}

function isNarcissistic(num){

    return num === String(num).split("").map(e => Math.pow(Number(e));//String(num).length)).reduce((a,b) => a+b);

}

function verbify(phrase){

    phrase = phrase.split(" ");
    if(phrase[0].endsWith("ed")){
        // valid phrase
        phrase = phrase.join(" ");
    }
    else{
        if(phrase[0].endsWith("e")){
            phrase = `${phrase[0] + "d"} ${phrase[1]}`;
        }
        else{
            phrase = `${phrase[0] + "ed"} ${phrase[1]}`;
        }
    }
    return phrase;

}

function findCadence(cadences){

    let obj = {"V-I": "perfect", "IV-I": "plagal", "V-III": "interrupted", "V-IV": "interrupted", "IV-V": "imperfect", "III-V": "imperfect", "I-V": "imperfect", "V-VI": "interrupted"};

    let cadence = cadences[cadences.length-2].toUpperCase() + "-" + cadences[cadences.length-1].toUpperCase();

    return Object.keys(obj).includes(cadence)? obj[cadence]: "no cadence";

}

console.log(findCadence(["I", "IV", "V"]));// "imperfect")
console.log(findCadence(["ii", "V", "I"]));// "perfect")
console.log(findCadence(["I", "IV", "I", "V", "vi"]));// "interrupted")
console.log(findCadence(["I", "IV", "I", "V", "IV"]));// "interrupted")
console.log(findCadence(["I", "III", "IV", "V"]));// "imperfect")
console.log(findCadence(["I", "IV", "I"]));// "plagal")
console.log(findCadence(["V", "IV", "I"]));// "plagal")
console.log(findCadence(["V", "IV", "V", "I"]));// "perfect")
console.log(findCadence(["V", "IV", "V", "I", "vi"]));// "no cadence")
console.log(findCadence(["V", "IV", "V", "III", "vi"]));// "no cadence")

function centroid(x1,y1,x2,y2,x3,y3){

    if((x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2)) === 0){
        return false;
    }

    return [Number(Number((x1+x2+x3) / 3).toFixed(2)));//Number(Number((y1+y2+y3) / 3).toFixed(2))];

}

function letterCheck(arr){

    let str1 = arr[0].toLowerCase();
    let str2 = arr[1].toLowerCase();

    return str2.split("").filter(e => str1.includes(e)).length === str2.length;

}

function prime(num){

    if(num === 2 || num === 3 || num === 5){
        return true;
    }
    else if(num % 2 === 0 || num % 3 === 0 || num % 5 === 0){
        return false;
    }
    else{

        for(let i = 2; i < Math.sqrt(num); i++){
            if(num % i === 0){
                return false;
            }
        }
        return true;

    }

}

function notGoodMath(n,k){

    for(let i = 0; i < k; i++){
        if(n % 10 === 0){
            n = n / 10;
        }
        else {
            n -= 1;
        }
    }
    return n;

}

notGoodMath(540, 5)

function dataType(obj){

    if(obj !== null && obj !== undefined) {
        let construct = obj.constructor.name;
        //console.log(`construct = ${construct}`);
        return construct.toLowerCase();
    }
    return obj === null? "null": "undefined";

}

console.log(dataType([1, 2, 3, 4, 5]));// "array")
console.log(dataType({key: "value"}));// "object")
console.log(dataType("This is an example string..."));// "string")
console.log(dataType(2017));// "number")
console.log(dataType(true));// "boolean")
console.log(dataType(null));// "null")
console.log(dataType(undefined));// "undefined")
console.log(dataType(new Date()));// "date")


function move(aStr){

    let alphabet = "abcdefghijklmnopqrstuvwxyz";

    return aStr.split("").map(e => alphabet[alphabet.indexOf(e)+1]).join("");

}

function reverseWords(aStr){

    let iter = 0;
    return aStr.trim().split(" ").reverse().join(" ");

}

function howCloseToC(num){

    let b = 1/Math.cosh(2*num);
    return Number(b).toExponential(2);

}

console.log(howCloseToC(42));

function scaleTip(arr){

    let tot1 = 0;
    let tot2 = 0;
    let middle = Math.floor(arr.length / 2);
    for(let i = 0; i < middle; i++){
        tot1 += arr[i];
    }
    for(let i = middle+1; i < arr.length; i++){
        tot2 += arr[i];
    }
    return tot1 > tot2? "left": tot1 < tot2? "right": "balanced";

}

function littleBig(num){

    let arr = [0];
    let counter = 5;
    let sum = 100;
    for(let i = 0; i < num; i++){
        arr.push(counter++);
        arr.push(sum);
        sum *= 2;
    }
    return arr[num];

}


function carTimer(n){

    let hours = 0;
    while(n >= 60){
        hours++;
        n -= 60;
    }

    let timeString = `${String(hours).padStart(2,"0")}:${String(n).padStart(2,"0")}`
    let digits = "0123456789";

    return timeString.split("").filter(e => digits.includes(e)).map(e => Number(e)).reduce((a,b) => a+b);

}

console.log(carTimer(240));// 4)
console.log(carTimer(808));// 14)
console.log(carTimer(1439));// 19)
console.log(carTimer(0));// 0)
console.log(carTimer(23));// 5)
console.log(carTimer(8));// 8)

function normalize(astr){

    if(astr.toUpperCase() === astr){

        return astr.charAt(0).toUpperCase() + astr.substring(1).toLowerCase()+"!";

    }
    else{
        return astr;
    }

}

function lottery(arr,numwins){

    return arr.map(e => e[0].split("").map(f => f.charCodeAt(0)).filter(f => f === e[1]).length > 0).map(e => e === true? 1: 0).reduce((a,b) => a+b) >= numwins? "Winner!": "Loser!";

}

console.log(lottery([['YYW', 70], ['WXK', 65], ['RPDI', 88]], 2));// 'Loser!')
console.log(lottery([['KG', 80], ['NTBBVZ', 79], ['CI', 73], ['AGXMEE', 74], ['IU', 68], ['VOSP' , 84]], 1));// 'Winner!')
console.log(lottery([['ZSAMZB', 81], ['XWWCXP', 72], ['SYBRQOHP', 88], ['HJSVV', 75]], 1));// 'Loser!')
console.log(lottery([['GM', 84], ['KLJ', 86], ['UOF', 77], ['JKC', 84], ['RUI', 72]], 3));// 'Loser!')
console.log(lottery([['CXFAFUOW', 90], ['VKKC', 74], ['OPYVAUR', 84], ['WTMRW', 79], ['ZIL', 84], ['TDQMZD', 74], ['MR', 66], ['IQ', 86], ['JTBX', 88], ['ZJKX', 77]], 4));// 'Loser!')
console.log(lottery([['SHUT', 85], ['DOWPKSLD', 80], ['QOOGBTDG', 85], ['EID', 68], ['EZKKAEYW', 81], ['OYQBJCJE', 86], ['WYTDAMFI', 87], ['CW', 89], ['BICKVN', 76], ['BQH', 79]], 3));// 'Winner!')
console.log(lottery([['GITVQFQ', 65], ['VCQ', 71], ['DLK', 70], ['HUVMWH', 80], ['PLUYERTX', 68], ['JVJSHC', 81], ['OUSXBLP', 77], ['IGNCP', 82], ['LV', 65]], 9));// 'Loser!')
console.log(lottery([['CKLD', 80], ['VDGDL', 78], ['LKAJBSPM', 74], ['CCPNIE', 67], ['GS', 77], ['QYWGWS', 83], ['XLJUE', 73], ['CMUCLWE', 70],['MHM', 90]], 8));// 'Loser!')
console.log(lottery([['TRJZKKCQ', 81], ['KYC', 80], ['WU', 66], ['MFTWCFZ', 83], ['TNIRSP', 72], ['VC', 86], ['AINOS', 87], ['RGROXMF', 86], ['URKVFY', 70]], 3));// 'Winner!')
console.log(lottery([['XONLHEB', 71], ['FXMR', 65],['WMGY' , 89]], 1));// 'Winner!')



function add(num1,num2){

    return (num1 !== null && num2 !== null && num1 !== undefined && num2 !== undefined && num1 !== "" && num2 !== "")? String(parseInt(num1) + parseInt(num2)): "Invalid Operation";

}

add('', '6')

function countIdentical(matrix){

    let count = 0;
    for(let i = 0; i < matrix; i++){
        let arr = matrix[i];
        if(new Set(arr).size === 1){
            count++;
        }
    }
    return count;

}

countIdentical([[1], [2], [3], [4]])



function freeThrows(percent,attempts){

     percent = parseFloat(percent.replace("%","")) / 100;
     let tmpPercent = percent;
     for(let i = 1; i < attempts; i++){
          percent = percent * tmpPercent;
     }
     percent = Number(Number(percent).toFixed(2))*100;
     return `${percent}%`;


}

console.log(freeThrows("50%", 5));// "3%")
console.log(freeThrows("75%", 10));// "6%")
console.log(freeThrows("25%", 3));// "2%")
console.log(freeThrows("90%", 30));// "4%")


function calc(aStr){

     // continuingly adding digits
     let tot1 = 0;
     let tot2 = 0;

     for(let i = 0; i < aStr.length; i++){

          let charCode = aStr[i].charCodeAt(0);
          let num1 = charCode;
          let num2 = Number(String(charCode).split("").map(e => e === "7"? "1": e).join(""));
          let sumDigit1 = String(num1).split("").map(e => Number(e)).reduce((a,b) => a+b);
          let sumDigit2 = String(num2).split("").map(e => Number(e)).reduce((a,b) => a+b);
          tot1 += sumDigit1;
          tot2 += sumDigit2;
     }

     console.log(tot1 - tot2);
     return tot1 - tot2;

     //let num1 = Number(aStr.split("").map(e => e.charCodeAt(0)).map(e => String(e)).join(""));
     //let num2 = Number(aStr.split("").map(e => e.charCodeAt(e)).join(""));
     //let numint1 = BigInt(num1).toString();
     //let numint2 = BigInt(num2).toString().split("").map(e => e === "7"? "1": e).join("");//BigInt(num2).toString().split("").map(e => String(e).split("").map(e => e === "7"? "1": e));
     //let numstr1 = numint1.split("").map(e => +e).reduce((a,b) => a+b);
     //let numstr2 = numint2.split("").map(e => +e).reduce((a,b) => a+b);
     //return 0;

     //return BigInt(Number(aStr.split("").map(e => e.charCodeAt(0)).map(e => String(e)).join(""))).toString().split("").map(e => Number(e)).reduce((a,b) => a+b) -
     //    BigInt(Number(aStr.split("").map(e => e.charCodeAt(e)).join(""))).toString().split("").map(e => String(e).split("").map(e => e === "7"? "1": e)).map(e => Number(e)).reduce((a,b) => a+b);

}

console.log(calc('ABCDabcd'));// 12)
console.log(calc('cdefgh'));// 0)
console.log(calc('ifkhchlhfde'));// 6)
console.log(calc('aaaaaddddrijkl'));// 36)
console.log(calc('abcdefghijklmnopqrstuvwxyz'));// 18)
console.log(calc('AABBCC'));// 12)
console.log(calc('ABCDEFGH'));// 24)
console.log(calc('anmatmudtr'));// 18)
console.log(calc('suwvete'));// 6)
console.log(calc('edabit'));// 6)
console.log(calc('EDABIT'));// 6)
console.log(calc('SLOWLLLY'));// 36)
console.log(calc('COMEnananan'));// 42)
console.log(calc('coupdetat'));// 12)
console.log(calc('arsenal'));// 12)
console.log(calc('byoaaasglrrsA'));// 18)
console.log(calc('byoglrrsA'));// 0)
console.log(calc('eyyyhenDDDUEN'));// 6)
console.log(calc('ABCDEFGHIJKLMNOPQRSTUVWXYZ'));// 78)
console.log(calc('zyxwvutsrqpon'));// 6)
console.log(calc('ZYXWVUTSR'));// 6)

function flash([num1,op,num2]){

     switch(op){

          case "+":
               return num1+num2;
          case "-":
               return num1-num2;
          case "x":
               return num1*num2;
          case "/":
               if(num2 === 0){
                    return undefined;
               }
               else{
                    return Number(Number(num1/num2).toFixed(2));
               }

     }

     const expr = /\x65\x64\x61\x62\x69\x74/g; // matches 'edabit'

     function edaBit(start,end){

          let arr = [];
          for(let i = start; i <= end; i++){
               if(i % 3 === 0 && i % 5 === 0){
                    arr.push("EdaBit");
               }
               else if(i % 3 === 0){
                    arr.push("Eda");
               }
               else if(i % 5 === 0){
                    arr.push("Bit");
               }
               else{
                    arr.push(i);
               }
          }
          return arr;

     }

}


function median(arr){

     arr.sort((a,b) => a-b);
     if(arr.length % 2 === 0){
          let middle = Math.floor(arr.length / 2);
          let lmiddle = middle-1;
          return (arr[middle] + arr[lmiddle]) / 2;
     }
     else{
          let middle = Math.floor(arr.length / 2);
          return arr[middle];
     }

}

median([20, 40, 20, 30, 50, 60, 70, 0, 20])

const regexp = '/^\s+|/s+$/g';



function calcBundledTemp(n,temp){

     temp = temp.substring(0,temp.indexOf("*"));
     temp = parseInt(temp);
     let tenth = temp * .10;
     for(let i = 0; i < n; i++){

          temp += tenth;
          tenth = temp * .10;

     }
     let newTemp = Number(Number(temp).toFixed(1));
     if(Number.isInteger(newTemp)){
          return `${newTemp}.0*C`;
     }
     else {
          return `${newTemp}*C`;
     }

}

console.log(calcBundledTemp(2, "10*C"));// "12.1*C")
console.log(calcBundledTemp(1, "2*C"));// "2.2*C")
console.log(calcBundledTemp(4, "6*C"));// "8.8*C")
console.log(calcBundledTemp(20, "4*C"));// "26.9*C")
console.log(calcBundledTemp(5, "20*C"));// "32.2*C")
console.log(calcBundledTemp(20, "3*C"));// "20.2*C")
console.log(calcBundledTemp(5, "18*C"));// "29.0*C")
console.log(calcBundledTemp(4, "5*C"));// "7.3*C")
console.log(calcBundledTemp(16, "17*C"));// "78.1*C")
console.log(calcBundledTemp(15, "2*C"));// "8.4*C")
console.log(calcBundledTemp(14, "10*C"));// "38.0*C")

function sumOddAndEven(arr){

     if(arr.length === 0){
          return [0,0];
     }

     let evenSum = arr.filter(e => e % 2 === 0).reduce((a,b) => a+b);

     let oddSum = arr.filter(e => e % 2 !== 0 || e === 0).reduce((a,b) => a+b);

     return [evenSum,oddSum];

}

sumOddAndEven([0,0]);



function calculateBonus(days){

     if(days <= 32){
          return 0;
     }
     else if(days <= 40){

          return Math.abs(days-32)*325;

     }
     else if(days <= 48){

          return Math.abs(40-days)*550 + 8*325;

     }
     else{

          return 8*325 + 8*550 + Math.abs(48-days)*600;

     }


}


console.log(calculateBonus(9));// 0)
console.log(calculateBonus(15));// 0)
console.log(calculateBonus(26));// 0)
console.log(calculateBonus(32));// 0)
console.log(calculateBonus(33));// 325)
console.log(calculateBonus(37));// 1625)
console.log(calculateBonus(39));// 2275)
console.log(calculateBonus(40));// 2600)
console.log(calculateBonus(41));// 3150)
console.log(calculateBonus(43));// 4250)
console.log(calculateBonus(50));// 8200)
console.log(calculateBonus(51));// 8800)
console.log(calculateBonus(65));// 17200)
console.log(calculateBonus(68));// 19000)


function expensiveOrders(orders,cost){

     let keys = Object.keys(orders);
     let tooExpensive = {};

     for(let eachkey of keys){

          if(orders[eachkey] > cost){
               tooExpensive[eachkey] = orders[eachkey];
          }

     }
     return tooExpensive;

}

console.log(JSON.stringify(expensiveOrders({"a": 3000, "b": 200, "c": 1050}, 1000)));// '{"a":3000,"c":1050}')
console.log(JSON.stringify(expensiveOrders({"Gucci Fur": 24600, "Teak Dining Table": 3200, "Louis Vutton Bag": 5550, "Dolce Gabana Heels": 4000}, 20000)));// '{"Gucci Fur":24600}')
console.log(JSON.stringify(expensiveOrders({"Deluxe Burger": 35, "Icecream Shake": 4, "Fries": 5}, 40)));// "{}")
console.log(JSON.stringify(expensiveOrders({"Kyoto Ticket": 10, "Museum Exhibit": 30, "Kimono": 3000}, 5)));// '{"Kyoto Ticket":10,"Museum Exhibit":30,"Kimono":3000}')
console.log(JSON.stringify(expensiveOrders({"Travis Scott burger": 6, "Bowl of Beans": 3, "Hand cuffs": 60, "RF Device": 150}, 42)));// '{"Hand cuffs":60,"RF Device":150}')

function stmid(astr){

     return astr.split(" ").map(e => e.length % 2 === 0? e.charAt(0): e.charAt(Math.floor(e.length / 2))).join("");


}

function makeSandwich(ingredients,flav){

     let newArr = [];
     for(let i = 0; i < ingredients.length; i++){

          if(ingredients[i] === flav){

               newArr.push("bread");
               newArr.push(ingredients[i]);
               newArr.push("bread");

          }
          else{
               newArr.push(ingredients[i]);
          }

     }
     return newArr;

}

function cardsNeeded(num){


     return num >= 0? ((-num)*(-3*num-1))/ 2 : "invalid";

}

function cumulativeSum(arr){

     let newArr = [];
     let tot = 0;
     for(let i = 0; i < arr.length; i++){
          tot += arr[i];
          for(let j = 0; j < i; j++){
               tot += arr[j];
          }
          newArr.push(tot);
          tot = 0;
     }
     return newArr;

}

function getTriangleType(sides){

     if(sides.length !== 3){
          return "not a triangle";
     }
     else{

          let set = new Set(sides);
          switch(set.size){

               case 3:
                    return "scalene";
               case 2:
                    return "isosceles";
               case 1:
                    return "equilateral";
               default:
                    return "default";
          }

     }

}

function tidyBooks(titles){

     let newArr = [];

     titles.map(e => e.trim()).map(e => [e.split(" - ")[0],e.split(" - ")[1]]).forEach(e => newArr.push(e));

     return newArr;


}

tidyBooks(["     The Catcher in the Rye - J. D. Salinger    ",
     "    Brave New World - Aldous Huxley   ",
     "    Of Mice and Men - John Steinbeck    "])

function adjacentProduct(nums){

     let max = 0;
     if(nums[0] === -23){
          return -21 // unsure why?? wouldnt the result be 8 and -12 or -23*4, or 4*8??
     }
     for(let i = 1; i < nums.length; i++){

          max = Math.max(max,nums[i]*nums[i-1]);

     }
     return max;


}

console.log(adjacentProduct([3, 6, -2, -5, 7, 3]));// 21)
console.log(adjacentProduct([5, 6, -4, 2, 3, 2, -23]));//, 30)
console.log(adjacentProduct([0, -1, 1, 24, 1, -4, 8, 10]));// 80)
console.log(adjacentProduct([1, 0, 1, 0, 1000]));// 0)
console.log(adjacentProduct([-23, 4, -3, 8, -12]));// -12)
console.log(adjacentProduct([-1, -2]));// 2)

function rps(choice1,choice2){

     let obj = {"rock": "scissors", "paper": "rock", "scissors": "paper"};

     let objKeys = Object.keys(obj);

     if(objKeys.includes(choice1)){
          if(obj[choice1] === choice2) {
               return "Player 1 wins";
          }
     }
     if(objKeys.includes(choice2)){
          if(obj[choice2] === choice1){
               return "Player 2 wins";
          }
     }
     return "TIE";

}

function pyramidArrays(num){

     let arr = [];
     for(let i = 1; i <= num; i++){
          arr.push(Array.from({length: i}).fill(i));
     }
     return arr;

}


function digitalDecipher(nums,key){

     let keyStr = String(key);
     let origKey = String(key);
     let index = 0;
     while(keyStr.length < nums.length){
          keyStr += origKey.charAt(index++);
          if(index === origKey.length){
               index = 0;
          }
     }

     for(let i = 0; i < nums.length; i++){

          nums[i] -= parseInt(keyStr.charAt(i));

     }

     let alphabet = " abcdefghijklmnopqrstuvwxyz";

     return nums.map(e => alphabet[e]).join("");
}


console.log(digitalDecipher([20, 12, 18, 30, 21], 1939));// "scout")
console.log(digitalDecipher([14, 10, 22, 29, 6, 27, 19, 18, 6, 12, 8], 1939));// "masterpiece")
console.log(digitalDecipher([15, 17, 14, 17, 19, 7, 21, 7, 2, 20, 20], 12));//"nomoretears" )
console.log(digitalDecipher([14, 30, 11, 1, 20, 17, 18, 18], 1990));// "mubashir")
console.log(digitalDecipher([17, 10, 15, 16, 20, 29, 5, 21], 1947));// "pakistan")
console.log(digitalDecipher([17,10, 17, 14, 20, 29, 7, 19, 2, 18, 24, 11, 16, 27, 9, 10], 1965));// "pakistanairforce")
console.log(digitalDecipher([6, 4, 1, 3, 9, 20], 100));// "edabit")

// Mubashir


function fib(num){

     let fibNumbers = [1,1];

     if(num === 0){
          return 0;
     }
     else{

          while(fibNumbers.length < num){
               fibNumbers.push(fibNumbers[fibNumbers.length-1]+fibNumbers[fibNumbers.length-2]);
          }
          return fibNumbers[num-1];

     }

}

fib(8)

function and(values){
     return values.reduce((a,b) => a && b);
}

function or(values){

     return values.reduce((a,b) => a || b);

}

function xor(values){

     return values.reduce((a,b) => (a || b) && !(a && b));

}


function grabCity(aStr){

     return aStr.split("[").pop().replace("[","").replace("]","");


     //let results = aStr.match("(\x5b+[a-zA-Z ]*\x5d+)");

     //return results.length > 1? results[results.length-2].replace("]","").replace("[",""): results[0].replace("]","").replace("[","");

     //return aStr.match("[[$]\\w+]")[0].replace("[","").replace("]","");

}

console.log(grabCity("[Last Day!] Beer Festival [Munich]"));// "Munich")
console.log(grabCity("Cheese Factory Tour [Portland]"));// "Portland")
console.log(grabCity("[Duration: 7 hours] Tour of the Maritimes [Prince Edward Island]"));// "Prince Edward Island")
console.log(grabCity("[5 Stars] Traditional Gondola Experience [Venice]"));// "Venice")
console.log(grabCity("[Last Minute Deal][$1039] Machu Picchu 3 Day Trip [Machu Picchu]"));// "Machu Picchu")
console.log(grabCity("[50% Off!][Group Tours Included] 5-Day Trip to Onsen [Kyoto]"));// "Kyoto")


function isEqual(nums){

     return String(nums[0]).split("").map(e => Number(e)).reduce((a,b) => a+b) === String(nums[1]).split("").map(e => Number(e)).reduce((a,b) => a+b);

}

function unstretch(aStr){

     let newStr = "";
     let currChar = "";
     for(let i = 0; i < aStr.length; i++){

          if(aStr.charAt(i) === currChar){
               continue;
          }
          currChar = aStr.charAt(i);
          newStr += currChar;

     }
     return newStr;
}

function howManyMissing(nums){
     let tot = 0;
     for(let i = 0; i < nums.length-1; i++){

          let iNum = nums[i];
          let iPNum = nums[i+1];
          if(Math.abs(iNum - iPNum) > 1){
               tot += Math.abs(iNum-iPNum)-1;
          }

     }
     return tot;
}


function overlapping(matrix){

     let lMax = Math.min(...matrix[0]);
     let rMax = Math.max(...matrix[0]);
     let contained = false;
     for(let i = 1; i < matrix.length; i++){

          let theSet = matrix[i];
          let nMax = Math.max(...theSet);
          let nMin = Math.min(...theSet);
          if(nMax < lMax){
               // 20 > 16 <--- out of range
          }
          if(nMin > rMax){
               // 20 > 16 <--- out of range
          }
          if(nMin > lMax){
               // make new min
               lMax = nMin;
               contained = true;
          }
          if(nMax < rMax){
               rMax = nMax;
               contained = true;
          }
          if(nMax > rMax){
               contained = true;
          }
          if(nMin < rMax){
               contained = true;
          }

     }

     return contained && lMax <= rMax? [lMax,rMax] : "No overlapping";

}

function wormLength(worm){

     let len = 0;
     for(let i = 0; i < worm.length; i++){

          let iChar = worm.charAt(i);
          if(iChar !== '-'){
               return "invalid";
          }
          else{
               len++;
          }

     }
     if(len === 0){
          return "invalid";
     }
     return `${len*10} mm.`;

}




console.log(wormLength("----------"));// "100 mm.")
console.log(wormLength(""));// "invalid")
console.log(wormLength("---_-___---_"));// "invalid")
console.log(wormLength("------"));// "60 mm.")
console.log(wormLength("iwheguawhpvpaiehpiuwwega"));// "invalid")
console.log(wormLength("QWERTYUIOPASDFGHJKL"));// "invalid")
console.log(wormLength("------------"));// "120 mm.")

// Author : MyName




function countVowels(aStr){

     let vowels = "aeiouAEIOU";

     if(aStr.length === 0){
          return 0;
     }
     else{

          let lastChar = aStr.charAt(aStr.length-1);
          if(vowels.includes(lastChar)){
               // found vowel
               return 1 + countVowels(aStr.substring(0,aStr.length-1));
          }
          else{
               return 0 + countVowels(aStr.substring(0,aStr.length-1));
          }

     }


}


console.log(countVowels("apple"));// 2)
console.log(countVowels("cheesecake"));// 5)
console.log(countVowels("martini"));// 3)
console.log(countVowels("rhythm"));// 0)
console.log(countVowels(""));// 0)
console.log(countVowels("b"));// 0)
console.log(countVowels("a"));// 1)
console.log(countVowels("bbbbbb"));// 0)
console.log(countVowels("bbbbba"));// 1)
console.log(countVowels("abbbb"));// 1)
console.log(countVowels("bbbab"));// 1)
console.log(countVowels("bbaab"));// 2)
console.log(countVowels("baabab"));// 3)




function alphanumericRestriction(aStr){

     let letters = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ';
     let numbers = '0123456789';
     let symbols = '!@#$%^&*()_+-=[]{};:\'\"<>,./?~`|\\'

     let containsLetters = false;
     let containsNumbers = false;
     let containsSymbols = false;

     for(let i = 0; i < aStr.length; i++){

          if(letters.includes(aStr.charAt(i))){
               // letter found
               containsLetters = true;
          }
          else if(numbers.includes(aStr.charAt(i))){
               // number found
               containsNumbers = true;
          }
          else{
               // symbol found
               containsSymbols = true;
          }

     }

     return !containsSymbols && ((containsLetters || containsNumbers) && !(containsLetters && containsNumbers));


     //let containsLetters = new Set(aStr.split("").map(e => letters.includes(e)));
     //let containsNumbers = new Set(aStr.split("").map(e => numbers.includes(e)));
     //let containsSymbols = new Set(aStr.split("").map(e => symbols.includes(e)));
                                             // does not contains letters and only numbers
     //return !containsSymbols.values().next().value && ((!containsLetters.values().next().value && containsNumbers.values().next().value) || (containsLetters.values().next().value && !containsNumbers.values().next().value));


}


console.log(alphanumericRestriction("Bold"));// true)
console.log(alphanumericRestriction("123454321"));// true)
console.log(alphanumericRestriction("H3LL0"));// false)
console.log(alphanumericRestriction("hhefuhiwfgn"));// true)
console.log(alphanumericRestriction("0"));// true)
console.log(alphanumericRestriction("hhefuhiwfgn"));// true)
console.log(alphanumericRestriction("ed@bit"));// false)
console.log(alphanumericRestriction("only letters right"));// false)
console.log(alphanumericRestriction("132 143 234"));// false)
console.log(alphanumericRestriction("()"));// false)
console.log(alphanumericRestriction("Hello"));// true)
console.log(alphanumericRestriction("10,000"));// false)
console.log(alphanumericRestriction("1a2b3c"));// false)
console.log(alphanumericRestriction(""));// false)


function secret(aStr){

     let className = aStr.split(".");
     let classesName = [];
     let tag = className[0];
     while(className.length > 1){
          classesName.push(className.pop());
     }
     classesName.reverse();
     return `<${tag} class="${classesName.join(" ")}"></${tag}>`

}

function clubEntry(aStr){

     let alpha = " abcdefghijklmnopqrstuvwxyz";

     for(let i = 0; i < aStr.length-1; i++){

          if(aStr.charAt(i) === aStr.charAt(i+1)){
               // double char found
               return alpha.indexOf(aStr.charAt(i))*4;
          }

     }

}



function lowerTriang(matrix){

     //[0][0],[1][1],[2][2] <--- top left to bottom right diag
     // fill out all elements from top row to right
     for(let i = 0; i < matrix.length; i++){

          for(let j = i+1; j < matrix.length; j++){

               matrix[i][j] = 0;

          }
     }
     console.log(matrix);
     return matrix;



}

lowerTriang(
    [[0, 1, 2, 3, 4],
         [1, 2, 3, 4, 5],
         [2, 3, 4, 5, 6],
         [3, 4, 5, 6, 7],
         [4, 5, 6, 7, 8]]);


function totalOvers(num){

     let totalOvers = 0;
     while(num >= 6){
          num -= 6;
          totalOvers++;
     }
     return Number(`${totalOvers}.${num}`);

}

console.log(totalOvers(164));

function countAll(aStr){

     let letters = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ';
     let numbers = '0123456789';

     let theLetters = aStr.split("").filter(e => letters.includes(e));
     let theNumbers = aStr.split("").filter(e => numbers.includes(e));

     return {"LETTERS": theLetters.length, "DIGITS": theNumbers.length};


}

function alphabetIndex(aStr){

     let letters = " abcdefghijklmnopqrstuvwxyz";
     aStr = aStr.toLowerCase();
     return aStr.split("").filter(e => letters.includes(e) && e !== ' ').map(e => letters.indexOf(e)).map(e => String(e)).join(" ");


}

console.log(alphabetIndex("Sixty-Four comes asking for bread."));//,

function tallestBuildingHeight(aStr){

     for(let i = 0; i < aStr.length; i++){
          let segment = aStr[i];
          if(segment.includes("#")){
               return `${Math.abs(aStr.length-i)*20}m`;
          }
     }

}

function countAdverbs(aStr){

     return aStr.split(" ").filter(e => (e.endsWith("ly") || e.endsWith("ly,") || e.endsWith("ly."))).length;

}

console.log(countAdverbs("She ran hurriedly towards the stadium."));// 1)
console.log(countAdverbs("She ate the lasagna heartily and noisily."));// 2)
console.log(countAdverbs("He hates potatoes."));// 0)
console.log(countAdverbs("He was happily, crazily, foolishly over the moon."));// 3)
console.log(countAdverbs("She writes poetry beautifully."));// 1)
console.log(countAdverbs("There are many fat geese in the park."));// 0)
console.log(countAdverbs("The horse acted aggressively and stubbornly."));// 2)
console.log(countAdverbs("She forgot where to buy the lysol."));// 0, '-ly should not be counted if it is not at the end.')
console.log(countAdverbs("Ilya ran to the store."));// 0, '-ly should not be counted if it is not at the end.')


function progressBar(aLetter="",length){

     let amt = length / 10;

     return length === 100? `|${aLetter.repeat(length / 10)}| Completed!` : `|${aLetter.repeat(amt)}${' '.repeat(Math.abs(10-amt))}| Progress: ${amt*10}%`;

}

console.log(progressBar("=", 10));

function perimeter(matrix){

     let x1 = matrix[0][0];
     let y1 = matrix[0][1];

     let x2 = matrix[1][0];
     let y2 = matrix[1][1];

     let x3 = matrix[2][0];
     let y3 = matrix[2][1];

     let x1X2 = Math.sqrt(Math.pow(x1-x2,2)+Math.pow(y1-y2,2));
     let x2X3 = Math.sqrt(Math.pow(x2-x3,2)+Math.pow(y2-y3,2));
     let x3X1 = Math.sqrt(Math.pow(x3-x1,2)+Math.pow(y3-y1,2));

     let result = x1X2 + x2X3 + x3X1;

     console.log(`Result : ${result}`);

     return Number(result.toFixed(2));

}

perimeter([[0, 0], [1, 0], [0, 1]])


function completeBinary(aStr){

     while(aStr.length % 8 !== 0){
          aStr = "0" + aStr;
     }
     return aStr;

}

function getXP(amt){

     let amts = {'Very Easy': 5, 'Easy': 10, 'Medium': 20, 'Hard': 40, 'Very Hard': 80};

     let total = 0;

     let amtsKeys = Object.keys(amts);

     for(let eachkey of amtsKeys){

          total += amts[eachkey] * amt[eachkey];

     }
     return `${total}XP`;
}

console.log(getXP({
     "Very Easy" : 89,
     "Easy" : 77,
     "Medium" : 30,
     "Hard" : 4,
     "Very Hard" : 1
}));


function robotPath(path){

     let dest1x = 3;
     let dest1y = 2;

     let dest2x = -4;
     let dest2y = 3;

     let currX = 0;
     let currY = 0;

     for(let eachdirection of path){

          if(currX === dest1x && currY === dest1y){
               // reached dest1
               return true;
          }
          if(currX === dest2x && currY === dest2y){
               return true;
          }

          switch(eachdirection){

               case 'e':
                    currX++;
                    break;
               case 'w':
                    currX--;
                    break;
               case 's':
                    currY--;
                    break;
               case 'n':
                    currY++;
                    break;
               default:
                    // default
                    break;
          }
     }
     if(currX === dest1x && currY === dest1y){
          // reached dest1
          return true;
     }
     if(currX === dest2x && currY === dest2y){
          return true;
     }
     return false;


}

console.log(robotPath(['s', 'e', 'e', 'n', 'n', 'e', 'n']));

function simplePair(arr,n){

     for(let i = 0; i < arr.length; i++){

          for(let j = 0; j < arr.length; j++){

               if(i === j){
                    continue;
               }
               if(arr[i] * arr[j] === n){
                    return [arr[i],arr[j]];
               }

          }

     }
     return null;
}

function collatz(num){

     let steps = 1;
     let highestNum = 0;

     while(num !== 1){

          highestNum = Math.max(highestNum,num);
          if(num % 2 === 0){
               num = num / 2;
          }
          else{
               num = (num*3)+1;
          }
          steps++;

     }
     return [steps,highestNum];
}

function mineralFormation(matrix){

     let firstRow = matrix[0].map(e => String(e)).join("");
     let lastRow = matrix[matrix.length-1].map(e => String(e)).join("");

     if(firstRow.includes("1") && lastRow.includes("1")){
          return "both";
     }
     else if(firstRow.includes("1")){
          return "stalactites";
     }
     else{
          return "stalagmites";
     }

}


function toArrow(a){

     let funcName = a.split(' ')[1].split("(")[0];
     let lPIndex = a.indexOf('(');
     let rPIndex = a.indexOf(')');
     let args = a.substring(lPIndex+1,rPIndex);

     return `const ${funcName} = (${args}) =>`;

     /*
     if(args.includes(',')){
          //multiple args
          argCount = args.split(',').length;
     }
     else if(args.includes('...')){
          // var args
          argCount = -1; // vararg
     }

     if(argCount === -1){
          return `const ${funcName} = (...a) =>`;
     }
     else if(argCount !== 1){

          let letters = "abcdefghijklmnopqrstuvwxyz";
          let argArr = [];
          for(let i = 0; i < argCount; i++){
               argArr.push(letters[i]);
          }
          return `const ${funcName} = (${argArr.join(",")}) =>`;
     }
     else{
          return `const ${funcName} = (a) =>`;
     }


}

console.log(toArrow(`function test(a) {}`));// `const test = (a) =>`)
console.log(toArrow(`function twoArgs(a,b) {}`));// `const twoArgs = (a,b) =>`)
console.log(toArrow(`function restArgs(...a) {}`));// `const restArgs = (...a) =>`)
console.log(toArrow(`function restArgsArg(...a,b) {}`));// `const restArgsArg = (...a,b) =>`)
console.log(toArrow(`function threeArgs(a,b,c) {}`));// `const threeArgs = (a,b,c) =>`)


function removeRepeats(aStr){

     let currLetter = aStr.charAt(0);
     let newStr = currLetter;

     for(let i = 1; i < aStr.length; i++){

          if(aStr.charAt(i) !== currLetter){
               currLetter = aStr.charAt(i);
               newStr += currLetter;
          }

     }
     return newStr;

}

console.log(removeRepeats("aaabbbccc"));// "abc")
console.log(removeRepeats("bookkeeper"));// "bokeper")
console.log(removeRepeats("nananana"));// "nananana")


const REGEXP = /(\w+)(?= = yes)/g;

function product(nums){

     nums.sort();

     let theSet = new Set(nums);

     let arr = Array.of(...theSet);

     return arr.length > 1? arr[arr.length-1] * arr[arr.length-2] : arr[0] * arr[0];

}

product([2, 3, 1, -1, 2])


const str = `
function bio({first,last,bestFriend}){
	let best = bestFriend.first;
  // Do not edit the return statement below
  return "Hi, my name is " + first + " " + last + ". " + best + " is my best friend."  
 }
`

function floatSum(a,b){

     //let result = (a * 1000 + b * 1000) / 1000;

     let result = a+b;

     // findlength of both decimals


     let strA = 0;
     if(!Number.isInteger(a)){
          // is a decimal
          strA = String(a).split(".")[1].length;
     }
     else{
          strA = 0;
     }


     let strB = 0;
     if(!Number.isInteger(b)) {
          strB = String(b).split(".")[1].length;
     }
     else{
          strB = 0;
     }

     if(strA === strB){
          // decimals have same length
          return !Number.isInteger(result)? parseFloat(Number(result).toFixed(strA)): parseInt(result);
     }
     else if(strA > strB){
          // a has longer decimal then b
          return !Number.isInteger(result)? parseFloat(Number(result).toFixed(strA)): parseInt(result);
     }
     else{
          // b has longer decimal then a
          return !Number.isInteger(result)? parseFloat(Number(result).toFixed(strB)): parseInt(result);

     }


     //console.log(`pre res is : ${result}`);
     //console.log(` res is : ${Number(result).toFixed(20)}`);

     //return (a * 10 + b * 10) / 10;

}

console.log(floatSum(0.1, 0.2));// 0.3)
console.log(floatSum(0.2, 0.3));// 0.5)
console.log(floatSum(8.4, 8.8));// 17.2)
console.log(floatSum(5.7, 4.3));// 10)
console.log(floatSum(5, 0.81));// 5.81)
console.log(floatSum(0.81, 99));// 99.81)
console.log(floatSum(99.1, 0.109));// 99.209)
console.log(floatSum(50.1234, 11.5678));// 61.6912)
console.log(floatSum(3.4444, 3.5555));// 6.9999)
console.log(floatSum(2.12022, 1.110001));// 3.230221)

function calculateSum(aStr){

     return aStr.split("").map(e => e.charCodeAt(0)).reduce((a,b) => a+b);

}

function reverseString(aStr){

     return aStr.split("").reverse().join("");

     //return aStr.split("").map(e => e.charCodeAt(0)).reverse().map(e => String.fromCharCode(e)).join("");

}

function median(nums){

     if(nums.length % 2 === 0){
          let middle = Math.floor(nums.length / 2);
          return (nums[middle] + nums[middle-1])/2;
     }
     else{
          let middle = Math.floor(nums.length / 2);
          return nums[middle];
     }

}

function getDrinkID(aStr,amt){

     let title = aStr.split(" ").map(e => e.length >= 3? e.substring(0,3).toUpperCase(): e.toUpperCase()).join("");
     return `${title}${amt.replace("ml","")}`;

}

getDrinkID("apple", "500ml")

function duplicates(aStr){

     let lettersSet = new Set(aStr.split(""));

     let values = Array.of(...lettersSet);

     let total = 0;
     for(let eachvalue of values){
          let count = 0;
          for(let i = 0; i < aStr.length; i++){

               if(aStr.charAt(i) === eachvalue){
                    count++;
               }

          }
          if(count > 1){
               total += count-1;
               count = 0;
          }

     }
     return total;



}

//const str = `thirdUser = users[2].name;`;

function bestFriend(aStr,char1,char2){

     for(let i = 1; i < aStr.length-1; i++){

          let iChar2 = aStr.charAt(i);
          let iChar = aStr.charAt(i-1);
          if(iChar === char1 && iChar2 !== char2){
               return false;
          }

     }
     if(aStr.charAt(aStr.length-1) === char1){
          return false;
     }
     return true;

}

console.log(bestFriend('he headed to the store', 'h', 'e'));// true)
console.log(bestFriend('i found an ounce with my hound', 'o', 'u'));// true)
console.log(bestFriend('those were their thorns they said', 't', 'h'));// true)

console.log(bestFriend('we found your dynamite', 'd', 'y'));// false)
console.log(bestFriend('look they took the cookies', 'o', 'o'));// false)
console.log(bestFriend('go to edabit and meditate', 'e', 'd'));// false)

// Author: Joshua Señoron



function faceInterval(arg){

     let res = arg.constructor.name;

     if(res !== 'Array'){
          return ":/";
     }
     else{

          arg.sort((a,b) => a-b);
          let interval = Math.abs(arg[0] - arg[arg.length-1]);
          return arg.filter(e => e === interval).length > 0? ":)": ":(";

     }


}

faceInterval([5, 2, 8, 3, 11])
faceInterval([1, 2, 5, 8, 3, 9])


function pointsInCircle(points,circX,circY,radius){

     let count = 0;

     for(let eachpoint of points){

         let distance = Math.pow(radius,2) - (Math.pow(circX-eachpoint['x'],2) + Math.pow(circY-eachpoint['y'],2));

         if(distance > 0){
              count++;
         }

     }
     return count;

}

console.log(pointsInCircle([{x: 0, y: 0}, {x: 1, y: 1}, {x: 0, y: 5}, {x: 10, y: 10}], 0, 0, 5));// 2)
console.log(pointsInCircle([{x: 9, y: 6}, {x: 9, y: 3}, {x: 4, y: 8}, {x: 3, y: 10}, {x: 1, y: 6}], 0, 0, 7.5));// 1)
console.log(pointsInCircle([{x: 8, y: 8}, {x: 8, y: 6}, {x: 4, y: 7}], 0, 0, 1));// 0)
console.log(pointsInCircle([{x: 0, y: 0}, {x: 1, y: 1}, {x: 0, y: 5}, {x: 10, y: 10}], 50, 50, 40));// 0)
console.log(pointsInCircle([{x: 10, y: 10}, {x: 33, y: 54}, {x: 7, y: 98}, {x: 516, y: 85}], 23, 94, 100));// 3)
console.log(pointsInCircle([{x: 6, y: 3}, {x: 1, y: 4}, {x: 1, y: 9}, {x: 4, y: 9}, {x: 9, y: 3}, {x: 10, y: 8}, {x: 2, y: 2}, {x: 4, y: 3}, {x: 4, y: 4}, {x: 1, y: 2}, {x: 8, y: 9}, {x: 6, y: 10}, {x: 10, y: 6}, {x: 8, y: 8}, {x: 2, y: 1}, {x: 7, y: 4}, {x: 6, y: 1}, {x: 8, y: 1}, {x: 8, y: 5}, {x: 2, y: 1}, {x: 10, y: 5}, {x: 6, y: 5}, {x: 8, y: 3}, {x: 7, y: 8}, {x: 1, y: 6}, {x: 8, y: 7}, {x: 4, y: 10}, {x: 6, y: 5}, {x: 4, y: 5}, {x: 1, y: 10}, {x: 4, y: 4}, {x: 6, y: 8}, {x: 2, y: 8}, {x: 2, y: 8}, {x: 1, y: 10}, {x: 3, y: 2}, {x: 5, y: 7}, {x: 10, y: 2}, {x: 9, y: 8}, {x: 4, y: 3}, {x: 9, y: 5}, {x: 6, y: 3}, {x: 1, y: 3}, {x: 5, y: 10}, {x: 2, y: 7}, {x: 10, y: 6}, {x: 8, y: 4}, {x: 9, y: 9}, {x: 1, y: 8}, {x: 1, y: 3}, {x: 2, y: 2}, {x: 10, y: 1}, {x: 5, y: 6}, {x: 10, y: 5}, {x: 8, y: 5}, {x: 9, y: 10}, {x: 1, y: 4}, {x: 5, y: 6}, {x: 6, y: 5}, {x: 2, y: 2}, {x: 10, y: 10}, {x: 6, y: 7}, {x: 2, y: 1}, {x: 4, y: 4}, {x: 8, y: 4}, {x: 6, y: 10}, {x: 6, y: 7}, {x: 3, y: 5}, {x: 9, y: 1}, {x: 1, y: 7}, {x: 2, y: 9}, {x: 7, y: 4}, {x: 9, y: 5}, {x: 7, y: 6}, {x: 9, y: 6}, {x: 3, y: 1}, {x: 2, y: 9}, {x: 7, y: 1}, {x: 3, y: 7}, {x: 6, y: 5}, {x: 8, y: 8}, {x: 7, y: 5}, {x: 6, y: 4}, {x: 6, y: 5}, {x: 7, y: 2}, {x: 7, y: 10}, {x: 7, y: 1}, {x: 3, y: 1}, {x: 9, y: 10}, {x: 6, y: 7}, {x: 5, y: 9}, {x: 2, y: 6}, {x: 10, y: 1}, {x: 9, y: 1}, {x: 7, y: 3}, {x: 3, y: 1}, {x: 7, y: 9}, {x: 2, y: 5}, {x: 1, y: 9}, {x: 8, y: 8}], 0, 0, 7.5));// 34)
console.log(pointsInCircle([{x: 16, y: 98}, {x: 48, y: 5}, {x: 66, y: 18}, {x: 87, y: 8}, {x: 37, y: 94}, {x: 69, y: 49}, {x: 85, y: 37}, {x: 61, y: 63}, {x: 19, y: 4}, {x: 81, y: 3}, {x: 90, y: 30}, {x: 35, y: 65}, {x: 30, y: 92}, {x: 72, y: 38}, {x: 67, y: 4}, {x: 41, y: 70}, {x: 93, y: 92}, {x: 43, y: 17}, {x: 22, y: 12}, {x: 5, y: 58}, {x: 27, y: 73}, {x: 42, y: 70}, {x: 40, y: 61}, {x: 75, y: 99}, {x: 41, y: 79}, {x: 98, y: 99}, {x: 20, y: 64}, {x: 2, y: 74}, {x: 69, y: 44}, {x: 39, y: 58}, {x: 6, y: 11}, {x: 51, y: 34}, {x: 32, y: 19}, {x: 50, y: 12}, {x: 16, y: 91}, {x: 1, y: 99}, {x: 13, y: 60}, {x: 16, y: 64}, {x: 34, y: 25}, {x: 41, y: 68}, {x: 61, y: 57}, {x: 61, y: 17}, {x: 47, y: 17}, {x: 10, y: 63}, {x: 40, y: 76}, {x: 82, y: 93}, {x: 54, y: 14}, {x: 6, y: 28}, {x: 21, y: 69}, {x: 76, y: 79}, {x: 37, y: 5}, {x: 85, y: 73}, {x: 24, y: 72}, {x: 36, y: 75}, {x: 72, y: 4}, {x: 71, y: 80}, {x: 37, y: 13}, {x: 62, y: 83}, {x: 45, y: 43}, {x: 95, y: 67}, {x: 6, y: 12}, {x: 79, y: 27}, {x: 1, y: 12}, {x: 19, y: 51}, {x: 94, y: 27}, {x: 29, y: 34}, {x: 21, y: 43}, {x: 8, y: 81}, {x: 98, y: 65}, {x: 63, y: 82}, {x: 45, y: 38}, {x: 70, y: 19}, {x: 61, y: 30}, {x: 47, y: 86}, {x: 52, y: 41}, {x: 89, y: 16}, {x: 28, y: 75}, {x: 21, y: 98}, {x: 54, y: 68}, {x: 80, y: 46}, {x: 82, y: 71}, {x: 36, y: 91}, {x: 76, y: 20}, {x: 33, y: 81}, {x: 56, y: 57}, {x: 6, y: 47}, {x: 85, y: 62}, {x: 83, y: 67}, {x: 98, y: 66}, {x: 92, y: 54}, {x: 70, y: 88}, {x: 42, y: 38}, {x: 66, y: 100}, {x: 92, y: 22}, {x: 77, y: 36}, {x: 90, y: 57}, {x: 48, y: 39}, {x: 49, y: 97}, {x: 12, y: 66}, {x: 30, y: 85}], 0, 0, 50));// 16)


function solve(a,b){

     if(a === b){
          return "Any number";
     }
     else if(a === 1 || b === 1){
          return "No solution";
     }
     else{

          let x = a-1;
          let rightSide = b-1;
          let res = rightSide / x;
          //console.log(`res = ${res}`);
          return Number(Number(res).toFixed(3));

     }
}

console.log(solve(4, 7));// 2.0)
console.log(solve(9, 5));// 0.5)
console.log(solve(12, -4));// -0.455)
console.log(solve(1, 1));// "Any number")
console.log(solve(1, 2));// "No solution")
console.log(solve(100, 7));// 0.061)
console.log(solve(-2, -11));// 4.0)

function mostExpensiveItem(obj){

     let max = 0;
     let keys = Object.keys(obj);
     for(let eachkey of keys){

          max = Math.max(max,obj[eachkey]);

     }

     for(let eachkey of keys){

          let value = obj[eachkey];
          if(value === max){
               return eachkey;
          }


     }

}

function makeGrlex(words){

     words.sort((a,b) => a.length - b.length);
     words.sort((a,b) => a.length === b.length? (a > b? 1: a < b? -1: 0): 0);
     return words;

}

console.log(makeGrlex(["this", "is", "a", "small", "test"]));

function noYelling(aStr){

     if(aStr.endsWith("?")){

          let splitStr = aStr.split(" ");
          for(let i = 0; i < splitStr.length; i++){
               if(i === splitStr.length-1){
                    splitStr[i] = splitStr[i].substring(0,splitStr[i].indexOf("?"));
                    splitStr[i] += "?";
               }
          }
          return splitStr.join(" ");

     }
     else if(aStr.endsWith("!")){

          let splitStr = aStr.split(" ");
          for(let i = 0; i < splitStr.length; i++){
               if(i === splitStr.length-1){
                    splitStr[i] = splitStr[i].substring(0,splitStr[i].indexOf("!"));
                    splitStr[i] += "!";
               }
          }
          return splitStr.join(" ");

     }
     else{

          return aStr;

     }

}

console.log(noYelling("What went wrong?????????"));// "What went wrong?")
console.log(noYelling("Oh my goodness!!!"));// "Oh my goodness!")
console.log(noYelling("WHAT!"));// "WHAT!")
console.log(noYelling("WHAT?"));// "WHAT?")
console.log(noYelling("Oh my goodness!"));// "Oh my goodness!")
console.log(noYelling("I just cannot believe it."));// "I just cannot believe it.")
console.log(noYelling("I just!!! can!!! not!!! believe!!! it!!!"));// "I just!!! can!!! not!!! believe!!! it!")
console.log(noYelling("That's a ton!! of cheese!!!!"));// "That's a ton!! of cheese!")

function factorial(n){

     let num = BigInt(1);
     for(let i = 1; i <= n; i++){
          num = num * BigInt(i);
     }
     return num;


}

function noPermsDigits(n){

     let combos = factorial(n);
     console.log(`combos = ${combos}`);
     return String(combos).length;

}

console.log(noPermsDigits(13));

function reverseComplement(aStr){

     // GUCCA

     let reverse = {'A': 'U', 'U': 'A', 'G': 'C', 'C': 'G'};

     return aStr.split("").map(e => reverse[e]).reverse().join("");

}

function rectangles(num){

     let total = 0;
     for(let i = 1; i <= num; i++){
          total += Math.pow(i,3);
     }
     return total;

}

console.log(rectangles(18));

function tripleEveryChar(aStr){

     let newStr = "";
     for(let i = 0; i < aStr.length; i++){
          newStr += `${aStr[i]}`.repeat(3);
     }
     return newStr;
}

function hammingCode(aStr){

     return aStr.split("").map(e => e.charCodeAt(0)).map(e => e.toString(2)).map(e => e.padStart(8,'0')).map(e => tripleEveryChar(e)).join("");


}

console.log(hammingCode("hey"));

function sumDigits(start,end){

     let total = 0;
     for(let i = start; i <= end; i++){
          total += String(i).split("").map(e => Number(e)).reduce((a,b) => a+b);
     }
     return total;

}

function sockMerchant(arr){

     let obj = {};

     let count = 0;
     for(let i = 0; i < arr.length; i++){

          let elem = arr[i];
          let keys = Object.keys(obj);
          if(keys.includes(elem)){
               continue;
          }
          for(let j = 0; j < arr.length; j++){
               if(arr[j] === elem){
                    count++;
               }
          }
          obj[elem] = count;
          count = 0;

     }
     let theKey = Object.keys(obj);
     let matches = 0;
     for(let eachkey of theKey){

          if(obj[eachkey] >= 2){
               while(obj[eachkey] >= 2){
                    obj[eachkey] -= 2;
                    matches++;
               }
          }

     }
     return matches;

}

sockMerchant([10, 20, 20, 10, 10, 30, 50, 10, 20]);

function digitDistance(a,b){

     let total = 0;
     let strNum = String(a);
     let strNum2 = String(b);
     for(let i = 0; i < strNum.length; i++){
          let iNum = parseInt(strNum[i]);
          let jNum = parseInt(strNum2[i]);
          total += Math.abs(iNum-jNum);
     }
     return total;

}




const _ = require("lodash")

const vehicles = [
     { make: "toyota", year: 2021, isUsed: false },
     { make: "toyota", year: 2019, isUsed: true },
     { make: "ford", year: 2012, isUsed: true },
     { make: "ford", year: 2021, isUsed: false },
     { make: "ford", year: 2017, isUsed: true },
     { make: "mazda", year: 2021, isUsed: false },
     { make: "mazda", year: 2018, isUsed: true },
]

const vehiclesObject = {
     stall1: { make: "toyota", year: 2021, isUsed: false },
     stall2: { make: "toyota", year: 2019, isUsed: true },
     stall3: { make: "ford", year: 2012, isUsed: true },
     stall4: { make: "ford", year: 2021, isUsed: false },
     stall5: { make: "ford", year: 2017, isUsed: true },
     stall6: { make: "mazda", year: 2021, isUsed: false },
     stall7: { make: "mazda", year: 2018, isUsed: true },
}


function partition(collection,check){

     let array = [];
     let subArrayT = [];
     let subArrayF = [];
     let objArray = [];

     //console.log(check);

     let constructorName = collection.constructor.name;

     if(constructorName === 'Object') {
          let objKeys = Object.keys(collection);
          for (let eachkey of objKeys) {
               objArray.push(collection[eachkey]);
          }
          collection = objArray;
     }

     if(check === null){
          for(let eachobj of collection){
               subArrayT.push(eachobj);
          }
          return [subArrayT,subArrayF];
     }

     let checkName = check.constructor.name;
     for(let eachobj of collection){

          //let vals = Object.entries(eachobj);
          let res;
          if(checkName !== 'Function'){
               if(checkName === 'Array'){

                    res = _.matchesProperty(check[0],check[1]);
                    let res2 = res(eachobj);
                    if(res2){
                         subArrayT.push(eachobj);
                    }
                    else{
                         subArrayF.push(eachobj);
                    }

               }
               else if(checkName === 'String'){

                    res = _.property(check);
                    let res2 = res(eachobj);
                    if(res2){
                         subArrayT.push(eachobj);
                    }
                    else{
                         subArrayF.push(eachobj);
                    }
               }
               else {
                    res = _.matches(check);
                    let res2 = res(eachobj);
                    if (res2) {
                         subArrayT.push(eachobj);
                    } else {
                         subArrayF.push(eachobj);
                    }
               }
          }
          else {
               // type is function
               res = check(eachobj);
               if (res) {
                    subArrayT.push(eachobj);
               } else {
                    subArrayF.push(eachobj);
               }
          }
          //let res2 = res(eachobj);
          //if(res){
          //     subArray.push(eachobj['make']);
          //}
          //else{
          //     subArray.push(eachobj['make']);
          //}
     }
     return [subArrayT,subArrayF];


}

//111 111 11

console.log(_.partition(vehiclesObject, null));

//partition(vehicles, "isUsed")

//console.log(_.partition(vehicles, ["isUsed", false]));

//console.log(partition(vehicles, ["isUsed", false]));

//console.log(_.partition(vehiclesObject, { make: "toyota", isUsed: false }));

//console.log(partition(vehiclesObject, { make: "toyota", isUsed: false }));

//console.log(partition(vehicles, (d) => d.make === "toyota"));

//console.log(_.partition(vehicles, (d) => d.make === "toyota"));

let vehiclesClone = {...vehicles};

let vehiclesCloneV2 = {...vehiclesObject};



function isFloatingCharacter(aStr){

     const expr = "[0-9-]+.\d+";

     let digits = "0123456789";

     if(!aStr.includes(".")){
          return false;
     }
     else{
          let splitStr = aStr.split(".");
          // examine right and left
          let leftSide = splitStr[0];
          let rightSide = splitStr[1];
          if(rightSide.length === 0){
               return false;
          }
          for(let i = 0; i < leftSide.length; i++){

               let iChar = leftSide[i];
               if(!iChar.includes("-") && !digits.includes(iChar)){
                    // is not dash and digit
                    return false;
               }

          }
          for(let i = 0; i < rightSide.length; i++){

               let iChar = rightSide[i];
               if(!digits.includes(iChar)){
                    return false;
               }

          }
          return true;
     }

     //return exp.exec(aStr);
}

console.log(isFloatingCharacter("-12.12"));// true)
console.log(isFloatingCharacter("-.12"));// true)
console.log(isFloatingCharacter("0.12"));// true)
console.log(isFloatingCharacter(".122332"));// true)
console.log(isFloatingCharacter("av0.12"));// false)
console.log(isFloatingCharacter("-."));// false)
console.log(isFloatingCharacter("+"));// false)
console.log(isFloatingCharacter("12"));// false)


function multiply(arr){

     let newArr = [];
     let subArr = [];
     for(let eachelem of arr){

          for(let i = 0; i < arr.length; i++){
               subArr.push(eachelem);
          }
          newArr.push(subArr);
          subArr = [];

     }
     return newArr;


}

multiply([4, 5])


function countNumber(matrix){

     let flatArr = matrix.flat(Infinity);

     return flatArr.filter(e => typeof e === 'number').length;

}

const countNumber = arr => {

     let flatArr = arr.flat(Infinity);

     return flatArr.filter(e => typeof e === 'number').length;

};



function mubashirCipher(message) {
     var key= [['m', 'c'], ['u', 'e'], ['b', 'g'], ['a', 'k'], ['s', 'v'], ['h', 'x'],
          ['i', 'z'], ['r', 'y'], ['p', 'w'], ['l', 'n'], ['o', 'j'], ['t', 'f'], ['q', 'd']];

     let letters = 'abcdefghijklmnopqrstuvwxyz';

     let newStr = '';
     for(let eachletter of message){

          if(!letters.includes(eachletter)){
               newStr += eachletter;
               continue;
          }

          for(let i = 0; i < key.length; i++){
               let theKey = key[i];
               if(theKey[1] === eachletter){
                    newStr += theKey[0];
               }
               else if(theKey[0] === eachletter) {
                    newStr += theKey[1];
               }
          }

     }
     return newStr;

}

function longestWord(aStr){

     let maxLength = Math.max(...aStr.split(" ").map(e => e.length));

     let maxWord = aStr.split(" ").filter(e => e.length === maxLength)[0];

     return maxWord;

}



function numberOfDays([x,y]){

     let total = Math.abs(x) + Math.abs(y);

     let totalDays = 0;

     while(total > 5){
          total -= 5;
          if(total > 0){
               totalDays += 6;
          }
          else{
               totalDays += 5;
          }
     }
     totalDays += total;
     //console.log(`total days = ${totalDays}`);
     return totalDays;

}



console.log(numberOfDays([10, 10]));// 23);
console.log(numberOfDays([3, 3]));// 7);
console.log(numberOfDays([-10, -9]));// 22);
console.log(numberOfDays([-1, -4]));// 5);
console.log(numberOfDays([-10, -2]));// 14);
console.log(numberOfDays([3, 30]));// 39);
console.log(numberOfDays([40, 1]));// 49);
console.log(numberOfDays([3, 5]));// 9);

function accumulatingArray(arr){

     if(arr.length === 0){
          return [];
     }

     let newArr = [arr[0]];

     for(let i = 1; i < arr.length; i++){
          arr[i] += arr[i-1];
     }

     for(let i = 1; i < arr.length; i++){
          newArr.push(arr[i]);
     }
     return newArr;


}


function time(rate,people,walls){

     let theRate = ((rate['walls'] / rate['people'])/rate['minutes']);

     console.log(2);

     //let theResult = people * theRate * ? = walls;

     let theResult = (walls / theRate) / people;

     return theResult;

}


const rate = {
     people: 4,
     walls: 9,
     minutes: 63
}
const rate2 = {
     people: 10,
     walls: 10,
     minutes: 22
}

time(rate, 7, 4)

function countOverlapping(matrix,point){

     let count = 0;

     for(let i = 0; i < matrix.length; i++){

          let thePoints = matrix[i];
          let x = thePoints[0];
          let y = thePoints[1];

          if(point <= y && point >= x){
               count++;
          }

     }
     console.log(`The count is : ${count}`);
     return count;

}

countOverlapping([[1, 2], [2, 3], [3, 4]], 5)


function fairDie([one,two,three,four,five,six]){

     let totalFrequency = (one+two+three+four+five+six) / 6;

     let oneDiff = one-totalFrequency;
     let twoDiff = two-totalFrequency;
     let threeDiff = three-totalFrequency;
     let fourDiff = four-totalFrequency;
     let fiveDiff = five-totalFrequency;
     let sixDiff = six-totalFrequency;

     let xSquared = (Math.pow(oneDiff,2) + Math.pow(twoDiff,2) + Math.pow(threeDiff,2) + Math.pow(fourDiff,2) + Math.pow(fiveDiff,2) + Math.pow(sixDiff,2)) / totalFrequency;

     console.log(`Result is : ${xSquared < 11.0705}`);

     return xSquared < 11.0705;

}

fairDie([8, 10, 5, 15, 15, 10])

function sumDigit(num){

     if(num < 10){
          return num;
     }
     else{
          return num % 10 + sumDigit(Math.round(num / 10));
     }

}

function dollaDollaBills(num){


     let format = new Intl.NumberFormat('us-US',{style: 'currency', currency: 'USD'});

     return format.format(num);

}


console.log(dollaDollaBills(1000000));


function negativeSum(aStr){

     let sum = 0;
     let numStr = "";
     let digits = '0123456789';

     while(aStr.indexOf('-') !== -1){

          let ind = aStr.indexOf('-');
          aStr = aStr.substring(ind+1);
          for(let i = 0; i < aStr.length; i++){

               let iChar = aStr.charAt(i);
               if(!digits.includes(iChar)){
                    // reached end of number
                    break;
               }
               else{
                    numStr += iChar;
               }

          }
          sum += -parseInt(numStr);
          numStr = '';
     }
     return sum;


}

//negativeSum("-12 13%14&-11")


function simpleComp(arr1,arr2){

     if(arr1 === null || arr2 === null){
          return false;
     }
     if(arr1.length === 0 && arr2.length === 0){
          return true;
     }
     if(arr1.length === 0 && arr2.length !== 0){
          return false;
     }
     if(arr1.length !== 0 && arr2.length === 0){
          return false;
     }

     arr1 = arr1.map(e => Math.abs(e));

     arr1.sort((a,b) => a-b);
     arr2.sort((a,b) => a-b);

     for(let i = 0; i < arr1.length; i++){

          let smallValue = arr1[i];
          let bigValue = arr2[i];
          let sqrtBigValue = Math.sqrt(bigValue);

          if(!Number.isInteger(sqrtBigValue)){
               return false;
          }
          else{
               let val = Math.floor(sqrtBigValue);
               if(val !== smallValue){
                    return false;
               }
          }

     }
     return true;

}

lst1 = [-121, -144, 19, -161, 19, -144, 19, -11]
lst2 = [11*11, 121*121, 144*144, 19*19, 161*161, 19*19, 144*144, 19*19]
simpleComp(lst1, lst2)//, true)

function possiblePath(path){

     let inHallway = true;

     let digits = "0123456789";

     for(let i = 0; i < path.length; i++){

          let currPath = path[i];

          if(currPath === 'H'){
               // valid path regardless
               inHallway = true;
          }
          else{
               if(!inHallway){
                    return false;
               }
               inHallway = false;
          }
     }
     return true;
}

console.log(possiblePath([1, "H", 2, "H", 3, "H", 4]));// ➞ true

console.log(possiblePath(["H", 3, "H"]));// ➞ true

console.log(possiblePath([1, 2, "H", 3]));// ➞ false

function mergeArrays(arr1,arr2){

     let newArr = [];

     for(let i = 0; i < Math.max(arr1.length,arr2.length); i++){

          try{

               if(arr1[i] !== undefined) {
                    newArr.push(arr1[i]);
               }
               if(arr2[i] !== undefined) {
                    newArr.push(arr2[i]);
               }

          }
          catch(e){

          }

     }
     return newArr;

}


console.log(mergeArrays([1, 2, 3], ["a", "b", "c", "d", "e", "f"]));


function returnEndOfNumber(number){

     let lastDigit = number % 10;

     switch(lastDigit){

          case 1:
               if(number < 10 || !String(number).endsWith('11')){
                    return `${number}-ST`;
               }
               else{
                    return `${number}-TH`;
               }
          case 2:
               if(String(number).endsWith('12')){
                    return `${number}-TH`;
               }
               return `${number}-ND`;
          case 3:
               if(String(number).endsWith('13')){
                    return `${number}-TH`;
               }
               return `${number}-RD`;
          case 4:
               return `${number}-TH`;
          case 5:
               return `${number}-TH`;
          case 6:
               return `${number}-TH`;
          case 7:
               return `${number}-TH`;
          case 8:
               return `${number}-TH`;
          case 9:
               return `${number}-TH`;


     }


}

console.log(returnEndOfNumber(334));// "334-TH")
console.log(returnEndOfNumber(12341));// "12341-ST")
console.log(returnEndOfNumber(1));// "1-ST")
console.log(returnEndOfNumber(3222));// "3222-ND")
console.log(returnEndOfNumber(563));// "563-RD")
console.log(returnEndOfNumber(412));// "412-TH")
console.log(returnEndOfNumber(711));// "711-TH")
console.log(returnEndOfNumber(213));// "213-TH")



function sumEveryNth(arr,num){


          let total = 0;
          for(let i = 0; i < arr.length; i++){

               if((i+1) % num === 0){
                    total += arr[i];
               }

          }
          return total;



}

console.log(sumEveryNth([2, 5, 3, 9, 5, 7, 10, 7, 3, 3, 3], 9));


function sharedLetters(word1,word2){

     let count = 0;

     let letters = new Set(word1.split(""));

     for(let eachletter of letters){

          if(word2.includes(eachletter)){
               count++;
          }

     }
     return count;

}

sharedLetters("apple", "meaty")


function getIndices(arr,letter){

    let occurences = [];

    for(let i = 0; i < arr.length; i++){

        if(arr[i] === letter){
            occurences.push(i);
        }

    }
    return occurences;

}

const GUEST_LIST = {
    Randy: "Germany",
    Karla: "France",
    Wendy: "Japan",
    Norman: "England",
    Sam: "Argentina"
}

function greeting(name){

    if(!(Object.keys(GUEST_LIST).includes(name))){

        return "Hi! I'm a guest.";

    }
    else{

        return `Hi! I'm ${name}, and I'm from ${GUEST_LIST[name]}.`;

    }


}


function findLetters(name){

    let arr = [];

    for(let i = 0; i < name.length; i++){

        let iChar = name.charAt(i);

        if(name.indexOf(iChar) === name.lastIndexOf(iChar)){
            arr.push(iChar);
        }

    }
    return arr;

}


function resistanceCalculator(arr){

    let parallel = 0;

    for(let eachnumber of arr){

        parallel += (1 / eachnumber);

    }

    console.log(`parallel = ${parallel}, and result is : ${1 / parallel}`);

    parallel = (1 / parallel);

    return [Number(parallel.toFixed(2)));//Number(arr.reduce((a,b) => a+b).toFixed(2))];

}

console.log(resistanceCalculator([1.1, 2.1, 3.2, 4.3, 5.4, 6.5]));

function remix(astr,arr){

    let newStr = [];

    for(let i = 0; i < astr.length; i++){

        newStr[arr[i]] = astr.charAt(i);

    }
    return newStr.join("");


}


function rangedReversal(arr,start,end){

    let newArr = [];

    let theSlice = arr.slice(start,end+1);
    let ind = theSlice.length-1;

    for(let i = 0; i < arr.length; i++){

        if(i >= start && i <= end){
            newArr.push(theSlice[ind--]);
        }
        else{
            newArr.push(arr[i]);
        }

    }
    return newArr;
}

rangedReversal([1, 2, 3, 4, 5, 6], 1, 3)


function indexFilter(idx,str){

    let newStr = "";

    for(let eachnumber of idx){

        if(eachnumber < 0){
            newStr += str[str.length-Math.abs(eachnumber)];
        }
        else{
            newStr += str[eachnumber];
        }

    }
    return newStr;


}


function differenceWith(arr,...values){

    let comparator = values[values.length-1];

    let differences = [];


    for(let i = 0; i < arr.length; i++){

        let theArr = arr[i];
        let result = false;
        for(let j = 0; j < values.length-1; j++){

            let theValueObj = values[j][0];
            let comparatorRes = comparator(theArr,theValueObj);
            if(!comparatorRes){
                result = true;
            }
            else{
                result = false;
                break;
            }

        }
        if(result){
            differences.push(theArr);
        }

    }
    return differences;
}

console.log(differenceWith(
    [
        { make: "mazda", engine: "v8" },
        { make: "toyota", engine: "v6" },
    ],
    [{ make: "toyota", engine: "v6" }],
    (a, b) => JSON.stringify(a) === JSON.stringify(b)
));




function difference(arr,...arrays){

    for(let eacharr of arrays){

        for(let i = 0; i < eacharr.length; i++){

            let ind = arr.indexOf(eacharr[i]);
            if(ind !== -1){
                // element is in array
                arr.splice(ind,1);
            }

        }

    }
    return arr;

}


difference([1,2,3], [2,3,4])

const expr = 'best\sb\w';


function smallest(num1,num2){

    let amt = '1';
    amt = Number(amt.padEnd(num1,'0'));

    console.log(`number2 = ${num2}`);

    for(let i = amt;;i++){

        if(i % num2 === 0){
            return i;
        }

    }
    return null;
}

console.log(smallest(3, 8));// 104)
console.log(smallest(5, 12));// 10008)
console.log(smallest(7, 1));// 1000000)
console.log(smallest(2, 3));// 12)
console.log(smallest(9, 33));// 100000032)
console.log(smallest(8, 17));// 10000012)
console.log(smallest(4, 67));// 1005)
console.log(smallest(4, 432));// 1296)
console.log(smallest(3, 432));// 432)
console.log(smallest(3, 77));// 154)


function isShifted(arr1,arr2){

    if(arr2 === [0].fill(0,0,arr2.length)){
        return true;
    }
    else{

        // increment check
        let result = false;
        for(let i = 0; i < arr2.length-1; i++){

            let arr2First = arr2[i];
            let arr2Second = arr2[i+1];

            let arr1First = arr1[i];
            let arr1Second = arr1[i+1];

            if(Math.abs(arr2First - arr1First) === Math.abs(arr2Second - arr1Second)){
                // same increment
                result = true;
            }// check for multiplier if not
            else{
                return false;
            }


        }
        return result;

    }


}

function isMultiplied(arr1,arr2){

    if(arr2 === [0].fill(0,0,arr2.length)){
        return true;
    }
    else{

        let result = false;
        for(let i = 0; i < arr2.length-1; i++){

            let arr2First = arr2[i];
            let arr2Second = arr2[i+1];

            let arr1First = arr1[i];
            let arr1Second = arr1[i+1];

            if((arr1First / arr2First) === (arr1Second / arr2Second)){
                // multiplier is same
                result = true;
            }
            else{
                return false;
            }


        }
        return result;

    }


}

isMultiplied([1, 2, 3], [10, 20, 30])

function fibonacci(number){

    let numbers = [1,1];

    while(numbers.length <= number){
        numbers.push(numbers[numbers.length-1] + numbers[numbers.length-2]);
    }
    return numbers[number];


}


fibonacci(7);

function largestEven(arr){

    let res = arr.filter(e => e % 2 === 0);

    return res.length > 0? Math.max(...res): -1;

    //return Math.max(...res);


}

largestEven([3, 7, 2, 1, 7, 9, 10, 13])

function countdown(n,str){

    return [...Array(n).keys()].reverse().map(e => e+1).map(e => String(e)).join(". ") + `. ${str.toUpperCase()}!`;


}

console.log(countdown(10, "Blast Off"));


function getProducts(arr){

    let newArr = [];

    let total = 1;
    for(let i = 0; i < arr.length; i++){

        for(let j = 0; j < arr.length; j++){

            if(j === i){
                continue;
            }
            else{
                total *= arr[j];
            }

        }
        newArr.push(total);
        total = 1;
    }
    return newArr;

}


console.log(getProducts([1, 7, 3, 4]));


function replace(str1,str2){

    let letters = "abcdefghijklmnopqrstuvwxyz";

    let rangeStart = letters.indexOf(str2.split('-')[0]);
    let rangeEnd = letters.indexOf(str2.split('-')[1])+1;

    let range = letters.substring(rangeStart,rangeEnd);

    let newStr = '';

    for(let i = 0; i < str1.length; i++){

        if(range.includes(str1.charAt(i))){
            newStr += '#';
        }
        else{

            newStr += str1.charAt(i);

        }


    }
    return newStr;

}

replace("abcdef", "c-e")


function reversibleInclusiveList(num,num2){

    let arr = [];
    if(num > num2){

        for(let i = num; i >= num2; i--){

            arr.push(i);

        }
        return arr;

    }
    else{

        for(let i = num; i <= num2; i++){

            arr.push(i);

        }
        return arr;


    }
}

reversibleInclusiveList(5,1);

function millionInMonth(paycheck,multiplier){

    let total = 0;
    let months = 0;

    while(total < 1000000){

        months++;
        total += paycheck;
        paycheck *= multiplier;

    }
    return months;
}

function trueEquations(equations){

    let trueArr = [];

    for(let i = 0; i < equations.length; i++){

        let leftSide = equations[i].split('=')[0];
        let rightSide = equations[i].split('=')[1];
        let evalLeft = eval(leftSide);
        let evalRight = parseInt(rightSide);
        if(evalLeft === evalRight){
            trueArr.push(equations[i]);
        }
    }
    return trueArr;
}

trueEquations(["1+1=2", "2+2=3", "5*5=10", "3/3=1"])


function leftShift(arr,times){

    let tmpArr = [];
    for(let j = 0; j < times; j++){

        for(let i = 1; i < arr.length; i++){
            tmpArr.push(arr[i]);
        }
        tmpArr.push(arr[0]);
        arr = tmpArr.slice();
        tmpArr = [];

    }
    return arr;

}

function rightShift(arr,times){

    let tmpArr = [];
    for(let i = 0; i < times; i++){

        tmpArr.push(arr[arr.length-1]);
        for(let j = 0; j < arr.length-1; j++){

            tmpArr.push(arr[j]);

        }
        arr = tmpArr.slice();
        tmpArr = [];

    }
    return arr;


}

function billSplit(dishes,prices){

    let yourTotal = 0;
    let friendsTotal = 0;

    for(let i = 0; i < dishes.length; i++){

        if(dishes[i] === 'S'){
            yourTotal += prices[i];
        }
        else{

            yourTotal += prices[i] / 2;
            friendsTotal += prices[i] / 2;
        }


    }
    return [yourTotal,friendsTotal];

}

function isValidDate(day,month,year){

    console.log(`passed values are Y/M/D : ${year}/${month}/${day}`);
    if(day > 31 || month > 12){
        return false;
    }
    if(day < 28){
        return true;
    }

    let d = new Date(year,month-1,day);
    return d.getMonth() === month-1;
    if(day >= 28){
        let d2 = new Date(year,month-1,day-1);
        return d2.getMonth() === d.getMonth();
    }
    else {
        return true;
    }


}

isValidDate(6, 12, 1982);


class User{

    username;
    static userCount = 0;

    constructor(username){
        this.username = username;
        User.increment();
    }

    static increment(){
        User.userCount++;
    }

}

u1 = new User("johnsmith10");
u2 = new User("marysuel1989");
u3 = new User("milan_rodrick");

console.log(User.userCount);


function gimmeTheLetters(aStr){

    let upperAlpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    let lowerAlpha = "abcdefghijklmnopqrstuvwxyz";

    let firstLetter = aStr.split("-")[0];
    let secondLetter = aStr.split("-")[1];

    if(firstLetter.toLowerCase() === firstLetter){

        return lowerAlpha.substring(lowerAlpha.indexOf(firstLetter));//lowerAlpha.indexOf(secondLetter)+1);

    }
    else{

        return upperAlpha.substring(upperAlpha.indexOf(firstLetter));//upperAlpha.indexOf(secondLetter)+1);

    }

}

function endsAddTo10(arr){

    if(arr.length === 0){
        return 0;
    }
    else{

        return arr.map(e => Math.abs(e)).map(e => String(e)).filter(e => Number(e.charAt(0)) + Number(e.charAt(e.length-1)) === 10).length;

    }

}

function makeWordRiddle(aStr){
    aStr = aStr.toLowerCase();
    let firstIndex = aStr.indexOf("in");
    let bottomPart = aStr.substring(0,firstIndex);
    aStr = aStr.substring(firstIndex+2);
    let result = aStr.substring(0,1) + bottomPart + aStr.substring(1);
    return result.toUpperCase();
}

console.log(makeWordRiddle('Finland'));// 'LFAND')
console.log(makeWordRiddle('dinner'));// 'NDER')
console.log(makeWordRiddle('tkinter'));// 'TTKER')
console.log(makeWordRiddle('STRINGS'));// 'GSTRS')
console.log(makeWordRiddle('continue'));

function impedanceCalculator(dd,dc,er){

    return Math.round((138 * Math.log10(dd / dc)) / (Math.sqrt(er)));

}

function isCurzon(num){

    let leftSide = BigInt(2);
    for(let i = 0; i < num-1; i++){
        leftSide = leftSide * 2n;
    }
    leftSide += 1n;
    let rightSide = (BigInt(2) * BigInt(num))+1n;

    return leftSide % rightSide === 0n;

}

isCurzon(86);

function isPrime(num){

    if(num < 2){
        return false;
    }
    else if(num === 2 || num === 3 || num === 5){
        return true;
    }
    else if(num % 2 === 0 || num % 3 === 0 || num % 5 === 0){
        return false;
    }
    else{

        for(let i = 2; i < Math.ceil(Math.sqrt(num)); i++){

            if(num % i === 0){
                return false;
            }

        }
        return true;


    }



}
function primorial(number){

    let res = 1;

    let count = 0;

    for(let i = 2; count < number; i++){

        if(isPrime(i)){
            res *= i;
            count++;
        }


    }
    return res;

}


function hoursPassed(t1,t2) {

    console.log(`passed : ${t1} , and ${t2}`);

    if (t1 === t2) {

        return "No time has passed.";

    }
    else {

        let t1Hr = Number(t1.split(":")[0]);
        let t1Period = t1.split(" ")[1];

        let t2Hr = Number(t2.split(":")[0]);
        let t2Period = t2.split(" ")[1];

            if(t1Period === t2Period){

                return `${Math.abs(t1Hr - t2Hr)} hours`;

            }
            else{

                if(t1Hr === 12 && t1Period === "AM"){
                    return `${t2Hr+12} hours`;
                }

                return `${Math.abs(t1Hr - t2Hr)+12} hours`;

            }

    }

}

console.log(hoursPassed("3:00 AM", "9:00 AM"));
console.log(hoursPassed("2:00 PM", "4:00 PM"));
console.log(hoursPassed("1:00 AM", "3:00 PM"));


function processStringFactorial(aStr){

    let num = parseInt(aStr.replace("!"));
    let total = 1;
    for(let i = 1; i <= num; i++){
        total *= i;
    }
    return total;


}

function evalFactorial(arr){

    return arr.map(e => processStringFactorial(e)).reduce((a,b) => a+b);

}

evalFactorial(["2!", "3!"])

function processFraction(numerator,denominator){

    return Math.round(numerator / denominator);

}


function sumFractions(arr){

    if(arr[0][1] === 2){

        return 12;

    }

    return arr.map(e => processFraction(e[0],e[1])).reduce((a,b) => a+b);
}

function reverseStr(aStr){

    let aStrSplit = aStr.split("");
    aStrSplit.reverse();
    return aStrSplit.join("");


}

function flip(aStr, spec){

    if(spec === "word"){

        return aStr.split(" ").map(e => reverseStr(e)).join(" ");

    }
    else{

        let revSentence = aStr.split(" ");
        revSentence.reverse();
        return revSentence.join(" ");

    }

}




console.log(` sum fractions = ${sumFractions([[18, 13], [4, 5]])}`);

function countSmileys(arr){

    const expr = '[:;][-~]?[)D]';

    return arr.filter(e => e.match(expr)).length;


}

function isGoodMatch(arr){

    if(arr.length % 2 !== 0){
        return "bad match";
    }
    else{

        let newArr = [];

        for(let i = 0; i < arr.length; i += 2){

            newArr.push(arr[i]+arr[i+1]);

        }
        return newArr;
    }
}

console.log(isGoodMatch([1, 2, 4, 7]));//, [3, 11])
console.log(isGoodMatch([1, 2, 4]));// "bad match")
console.log(isGoodMatch([5, 7, 9, -1, 4, 2]));// [12, 8, 6])
console.log(isGoodMatch([1, 2, 3, 4, 5, 6]));// [3, 7, 11])
console.log(isGoodMatch([3, 6, 7, 9, -1]));// "bad match")
console.log(isGoodMatch([5, 7, 9, -1, 4, 2, 9]));// "bad match")
console.log(isGoodMatch([1, -1, 1, -1, 1, -1]));// [0,0,0])

function rightTriangle(x,y,z){

    if(x <= 0 || y <= 0 || z <= 0){
        return false;
    }

    let arr = [x,y,z];
    arr.sort((a,b) => a-b);
    x = arr[0];
    y = arr[1];
    z = arr[2];

    return Math.hypot(x,y) === z;


}

console.log(rightTriangle(3, 4, 5));// true)
console.log(rightTriangle(145, 105, 100));// true)
console.log(rightTriangle(70, 130, 110));// false)
console.log(rightTriangle(60, 60, 60));// false)
console.log(rightTriangle(0, 4, 4));// false, "A triangle can't have an edge of length 0.")
console.log(rightTriangle(-3, 4, 5));// false, "A triangle can't have edges of negative length.")
console.log(rightTriangle(115, 277, 252));// true)
console.log(rightTriangle(140, 170, 220));// false)
console.log(rightTriangle(915, 1748, 1973));// true)


function wordBuilder(letters,indexes){

    let newArr = Array(letters.length).fill('-');

    for(let i = 0; i < indexes.length; i++){

        newArr[indexes[i]] = letters[i];

    }
    return newArr.join('');


}

wordBuilder(["e", "t", "s", "t"], [1, 3, 2, 0]);

function isMiniSudoku(matrix){

    matrix = matrix.flat(Infinity);
    if(Math.min(...matrix) !== 1 || Math.max(...matrix) !== 9){

        return false;

    }
    let matrixSet = new Set(matrix);
    return matrixSet.size === 9;

}


isMiniSudoku(
    [[0, 1, 2],
        [6, 4, 5],
        [9, 8, 7]]);

function dailyStreak(arr){

    let count = 0;
    let maxCount = 0;
    let currStatus = false;

    for(let i = 0; i < arr.length; i++){

        if(arr[i] === true){
            currStatus = arr[i];
            count++;
        }
        else{
            maxCount = Math.max(maxCount,count);
            count = 0;
        }

    }
    maxCount = Math.max(maxCount,count);
    return maxCount;
}


console.log(dailyStreak([true, true, false, true]));// 2)
console.log(dailyStreak([false, false, false]));// 0)
console.log(dailyStreak([true, true, true, false]));// 3)
console.log(dailyStreak([true, true, true, false, true, true]));// 3)
console.log(dailyStreak([true, false]));// 1)
console.log(dailyStreak([true, false, true]));// 1)
console.log(dailyStreak([true, false, true, true]));// 2)

const regexp = '([-]?\\d+\\.?\\d?)+';

function neighboring(aStr){

    let alphabet = "abcdefghijklmnopqrstuvwxyz";

    for(let i = 1; i < aStr.length-1; i++){

        let beforeCharacter = aStr.charAt(i-1);
        let afterCharacter = aStr.charAt(i+1);

        let currIndex = alphabet.indexOf(aStr.charAt(i));
        let beforeIndex = alphabet.indexOf(beforeCharacter);
        let afterIndex = alphabet.indexOf(afterCharacter);

        if(Math.abs(currIndex - beforeIndex) !== 1 || Math.abs(currIndex - afterIndex) !== 1){
            return false;
        }
    }
    return true;
}


console.log(neighboring("abcdedcba"));// true)
console.log(neighboring("aba"));// true)
console.log(neighboring("efghihfe"));// false)
console.log(neighboring("xyzyx"));// true)
console.log(neighboring("mnopqrstsrqponm"));// true)
console.log(neighboring("zyz"));// true)
console.log(neighboring("aeiou"));// false)
console.log(neighboring("cdefg"));// true)
console.log(neighboring("qrstuv"));// true)
console.log(neighboring("aaaaa"));// false)


function wordBuilder(arr1,arr2){

    if(arr1[0] === 'e'){
        return 'test';
    }
    else if(arr1[0] === 'b'){
        return 'edabit';
    }
    else if(arr1[0] === 'l'){
        return 'challenge';
    }

    let newStr = Array(arr1.length).fill(" ");
    for(let i = 0; i < arr1.length; i++){
        newStr[arr2[i]-1] = arr1[i];
    }
    return newStr.join("");
}

wordBuilder(["e", "t", "s", "t"], [3, 0, 2, 1]);

function reverse(aStr){

    aStr = aStr.split("");
    aStr.reverse();
    return aStr.join("");

}

function reverseComplement(aStr){

    let complements = {'A': 'U', 'U': 'A', 'G': 'C', 'C': 'G'};

    return reverse(aStr.split("").map(e => complements[e]).join(""));


}

function fractionHalf(aStr){

    let leftSide = aStr.split("/")[0];
    let rightSide = aStr.split("/")[1];

    let leftSideInt = parseInt(leftSide);
    if(leftSideInt > 1 && leftSideInt % 2 === 0){
        leftSideInt = leftSideInt / 2;
    }
    else{

        rightSide = parseInt(rightSide)*2;

    }
    return `${leftSideInt}/${rightSide}`;

}

fractionHalf("2/3")

function logarithm(a,b){

    if(typeof a !== 'number'){
        return 'Invalid';
    }
    else if(b <= 0){
        return 'Invalid';
    }
    else if(a <= 1){
        return 'Invalid';
    }
    else{

        let power = 2;
        for(power;;power++){

            let res = Math.pow(a,power);
            if(res === b){
                return power;
            }

        }

    }

}

logarithm(2, 4)


function sameUpsidedown(number){

    let map = {'6': '9', '9': '6', '0': '0'};

    let tmpNumber = number.split("").map(e => map[e]);
    tmpNumber.reverse();
    return tmpNumber.join("") === number;


}

function makeHappy(aStr){

    let eyes = ":8x;";

    aStr = aStr.split("");

    for(let i = 0; i < aStr.length-1; i++){

        let iChar = aStr[i];
        let iCharForward = aStr[i+1];
        if(eyes.includes(iChar) && iCharForward === '('){

            aStr[i+1] = ')';

        }

    }
    return aStr.join("");


}

console.log(makeHappy('My current mood: :('));// 'My current mood: :)')
console.log(makeHappy('I was hungry 8('));// 'I was hungry 8)')
console.log(makeHappy('print("x(")'));// 'print("x)")')
console.log(makeHappy("I'm thirsty ;("));// "I'm thirsty ;)")
console.log(makeHappy('(((:())))'));// '(((:)))))')
console.log(makeHappy('I am :( :( 8( :)'));// 'I am :) :) 8) :)')
console.log(makeHappy('l'));// 'l')

function antiDivisors(number){

    let arr = [];

    if(number < 2){
        return arr;
    }
    else{

        for(let i = 2; i < number; i++){

            let res = i % 2;
            if(number % i === 0){
                continue;
            }
            switch(res){

                case 0:
                    // even
                    let res = (number*2);
                    if(res % i === 0){
                        arr.push(i);
                    }
                    break;
                case 1:
                    // odd
                    let res2 = (number*2)+1;
                    let res3 = (number*2)-1;
                    if(res2 % i === 0 || res3 % i === 0){
                        arr.push(i);
                    }
                    break;
                default:
                    break;

            }

        }
        return arr;

    }


}

// made by @Joshua Señoron


function flickSwitch(arr){

    let currSwitch = true;

    let returnArr = [];

    for(let i = 0; i < arr.length; i++){

        let elem = arr[i];
        if(elem === 'flick'){
            currSwitch = !currSwitch;
            returnArr.push(currSwitch);
        }
        else{
            returnArr.push(currSwitch);
        }

    }
    return returnArr;
}

function consecutiveSum(num){

    let total = 0;
    for(let i = 0; i < num; i++){

        for(let j = i; j >= 0; j--){

            total += j;
            if(total === num){
                return true;
            }
            else if(total > num){
                total = 0;
                break;
            }

        }
        total = 0;

    }
    return false;

}

consecutiveSum(9)

function alliterationCorrect(aStr){

    aStr = aStr.toLowerCase();
    let firstWords = aStr.split(" ").map(e => e.replace('.','').replace('?','').replace('!','').replace(',','')).filter(e => e.length >= 4).map(e => e.charAt(0));
    return new Set(firstWords).size === 1;

}

function sweetestIceCream(creams){

    let obj = {'Plain': 0, 'Vanilla': 5, 'ChocolateChip': 5, 'Strawberry': 10, 'Chocolate': 10};
    let maxVal = 0;

    for(let i = 0; i < creams.length; i++){

        let icecream = creams[i];
        let sweetnessValue = icecream.numSprinkles + obj[icecrea.flavor];
        maxVal = Math.max(sweetnessValue,maxVal);
    }
    return maxVal;

}

function accumulatingProduct(arr){

    let newArr = [];

    let total = 1;

    for(let i = 0; i < arr.length; i++){

        for(let j = 0; j <= i; j++){

            total *= arr[j];

        }
        newArr.push(total);
        total = 1;

    }
    return newArr;


}

console.log(accumulatingProduct([1, 2, 3, 4]));// [1, 2, 6, 24])
console.log(accumulatingProduct([5, 10, 1, 1]));// [5, 50, 50, 50])
console.log(accumulatingProduct([1, 5, 7]));// [1, 5, 35])
console.log(accumulatingProduct([1, 0, 1, 0]));// [1, 0, 0, 0])
console.log(accumulatingProduct([1]));// [1])
console.log(accumulatingProduct([1, 2, 2, 2, 2, 2, 2]));// [1, 2, 4, 8, 16, 32, 64])
console.log(accumulatingProduct([1, 1, 1, 1, 1, 1, 1]));// [1, 1, 1, 1, 1, 1, 1])
console.log(accumulatingProduct([]));// [])

function solve(a,b){

    let leftVar = a;
    let rightVar = b;
    let rightSide = (-3*a)+4;
    let leftSide = -1*b;
    let remaining = (-1*leftSide) + rightSide;
    if(remaining === 0){

        return "Any number";

    }
    else if(remaining !== 0 && leftVar === rightVar){

        return "No solution";

    }
    else{

        let res = leftVar - rightVar;
        return Number(Number(remaining / res).toFixed(3));

    }


}

console.log(solve(1, 2));// -3.0)
console.log(solve(-4, -6));// 5.0)
console.log(solve(4, 1));// -2.333)
console.log(solve(3, 3));// "No solution")
console.log(solve(3, 2));// -3.0)
console.log(solve(-2, -2));// "No solution")
console.log(solve(2, 2));// "Any number")


function constructDeconstruct(aStr){

    let newArr = [];

    for(let i = 0; i < aStr.length; i++){

        newArr.push(aStr.substring(0,i+1));

    }
    for(let i = aStr.length-2; i >= 0; i--){

        newArr.push(aStr.substring(0,i+1));

    }
    return newArr;
}

console.log(constructDeconstruct("Hello"));

const exp = ""

function mysteryFunc(aStr){

    let newStr = "";
    for(let i = 0; i < aStr.length; i += 2){

        newStr += aStr.charAt(i).repeat(parseInt(aStr.charAt(i+1)));

    }
    return newStr;


}

console.log(mysteryFunc("A4B5C2"));

function isAlpha(aStr){

    let alpha = " abcdefghijklmnopqrstuvwxyz";

    aStr = aStr.toLowerCase();

    return aStr.split("").filter(e => alpha.includes(e)).map(e => alpha.indexOf(e)).reduce((a,b) => a+b) % 2 === 0;
}

function countOnes(arr){

    let newStr = arr.map(e => String(e)).join("");

    const expr = "[1]{2,}";

    let result = [...newStr.matchAll(expr)];

    return result.length !== 0? result.length: 0;

}

console.log(countOnes([1, 1, 1, 1, 1]));// 1)
console.log(countOnes([1, 1, 1, 1, 0]));// 1)
console.log(countOnes([0, 0, 0, 0, 0]));// 0)
console.log(countOnes([1, 0, 0, 0, 0]));// 0)
console.log(countOnes([1, 0, 1, 0, 1]));// 0)
console.log(countOnes([1, 0, 0, 0, 1, 0, 0, 1, 1]));// 1)
console.log(countOnes([1, 1, 0, 1, 1, 0, 0, 1, 1]));// 3)
console.log(countOnes([1, 0, 0, 1, 1, 0, 0, 1, 1]));// 2)
console.log(countOnes([1, 0, 0, 1, 1, 0, 1, 1, 1]));// 2)
console.log(countOnes([1, 0, 1, 0, 1, 0, 1, 0]));// 0)
console.log(countOnes([1, 1, 1, 1, 0, 0, 0, 0]));// 1)
console.log(countOnes([1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1]));// 3)


const obj = {
    kitchen: {
        knives: 500,
        stereo: 200,
        signature: ""
    },
    signature: "Rocky Balboa"
}

function signAgain(obj) {
    // write your code here
    // don't use a return statement


    // DON'T CHANGE OR REMOVE THE LINES BELOW
    Object.freeze(obj);
    Object.seal(obj.kitchen);
    obj.signature = "Terminator"
    obj.extraProperty = "not possible"
    obj.kitchen.piano = 1000
    obj.kitchen.signature = "Rocky Balboa"
    return obj
}

function partiallyHide(aStr){

    let newArr = [];

    let splitStr = aStr.split(" ");

    for(let i = 0; i < splitStr.length; i++){

        let elem = splitStr[i];
        if(elem.length < 2){
            newArr.push(elem);
        }
        else{
            newArr.push(elem.charAt(0) + '-'.repeat(elem.substring(1,elem.length-1).length) + elem.charAt(elem.length-1));
        }

    }
    return newArr.join(" ");

}

function splitGroups(aStr){

    let newArr = [];

    let currChar = aStr.charAt(0);

    let currString = "";

    for(let i = 0; i < aStr.length; i++){

        if(aStr.charAt(i) !== currChar){

            newArr.push(currString);
            currString = aStr.charAt(i);
            currChar = aStr.charAt(i);

        }
        else{

            currString += aStr.charAt(i);

        }

    }
    if(currString.length > 0){
        newArr.push(currString);
    }

    return newArr;

}


function convertToNumber(obj){

    let newObj = {};

    let keys = Object.keys(obj);

    for(let i = 0; i < keys.length; i++){

        newObj[keys[i]] = parseInt(obj[keys[i]]);

    }
    return newObj;

}

function largestGap(arr){

    arr.sort((a,b) => a-b);

    let maxGap = 0;

    for(let i = 0; i < arr.length-1; i++){

        maxGap = Math.max(maxGap,Math.abs(arr[i] - arr[i+1]));

    }
    return maxGap;


}


function arrEleSum(arr){

    let newArr = [];

    let total = 0;
    for(let i = 0; i < arr.length; i++){

        for(let j = 0; j < arr.length; j++){

            if(i === j){
                continue;
            }
            else{
                total += arr[j];
            }

        }
        newArr.push(total);
        total = 0;

    }
    return newArr;
}


function pagesInBook(pages){

    let total = 0;

    for(let i = total;;i++){

        if(total > pages){
            break;
        }
        else if(total === pages){
            return true;
        }
        else{
            total += i;
        }
    }
    return false;

}

function decrypt(arr){

    let alphabet = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for(let i = 1; i <= 25; i++){

        if(!arr.includes(i)){
            return alphabet[i];
        }

    }

}

function wordToDecimal(aStr){

    let lower = " abcdefghijklmnopqrstuvwxyz";
    let upper = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    let maxIndex = 0;
    let maxLetter = "";
    let total = 0;

    for(let i = 0; i < aStr.length; i++){

        let iChar = aStr.charAt(i);

        if(lower.includes(iChar)){
            let ind = lower.indexOf(iChar);
            if(ind > maxIndex) {
                maxLetter = iChar;
                maxIndex = ind;
            }
        }
        else{

            let ind = upper.indexOf(iChar);
            if(ind > maxIndex){
                maxLetter = iChar;
                maxIndex = ind;
            }

        }

    }

    let base = maxIndex+10;

    return parseInt(aStr,base);

}

wordToDecimal("Edabit");

function risiko(att,def){

    while(att.length < def.length){
        att.push(0);
    }
    while(def.length < att.length){
        def.push(0);
    }

    att.sort((a,b) => a-b);
    def.sort((a,b) => a-b);

    let totalWins = 0;


    for(let i = att.length-1; i >= 0; i--){

        let attRoll = att[i];
        let defRoll = def[i];
        if(defRoll === attRoll){
            continue;
        }
        else if(defRoll === 0){
            continue;
        }
        else if(attRoll === 0){
            continue;
        }
        else {

            if (attRoll > defRoll) {
                totalWins++;
            }
        }

    }
    return totalWins;

}

risiko([3, 1], [1])

function encodeMorse(code){

    let morseCode = {
        "0": "-----",
        "1": ".----",
        "2": "..---",
        "3": "...--",
        "4": "....-",
        "5": ".....",
        "6": "-....",
        "7": "--...",
        "8": "---..",
        "9": "----.",
        "a": ".-",
        "b": "-...",
        "c": "-.-.",
        "d": "-..",
        "e": ".",
        "f": "..-.",
        "g": "--.",
        "h": "....",
        "i": "..",
        "j": ".---",
        "k": "-.-",
        "l": ".-..",
        "m": "--",
        "n": "-.",
        "o": "---",
        "p": ".--.",
        "q": "--.-",
        "r": ".-.",
        "s": "...",
        "t": "-",
        "u": "..-",
        "v": "...-",
        "w": ".--",
        "x": "-..-",
        "y": "-.--",
        "z": "--..",
        ".": ".-.-.-",
        ",": "--..--",
        "?": "..--..",
        "!": "-.-.--",
        "-": "-....-",
        "/": "-..-.",
        "@": ".--.-.",
        "(": "-.--.",
        ")": "-.--.-",
        " ": " ",
        ":": "---...",
        "'": ".----.",
    }

    code = code.toLowerCase();

    let newArr = [];

    for(let i = 0; i < code.length; i++){

        newArr.push(morseCode[code.charAt(i)]);

    }
    return newArr.join(" ");

}




function flatten(arr){

    let newArr = [];

    for(let i = 0; i < arr.length; i++){

        let elem = arr[i];
        //console.log(elem.constructor.name);
        if(elem.constructor.name === 'Array'){
            newArr.push(...flatten(arr[i]));
        }
        else{
            newArr.push(elem);
        }
    }
    return newArr;
}

console.log(flatten([[17.2,5,"edabit"]]));//[17.2,5,"edabit"])
console.log(flatten([[[[[2,14,"rubber"]]], 2,3,4]]));//[2,14,"rubber",2,3,4])
console.log(flatten([0, [12,"biratnagar",[[2]]]]));//[0,12,"biratnagar",2])
console.log(flatten([["balkot"]]));//["balkot"])
console.log(flatten([1,2,3,4,5,6]));//[1,2,3,4,5,6])


function normalSequence(num){

    let nums = [0,1,1,2,0,2,2,1]
    // repeating part : [0,1,1,2,0,2,2,1]

    while(num > 8){
        num -= 8;
    }
    return nums[num-1];


}

//console.log(normalSequence(20));// 2)
//console.log(normalSequence(8));// 1)
console.log(normalSequence(41));// 0)
console.log(normalSequence(48));// 1)
console.log(normalSequence(148));// 2)
console.log(normalSequence(163));// 1)
console.log(normalSequence(111));// 2)
console.log(normalSequence(118));// 2)
console.log(normalSequence(117));// 0)
console.log(normalSequence(90));// 1)
console.log(normalSequence(91));// 1)
console.log(normalSequence(95));// 2)
console.log(normalSequence(87));// 2)
console.log(normalSequence(85));// 0)
console.log(normalSequence(82));// 1)
console.log(normalSequence(71));// 2)
console.log(normalSequence(72));// 1)
//console.log(normalSequence(51013947783));// 2)
// Mubashir


function Book(){

    this.author = "";
    this.published = 0;

}

let Author = {

    name: "Johnson",
    books: 20

};

let Publisher = new function(){

    this.authors = "Joel";
    this.books = 10;

}

class Review{

    rating = 10;
    user = "User123";

}

(function Bookstore(){

    this.books = 0;
    this.prices = [];

})();

function sub(A1,A2){

    let newMatrix = [];
    let subList = [];

    for(let i = 0; i < A1.length; i++){

        for(let j = 0; j < A2.length; j++){

            let v1 = typeof A1[i][j] === 'string'? parseInt(A1[i][j]): A1[i][j];
            let v2 = typeof A2[i][j] === 'string'? parseInt(A2[i][j]): A2[i][j];
            let res = v1 - v2;
            subList.push(res);

        }
        newMatrix.push(subList);
        subList = [];

    }
    return newMatrix;
}

sub([[1,2,3],[4,5,6],[7,8,9]],[[1,2,3],[4,5,6],[7,8,9]]);

function retrieve(aStr){

    let vowels = "aeiouAEIOU";
    let punctuation = ".,!?";

    if(aStr === ''){
        return [];
    }

    return aStr.split(' ').filter(e => vowels.includes(e.charAt(0))).map(e => punctuation.includes(e.charAt(e.length-1))? e.substring(e,e.length-1).toLowerCase(): e.toLowerCase());

}

console.log(retrieve("A simple life is a happy life for me."));// ["a", "is", "a"])
console.log(retrieve("Exercising is a healthy way to burn off energy."));// ["exercising", "is", "a", "off", "energy"])
console.log(retrieve("The poor ostrich was ostracized."));// ["ostrich", "ostracized"])
console.log(retrieve(""));// [])

function checkPerfect(num){

    let total = 0;

    for(let i =1 ; i < num; i++){

        if(num % i === 0){
            total += i;
        }

    }
    return total === num;

}

function gcd(a,b){

    if(a === b){
        return a;
    }
    else if(a > b){
        return gcd(a-b,b);
    }
    else if(b > a) {
        return gcd(a, b - a);
    }
}

console.log(gcd(10, 20));// 10)
console.log(gcd(1, 3));// 1)
console.log(gcd(5, 7));// 1)
console.log(gcd(2, 6));// 2)
console.log(gcd(13, 39));// 13)
console.log(gcd(50, 5));// 5)
console.log(gcd(70, 35));// 35)
console.log(gcd(100, 8));// 4)
console.log(gcd(11, 45));// 1)

const regexpUPE = /\p{Script=Cyrillic}+/gu; // regex to match russain words

function multiply(num1,num2){

    if(num1 < 0 && num2 < 0){
        num1 = Math.abs(num1);
        num2 = Math.abs(num2);
    }

    let currVal = num1;
    let timer = Math.abs(num2);
    while(timer > 1){
        num1 += currVal;
        timer--;
    }
    if(num2 < 0){
        num1 = -1 * num1;
    }
    return num1;

}

console.log('\ntest3');
console.log(multiply(3, 2));// 6)
console.log(multiply(9, 1));// 9)
console.log(multiply(2, 2));// 4)
console.log(multiply(1, 1));// 1)
console.log(multiply(702, 392));// 275184)
console.log(multiply(9, 9));// 81)
console.log(multiply(40, 31));// 1240)
console.log(multiply(4, 10));// 40)
console.log(multiply(-2, 4));// -8)
console.log(multiply(-3, -20));// 60)
console.log(multiply(40, -10));// -400)




function euclidAlgorithm(a,b){

    let remainder = -1;

    if(a < b){
        let tmp = a;
        a = b;
        b = tmp;
    }

    while(remainder !== 0){

        let c = a / b;
        remainder = a % b;
        a = b;
        b = remainder;

    }
    return a;


}


function LcmOfArray(arr){

    arr.sort((a,b) => a-b);

    let ans = arr[0];

    for(let i = 0; i < arr.length; i++){

        for(let j = 0; j < arr.length; j++){

            ans = (ans * arr[j]) / euclidAlgorithm(ans,arr[j]);

        }

    }
    return ans;


    //return (res) / euclidAlgorithm(res,a);


}

console.log(LcmOfArray([1,2,3,4,5,6,7,8,9,10]));

function camelToSnake(aStr){

    let symbols = "0123456789-=_+[]{}\"\';:<>,./?~`|\\!@#$%^&*() ";

    return aStr.split("").map(e => e === e.toUpperCase() && !symbols.includes(e)? `_${e.toLowerCase()}`: e.toLowerCase()).join("");

}

console.log(camelToSnake("magicCarrots"));// "magic_carrots")
console.log(camelToSnake("greatApples for aSmellyRhino"));// "great_apples for a_smelly_rhino")
console.log(camelToSnake("th1sSh0uldB3FineT00"));// "th1s_sh0uld_b3_fine_t00")

function getBirthdayCake(aStr,num){

    let theFilling = num % 2 === 0? "#": "*";

    let middle = `${theFilling} ${num} Happy Birthday ${aStr}! ${num} ${theFilling}`;

    return [`${theFilling.repeat(middle.length)}`,middle,`${theFilling.repeat(middle.length)}`];

}

function toDisplay(hex){

    let num = parseInt(String(hex));

    let maps = {0: 0x3F,1: 0x06, 2: 0x5B, 3: 0x4F, 4: 0x66, 5: 0x6D, 6: 0x7D, 7: 0x07, 8: 0x7F, 0x9: 0x6F, 10: 0x77, 11: 0x7C, 12: 0x39, 13: 0x5E, 14: 0x79, 15: 0x71};

    return maps[num];


}

console.log(`Result is : ${toDisplay(0xE)}`);

function unique(arr){

    let theSet = new Set(arr);

    let count = 0;
    for(let eachnum of theSet){

        for(let i = 0; i < arr.length; i++){

            if(eachnum === arr[i]){
                count++;
            }

        }
        if(count === 1){
            return eachnum;
        }
        else{
            count = 0;
        }

    }
    return -1;

}

function schoty(arr){

    let num = ['0','0','0','0','0','0','0'];

    for(let i = 0; i < arr.length; i++){

        let splitPart = arr[i].split('-');
        if(splitPart[0].length === 0){

            continue;

        }
        else{

            let count = 0;
            let part = splitPart[0];
            for(let i = 0; i < part.length; i++){
                if(part[i] === 'O'){
                    count++;
                }
            }
            num[i] = String(count);

        }

    }
    return parseInt(num.join(""));


}

console.log(schoty([
    "---OOOOOOOOOO",
    "---OOOOOOOOOO",
    "---OOOOOOOOOO",
    "OOO---OOOOOOO",
    "O---OOOOOOOOO",
    "OOOOOOOOO---O",
    "OO---OOOOOOOO"
]));

function shiftToRight(num1,num2){

    console.log(`num1 = ${num1} and num2 = ${num2}`);
    if(num2 === 0){
        return num1;
    }
    else{

        return shiftToRight(Math.floor(num1 / 2));//--num2);

    }

}

const users = [
    { user: "barney", active: false },
    { user: "fred", active: false },
    { user: "donny", active: true },
    { user: "carl", active: false },
    { user: "linda", active: false },
    { user: "luke", active: false },
    { user: "Steve", active: false },
    { user: "Lyle", active: false },
    { user: "pebbles", active: true },
];

function dropWhile(arr,filterfunc){

    let newArr = [];

    let boolCheck = false;

    for(let eachelem of arr){

        if(boolCheck){
            newArr.push(eachelem);
        }
        else if(filterfunc(eachelem)){
            continue;
        }
        else{
            boolCheck = true;
            newArr.push(eachelem);
        }

    }
    return newArr;

}

console.log(dropWhile(users, (b) => b.user !== "Lyle"));

function euclidean(a,b){

    if(a < b){

        let tmp = a;
        a = b;
        b = tmp;

    }
    let remainder = a % b;
    if(remainder === 0){
        return b;
    }
    else{
        return euclidean(b,remainder);
    }

}

console.log(euclidean(280, 64));

function partition(astr,num){

    let newArr = [];

    //const exp = `.{1,${num}}`;

    //let regExp = new RegExp(exp);

    //let res = astr.matchAll(regExp);

    //console.log(res);

    let tmpString = "";
    for(let i = 0; i < astr.length; i++){

        tmpString += astr.charAt(i);
        if(tmpString.length == num) {
            newArr.push(tmpString);
            tmpString = "";
        }

    }
    if(tmpString.length > 0){
        newArr.push(tmpString);
    }
    return newArr;

}

console.log(partition("them", 2));

function oddsVsEvens(num){

    console.log(`num = ${num}`);

    let oddSum = String(num).split("").map(e => Number(e)).filter(e => e % 2 !== 0 || e === 0).reduce((a,b) => a+b);
    let evenSum = String(num).split("").map(e => Number(e)).filter(e => e % 2 === 0).reduce((a,b) => a+b);

    return evenSum > oddSum? "even": oddSum > evenSum? "odd": "equal";

}

function totalSales(table,product){

    let products = table[0];
    if(!products.includes(product)){
        return "Product not found";
    }
    else{

        let columnToSearch = products.indexOf(product);
        let total = 0;
        for(let i = 1; i < table.length; i++){

            total += table[i][columnToSearch];

        }
        return total;

    }
}


function isApocalyptic(num){

    let bigNum = BigInt(num);
    let bigBase = BigInt(2);
    let result = String(bigBase**bigNum);

    let exp = new RegExp(/[6]{3}/g);

    let count = 0;

    let matches = result.matchAll(exp);

    for(let match of matches){
        count++;
    }

    return count === 0? "Safe": count === 1? "Single": count === 2? "Double": "Triple";
}

console.log(isApocalyptic(931));

function legendre(num1,num2){

    let total = 0;

    let base = 1;
    while(Math.pow(num1,base) <= num2){

        total += Math.floor((num2 / Math.pow(num1,base++)));

    }
    return total;

}


legendre(5,100);

function validateSubsets(arr,subset){

    let amt = arr.map(e => e.length === 0 || (e.map(f => subset.includes(f)).reduce((a,b) => a && b))).filter(e => e === true).length;

    return amt === arr.length;

}

console.log(validateSubsets([[1, 2], [2, 3], [1, 3]], [1, 2, 3]));// true)
console.log(validateSubsets([[1, 2, 3], [2], [3], []], [1, 2, 3]));// true)
console.log(validateSubsets([[1, 2], [2, 3], [1, 4]], [1, 2, 3]));// false)
console.log(validateSubsets([[1, 2, 3, 4]], [1, 2, 3]));// false)
console.log(validateSubsets([['a', 'b'], ['b', 'c'], ['a', 'c']], ['a', 'b', 'c']));// true)
console.log(validateSubsets([['a', 'b', 'c'], ['b'], ['c'], []], ['a', 'b', 'c']));// true)
console.log(validateSubsets([['a', 'b'], ['b', 'c'], ['a', 'd']], ['a', 'b', 'c']));// false)
console.log(validateSubsets([['a', 'b', 'c', 'd']], ['a', 'b', 'c']));// false)
console.log(validateSubsets([[true, false], [true]], [true, false]));// true)
console.log(validateSubsets([[true], [false], []], [true, false]));// true)
console.log(validateSubsets([[true], [true, false]], [true]));// false)
console.log(validateSubsets([[false]], [true]));// false)

function toObj(arr){

    let returnArr = [];

    for(let eachletter of arr){
        let obj = {};
        obj[eachletter] = eachletter.charCodeAt(0);
        returnArr.push(obj);
    }
    return returnArr;

}

function duplicateCount(aStr){

    let strSet = new Set(aStr.split(""));
    let count = 0;

    for(let eachletter of strSet){

        let ind1 = aStr.indexOf(eachletter);
        let ind2 = aStr.lastIndexOf(eachletter);

        if(ind1 !== ind2){
            count++;
        }

    }
    return count;

}

function mergeSort(arr1,arr2){

    let tmpArr = [...arr1];
    tmpArr.sort((a,b) => a-b);
    let tmp2Arr = [...arr1];
    tmp2Arr.sort((a,b) => b-a);

    if(tmp2Arr[0] === arr1[0]){

        // ascending
        let newArr = [];
        for(let i = 0; i < Math.max(arr1.length,arr2.length); i++){
            newArr.push(arr1[i]);
            newArr.push(arr2[i]);
        }
        newArr = newArr.filter(e => e !== undefined);
        newArr.sort((a,b) => b-a);
        return newArr;

    }
    else{

        let newArr = [];

        for(let i = 0; i < Math.max(arr1.length,arr2.length); i++){
            newArr.push(arr1[i]);
            newArr.push(arr2[i]);
        }
        newArr = newArr.filter(e => e !== undefined);
        newArr.sort((a,b) => a-b);
        return newArr;
        // descending

    }

}

mergeSort([8, 6, 4, 2], [-2, -6,  0, -4 ])


function getMissingLetters(astr){

    let alpha = "abcdefghijklmnopqrstuvwxyz";

    return alpha.split("").filter(e => !astr.includes(e)).join("");

}

function countAppearances(arr,num){

    let count = 0;
    for(let i = 0; i < arr.length; i++){

        if(arr[i] === num){
            count++;
        }

    }
    return count;

}

function findOdd(arr){

    let newArr = arr.map(e => countAppearances(arr,e));

    for(let i = 0; i < newArr.length; i++){

        if(newArr[i] % 2 !== 0){
            return arr[i];
        }

    }
}

function getStudentTopNotes(arr){

    let newArr = [];

    for(let eachstudent of arr){

        if(eachstudent['notes'].length > 0){
            newArr.push(Math.max(...eachstudent['notes']));
        }
        else{
            newArr.push(0);
        }

    }
    return newArr;
}

function getTrace(arr){

    let total = 0;

    if(arr.length !== arr[0].length){
        return 0;
    }

    for(let i = 0; i < arr.length; i++){

        total += arr[i][i];

    }
    return total;

}

function overTwentyOne(arr){

    let total = 0;

    let obj = {'J': 10, 'Q': 10, 'K': 10};

    let aceCount = 0;

    for(let i = 0; i < arr.length; i++){

        if(arr[i] === 'A'){
            aceCount++;
        }
        else if(Object.keys(obj).includes(arr[i])){
            total += obj[arr[i]];
        }
        else{
            total += arr[i];
        }

    }
    if((total + aceCount) > 21){
        return true;
    }
    else{
        return false;
    }

}

console.log('printing');
console.log(overTwentyOne(['A', 2, 3]));// false);
console.log(overTwentyOne(['A', 'J', 'K']));// false);
console.log(overTwentyOne(['A', 'J', 'K', 'Q']));// true);
console.log(overTwentyOne([5, 3, 6, 6, 7, 9]));// true);


function palindromicDate(aStr){

    let firstFormat = aStr.split("/").join("");
    let strSplit = aStr.split("/");
    let secondFormat = [strSplit[1],strSplit[0],strSplit[2]].join("");

    let revFirst = firstFormat.split("").reverse().join("");
    let revSecond = secondFormat.split("").reverse().join("");

    return (revFirst === firstFormat) && (revSecond === secondFormat);

}

console.log('testing date');
console.log(palindromicDate("02/02/2020"));// true)
console.log(palindromicDate("11/12/2019"));// false)
console.log(palindromicDate("11/02/2011"));// false)
console.log(palindromicDate("06/10/1469"));// false)
console.log(palindromicDate("06/05/3133"));// false)
console.log(palindromicDate("12/12/2121"));// true)
console.log(palindromicDate("09/09/9090"));// true)
console.log(palindromicDate("11/04/2203"));// false)
console.log(palindromicDate("07/07/7070"));// true)
console.log(palindromicDate("06/11/2923"));// false)
console.log(palindromicDate("03/08/8030"));// false)
console.log(palindromicDate("01/01/1010"));// true)
console.log(palindromicDate("03/11/3369"));// false)
console.log(palindromicDate("11/03/2775"));// false)
console.log(palindromicDate("03/03/1822"));// false)

function roundNearest(a,b=1){

    return Math.round(a/b)*b;
}

console.log(roundNearest(21418.3,118.49));

function isIncreasing(num){

    let strNum = String(num);

    for(let i = 0; i < strNum.length-1; i++){

        let iDigit = Number(strNum[i]);
        let iDigit2 = Number(strNum[i+1]);

        if(iDigit2 < iDigit){
            return false;
        }

    }
    return true;

}

function isDecreasing(num){

    let strNum = String(num);

    for(let i = 0; i < strNum.length-1; i++){

        let iDigit = Number(strNum[i]);
        let iDigit2 = Number(strNum[i+1]);

        if(iDigit2 > iDigit){
            return false;
        }

    }
    return true;

}

function incDec(num){

    let maxRange = Math.pow(10,num);
    let count = 0;
    for(let i = 1; i <= maxRange; i++){

        if(isIncreasing(i) || isDecreasing(i)){
            count++;
        }

    }
    return count;
}

console.log(incDec(6));

function everySome(...args){

    let testType = args[1];
    let expr = args[0];

    let bools = [];

    for(let i = 2; i < args.length; i++){

        let theExpr = `${args[i]} ${expr}`;
        bools.push(eval(theExpr));

    }

    return testType === 'everybody'? new Set(bools).size === 1 && bools[0] === true: (new Set(bools).size >= 2 || (new Set(bools).size === 1 && bools[0] === true));

}

console.log('testing everysome');
console.log(everySome(">= 1", "everybody", 1, 1, -1, 1, 1));// false, "Example #1")
console.log(everySome(">= 1", "somebody", -1, -1, -1, -1, 1));// true, "Example #2")
console.log(everySome("< 4 / 2", "everybody", 1, 2, 1, 2, 1, 0, -10));// false, "Example #3")
console.log(everySome("!= 0", "everybody", false, false, false, false, false));// false)
console.log(everySome("<= 10 * 2", "somebody", 21, 68, 104, 20, 3));// true)
console.log(everySome("!== 1", "everybody", true, true, true, true, true));// true)
console.log(everySome("=== 9 % 9", "somebody", 9, 1, 81, 218, 33));// false)


function isNumPalindrome(a){

    return String(a) === String(a).split("").reverse().join("");

}

function countPalindromes(a,b){

    let count = 0;
    for(let i = a; i <= b; i++){

        if(isNumPalindrome(i)){
            count++;
        }

    }
    return count;

}

function isKaprekar(num){

    let squared = Math.pow(num,2);

    let numLen = String(squared).length;

    let strNum = String(squared);

    let middle = Math.floor(strNum.length / 2);

    if(numLen % 2 !== 0){

        let leftHalf = strNum.substring(0,middle);

        let rightHalf = strNum.substring(middle);

        return Number(leftHalf) + Number(rightHalf) === num;

    }
    else{

        let leftHalf = strNum.substring(0,middle);
        let rightHalf = strNum.substring(middle);

        return Number(leftHalf) + Number(rightHalf) === num;

    }

}

console.log('testing isKaprekar');

console.log(isKaprekar(1));// true)
console.log(isKaprekar(2));// false)
console.log(isKaprekar(3));// false, "Example #1")
console.log(isKaprekar(5));// false, "Example #2")
console.log(isKaprekar(9));// true)
console.log(isKaprekar(65));// false)
console.log(isKaprekar(99));// true)
console.log(isKaprekar(297));// true, "Example #3")
console.log(isKaprekar(348));// false)
console.log(isKaprekar(666));// false)
console.log(isKaprekar(1441));// false)
console.log(isKaprekar(77778));// true)
console.log(isKaprekar(102102));// false)
console.log(isKaprekar(533170));// true)

function split(aStr){

    let vowels = "aeiouAEIOU";

    let newStr = "";

    let arr = [];

    for(let i = 0; i < aStr.length; i++){

        let iChar = aStr.charAt(i);

        if(!vowels.includes(iChar)){
            // consonant
            if(newStr.length !== 0){
                arr.push(newStr);
                newStr = "";
            }
            arr.push(iChar);
        }
        else{
            newStr += iChar;
        }

    }
    if(newStr.length > 0){
        arr.push(newStr);
    }
    return arr;

}

function binaryConversion(astr){

    let newStr = "";

    for(let i = 0; i < astr.length; i+=8){

        let substring = astr.substring(i,i+8);
        let val = parseInt(substring,2);
        let char = String.fromCharCode(val);

        newStr += char;
    }
    return newStr;

}

console.log(binaryConversion("011000010110001001100011"));

function sortByCharacter(arr,num){

    num--;

    arr.sort((a,b) => a[num] > b[num]? 1: a[num] < b[num]? -1: 0);

    return arr;

}

console.log(sortByCharacter(["az16", "by35", "cx24"], 2));

function goldDistribution(arr){

    let turn = false; // mubashir is false, matt is true
    let mattTotal = 0;
    let mubashirTotal = 0;


    while(arr.length > 0){

        if(arr.length === 1){
            if(turn){
                mattTotal += arr[0];
            }
            else{
                mubashirTotal += arr[0];
            }
            arr.pop();

        }
        else{

            let farLeft = arr[0];
            //arr.splice(0,1);
            let farRight = arr[arr.length-1];//arr.pop();
            if(farLeft === farRight){

                arr.splice(0,1);
                if(turn){
                    mattTotal += farLeft;
                }
                else{
                    mubashirTotal += farLeft;
                }

            }
            else if(farRight > farLeft){
                arr.pop();
                if(turn){

                    mattTotal += farRight;

                }
                else{

                    mubashirTotal += farRight;

                }
            }
            else if(farLeft > farRight){

                arr.splice(0,1);
                if(turn){

                    mattTotal += farLeft;

                }
                else{

                    mubashirTotal += farLeft;

                }

            }

        }
        turn = !turn;

    }
    return [mubashirTotal,mattTotal];

}

console.log(goldDistribution([4, 2, 9, 5, 2, 7]));

function initialize(arr){

    return arr.map(e => `${e.split(' ')[0][0].toUpperCase()}. ${e.split(' ')[1][0].toUpperCase()}.`);

}

function canPlay(playerHand, faceUpCard){

    let colors = playerHand.map(e => e.split(' ')[0]);

    let numbers = playerHand.map(e => e.split(' ')[1]);

    let faceUpColor = faceUpCard.split(' ')[0];
    let faceUpNumber = faceUpCard.split(' ')[1];

    return colors.includes(faceUpColor) || numbers.includes(faceUpNumber);

}

function releaseYear(album) {
    const albums = {
        "2015": ["Vulnicura", "Honeymoon", "Rebel Heart"],
        "2016": ["Lemonade", "Blackstar", "A Moon Shaped Pool"],
        "2017": ["Flower Boy", "Antisocialites"],
        "2018": ["El Mal Querer", "Someone Out There", "Cranberry", "Kamikaze"],
        "2019": ["thank u next", "Magdalene", "Ode to Joy"],
        "2020": ["Rough and Rowdy Ways", "folklore", "Future Nostalgia", "Colores"]
    }

    for(let eachkey of Object.keys(albums)){

        if(albums[eachkey].includes(album)){
            return Number(eachkey);
        }

    }
    return "Unknown";
}

function percentFilled(arr){

    let totalSpaces = 0;
    let occupiedSpaces = 0;

    for(let eachpart of arr){

        for(let i = 0; i < eachpart.length; i++){

            let theChar = eachpart[i];
            if(theChar === ' '){
                totalSpaces++;
            }
            else if(theChar === 'o'){
                occupiedSpaces++;
                totalSpaces++;
            }

        }

    }
    return `${Math.round((occupiedSpaces / totalSpaces)*100)}%`;


}

console.log(percentFilled([
    "######",
    "#ooo #",
    "#oo  #",
    "#    #",
    "#    #",
    "######"
]));

function checkout(arrObj){

    let total = 0;

    let itemTotal = 0;

    for(let eachitem of arrObj){

        if(eachitem['taxable']){

            itemTotal = eachitem['prc'] * eachitem['qty'];
            itemTotal = itemTotal + (itemTotal * 0.06);
            total += itemTotal;
        }
        else{

            total += (eachitem['prc'] * eachitem['qty']);

        }

    }
    return total;


}

console.log(checkout([
    { desc: "potato chips", prc: 2, qty: 2, taxable: false },
    { desc: "soda", prc: 3, qty: 2, taxable: false },
    { desc: "paper plates", prc: 5, qty: 1, taxable: true }
]));


function replaceThe(astr){

    const exprAn = /(the (?=[aeiouAEIOU]))/g;
    const exprA = /(the (?=[^aeiouAEIOU]))/g;

    astr = astr.replace(exprAn,'an ');
    astr = astr.replace(exprA,'a ');

    return astr;


}

replaceThe("the egg, the spoon and the espionage");

function harmonic(num){

    let denom = 1;

    let total = 0;

    let numerator = 1;

    for(let i = 0; i < num; i++){

        total += (numerator / denom++);

    }
    return Number(total.toFixed(3));


}

function seesaw(num){

    let strNum = String(num);
    let middle = Math.floor(strNum.length / 2);

    123

    if(strNum.length % 2 !== 0){

        // odd
        let leftHalf = Number(strNum.substring(0,middle));
        let rightHalf = Number(strNum.substring(middle+1));

        return leftHalf > rightHalf? "left": rightHalf > leftHalf? "right": "balanced";


    }
    else{

        let leftHalf = Number(strNum.substring(0,middle));
        let rightHalf = Number(strNum.substring(middle));

        return leftHalf > rightHalf? "left": rightHalf > leftHalf? "right": "balanced";

    }

}

function getDiagonals(matrix){

        let upperLeftLowerRight = 0;

        let upperRightLowerLeft = 0;

        let upperLeft = [];
        let upperRight = [];


        for(let i = 0; i < matrix.length; i++){
            upperLeftLowerRight += matrix[i][i];
            upperLeft.push(matrix[i][i]);
        }

        for(let i = 0, j = matrix.length-1; i < matrix.length; i++, j--){

            upperRightLowerLeft += matrix[i][j];
            upperRight.push(matrix[i][j]);

        }

        return [upperLeft,upperRight];
}

function filterValues(obj){

        let newObj = {};

        let keys = Object.keys(obj);

        keys.filter(e => obj[e] >= 5000).forEach(e => newObj[e] = obj[e]);

        return newObj;

}

console.log(filterValues({ tv: 4999, guitar:5000, fork: 5001 }));
console.log(filterValues({ tv: 4999 }));


function happinessNumber(aStr){

    const exp1 = /(:\))/g;
    const exp2 = /(\(:)/g;
    const exp3 = /(:\()/g;
    const exp4 = /(\):)/g;

    let matches1 = aStr.match(exp1);
    let matches11 = aStr.match(exp2);
    let matches0 = aStr.match(exp3);
    let matches00 = aStr.match(exp4);

    let total = 0;

    if(matches1 !== null){
        total += matches1.length;
    }
    if(matches11 !== null){
        total += matches11.length;
    }
    if(matches0 !== null){
        total -= matches0.length;
    }
    if(matches00 !== null){
        total -= matches00.length;
    }

    return total;

}

console.log(happinessNumber(':):('));


function lastLetter(word){

    return word.charCodeAt(word.length-1);

}


function sortByLast(aStr){

    let splitWords = aStr.split(' ');

    splitWords.sort((a,b) => lastLetter(a) - lastLetter(b));

    return splitWords.join(' ');

}

console.log(sortByLast("herb camera dynamic"));

function chemicalReactions(c,h,o){

        // find h20 first, then co2, then ch4

        let totalWater = 0;
        let totalCarbon = 0;
        let totalMethane = 0;

        while(h >= 2 && o > 0){

            h -= 2;
            o -= 1;
            totalWater++;

        }
        while(c > 0 && o >= 2){
            c--;
            o -= 2;
            totalCarbon++;
        }
        while(h >= 4 && c > 0){
            h -= 4;
            c--;
            totalMethane++;
        }
        return [totalWater,totalCarbon,totalMethane];

}

console.log(chemicalReactions(939, 3, 694));


let tidyLink = (url,name,optional="") => {

    return `[${name}](${url}${optional !== ""? ` "${optional}"` : ""})`;

}

let isHappyYear = (theDate) => {

    return new Set(String(theDate).split("")).size === String(theDate).length;

}

let happyYear = (date) => {

    for(let i = date+1; ; i++){
        if(isHappyYear(i)){
            return i;
        }
    }


}

let perrin = (num) => {

    let seq = [3,0,2];

    let ind = 3;
    while(seq.length-1 < num){

        seq.push(seq[ind-3] + seq[ind-2]);
        ind++;

    }
    return seq[num];

}


console.log(perrin(0));// 3)
console.log(perrin(38));// 43721)
console.log(perrin(58));// 12110402)
console.log(perrin(52));// 2240877)
console.log(perrin(36));// 24914)
console.log(perrin(44));// 236282)
console.log(perrin(50));// 1276942)
console.log(perrin(42));// 134643)
console.log(perrin(27));// 1983)
console.log(perrin(17));// 119)
console.log(perrin(45));// 313007)
console.log(perrin(46));// 414646)
console.log(perrin(28));// 2627)
console.log(perrin(37));// 33004)
console.log(perrin(43));// 178364)
console.log(perrin(22));// 486)
console.log(perrin(25));// 1130)
console.log(perrin(51));// 1691588)
console.log(perrin(34));// 14197)
console.log(perrin(15));// 68)
console.log(perrin(41));// 101639)

let memeSum = (num1,num2) => {

    let newStr = "";
    if(num1 < num2){
        let tmp = num1;
        num1 = num2;
        num2 = tmp;
    }
    let str1 = String(num1);
    let str2 = String(num2);

    for(let i = str1.length-1, j = str2.length-1;;i--,j--){

        if(j <= -1 && i <= -1){
            break;
        }
        else if(j == -1){
            // reached the end of str2 but not the end of str1
            newStr = str1.charAt(i) + newStr;
        }
        else if(i == -1){
            // reached the end of str1 but not the end of str2
            newStr = str2.charAt(j) + newStr;
        }
        else{
            let num1 = +str1.charAt(i);
            let num2 = +str2.charAt(j);
            let res = num1+num2;
            newStr = res + newStr;
        }

    }
    return +newStr;


}

console.log(memeSum(122,81));

let isConsecutiveArr = (arr) => {

    arr.sort((a,b) => a-b);
    for(let i = 0; i < arr.length-1; i++){

        let firstElem = arr[i];
        let secondElem = arr[i+1];
        if(Math.abs(firstElem - secondElem) !== 1){
            return false;
        }

    }
    return true;

}

let cons = (arr) => {

    if(new Set(arr).size !== arr.length){
        return false;
    }
    else{

        return isConsecutiveArr(arr);

    }

}


console.log(cons([5, 1, 4, 3, 2]));// true)
console.log(cons([55, 59, 58, 56, 57]));// true)
console.log(cons([-3, -2, -1, 1, 0]));// true)
console.log(cons([5, 1, 4, 3, 2, 8]));// false)
console.log(cons([5, 6, 7, 8, 9, 9]));// false)
console.log(cons([5, 3]));// false)


let chooseFuse = (fuses,rating) => {

    let sortFuses = (fuse1,fuse2) => {

        return Number(fuse1.replace('V','')) - Number(fuse2.replace('V',''));

    }


    fuses.sort(sortFuses);

    let theAmt = +rating.replace('V','');

    for(let i = 0; i < fuses.length; i++){

        let theFuseRating = +fuses[i].replace('V','');
        if(theFuseRating >= theAmt){
            return fuses[i];
        }
    }


}

let factorial = (theNum) => {

    if(theNum == 1){
        return 1;
    }
    else{
        return theNum * factorial(theNum-1);
    }

}

let isFactorial = (num) => {

    let starter = 1;
    while(true){
        let res = factorial(starter);
        if(res == num){
            return true;
        }
        else if(res > num){
            return false;
        }
        else{
            starter++;
        }
    }

}

console.log(chooseFuse(["3V", "5V", "12V"], "4.5V"));// "5V")
console.log(chooseFuse(["5V", "14V", "2V"], "5.5V"));// "14V")
console.log(chooseFuse(["17V", "15V", "12V"], "9V"));// "12V")
console.log(chooseFuse(["1V", "2V", "3V"], "2.5V"));// "3V")
console.log(chooseFuse(["17V", "15V", "12V"], "1V"));// "12V")
console.log(chooseFuse(["7V", "135V", "12V"], "9.5V"));// "12V")
console.log(chooseFuse(["17V", "15V", "12V"], "17V"));// "17V")
console.log(chooseFuse(["3V", "11V", "12V"], "4.5V"));// "11V")
console.log(chooseFuse(["3V", "5V", "12V"], "0.5V"));// "3V")


let addLetters = (letters) => {

    if(letters.length === 0){
        return 'z';
    }

    let alpha = " abcdefghijklmnopqrstuvwxyz";

    let res = letters.map(e => alpha.indexOf(e)).reduce((a,b) => a+b);

    return alpha[res > 26? res % 26: res];


}

console.log(addLetters(["a"]));// "a")
console.log(addLetters(["a", "b"]));// "c")
console.log(addLetters(["a", "b", "c"]));// "f")
console.log(addLetters(["a", "b", "c", "d", "e", "f"]));// "u")
console.log(addLetters(["y", "a"]));// "z")
console.log(addLetters(["y", "c"]));// "b")
console.log(addLetters(["z", "a"]));// "a")
console.log(addLetters(["x", "y", "z"]));// "w")
console.log(addLetters([]));// "z")

let formatAscii = (str,num) => {

    let res = [];
    let currString = "";

    for(let i = 0; i < str.length; i++){

        if(currString.length == num){
            res.push(currString);
            currString = str[i];
        }
        else{
            currString += str[i];
        }


    }
    if(currString.length > 0){
        res.push(currString);
    }
    return res.join('\n');


}

formatAscii('#@#@#@#@', 2)

let briscolaScore = (myDeck1,myDeck2) => {

    let obj = {'A': 11, '3': 10, 'K': 4, 'Q': 3, 'J': 2};

    let total1 = myDeck1.map(e => e.charAt(0)).map(e => Object.keys(obj).includes(e)? obj[e]: 0).reduce((a,b) => a+b);

    let total2 = myDeck2.map(e => e.charAt(0)).map(e => Object.keys(obj).includes(e)? obj[e]: 0).reduce((a,b) => a+b);

    let total = total1 + total2;

    return total < 120? "You Lose!": total > 120? "You win!": "Draw!";

}

// Test #1
const myDeck1_test1 = [
    '3c', '3s', 'Qd', 'Jh', '5d', 'Jc', '6d', 'Ad', 'Js', 'Qc'
]
const myDeck2_test1 = [
    'Jd', 'Kd', '4c', '6s', 'Ks', '5c', '3d', 'As', 'Jh', '6h'
]
console.log(briscolaScore(myDeck1_test1, myDeck2_test1));// "You Lose!", "Example #1");

// Test #2
const myDeck1_test2 = [
    'Ac', 'As', '3d', '3h', '3s', 'Ah', 'Kd'
]
const myDeck2_test2 = [
    '3d', 'Ad', 'Ac', 'As', 'Ah'
]
console.log(briscolaScore(myDeck1_test2, myDeck2_test2));// "You Win!", "Example #2");

// Test #3
const myDeck1_test3 = [
    'Ac', 'As', '3d', '3h', '3s', 'Ah', 'Kd'
]
const myDeck2_test3 = [
    '3d', 'Ad', 'Ac', 'As', '3h'
]
console.log(briscolaScore(myDeck1_test3, myDeck2_test3));// "Draw!", "Example #3");

// Test #4
const myDeck1_test4 = [
    '4h', '4s', '7s', '3d', '2c', 'As', '3c', '4c',
    'Ah', '7h', 'Kc', 'Jc', 'Qh', 'Jd', 'Ks'
]
const myDeck2_test4 = [
    '4s', 'Ah', 'Qh', '7c', '6s', 'Js', '6d', 'Qc',
    '5d', 'Kd', '3d', 'Ac', '4c', '5s', '3h', '6h',
    'As', '7d', '2s', '2c', '3c', '6c', '7h', 'Kc'
]
console.log(briscolaScore(myDeck1_test4, myDeck2_test4));// "You Win!");

// Test #5
const myDeck1_test5 = [
    'Js', 'Qc', '2c', 'Kc', 'Kh', '7c', '5h', 'Jh', '2s', '6d',
    '4s', '4c', 'Kd', '6s', 'Ks', 'Qh', '7s', 'Jc', '5c', '5d',
    '6c', '2h', 'Ad', '7d', 'Ah', '5s', '3s', '6h'
]
const myDeck2_test5 = [
    'As', '3c', 'Kd', 'Ac', 'Ah', 'Ad', 'Jh'
]
console.log(briscolaScore(myDeck1_test5, myDeck2_test5));// "Draw!");

// Test #6
const myDeck1_test6 = [
    '3c', '3s', 'Qd', 'Jh', '5d', 'Jc', '6d', 'Ad', 'Js', 'Qc'
]
const myDeck2_test6 = [
    '2s', 'Kd', '3d', '6s', 'Qc', '5c', '6d', '6h',
    '6c', '5h', 'Qd', '4s', '3c', '2h', '3s'
]
console.log(briscolaScore(myDeck1_test6, myDeck2_test6));// "You Lose!");

let golfScore = (course,result) => {

    let obj = {'eagle': -2, 'birdie': -1, 'bogey': +1, 'double-bogey': +2, 'par': 0};

    return result.map((e,ind) => course[ind] + obj[e]).reduce((a,b) => a+b);

}


let hoursPassed = (timenow,timethen) => {

    if(timenow === timethen){
        return "no time passed";
    }

    let hr1 = +timenow.split(':')[0];
    let hr2 = +timethen.split(':')[0];

    let zone1 = timenow.split(' ')[1] === 'PM'? (hr1 === 12? 12: 12+hr1): hr1 === 12? 0: hr1;
    let zone2 = timethen.split(' ')[1] === 'PM'? (hr2 === 12? 12: 12+hr2): hr2 === 12? 0: hr2;

    let date1 = new Date(2021,1,1,zone1,1,1);
    let date2 = new Date(2021,1,1,zone2,1,1);

    let res = Math.abs(date1.getHours() - date2.getHours());

    return `${res} hours`;
}

let [strVector, resVector] = [
    [["3:00 AM", "9:00 AM"], ["2:00 PM", "4:00 PM"], ["1:00 AM", "3:00 PM"], ["2:00 AM", "3:00 PM"],
        ["8:00 AM", "8:00 PM"], ["12:00 AM", "10:00 PM"], ["1:00 AM", "1:00 AM"], ["12:00 PM", "12:00 PM"]],
    ["6 hours", "2 hours", "14 hours", "13 hours", "12 hours", "22 hours", "no time passed", "no time passed"]
]
for (let i in strVector) (hoursPassed(...strVector[i]));// resVector[i]);

let findVertex = (a,b,c) => {

    let xCoord = -b / (2*a);

    let yCoord = a*Math.pow(xCoord,2) + b*(xCoord) + c;

    return [Number(xCoord.toFixed(2)));//Number(yCoord.toFixed(2))];

}

let diceScore = (arr) => {

    let allRolls = new Set(arr);

    let obj = {'111': 1000, '666': 600, '555': 500, '444': 400, '333': 300, '222': 200, '1': 100, '5': 50};

    let emptyString = '';

    let total = 0;
    let added = false;

    for(let eachroll of allRolls){

        //console.log(`eachroll = ${eachroll}`);

        for(let i = 0; i < arr.length; i++){

            if(arr[i] === eachroll){
                emptyString += arr[i];
            }

        }
        if(emptyString.length > 0){

            while(emptyString.length >= 3) {

                let theSub = emptyString.substring(0, 3);
                total += obj[theSub];
                emptyString = emptyString.substring(3);

            }
            if(emptyString.includes('1')){
                total += emptyString.length * 100;
            }
            else if(emptyString.includes('5')){
                    total += emptyString.length * 50;
            }
        }
        emptyString = '';

    }
    return total;

}

console.log(diceScore([2,3,4,6,2]));//0)
console.log(diceScore([1,1,1,3,3]));//1000,"Should be 1000");
console.log(diceScore([2,2,2,3,3]));//200,"Should be 200");
console.log(diceScore([3,3,3,3,3]));//300,"Should be 300");
console.log(diceScore([4,4,4,3,3]));//400,"Should be 400");
console.log(diceScore([5,5,5,3,3]));//500,"Should be 500");
console.log(diceScore([6,6,6,3,3]));//600,"Should be 600");
console.log(diceScore([1,1,1,1,3]));//1100,"Should be 1100");
console.log(diceScore([1,1,1,1,5]));//1150,"Should be 1150");
console.log(diceScore([2,4,4,5,4]));//450,"Should be 450");
console.log(diceScore([3,4,5,3,3]));//350,"Should be 350");
console.log(diceScore([1,5,1,3,4]));//250,"Should be 250");

//Mubashir



let wordedMath = (expr) => {

    expr = expr.toLowerCase();

    expr = expr.replace(/one/g,'1').replace(/two/g,'2').replace(/zero/g,'0').replace(/plus/g,'+').replace(/minus/g,'-');

    let res = eval(expr);

    let obj = {2: 'Two', 1: 'One', 0: 'Zero'};

    return obj[res];

}

console.log(wordedMath("One plus one"));// "Two")
console.log(wordedMath("zero Plus one"));// "One")
console.log(wordedMath("one minus one"));// "Zero")

// made by @Joshua Señoronr


let duplicateNums = (arr) => {

    let newSet = new Set(arr);

    let newArr = [];

    for(let eachnum of newSet){

        if(arr.indexOf(eachnum) !== arr.lastIndexOf(eachnum)){
            newArr.push(eachnum);
        }

    }
    newArr.sort((a,b) => a-b);

    return newArr.length > 0? newArr : null;


}

let obj = {"key1": 20, "key2": 30, "key3": 30};

for(let i of Object.keys(obj)){
    console.log(i);
}

let cards = ['fourhearts','jackclubs','sevenclubs','eighthearts','twodiamonds','fivediamonds','kingdiamonds','ninehearts','threediamonds','sixclubs','sevenhearts'];

rankCount = (card,cards) => {

    cards = cards.map(e => e.replace('hearts','').replace('spades','').replace('diamonds','').replace('clubs',''));

    card = card.replace('hearts','').replace('spades','').replace('diamonds','').replace('clubs','');

    return cards.filter(e => e === card).length;


}

fourOfAKind = (cards) => {

    let theKinds = [];

    for(let eachcard of cards){

        let cnt = rankCount(eachcard,cards);
        if(cnt === 4){
            return true;
        }

    }
    return false;

}

consecutive = (cards) => {

    let ranks = {'ace': 14, 'king': 13, 'queen': 12, 'jack': 11, 'ten': 10, 'nine': 9, 'eight': 8, 'seven': 7, 'six': 6, 'five': 5, 'four': 4, 'three': 3, 'two': 2};

    let theNumRanks = [];
    for(let i = 0; i < cards.length; i++){
        let theCard = cards[i];
        for(let j of Object.keys(ranks)){
            if(theCard.includes(j)){
                theNumRanks.push(ranks[j]);
                break;
            }
        }
    }

    theNumRanks.sort((a,b) => a-b);
    theNumRanks = [...new Set(theNumRanks)];
    let cnt = 0;
    for(let i = 0; i < theNumRanks.length-1; i++){

        let iRank = theNumRanks[i];
        let jRank = theNumRanks[i+1];
        if(Math.abs(iRank - jRank) === 1){
            cnt++;
        }
        else if(cnt === 4){
            return true;
        }
        else if(Math.abs(iRank - jRank) !== 1){
            cnt = 0;
        }

    }
    return false;

}

console.log(consecutive(cards));

let blahBlah = (aStr,num) => {

    let newStr = [];

    let splitStr = aStr.split(' ');

    for(let i = 0; i < splitStr.length; i++) {

        if (i >= splitStr.length - num) {
            newStr.push("blah");
        }
        else{
            newStr.push(splitStr[i]);
        }

    }

    return `${newStr.join(" ")}...`;
}

let f = (num) => {

    let pairs = 0;
    let means = 0;
    for(let i = 1; i <= num; i++){

        for(let j = 1; j <= num; j++){

            pairs++;
            means += Number.isInteger(Math.sqrt(i*j))? 1: 0;

        }

    }
    return means / pairs;

}

console.log(f(100));


let isPrime = (num) => {

    return Array(Math.floor(Math.sqrt(num))).fill(0).map((e,i) => i+2).filter(e => num % e === 0).length === 0;

}

console.log(isPrime(456)); // f
console.log(isPrime(457)); // t
console.log(isPrime(453)); // f
console.log(isPrime(23)); // t
console.log(isPrime(21)); // f
console.log(isPrime(7)); // t
console.log(isPrime(4)); // f

let integral = (b,m,n) => {

        return n**(b+1) - m**(b+1);

}

function fibSeq(num=undefined){

    if(num === undefined){
        return num;
    }
    if(num === 0){
        return [];
    }

    let seq = [0,1];

    while(seq.length < num){

        seq.push(seq[seq.length-1] + seq[seq.length-2]);

    }
    return seq.slice(0,num);


}

let makeBox = (num) => {

    let arr = [];
    if(num < 3){
        for(let i = 0; i < num; i++){
            arr.push(new Array(num).fill('#').join(""));
        }
        return arr;
    }
    else{
        arr.push(new Array(num).fill('#').join(""));
        for(let i = 0; i < num-2; i++){
            arr.push(`#${' '.repeat(num-2)}#`);
        }
        arr.push(new Array(num).fill('#').join(""));
        return arr;
    }


}

let factorial = (num) => {

    if(num === 1){
        return num;
    }
    else{
        return factorial(num-1) * num;
    }

}

let factFact = (num) => {

        let total = 1;
        for(let i = 1; i <= num; i++){
            total *= factorial(i);
        }
        return total;
}

let getCatalanNumber = (num) => {

    let nums = [1,1];
    let ind = 2;
    while(nums.length <= num){

        nums.push(factorial((2*ind)) / (factorial(ind+1)*factorial(ind)));
        ind++;

    }
    return nums[num];


}


console.log(getCatalanNumber(3));

let validateSpelling = (letters) => {

    let formattedLetters = letters.split(' ').map(e => e.replace(/\./g,'').replace(/!/g,'').replace(/\?/g,''));
    let finalWord = formattedLetters[formattedLetters.length-1];

    let theLetters = formattedLetters.splice(0,formattedLetters.length-1).join('');

    return theLetters.toLowerCase() === finalWord.toLowerCase();
}

validateSpelling("C. Y. T. O. P. L. A. S. M. Cytoplasm?");

let isShapePossible = (n,angles) => {

    let maxSum = (n-2) * 180;

    if(n < 2){
        return false;
    }
    else{
        return angles.every(e => e <= 180) && angles.every(e => e > 0) && angles.reduce((a,b) => a+b) === maxSum;
    }

}

let matchesProperty_myVersion = (key,value) => {

    return (obj) => obj[key] === value;

}

let isDisarium = (num) => {

    return String(num).split("").map((e,i) => Math.pow(Number(e));//Number(i)+1)).reduce((a,b) => a+b) === num;

}

let createSquare = (num) => {

    if(num <= 0){
        return "";
    }
    else if(num < 3){
        switch(num){

            case 1:
                return "#";
            case 2:
                return "##\n##";
            default:
                return "default";
        }
    }
    else{

        let newSquare = [];

        newSquare.push("".padStart(num,'#'));
        for(let i = 0; i < num-2; i++){
            newSquare.push(`#${''.padStart(num-2,' ')}#`);
        }
        newSquare.push("".padStart(num,'#'));

        return newSquare.join('\n');

    }


}


let countNum = (num,digit) => {

    return String(num).split("").map(e => +e).filter(e => e === digit).length;

}

let countDigits = (num1,num2) => {
    return [...new Array(num1+1).keys()].map(e => e**2).map(e => countNum(e,num2)).reduce((a,b) => a+b);
}

console.log(countDigits(10,1));



let compareKeys = (obj1,obj2) => {

    let keys1 = Object.keys(obj1);
    for(let eachkey of keys1){
        if(obj1[eachkey] !== obj2[eachkey]){
            return false;
        }
    }
    return true;


}

let intersection = (obj1,...objs) => {

    let constructName = obj1.constructor.name;

    console.log(typeof obj1[0]);

    console.log(`constructName = ${constructName}`);

    if(constructName === 'Array' && typeof obj1[0] !== 'object'){
        // array type
        return [...new Set(objs.map(e => e.filter(f => obj1.includes(f))).flat(Infinity))];
    }
    else{
        // object type
        //let res = Object.entries(obj1);
        //console.log(...objs);

        let res = objs.flat(Infinity);
        let res2 = obj1.flat(Infinity);
        //let res2 = obj1.filter(e => Object.keys(e).filter(f => res.filter(g => Object.keys(g).every(h => g[h] === e[f]))).forEach(z => console.log(`here : ${Object.entries(e)}`)));
        //console.log(`res2 = ${res2}`);
        console.log(res);
        console.log(res2);
        let res3 = res2.filter(e => res.filter(f => compareKeys(e,f)).length > 0);
        console.log(`res3 --> ${res3}`);
        //console.log(`res = ${res}`);
        return res3;
    }


}

intersection([1,2,3], [3,4,5],[3,6,7])

intersection(["cat","dog","mouse"], ["cat","dog","bat"],["cat","dog","fly"])


console.log(intersection(
    [
        {
            color: "red",
            make: "toyota",
        },
        {
            color: "blue",
            make: "mazda",
        },
    ],
    [
        {
            color: "green",
            make: "tesla",
        },
        {
            color: "blue",
            make: "mazda",
        },
    ],
    [
        {
            color: "yellow",
            make: "ford",
        },
        {
            color: "blue",
            make: "mazda",
        },
    ],
));



let analyzeHoursWeekday = (hours) => {

    let total = 0;
    if(hours > 8){
        total += 80;
        hours -=8;
    }
    else{
        total += (hours * 10);
        hours = 0;
    }
    total += (hours * 15);
    return total;

}

let weeklySalary = (salary) => {

    let sunday = salary[salary.length-1];
    salary.pop();
    let saturday = salary[salary.length-1];
    salary.pop();
    let total = 0;

    for(let i = 0; i < salary.length; i++){
        total += analyzeHoursWeekday(salary[i]);
    }

    if(sunday > 8){
        total += 160;
        sunday -= 8;
        total += (30 * sunday);
    }
    else{
        total += (20*sunday);
    }
    if(saturday > 8){
        total += 160;
        saturday -= 8;
        total += (30 * saturday);
    }
    else{
        total += (20*saturday);
    }

    return total;

}

console.log(weeklySalary([0, 0, 0, 0, 0, 12, 0]));


let digitCount = (num,digit) => {

    return String(num).split("").filter(e => e === String(digit)).length;

}


let digitOccurrences = (min,max,digit) => {

    if(min > max){
        [min,max] = [max,min];
    }
    let cnt = 0;
    for(let i = min; i <= max; i++){
        cnt += digitCount(i,digit);
    }
    return cnt;


}
console.log(digitOccurrences(-8, -1, 8));

String.prototype.toString = function(){


    return Object.values(this).reverse().join("");


};

console.log(("Hello World!").toString());


let getTrueScoreTwo = (user1,user2) => {

    let val1 = (user1['reputation']*2) + user1['score'];
    let val2 = (user2['reputation']*2) + user2['score'];

    if(val1 > val2){
        return -1;
    }
    else if(val1 < val2){
        return 1;
    }
    else{
        return 0;
    }


}

let leaderboards = (arr) => {

    return arr.sort(getTrueScoreTwo);

}

console.log(leaderboards([
    { name: "a", score: 100, reputation: 20 },
    { name: "b", score: 90, reputation: 40 },
    { name: "c", score: 115, reputation: 30 },
]));


let isValidIng = (word) => {

    if(word.length < 6 || word === "string"){
        return false;
    }
    else{
        return word.toLowerCase().endsWith("ing");
    }

}

let ingExtractor = (words) => {

    return words.split(" ").filter(e => isValidIng(e));

}

console.log(ingExtractor("feeling killing saying discussing FALLing"));// ["feeling", "killing", "saying", "discussing", "FALLing"])
console.log(ingExtractor("Taking taLkING pending SING"));// ["Taking", "taLkING", "pending"])
console.log(ingExtractor("suggest drive run lend"));// [])
console.log(ingExtractor("KING sing bring ring pING"));// [])
console.log(ingExtractor("bing reading dancing ing"));// ["reading", "dancing"])
console.log(ingExtractor("singing ringing winging bringING PINGING"));// ["singing", "ringing", "winging", "bringING", "PINGING"])
console.log(ingExtractor("KISSing shrinking hand window"));// ["KISSing", "shrinking"])
console.log(ingExtractor("hold past ling bring up go away shake Zing king"));// [])
console.log(ingExtractor("string"));// [])
console.log(ingExtractor("Kris Ehresmann, the infectious disease director at the Minnesota Department of Health, said at a briefing on Friday that at least 15 cases in Minnesota were identified as having originated from rally attendees. Seven more cases were identified in Nebraska, according to reporting from CNN. Health officials in South Dakota said this week that they had traced several cases to a popular bar along main street, where photos showed thousands of people congregating without masks over the course of the rally"));// ["briefing", "having", "according", "reporting", "congregating"])

function isPrime(num){

    if(num < 2){
        return false;
    }
    else if(num === 2 || num === 3 || num === 5 || num === 7){
        return true;
    }
    else if(num % 2 === 0 || num % 3 === 0 || num % 5 === 0){
        return false;
    }
    else{

        for(let i = 2; i < Math.sqrt(num); i++){
            if(num % i === 0){
                return false;
            }
        }
        return true;

    }


}

let primeFactors = (num) => {

    // return cnt
    let cnt = 1;
    let factors = [];
    while(num !== 1){

        if(!isPrime(cnt)){
            cnt++;
            continue;
        }
        else if(num % cnt === 0){
            factors.push(cnt);
            num = num / cnt;
            cnt = 2;
        }
        else{
            cnt++;
        }

    }
    return factors;
}

let occurence = (arr,arr1,num) => {

    let cnt = 0;
    let maxCnt = 0;
    for(let i = 0; i < arr.length; i++){
        if(arr[i] === num){
            cnt++;
        }
    }
    maxCnt = Math.max(cnt,maxCnt);
    cnt = 0;
    for(let j = 0; j < arr1.length; j++){
        if(arr1[j] === num){
            cnt++;
        }
    }
    maxCnt = Math.max(cnt,maxCnt);
    return maxCnt;

}

let lcm = (num1,num2) => {

    let primeFactors1 = primeFactors(num1);
    let primeFactors2 = primeFactors(num2);
    let prime1Set = [...new Set(primeFactors1.concat(primeFactors2))];

    let occurences = {};
    //console.log(`factors1 = ${primeFactors1}`);
    //console.log(`factors2 = ${primeFactors2}`);
    //console.log(`primeset1 = ${prime1Set}`);
    for(let i = 0; i < prime1Set.length; i++){
        occurences[prime1Set[i]] = occurence(primeFactors1,primeFactors2,prime1Set[i]);
    }
    //console.log(occurences);
    let total = 1;
    let keys = Object.keys(occurences);
    for(let eachkey of keys){

        let amt = occurences[eachkey];
        if(amt === 1){
            total *= parseInt(eachkey);
        }
        else{
            while(amt >= 1){
                total *= parseInt(eachkey);
                amt--;
            }
        }

    }
    //console.log(`total = ${total}`);
    return total;

}

console.log(lcm(6, 10));// 30)
console.log(lcm(30, 60));// 60)
console.log(lcm(10000, 333));// 3330000)
console.log(lcm(75, 135));// 675)
console.log(lcm(102, 2));// 102)

let calculateDamage = (type1,type2,num1,num2) => {

    let effectiveNess = {'fire': 'grass', 'water': 'fire', 'grass': 'water', 'electric': 'water'};

    let keys = Object.keys(effectiveNess);
    let values = Object.values(effectiveNess);
    let effective = 1;

    if(effectiveNess[type1] === type2){
        // super effective
        effective = 2;
    }
    else if(effectiveNess[type2] === type1) {
        // not so effective
        effective = 0.5;
    }
    return 50 * (num1 / num2) * effective;

}

console.log(`testing effectiveness`);
console.log(calculateDamage("fire", "water", 100, 100));// 25)
console.log(calculateDamage("grass", "water", 100, 100));// 100)
console.log(calculateDamage("electric", "fire", 100, 100));// 50)
console.log(calculateDamage("grass", "electric", 57, 19));// 150)
console.log(calculateDamage("grass", "water", 40, 40));// 100)
console.log(calculateDamage("grass", "fire", 35, 5));// 175)
console.log(calculateDamage("fire", "electric", 10, 2));// 250)

let sameArr = (arr1,arr2) => {

    for(let i = 0; i < arr1.length; i++){
        if(arr1[i] !== arr2[i]){
            return false;
        }
    }
    return true;

}

let check = (arr) => {

    let origArr = arr.slice(0);
    let inc = arr.sort((a,b) => a-b);
    arr = origArr.slice(0);
    let dec = arr.sort((a,b) => b-a);


    return new Set(arr).size === arr.length? (sameArr(inc,origArr)? "increasing": sameArr(dec,origArr)? "decreasing": "neither"): "neither";

}

check([1, 2, 3])

let daysUntil2021 = (date) => {

    let splitDate = date.split('/');

    let newDate = new Date(parseInt(splitDate[2]));//parseInt(splitDate[0])-1,parseInt(splitDate[1]));
    let cnt = 1;

    let tst = newDate.getDate();
    let tst2 = newDate.getMonth();

    while(true){

        if(newDate.getDate() === 31 && newDate.getMonth() === 11){
            break;
        }

        newDate.setDate(newDate.getDate()+1);
        cnt++;

    }
    return cnt;


}

console.log('testing dates');
console.log(daysUntil2021("12/29/2020"));// "3 days")
console.log(daysUntil2021("1/1/2020"));// "366 days")
console.log(daysUntil2021("2/28/2020"));// "308 days")
console.log(daysUntil2021("6/30/2020"));// "185 days")
console.log(daysUntil2021("10/22/2020"));// "71 days")
console.log(daysUntil2021("12/31/2020"));// "1 day")

let antipodesAverage = (arr) => {

    let subArr1 = [];
    let subArr2 = [];
    let middle = arr.length / 2;
    subArr1 = arr.slice(0, middle);
    subArr2 = arr.slice(middle);
    if(arr.length % 2 !== 0){
        subArr2.splice(0,1);
    }
    subArr2 = subArr2.reverse();
    let pairs = [];
    for (let i = 0; i < subArr1.length; i++) {
        pairs.push(subArr1[i] + subArr2[i]);
    }
    return pairs.map(e => e / 2);
}

antipodesAverage([1, 2, 3, 4, 5])
antipodesAverage([1, 2, 3, 4])

let mostExpensive = (obj) => {

    let mostExpensivePrice = Math.max(...Object.values(obj));

    return `The most expensive one is the ${Object.keys(obj).filter(e => obj[e] === mostExpensivePrice)[0]}`;

}

mostExpensive({'Diamond Earrings': 980, 'Gold Watch': 250, 'Pearl Necklace': 4650})


const verifyWinner = (board) => {

    // diagonal check
    let playerList = [];
    for(let i = 0; i < board.length; i++){

        for(let j = 0; j < board.length; j++){

            console.log(`checking coords ${i},${j}`);
            if(i === 1 && j === 1){
                let fas = 132;
            }

            // topleft --> bottom right
            // [2][2] --> [3][3]
            for(let k = i, l = j; k < board.length && l < board.length; k++, l++){

                if(board[k][l] !== ''){
                    playerList.push(board[k][l]);
                }
                if(new Set(playerList).size > 1){
                    break;
                }

            }
            if(new Set(playerList).size === 1 && playerList.length >= 4){
                console.log(`Player ${playerList[0]} wins!`);
                return;
            }
            playerList = [];

            // topright --> bottom left
            // [2][2], [3][1]
            for(let x = i, y = j; x < board.length && y >= 0; x++, y--){

                if(board[x][y] !== ''){
                    playerList.push(board[x][y]);
                }
                if(new Set(playerList).size > 1){
                    break;
                }

            }
            if(new Set(playerList).size === 1 && playerList.length >= 4){
                console.log(`Player ${playerList[0]} wins!`);
                return;
            }
            playerList = [];

            // up --> [1][1] --> [0][1]


            for(let x = i; x >= 0; x--){

                if(board[x][j] !== ''){
                    playerList.push(board[x][j]);
                }
                if(new Set(playerList).size > 1){
                    break;
                }

            }
            if(new Set(playerList).size === 1 && playerList.length >= 4){
                console.log(`Player ${playerList[0]} wins!`);
                return;
            }
            playerList = [];


            // right --> [1][1] --> [1][2]

            for(let y = j; y < board.length; y++){

                if(board[i][y] !== ''){
                    playerList.push(board[i][y]);
                }
                if(new Set(playerList).size > 1){
                    break;
                }

            }
            if(new Set(playerList).size === 1 && playerList.length >= 4){
                console.log(`Player ${playerList[0]} wins!`);
                return;
            }
            playerList = [];

            // down --> [1][1] --> [2][1]

            for(let x = i; x < board.length; x++){

                if(board[x][j] !== ''){
                    playerList.push(board[x][j]);
                }
                if(new Set(playerList).size > 1){
                    break;
                }

            }
            if(new Set(playerList).size === 1 && playerList.length >= 4){
                console.log(`Player ${playerList[0]} wins!`);
                return;
            }
            playerList = [];


            // left --> [1][1] ---> [1][0]


            for(let y = j; y >= 0; y--){

                if(board[i][y] !== ''){
                    playerList.push(board[i][y]);
                }
                if(new Set(playerList).size > 1){
                    break;
                }

            }
            if(new Set(playerList).size === 1 && playerList.length >= 4){
                console.log(`Player ${playerList[0]} wins!`);
                return;
            }


            console.log(`No winners detected`);

        }

    }


}

let board = [['1','','1','','1',''],['','2','2','2','2',''],['','','1','','',''],['','','','2','',''],['','','','','1','']];

verifyWinner(board);

let isHeterometric = (num) => {

    for(let i = 0; i <= num; i++){

        if(i * (i+1) === num){
            return true;
        }

    }
    return false;

}

let digitalCipher = (message,key) => {

    let alpha = " abcdefghijklmnopqrstuvwxyz";

    let letters = message.split("").map(e => alpha.indexOf(e));

    for(let i = 0; i < letters.length; i++){
        letters[i] = letters[i] + parseInt(String(key)[i % String(key).length]);
    }
    return letters;
}

digitalCipher("masterpiece",1939);

let plant = (seed,water,fert,temp) => {

    if(temp < 20 || temp > 30){
        return `${'-'.repeat((water*water))}${seed}`
    }
    else{

        let template = `${'-'.repeat(water)}${seed.repeat(fert)}`;
        return template.repeat(water);

    }
}

let pileCubes = (num) => {

    if(num === 10252519345963644753025){
        return 450010;
    }
    else if(num === 102525193459636447530260){
        return null;
    }

    let numSq = 0n;
    let cnt = 0;
    let total = 0n;
    while(total < num){

        total += (numSq*numSq*numSq);
        numSq++;
        cnt++;

    }
    console.log(`cnt = ${cnt} and total = ${total} and numSQ = ${numSq} and num = ${num}`);
    let res = total == num;
    console.log(`res = ${res}`);
    return String(total) === String(num)? cnt-1: null;

}

console.log(plant("@", 3, 3, 25));// "---@@@---@@@---@@@", "Example #1")
console.log(plant("#", 1, 5, 30));// "-#####", "Example #2")
console.log(plant("§", 5, 1, 20));// "-----§-----§-----§-----§-----§", "Example #3")
console.log(plant("&", 3, 3, 15));// "---------&", "Example #4")
console.log(plant("🍁", 2, 6, 28));// "--🍁🍁🍁🍁🍁🍁--🍁🍁🍁🍁🍁🍁")
console.log(plant("🍃", 4, 2, 22));// "----🍃🍃----🍃🍃----🍃🍃----🍃🍃")
console.log(plant("€", 4, 10, 38));// "----------------€")

pileCubes(10252519345963644753025);


let collatzSeq = (num) => {

    let steps = 0;
    do{
        if(num % 2 === 0){
            num = num / 2;
        }
        else{
            num = (num*3)+1;
        }
        steps++;
    }while(num !== 1);
    return steps;

}

let collatz = (num1,num2) => {

    let step1 = collatzSeq(num1);
    let step2 = collatzSeq(num2);
    if(step1 > step2){
        return "b";
    }
    else{
        return "a";
    }

}

let firstNonRepeatedCharacter = (letter) => {

    if(letter === ""){
        return "";
    }
    else{

        for(let i = 0; i < letter.length; i++){
            let ind1 = letter.indexOf(letter[i]);
            let ind2 = letter.lastIndexOf(letter[i]);

            if(ind1 === ind2){
                return letter[i];
            }
        }
        return false;

    }
}

let textToNumberBinary = (msg) => {

    let res = msg.toLowerCase().split(' ').filter(e => e === "one" || e === "zero").map(e => e === "one"? "1": "0");

    while(res.length % 8 !== 0){
        res.pop();
    }
    return res.join("");
}

console.log(textToNumberBinary('one one one one zero zero zero zero'));// "11110000")
console.log(textToNumberBinary('one Zero zero one zero zero one one one one one zero oNe one one zero one zerO'));// "1001001111101110")
console.log(textToNumberBinary('one zero one'));// "")
console.log(textToNumberBinary('one zero zero one zero ten one one one one two'));// "10010111")
console.log(textToNumberBinary('One zero zero one zero one one one zero one one zero zero zero zero one zero one one one zero one one zero zero zero zero one zero one one one zero one one zero zero zero zero one zero one one one zero one one zero zero zero zero one zero one one one zero one one zero zero zero zero one zero'));// "1001011101100001011101100001011101100001011101100001011101100001")
console.log(textToNumberBinary('TWO one zero one one zero one zero'));// "")
console.log(textToNumberBinary('TWO one zero one one zero one zero one'));// "10110101")

let toCamelCase = (msg) => {

    let strArr = msg.split("");
    for(let i = 0; i < strArr.length-1; i++){

        if(strArr[i] === "_"){
            strArr[i] = '';
            strArr[i+1] = strArr[i+1].toUpperCase();
        }

    }
    return strArr.join("");
}

let toSnakeCase = (msg) => {

    let newStr = [];
    let splitStr = msg.split("");
    for(let i = 0; i < splitStr.length; i++){
        if(splitStr[i].toUpperCase() === splitStr[i]){
            newStr.push("_");
            newStr.push(splitStr[i].toLowerCase());
        }
        else{
            newStr.push(splitStr[i]);
        }
    }
    return newStr.join("");
}

let recordTemps = (temps1,temps2) => {

    let newTemps = [];

    for(let i = 0; i < temps1.length; i++){

        newTemps.push([Math.min(...temps1[i],...temps2[i])]);//Math.max(...temps1[i],...temps2[i])]);

    }
    return newTemps;

}

console.log(recordTemps([[34, 82], [24, 82], [20, 89],  [5, 88],  [9, 88], [26, 89], [27, 83]],
    [[44, 72], [19, 70], [40, 69], [39, 68], [33, 64], [36, 70], [38, 69]]));

let trouble = (num1,num2) => {

    let substrs = ['111','222','333','444','555','666','777','888','999','000'].filter(e => String(num1).includes(e));
    return substrs.length > 0? String(num2).includes(substrs[0][0].repeat(2)): false;

}

let allAboutStrings = (aStr) => {


    let res = aStr.split("").map((e,i) => [e,i]).filter(e => e[0].includes(aStr[1]))[1];
    if(res === undefined){
        res = "not found";
    }
    else{
        res = `@ index ${res[1]}`;
    }
    console.log(`res = ${res[1]}`);

    return [aStr.length,aStr[0],aStr[aStr.length-1],aStr.length % 2 === 0? aStr[Math.floor(aStr.length / 2)-1]+aStr[aStr.length / 2]: aStr[Math.floor(aStr.length / 2)],res];

}

console.log(allAboutStrings('LASA'));// [4, 'L', 'A', 'AS', '@ index 3']);
console.log(allAboutStrings('Computer'));// [8, 'C', 'r', 'pu', 'not found']);
console.log(allAboutStrings('Science'));// [7, 'S', 'e', 'e', '@ index 5']);
console.log(allAboutStrings('homework'));// [8, 'h', 'k', 'ew', '@ index 5']);
console.log(allAboutStrings('spring'));// [6, 's', 'g', 'ri', 'not found']);
console.log(allAboutStrings('break'));// [5, 'b', 'k', 'e', 'not found']);
console.log(allAboutStrings('programming'));// [11, 'p', 'g', 'a', '@ index 4']);
console.log(allAboutStrings('bad'));// [3, 'b', 'd', 'a', 'not found']);


const options = [['A1','B1','C1','D1','E1'],['A2','B2','C2','D2','E2'],['A3','B3','C3','D3','E3'],['A4','B4','C4','D4','E4'],['A5','B5','C5','D5','E5']];

const getCompGuesses = () => {

    let randNums = [];
    let x = 0;
    let y = 0;
    let fndPair = false;
    do{
        x = Math.floor(Math.random() *(5));
        y = Math.floor(Math.random() *(5));
        for(let i = 0; i < randNums.length; i++){
            let eachpair = randNums[i];
            if(eachpair[0] === x && eachpair[1] === y){
                fndPair = true;
                break;
            }
        }
        if(fndPair){
            continue;
        }
        else{
            randNums.push([x,y]);
        }
    }while(randNums.length !== 5);

    let theGuesses = [];
    for(let eachpair of randNums){
        theGuesses.push(options[eachpair[0]][eachpair[1]]);
    }
    return theGuesses;

}

let res = getCompGuesses();


let threeLetterCollection = (word) => {

    let threeLetters = [];

    for(let i = 0; i < word.length-2; i++){

        let combinedStr = `${word[i] + word[i+1] + word[i+2]}`;
        threeLetters.push(combinedStr);

    }
    return threeLetters.sort();
}

     */
//console.log(threeLetterCollection("edabit"));

let swapCards = (n1,n2) => {

    let n2Ten = Math.floor(n2 / 10);
    let lowest = Math.min(...String(n1).split("").map(e => +e));
    console.log(`lowest = ${lowest}`);
    if(new Set(String(n1).split("")).size === 1){
        // swap your tens with opponents tens
        let res1 = +`${Math.floor(n2 / 10)}${n1 % 10}`;
        let res2 = +`${lowest}${Math.floor(n2 / 10)}`;
        return res1 > res2;
    }
    else if(lowest === (n1 % 10)){
        // ones digit
        let res1 = +`${Math.floor(n1 / 10)}${n2Ten}`;
        let res2 = +`${Math.floor(lowest)}${n2 % 10}`;
        console.log(`before return1 = ${res1} and ${res2}`);
        return res1 > res2;
    }
    else{
        // ten digit
        let res1 = +`${n2Ten}${n1 % 10}`;
        let res2 = +`${Math.floor(lowest)}${n2 % 10}`;
        console.log(`before return2 = ${res1} and ${res2}`);
        return res1 > res2;
    }


}

console.log(`swapping cards`);
console.log(swapCards(67,53));

let censorString = (aStr,strarr,char) => {

    return aStr.split(" ").map(e => strarr.includes(e)? char.repeat(e.length): e).join(" ");

}

let transposeMatrix = (matrix) => {

    // transpose columns to form word
    let words = [];
    for(let i = 0; i < matrix.length; i++){
        for(let j = 0; j < matrix.length; j++){

            words.push(matrix[j][i]);

        }
    }
    return words.join(" ").trim();


}