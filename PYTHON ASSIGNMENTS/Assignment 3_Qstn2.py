# Assignment 03
# Dan Otieno
# ENG 101-02
# Due Date 11/04/2019
#
# Question 2: SCRIPT FOR RANDOM SHUFFLE CIPHER.

#Create lists:
aatozz = 'abcdefghijklmnopqrstuvwxyz'
Alphabet = list(aatozz)
Cilphabet = 'yptalqrwcfdsvzxkgnimhjeoub'
CiphAlphabet = list(Cilphabet)

#Let's create the dictionaries and loop here:
CipherDict = {}
DeCipherDict = {}
for k in range(0,len(Alphabet)):
    CipherDict[Alphabet[k]] = CiphAlphabet[k]
    DeCipherDict[CiphAlphabet[k]] = Alphabet[k]

print(CipherDict)

Ytext = 'mwcicivuyelixvltckwlntxal'
DCtext = ''
for x in Ytext:
    DCtext += DeCipherDict[x]

print(DCtext)

Ztext = 'vximklxkslsxjlkcbby'
DCtext2 = ''
for x in Ztext:
    DCtext2 += DeCipherDict[x]

print(DCtext2)







