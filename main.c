


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sensor.h"

int main(void)
{
    srand((unsigned int)time(NULL));

    SensorData machine_sensor;

    printf("INDUSTRIAL MACHINE MONITOR\n");

    for (int i = 0; i < 10; i++)
    {
        generate_sensor_data(&machine_sensor);

        MachineStatus status =
            analyse_sensor_data(&machine_sensor);

        printf("\nReading %d\n", i + 1);

        display_sensor_data(
            &machine_sensor,
            status
        );
    }

    return 0;
}
