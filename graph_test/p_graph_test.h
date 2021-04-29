#ifndef P_GRAPH_TEST_H
#define P_GRAPH_TEST_H

#include <stdlib.h>
#include <stdio.h>

/**
 * --------------------- PARSER ---------------------
 * 
 * @author Anatole de Chauveron, Adrien Ducourthial
 * 
 * @date 21/04/2021
 * 
 * Module that creates, updates and evaluates graphs
*/


typedef struct s_coloring {
    int* color;
} t_coloring;


/**
 * @param int index : The index of the node
 * @param s_node** edge : All connected nodes
*/
typedef struct s_node {
    int index;
    int nb_of_connections;
    struct s_node** edges;
} t_node;

typedef t_node* a_node;


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


/* ========================= GRAPHS ========================= */

typedef struct s_graph {
    a_node* nodes;
    int size_graph;
} t_graph;

typedef t_graph* a_graph;

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
 * Check if a node is inside a graph
 * 
 * @param t_node node : The node to be checked
 * @param t_graph graph : The graph to check
 * 
 * @return int : 1 if the node is inside, 0 if not
*/
int node_in_graph(a_node node, a_graph graph);

#endif