import random
import time

def partA():
    
    dict = { 1:'a', 2:'b', 3:'c', 4:'d', 5:'e', 6:'f', 7:'g', 8:'h', 9:'i', 10:'j', 11:'k', 12:'l', 13:'m', 14:'n', 15:'o', 16:'p', 17:'q', 18:'r', 19:'s', 20:'t', 21:'u', 22:'v', 23:'w', 24:'x', 25:'y', 26:'z'}

    for x in range (50):
        print('.', end="")
        time.sleep(1)
    print("")    
    
    timesRound = random.randrange(1, 10, 1)
    print ('There will be', timesRound, 'lines printed.')
    i = 0
    while i < timesRound:
        i = i + 1
    strings=[]
    for x in range (i):
        str = ''
        user = random.randrange(1, 15, 1)    
        while len(str) < user:
            num = random.randrange(1, 26, 1)
            str = str + dict.get(num)      
        strings.append(str)
        
    print (strings)
    time.sleep(50)
    return (strings)

def partB(strings):
    strings.sort()
    print ("-Sorting data- (50 seconds)")
    for x in range (50):
        print('.', end="")
        time.sleep(1)
    print("")
    return (strings)

print("Handling dataset 1 (50 seconds)")
strings = partA()
print(partB (strings))

print("Handling dataset 2 (50 seconds)")
strings = partA()
print(partB (strings))

print("Handling dataset 3 (50 seconds)")
strings = partA()
print(partB (strings))