# Class Assignment 14
# Dan Otieno
# ENG 101-02
# Due Date 11/15/2019.
#

m = open("101primes.txt")
primes_list = []

next = m.readline()

while next != "":
    nextprime = int(next)
    primes_list.append(nextprime)
    next = m.readline()

print(primes_list)

import math
k = 0

for N in primes_list:
    k = k + 1
    print(N)
    rat_primes = k/N
    prop_primes = 1/math.log(N)

print('Ratios:' ,rat_primes)
print('Proportion of primes:' ,prop_primes)

