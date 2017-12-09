/// file: utils.h
/// description: implemetations for ultility functions
/// author: Duc Phan - ddp3945@rit.edu

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
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
    size_t len = 0;
    ssize_t nread = 0;

    while((nread = getdelim(&lineptr, &len, ' ', fdSym)) != -1) {
        printf("nread = %lu\n", nread);
        sscanf(lineptr, "%s", typeName);

        getdelim(&lineptr, &len, ' ', fdSym);
        sscanf(lineptr, "%7s", symName);

        getdelim(&lineptr, &len, '\n', fdSym);

        if (!strcmp("integer", typeName)) {
            sscanf(lineptr, "%d", &value.iVal);
            printf("%s %s %d\n", typeName, symName, value.iVal);
            put(symName, value, Integer, symtab);
        } else if (!strcmp("real", typeName)) {
            sscanf(lineptr, "%f", &value.fVal);
            printf("%s %s %.3f\n", typeName, symName, value.fVal);
            put(symName, value, Float, symtab);
        }
        
    }

    if (lineptr != NULL) {
        free(lineptr);
    }
    fclose(fdSym);
}

/// Parse a symbol entry from a line of text
/// @param line: the line containing the symbol entry
/// @return: pointer to a symbol
Symbol* parseSymbol(char *line) {

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