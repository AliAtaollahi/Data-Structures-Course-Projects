if __name__ == "__main__":
    inp=input()
    inp+=" "
    result=""
    cursor=0
    while cursor!=len(inp):
        num=0
        while inp[cursor+num]!=" " and inp[cursor+num]==inp[cursor+num+1]:
            num+=1
        if(num!=0 and num%2==1):
            inp=inp[:cursor]+inp[cursor+num+1:]    
        if(cursor-1>=0 and inp[cursor]==inp[cursor-1]):
            cursor-=1
        else:
            cursor+=1
    print(inp)