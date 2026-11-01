
#include <stdio.h>
#include <stdlib.h>
#include "sensor.h"

void generate_sensor_data(SensorData *sensor)
{
    sensor->temperature = 40.0f + (rand() % 50);
    sensor->vibration = 1.0f + (rand() % 10);
    sensor->pressure = 90.0f + (rand() % 30);
}

MachineStatus analyse_sensor_data(
    const SensorData *sensor)
{
    if (sensor->temperature >= 80.0f ||
        sensor->vibration >= 9.0f ||
        sensor->pressure >= 115.0f)
    {
        return STATUS_CRITICAL;
    }

    if (sensor->temperature >= 70.0f ||
        sensor->vibration >= 7.0f ||
        sensor->pressure >= 110.0f)
    {
        return STATUS_WARNING;
    }

    return STATUS_NORMAL;
}

void display_sensor_data(
    const SensorData *sensor,
    MachineStatus status)
{
    printf("\nTemperature: %.2f C\n",
           sensor->temperature);

    printf("Vibration: %.2f mm/s\n",
           sensor->vibration);

    printf("Pressure: %.2f PSI\n",
           sensor->pressure);

    switch (status)
    {
        case STATUS_NORMAL:
            printf("Machine Status: NORMAL\n");
            break;

        case STATUS_WARNING:
            printf("Machine Status: WARNING\n");
            break;

        case STATUS_CRITICAL:
            printf("Machine Status: CRITICAL\n");
            break;
    }

    printf("-----------------------------\n");
}
