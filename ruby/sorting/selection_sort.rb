=begin
  Selection sort
  - O(n^2)
  - Counterpart of bubble sort
  - Performs poorly in real-world applications
=end

def selection_sort(arr)
  length = arr.length()
  for i in (0...(length - 1)) do
    for j in ((i + 1)...length) do
      if arr[j] < arr[i]
        arr[j], arr[i] = arr[i], arr[j]
      end
    end
  end
end

numbers = [ 4, 2, 7, 3, 5, 6, 0 ]
selection_sort(numbers)
puts numbers