=begin
  Merge sort
  - O(nlogn)
  - Divide and conquer alogrithm
  - More efficient than quicksort for large datasets
  - Requires additional storage for auxiliary arrays (not in-place)
  - Stable
=end

def merge_sort(arr)
  return arr unless arr.length > 1

  # Recursively split the array down to single digits
  mid = arr.length / 2
  first_half = merge_sort(arr[0...mid])
  second_half = merge_sort(arr[mid..-1])

  # Merge the halves by comparing their first elements and shifting
  sorted = []
  unless first_half.empty? || second_half.empty?
    sorted << (first_half[0] < second_half[0] ? first_half.shift : second_half.shift)
  end

  # Add the remaining element from either the first half or the second half
  sorted + first_half + second_half
end

numbers = [ 4, 2, 7, 3, 5, 6, 0, 1 ]
sorted = merge_sort(numbers)
puts sorted