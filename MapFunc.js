// Higher-Order Functions:like map,filter

// Write a function that takes an array of numbers and returns a new array with only the even numbers 

let arr = [10,35,20,40,30,85,93];

function FilterEvenNumber(arr){
    return arr.filter(num =>num % 2 === 0);
}

console.log(FilterEvenNumber(arr));
// console.log(arr)
