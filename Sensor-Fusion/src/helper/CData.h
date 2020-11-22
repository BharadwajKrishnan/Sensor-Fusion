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

public:
	CData()
	{

	}

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


				// Lidar data
				m_file>> x >> y >> lidar_timestamp;

				temp_x = std::atof(x.c_str());
				temp_y = std::atof(y.c_str());
				t = (long double)std::atof(lidar_timestamp.c_str());

				CLidar lidar(temp_x, temp_y, t);


			}
			else if(sensor == "R")
			{
				// Radar data
				m_file>> ro >> phi >> ro_dot >> radar_timestamp;

				CRadar radar;
			}
			else
			{
				cout << "Unidentified Sensor" <<endl;
			}

		}

		m_file.close();
	}
};

#endif /* HELPER_CDATA_H_ */
