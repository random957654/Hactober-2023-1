function bubbleSort(arr: number[]): void {
 const n: number = arr.length;
 for (let i: number = 0; i < n - 1; i++) {
     for (let j: number = 0; j < n - i - 1; j++) {
         if (arr[j] > arr[j + 1]) {
             // Swap arr[j] and arr[j+1]
             [arr[j], arr[j + 1]] = [arr[j + 1], arr[j]];
         }
     }
 }
}

// Example unsorted array
const arr: number[] = [64, 34, 25, 12, 22, 11, 90];

console.log("Unsorted array:", arr);
bubbleSort(arr);
console.log("Sorted array:", arr);
