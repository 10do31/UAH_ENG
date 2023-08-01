# Class Assignment 11
# Dan Otieno
# ENG 101-02
# Due Date 10/23/2019
#
# NUMBER GUESSING GAME.
#
import random
#   CREATING TITLE FOR GAME, WILL CALL IT "NUMGUESS"
#
#   GREET AND PROMPT PLAYER TO INTRODUCE THEMSELVES.
print('Greetings!! Welcome to Numguess! Please enter your name to get started ')
name = input()
print("Hello",name,":I am thinking of a number between 1 and 100, can you guess what it is? ")
#
number = random.randint(1, 100)
numattempts = 0     #number of attempts.
guess = 0           #user guess.
#
#   While Loop for number game.
while guess != number:
    guess = int(input('Guess the number in my mind: '))
    numattempts += 1
    if guess == number:
        print("Awesome job!!",name,"!,You have successfully read my mind!" )
        break
    elif guess < number:
        print('Sorry buddy, too low, bump the numbers up and try again: ')
        break
    else:
        print('That is a lot more integer than needed, try again: ')
        break
    if guess != number:
        number = str(number)
        print("",name,"You have FAILED to read my mind!!! GAME OVER!! The answer is " ,number,)
        break
        
