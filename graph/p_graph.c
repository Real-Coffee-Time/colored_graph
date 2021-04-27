#include "p_graph.h"

a_node create_node(int index) {
    a_node new_node = (a_node) malloc(sizeof(t_node));
    new_node->index = index;
    new_node->neighbour = 0;

    return new_node;

} // end of create_node(...)


void print_node(a_node node) {
    printf("Node index : %i\n", node->index);

    if (node->neighbour == 0) {
        printf("\tThis node is connected to no other node\n");

    } else {
        int index = 0;

        while (node->edge[index] != NULL) {
            printf("\t%i \n", (node->edge[index])->index);
            index++;

        }
    }
} // end of print_node(...)

int connect_nodes(a_node node1, a_node node2) {

    node1->edge[node1->neighbour] = node2;
    node1->neighbour ++ ;

    node2->edge[node2->neighbour] = node1;
    node2->neighbour ++ ;

    return 1;

} // end of connect_nodes(...)

int is_entry(a_node node) {

    // Uniquement dans un graph orienté

    return 0;

} // end of is_entry(...)

int is_endpoint(t_node node) {

    // Uniquement dans un graph orienté

    return 0;

} // end of is_endpoint(...)

int node_in_graph(a_node node, t_graph graph) {

    int index = 0;

    while (graph[index] != NULL) {

        if (graph[index] == node) {
            return 1;
        }

        index++;
    }
    
    return 0;

} // end of node_in_graph(...)

/* ========================= GRAPHS ========================= */

t_graph create_graph(int size_graph) {

    t_graph new_graph = malloc(sizeof(t_node)*size_graph);

    return new_graph;

} // end of create_graph(...)

int add_node(t_graph graph, a_node node) {

    int index = 0;

    while (graph[index] != NULL) {

        index++;

    }

    graph[index] = node;

    return 1;
} // end of add_node(...)

void print_graph(t_graph graph) {

    int index = 0;

    while (graph[index]) {

        print_node(graph[index]);
        index++;

    }

} // end of print_graph(...)