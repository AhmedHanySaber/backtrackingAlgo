# Understanding of the Algorithms

## Backtracking Algorithm
Backtracking is a general algorithmic technique for solving problems incrementally. It involves exploring all possible solutions and backtracking when a partial solution doesn't lead to a valid or optimal result.

### Key Features:
- Typically uses recursion.
- Explores all possible paths in a decision tree.
- Backtracks to previous states when a dead-end is encountered.

### Examples of Problems:
- N-Queens problem.
- Sudoku solver.
- Maze traversal.

---

## Tarjan's SCC Algorithm
Tarjan's SCC algorithm is used to find all Strongly Connected Components (SCCs) in a directed graph in linear time. A strongly connected component is a maximal subgraph where every vertex is reachable from every other vertex.

### Key Features:
- Based on Depth First Search (DFS).
- Uses a stack to keep track of visited vertices.
- Low-link values are used to identify SCCs.

### Applications:
- Deadlock detection in operating systems.
- Circuit analysis.
- Social network analysis.