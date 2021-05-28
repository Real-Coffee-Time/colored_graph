#ifndef P_GRAPH_H
#define P_GRAPH_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

// #include "../colored_graph/p_colored_graph.h"

/**
 * --------------------- PARSER ---------------------
 * 
 * @author Anatole de Chauveron, Adrien Ducourthial
 * 
 * @date 21/04/2021
 * 
 * Module that creates, updates and evaluates graphs
*/

#define COLOR_NULL -1
typedef int color;


/**
 * @param int index : The index of the node
 * @param s_node** edge : All connected nodes
*/
typedef struct s_node {
    int index;
    int nb_of_connections;
    color node_color;
    struct s_node** edges;
} t_node;

typedef t_node* a_node;

typedef struct s_coloring {
    color* colors;
    int nb_colors;
} t_coloring;

typedef t_coloring* a_coloring;

typedef struct s_graph {
    a_node* nodes;
    int size_graph;
    a_coloring colors;
} t_graph;

typedef t_graph* a_graph;


/* ========================= NODES ========================= */

/**
 * Create a new node
 * 
 * @param int index : The color index (order of creation)
 * 
 * @return a_node : The new node
*/
a_node create_node(int index);

/**
 * Count the number of connections of a node.
 * @param a_node node : The node to check
 * @return the number of connection
*/
int number_of_edges(a_node node);

/**
 * Connects a node to another
 * 
 * @param a_node node1 : The node to connect
 * @param a_node node2 : The node to connect to
 * 
 * @return int : 1 if the two nodes are connected, 0 if an error occured
*/
int connect_node_to(a_node node1, a_node node2);


/**
 * Connects to nodes between each other
 * @param a_node node1 : the first node to connect
 * @param a_node node2 : the second node to connect
 * 
 * @return int : 1 if the two nodes are connected, 0 if an error occured
*/
int connect_nodes_between(a_node node1, a_node node2);

/**
 * Print the content of a node
 * 
 * @param t_node node : The node to print
 * @return int : 1 if ok, 0 if an error occured.
*/
int print_node(a_node node);

/**
 * Check if a node is empty.
 * @param a_node: The node to check.
 * @return int: 1 if empty, 0 if not.
*/
int is_empty_node(a_node node);

/**
 * Check if a node edges are null.
 * @param a_node: The node to check.
 * @return int: 1 if empty, 0 if not.
*/
int is_empty_edges(a_node node);

/**
 * Print a node's edges.
 * @param a_node node : The node to print the edges.
 * @return int: 1 if printed, 0 if an error occured
*/
int print_edges(a_node node);

/**
 * Check if a node is connected to an other
 * @param a_node node1: The node to check
 * @param a_node node2: The node to explore
 * @return int : 1 if connected, 0 if not, -1 if an error occured
*/
int is_connected_to(a_node node1, a_node node2);

/**
 * Check if two nodes are connected together
 * @param a_node node1: The first node to explore
 * @param a_node node2: The second node to explore
 * @return int : 1 if connected, 0 if not, -1 if an error occured
*/
int are_connected_together(a_node node1, a_node node2);

/**
 * Check if no node is connected to the current node
 * 
 * @param t_node node : The node to check
 * 
 * @return int : 1 if the node is an entry, 0 if not
*/
int is_entry(a_node node);

/**
 * Check if the node is connected to no other
 * 
 * @param t_node node : The node to check
 * 
 * @return int : 1 if the node is an endpoint, 0 if not
*/
int is_endpoint(t_node node);

/**
 * Delete a connection between two nodes
 * 
 * @param a_node node1 : the first node
 * @param a_node node2 : the second node
 * 
 * @return int : 1 if the connection is deleted, 0 if not
*/
int delete_connection(a_node node1, a_node node2);


/* ========================= GRAPHS ========================= */

/**
 * Initialize an empty graph
 * 
 * @return t_graph : The new empty graph
*/
a_graph create_graph();

/**
 * Check if a graph is empty.
 * @param a_graph: The graph to check.
 * @return int: 1 if empty, 0 if not.
*/
int is_empty_graph(a_graph graph);

/**
 * Returns the size of a graph
 * 
 * @param a_graph: the graph to check.
 * @return int : -1 if an error occured, positive int
*/
int size_graph(a_graph graph);

/**
 * Add a node to the graph. All the connected nodes will also be added to the graph.
 * 
 * @param t_graph graph : The graph to be modified
 * @param a_node node : The node to add to the graph
 * 
 * @return int : 1 if the node was added, 0 if a problem occured
*/
int add_node(a_graph graph, a_node node);

/**
 * Print a graph
 * 
 * @param t_graph graph : The graph to print
*/
int print_graph(a_graph graph);


/**
 * Returns a random graph
 * 
 * @param int nb_nodes: The number of nodes in the graph
 * @param int max_edges: The maximum number of edges per node
 * 
 * @return a_graph: the new graph
*/
a_graph create_random_graph(int nb_nodes, int max_edges);


/**
 * Check if a node is inside a graph
 * 
 * @param t_node node : The node to be checked
 * @param t_graph graph : The graph to check
 * 
 * @return int : 1 if the node is inside, 0 if not
*/
int is_node_in_graph(a_node node, a_graph graph);

/**
 * Get a node by his index
 * 
 * @param int node : the node's index
 * @param a_graph graph : the graph to check
 * 
 * @return int : 1 if the node is found, 0 if not
*/
a_node find_node_by_index(int node, a_graph graph);

/**
 * Return a new graph where all nodes are only connected once between each other
*/
a_graph one_connexion_graph(a_graph graph);

#endif