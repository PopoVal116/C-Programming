def mergesort(list):
    print("mergesort called")
    #return list
    if len(list) <= 1:
      return list

    middle = len(list) // 2
    left_list = list[:middle]
    right_list = list[middle:]

    left_list = mergesort(left_list)
    right_list = mergesort(right_list)

    return merge(left_list, right_list)
