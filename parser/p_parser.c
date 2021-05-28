#include "p_parser.h"
#include "../colored_graph/p_colored_graph.h"

FILE* init_file(char* file_name) {
    FILE* file_to_open = fopen(file_name, "r");

    if (file_to_open != NULL_FILE) {
        printf("File %s opened with success\n", file_name);
        return file_to_open;
    }

    printf("An error occured while opening file %s\n", file_name);
    return NULL_FILE;
}


int print_file(char* file_name) {
    FILE* file = init_file(file_name);
    if (file == NULL_FILE) {
        printf("Cannot print null file\n");
        return 0;
    }

    char line[LINE_MAX_SIZE];

    // Read line by line (to change to char by char)
    while (fgets(line, LINE_MAX_SIZE, file) != NULL){
        printf("%s", line);
    }

    // Close the file
    fclose(file);
    return 1;
}

int is_init_line(char* line) {
    regex_t preg;
    const char* regex = "p edge [0-9]+ [0-9]+\n";
    int err = regcomp (&preg, regex, REG_NOSUB | REG_EXTENDED);

    if (err == 0) {
        int match = regexec (&preg, line, 0, NULL, 0);

        regfree (&preg);
        if (match == 0)
        {
            printf ("Init line identified : %s\n", line);
            return 1;
        }
    }

    return 0;    
}


int is_edge_line(char* line) {
    regex_t preg;
    const char* regex = "^e{1} [0-9]+ [0-9]+\n";
    int err = regcomp (&preg, regex, REG_NOSUB | REG_EXTENDED);

    if (err == 0) {
        int match = regexec (&preg, line, 0, NULL, 0);

        regfree (&preg);
        if (match == 0)
        {
            printf ("Edge identified : %s\n", line);
            return 1;
        }
    }

    return 0;   
}


a_graph graph_from_file(char* file_name) {

    FILE* file = init_file(file_name);

    if (file == NULL_FILE) {
        printf("Cannot print null file\n");
        return NULL;
    }

    char line[LINE_MAX_SIZE];
    int nb_nodes, nb_edges = 0;

    a_graph graph = create_graph();

    while (fgets(line, LINE_MAX_SIZE, file) != NULL) {
        sscanf(line, "p edge %d %d", &nb_nodes, &nb_edges);

        for (int i=1; i<=nb_nodes; i++) {
            add_node(graph, create_node(i));
        }

        if (nb_nodes != 0) {
            break;
        }
        
    }

    // print_graph(graph);

    rewind(file);

    int node, edge;

    while (fgets(line, LINE_MAX_SIZE, file) != NULL) {
        sscanf(line, "e %d %d", &node, &edge);

        if (node != 0) {
            // printf("%d %d\n", node, edge);

            a_node current_node = find_node_by_index(node, graph);
            a_node connection = find_node_by_index(edge, graph);

            if (is_empty_node(current_node) || is_empty_node(connection)) {
                return NULL;
            }
            
            if(!are_connected_together(current_node, connection)) {
                connect_nodes_between(current_node, connection);
            }
        }
        
    }

    // print_graph(graph);


    fclose(file);
    return graph;
}