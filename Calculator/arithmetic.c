#include "arithmetic.h"
// -------- Helper Functions --------//

// -------- Library Functions --------//
int arith_add(float a, float b, float *result)
{
	*result = a + b;
	return 0;
}

int arith_sub(float a, float b, float *result)
{
	*result = a - b;
	return 0;
}

int arith_mul(float a, float b, float *result)
{
	*result = a * b;
	return 0;
}

int arith_div(float a, float b, float *result)
{
	if (b == 0) return 1;

	*result = a / b;
	return 0;
}

int arith_rem(float a, float b, float *result)
{
	if (b == 0) return 1;
	*result = a - (int)(a / b) * b;
	return 0;
}

// -------- Object Defintions --------//
char *op_str[OP_NUM] = {
		[ADD] = "+", [SUB] = "-", [MUL] = "*", [DIV] = "/", [REM] = "%",
};

arith_func op_func[OP_NUM] = {
		[ADD] = arith_add, [SUB] = arith_sub, [MUL] = arith_mul, [DIV] = arith_div, [REM] = arith_rem,
};

char *ERRCODES[2] = {
		[0] = "No Error",
		[1] = "Division by Zero",
};
