directions=((1,1),(1,-1),(-1,-1),(-1,1),(1,0),(-1,0),(0,1),(0,-1))
def makePath(table,results,path,loc,word,index):
    if(index==len(word)):
        results.extend(path)
        return
    for i in range(len(directions)): 
        x,y=loc[0]+directions[i][0],loc[1]+directions[i][1]
        if((x>=0) and (x<len(table)) and (y>=0) and (y<len(table))and (word[index]==table[x][y])):
            table[x][y]="-"
            path.append([x,y])
            makePath(table,results,path,[x,y],word,index+1)
            table[x][y]=word[index]
            path.pop()
            
    
if __name__ == "__main__":
    n,word=input().split(",")
    n=int(n)
    table=[input().split(",") for i in range(n)]
    path=[[]]
    results=list(list(list()))
    for i in range(n):
        for j in range(n):
            if(table[i][j]==word[0]):
                path.append([i,j])
                table[i][j]="-"
                makePath(table,results,path,[i,j],word,1)
                table[i][j]=word[0]
                path.pop()
    for i in range(1,len(results)):
        if(results[i]==[]):
            print()
        else:
            print("("+str(results[i][0])+", "+str(results[i][1])+")",end='')        
            if(i+1<len(results) and results[i+1]!=[]):
                print(",",end='')