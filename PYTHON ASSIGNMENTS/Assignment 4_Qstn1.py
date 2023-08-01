# Assignment 04
# Dan Otieno
# ENG 101-02
# Due Date 11/18/2019
#
# Question 1: CAR RENTAL PROGRAM.

print("WELCOME TO Rapid|Rentals COST CALCULATOR! ")

classifcode = input("Please enter the Customer's code here: ")
rent_days = int(input("Enter rental period (days): "))
odostart = int(input("Please enter starting Odometer reading: "))
odostop = int(input("Please enter ending Odometer reading: "))

base_charges = 0
mileage_charges = 0
ododiff = odostop - odostart

if(classifcode=='B' or classifcode=='b'):
    base_charges = rent_days * 40
    mileage_charges = 0.25 * ododiff
elif(classifcode=='D' or classifcode=='d'):
    base_charges = rent_days * 60
    average_m = ododiff/rent_days
    if average_m <= 100:
        mileage_charges = 0
    else:
        mileage_charges = 0.25*(ododiff - 100*rent_days)
else:
    print("sorry, the class code you entered is invalid. ")

totalcharges = base_charges + mileage_charges
totalrounded = round(totalcharges, 2)
print('Total rental charges:  $',totalrounded)
    
