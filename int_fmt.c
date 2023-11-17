#include <stdio.h>
#include <stdarg.h>

void print_binary(unsigned int num)
{
if (num > 1)
{
print_binary(num / 2);
}
putchar('0' + num % 2);
}

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
int flags = 0;


while (*format == '+' || *format == ' ' || *format == '#')
{
if (*format == '+')
{
flags |= 1; '+'
}
else if (*format == ' ')
{
flags |= 2; 'space'
}
else if (*format == '#')
{
flags |= 4; '#'
}
format++;
}

switch (*format)
{
case 'c':
count += putchar(va_arg(args, int));
break;
case 's':
count += printf("%s", va_arg(args, char *));
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
count += printf("%+d", va_arg(args, int));
break;
case 'o':
count += printf("%#o", va_arg(args, unsigned int));
break;
case 'x':
case 'X':
count += printf("%#x", va_arg(args, unsigned int));
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

{
unsigned int value = 42;
_printf("The binary representation of %u is %b\n", value, value);
_printf("Formatted number: %+d\n", -123);
_printf("Octal number with '#' flag: %#o\n", 077);
_printf("Hexadecimal number with '#' flag: %#x\n", 0xABCD);

return (0);
}
