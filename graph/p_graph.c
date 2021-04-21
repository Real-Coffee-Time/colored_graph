#include "p_graph.h"

a_node create_node(int index) {
    a_node new_node = (a_node) malloc(sizeof(t_node));
    new_node->index = index;

    return new_node;

} // end of create_node(...)


void print_node(a_node node) {
    printf("Node index : %i\n", node->index);

    if (node->edge == NULL) {
        printf("\tThis node is connected to no other node\n");

    } else {
        int index = 0;

        while (node->edge[index] != NULL) {
            printf("\t%i", node->edge[index]->index);
            index++;

        }
    }
} // end of print_node(...)