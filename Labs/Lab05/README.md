| CSE100 Algorithm Design and Analysis | Lab 05, Spring 2019 |
| -- | -- |

---

# RadixSort

## Description

In this assignment you will implement RadixSort. See the textbook for the pseudocode.

## Input Structure

You are going to apply RadixSort to sort vectors. The input starts with an integer number which indicates the number of vectors to be sorted. Then vectors follow, one vector per line. Each vector consists of 10 numbers where each number has a value in $\{0, 1, 2, 3\}$. Entries of a vector are separated by a space.

## Output Structure

Output the sorted sequence of vectors, one per line. Vector $i$ must appear before vector $j$ in your output if and only if for some $d \in \{1, 2, \dots, 10\}$, vector $i$ is smaller than or equal to vector $j$ of the $d$th entry, and the two vectors are equal for any of the first $d - 1$ entries.

## Examples of input and output

### _Input_

```c++
5
3 3 3 3 3 2 2 2 2 2
2 3 2 2 2 2 2 2 2 2
1 3 0 0 2 1 0 0 0 0
1 3 0 0 2 2 0 0 0 0
2 3 2 1 2 2 2 2 2 2
```

### _Output_

```c++
1;3;0;0;2;1;0;0;0;0;
1;3;0;0;2;2;0;0;0;0;
2;3;2;1;2;2;2;2;2;2;
2;3;2;2;2;2;2;2;2;2;
3;3;3;3;3;2;2;2;2;2;
```

> More precisely, this output example has `6` lines since a `cout << endl;` call was made at the end of each of the first 5 lines; those are the only white characters;.

See the lab guidelines for submission/grading, etc., which can be found at [The root of the Repo](https://github.com/adriandarian/CSE100/Labs)
