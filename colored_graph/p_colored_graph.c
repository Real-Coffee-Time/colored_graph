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

int is_color_in_list(color col, a_coloring colors) {
    if (is_null_colors_list(colors)) {
        printf("Cannot perform this action with null colors list.\n");
        return -1;
    }

    for (int i=0; i<colors->nb_colors; i++) {
        if (col == colors->colors[i]) {
            return 1;
        }
    }

    return 0;
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

int add_color_to_list(color col, a_coloring colors) {
    if (is_null_colors_list(colors)) {
        printf("Cannot print colors list with null values.\n");
        return -1;
    }

    int nb_c = nb_colors(colors);

    if (is_empty_colors_list(colors)) {
        colors->colors = (color*) malloc(sizeof(color));
        colors->colors[0] = col;
        colors->nb_colors++;

        return colors->colors[0];

    } else {
        colors->colors = (color*) realloc(colors->colors, sizeof(color) * (nb_c + 1));
        colors->colors[nb_c] = col;
        colors->nb_colors++;

        return colors->colors[nb_c];
    }

    return 1;
    
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

color get_random_color(a_coloring colors) {
    if (is_null_colors_list(colors)) {
        printf("Cannot print colors list with null values.\n");
        return -1;
    }

    int random_index = rand() % ((colors->nb_colors+1)-0) + 0;
    // printf("%d\n",random_index);

    return colors->colors[random_index];
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

int color_random(a_graph graph) {
    if (is_empty_graph(graph)) {
        printf("Cannot perform this action with null graph.\n");
        return -1;
    }
    graph->colors = init_colors();
    a_coloring cl = init_colors();

    for (int i=1; i<=graph->size_graph; i++) {
        create_new_color(cl);
    }

    for (int i=0; i<size_graph(graph); i++) {
        color c = get_random_color(cl);
        assign_color_to_node(c, graph->nodes[i]);

        if (!is_color_in_list(c, graph->colors)) {
            add_color_to_list(c, graph->colors);
        }
    }

    return 1;
}

/* ========================== LOCAL_SEARCH ========================== */

a_constraint create_constraints(color col, int nb_constraint, a_node node) {
    a_constraint new_constraint = malloc(sizeof(t_constraint));
    new_constraint->col = col;
    new_constraint->nb_constraint = nb_constraint;
    new_constraint->node = node;

    return new_constraint;
}

a_constraint get_node_best_constraint(a_node node, a_coloring colors) {
    if (is_empty_node(node)) {
        printf("Cannot check empty node.\n");
        return NULL;
    }

    color new_color = create_new_color(colors);
    printf("NEw color : %i\n", new_color);
    list_constraints node_constraints = (list_constraints) malloc(sizeof(a_constraint) * colors->nb_colors);

    for (int i=0; i<colors->nb_colors; i++) {
        int constraint = 0;

        color current_color = colors->colors[i];


        for (int e=0; e<node->nb_of_connections; e++) {

            a_node current_node = node->edges[e];

            // printf("Comparing %i with color %i\n", node->index, current_node->node_color);

            if (current_color == node_color(current_node) && node_color(node) != node_color(current_node)) {
                printf("%i has color %i, it would not help\n", current_node->index, current_color);
                constraint++;

            } else if (current_color != node_color(current_node) && node_color(node) == node_color(current_node)) {
                printf("As %i has the same color, it would help to change\n", current_node->index);
                constraint--;
            } else if (current_color == new_color) {
                constraint++;
            }
        }
        a_constraint c = create_constraints(current_color, constraint, node);
        node_constraints[i] = c;


        // return 1; 

    }
    a_constraint best_constraint = NULL;

    for (int i=0; i<colors->nb_colors; i++) {
        printf("%d %d\n", node_constraints[i]->col, node_constraints[i]->nb_constraint);
        if (best_constraint == NULL) {
            best_constraint = node_constraints[i];
        } else if (node_constraints[i]->nb_constraint < best_constraint->nb_constraint) {
            best_constraint = node_constraints[i];
        }
    }

    printf("The best constraint for this node is %d %d\n", best_constraint->col, best_constraint->nb_constraint);

    return best_constraint;
}

int color_graph_local_search(a_graph graph) {
    if (is_empty_graph(graph) || is_null_colors_list(graph->colors)) {
        printf("Cannot perform this action with null graph.\n");
        return -1;
    }

    // For each node
        // Look for the constraints

        // Keep the best constraints

    // For each node
        // Keep the constraints

        // Compare with the current_constraints

    // Change 

    return 1;
}