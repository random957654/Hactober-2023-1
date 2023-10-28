package main

import "fmt"

func factorial(n int) int {
    if n == 0 {
        return 1
    }
    return n * factorial(n-1)
}

func main() {
    var n int
    fmt.Print("Enter any number of your choice: ")
    fmt.Scan(&n)
    fact := factorial(n)
    fmt.Printf("The factorial of the given number is %d\n", fact)
}
