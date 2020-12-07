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
	long long m_timestamp;

public:
	CLidar(float x=0.0, float y=0.0, long long timestamp=0.0);

	// Print object details
	void print();

	// Returns timestamp
	long long get_timestamp();

	// Returns pos_x
	float get_pos_x();

	// Returns pos_y
	float get_pos_y();
};

#endif /* HELPER_CLIDAR_H_ */
