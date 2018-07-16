#ifndef SHAREDADT_H_
#define SHAREDADT_H_

typedef char stackElement;
typedef struct {
	stackElement *elements;
	int maxSize;
	int topElement;
} stackS;

void stack(stackS *S, int maxSize);

void push(stackS *S, stackElement p);

stackElement pop(stackS *S);

stackElement top(stackS *S);

int is_full(stackS *S);

int is_empty(stackS *S);

#endif
