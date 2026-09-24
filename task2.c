#include <stdio.h>
#include <ctype.h>

float convert_to_celsius(float temp, char scale) {
    if (scale == 'C' || scale == 'c') {
        return temp;
    } else if (scale == 'F' || scale == 'f') {
        return (temp - 32.0) * (5.0 / 9.0);
    } else if (scale == 'K' || scale == 'k') {
        return temp - 273.15;
    }
    return -999.0;
}

float convert_from_celsius(float celsius, char target_scale) {
    if (target_scale == 'C' || target_scale == 'c') {
        return celsius;
    } else if (target_scale == 'F' || target_scale == 'f') {
        return (celsius * (9.0 / 5.0)) + 32.0;
    } else if (target_scale == 'K' || target_scale == 'k') {
        return celsius + 273.15;
    }
    return -999.0;
}

void print_advisory(float celsius) {
    if (celsius < 0.0) {
        printf("Temperature category: Freezing\n");
        printf("Weather advisory: Wear a heavy coat!\n");
    } else if (celsius >= 0.0 && celsius < 10.0) {
        printf("Temperature category: Cold\n");
        printf("Weather advisory: Wear a jacket.\n");
    } else if (celsius >= 10.0 && celsius < 25.0) {
        printf("Temperature category: Comfortable\n");
        printf("Weather advisory: You should feel comfortable.\n");
    } else if (celsius >= 25.0 && celsius < 35.0) {
        printf("Temperature category: Hot\n");
        printf("Weather advisory: Drink lots of water!\n");
    } else {
        printf("Temperature category: Extreme Heat\n");
        printf("Weather advisory: Stay indoors!\n");
    }
}

int main() {
    float temp, converted_temp, temp_in_celsius;
    char original_scale, target_scale;

    printf("Enter the temperature value: ");
    if (scanf("%f", &temp) != 1) {
        printf("Invalid temperature input.\n");
        return 1;
    }

    printf("Enter the original scale (C, F, or K): ");
    scanf(" %c", &original_scale);

    printf("Enter the scale to convert to (C, F, or K): ");
    scanf(" %c", &target_scale);

    // Input Validation for Kelvin
    if ((original_scale == 'K' || original_scale == 'k') && temp < 0.0) {
        printf("Invalid input: Kelvin temperature cannot be negative.\n");
        return 1;
    }

    temp_in_celsius = convert_to_celsius(temp, original_scale);
    if (temp_in_celsius == -999.0) {
        printf("Invalid original scale entered.\n");
        return 1;
    }

    // Absolute zero check in Celsius
    if (temp_in_celsius < -273.15) {
        printf("Invalid input: Temperature is below absolute zero.\n");
        return 1;
    }

    converted_temp = convert_from_celsius(temp_in_celsius, target_scale);
    if (converted_temp == -999.0) {
        printf("Invalid target scale entered.\n");
        return 1;
    }

    printf("Converted temperature: %.2f %c\n", converted_temp, toupper(target_scale));
    print_advisory(temp_in_celsius);

    return 0;
}