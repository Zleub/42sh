#ifndef ERRORS_H
# define ERRORS_H

#define EXPAND(A, B) # A # B
#define ERROR(A, B) EXPAND(A, B)
#define SETENV setenv :\t
#define UNSETENV unsetenv :\t
#define E_GENERIC An error occured.\n
#define E_TOO_MANY_ARG Error. Too many arguments.\n
#define E_NOT_ENOUGH_ARG Error. Not enough arguments.\n
#define E_INPUT Error on input. Is your input reasonnable ?\n

#endif /* !ERRORS_H */
