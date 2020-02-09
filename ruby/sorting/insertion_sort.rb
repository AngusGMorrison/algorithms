=begin
  Insertion sort
  - O(n^2)
  - May outperform merge sort for very small datasets
  - Not typically used in real-world context
=end

def insertion_sort(arr)
  for i in (1...arr.length)
    j = i
    while j > 0 && arr[j - 1] > arr[j]
      arr[j], arr[j - 1] = arr[j - 1], arr[j]
      j -= 1
    end
  end
end

numbers = [ 4, 2, 7, 3, 5, 6, 0 ]
insertion_sort(numbers)
puts numbers