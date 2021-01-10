/*
 * CEgo.cpp
 *
 *  Created on: 10-Jan-2021
 *      Author: Bharadwaj
 */
#include <iostream>

using namespace std;

#include "CEgo.h"

CEgo::CEgo(float x, float y, float v_x, float v_y, float a_x, float a_y, long long t)
{
	m_pos_x = x;
	m_pos_y = y;

	m_vel_x = v_x;
	m_vel_y = v_y;

	m_acc_x = a_x;
	m_acc_y = a_y;

	m_timestamp = t;

}

void CEgo::print()
{
	cout<< "Timestamp = " <<this->m_timestamp <<endl;
	cout<< "PosX = " <<this->m_pos_x <<endl;
	cout<< "PosY = " <<this->m_pos_y <<endl;
	cout<< "VelX = " <<this->m_vel_x <<endl;
	cout<< "VelY = " <<this->m_vel_y <<endl;
	cout<< "AccX = " <<this->m_acc_x <<endl;
	cout<< "AccY = " <<this->m_acc_y <<endl;
}

float CEgo::get_pos_x()
{
	return m_pos_x;
}

float CEgo::get_pos_y()
{
	return m_pos_y;
}

float CEgo::get_vel_x()
{
	return m_vel_x;
}

float CEgo::get_vel_y()
{
	return m_vel_y;
}

long long CEgo::get_timestamp()
{
	return m_timestamp;
}
