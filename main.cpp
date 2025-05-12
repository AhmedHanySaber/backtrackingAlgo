#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;

// Tarjan's SCC Algorithm
class TarjanSCC {
public:
    TarjanSCC(int vertices) : V(vertices), adj(vertices), index(0) {
        indices.assign(V, -1);
        lowlink.assign(V, -1);
        onStack.assign(V, false);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void findSCCs() {
        for (int v = 0; v < V; ++v) {
            if (indices[v] == -1) {
                strongConnect(v);
            }
        }
    }

    const vector<unordered_set<int>>& getSCCs() const {
        return sccs;
    }

private:
    int V, index;
    vector<vector<int>> adj;
    vector<int> indices, lowlink;
    vector<bool> onStack;
    stack<int> st;
    vector<unordered_set<int>> sccs;

    void strongConnect(int v) {
        indices[v] = lowlink[v] = index++;
        st.push(v);
        onStack[v] = true;

        for (int w : adj[v]) {
            if (indices[w] == -1) {
                strongConnect(w);
                lowlink[v] = min(lowlink[v], lowlink[w]);
            } else if (onStack[w]) {
                lowlink[v] = min(lowlink[v], indices[w]);
            }
        }

        if (lowlink[v] == indices[v]) {
            unordered_set<int> scc;
            while (true) {
                int w = st.top();
                st.pop();
                onStack[w] = false;
                scc.insert(w);
                if (w == v) break;
            }
            sccs.push_back(scc);
        }
    }
};

// Backtracking Algorithm for Pathfinding
class EscapeGame {
public:
    EscapeGame(int vertices, int start, int exit, const vector<unordered_set<int>>& safeZones)
        : V(vertices), startNode(start), exitNode(exit), adj(vertices), safeZones(safeZones) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void playGame() {
        vector<bool> visited(V, false);
        if (findPath(startNode, visited)) {
            cout << "Escape Path Found: ";
            for (int node : path) {
                cout << node << " ";
            }
            cout << endl;
        } else {
            cout << "No Escape Path Found!" << endl;
        }
    }

private:
    int V, startNode, exitNode;
    vector<vector<int>> adj;
    vector<int> path;
    const vector<unordered_set<int>>& safeZones;

    bool findPath(int current, vector<bool>& visited) {
        // Mark the current node as visited and add it to the path
        visited[current] = true;
        path.push_back(current);

        // If the current node is the exit node, return true
        if (current == exitNode) {
            return true;
        }

        // Check all neighbors
        for (int neighbor : adj[current]) {
            if (!visited[neighbor] && isSafe(neighbor)) {
                if (findPath(neighbor, visited)) {
                    return true;
                }
            }
        }

        // Backtrack
        visited[current] = false;
        path.pop_back();
        return false;
    }

    bool isSafe(int node) {
        // A node is safe if it belongs to any SCC
        for (const auto& scc : safeZones) {
            if (scc.find(node) != scc.end()) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    int vertices = 8;
    int startNode = 0, exitNode = 7;

    // Create the graph
    TarjanSCC tarjan(vertices);
    tarjan.addEdge(0, 1);
    tarjan.addEdge(1, 2);
    tarjan.addEdge(2, 0);
    tarjan.addEdge(2, 3);
    tarjan.addEdge(3, 4);
    tarjan.addEdge(4, 5);
    tarjan.addEdge(5, 3);
    tarjan.addEdge(5, 6);
    tarjan.addEdge(6, 7);

    // Find SCCs
    tarjan.findSCCs();
    const auto& safeZones = tarjan.getSCCs();

    // Setup the game
    EscapeGame game(vertices, startNode, exitNode, safeZones);
    game.addEdge(0, 1);
    game.addEdge(1, 2);
    game.addEdge(2, 0);
    game.addEdge(2, 3);
    game.addEdge(3, 4);
    game.addEdge(4, 5);
    game.addEdge(5, 3);
    game.addEdge(5, 6);
    game.addEdge(6, 7);

    // Play the game
    game.playGame();

    return 0;
}