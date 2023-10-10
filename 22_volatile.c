#include <stdio.h>
typedef struct SENSOR
{
    int sensor_flag; /* if sensed 1, else 0 */
    int data;
} SENSOR;

int main()
{
    volatile SENSOR *sensor;  // with volatile, we can remove the optimization option
    while (!(sensor->sensor_flag)) {}
    printf("Data : %d\n", sensor->data);
    return 0;
}