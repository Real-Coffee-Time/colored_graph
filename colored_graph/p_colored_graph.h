#ifndef P_COLORED_GRAPH_H
#define P_COLORED_GRAPH_H

#include "../graph/p_graph.h"

/* ========================= COLORED_NODES ========================= */

/***/
a_coloring init_colors();

/***/
int nb_colors(a_coloring colors);

/***/
int is_null_colors_list(a_coloring colors);

/***/
int is_empty_colors_list(a_coloring colors);

/***/
int create_new_color(a_coloring colors);

/***/
int is_not_colored(a_node node);

/***/
color node_color(a_node node);

/***/
int assign_color_to_node(color color, a_node node);

/***/
int print_colors_list(a_coloring colors);

/* ========================= COLORED_GRAPH ========================= */

/***/
int is_colored_graph(a_graph graph);

/***/
int color_graph(a_graph graph);


#endif // P_COLORED_GRAPH_H
