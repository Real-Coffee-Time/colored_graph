#ifndef P_GRAPH_H
#define P_GRAPH_H

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
    // char* label;
    int index;
    struct s_node** edge;
} t_node;

typedef t_node* a_node;
typedef a_node* t_graph;


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
 * Connects to node between each other
 * 
 * @param a_node node1 : The first node to connect
 * @param a_node node2 : The second node to connect
 * 
 * @return int : 1 if the two nodes are connected, 0 if an error occured
*/
int connect_nodes(a_node node1, a_node node2);

/**
 * Print the content of a node
 * 
 * @param t_node node : The node to print
*/
void print_node(a_node node);

/**
 * Check if no node is connected to the current node
 * 
 * @param t_node node : The node to check
 * 
 * @return int : 1 if the node is an entry, 0 if not
*/
int is_entry(t_node node);

/**
 * Check if the node is connected to no other
 * 
 * @param t_node node : The node to check
 * 
 * @return int : 1 if the node is an endpoint, 0 if not
*/
int is_endpoint(t_node node);

/**
 * Check if a node is inside a graph
 * 
 * @param t_node node : The node to be checked
 * @param t_graph graph : The graph to check
 * 
 * @return int : 1 if the node is inside, 0 if not
*/
int node_in_graph(t_node node, t_graph graph);


/* ========================= GRAPHS ========================= */

/**
 * Initialize an empty graph
 * 
 * @param int size_graph : The size of the graph
 * 
 * @return t_graph : The new empty graph
*/
t_graph create_graph(int size_graph);

/**
 * Add a node to the graph. All the connected nodes will also be added to the graph.
 * 
 * @param t_graph graph : The graph to be modified
 * @param a_node node : The node to add to the graph
 * 
 * @return int : 1 if the node was added, 0 if a problem occured
*/
int add_node(t_graph graph, a_node node);

/**
 * Print a graph
 * 
 * @param t_graph graph : The graph to print
*/
void print_graph(t_graph graph);

#endif