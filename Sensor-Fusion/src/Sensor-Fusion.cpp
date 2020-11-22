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

	lidar_database.print();

	return 0;
}
