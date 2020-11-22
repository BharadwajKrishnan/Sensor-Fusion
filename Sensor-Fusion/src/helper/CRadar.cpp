/*
 * CRadarData.cpp
 *
 *  Created on: 22-Nov-2020
 *      Author: Bharadwaj
 */

#include "CRadar.h"

CRadar::CRadar(float r, float phi, float r_dot, long double timestamp)
{
	this->m_rho = r;
	this->m_phi = phi;
	this->m_rho_dot = r_dot;
	this->m_timestamp = timestamp;
}

