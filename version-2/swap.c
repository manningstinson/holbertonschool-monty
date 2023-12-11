void swap(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp;

    if (stack_empty(*stack))
    {
        fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    tmp = (*stack)->next;
    (*stack)->next = tmp->next;
    tmp->next->prev = *stack;
    tmp->prev = NULL;
    tmp->next = *stack;
    (*stack)->prev = tmp;
    *stack = tmp;
}
