/*
 * CRadarData.cpp
 *
 *  Created on: 22-Nov-2020
 *      Author: Bharadwaj
 */
#include <iostream>
using namespace std;


#include "CRadar.h"

CRadar::CRadar(double r, double phi, double r_dot, long double timestamp)
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

