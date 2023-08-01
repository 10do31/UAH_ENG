# Assignment 04
# Dan Otieno
# ENG 101-02
# Due Date 11/18/2019
#
# Question 2: LETTER/WORD COUNT.

g = open("gettysburg_address.txt")    # Opening file.

content = g.read()

punct_symbols = ['.' ',' '?' '!' '-']

print(content)

def frequency(wordcount):
    words = content.split()
    count = len(words)
    freq = {}
    line = g.readline()
    
    for word in words:
        word = word.lower()     # Convert all to lowercase.
        if word in freq:
            freq[word] += 1
        for char in content:
            if char in punct_symbols:
                word = word.split(char)
        else:
            freq[word] = 1
            
    return count, freq


num, dictx = frequency(content)
import pprint
pprint.pprint(dictx)
print('\n\n total number of words is:', num)      # Output


