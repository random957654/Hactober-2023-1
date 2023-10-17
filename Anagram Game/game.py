import random

# List of words for the game
word_list = ["python", "java", "javascript", "programming", "computer", "developer", "algorithm", "data", "machine",
             "learning"]


def choose_word():
    # Randomly select a word from the word_list
    return random.choice(word_list)


def scramble_word(word):
    # Shuffle the letters of the word
    word_as_list = list(word)
    random.shuffle(word_as_list)
    return ''.join(word_as_list)


def main():
    print("Welcome to the Anagram Game!")
    while True:
        original_word = choose_word()
        scrambled_word = scramble_word(original_word)

        print("Unscramble the word:", scrambled_word)

        # Get the player's guess
        guess = input("Your guess: ").lower()

        if guess == original_word:
            print("Correct! You unscrambled the word.")
        else:
            print("Incorrect. The word was:", original_word)

        play_again = input("Play again? (yes/no): ").lower()
        if play_again != "yes":
            print("Thanks for playing!")
            break


main()
# To run this file use python game.py
