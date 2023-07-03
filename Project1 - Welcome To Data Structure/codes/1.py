MAX_SCALE=1000
if __name__ == "__main__":
    scale=int(input())
    sumCouple=0
    colBluesCounter=[0]*MAX_SCALE
    for i in range (scale):
        rowBlues=0
        line=input()
        for j in range (scale):
            if(line[j]=="B"):
                rowBlues+=1
                colBluesCounter[j]+=1
        sumCouple += (((rowBlues-1)*rowBlues)/2)
    for x in colBluesCounter:
        sumCouple += (((x-1)*x)/2)
    print(int(sumCouple))