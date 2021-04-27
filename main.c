#include <stdlib.h>
#include <stdio.h>
#include "graph/p_graph.h"

int main(int argc, char** argv) {
    printf("Hello World !\n");

    a_node new_node = create_node(0);
    a_node new_node1 = create_node(1);
    a_node new_node2 = create_node(2);

    // new_node->edge[0] = new_node1;
    // new_node->edge[1] = new_node2;

    connect_nodes(new_node1, new_node2);
    connect_nodes(new_node, new_node1);

    // print_node(new_node);
    // print_node(new_node1);

    t_graph new_graph = create_graph(3);
    add_node(new_graph, new_node);
    add_node(new_graph, new_node1);
    add_node(new_graph, new_node2);

    print_graph(new_graph);
    
    return 0;
}