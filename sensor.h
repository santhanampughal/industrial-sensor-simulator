
#ifndef SENSOR_H
#define SENSOR_H

typedef struct
{
    float temperature;
    float vibration;
    float pressure;

} SensorData;

typedef enum
{
    STATUS_NORMAL,
    STATUS_WARNING,
    STATUS_CRITICAL

} MachineStatus;

void generate_sensor_data(SensorData *sensor);

MachineStatus analyse_sensor_data(
    const SensorData *sensor
);

void display_sensor_data(
    const SensorData *sensor,
    MachineStatus status
);

#endif
