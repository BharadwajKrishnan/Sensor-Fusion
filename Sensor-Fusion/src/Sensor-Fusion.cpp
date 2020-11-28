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
	vector<long long>::iterator itr;
	for(itr = lidar_ts.begin(); itr != lidar_ts.end(); itr++)
	{
		radar_database.get_from_timestamp(*itr);
	}


	//Initialize the filter with first measurement data
	CKalmanFilter kf;

	cout <<"All ok" <<endl;

	return 0;
}
