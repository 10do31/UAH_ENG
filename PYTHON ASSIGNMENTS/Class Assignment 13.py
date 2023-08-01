# Class Assignment 13
# Dan Otieno
# ENG 101-02
# Due Date 11/08/2019.
#
# MORTGAGE!

print("Welcome to MoneyHome Calculator! ")

P = float(input("Please enter the Principal amount for the loan: "))    # Principal amount.
APR = float(input("Please enter the annual % rate for the loan: "))     # Interest rate.
Y = int(input("Please enter the number of years to repay the loan: "))  # Loan period.

import math

i = APR/(12*100)                            # Monthly interest rate.
n = 12 * Y                                  # Number of payments in months.
amount = P*((i*(1+i)**n)/((1+i)**n - 1))    # Monthly payments.

monthpay = round(amount, 2)    

total_pay = round(amount * Y * 12, 2)

print("Your monthly payment is: ",monthpay)    # Output.

print("Your total payment will be: ",total_pay)

#Demonstrating Balances:
balance = float(input("Enter balance here: "))
payment = float(input("How much is the monthly payment? "))
month = 0
total = 0

while balance > 0:
    for month in range(1,24):
        month = month + 1
        balance = balance +(balance*i)-payment
        total = total + payment
        print("Month: "+str(month))
        print("Balance: "+str(round(balance, 2)))
        print("Total Payment: "+str(round(total, 2)))
    break


print("Thank you for using MoneyHome Calculator! Have a good one :) ")





    
    
          
