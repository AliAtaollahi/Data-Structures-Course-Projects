def partt(listLeft, rightList,index):
    listSorted = []
    listLeftIndex = rightListIndex = 0
    listLeft_length, rightList_length = len(listLeft), len(rightList)
    for _ in range(listLeft_length + rightList_length):
        if listLeftIndex < listLeft_length and rightListIndex < rightList_length:
            if listLeft[listLeftIndex][index] <= rightList[rightListIndex][index]:
                listSorted.append(listLeft[listLeftIndex])
                listLeftIndex += 1
            else:
                listSorted.append(rightList[rightListIndex])
                rightListIndex += 1
        elif listLeftIndex == listLeft_length:
            listSorted.append(rightList[rightListIndex])
            rightListIndex += 1
        elif rightListIndex == rightList_length:
            listSorted.append(listLeft[listLeftIndex])
            listLeftIndex += 1
    return listSorted

def ssoorrtt(nums,index):
    if len(nums) <= 1:
        return nums
    mid = len(nums) // 2
    listLeft = ssoorrtt(nums[:mid],index)
    rightList = ssoorrtt(nums[mid:],index)
    return partt(listLeft, rightList,index)


col,res1,res2,sum3,res4=int(input()),0,0,0,0
table = [ [0]*4 for i in range(col)]
for i in range(2):
    inp=input().split(" ")
    if inp[-1]=='':
        inp.pop()
    nums=list(int(num) for num in inp)
    for j in range(col):
        table[j][i+1]=nums[j]

for j in range(col):
    res1+=table[j][1]
    res2+=table[j][2]
    table[j][0] = table[j][2] + table[j][1]
    table[j][3]= j + 1

#table.sort(key = lambda x: x[2])
table=ssoorrtt(table,0)
nums=int(col/2)
print(nums+1)
targets=table[nums:] if col%2==1 else table[nums-1:]
rest=table[:nums] if col%2==1 else table[:nums-1]
if col%2==1:
    for j in range(nums, col):
        sum3 += table[j][1]
        res4 += table[j][2]
else:
    for j in range(nums-1, col):
        sum3 += table[j][1]
        res4 += table[j][2]
while res4<=res2/2 or sum3<=res1/2:
    if res4 <= res2 / 2:
        targets=ssoorrtt(targets,1)
        rest = ssoorrtt(rest, 2)
        rest.reverse()
        for i in range(len(rest)):
            res4 = res4 + rest[i][2] - targets[i][2]
            sum3 = sum3 + rest[i][1] - targets[i][1]
            targets[i], rest[i] = rest[i], targets[i]
            if not (res4 <= res2 / 2):
                break
    if sum3 <= res1 / 2:
        targets=ssoorrtt(targets,2)
        rest = ssoorrtt(rest, 1)
        rest.reverse()
        for i in range(len(rest)):
            res4 = res4 + rest[i][2] - targets[i][2]
            sum3 = sum3 + rest[i][1] - targets[i][1]
            targets[i], rest[i] = rest[i], targets[i]
            if not (sum3 <= res1 / 2):
                break
[print(targets[i][3],end=" ") for i in range(len(targets))]