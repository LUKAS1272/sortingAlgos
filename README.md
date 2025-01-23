# Sorting Algorithms Explained in Actions

## Bubble Sort
1. **Compare** adjacent elements.
2. **Swap** them if they are out of order.
3. **Repeat** until no more swaps are needed.

**Time Complexity**: O(n²) (average and worst)  
**In-Place?**: Yes (no extra array needed)

**Positives**:
- Simple to understand and implement.
- Useful for small datasets or teaching purposes.

**Negatives**:
- Extremely inefficient for large datasets.
- Performs unnecessary comparisons even when the list is nearly sorted.

---

## Insertion Sort
1. **Pick** the next element from the unsorted part.
2. **Compare** it with elements in the sorted part.
3. **Shift** larger elements one position to the right.
4. **Insert** the element into its correct position.

**Time Complexity**: O(n²) (average and worst)  
**In-Place?**: Yes (no extra array needed)

**Positives**:
- Efficient for small or nearly sorted datasets.
- Easy to implement and understand.

**Negatives**:
- Poor performance on large datasets.
- Comparisons increase significantly with unsorted inputs.

---

## Selection Sort
1. **Scan** the unsorted part to find the smallest element.
2. **Swap** it with the first unsorted element.
3. **Move** the boundary between sorted and unsorted parts.
4. **Repeat** until the entire list is sorted.

**Time Complexity**: O(n²) (average and worst)  
**In-Place?**: Yes (no extra array needed)

**Positives**:
- Minimal memory usage.
- Performs fewer swaps compared to Bubble Sort.

**Negatives**:
- Inefficient for large datasets.
- Always performs O(n²) comparisons regardless of input order.

---

## Quick Sort
1. **Choose** a pivot (e.g., first or last element).
2. **Partition** the list into elements smaller and larger than the pivot.
3. **Recursively** apply the same steps to each partition.
4. **Combine** the sorted partitions with the pivot in between.

**Time Complexity**: O(n log n) on average, O(n²) in the worst case  
**In-Place?**: Yes (no extra array needed, but uses recursion stack)

**Positives**:
- Very efficient for large datasets.
- Performs well on average with a good pivot selection strategy.

**Negatives**:
- Performance can degrade to O(n²) with poor pivot selection.
- Requires additional stack space due to recursion.

---

## Merge Sort
1. **Divide** the list into two halves.
2. **Recursively** sort each half.
3. **Merge** the two sorted halves by comparing the front elements.
4. **Continue** until a single sorted list remains.

**Time Complexity**: O(n log n) (average and worst)  
**In-Place?**: No (requires extra arrays during merging)

**Positives**:
- Guarantees O(n log n) performance.
- Stable sorting algorithm (preserves the order of equal elements).

**Negatives**:
- Requires additional memory for merging.
- Slower compared to Quick Sort in practical scenarios due to memory overhead.

---

## Heap Sort
1. **Build** a max-heap from the entire list.
2. **Swap** the top of the heap (largest) with the last element.
3. **Reduce** the heap size by one.
4. **Re-heapify** the reduced heap and repeat.

**Time Complexity**: O(n log n) (average and worst)  
**In-Place?**: Yes (no extra array needed aside from the heap structure in-place)

**Positives**:
- Consistent O(n log n) performance.
- Does not require additional memory.

**Negatives**:
- Not stable (does not preserve the order of equal elements).
- Slower than Quick Sort for practical datasets.

---

## Radix Sort
1. **Determine** the number of digits (d) of the largest element in the list.  
2. **Iterate** through each digit position starting from the least significant digit (LSD) to the most significant digit (MSD).  
3. **Sort** the list at each digit position using a **stable** sorting method (often Counting Sort).  
4. **Repeat** for the next digit position until all digit positions have been processed.  

**Time Complexity**: O(n * d), where d is the number of digits. In practical terms, often approximated as O(n log n) if d is proportional to log of the maximum value. 
**In-Place?**: No (requires additional data structures, such as the array used in each Counting Sort step)

**Positives**:
- Very efficient for large datasets with small digit ranges.
- Performance is not dependent on comparisons, making it faster for specific inputs.

**Negatives**:
- Requires additional memory for intermediate sorting.
- Limited to integer or fixed-format data (e.g., strings of equal length).