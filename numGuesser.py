import random

def guess_the_number():
    secret_number = random.randint(1, 100)
    attempts = 0
    max_attempts = 10
    
    print("Welcome to the Number Guessing Game!")
    print("I have selected a number between 1 and 100. Can you guess it?")

    while attempts < max_attempts:
        try:
            guess = int(input("Enter your guess: "))
            attempts += 1

            if guess == secret_number:
                print(f"Congratulations! You guessed the number {secret_number} in {attempts} attempts.")
                break
            elif guess < secret_number:
                print("Too low! Try again.")
            else:
                print("Too high! Try again.")
        except ValueError:
            print("Invalid input. Please enter a valid number.")

    else:
        print(f"Sorry, you've run out of attempts. The correct number was {secret_number}.")

guess_the_number()
