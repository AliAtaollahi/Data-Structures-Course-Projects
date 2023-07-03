if __name__ == "__main__":
    sum=0
    result=[]
    members=list(map(int,input().split(",")))
    membersInGroup=list(map(int,input().split(",")))
    for i in range(len(members)):
        index=-1
        try:
            index = membersInGroup.index(members[i])
            result.append(membersInGroup[index])
            membersInGroup[-1],membersInGroup[index]=membersInGroup[index],membersInGroup[-1]
            membersInGroup.pop()
        except ValueError:
            index_value = -1
            if(result!=[]):
                sum+=1
            result=[]
    if(result!=[]):
        sum+=1
    print(sum)