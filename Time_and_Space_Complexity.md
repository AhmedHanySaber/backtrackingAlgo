# Time and Space Complexity

## Backtracking Algorithm
- **Time Complexity**: Depends on the problem.
  - N-Queens: O(N!) due to the exponential number of possibilities.
- **Space Complexity**: O(N) for the recursion stack (if board size is N×N).

## Tarjan's SCC Algorithm
- **Time Complexity**: O(V + E), where V is the number of vertices and E is the number of edges.
- **Space Complexity**: O(V) for storing indices, low-link values, and stack.

## Combined Example
- **Time Complexity**: O(V + E) for SCC computation, plus any additional complexity for backtracking.
- **Space Complexity**: O(V) for SCC, plus backtracking stack.