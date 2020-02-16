=begin
  Bubble sort
  - Θ(n^2)
  - O(n^2)
  - Ω(n^2)
  - Stable
  - Performs poorly; not used in practice
=end

def bubble_sort(arr)
  length = arr.length
  (length - 1).times do |i|
    (length - i - 1).times do |j|
      if arr[j] > arr[j + 1]
        arr[j], arr[j + 1] = arr[j + 1], arr[j]
      end
    end
  end
end

numbers = [ 4, 2, 7, 3, 5, 6, 0 ]
bubble_sort(numbers)
puts numbers
