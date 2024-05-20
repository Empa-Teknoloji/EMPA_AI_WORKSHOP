/*
 * EMPA_Sensor.c
 *
 *  Created on: May 19, 2024
 *      Author: bilalk
 */

#include "EMPA_Sensor.h"
#include "Empa_DataCollector.h"

extern SAI_HandleTypeDef hsai_BlockA1;
uint8_t counter_timer 	= 0;
uint8_t flag_working  	= 0;
uint16_t counter_state	= 0;
extern uint8_t Flag_DataCollector;
extern SensorMode sensor_mode;

//SHT4X Start

//SHT4X End

//ISM330IS Start

//ISM330IS End

//IMP34DT05 Start

//IMP34DT05 End

uint8_t EMPA_SensorInit(void)
{
//SHT4X Init Start

//SHT4X Init End

//ISM330IS Init Start

//ISM330IS Init End

//IMP34DT05 Init Start
	
//IMP34DT05 Init End
	return 0;

}

uint8_t EMPA_SensorProcess(void)
{
	// SHT40 Sensor Process Start

	// SHT40 Sensor Process End

	//ISM330IS Sensor Process Start

	//ISM330IS Sensor Process End

	//IMP34DT05 Sensor Process Start

	//IMP34DT05 Sensor Process End

	return 0;
}

void EMPA_SensorPrint(void)
{
	//Print Start

    //Print End

	//SHT40 Print Start

	//SHT40 Print End

	//ISM330IS Print Start

	//ISM330IS Print End

	//IMP34DT05 Print Start

	//IMP34DT05 Print End
}

uint8_t sht40_sensor_process(int32_t* temp, int32_t* hum)
{
	if (sht4x_measure_high_precision(temp, hum) == 0) {
		return 0;
	} else
		return 1;
}

uint8_t ism330_sensor_process(imu_data *sensor_data) {
	ISM330IS_Axes_t ism330_axes;
	if (ISM330IS_ACC_GetAxes(&ism330_obj_o, &ism330_axes) == 0) {
		sensor_data->acc.x = ism330_axes.x;
		sensor_data->acc.y = ism330_axes.y;
		sensor_data->acc.z = ism330_axes.z;
	} else
		return 1;

	if (ISM330IS_GYRO_GetAxes(&ism330_obj_o, &ism330_axes) == 0) {
		sensor_data->gyro.x = ism330_axes.x/100;
		sensor_data->gyro.y = ism330_axes.y/100;
		sensor_data->gyro.z = ism330_axes.z/100;
	} else
		return 1;
	return 0;
}

uint8_t imp34_sensor_process(void)
{
	if (HAL_SAI_DMAResume(&hsai_BlockA1) != HAL_OK) {
		return 1;
	}
	while(AUDIO_MODE == 0);

	return 0;
}

