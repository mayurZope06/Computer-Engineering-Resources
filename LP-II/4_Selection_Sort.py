n = int(input("Enter size of array: "))
arr = list(map(int, input("Enter array elements: ").split()))

for i in range(n):
    min_index = i
    for j in range(i + 1, n):
        if arr[j] < arr[min_index]:
            min_index = j

    temp = arr[i]
    arr[i] = arr[min_index]
    arr[min_index] = temp

print("Sorted array:", arr)

# Enter size of array: 5
# Enter array elements: 5 3 8 1 2
# Sorted array: [1, 2, 3, 5, 8]

# n = int(input("Enter size of array: "))
# arr = list(map(int, input("Enter elements: ").split()))

# for i in range(n):
#     min_index = i
#     for j in range(i + 1, n):
#         if arr[j] < arr[min_index]:
#             min_index = j

#     arr[i], arr[min_index] = arr[min_index], arr[i]

# print("Sorted array:", arr)

# 4) Selection Sort

# Explanation:
# Selection sort repeatedly finds the smallest element from the unsorted part and swaps it into the correct position.

# Time Complexity:
# Best / Average / Worst = O(n^2)

# Space Complexity: O(1)

# Viva Q&A:
# Q1. What is selection sort?
# A sorting method that selects the minimum element each pass.

# Q2. Is it stable?
# Normally no.

# Q3. Is it in-place?
# Yes.

# Q4. Why is it simple?
# Because it uses only comparisons and swaps.

# n = int(input("Enter size: "))

# arr = []
# for i in range(n):
#     x = int(input("Enter element: "))
#     arr.append(x)