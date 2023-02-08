#include <stdarg.h>
#include <unistd.h>

void my_putchar(char c) {
  write(1, &c, 1);
}

void my_putstr(char *str) {
  int i = 0;
  while (str[i]) {
    my_putchar(str[i]);
    i++;
  }
}

void my_put_nbr(int nb) {
  if (nb < 0) {
    my_putchar('-');
    nb = -nb;
  }
  if (nb >= 10) {
    my_put_nbr(nb / 10);
    my_put_nbr(nb % 10);
  } else {
    my_putchar(nb + '0');
  }
}

void my_put_unsigned_nbr(unsigned int nb) {
  if (nb >= 10) {
    my_put_unsigned_nbr(nb / 10);
    my_put_unsigned_nbr(nb % 10);
  } else {
    my_putchar(nb + '0');
  }
}

void my_put_hex(unsigned int nb, char *base) {
  if (nb >= 16) {
    my_put_hex(nb / 16, base);
    my_put_hex(nb % 16, base);
  } else {
    my_putchar(base[nb]);
  }
}

void my_put_pointer(unsigned long nb) {
  my_putstr("0x");
  if (nb >= 16) {
    my_put_hex(nb / 16, "0123456789abcdef");
    my_put_hex(nb % 16, "0123456789abcdef");
  } else {
    my_putchar('0');
  }
}

int my_printf(const char *format, ...) {
  va_list args;
  va_start(args, format);
  for (int i = 0; format[i]; i++) {
        if (format[i] == '%') {
        i++;
        switch (format[i]) {
                case 'd':
                    my_put_nbr(va_arg(args, int));
                break;
                case 'o':
                    my_put_unsigned_nbr(va_arg(args, unsigned int));
                break;
                case 'u':
                    my_put_unsigned_nbr(va_arg(args, unsigned int));
                break;
                case 'x':
                    my_put_hex(va_arg(args, unsigned int), "0123456789abcdef");
                break;
                case 'c':
                    my_putchar((char) va_arg(args, int));
                break;
                case 's':
                    my_putstr(va_arg(args, char *));
                break;
                case 'p':
                    my_put_pointer(va_arg(args, unsigned long));
                break;
                default:
                    my_putchar(format[i]);
                break;
            }
        }else {
            my_putchar(format[i]);
        }
    }
    va_end(args);
    return 0;
}
