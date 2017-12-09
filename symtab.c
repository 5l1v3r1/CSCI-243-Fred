/// file: symtab.c
/// description: implementation for symbol tables
/// author: Duc Phan - ddp3945@rit.edu

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "symtab.h"

/// Create a new empty Symbol Table
/// @return: pointer to a new symbol table
SymTab* createSymTab() {
    SymTab *symtab = (SymTab *) malloc(sizeof(SymTab));
    if (symtab == NULL) {
        fprintf(stderr, "symtab::createSymTab() failed to allocate memory.\n");
        exit(EXIT_FAILURE);
    }
    symtab -> cap = INIT_CAP;
    symtab -> nEntry = 0;
    symtab -> table = calloc(symtab -> cap, sizeof(Symbol *));
    if (symtab -> table == NULL) {
        fprintf(stderr, "symtab::createSymTab() failed to allocate memory.\n");
        exit(EXIT_FAILURE);
    }
}

/// Destroy a symbol table
/// @param symtab: pointer to a symbol table
void destroySymTab(SymTab *symtab) {

}

/// Put a symbol into a symbol table
/// @param name: name of the symbol
/// @param value: the value of the symbol
/// @param type: type of the symbol
/// @param symtab: the symbol table to put the symbol into
/// @return: true if the symbol is successfully put, otherwise false
bool put(char *name, Value value, Type type, SymTab *symtab) {

}

/// Get the symbol with the specified name
/// param name: name of the symbol to get
/// @return: pointer to the symbol, NULL if not found
Symbol* get(char *name) {

}

/// Determine if a symbol with the specified name is in the table
/// @param name: the name of the symbol
/// @return: true if the symbol is found, false otherwise.
bool has(char *name) {

}

/// Dump the symbol table in alphabetical order
/// @param symtab: the symbol table to be dumped
void dump(SymTab *symtab) {
    
}
