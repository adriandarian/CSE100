| CSE100 Algorithm Design and Analysis | Lab 11, Spring 2019 |
| -- | -- |

---

# Strongly Connected Components

## Description

A strongly connected component (SCC) of a directed graph $G = (V, E)$ is defined as a maximal set of vertices $C \in V$ such that for every pair of vertices $u$ and $v$ in $C$, the two vertices are reachable from each other. In this lab assignment, you are asked to decompose a given directed graph $G = (V, E)$ into a collection of SCCs.

## Input

The input will have the following format. The first integer refers to the number of vertices, $|V|$. The second integer is the number of edges, $|E|$. Vertices are indexed by $0, 1, \dots, |V| - 1$. Then, two numbers $u v$ appearing in each line means an edge $(u, v)$. See the example given below.

## Output

Output the SCC ID of every vertex. A SCC's ID is defined as the smallest index of any vertex in the SCC. In other words, you have to output, for each vertex $v$, the ID of the unique SCC the vertex $v$ belongs to. You must output the ID for each vertex, considering vertices in the order of $0, 1, \dots, |V| - 1$.

## Examples of input and output

$Input$

```c++
8
13
0 1
1 2
1 4
1 5
2 3
2 6
3 2
3 7
4 0
4 5
5 6
6 5
6 7
```

$Output for problem 2$

```c++
0
0
2
2
0
5
5
7
```

What this answer implies is that the graph is decomposed into four SCCs, $\{0, 1, 4\}, \{2, 3\}, \{5, 6\}, \{7\}$. Note that all vertices in the same SCC have the same label, which is equal to the smallest index of all vertices in the same component. For example, vertices $0, 1$ and $4$ are all labeled with $0$.

See the lab guidelines for submission/grading, etc., which can be found at [The root of the Repo](https://github.com/adriandarian/CSE100/Labs)
