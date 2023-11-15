#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int count = 0;  // to keep track of the number of characters printed

    while (*format != '\0') {
        if (*format == '%') {
            format++;  // move to the next character after '%'
            switch (*format) {
                case 'c':
                    count += putchar(va_arg(args, int));
                    break;
                case 's': {
                    const char *str = va_arg(args, const char *);
                    while (*str != '\0') {
                        count += putchar(*str);
                        str++;
                    }
                    break;
                }
                case 'd':
                case 'i': {
                    int num = va_arg(args, int);
                    count += printf("%d", num);
                    break;
                }
                case '%':
                    count += putchar('%');
                    break;
                default:
                    // Handle unsupported conversion specifier or other characters
                    count += putchar('%');
                    count += putchar(*format);
            }
        } else {
            count += putchar(*format);
        }
        format++;
    }

    va_end(args);
    return count;
}

int main() {
    _printf("Hello, %s! The character is %c, the percentage is %%.\n", "World", 'A');
    _printf("The number is %d.\n", 42);
    return 0;
}
