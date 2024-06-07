#include <iostream>
#include <vector>
#include "main.hpp"
#include "graph.cpp"

int main() {
    // ———————— 01-01 —————————
    // Graph::WeightedGraph graph;
    // graph.add_vertex(1);
    // graph.add_vertex(2);
    // graph.add_vertex(3);
    // graph.add_vertex(2);

    // ———————— 01-05 —————————
    Graph::WeightedGraph graph1 = adjacency_list_from_adjacency_matrix({
        // trauma par les bases canoniques de novelli
        {0, 0, 0, 1},
        {1, 0, 0, 0},
        {0, 1, 0, 0}
    });
    Graph::WeightedGraph graph2;
    graph2.add_vertex(1);
    graph2.add_vertex(2);
    graph2.add_vertex(3);
    graph2.add_undirected_edge(1, 2);
    graph2.add_undirected_edge(1, 3);

    bool compare = (graph1 == graph2);
    std::cout << "Les graphs sont " << (compare ? "égaux." : "inégaux.") << std::endl;

    // ———————— 02-01 —————————
    graph2.print_DFS(1);
    return 0;
}