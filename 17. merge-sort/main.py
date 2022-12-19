
def merge( arr1, arr2 ):
    
    newArr = []

    a = b = 0

    while a < len( arr1 ) and b < len(arr2) :
        if arr1[a] < arr2[b]:
            newArr.append( arr1[a] )
            a = a + 1
        else:
            newArr.append( arr2[b] )
            b = b + 1 


    while a < len( arr1 ):
        newArr.append(arr1[a])
        a = a + 1

    while b < len(arr2):
        newArr.append( arr2[b] )
        b = b + 1
    
    return newArr




def merge_sort(arr):

    mid = int(len(arr) /2)

    if mid <= 0:
        return arr
        
    remainder = int(len(arr)) % 2

    firstHalf = arr[ 0 : mid + remainder ]
    secondHalf = arr[ mid + remainder : (len(arr) ) ]

    # print('-----------')
    # print( firstHalf )
    # print( secondHalf )
    # print('-----------')

    firstHalf = merge_sort( firstHalf )
    secondHalf = merge_sort( secondHalf )

    print( firstHalf )
    print( secondHalf )

    print('-------------')

    mergedArray = merge( firstHalf, secondHalf )

    print( mergedArray)

    print('-----------')

    for i in range( 0, len( mergedArray ) ):
        arr[i] = mergedArray[i]

    return arr

    
if __name__ == "__main__":
    arr = [  15, 5, 24, 8, 1, 3, 16, 10, 20 ]

    merged = merge_sort( arr )
    print( merged )
