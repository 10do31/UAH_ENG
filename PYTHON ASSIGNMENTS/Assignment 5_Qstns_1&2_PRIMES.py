# Assignment 05
# Dan Otieno
# ENG 101-02
# Due Date 12/02/2019
#
# Question 1: PRIME NUMBERS TEST.
#

import math

m = open("101primes.txt")

primes_list = []

for line in m:
    # Update primes list of prime numbers. 
    primes_list.append(int(line))

# List of numbers to be tested:
primestest = [2692493, 8767843, 13065521, 14123649, 2692503,
              7982119, 11505341, 14123651, 4632703, 7983121, 11505343]

print("List to check:"+ str(primestest))
print('\n')

for primecheck in primestest:
    flag = 1
    #Find the roots.
    numroot = int(math.sqrt(primecheck))
    for prime_number in primes_list:
        if prime_number > numroot:
            break
        elif(primecheck%prime_number==0):
            flag = 0
            break
    # Outputs.
    if(flag):
        print(str(primecheck)+"\n is a prime number\n")
    else:
        print(str(primecheck)+"\n is not a prime number\n")
print("\n")

# Find Prime Factors of any or given numbers:

string_test = 'Composite numbers given: 488635, 6958063, 17764527, 21364667. '
print(string_test)
# Code is to generate factors of any number the user enters.
num = int(input(" Enter any number or pick from the list above to test: "))

for i in range(2, num+1):
    if(num % i == 0):
        prime = 1
        for j in range(2, (i//2 + 1)):
            if(i % j == 0):
                prime = 0
                break
        if (prime == 1):
            print('\n',i,' is a prime factor of ',num)


