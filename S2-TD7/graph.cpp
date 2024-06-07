#include <iostream>
#include <vector>
#include "graph.hpp"
#include <unordered_map>
#include <utility>
#include <stack>

// ===== Exercice 1 =====
// ———————— 01-01 —————————
void Graph::WeightedGraph::add_vertex(int const id) {
    if (adjacency_list.find(id) != adjacency_list.end()) {
        std::cout << "Nope le vertex " << id << " existe déjà" << std::endl;
        return;
    }
    else {
        adjacency_list.insert({id, {}});
        std::cout << "Vertex " << id << " ajouté" << std::endl;
    }
}

// ———————— 01-02 —————————
void Graph::WeightedGraph::add_directed_edge(int const from, int const to, float const weight) {
    this->add_vertex(to);
    this->add_vertex(from);
    auto key { this->adjacency_list.find(from) };
    (*key).second.push_back({to, weight}); 
}

// ———————— 01-03 —————————
void Graph::WeightedGraph::add_undirected_edge(int const node1, int const node2, float const weight) {
    this->add_directed_edge(node1, node2, weight);
    this->add_directed_edge(node2, node1, weight);
}

// ———————— 01-04 —————————
Graph::WeightedGraph adjacency_list_from_adjacency_matrix(std::vector<std::vector<int>> const& adjacency_matrix) {
    Graph::WeightedGraph graph;
    // i = from, j = to 
    int num_vertices = adjacency_matrix.size();
    for (int i = 0; i < num_vertices; i++) {
        graph.add_vertex(i);
    }
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            if (adjacency_matrix[i][j] != 0) {
                graph.add_directed_edge(i, j, adjacency_matrix[i][j]);
            }
        }
    }

    return graph;
}

// ===== Exercice 2 =====
// ———————— 02-01 —————————
        void Graph::WeightedGraph::print_DFS(int const start) const {
            std::unordered_map<int, bool> checked;
            for (const auto& vertex : adjacency_list) {
                checked[vertex.first] = false;
            }

            std::stack<int> stack;
            stack.push(start);

            while (!stack.empty()) {
                int current_vertex = stack.top();
                stack.pop();

                if (!checked[current_vertex]) {
                    checked[current_vertex] = true;
                    std::cout << current_vertex << ", ";

                    for (const auto& next_vertex : adjacency_list.at(current_vertex)) {
                        if (!checked[next_vertex.to]) {
                            stack.push(next_vertex.to);
                        }
                    }
                }
            }
        }