#include <stdio.h>
#include <string.h>

int main() {
    char stack[20], input[20], operators[10][10][2], terminals[10];
    int i, j, k, num_terminals, top = 0, col, row;

    for (i = 0; i < 10; i++) {
        stack[i] = '\0'; // Use '\0' to represent null character
        input[i] = '\0';
        for (j = 0; j < 10; j++) {
            operators[i][j][0] = '\0';
            operators[i][j][1] = '\0';
        }
    }

    printf("Enter the number of terminals: ");
    scanf("%d", &num_terminals);
    printf("\nEnter the terminals: ");
    scanf("%s", terminals);

    printf("\nEnter the table values:\n");
    for (i = 0; i < num_terminals; i++) {
        for (j = 0; j < num_terminals; j++) {
            printf("Enter the value for %c %c: ", terminals[i], terminals[j]);
            scanf("%s", operators[i][j]);
        }
    }

    printf("\nOPERATOR PRECEDENCE TABLE:\n");
    for (i = 0; i < num_terminals; i++) {
        printf("\t%c", terminals[i]);
    }
    printf("\n");
    for (i = 0; i < num_terminals; i++) {
        printf("%c\t", terminals[i]);
        for (j = 0; j < num_terminals; j++) {
            printf("\t%c", operators[i][j][0]);
        }
        printf("\n");
    }

    stack[top] = '$';
    printf("\nEnter the input string: ");
    scanf("%s", input);

    i = 0;
    printf("\nSTACK\t\t\tINPUT STRING\t\t\tACTION\n");
    printf("\n%s\t\t\t%s\t\t\t", stack, input);

    while (i <= strlen(input)) {
        for (k = 0; k < num_terminals; k++) {
            if (stack[top] == terminals[k])
                col = k;
            if (input[i] == terminals[k])
                row = k;
        }

        if ((stack[top] == '$') && (input[i] == '$')) {
            printf("String is accepted");
            break;
        } else if ((operators[col][row][0] == '<') || (operators[col][row][0] == '=')) {
            stack[++top] = operators[col][row][0];
            stack[++top] = input[i];
            printf("Shift %c", input[i]);
            i++;
        } else {
            if (operators[col][row][0] == '>') {
                while (stack[top] != '<') {
                    --top;
                }
                top = top - 1;
                printf("Reduce");
            } else {
                printf("\nString is not accepted");
                break;
            }
        }
        printf("\n");
        for (k = 0; k <= top; k++) {
            printf("%c", stack[k]);
        }
        printf("\t\t\t");
        for (k = i; k < strlen(input); k++) {
            printf("%c", input[k]);
        }
        printf("\t\t\t");
    }
}

/*
gcc operator-precedence.c -o operator-precedence
./operator-precedence
*/
