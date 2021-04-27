#include "p_parser.h"

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


int parse_file(char* file_name) {
    FILE* file = init_file(file_name);
    if (file == NULL_FILE) {
        printf("Cannot print null file\n");
        return 0;
    }

    char line[LINE_MAX_SIZE];

    // Read line by line (to change to char by char)
    while (fgets(line, LINE_MAX_SIZE, file) != NULL){
        // Indentification of the init line
        is_init_line(line);

        // Identification of the edges line
        is_edge_line(line);
    }

    fclose(file);
    return 1;
}