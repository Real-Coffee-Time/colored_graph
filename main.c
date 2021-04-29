#include <stdlib.h>
#include <stdio.h>
#include "graph_test/p_graph_test.h"
#include "parser/p_parser.h"

int main(int argc, char** argv) {

    printf("Hello World !\n");

    /* ========================= NODES ========================= */

    a_node test_node = create_node(51);

    for (int i=1; i<10; i++) {
        connect_nodes_between(test_node, create_node(i));
    }

    // print_node(node);

    /* ========================= GRAPHS ========================= */

    a_graph graph = create_random_graph(50, 5);

    // print_graph(graph);

    printf("Test de présence pour le node %i : %i\n", test_node->index, is_node_in_graph(test_node, graph));

    return 0;
}