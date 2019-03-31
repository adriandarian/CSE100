| CSE100 Algorithm Design and Analysis | Lab 03, Spring 2019 |
| -- | -- |

---

# Solving the Max Subarray Problem via Divide-and-conquer

## Description

In this lab assignment, your job is to implement the $O(nlogn)$ time divide-and-conquer algorithm for the Max Subarray Problem; for the pseudo-code, see page 72 in the textbook or the lecture slides. Recall that in the problem, we are given as input an array $A[1...n]$ of $n$ integers, and would like to find $i^*$ and $j^* (1 <= i^* <= j^* <= n)$ such that $A[i^*] + A[i^* + 1] + ... A[j^*]$ is maximized.

## Input Structure

The input starts with an integer number n, which indicates the array size. Then, the integers, $A[1], A[2], ..., A[n],$ follow, one per line.

## Output Structure

Output the sum of integers in the max subarray, i.e., $A[i^*] + A[i^* + 1] + ...+ A[j^*]$.

## Examples of input and output

### _Input_

```c++
6
-3
11
-2
-3
10
-5
```

### _Output_

`16`

> Note that in this example, the max subarray is $A[2...5]$. So, we output $A[i^*] + ... + A[j^*] = 11 - 2 - 3 + 10 = 16$. The output is only one number and has no white space.

See the lab guidelines for submission/grading, etc., which can be found at [The root of the Repo](https://github.com/adriandarian/CSE100/Labs)
