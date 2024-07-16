def binarySearch(arr,low,high,k):
    res = 0
    while low <= high:
        mid = (low + high)//2
        if k == arr[mid]:
            for i in range(mid,-1,-1):
                if arr[i] == k:
                    res = i
                else:
                    break
            return res+1
        elif k < arr[mid]:
            high = mid-1
        elif k > arr[mid]:
            low = mid+1
arr = [int(i) for i in input(" Enter the numbers : ").split(' ')]
k = int(input(" Enter the k value : "))
print(" Position of k : ",binarySearch(arr,0,len(arr),k))