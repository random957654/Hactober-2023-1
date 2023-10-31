import time

name = input("What is your name? ")

print ("Hello, " + name, "Time to play hangman!")
time.sleep(1)

print ("Start guessing...")
time.sleep(0.5)

word = ("secret")

guesses = ''

turns = 10


while turns>0:         
    failed = 0             
 
    for char in word: 

        if char in guesses:    
            print (char,end=""),    

        else:
            print ("_",end=""),     
            failed += 1    


    if failed == 0:        
        print ("You won")
        break            

    guess = input("guess a character:") 
    guesses += guess                    

    if guess not in word:
        turns-=1       
        print ("Wrong")  
        print ("You have", + turns, 'more guesses' )
        if turns == 0:           
            print ("You Lose"  )
