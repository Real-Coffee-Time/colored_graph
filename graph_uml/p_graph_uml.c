#include "p_graph_uml.h"

FILE* create_file(char* file_name) {
    FILE* new_file = fopen(file_name, "w");
    if (new_file != NULL) {
        return new_file;
    }
    return NULL;
}

int write_line(FILE* file, char* text) {
    if (file == NULL) {
        printf("Cannot write line in NULL file.\n");
        return -1;
    }

    fputs(text, file);

    return 1;
}

int pass_line(FILE* file) {
    if (write_line(file, "\n")) {
        return 1;
    }

    return 0;
}

int export_graph_to_uml(a_graph graph) {
    if (is_empty_graph(graph)) {
        printf("Cannot perform action with empty graph\n.");
        return -1;
    }

    // Create file

    FILE* export_file = create_file("test_export_graph.puml");
    if (export_file == NULL) {
        printf("An error occured while creating the export file.\n");
        return -1;
    }

    // Write the header of the file
    write_line(export_file, "@startuml graph_export\n");
    pass_line(export_file);

    write_line(export_file, "\tleft to right direction\n");
    pass_line(export_file);

    // Write the graph in the file

    // Color array

    char* color_array[] = {"green", "red", "blue", "yellow", "purple", "pink"};

    // For every node in the graph initialize value in puml file
    for (int n=0; n<size_graph(graph); n++) {
        a_node current_node = graph->nodes[n];
        if (current_node->node_color != -1) {
            fprintf(export_file, "\t(%i) as %i#%s\n", current_node->node_color, current_node->index, color_array[current_node->node_color]);
        } else {
            fprintf(export_file, "\t(%i) as %i\n", current_node->index, current_node->index);
        }
    }

    // Recreate a one_connexion graph
    a_graph temp_graph = one_connexion_graph(graph);

    pass_line(export_file);


    // For each node write edges
    for (int i=0; i<size_graph(temp_graph); i++) {
        a_node current_node = temp_graph->nodes[i];
        for (int e=0; e<number_of_edges(current_node); e++) {
            fprintf(export_file, "\t%i == %i\n", current_node->index, current_node->edges[e]->index);
        }
    }

    pass_line(export_file);

    // Write the footer of the file
    write_line(export_file, "@enduml");

    // Fermeture du fichier
    fclose(export_file);

    return 1;
}