/// file: utils.h
/// description: interface for ultility functions
/// author: Duc Phan - ddp3945@rit.edu

#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>
#include "symtab.h"

/// Load a symbol table file into a symbol table
/// @param symtabFile: the symbol table file
/// @param symtab: the symbol table
void loadSymTabFile(char *symtabFile, SymTab *symtab);

/// Parse a symbol entry from a line of text
/// @param line: the line containing the symbol entry
/// @return: pointer to a symbol
Symbol* parseSymbol(char *line);

/// Comparator for symbol entries
/// @param p1: The first symbol
/// @param p2: The second symbol
/// @return: -1 if p1 < p2, 0 if p1 == p2, 1 if p1 > p2
int symbolCmp(const void *p1, const void *p2);

#endif