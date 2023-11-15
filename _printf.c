#include <stdio.h>
#include <stdarg.h>

int main(void)
{
    int age = 25;
    myprintf("My name is %s and I am %d years old.\n", "Snehasish", age);
    double pi = 3.14;
    myprintf("The value of pi is %.2f.\n", pi);
    // Print a date and time.
    myprintf("%s %s\n", "Today is", __DATE__);
    myprintf("%s %s\n", "The time is", __TIME__);

    // Print a list of numbers.
    int numbers[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < sizeof(numbers) / sizeof(numbers[0]); i++)
    {
        myprintf("%d\n", numbers[i]);
    }

    // Print a table of data.
    myprintf("| Name | Age | Occupation |\n");
    myprintf("| Snehasish | 25 | AI Engineer |\n");
    myprintf("| Alice | 30 | Software Engineer |\n");
}
int myprintf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int count = 0;
    while (*format != '\0')
    {
        if (*format != '%')
        {
            putchar(*format);
            count++;
        }
        else
        {
            // Handle format specifiers
            switch (*++format)
            {
            case 'd':
                count += fprintf(stdout, "%d", va_arg(args, int));
                break;
            case 'c':
                count += fprintf(stdout, "%c", va_arg(args, char));
                break;
            case 's':
                count += fprintf(stdout, "%s", va_arg(args, char *));
                break;
            case 'f':
                count += fprintf(stdout, "%f", va_arg(args, double));
                break;
            default:
                // Handle unknown format specifiers
                putchar('%');
                putchar(*format);
                count += 2;
                break;
            }
        }
        format++;
    }

    va_end(args);
    return (count);
}
