#include "p_colored_graph.h"

a_coloring init_colors() {
    a_coloring new_colors_list = (a_coloring) malloc(sizeof(t_coloring));
    new_colors_list->nb_colors = 0;

    return new_colors_list;
}

int is_null_colors_list(a_coloring colors) {
    return colors == NULL;
}

int is_empty_colors_list(a_coloring colors) {
    if (is_null_colors_list(colors)) {
        printf("Cannot perform this action with empty colors list.\n");
        return -1;
    }

    return colors->nb_colors == 0;
}

int nb_colors(a_coloring colors) {
    if (is_null_colors_list(colors)) {
        printf("Cannot perform this action with empty colors list.\n");
        return -1;
    }

    return colors->nb_colors;
}

int is_not_colored(a_node node) {
    if (is_empty_node(node)) {
        printf("Cannot check empty node.\n");
        return -1;
    }

    return node->node_color == COLOR_NULL;
}

color node_color(a_node node) {
    if (is_not_colored(node)) {
        return COLOR_NULL;
    }

    return node->node_color;
}

int create_new_color(a_coloring colors) {
    if (is_null_colors_list(colors)) {
        printf("Cannot perform this action with null colors list.\n");
        return -1;
    }

    int nb_c = nb_colors(colors);

    if (is_empty_colors_list(colors)) {
        colors->colors = (color*) malloc(sizeof(color));
        colors->colors[0] = 0;
        colors->nb_colors++;

        return colors->colors[0];

    } else {
        colors->colors = (color*) realloc(colors->colors, sizeof(color) * (nb_c + 1));
        colors->colors[nb_c] = nb_c;
        colors->nb_colors++;

        return colors->colors[nb_c];
    }

    return 0;
}

int print_colors_list(a_coloring colors) {
    if (is_null_colors_list(colors)) {
        printf("Cannot print colors list with null values.\n");
        return -1;
    }

    if (is_empty_colors_list(colors)) {
        printf("This list does not contain any colors\n");
    } else {
        printf("Colors inside list :\n");
        for (int i=0; i<nb_colors(colors); i++) {
            printf("\t%i\n", colors->colors[i]);
        }
    }

    return 0;
}

int assign_color_to_node(color color, a_node node) {
    if (is_empty_node(node) | (color == COLOR_NULL)) {
        printf("Cannot perform action with empty values.\n");
        return -1;
    }

    if (!is_not_colored(node)) {
        printf("Node already colored (%i).\n", node->node_color);
        return 0;
    }

    node->node_color = color;
    return 1;
}

int color_graph(a_graph graph) {
    if (is_empty_graph(graph)) {
        printf("Cannot perform this action with null graph.\n");
        return -1;
    }

    // Initialize graph colors
    graph->colors = init_colors();

    // For each node
    for (int i=0; i<size_graph(graph); i++) {
        a_node current_node = graph->nodes[i];

        // For each color
        for (int c=0; c<nb_colors(graph->colors); c++) {
            color current_color = graph->colors->colors[c];

            // Check if a connected node is using this color
            int is_color_used = 0;

            // For each edge check the color
            for (int e=0; e<number_of_edges(current_node); e++) {
                if (current_node->edges[e]->node_color == current_color) {
                    is_color_used += 1;
                }
            } 

            // If it does not
            if (is_color_used == 0) {
                // Assign the color to the node
                assign_color_to_node(current_color, current_node);
                break;
            }
        }

        // When reached if no color assigned
        if (is_not_colored(current_node)) {
            // Create new color and assign
            color new_color = create_new_color(graph->colors);
            assign_color_to_node(new_color, current_node);
        }
    }

    return 1;

}