# Assignment 05
# Dan Otieno
# ENG 101-02
# Due Date 12/02/2019
#
# Question 3: ENCRYPTION CODE.
#
# List to hold the letters to display

import random

alphab = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
          'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '  ']

alphab2 = []

# Picking a value from the alphabet list:
for i in alphab:
   # Loop to combine the letters in pairs.
   for j in alphab:
       alphab2.append(i+j)

print(alphab2)

random.seed(6767)
randlist = alphab2[:]
random.shuffle(randlist)
print('randomlist  ',randlist,'\n')

# Create Dictionaries for cipher/decipher.
cipher = {}
decipher = {}

for k in range(0, len(alphab2)):
    cipher[alphab2[k]] = randlist[k]
    decipher[randlist[k]] = alphab2[k]
    
import pprint
pprint.pprint(cipher)
print('\n\n')
pprint.pprint(decipher)

#Demonstrate with text.

textest = open("hobbit_text.txt")

test = textest.read()
test += ' '
test_string = str(test).lower()
n = 2
# set text to list of 2 characters.
split_test = [(test_string[i:i+n]) for i in range(0, len(test_string), n)]

ciphtxt = ''
for x in split_test:
   ciphtxt += cipher[x]
print('\nCiphered text:\n',ciphtxt,'\n')

deciphtxt = ''
for x in split_test:
   deciphtxt += decipher[x]
print('Deciphered text:\n',deciphtxt)
   







       
    


