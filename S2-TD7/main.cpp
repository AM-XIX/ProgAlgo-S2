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
    // ———————— 02-02 —————————
    graph2.print_BFS(1);
    // ———————— 02-Bonus —————————
    std::cout << "DFS from node 1:" << std::endl << "Visited nodes: ";
    graph2.DFS(1, [](int const node_id) { std::cout << node_id << " "; });
    std::cout << std::endl;

    // ======== Dijkstra ========
    // D'après le schéma de l'énoncé
    Graph::WeightedGraph graph3;
    graph3.add_vertex('A');
    graph3.add_vertex('B');
    graph3.add_vertex('C');
    graph3.add_vertex('D');
    graph3.add_vertex('E');
    graph3.add_vertex('F');
    graph3.add_directed_edge('A', 'B', 1);
    graph3.add_directed_edge('A', 'C', 5);
    graph3.add_directed_edge('A', 'D', 2);
    graph3.add_directed_edge('B', 'C', 4);
    graph3.add_directed_edge('B', 'D', 5);
    graph3.add_directed_edge('C', 'D', 2);
    graph3.add_directed_edge('C', 'E', 3);
    graph3.add_directed_edge('C', 'F', 4);
    graph3.add_directed_edge('D', 'E', 5);
    graph3.add_directed_edge('E', 'F', 3);


    std::cout << "Le + court chemin de A à E :" << std::endl;
    auto shortest_path = dijkstra(graph3, 'A', 'E');
    if (shortest_path.empty()) {
        std::cout << "Pas de chemin possible." << std::endl;
    } else {
        std::cout << "Chemin : ";
        for (auto vertex : shortest_path) {
            std::cout << static_cast<char>(vertex.first) << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}