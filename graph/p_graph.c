#include "p_graph.h"

/* ========================= NODES ========================= */

a_node create_node(int index) {
    a_node new_node = (a_node) malloc(sizeof(t_node));
    new_node->index = index;
    new_node->nb_of_connections = 0;
    new_node->node_color = COLOR_NULL;

    return new_node;
}

int is_empty_node(a_node node) {
    return node == NULL;
}

int is_empty_edges(a_node node) {
    if (is_empty_node(node)) {
        printf("Cannot check empty node.\n");
        return -1;
    }

    return node->nb_of_connections == 0;
}

int print_edges(a_node node) {
    if (is_empty_node(node)) {
        printf("Cannot check empty node.\n");
        return -1;
    }

    if (is_empty_edges(node)) {
        printf("\tThis node has no connections\n");
    } else {
        for (int i=0; i<node->nb_of_connections; i++) {
            printf("\t%i\n", node->edges[i]->index);
        }
    }

    return 1;
}


int print_node(a_node node) {
    if (is_empty_node(node)) {
        printf("Cannot print empty node.");
        return 0;
    }

    printf("Node : %i (color: %i)\n", node->index, node->node_color);
    print_edges(node);

    return 1;
}

int number_of_edges(a_node node) {
    if (is_empty_node(node)) {
        printf("Cannot check empty nodes.\n");
        return -1;
    }

    return node->nb_of_connections;
}

int connect_node_to(a_node node1, a_node node2) {
    if (is_empty_node(node1) | is_empty_node(node2)) {
        printf("Cannot connect empty nodes.");
        return 0;
    }

    // Add node2 to node1's edges

    // Get the number of edges (for dynamic resize)
    int nb_connections_node1 = number_of_edges(node1);
    // printf("Before add node %i to node %i : Number of edges = %i\n", node2->index, node1->index, nb_connections_node1);

    // If node1 edges is not NULL
    if (is_empty_edges(node1)) {
        node1->edges = (a_node*) malloc(sizeof(a_node));
        node1->edges[0] = node2;
        node1->nb_of_connections++;

    } else {
        a_node* temp = node1->edges;
        node1->edges = (a_node*) realloc(temp, sizeof(a_node)  * (nb_connections_node1 + 1)); // Reallocation of memory
        node1->edges[nb_connections_node1] = node2;
        node1->nb_of_connections++;
    }

    // printf("Node %i a désormais %i edges\n", node1->index, number_of_edges(node1));

    return 1;
}

int delete_connection(a_node node1, a_node node2) {
    if (is_empty_node(node1) | is_empty_node(node2)) {
        printf("Cannot disconnect empty nodes.");
        return 0;
    }

    // int index_node1;

    a_node last_edge = node2->edges[number_of_edges(node2) - 1];

    // On remplace la connexion avec node 2 par null
    for (int i=0; i<number_of_edges(node2); i++) {
        if (node2->edges[i] == node1) {
            // index_node1 = i;
            
            // On prend la dernière connexion des edges et on la place au niveau de l'ancienne place de node 2
            node2->edges[i] = last_edge;

            // On designe la dernière connexion comme null
            node2->edges[number_of_edges(node2) - 1] = NULL;
            
            // On retire un à la taille du graph
            node2->nb_of_connections--;

            return 1;
        }
    }

    return 0;
}

int connect_nodes_between(a_node node1, a_node node2) {
    if (is_empty_node(node1) | is_empty_node(node2)) {
        printf("Cannot connect empty nodes.");
        return 0;
    }

    connect_node_to(node1, node2);
    connect_node_to(node2, node1);

    return 1;
}


int is_connected_to(a_node node1, a_node node2) {
    if (is_empty_node(node1) | is_empty_node(node2)) {
        printf("Cannot perform action with empty nodes.\n");
        return -1;
    }

    for (int i=0; i<node2->nb_of_connections; i++) {
        if (node1 == node2->edges[i]) {
            return 1;
        }
    }

    return 0;
}

int are_connected_together(a_node node1, a_node node2) {
    if (is_empty_node(node1) | is_empty_node(node2)) {
        printf("Cannot perform action with empty nodes.\n");
        return -1;
    }

    if (is_connected_to(node1, node2) && is_connected_to(node2, node1)) {
        return 1;
    }

    return 0;
}

/* ========================= GRAPHS ========================= */

a_graph create_graph() {
    a_graph new_graph = (a_graph) malloc(sizeof(t_graph));
    new_graph->size_graph = 0;

    return new_graph;
}

int is_empty_graph(a_graph graph) {
    return graph == NULL;
}

int size_graph(a_graph graph) {
    return graph->size_graph;
}

int add_node(a_graph graph, a_node node) {
    if (is_empty_graph(graph) | is_empty_node(node)) {
        printf("Cannot perform operation with empty values.\n");
        return -1;
    }

    int nb_of_nodes = size_graph(graph);

    if (nb_of_nodes == 0) {
        graph->nodes = (a_node*) malloc(sizeof(a_node));
        graph->nodes[0] = node;
        graph->size_graph++;
    } else {
        graph->nodes = (a_node*) realloc(graph->nodes, sizeof(a_node) * (nb_of_nodes + 1));
        graph->nodes[nb_of_nodes] = node;
        graph->size_graph++;
    }

    return 1;
}


int print_graph(a_graph graph) {
    if (is_empty_graph(graph)) {
        printf("Cannot print empty graph.\n");
        return -1;
    }

    if (size_graph(graph) == 0) {
        printf("This graph does not contain any node\n");
    } else {
        for (int i=0; i<size_graph(graph); i++) {
            print_node(graph->nodes[i]);
        }
    }

    return 1;
}

a_graph create_random_graph(int nb_nodes, int max_edges) {
    a_graph random_graph = create_graph();

    // Create all the nodes inside the graph
    for (int i=0; i<nb_nodes; i++) {
        add_node(random_graph, create_node(i));
    }

    // Init the random generator
    srand(time(NULL));

    // For each node, chose a random number of connexions
    for (int i=0; i<nb_nodes; i++) {
        a_node current_node = random_graph->nodes[i];
        int nb_of_connexions = rand() % max_edges;

        // Create nb_of_connexions random connections
        for (int i=0; i<nb_of_connexions; i++) {
            // While the random_node is either the current_node, or already connected, or already have a max number of connections
            int random_index;
            a_node random_node_to_connect;

            do {
                random_index = rand() % nb_nodes;
                random_node_to_connect = random_graph->nodes[random_index];
            } while ((current_node == random_node_to_connect) | are_connected_together(current_node, random_node_to_connect) | (number_of_edges(random_node_to_connect) >= max_edges) );

            // The node can be added
            connect_nodes_between(current_node, random_node_to_connect);
        }

    }

    return random_graph;
}

int is_node_in_graph(a_node node, a_graph graph) {
    if (is_empty_node(node) | is_empty_graph(graph)) {
        printf("Cannot perform action with NULL values.\n");
        return -1;
    }

    for (int i=0; i<size_graph(graph) - 1; i++) {
        if (node->index == graph->nodes[i]->index) {
            return 1;
        }
    }

    return 0;
}

a_node find_node_by_index(int node, a_graph graph) {
    if (is_empty_graph(graph)) {
        printf("Cannot perform action with NULL values.\n");
        return NULL;
    }

    // printf("Loooking for node %i\n", node);

    for (int i=0; i<size_graph(graph); i++) {
        if (node == graph->nodes[i]->index) {
            return graph->nodes[i];
        }
    }

    printf("Node %i not foundt\n", node);
    return NULL;
}

a_graph one_connexion_graph(a_graph graph) {
    if (is_empty_graph(graph)) {
        printf("Cannot perform action with NULL graph.\n");
        return NULL;
    }

    a_graph oc_graph = graph;

    for (int n=0; n<size_graph(oc_graph); n++) {
        a_node current_node = oc_graph->nodes[n];
        for (int e=0; e<number_of_edges(current_node); e++) {
            a_node current_edge = current_node->edges[e];

            // Si la connexion est double:
            if (are_connected_together(current_node, current_edge)) {
                // Supprimer la connexion dans le noeud connecté
                delete_connection(current_node, current_edge);
            }
        }
    }

    return oc_graph;
}