// #include <stdio.h>
// #include <stdlib.h>

// #define MAX 100

// // Compare function for qsort
// int cmp(const void *a, const void *b) {
//     return (*(int *)a - *(int *)b);
// }

// int main() {
//     int input[] = {3,10,6, 7,1, 4, 2,8,9, 5};
//     int n = sizeof(input) / sizeof(int);

//     int stack[MAX], top = -1;
//     int output[MAX], out_i = 0;

//     printf("Input: ");
//     for (int i = 0; i < n; i++)
//         printf("%d ", input[i]);
//     printf("\n\n");

//     for (int i = 0; i < n; i++) {
//         int curr = input[i];
//         printf("Incoming: %d\n", curr);

//         // Pop until current is <= stack[top]
//         while (top >= 0 && curr > stack[top]) {
//             printf("Pop %d (since %d > top)\n", stack[top], curr);
//             output[out_i++] = stack[top--];
//         }

//         printf("Push %d\n", curr);
//         stack[++top] = curr;
//     }

//     // Pop remaining stack to output
//     while (top >= 0)
//         output[out_i++] = stack[top--];

//     // Sort final output
//     qsort(output, out_i, sizeof(int), cmp);

//     printf("\nFinal sorted (ascending) output:\n");
//     for (int i = 0; i < out_i; i++)
//         printf("%d ", output[i]);
//     printf("\n");

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int top;
} Stack;

// Stack operations
void push(Stack *s, int value) {
    s->data[++s->top] = value;
}

int pop(Stack *s) {
    return s->data[s->top--];
}

int is_empty(Stack *s) {
    return s->top == -1;
}

void print_stack(Stack *s, char name) {
    printf("Stack %c (top to bottom): ", name);
    for (int i = s->top; i >= 0; i--)
        printf("%d ", s->data[i]);
    printf("\n");
}

// Push_swap operations
void sa(Stack *a) {
    if (a->top < 1) return;
    int tmp = a->data[a->top];
    a->data[a->top] = a->data[a->top - 1];
    a->data[a->top - 1] = tmp;
    printf("sa\n");
}

void pa(Stack *a, Stack *b) {
    if (is_empty(b)) return;
    push(a, pop(b));
    printf("pa\n");
}

void pb(Stack *a, Stack *b) {
    if (is_empty(a)) return;
    push(b, pop(a));
    printf("pb\n");
}

void ra(Stack *a) {
    if (a->top < 1) return;
    int tmp = a->data[a->top];
    for (int i = a->top; i > 0; i--)
        a->data[i] = a->data[i - 1];
    a->data[0] = tmp;
    printf("ra\n");
}

void rra(Stack *a) {
    if (a->top < 1) return;
    int tmp = a->data[0];
    for (int i = 0; i < a->top; i++)
        a->data[i] = a->data[i + 1];
    a->data[a->top] = tmp;
    printf("rra\n");
}



// Utility: find index of minimum value in stack
int find_min_index(Stack *a) {
    int min = a->data[0];
    int idx = 0;
    for (int i = 1; i <= a->top; i++) {
        if (a->data[i] < min) {
            min = a->data[i];
            idx = i;
        }
    }
    return idx;
}

int find_min_index_n(Stack *a, int n) {
    int min = a->data[a->top - n + 1];
    int idx = a->top - n + 1;
    for (int i = idx + 1; i <= a->top; i++) {
        if (a->data[i] < min) {
            min = a->data[i];
            idx = i;
        }
    }
    return idx;
}




// Rotate smallest value to top of A
void bring_min_to_top(Stack *a) {
    int idx = find_min_index(a);
    int size = a->top + 1;

    if (idx <= size / 2) {
        for (int i = 0; i < idx; i++)
            ra(a);
    } else {
        for (int i = 0; i < size - idx; i++)
            rra(a);
    }
}


int is_sorted(Stack *a) {
    for (int i = a->top; i > 0; i--) {
        if (a->data[i] > a->data[i - 1])
            return 0;
    }
    return 1;
}



void sort_two(Stack *a) {
    if (a->top > 0 && a->data[a->top] > a->data[a->top - 1])
        sa(a);
}

void sort_three(Stack *a, Stack *b) {
    int min_idx = find_min_index(a);
    int size = a->top + 1;
    int from_top = a->top - min_idx;

    if (from_top <= size / 2) {
        while (from_top-- > 0)
            ra(a);
    } else {
        int rotations = size - from_top;
        while (rotations-- > 0)
            rra(a);
    }

    pb(a, b);
    sort_two(a);
    pa(a, b);
}



// void sort_two(Stack *a) {
//     if(!is_sorted(a))
//         sa(a);
// }

// // Sort small stacks
// void sort_three(Stack *a, Stack *b) {
//     int min_idx = find_min_index(a);
//     int size = a->top + 1;
//     int from_top = a->top - min_idx;

//     // Rotate smallest to top
//     if (from_top <= size / 2) {
//         while (from_top-- > 0)
//             ra(a);
//     } else {
//         int rotations = size - from_top;
//         while (rotations-- > 0)
//             rra(a);
//     }

//     pb(a, b);       // push smallest to B
//     sort_two(a);    // sort remaining 2 elements
//     pa(a, b);       // bring smallest back
// }


void sort_four(Stack *a, Stack *b) {
    int min_idx = find_min_index(a);
    int size = a->top + 1;
    int from_top = a->top - min_idx;

    // Rotate until the smallest is at the top (head)
    if (from_top <= size / 2) {
        while (from_top-- > 0)
            ra(a);
    } else {
        int rotations = size - from_top;
        while (rotations-- > 0)
            rra(a);
    }

    pb(a, b);       // push smallest to B
    sort_three(a,b);  // sort the remaining three elements
    pa(a, b);       // bring smallest back to A
}


void sort_five(Stack *a, Stack *b) {
    int min_idx = find_min_index(a);
    int size = a->top + 1;
    int from_top = a->top - min_idx;

    // Rotate until the smallest is at the top
    if (from_top <= size / 2) {
        while (from_top-- > 0)
            ra(a);
    } else {
        int rotations = size - from_top;
        while (rotations-- > 0)
            rra(a);
    }

    pb(a, b);       // push smallest to B
    sort_four(a, b); // sort the remaining four elements
    pa(a, b);       // bring smallest back to A
}
void sort_six(Stack *a, Stack *b) {
    int min_idx = find_min_index(a);
    int size = a->top + 1;
    int from_top = a->top - min_idx;

    // Rotate until smallest is on top
    if (from_top <= size / 2) {
        while (from_top-- > 0)
            ra(a);
    } else {
        int rotations = size - from_top;
        while (rotations-- > 0)
            rra(a);
    }

    pb(a, b);          // push smallest to B
    sort_five(a, b);   // sort remaining five elements
    pa(a, b);          // bring smallest back to A
}

void sort_seven(Stack *a, Stack *b) {
    int min_idx = find_min_index(a);
    int size = a->top + 1;
    int from_top = a->top - min_idx;

    // Rotate smallest to top
    if (from_top <= size / 2) {
        while (from_top-- > 0)
            ra(a);
    } else {
        int rotations = size - from_top;
        while (rotations-- > 0)
            rra(a);
    }

    pb(a, b);         // push smallest to B
    sort_six(a, b);   // sort remaining 6
    pa(a, b);         // bring smallest back
}


void insert_pa_sorted(Stack *a, Stack *b) {
    pa(a, b);
    int val = a->data[a->top];
    int i = a->top;

    // Rotate to place inserted element at correct position
    while (i > 0 && a->data[i - 1] > val) {
        sa(a);
        i--;
    }
}

void sort_n(Stack *a, Stack *b, int n) {
    if (n <= 1)
        return;
    if (n == 2) {
        sort_two(a);
        return;
    }
    if (n == 3) {
        sort_three(a, b); // your recursive one, not hardcoded cases
        return;
    }

    int min_idx = find_min_index(a);
    int size = a->top + 1;
    int from_top = a->top - min_idx;

    if (from_top <= size / 2) {
        while (from_top-- > 0)
            ra(a);
    } else {
        int rotations = size - from_top;
        while (rotations-- > 0)
            rra(a);
    }

    pb(a, b);
    sort_n(a, b, n - 1);
    pa(a, b);
}


int main() {
    Stack a = {.top = -1}, b = {.top = -1};
    int input[] = {55,2,10,-4,6};
    int n = sizeof(input) / sizeof(int);

    for (int i = n - 1; i >= 0; i--)
        push(&a, input[i]);

    // printf("Initial state:\n");
    // print_stack(&a, 'A');
    // print_stack(&b, 'B');
    // printf("\n");

    sort_n(&a, &b, n);

    // if (n==2)
    //     sort_two(&a);
    // else if (n == 3)
    //     sort_three(&a, &b);
    // else if (n == 4)
    //     sort_four(&a, &b);
    // else if (n == 5)
    //     sort_five(&a, &b);
    // else if (n == 6)
    //     sort_six(&a, &b);
    // else if (n == 7)
    //     sort_seven(&a, &b);

    printf("\nFinal state:\n");
    print_stack(&a, 'A');
    print_stack(&b, 'B');

    return 0;
}
