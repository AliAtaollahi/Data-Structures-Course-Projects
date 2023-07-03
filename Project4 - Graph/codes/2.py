x_direction=(0,0,-1,1,1,1,-1,-1)
y_direction=(1,-1,0,0,1,-1,1,-1)
def findGoal(graph, start, goal):
    searched = []
    queue = [[start]]
    while queue:
        path = queue.pop(0)
        node = path[-1]
        if node not in searched:
            neigs = graph[node]
            for neighbour in neigs:
                newPath = list(path)
                newPath.append(neighbour)
                queue.append(newPath)
                if neighbour == goal:
                    return newPath
            searched.append(node)
    return []

if __name__ == "__main__":
    row, col = map(int, input().split(" "))
    target=0
    table=list()
    dic={}
    for i in range(row):
       table.append(input())
       if "$" in table[-1]:
          target = i*col+table[-1].index("$")
    for i in range(row):
       for j in range(col):
          edges=list()
          if(table[i][j]=='@' or table[i][j]=='$'):
             if(i==row-1 or i==0 or j==col-1 or j==0):
                edges.append(-1)
             for direct in range(len(x_direction)):
                newX, newY = i + x_direction[direct], j + y_direction[direct]
                if 0 <= newX < row and 0 <= newY < col and (table[newX][newY] == "@" or table[newX][newY] == "$"):
                   edges.append(newX*col+newY)
          if len(edges) != 0 or i*col+j==target:
             dic[i*col+j]=edges
    sum=len(findGoal(dic, target, -1))
    print(sum-1)