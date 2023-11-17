#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
            case 'c':
                count += putchar(va_arg(args, int));
                break;
            case 's':
                count += printf("%s", va_arg(args, char *));
                break;
            case '%':
                count += putchar('%');
                break;
            default:
                count += putchar('%');
                count += putchar(*format);
                break;
            }
        }
        else
        {
            count += putchar(*format);
        }
        format++;
    }

    va_end(args);

    return count;
}

int main()
{
    _printf("Hello, %s! My favorite character is %c. This is a percent sign: %%.\n", "World", 'A');

    return 0;
}
