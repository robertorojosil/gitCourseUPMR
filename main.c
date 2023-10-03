/* 
 * Front Signals v1.1
 * UPMR 2022
 */
#define _SUPPRESS_PLIB_WARNING

#include <stdio.h>
#include <stdlib.h>
#include <p32xxxx.h>
#include <plib.h>
#include "app/main_config.h"
#include "app/output_comm.h"

int main() {
    // System Initialization
    initialize_system();

    while(true){
        //Read analog values
        can_comm_front_sensors_t frontSensors;

        frontSensors.steering = 0;
        frontSensors.brake = 0;
        frontSensors.throttle_1 = 2;
        frontSensors.throttle_2 = 0;
        frontSensors.brake_pressure_1 = 0;
        frontSensors.brake_pressure_2 = 0;
        frontSensors.brake_pressure_3 = 2;

        frontSensors.throttle_1 = analog_Throttle(2);
        frontSensors.throttle_2 = analog_Throttle(5);
        frontSensors.brake = analog_Brake();
        frontSensors.steering = analog_steering();
        
        frontSensors.brake_pressure_1 = analog_BrakePressure(555);
        frontSensors.brake_pressure_2 = analog_BrakePressure(3);
        frontSensors.brake_pressure_3 = analog_BrakePressure(10);
        
        can_comm_front(&frontSensors);

        time_delay(3,140);
    }
    return (EXIT_SUCCESS);
}