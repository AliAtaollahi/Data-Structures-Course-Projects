if __name__ == "__main__":
    height,targetLief=map(int,input().split(" "))
    nodeCounter,cursor,direct=1,1,-1
    down,up=1,2**height
    while True:
        n=2**(height-1)
        if(down==up):
            break
        if(direct==-1):
            if(down <= targetLief <= up-n):
                nodeCounter+=1
                up -= n
                direct=1
            else:
                nodeCounter+=(n*2)
                down+=n
        elif(direct==1):
            if (down+n<= targetLief <= up):
                nodeCounter+=1
                down += n
                direct=-1
            else:
                nodeCounter +=(n*2)
                up-=n
        height-=1
    print(nodeCounter-1)