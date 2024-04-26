
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "array_helpers.h"
#include "weather_utils.h"

/**
 * @brief print usage help
 * @param[in] program_name Executable name
 */
void print_help(char *program_name) {
    printf("Usage: %s <input file path>\n\n"
           "Load climate data from a given file in disk.\n"
           "\n"
           "The input file must exist in disk and every line in it must have the following format:\n\n"
           "<year> <month> <day> <temperature> <high> <low> <pressure> <moisture> <precipitations>\n\n"
           "Those elements must be integers and will be copied into the multidimensional integer array 'a'.\n"
           "The dimensions of the array are given by the macro tclimate.\n"
           "\n\n",
           program_name);
}

/**
 * @brief reads file path from command line
 *
 * @param[in] argc amount of command line arguments
 * @param[in] argv command line arguments
 *
 * @return An string containing read filepath
 */
char *parse_filepath(int argc, char *argv[]) {
    char *result = NULL;

    if (argc < 2) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return (result);
}

/**
 * @brief Main program function
 *
 * @param[in] argc amount of command line arguments
 * @param[in] argv command line arguments
 *
 * @return EXIT_SUCCESS when programs executes correctly, EXIT_FAILURE otherwise
*/

int main(int argc, char *argv[]) {

    char *filepath = NULL;
    int value_min_TempMin = 0;
    int array_of_TempMax_per_Year[YEARS];
    unsigned int array_of_Month_MaxMountRainfall_Per_Year[YEARS];

    filepath = parse_filepath(argc, argv);

    WeatherTable array;

    array_from_file(array, filepath);

    value_min_TempMin = min_TempMin(array);
    printf("\nLa menor temperatura mínima histórica es: %d\n" , value_min_TempMin);

    max_TempMax_per_year(array , array_of_TempMax_per_Year);
    print_int_array(array_of_TempMax_per_Year , YEARS);

    month_max_amount_Rainfall_per_year(array , array_of_Month_MaxMountRainfall_Per_Year);
    print_unsigned_int_array(array_of_Month_MaxMountRainfall_Per_Year , YEARS);

    return (EXIT_SUCCESS);
}
