def isNumbersOK(numbers):
    for i in range(1,len(numbers)-1):
        if((numbers[i-1]+numbers[i+1])/2==numbers[i]): 
            return False
    if((numbers[0]+numbers[-2])/2==numbers[-1] or (numbers[1]+numbers[-1])/2==numbers[0]):
        return False
    return True

if __name__ == "__main__":
    size=int(input())
    numbers=[int(x) for x in input().split()]
    numbers.sort()
    finalNumbers=numbers.copy()
    for i in range (0,len(numbers),2):
        finalNumbers[i]=numbers[int(i/2)]
    for i in range (1,len(numbers),2):
        finalNumbers[i]=numbers[int(i/2+len(numbers)/2)]
    if(isNumbersOK(finalNumbers)):
        [print(int(x), end = " ") for x in finalNumbers] 
    else:
        finalNumbers[0],finalNumbers[-1]=finalNumbers[-1],finalNumbers[0]
        if(isNumbersOK(finalNumbers)):
            [print(int(x), end = " ") for x in finalNumbers]
        else:
            print(-1)