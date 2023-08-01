# Assignment 03
# Dan Otieno
# ENG 101-02
# Due Date 11/04/2019
#
# Question 1: SCRIPT FOR TRIANGLE LAWCOSINES.
#
# Input sides of Triangle:
a = int(input("Side a:  "))
b = int(input("Side b:  "))
c = int(input("Side c:  "))
sides = [a, b, c]

print("For triangle sides:" ,sides)
#

#Apply LoCosines:
import math

Angle_A = math.degrees(math.acos((b**2 + c**2 - a**2)/(2*b*c)))
Angle_B = math.degrees(math.acos((c**2 + a**2 - b**2)/(2*a*c)))
Angle_C = math.degrees(math.acos((a**2 + b**2 - c**2)/(2*a*b)))

# Rounding outputs to 2 decimal places:
outA = round(Angle_A, 1)
outB = round(Angle_B, 1)
outC = round(Angle_C, 1)

#Printing Outputs:
print('Angle A in degrees is:' ,outA)
print('Angle B in degrees is:' ,outB)
print('Angle C in degrees is:' ,outC)

    

