#include <stdlib.h>
#include <stdio.h>
#include "graph/p_graph.h"
#include "parser/p_parser.h"

int main(int argc, char** argv) {

    // printf("Hello World !\n");

    /* ========================= NODES ========================= */

    a_node test_node = create_node(24);

    for (int i=1; i<10; i++) {
        connect_nodes_between(test_node, create_node(i));
    }

    // print_node(node);

    /* ========================= GRAPHS ========================= */

    a_graph graph = create_random_graph(50, 5);

    print_graph(graph);

    return 0;
}