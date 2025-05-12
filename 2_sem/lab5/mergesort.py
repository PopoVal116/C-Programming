def mergesort(list):
<<<<<<< HEAD
    print("mergesort left called")
=======
    print("mergesort right called")
>>>>>>> Mergesort-Impl
    #return list
    if len(list) <= 1:
      return list

    middle = len(list) // 2
    left_list = list[:middle]
    right_list = list[middle:]

    left_list = mergesort(left_list)
    right_list = mergesort(right_list)

    return merge(left_list, right_list)

<<<<<<< HEAD

def merge(left,right):
    print("merge left called")
=======
def merge(left,right):
    print("merge right called")
>>>>>>> Mergesort-Impl
    merged = []
    left_index = 0
    right_index = 0

    while left_index < len(left) and right_index < len(right):
        if left[left_index] <= right[right_index]:
            merged.append(left[left_index])
<<<<<<< HEAD
            left_index = left_index + 1
        else:
            merged.append(right[right_index])
            right_index = right_index + 1
=======
            left_index += 1
        else:
            merged.append(right[right_index])
            right_index += 1
>>>>>>> Mergesort-Impl

    merged += left[left_index:]
    merged += right[right_index:]

    return merged
