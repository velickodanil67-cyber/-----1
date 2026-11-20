#include "loc_max_func.h"

int max_local_maximum_len(FILE *f)
{
	double previous = 0., current = 0.;
	int max_len = 0;
	int cur_len = 0;
	int is_left_lower = 0;

	if (fscanf(f, "%lf", &previous) != 1)
	{
		printf("File is empty\n");
		return 0;
	}

	// Для самой первой площадки равных чисел k = 1,
	// поэтому условие слева (k = 1 или a_{k-1} < a_k) выполнено автоматически
	cur_len = 1;
	is_left_lower = 1;

	while (fscanf(f, "%lf", &current) == 1)
	{
		if (fabs(current - previous) < eps)
		{
			// Площадка равных элементов продолжается
			cur_len++;
		}
		else if (current < previous)
		{
			// Пошел спуск вниз (a_{l+1} < a_l): правое условие для текущей площадки выполнено!
			if (is_left_lower && cur_len > max_len)
			{
				max_len = cur_len;
			}
			// Новая площадка меньше предыдущей, поэтому для нее условие слева НЕ выполнено
			is_left_lower = 0;
			cur_len = 1;
		}
		else
		{
			// Пошел подъем вверх (current > previous):
			// старая площадка не максимум, но для новой площадки левое условие выполнено!
			is_left_lower = 1;
			cur_len = 1;
		}
		previous = current;
	}

	// Когда файл закончился, для последней площадки l = N (правое условие выполнено)
	if (is_left_lower && cur_len > max_len)
	{
		max_len = cur_len;
	}

	return max_len;
}