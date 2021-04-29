#include "p_graph_test.h"

/* ========================= NODES ========================= */

a_node create_node(int index) {
    a_node new_node = (a_node) malloc(sizeof(t_node));
    new_node->index = index;
    new_node->nb_of_connections = 0;

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

    printf("Node : %i\n", node->index);
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

int connect_nodes_between(a_node node1, a_node node2) {
    if (is_empty_node(node1) | is_empty_node(node2)) {
        printf("Cannot connect empty nodes.");
        return 0;
    }

    connect_node_to(node1, node2);
    connect_node_to(node2, node1);

    // if (connect_node_to(node1, node2) && connect_node_to(node2, node1)) {
    //     return 1;
    // }

    return 1;
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