#include "monty.h" /* Includes necessary header file for data structures and function definitions */

int add(stack_t **stack, unsigned int line_number) /* Function definition for `add` operation */
{
    if (!*stack || !(*stack)->next) { /* Check if stack is empty or only has one element */
        fprintf(stderr, "L%u: can't add, stack too short\n", line_number); /* Print error message if stack is too short */
        return EXIT_FAILURE; /* Return error code */
    }

    stack_t *node = (*stack)->next; /* Get a pointer to the second element */
    node->n += (*stack)->n; /* Add the top element's value to the second element's value */
    pop(stack); /* Remove the top element from the stack */

    return EXIT_SUCCESS; /* Return success code */
}
