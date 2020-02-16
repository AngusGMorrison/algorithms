=begin
  Selection sort
  - Θ(n^2)
  - O(n^2)
  - Ω(n^2)
  - Unstable
  - Performs poorly; not used in practice
=end

def selection_sort(arr)
  length = arr.length
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