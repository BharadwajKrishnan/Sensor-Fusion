/*
 * CLidarData.cpp
 *
 *  Created on: 22-Nov-2020
 *      Author: Bharadwaj
 */

#include <iostream>
using namespace std;

#include "CLidar.h"

CLidar::CLidar(float x, float y, long long timestamp)
{
	this->m_meas_x = x;
	this->m_meas_y = y;
	this->m_timestamp = timestamp;
}

void CLidar::print()
{
	cout<< "Timestamp = " <<this->m_timestamp <<endl;
	cout<< "Meas_X = " <<this->m_meas_x <<endl;
	cout<< "Meas_Y = " <<this->m_meas_y <<endl;
}

long long CLidar::get_timestamp()
{
	return this->m_timestamp;
}

float CLidar::get_pos_x()
{
	return this->m_meas_x;
}

float CLidar::get_pos_y()
{
	return this->m_meas_y;
}

