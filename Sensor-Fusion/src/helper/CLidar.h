/*
 * CLidarData.h
 *
 *  Created on: 22-Nov-2020
 *      Author: Bharadwaj
 */

#ifndef HELPER_CLIDAR_H_
#define HELPER_CLIDAR_H_

class CLidar
{
private:
	float m_meas_x;
	float m_meas_y;
	long double m_timestamp;

public:
	CLidar(float x=0.0, float y=0.0, long double timestamp=0.0);
};

#endif /* HELPER_CLIDAR_H_ */
