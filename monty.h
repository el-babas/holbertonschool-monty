#ifndef _MONTY_
#define _MONTY_

/************************ [Libraries] ************************/

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

#define MAXBUFFER 1024
/*************************************************************/

/*********************** [Structures] ************************/

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct variable_s - variables globals
 * @exit_code: exit code
 * @tokens: current token
 * @buffer: content file
 * @linenumber: line number
 * @tokenumber: tokens numbers
 * @head: doubly linked list representation of a stack
 *
 * Description: variables globals
 */
typedef struct variable_s
{
	int exit_code;
	char **tokens;
	char *buffer;
	unsigned int linenumber;
	unsigned int tokenumber;
	stack_t *head;
} variable_t;

/*************************************************************/

/************************* [Variables] ***********************/

extern variable_t gb_var;

/*************************************************************/

/************************* [Functions] ***********************/

void (*my_getfunc(char *opcode))(stack_t **stack, unsigned int linenumber);
void my_main(FILE *fd_monty);
void my_init(void);

void my_nodefree(stack_t *head);
stack_t *my_nodeadd(stack_t **head, const int n);
stack_t *my_nodeend(stack_t **head, const int n);

int my_strcmp(char *s1, char *s2);
void my_trim(char **bf);
void my_strtok(void);

void monty_push(stack_t **head, unsigned int linenumber);
void monty_pall(stack_t **head, unsigned int linenumber);

/*************************************************************/
#endif
