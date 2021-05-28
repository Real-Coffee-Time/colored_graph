#ifndef P_PARSER_H
#define P_PARSER_H

#include <stdlib.h>
#include <stdio.h>
#include <regex.h>
#include <ctype.h>

#include "../graph/p_graph.h"

#define LINE_MAX_SIZE 250
#define NULL_FILE NULL

/**
 * --------------------- PARSER ---------------------
 * 
 * @author Anatole de Chauveron, Adrien Ducourthial
 * 
 * Function to parse a file
*/

/**
 * Loads a file
 * @param char$ file_name : The name of the file to parse
 * @return The file if everything was correct, NULL_FILE if nothing 
 *  
*/
FILE* init_file(char* file_name);

/**
 * Print the content of a file
 * @param FILE* file : The file to print.
 * @return 1 if the file was printed, 0 if an error occured
*/
int print_file(char* file_name);

/**
 * Check if the current line is the init line that contains all the graph informations
 * @param char* line: The line to examin
 * @return int : 1 if the informations where foundt, 0 if an error occured
*/
int is_init_line(char* line);

/**
 * Check if the tested line is an edge line (with node connections informations)
 * @param char* line : The line to examin
 * @return int : 1 if the informations where foundt, 0 if an error occured
*/
int is_edge_line(char* line);

/**
 * Function parse the content of a file.
 * @param FILE* file_name: The file to parse
 * @returns Int : 1 if parse was executed without problem, 0 if an error occured while parsing the file
*/
a_graph graph_from_file(char* file_name);

/***/
int* decode_line(char* line);

#endif