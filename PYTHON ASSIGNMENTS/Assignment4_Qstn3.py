# Assignment 04
# Dan Otieno
# ENG 101-02
# Due Date 11/18/2019
#
# Question 3: ROCK PAPER SCISSORS!.

print("ROCK, PAPER, SCISSORS ")

player = input("Enter player name here: ")

print("Hello", player,", are you feeling lucky? Let's play! ")

import random

weapons = ["rock", "paper", "scissors"]

# Setting CPU and Player score counters
player_pts = 0

cpu_pts = 0

while cpu_pts != 4 and player_pts != 4:
    comp_pick = random.choice(weapons)
    player_pick = input('What is your weapon of choice?: ')
    print('rock, paper, scissors, GO!')
    print("")
    print("CPU chose", comp_pick)
    if player_pick == comp_pick:
        print("its a tie!!")
    if(comp_pick == "rock" and player_pick == "scissors") or (comp_pick == "scissors" and player_pick == "paper") or (comp_pick == "paper" and player_pick == "rock"):
        print("You Lose, I WIN! ")
        cpu_pts += 1
    elif(player_pick == "rock" and comp_pick == "scissors") or (player_pick == "scissors" and comp_pick == "paper") or (player_pick == "paper" and comp_pick == "rock"):
        print("Congratulations, YOU HAVE WON!")
        player_pts += 1

print("CPU SCORE:" + str(cpu_pts))
print("PLAYER SCORE:" + str(player_pts))

if player_pts > cpu_pts:
    print("CONGRATULATIONS", player,", YOU WIN THE GAME! :-) ")
elif cpu_pts > player_pts:
    print("SORRY", player,", YOU HAVE LOST, GAME OVER! :-( ")


print("Thank you for Playing ")
    
    

                                                            

