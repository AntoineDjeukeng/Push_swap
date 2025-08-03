
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int top;
    int n;
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
    a->n++;
    printf("sa\n");
}

void pa(Stack *a, Stack *b) {
    if (is_empty(b)) return;
    push(a, pop(b));
    a->n++;
    printf("pa\n");
}

void pb(Stack *a, Stack *b) {
    if (is_empty(a)) return;
    push(b, pop(a));
    a->n++;
    printf("pb\n");
}

void ra(Stack *a) {
    if (a->top < 1) return;
    int tmp = a->data[a->top];
    for (int i = a->top; i > 0; i--)
        a->data[i] = a->data[i - 1];
    a->data[0] = tmp;
    a->n++;
    printf("ra\n");
}

void rra(Stack *a) {
    if (a->top < 1) return;
    int tmp = a->data[0];
    for (int i = 0; i < a->top; i++)
        a->data[i] = a->data[i + 1];
    a->data[a->top] = tmp;
    a->n++;
    printf("rra\n");
}


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


void	bring_min_to_top(Stack *a)
{
	int	min_idx;
	int	size;
	int	from_top;
	int	rotations;

	min_idx = find_min_index(a);
	size = a->top + 1;
	from_top = a->top - min_idx;
	if (from_top <= size / 2)
	{
		while (from_top-- > 0)
			ra(a);
	}
	else
	{
		rotations = size - from_top;
		while (rotations-- > 0)
			rra(a);
	}
}

void	sort_n(Stack *a, Stack *b, int n)
{
	if (n <= 1)
		return ;
	if (n == 2)
	{
		sort_two(a);
		return ;
	}
	if (n == 3)
	{
		sort_three(a, b);
		return ;
	}
	bring_min_to_top(a);
	pb(a, b);
	sort_n(a, b, n - 1);
	pa(a, b);
}


// void sort_n(Stack *a, Stack *b, int n) {
//     if (n <= 1)
//         return;
//     if (n == 2) {
//         sort_two(a);
//         return;
//     }
//     if (n == 3) {
//         sort_three(a, b);
//         return;
//     }

//     int min_idx = find_min_index(a);
//     int size = a->top + 1;
//     int from_top = a->top - min_idx;

//     if (from_top <= size / 2) {
//         while (from_top-- > 0)
//             ra(a);
//     } else {
//         int rotations = size - from_top;
//         while (rotations-- > 0)
//             rra(a);
//     }

//     pb(a, b);
//     sort_n(a, b, n - 1);
//     pa(a, b);
// }

#include <time.h>

// int main() {
//     srand(time(NULL));
//     Stack a = {.top = -1}, b = {.top = -1};
//     int input[] = {55,25,-10,7,6};
//     int n = sizeof(input) / sizeof(int);
// Stack a = {.top = -1};
// srand(time(NULL));

// for (int i = 0; i < 5; i++) {
//     int value = rand() % 100;  // 0–99
//     push(&a, value);
// }

//     for (int i = n - 1; i >= 0; i--)
//         push(&a, input[i]);

//     sort_n(&a, &b, n);


    
//     return 0;
// }



int main() {
    srand(time(NULL));

    Stack a = {.top = -1,.n=0}, b = {.top = -1,.n=0};

    // Option 1: Use predefined input
    // int input[] = {55, 25, -10, 7, 6};
    // int n = sizeof(input) / sizeof(int);
    // for (int i = n - 1; i >= 0; i--)
    //     push(&a, input[i]);
    // Option 2: Use random input
    int n = 5;
    for (int i = 0; i < n; i++) {
        int value = rand() % 100;  // range 0–99
        push(&a, value);
    }

    print_stack(&a, 'A');
    print_stack(&b, 'B');
    

    sort_n(&a, &b, n);


    printf("Final state: %d\n",a.n);
    print_stack(&a, 'A');
    print_stack(&b, 'B');
    return 0;
}




// #include <stdio.h>
// #include <stdlib.h>

// #define MAX 100

// typedef struct {
//     int data[MAX];
//     int top;
// } Stack;

// // your push() here...

// int main(int argc, char **argv) {
//     Stack a = {.top = -1}, b = {.top = -1};

//     if (argc < 2) {
//         fprintf(stderr, "Usage: %s num1 num2 ...\n", argv[0]);
//         return 1;
//     }

//     // Read argv values into stack A in reverse
//     for (int i = argc - 1; i >= 1; i--) {
//         int value = atoi(argv[i]);  // or strtol for better error checking
//         push(&a, value);
//     }

//     // printf("Initial stack A (top to bottom): ");
//     // for (int i = a.top; i >= 0; i--)
//     //     printf("%d ", a.data[i]);
//     // printf("\n");

//     // Call your sort function here:
//     sort_n(&a, &b, argc - 1);


//     printf("\nFinal state:\n");
//     print_stack(&a, 'A');
//     print_stack(&b, 'B');

//     return 0;
// }
