| CSE100 Algorithm Design and Analysis | Lab 09, Spring 2019 |
| -- | -- |

---

# Huffman Codes

## Description

Suppose that we have to store a sequence of symbols (a file) efficiently, namely we want to minimize the amount of memory needed. For the sake of simplicity we assume that the symbols are restricted to the first $6$ letters of the alphabet. For example, let us assume that the frequency of different symbols that you have to store are the following:

## Questions and input structure

The input consists of 6 integers, one per each line. Each integer represents the frequency of characters, $A, B, C, D, E, and F$, in this order. The test cases have been built so that while building trees it never happens that the same frequency appears twice. Then, the decision about which tree goes to the left and which one goes to the right is always straightforward, and the final tree should be unique.

## Examples of input and output

### _Input_

```c++
15
11
5
1
2
4
```

### _Output_

```c++
A:0
B:10
C:110
D:11100
E:11101
F:1111
```

See the lab guidelines for submission/grading, etc., which can be found at [The root of the Repo](https://github.com/adriandarian/CSE100/Labs)
