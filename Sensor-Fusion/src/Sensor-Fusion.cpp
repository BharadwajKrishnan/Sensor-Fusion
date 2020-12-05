//============================================================================
// Name        : Sensor-Fusion.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include "helper/CDatabase.h"
#include "helper/CData.h"

#include "application/CKalmanFilter.h"

int main()
{
	// Database to store sensor data
	CDatabase<CLidar> lidar_database;
	CDatabase<CRadar> radar_database;

	// Declare object to read sensor data from file
	CData<float> sensor_data;

	// Connect to database
	sensor_data.connectToDatabase(&lidar_database, &radar_database);

	// Read Data from file
	sensor_data.read();

	// Get list of all timestamps stored in database
	vector<long long> lidar_ts, radar_ts;
	lidar_ts = lidar_database.get_timestamps();
	radar_ts = radar_database.get_timestamps();

	// Get first Lidar measurement
	CLidar lidar_obj = lidar_database.get_from_timestamp(lidar_ts[0]);

	//Initialize the filter with first measurement data
	CKalmanFilter kf(lidar_obj.get_pos_x(), lidar_obj.get_pos_y());

//	kf.print_state_vector();
//	kf.print_state_transition_vector();

	kf.predict();



	cout <<"All ok" <<endl;

	return 0;
}
