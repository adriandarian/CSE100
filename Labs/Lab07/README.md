| CSE100 Algorithm Design and Analysis | Lab 07, Spring 2019 |
| -- | -- |

---

# Dynamic Programming: Rod Cutting

## Description

In this assignment you are asked to implement a dynamic programming algorithm for the Rod Cutting Problem (chapter 15.1). In the Rod Cutting Problem, you are given an integer $n \geq 1$, along with a sequence of positive prices, $p_1, p_2, \dots, p_n$, where $p_i$ is the market price of a rod of length $i$. The goal is to figure out a best way of cutting the given rod of length $n$ to generate the maximum revenue. You can assume that the prices $p_1, p_2, \dots, p_n$ are all integers.

## Input Structure

The input has the following format. The input starts with $n$. Then, $p_1, p_2, \dots, p_n$ follow, one per each line.

## Output Structure

In the first line, output the maximum revenue ($r_n$), followed by an enter key. In the second line, sequentially output the length of each piece in your optimal cutting, followed by a space key. The second line must end by `-1` and an enter key.

## Examples of input and output

### _Input_

```c++
7
1
5
8
9
10
17
17
```

### _Output_

```c++
18
1 6 -1
```

The following is the output with white characters shown.

```c++
18(enter)
1(space)6(space)-1(enter)
```

> Alternatively, the second line can be replace with `6 1 -1`, `2 2 3 -1`, `2 3 2 -1`, or `3 2 2 -1`. That is, any sequence of piece lengths giving the maximum revenue will be considered to be correct.

See the lab guidelines for submission/grading, etc., which can be found at [The root of the Repo](https://github.com/adriandarian/CSE100/Labs)
