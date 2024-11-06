# Dynamic Array in C++ (Custom Vector Implementation)

## Overview
This repository contains a custom implementation of a dynamic array in C++, similar to `std::vector`, using C-style arrays. The dynamic array supports basic operations such as inserting elements, accessing elements, and automatic resizing when the capacity is reached.

This also analyzes the amortized runtime for inserting `n` elements into a dynamic array that doubles in size when needed, using two methods: the **aggregate method** and the **accounting method**. This analysis is based on concepts from Section 17.4 of *Introduction to Algorithms* by Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, and Clifford Stein.

---

## Implementation

The code for the dynamic array is implemented in the `dynamic_table.cpp` file.

---

## Amortized Runtime Analysis

### Problem Statement
Consider a dynamic array that doubles its size whenever it runs out of capacity. We want to determine the amortized runtime for inserting `n` elements.

1. **Aggregate Method**: Calculate the total cost for `n` insertions and divide by `n` to determine the amortized cost per insertion.
2. **Accounting Method**: Assign a fixed "credit" to each operation to cover future resizing costs.

### Amortized Analysis Methods

#### 1. Aggregate Method
The aggregate method involves calculating the total cost of `n` insertions and then dividing by `n` to determine the amortized cost per insertion.

- **Regular Insertions**: Each insertion costs \( O(1) \) if there’s available space.
- **Resizing**: When the array reaches full capacity, it doubles in size. This requires copying all existing elements, resulting in a cost of \( O(n) \) for each resize.

The total cost \( T(n) \) for `n` insertions can be calculated as:
\[
T(n) = O(n) + O\left(\frac{n}{2}\right) + O\left(\frac{n}{4}\right) + \ldots + O(1)
\]
This geometric series sums up to \( O(2n) \), simplifying to \( O(n) \).

**Amortized Cost per Insertion**:
\[
\frac{T(n)}{n} = \frac{O(n)}{n} = O(1)
\]
Therefore, the amortized runtime per insertion using the aggregate method is \( O(1) \).

#### 2. Accounting Method
In the accounting method, we assign "credits" to each insertion to cover both the current insertion cost and future resizing costs.

- **Credit Assignment**: Assign 3 credits to each insertion:
  - 1 credit covers the immediate insertion cost.
  - 2 credits are stored to cover future resizing costs.

- **Cost Usage During Resizing**: When resizing the array (doubling capacity), we need to copy each element from the old array to the new one. The saved credits from previous insertions cover this copying cost.

For example:
- When resizing from capacity `k` to `2k`, copying `k` elements requires `2k` credits, covered by the 2 saved credits per element.

**Amortized Cost per Insertion**:
By charging 3 credits per insertion, we cover both the insertion and future resizing costs, resulting in an amortized cost per operation of \( O(1) \).

---

### Conclusion
Using both the aggregate and accounting methods, we find that the amortized runtime per insertion in a dynamic array that doubles in size is \( O(1) \). This makes the dynamic array efficient for append operations, even though resizing occasionally requires copying elements.
