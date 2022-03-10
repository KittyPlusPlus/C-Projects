#ifndef ARITHMETIC_H
#define ARITHMETIC_H

// Operations allowed
enum operations { ADD, SUB, MUL, DIV, REM, OP_NUM };
typedef int (*arith_func)(float, float, float *);

// Strings for operators
extern char *op_str[OP_NUM];
// Arithmetic oprations
extern arith_func op_func[OP_NUM];
// Possible errors
extern char *ERRCODES[2];

/**
 * @brief Add @a a and @a b
 */
int arith_add(float a, float b, float *result);

/**
 * @brief Subtract @a a and @a b
 */
int arith_sub(float a, float b, float *result);

/**
 * @brief Multiply @a a and @a b
 */
int arith_mul(float a, float b, float *result);

/**
 * @brief Divide @a a and @a b. The second argument should not be 0
 *
 */
int arith_div(float a, float b, float *result);

/**
 * @brief Find the remainder of @a a and @a b
 */
int arith_rem(float a, float b, float *result);

#endif
