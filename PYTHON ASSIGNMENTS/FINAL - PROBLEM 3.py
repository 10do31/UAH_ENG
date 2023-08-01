# Dan Otieno
# Final- Problem 3
# ENG 101
# 12/10/2019.

# Script for Primes:

# Read contents of file.
import math

m = open("101primes.txt")
next = m.readline()
primelist = []
count = 0
c1000 = 0
#counter for prime numbers in file
while next != "":
    count += 1              
    nextprime = int(next)
    if nextprime < 10000:    
        c1000 += 1
        primelist.append(nextprime)     #append converted to primelist.
        next = m.readline()

primes2 = []
count2 = 0
for prime in primelist:
    if prime > 2500:
        if prime < 5000:
            count2 += 1
            primes2.append(prime)
print('\nNumber of primes between 2500 and 5000 is:', count2)
            
    
# Compute twin primes.
twinlist = []
twinprimes = 0

for prime in primes2:
    diffprime = prime - 2
    if diffprime in primes2:
        twinprimes += 1
        twinlist.append(diffprime)
print('\nList of twin primes:', twinlist)
print('\nNumber of twinprimes between 2500 and 5000:', twinprimes)
            

        
