#include "fdf.h"

void	ft_calibration(t_fdf *fdf)
{
	int		i;
	int		j;

	i = -1;
	//ratio_x = (1920) / (fdf->x_max - 1) / 2;
	//ratio_y = (1080) / (fdf->y_max - 1) / 2;
	//ratio = ft_calculate_diff(ratio_x, ratio_y);
	// printf("ratio=%f\n", ratio_y);
	// printf("ratio=%f\n", ratio_x);
	// printf("ratio=%f\n", ((1080) / (fdf->y_max)) * 0.75);
	while (++i < fdf->y_max)
	{
		j = -1;
		while (++j < fdf->x_max)
		{
			fdf->dfault[i][j].x = fdf->dfault[i][j].x * fdf->dist;
			fdf->dfault[i][j].y = fdf->dfault[i][j].y * fdf->dist;
			fdf->dfault[i][j].x += fdf->posx;
			fdf->dfault[i][j].y += fdf->posy;
			// printf("calibration[%d][%d].x=%f\n", i, j, fdf->map[i][j].x);
			// printf("calibration[%d][%d].y=%f\n", i, j, fdf->map[i][j].y);
			// printf("calibration[%d][%d].z=%f\n", i, j, fdf->map[i][j].z);
		}
	}
}

void	ft_calibrate_z(t_fdf *fdf)
{
	float	compare;
	int		i;
	int		j;

	i = -1;
	compare = ft_calculate_diffinv(fdf->x_max, fdf->y_max);
	while (++i < fdf->y_max)
	{
		j = -1;
		while (++j < fdf->x_max)
		{
			if (fdf->map[i][j].z != 0 && fdf->z_max >= compare / 2)
			{
				if (fdf->z_max >= compare * 2)
					fdf->map[i][j].z = fdf->map[i][j].z / ((fdf->z_max / compare) * 4);
				if (fdf->z_max < compare * 2)
					fdf->map[i][j].z = fdf->map[i][j].z / ((compare / fdf->z_max) * 4);
			}
		}
	}
	i = 0;
	fdf->dfault = (t_default **)malloc(sizeof(t_default *) * (fdf->y_max));
	while (i < fdf->y_max)
		fdf->dfault[i++] = (t_default *)malloc(sizeof(t_default) * (fdf->x_max));
}

float	ft_calculate_diffinv(float ratio_x, float ratio_y)
{
	if (ratio_x >= ratio_y)
	{
		return (ratio_x);
	}
	if (ratio_x <= ratio_y)
	{
		return (ratio_y);
	}
	return (1);
}

float	ft_calculate_diff(float ratio_x, float ratio_y)
{
	if (ratio_x >= ratio_y)
	{
		return (ratio_y);
	}
	if (ratio_x <= ratio_y)
	{
		return (ratio_x);
	}
	return (1);
}
