fn main() {
    println!("Hello, Welcome to Fizz Buzz!");
    fizz_buzz();
}

fn fizz_buzz() {
    let mut counter = 0;
    for i in 0..=301 {
        match (i % 3, i % 5) {
            (0, 0) => {
                println!("FizzBuzz");
                counter += 1;
            },
            (0, _) => println!("Fizz"),
            (_, 0) => println!("Buzz"),
            _ => println!("{}", i)
        }
    }
    println!("FizzbBuzz occured {} times.", counter);
}