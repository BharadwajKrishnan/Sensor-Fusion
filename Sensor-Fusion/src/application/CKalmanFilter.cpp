/*
 * CKalmanFilter.cpp
 *
 *  Created on: 27-Nov-2020
 *      Author: Bharadwaj
 */

#include "CKalmanFilter.h"

CKalmanFilter::CKalmanFilter()
{

}

void CKalmanFilter::print_state_vector()
{
	this->m_state_vector.print();
}

void CKalmanFilter::update_state_matrix(double data, int row, int col)
{
	this->m_state_vector.change_datas(data, row, col);
}


