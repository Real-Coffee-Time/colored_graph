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
int is_color_in_list(color col, a_coloring colors);

/***/
int create_new_color(a_coloring colors);

/***/
int is_not_colored(a_node node);

/***/
color node_color(a_node node);

/***/
int add_color_to_list(color col, a_coloring colors);

/***/
int assign_color_to_node(color color, a_node node);

/***/
int print_colors_list(a_coloring colors);

/***/
color get_random_color(a_coloring colors);

/* ========================= COLORED_GRAPH ========================= */

/***/
int is_colored_graph(a_graph graph);

/***/
int color_graph(a_graph graph);

/***/
int color_random(a_graph graph);

/* ========================== LOCAL_SEARCH ========================== */

typedef struct s_constraint {
    color col;
    int nb_constraint;
    a_node node;
} t_constraint;

typedef t_constraint* a_constraint;
typedef a_constraint* list_constraints;

/***/
a_constraint create_constraints(color col, int nb_constraint, a_node node);

/***/
a_constraint get_node_best_constraint(a_node node, a_coloring colors);

/***/
int make_graph_best_update(a_graph node);

/***/
int color_graph_local_search(a_graph graph);


#endif // P_COLORED_GRAPH_H
