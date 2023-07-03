def findPowerN(max):
    i=0
    while(2**(i+1)<=max+1):
        i+=1
    return i

if __name__ == "__main__":
    num=int(input())
    for i in range(num):
        min,max=[int(x) for x in input().split()]
        power=findPowerN(max)
        if(2**power-1>=min):
            print(2**power-1)
            continue
        finalNum=min
        minBinary=bin(min).replace("0b", "")
        maxBinary=bin(max).replace("0b", "")
        minBinary='0'*(len(maxBinary)-len(minBinary))+minBinary
        for j in range(len(maxBinary)-1,-1,-1):
            if(minBinary[j]=="0"):
                finalNum+=2**(len(maxBinary)-j-1)
                if(finalNum>max):
                    finalNum-=2**(len(maxBinary)-j-1)
                    break
        print(finalNum)