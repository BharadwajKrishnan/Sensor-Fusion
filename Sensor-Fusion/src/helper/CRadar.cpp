/*
 * CRadarData.cpp
 *
 *  Created on: 22-Nov-2020
 *      Author: Bharadwaj
 */
#include <iostream>
using namespace std;


#include "CRadar.h"

CRadar::CRadar(float r, float phi, float r_dot, long long timestamp)
{
	this->m_rho = r;
	this->m_phi = phi;
	this->m_rho_dot = r_dot;
	this->m_timestamp = timestamp;
}

void CRadar::print()
{
	cout<< "Timestamp = " <<this->m_timestamp <<endl;
	cout<< "Rho = " <<this->m_rho <<endl;
	cout<< "Phi = " <<this->m_phi <<endl;
	cout<< "Rho_dot = " <<this->m_rho_dot <<endl;
}

long long CRadar::get_timestamp()
{
	return this->m_timestamp;
}

void CRadar::update_data(CRadar data)
{
	this->m_rho = data.m_rho;
	this->m_phi = data.m_phi;
	this->m_rho_dot = data.m_rho_dot;
	this->m_timestamp = data.m_timestamp;
}

