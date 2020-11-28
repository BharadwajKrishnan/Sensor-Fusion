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
	double m_meas_x;
	double m_meas_y;
	long long m_timestamp;

public:
	CLidar(double x=0.0, double y=0.0, long long timestamp=0.0);

	// Print object details
	void print();

	// Return's timestamp
	long long get_timestamp();
};

#endif /* HELPER_CLIDAR_H_ */
