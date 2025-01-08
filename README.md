# Sorting Algorithms Explained in Actions

## Bubble Sort
1. **Compare** adjacent elements.
2. **Swap** them if they are out of order.
3. **Repeat** until no more swaps are needed.

**Time Complexity**: O(n²) (average and worst)  
**In-Place?**: Yes (no extra array needed)

---

## Insertion Sort
1. **Pick** the next element from the unsorted part.
2. **Compare** it with elements in the sorted part.
3. **Shift** larger elements one position to the right.
4. **Insert** the element into its correct position.

**Time Complexity**: O(n²) (average and worst)  
**In-Place?**: Yes (no extra array needed)

---

## Selection Sort
1. **Scan** the unsorted part to find the smallest element.
2. **Swap** it with the first unsorted element.
3. **Move** the boundary between sorted and unsorted parts.
4. **Repeat** until the entire list is sorted.

**Time Complexity**: O(n²) (average and worst)  
**In-Place?**: Yes (no extra array needed)

---

## Quick Sort
1. **Choose** a pivot (e.g., first or last element).
2. **Partition** the list into elements smaller and larger than the pivot.
3. **Recursively** apply the same steps to each partition.
4. **Combine** the sorted partitions with the pivot in between.

**Time Complexity**: O(n log n) on average, O(n²) in the worst case  
**In-Place?**: Yes (no extra array needed, but uses recursion stack)

---

## Merge Sort
1. **Divide** the list into two halves.
2. **Recursively** sort each half.
3. **Merge** the two sorted halves by comparing the front elements.
4. **Continue** until a single sorted list remains.

**Time Complexity**: O(n log n) (average and worst)  
**In-Place?**: No (requires extra arrays during merging)

---

## Heap Sort
1. **Build** a max-heap from the entire list.
2. **Swap** the top of the heap (largest) with the last element.
3. **Reduce** the heap size by one.
4. **Re-heapify** the reduced heap and repeat.

**Time Complexity**: O(n log n) (average and worst)  
**In-Place?**: Yes (no extra array needed aside from the heap structure in-place)
