#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int count = 0;

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
                    {
                    const char *str = va_arg(args, const char *);
                    while (*str != '\0')
                    {
                        count += putchar(*str);
                        str++;
                    }
                    break;
                }
                case '%':
                    count += putchar('%');
                    break;
                default:
                    count += putchar('%');
                    count += putchar(*format);
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

int main() {
    _printf("Hello, %s! The character is %c and the percentage is %%.\n", "World", 'A');
    return 0;
}
