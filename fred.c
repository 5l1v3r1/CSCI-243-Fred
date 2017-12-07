/// file: fred.c
/// description: implementation of interpreter for Fred Language
/// author: Duc Phan - ddp3945@rit.edu

#define _BSD_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include "utils.h"

int main(int argc, char **argv) {
    char *symtabFile = NULL;
    char *programFile = NULL;
    int opt;

    if (argc > 1) {
        if (argc != 3 && argc != 5) {
            fprintf(stderr, "fred  [ -s symbol_table_file ] [ -f program_file ]\n");
            return EXIT_FAILURE;
        }
        opterr = 0;
        while ((opt = getopt(argc, argv, "s:f:")) != -1) {
            switch (opt) {
                case 's':
                    if (symtabFile != NULL) {
                        fprintf(stderr, "fred  [ -s symbol_table_file ] [ -f program_file ]\n");
                        return EXIT_FAILURE;
                    }
                    symtabFile = (char *) malloc(strlen(optarg) + 1);
                    strncpy(symtabFile, optarg, strlen(optarg));
                    break;
                case 'f':
                    if (programFile != NULL) {
                        fprintf(stderr, "fred  [ -s symbol_table_file ] [ -f program_file ]\n");
                        return EXIT_FAILURE;
                    }
                    programFile = (char *) malloc(strlen(optarg) + 1);
                    strncpy(programFile, optarg, strlen(optarg));
                    break;
                default:
                    fprintf(stderr, "fred  [ -s symbol_table_file ] [ -f program_file ]\n");
                    return EXIT_FAILURE;
            }
        }
    }
}
