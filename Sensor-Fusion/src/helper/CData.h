/*
 * CData.h
 *
 *  Created on: 22-Nov-2020
 *      Author: Bharadwaj
 */

#ifndef HELPER_CDATA_H_
#define HELPER_CDATA_H_

#include <fstream>
#include <list>

#include <bits/stdc++.h>

#include "CLidar.h"
#include "CRadar.h"

using namespace std;

template<class T>
class CData
{
private:
	list<T> m_data;
	fstream m_file;

	CDatabase<CLidar>* m_lidar_db;
	CDatabase<CRadar>* m_radar_db;

public:
	CData()
	{

	}

	// Connect to database
	void connectToDatabase(CDatabase<CLidar>* lidar_db, CDatabase<CRadar>* radar_db)
	{
		m_lidar_db = lidar_db;
		m_radar_db = radar_db;
	}

	// Read sensor data from file
	void read()
	{
		string line;

		m_file.open("C:/GitRepo/Some_Interesting_Projects/Sensor-Fusion/Sensor-Fusion/src/helper/sample-laser-radar-measurement-data-1.txt", ios::in);
		while(getline(m_file, line))
		{
			string sensor;
			string x, y, lidar_timestamp;
			string ro, phi, ro_dot, radar_timestamp;
			m_file>> sensor;

			if(sensor == "L")
			{
				double temp_x, temp_y;
				long double t;

				// Read Lidar data
				m_file>> x >> y >> lidar_timestamp;

				// Convert from string to float
				temp_x = std::atof(x.c_str());
				temp_y = std::atof(y.c_str());
				t = (long double)std::atof(lidar_timestamp.c_str());

				// Create lidar object
				CLidar lidar(temp_x, temp_y, t);

				// Add to database
				m_lidar_db->addSensorData(lidar);

			}
			else if(sensor == "R")
			{
				double temp_ro, temp_phi, temp_ro_dot;
				long double t;

				// Read Radar data
				m_file>> ro >> phi >> ro_dot >> radar_timestamp;

				// Convert from string to float
				temp_ro = std::atof(ro.c_str());
				temp_phi = std::atof(phi.c_str());
				temp_ro_dot = std::atof(ro_dot.c_str());
				t = (long double)std::atof(radar_timestamp.c_str());

				// Create radar object
				CRadar radar(temp_ro, temp_phi, temp_ro_dot, t);

				// Add to database
				m_radar_db->addSensorData(radar);
			}
			else
			{
				// Do nothing
			}

		}

		m_file.close();
	}
};

#endif /* HELPER_CDATA_H_ */
