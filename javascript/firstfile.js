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

const padZero = (length,padder) => {

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

let animals = padZero(10,"#");
console.log(animals("Pigs",4));
console.log(animals("Tiger",10));