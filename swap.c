void swap(stack_t **stack) {
    if (*stack != NULL && (*stack)->next != NULL) {
        int temp = (*stack)->n;
        (*stack)->n = (*stack)->next->n;
        (*stack)->next->n = temp;
    } else {
        fprintf(stderr, "L%zu: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
}
