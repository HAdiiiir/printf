#include "main.h"

/**
 * check_null - Checks if a constant char pointer is NULL
 * @format: the character pointer to be checked
 *
 * Return: None.
 */
void check_null(const char *format)
{
if (!format)
{
while (*format >= '0' && *format <= '9')
{
width = width * 10 + (*format - '0');
format++;
}

switch (*format)
{
case 'c':
count += putchar(va_arg(args, int));
break;
case 's':
if (width > 0)
{
count += printf("%*s", width, va_arg(args, char *));
}
else
{
count += printf("%s", va_arg(args, char *));
}
break;
case 'p':
count += printf("%p", va_arg(args, void *));
break;
case 'b':
print_binary(va_arg(args, unsigned int));
count += sizeof(unsigned int) * 8;
break;
case 'd':
case 'i':
if (width > 0)
{
count += printf("%+*d", width, va_arg(args, int));
}
else
{
count += printf("%+d", va_arg(args, int));
}
break;
case 'o':
if (width > 0)
{
count += printf("%#*o", width, va_arg(args, unsigned int));
}
else
{
count += printf("%#o", va_arg(args, unsigned int));
}
break;
case 'x':
case 'X':
if (width > 0)
{
count += printf("%#*x", width, va_arg(args, unsigned int));
}
else
{
count += printf("%#x", va_arg(args, unsigned int));
}
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

return (count);
}
}
}
