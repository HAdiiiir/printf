#include <stdio.h>

/*
 * Entry point of the program.
 *
 * This function reads two integers from the user and prints them.
 *
 * Returns:
 *   0 on successful execution.
 */

int main(void)
{
int number1, number2;

printf("Enter an integer: ");
scanf("%d", &number1);

printf("Enter another integer: ");
scanf("%i", &number2);

printf("You entered: %d and %i\n", number1, number2);

return (0);
}
