
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "weather_utils.h"


int min_TempMin(WeatherTable a){

    int minimo = __INT_MAX__;

    for (size_t anio = 0; anio < YEARS; anio++) {

        for (size_t mes = 0; mes < MONTHS; mes++) {

            for (size_t dia = 0; dia < DAYS; dia++) {

                if (a[anio][mes][dia]._min_temp < minimo) {

                    minimo = a[anio][mes][dia]._min_temp;
                }               
            }
        }
    }
    
    return minimo;
}


void max_TempMax_per_year(WeatherTable a, int output[YEARS]){

    int *puntero_int = NULL;
    int maximo = -(__INT_MAX__);

    for (size_t anio = 0; anio < YEARS; anio++) {

        puntero_int = &output[anio];

        for (size_t mes = 0; mes < MONTHS; mes++) {

            for (size_t dia = 0; dia < DAYS; dia++) {

                if (a[anio][mes][dia]._max_temp > maximo) {

                    maximo = a[anio][mes][dia]._max_temp;
                }
            }
        }
        *puntero_int = maximo;
    }
}


void month_max_amount_Rainfall_per_year(WeatherTable a, unsigned int output[YEARS]){

    unsigned int *puntero_uns_int = NULL;
    unsigned int sum_rainfall = 0u , max_rainfall = 0u , mes_max_rainfall;


    for (size_t anio = 0; anio < YEARS; anio++) {

        puntero_uns_int = &output[anio];

        for (size_t mes = 0; mes < MONTHS; mes++) {

            for (size_t dia = 0; dia < DAYS; dia++) {

                sum_rainfall += a[anio][mes][dia]._rainfall;
                
            }

            if (sum_rainfall >= max_rainfall){

                max_rainfall = sum_rainfall;
                mes_max_rainfall = mes + 1;

            }

            sum_rainfall = 0u;
        }

        *puntero_uns_int = mes_max_rainfall;
        max_rainfall = 0u;
    }
}
