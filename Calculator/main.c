#define _GNU_SOURCE
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// User headers
#include "arithmetic.h"

#define TODO(msg)                                                  \
	{                                                                \
		fprintf(stderr, "TODO::%s:%d: %s\n", __FILE__, __LINE__, msg); \
		exit(EXIT_FAILURE);                                            \
	}

int main()
{
	float a = 0, b = 0, result = 0;
	int opcode = ADD, errno = 0;
	char *expr = NULL, operator[10];
	size_t len = 0;

	// REPL loop for the calculator
	while (true) {
		// ---- Step 1: Read input from user ---- //
		printf("Calc>> ");
		// Read the expression
		if (getline(&expr, &len, stdin) == EOF) goto quit;
		if (expr[0] == 'q' || expr[0] == 'Q') goto quit;

		// Get operators and operands from the expression
		TODO("Parse expression to handle arguments better. Use Lex maybe");
		TODO("Add _ to refer to result");
		sscanf(expr, "%f %s %f", &a, operator, & b);
		// Match the opcode to the operator
		for (opcode = 0; opcode < OP_NUM; opcode++) {
			if (strcasecmp(op_str[opcode], operator) == 0) break;
		}
		// If operand in invalid prompt the user and repeat loop
		if (opcode == OP_NUM) {
			printf("Invalid Operand %s\n", operator);
			continue;
		}

		// ---- Step 2: Evaluate the expression ---- //
		TODO("Add more operations");
		errno = op_func[opcode](a, b, &result);
		if (errno != 0) {
			printf("Error: %s\n", ERRCODES[errno]);
			continue;
		}

		// ---- Step 3: Print the result ---- //
		printf("%g\n", result);
	}

quit:
	printf("Closing the program\n");
	free(expr);
	return 0;
}
