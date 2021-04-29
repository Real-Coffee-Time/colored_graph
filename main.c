#include <stdlib.h>
#include <stdio.h>
#include "graph_test/p_graph_test.h"
#include "parser/p_parser.h"

int main(int argc, char** argv) {

    printf("Hello World !\n");

    /* ========================= NODES ========================= */

    a_node test_node = create_node(0);

    for (int i=1; i<10; i++) {
        connect_nodes_between(test_node, create_node(i));
    }

    // print_node(node);

    /* ========================= GRAPHS ========================= */

    a_graph graph = create_graph();

    a_node node = create_node(0);
    a_node node1 = create_node(1);
    a_node node2 = create_node(2);
    a_node node3 = create_node(3);
    a_node node4 = create_node(4);

    connect_nodes_between(node, node1);
    connect_nodes_between(node, node3);
    connect_nodes_between(node, node4);
    connect_nodes_between(node3, node4);
    connect_nodes_between(node1, node2);

    add_node(graph, node);
    add_node(graph, node1);
    add_node(graph, node2);
    add_node(graph, node3);
    add_node(graph, node4);
    
    print_graph(graph);

    return 0;
}