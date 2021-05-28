#include <stdlib.h>
#include <stdio.h>

#include "graph/p_graph.h"
#include "parser/p_parser.h"
#include "colored_graph/p_colored_graph.h"
#include "graph_uml/p_graph_uml.h"

int main(int argc, char** argv) {
    srand(time(NULL));

    // printf("Hello World !\n");

    /* ========================= NODES ========================= */

    a_node node1 = create_node(1);
    a_node node2 = create_node(2);
    a_node node3 = create_node(3);
    a_node node4 = create_node(4);
    a_node node5 = create_node(5);

    connect_nodes_between(node1, node2);
    connect_nodes_between(node1, node3);
    connect_nodes_between(node2, node4);
    connect_nodes_between(node2, node5);
    connect_nodes_between(node4, node3);
    connect_nodes_between(node3, node5);

    /* ========================= GRAPHS ========================= */

    // a_graph graph = create_random_graph(25, 5);
    a_graph graph = create_graph();

    add_node(graph, node1);
    add_node(graph, node2);
    add_node(graph, node3);
    add_node(graph, node4);
    add_node(graph, node5);

    // print_graph(graph);

    // color_graph(graph);

    /* ========================= COLORS ========================= */

    // printf("\n\n\n");

    // print_graph(graph);
    color_random(graph);
    print_graph(graph);
    get_node_best_constraint(node1, graph->colors);

    /* ========================== UML ========================== */

    export_graph_to_uml(graph);

    /* ========================= PARSER ========================= */

    // a_graph g = graph_from_file("assets/1-FullIns_3.col");
    // a_graph g = graph_from_file("assets/zeroin.i.3.col");

    // print_graph(g);

    // export_graph_to_uml(g);


    return 0;
}