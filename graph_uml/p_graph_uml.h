#ifndef P_GRAPH_UML
#define P_GRAPH_UML

#include <stdlib.h>
#include <stdio.h>

#include "../colored_graph/p_colored_graph.h"


/***/
FILE* create_file(char* file_name);

/***/
int write_line(FILE* file, char* text);

/***/
int write_header(FILE* file);

/***/
int export_graph_to_uml(a_graph graph);

#endif