# Calculator Program in C

Performs arithmetic operations on floating point values

---

The program implements a simple calculator as a REPL loop. It takes two floats _(a, b)_ and an operator _(op)_ in the form **a op b** and prints the result. The operands are expected to be numeric strings. All other character strings but string starting with **q**, the character **\_** are ignored and skip the evaluation.

### Allowed Operations

- Addition(+)
- Subtraction(-)
- Multiply(\*)
- Division(/)
- Remainder(%)

### Special Inputs

1. [q/Q] quits the calculator.
2. The underscore character (\_) stores the result of the last operation. It is initialised at 0.
