def mergesort(list):
    print("mergesort left called")
    #return list
    if len(list) <= 1:
      return list

    middle = len(list) // 2
    left_list = list[:middle]
    right_list = list[middle:]

    left_list = mergesort(left_list)
    right_list = mergesort(right_list)

    return merge(left_list, right_list)


def merge(left,right):
    print("merge left called")
    merged = []
    left_index = 0
    right_index = 0

    while left_index < len(left) and right_index < len(right):
        if left[left_index] <= right[right_index]:
            merged.append(left[left_index])
            left_index = left_index + 1
        else:
            merged.append(right[right_index])
            right_index = right_index + 1

    merged += left[left_index:]
    merged += right[right_index:]

    return merged
