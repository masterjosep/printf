#include "main.h"

/**
 * retrieve_size - Calculates the size of the dispute
 * @format: Formatted string in which to print the disputes
 * @i: List of disputes to be printed.
 *
 * Return: Precision.
 */
int retrieve_size(const char *format, int *i)
{
	int curr_i = *i + 1;
	int size = 0;

	if (format[curr_i] == 'l')
		size = S_LONG;
	else if (format[curr_i] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;

	return (size);
}
