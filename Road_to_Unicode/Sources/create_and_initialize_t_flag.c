#include <stdlib.h>
#include "../Includes/create_and_initialize_t_flag.h"
#include "../Includes/errors.h"

t_flags *create_and_initialize_t_flag(void)
{
	t_flags		*flag;
	if (!(flag = malloc(sizeof(t_flags))))
		exit_with_msg(ERROR_MALLOC_FAILED);
	flag->prefix_more_and_less = 0;
	flag->left_align_field = 0;
	flag->fields_zero = 0;
	flag->prefix_0_0x_0X = 0;
	flag->prefix_more = 0;
	flag->field = 0;
	flag->precision = 0;
}