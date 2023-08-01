# Assignment 03
# Dan Otieno
# ENG 101-02
# Due Date 11/04/2019
#
# Question 3: BOTTLES OF SANGRIA!!
#
input_bottles = int(input("How many bottles of Sangria on the wall?? "))
bottles = 0
while (bottles !=1):
    if(input_bottles > 0):
        bottles = 1
        for i in range (input_bottles,0,-1):
            if(i==1):
                print("\n" + str(i) + "bottle of Sangria on the wall, " + str(i) + "bottle of sangria.")
                print("Take one down and pass it around, no more bottles of Sangria on the wall. ")
            elif(i==2):
                print("\n" + str(i) + "bottles of Sangria on the wall, " + str(i) + "bottles of Sangria.")
                print("Take one down and pass it around, " + str(i-1) + "bottles of Sangria on the wall.")
            else:
                print("\n" + str(i) + "bottles of Sangria on the wall, " + str(i) + "bottles of Sangria. ")
                print("Take one down and pass it around, " + str(i-1) + "bottles of Sangria on the wall. ")
    else:
        print("Number not valid, try again \n")
        input_bottles = int(input("How many bottles of Sangria on the wall?? "))
    
