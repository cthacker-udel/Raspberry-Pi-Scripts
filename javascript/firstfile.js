
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


 */

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
    for(let eachKey of keys){
        newSubArr.push(eachKey);
        newSubArr.push(obj[eachKey]);
        newArr.push(newSubArr);
        newSubArr = [];
    }
    return newArr;

}

console.log(toArray({a:1,b:2}));

