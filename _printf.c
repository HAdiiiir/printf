#include "main.h"
#include <stdlib.h>

/**
 * itoa - Converts an integer to a string
 * @val: Integer to convert
 * @base: Number base for conversion
 *
 * Return: Pointer to the converted string
 */
<<<<<<< HEAD
char *itoa(int val, int base)
{
=======
char *itoa(int val, int base) {
>>>>>>> da8547fe009dd036ab50156dec046790508c22f1
    static char buf[32] = {0};
    int i = 30;

    for (; val && i; --i, val /= base)
        buf[i] = "0123456789abcdef"[val % base];

    return &buf[i + 1];
}

<<<<<<< HEAD
/**
 * _printf - Custom printf function to format and print data
 * @format: format string containing the directives
 *
=======

/**
 * _printf - Custom printf function to format and print data
 * @format: format string containing the directives
 * 
>>>>>>> da8547fe009dd036ab50156dec046790508c22f1
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    char ch;
    char *str;
    int val;

    va_start(args, format);

<<<<<<< HEAD
    while (*format)
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
            case 'c':
                ch = (char)va_arg(args, int);
                putchar(ch);
                count++;
                break;
            case 's':
                str = va_arg(args, char *);
                while (*str)
                {
                    putchar(*str);
                    str++;
                    count++;
                }
                break;
            case 'd':
            case 'i':
                val = va_arg(args, int);
                str = itoa(val, 10);
                while (*str)
                {
                    putchar(*str);
                    str++;
                    count++;
                }
                break;
            case '%':
                putchar('%');
                count++;
                break;
            }
        }
        else
        {
=======
    while (*format) {
        if (*format == '%') {
            format++;
            switch (*format) {
                case 'c':
                    ch = (char)va_arg(args, int);
                    putchar(ch);
                    count++;
                    break;
                case 's':
                    str = va_arg(args, char *);
                    while (*str) {
                        putchar(*str);
                        str++;
                        count++;
                    }
                    break;
                case 'd':
                case 'i':
                    val = va_arg(args, int);
                    str = itoa(val, 10);
                    while (*str) {
                        putchar(*str);
                        str++;
                        count++;
                    }
                    break;
                case '%':
                    putchar('%');
                    count++;
                    break;
            }
        } else {
>>>>>>> da8547fe009dd036ab50156dec046790508c22f1
            putchar(*format);
            count++;
        }
        format++;
    }

    va_end(args);

    return count;
<<<<<<< HEAD
}
=======
}
>>>>>>> da8547fe009dd036ab50156dec046790508c22f1
