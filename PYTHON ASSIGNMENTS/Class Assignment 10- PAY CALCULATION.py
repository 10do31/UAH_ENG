# Class Assignment 10 - PAY CALCULATOR
# Dan Otieno
# ENG 101-02
# Due Date 10/17/2019
#
#CALCULATING PAY BASED ON HOURLY RATE AND HOURS WORKED, PROGRAM NAMED PayArcade.
nminput = input('Welcome to PayArcade!! Please enter your name: ') #Input Employee name.
Name = print("Hello",nminput,"! \n")
einput = input('Please enter your 4-Digit Employee Number: ') #Input Employee ID.
Employee = int(einput)
winput = input('Enter hourly wage here: ') #Input hourly wage rate.
WageRate = int(winput)
hinput = input('Total hours worked last week: ') #Input total work hours.
Hours = int(hinput)
var1 = WageRate*Hours #var1 denotes Total Pay calculated.
Pay = int(var1)
print("Total wages: $",int(Pay)," ")
#
# PRINTING OUTPUT STATEMENTS.
print("\t",nminput,"is hourly employee number",Employee," ")
print("\t",nminput,"worked",hinput,"hours last week ")
#
print("\t",nminput,"earned $",Pay,"last week ")




