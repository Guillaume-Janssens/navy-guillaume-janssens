/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** .h file for the library
*/

#pragma once
#include <stdarg.h>

//macro
#define NOMBRE_DE_FLAG 10

//principal functions
int my_strlen(char const *str);
void my_putchar(char c);
int my_put_nbr_base(int nb, char *base);
int my_putstr(char const *str);
int my_printf(char const *format, ...);
int my_flag_finder(char element);

//void flag functions
void my_char(va_list ap, char const *format, int *i);
void my_string(va_list ap, char const *format, int *i);
void my_integer(va_list ap, char const *format, int *i);
void my_integer_plus(va_list ap, char const *format, int *i);
void my_integer_octal(va_list ap, char const *format, int *i);
void my_integer_hexa(va_list ap, char const *format, int *i);
void my_integer_hexa_capital_letters(va_list ap, char const *format, int *i);
void my_binary_base(va_list ap, char const *format, int *i);

//void function to shortcut my code
int my_condition(char const *format, int *i, va_list ap);

