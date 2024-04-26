
#ifndef _WEATHER_UTILS_H
#define _WEATHER_UTILS_H

#include "array_helpers.h"

int min_TempMin(WeatherTable a);

void max_TempMax_per_year(WeatherTable a, int output[YEARS]);

void month_max_amount_Rainfall_per_year(WeatherTable a, unsigned int output[YEARS]);

#endif