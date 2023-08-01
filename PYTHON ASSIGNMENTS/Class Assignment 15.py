# Class Assignment 15
# Dan Otieno
# ENG 101-02
# Due Date 11/22/2019.
#
#   POLYNOMIAL FUNCTIONS.
#
#   CalcPoly ---    compute the value of polynomial.
#   DerivPoly ---   compute the derivative of a polynomial.
#   IntPoly ---     compute the integral of a polynomial.
#
#   Coeffcients given by lists [a0, a1,........an]
#

def CalcPoly( coefs, xx ):
    sum = 0
    for k in range(0, len(coefs) ):
        sum += coefs[k] * xx**k
    return sum

def DerivPoly( pcoefs):
    dcoefs = []
    for k in range(0, len(pcoefs)-1 ):
        dcoefs.append( (k+1)*pcoefs[k+1] )
    return dcoefs


import math

def IntPoly( scoefs ):
    a = -5
    x = a/2
    gx = x**2 - a
    for k in range(-15, 16):
        while abs(gx) > 1.E-6:
            x = x - gx/2/x
            gx = x**2 - a
    return x
            
        
    
   
            
test1 = [10, 1]
xtest = 1
y1 = CalcPoly( test1, xtest)
print(test1)
print("Test1 CalcPoly:", xtest, y1)
dtest1 = DerivPoly( test1 )
print("Test1 DerivPoly:", dtest1)

test2 = [5, 0, -1]
y2 = CalcPoly( test2, xtest)
print(test2)
print("Test2 CalcPoly:", xtest, y2)
dtest2 = DerivPoly( test2)
print("Test2 DerivPoly:", dtest2)

test3 = [5, 0, -1, 0, .4]
y3 = CalcPoly( test3, xtest)
print(test3)
print("Test3 CalcPoly:", xtest, y3)
dtest3 = DerivPoly( test3)
print("Test3 DerivPoly:", dtest3)

test4 = [10, 1, -.10, .005]
y4 = CalcPoly( test4, xtest)
print(test4)
print("Test4 CalcPoly:", xtest, y4)
dtest4 = DerivPoly( test4)
print("Test4 DerivPoly:", dtest4)
stest = IntPoly( test4 )
print("Test4 IntPoly:", stest)

