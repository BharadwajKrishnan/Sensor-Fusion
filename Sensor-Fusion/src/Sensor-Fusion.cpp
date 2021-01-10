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
	CDatabase<CEgo> ego_database;

	// Declare object to read sensor data from file
	CData<float> data;

	// Connect to database
	data.connectToDatabase(&lidar_database, &radar_database, &ego_database);

	// Read Data from file
	data.read();

	data.read_ego();

	// Get list of all timestamps stored in database
	vector<long long> ego_ts;
	ego_ts = ego_database.get_timestamps();

	// Get first Lidar measurement
	CEgo ego = ego_database.get_from_timestamp(ego_ts[0]);

	//Initialize the filter with first measurement data
	CKalmanFilter kf(ego.get_pos_x(), ego.get_pos_y(), ego.get_vel_x(), ego.get_vel_y());

	vector<Matrix<float, 4, 1> > output;

	for(int iteration = 1; iteration < ego_database.size(); iteration++)
	{
		// Compute delta time
		float deltaTime = static_cast<float>((ego_ts[iteration] - ego_ts[iteration - 1])/1000000000.0);

		ego = ego_database.get_from_timestamp(ego_ts[iteration]);

		kf.predict(deltaTime);

		kf.update(ego.get_pos_x(), ego.get_pos_y(), ego.get_vel_x(), ego.get_vel_y());

		output.push_back(kf.get_estimate());
	}

	data.write(output);

	cout <<"All ok" <<endl;

	return 0;
}
