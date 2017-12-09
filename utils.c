/// file: utils.h
/// description: implemetations for ultility functions
/// author: Duc Phan - ddp3945@rit.edu

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>
#include "symtab.h"
#include "utils.h"
#include "stackADT.h"

/// Load a symbol table file into a symbol table
/// @param symtabFile: the symbol table file
/// @param symtab: the symbol table
void loadSymTabFile(char *symtabFile, SymTab *symtab) {
    FILE *fdSym = fopen(symtabFile, "r");
    if (fdSym == NULL) {
        fprintf(stderr, "Error opening file %s\n", symtabFile);
        exit(EXIT_FAILURE);
    }
    char typeName[10];
    char symName[MAX_NAME_LEN + 1];
    Value value;
    
    char *lineptr = NULL;
    char *lineptr2 = NULL;
    size_t len = 0;

    while(getline(&lineptr2, &len, fdSym) != EOF) {
        assert(strlen(lineptr2) > 1);

        lineptr = strtok(lineptr2, " \n");
        sscanf(lineptr, "%s", typeName);

        lineptr = strtok(NULL, " \n");
        sscanf(lineptr, "%7s", symName);

        lineptr = strtok(NULL, " \n");
        bool isFloat = false;
        for (size_t i = 0; i < strlen(lineptr); i++) {
            if (lineptr[i] == '.') {
                isFloat = true;
                break;
            }
        }

        if (!strcmp("integer", typeName)) {
            if (isFloat) {
                float f = 0.0;
                sscanf(lineptr, "%f", &f);
                f = roundf(f);
                value.iVal = (int) f;
            } else {
                sscanf(lineptr, "%d", &value.iVal);
            }
            //printf("%s %s %d\n", typeName, symName, value.iVal);
            put(symName, value, Integer, symtab);
        } else if (!strcmp("real", typeName)) {
            sscanf(lineptr, "%f", &value.fVal);
            //printf("%s %s %.3f\n", typeName, symName, value.fVal);
            put(symName, value, Float, symtab);
        }
        
    }

    if (lineptr2 != NULL) {
        free(lineptr2);
    }
    fclose(fdSym);
}

/// Comparator for symbol entries
/// @param p1: The first symbol
/// @param p2: The second symbol
/// @return: < 0 if p1 < p2, 0 if p1 == p2, > 0 if p1 > p2
int symbolCmp(const void *p1, const void *p2) {
    // printf("%p %p\n", (void *) *(Symbol **)p1, (void *) *(Symbol **)p2);
    // puts((*(Symbol **)p1) -> name);
    // puts((*(Symbol **)p2) -> name);
    // printf("%d\n", strcmp( (*(Symbol **)p1) -> name, (*(Symbol **)p2) -> name));
    return strcmp( (*(Symbol **)p1) -> name, (*(Symbol **)p2) -> name);
}