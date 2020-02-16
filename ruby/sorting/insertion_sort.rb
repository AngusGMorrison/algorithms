=begin
  Insertion sort
  - Θ(n^2)
  - O(n^2)
  - Ω(n)
  - Stable
  - Limited real-world use
=end

def insertion_sort(arr)
  for i in (1...arr.length) do
    key = arr[i];
    j = i - 1;
    while j >= 0 && arr[j] > key
      arr[j + 1] = arr[j]
      j -= 1
    end
    arr[j + 1] = key
  end
end

numbers = [ 4, 2, 7, 3, 5, 6, 0 ]
insertion_sort(numbers)
puts numbers