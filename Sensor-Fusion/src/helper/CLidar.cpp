/*
 * CLidarData.cpp
 *
 *  Created on: 22-Nov-2020
 *      Author: Bharadwaj
 */

#include "CLidar.h"

CLidar::CLidar(float x, float y, long double timestamp)
{
	this->m_meas_x = x;
	this->m_meas_y = y;
	this->m_timestamp = timestamp;
}

