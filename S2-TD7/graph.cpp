#include <iostream>
#include <vector>
#include "graph.hpp"
#include <unordered_map>
#include <utility>
#include <stack>
#include <queue>

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
    std::cout << std::endl;
}

// ———————— 02-02 —————————
void Graph::WeightedGraph::print_BFS(int const start) const {
    std::unordered_map<int, bool> checked;
    for (const auto& vertex : adjacency_list) {
        checked[vertex.first] = false;
    }
    std::queue<int> queue;
    queue.push(start);
    
    while (!queue.empty()) {
        int current_vertex = queue.front();
        queue.pop();
        if (!checked[current_vertex]) {
            checked[current_vertex] = true;
            std::cout << current_vertex << ", ";  
            for (const auto& next_vertex : adjacency_list.at(current_vertex)) {
                if (!checked[next_vertex.to]) {
                    queue.push(next_vertex.to);
                }
            }
        }
    }
    std::cout << std::endl;
}

// ———————— 02-Bonus —————————
void Graph::WeightedGraph::DFS(int const start, std::function<void(int const)> const& callback) const {
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
            callback(current_vertex);
            
            for (const auto& next_vertex : adjacency_list.at(current_vertex)) {
                if (!checked[next_vertex.to]) {
                    stack.push(next_vertex.to);
                }
            }
        }
    }
}

// ===== Exercice Dijkstra =====
std::unordered_map<int, std::pair<float, int>> dijkstra(Graph::WeightedGraph const& graph, int const& start, int const end) {
    // On crée un tableau associatif pour stocker les distances les plus courtes connues pour aller du sommet de départ à chaque sommet visité
    // La clé est l'identifiant du sommet et la valeur est un pair (distance, sommet précédent)
    std::unordered_map<int, std::pair<float, int>> distances {};

    // On crée une file de priorité pour stocker les sommets à visiter
    // la pair contient la distance pour aller jusqu'au sommet et l'identifiant du sommet

    // Ce type compliqué permet d'indiquer que l'on souhaite trier les éléments par ordre croissant (std::greater) et donc les éléments les plus petits seront au début de la file (top) (Min heap)
    std::priority_queue<std::pair<float, int>, std::vector<std::pair<float, int>>, std::greater<std::pair<float, int>>> to_visit {};

    // 1. On ajoute le sommet de départ à la liste des sommets à visiter avec une distance de 0 (on est déjà sur le sommet de départ)
    to_visit.push({0, start});
    distances[start] = {0, -1}; // -1 represents no previous vertex

    // Tant qu'il reste des sommets à visiter
    while (!to_visit.empty()) {
        // 2. On récupère le sommet le plus proche du sommet de départ dans la liste de priorité to_visit
        auto current = to_visit.top();
        to_visit.pop();
        float current_distance = current.first;
        int current_vertex = current.second;

        // 3.Si on atteins le point d'arrivé, on s'arrête
        if (current_vertex == end) {
            return distances;
        }

        // 3. On parcoure la liste des voisins (grâce à la liste d'adjacence) du nœud courant
        for (const auto& neighbor : graph.adjacency_list.at(current_vertex)) {
            int neighbor_vertex = neighbor.to;
            float edge_weight = neighbor.weight;

            // 4. on regarde si le nœud existe dans le tableau associatif (si oui il a déjà été visité)
            auto find_node = distances.find(neighbor_vertex);
            bool const visited = (find_node != distances.end());

            if (!visited) {
                // 5. Si le nœud n'a pas été visité, on l'ajoute au tableau associatif en calculant la distance pour aller jusqu'à ce nœud
                // la distance actuelle + le poids de l'arête)
                distances[neighbor_vertex] = {current_distance + edge_weight, current_vertex};

                // 6. On ajoute également le nœud de destination à la liste des nœuds à visiter (avec la distance également pour prioriser les nœuds les plus proches)
                to_visit.push({current_distance + edge_weight, neighbor_vertex});
            } else {
                // 7. Si il a déjà été visité, On test si la distance dans le tableau associatif est plus grande
                // Si c'est le cas on a trouvé un plus court chemin, on met à jour le tableau associatif et on ajoute de nouveau le sommet de destination dans la liste à visiter
                if (current_distance + edge_weight < find_node->second.first) {
                    distances[neighbor_vertex] = {current_distance + edge_weight, current_vertex};
                    to_visit.push({current_distance + edge_weight, neighbor_vertex});
                }
            }
        }
    }
    return distances;
}



