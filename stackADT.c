/// file: stackADT.c
/// description: implementation for stack abstract data type
/// author: RIT CS Department

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdbool.h>
#include <assert.h>

#define	STACK_SIZE	5

struct stackStruct {
	void *contents[ STACK_SIZE ];
	size_t num;
};

#include "stackADT.h"

StackADT stk_create( void ) {
	StackADT new;

	new = (StackADT) malloc( sizeof(struct stackStruct) );
	if( new != 0 ) {
		new->num = 0;
	}

	return( new );
}

void stk_destroy( StackADT stack ) {

	assert( stack != 0 );

	free( stack );
}

void stk_clear( StackADT stack ) {
	stack->num = 0;
}

void stk_push( StackADT stack, void *data ) {

	assert( stack->num < STACK_SIZE );

	stack->contents[stack->num] = data;
	stack->num += 1;
}

void *stk_pop( StackADT stack ) {
	int n;
	void *data;

	assert( stack->num > 0 );

	n = stack->num -= 1;
	data = stack->contents[n];

	return( data );
}

void *stk_top( StackADT stack ) {
	int n;
	void *data;

	assert( stack->num > 0 );

	n = stack->num - 1;
	data = stack->contents[n];

	return( data );
}

bool stk_empty( StackADT stack ) {
	return( stack->num == 0 );
}

bool stk_full( StackADT stack ) {
	return( stack->num >= STACK_SIZE );
}
