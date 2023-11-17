#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...) {
    va_list args;
    int count = 0;

    va_start(args, format);

    while (*format != '\0') {
        if (*format == '%') {
            format++; // Move to the next character after '%'
            switch (*format) {
                case 'c':
                    count += putchar(va_arg(args, int));
                    break;
                case 's':
                    count += printf("%s", va_arg(args, char *));
                    break;
                case 'p':
                    count += printf("%p", va_arg(args, void *));
                    break;
                case '%':
                    count += putchar('%');
                    break;
                default:
                    count += putchar('%'); // Treat unknown specifier as literal '%'
                    count += putchar(*format);
                    break;
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
    int value = 42;
    _printf("The address of the variable 'value' is %p\n", (void*)&value);

    return 0;
}
