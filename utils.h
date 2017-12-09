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

/// Comparator for symbol entries
/// @param p1: The first symbol
/// @param p2: The second symbol
/// @return: -1 if p1 < p2, 0 if p1 == p2, 1 if p1 > p2
int symbolCmp(const void *p1, const void *p2);

/// Strip the trailing and heading whitespace and newline character
/// @param line: the line to strip
char* strip(char *line);

/// Process the define statement
/// @param cmd: the statement
void processDefine(char *cmd);

/// Process the prt statement
/// @param cmd: the statement
void processPrt(char *cmd);

/// Process the let statement
/// @param cmd: the statement
void processLet(char *cmd);

/// Process the if statement
/// @param cmd: the statement
void processIf(char *cmd);

/// Process the display statement
/// @param cmd: the statement
/// @param symtab: the symbol table
void processDisplay(char *cmd, SymTab *symtab);

/// Print symbol's value
/// @param entry: the symbol
void printValSymbol(Symbol *entry);

#endif