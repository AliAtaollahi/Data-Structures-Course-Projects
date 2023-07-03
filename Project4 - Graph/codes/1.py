x_direction=(0,0,-1,1)
y_direction=(1,-1,0,0)
class Point(object):
    def __init__(self, x, y):
        self.X = x
        self.Y = y
def findWay (table,i,j,row,col):
    sum=0
    current=Point(i,j)
    table[i][j] = "0"
    taskList=list()
    taskList.append(current)
    while taskList:
        sum+=1
        current=taskList[-1]
        taskList.pop()
        for direct in range(len(x_direction)):
            newX,newY=current.X+x_direction[direct],current.Y+y_direction[direct]
            if 0<=newX<row and 0<=newY<col and table[newX][newY]=="1":
                table[newX][newY] = "0"
                taskList.append(Point(newX,newY))
    return sum
if __name__ =="__main__":
    row,col,watchs=map(int,input().split(" "))
    table=[list(input()) for i in range(row)]
    result=list()
    for i in range(row):
        for j in range(col):
            if table[i][j] == "1":
                result.append(findWay(table,i,j,row,col))
    sum=0
    result.sort()
    if int(watchs)>len(result):
        for i in range(int(watchs)-len(result)):
            result.append(0)
    for i in range(int(watchs)):
        sum+=result[-i-1]
    print(sum)