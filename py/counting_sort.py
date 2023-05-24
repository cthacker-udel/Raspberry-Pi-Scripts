def counting_sort(arr):
    
    count_arr = [0] * (len(arr)+1)
    
    #crafting count array
    for eachelem in arr:
        count_arr[eachelem] += 1
    for i in range(1,len(count_arr)):
        count_arr[i] += count_arr[i-1]
    new_arr = [0] * len(arr)
    for i in range(len(arr)):
        if count_arr[arr[i]] > 0:
            new_arr[count_arr[arr[i]]-1] = arr[i]
            count_arr[arr[i]] -= 1
    print(new_arr)
    


def main():
    arr = [1,4,1,2,7,5,2]
    counting_sort(arr)
    
    
if __name__ == '__main__':
    main()