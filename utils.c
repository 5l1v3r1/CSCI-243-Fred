/// file: utils.h
/// description: implemetations for ultility functions
/// author: Duc Phan - ddp3945@rit.edu

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "symtab.h"
#include "utils.h"
#include "stackADT.h"

/// Load a symbol table file into a symbol table
/// @param symtabFile: the symbol table file
/// @param symtab: the symbol table
void loadSymTabFile(char *symtabFile, SymTab *symtab) {

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