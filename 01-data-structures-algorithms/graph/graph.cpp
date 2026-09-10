#include <cassert>
#include <iostream>
#include <queue>
#include <vector>

class Graph {
private:
    std::vector<std::vector<int>> adjacency_;

public:
    explicit Graph(int vertices) : adjacency_(vertices) {}

    void add_edge(int u, int v, bool undirected = true) {
        adjacency_.at(u).push_back(v);
        if (undirected) adjacency_.at(v).push_back(u);
    }

    std::vector<int> bfs(int start) const {
        std::vector<bool> visited(adjacency_.size(), false);
        std::vector<int> order;
        std::queue<int> q;

        visited.at(start) = true;
        q.push(start);

        while (!q.empty()) {
            const int u = q.front();
            q.pop();
            order.push_back(u);

            for (int v : adjacency_.at(u)) {
                if (!visited.at(v)) {
                    visited.at(v) = true;
                    q.push(v);
                }
            }
        }
        return order;
    }

    std::vector<int> dfs(int start) const {
        std::vector<bool> visited(adjacency_.size(), false);
        std::vector<int> order;

        auto visit = [&](auto&& self, int u) -> void {
            visited.at(u) = true;
            order.push_back(u);
            for (int v : adjacency_.at(u))
                if (!visited.at(v)) self(self, v);
        };

        visit(visit, start);
        return order;
    }
};

int main() {
    Graph graph(5);
    graph.add_edge(0, 1);
    graph.add_edge(0, 2);
    graph.add_edge(1, 3);
    graph.add_edge(2, 4);

    const auto bfs = graph.bfs(0);
    const auto dfs = graph.dfs(0);

    assert(bfs.size() == 5);
    assert(dfs.size() == 5);

    std::cout << "BFS: ";
    for (int v : bfs) std::cout << v << ' ';
    std::cout << "\nDFS: ";
    for (int v : dfs) std::cout << v << ' ';
    std::cout << "\nGraph demo passed.\n";

    return 0;
}
