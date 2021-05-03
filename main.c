#include <stdlib.h>
#include <stdio.h>
#include "graph/p_graph.h"
#include "parser/p_parser.h"
#include "colored_graph/p_colored_graph.h"

int main(int argc, char** argv) {

    // printf("Hello World !\n");

    /* ========================= NODES ========================= */

    a_node node1 = create_node(1);
    a_node node2 = create_node(2);
    a_node node3 = create_node(3);
    a_node node4 = create_node(4);
    a_node node5 = create_node(5);
    a_node node6 = create_node(6);
    a_node node7 = create_node(7);

    connect_nodes_between(node1, node2);
    connect_nodes_between(node1, node7);
    connect_nodes_between(node1, node4);
    connect_nodes_between(node2, node3);
    connect_nodes_between(node2, node5);
    connect_nodes_between(node3, node5);
    connect_nodes_between(node3, node6);
    connect_nodes_between(node4, node6);
    connect_nodes_between(node5, node7);
    connect_nodes_between(node6, node7);


    /* ========================= GRAPHS ========================= */

    a_graph graph = create_graph();

    add_node(graph, node1);
    add_node(graph, node2);
    add_node(graph, node3);
    add_node(graph, node4);
    add_node(graph, node5);
    add_node(graph, node6);
    add_node(graph, node7);

    // print_graph(graph);

    /* ========================= COLORS ========================= */

    color_graph(graph);

    print_graph(graph);


    return 0;
}