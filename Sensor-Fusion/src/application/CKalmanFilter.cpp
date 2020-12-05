/*
 * CKalmanFilter.cpp
 *
 *  Created on: 27-Nov-2020
 *      Author: Bharadwaj
 */

#include "CKalmanFilter.h"

CKalmanFilter::CKalmanFilter(float x, float y, float vel_x, float vel_y)
{
	// Update state vector with initial measurement
	this->update_state_matrix(x, 0, 0);
	this->update_state_matrix(y, 1, 0);
	this->update_state_matrix(vel_x, 2, 0);
	this->update_state_matrix(vel_y, 3, 0);

	// Update state transition matrix as Identity
	this->update_state_transition_matrix(1, 0, 0);
	this->update_state_transition_matrix(1, 1, 1);
	this->update_state_transition_matrix(1, 2, 2);
	this->update_state_transition_matrix(1, 3, 3);

	// Update process noise covariance matrix
	this->update_process_noise_covariance_matrix(1, 0, 0);
	this->update_process_noise_covariance_matrix(1, 1, 1);
	this->update_process_noise_covariance_matrix(10, 2, 2);
	this->update_process_noise_covariance_matrix(10, 3, 3);

}

void CKalmanFilter::print_state_vector()
{
	cout<< "State Vector" <<endl;
	this->m_state_vector.print();
}

void CKalmanFilter::print_state_transition_vector()
{
	cout<< "State Transition Matrix" <<endl;
	this->m_A.print();
}

void CKalmanFilter::update_state_matrix(float data, int row, int col)
{
	this->m_state_vector.change_data(data, row, col);
}

void CKalmanFilter::update_state_transition_matrix(float data, int row, int col)
{
	this->m_A.change_data(data, row, col);
}

void CKalmanFilter::update_process_noise_covariance_matrix(float data, int row, int col)
{
	this->m_P.change_data(data, row, col);
}

void CKalmanFilter::predict()
{
	// X(k) = A*X(k-1)
	// P(k) = A*P(k-1)*A.T

	Matrix<float, 4, 1> X_k;
	Matrix<float, 4, 4> P_k;

	// X(k) = A*X(k-1)
	vector<vector<float> > prd = this->m_A * this->m_state_vector;

	// P(k) = A*P(k-1)*A.T
	//this->m_A.transpose();
	//this->m_A.print_transposed();

	this->m_A.print();
	X_k.change_data(prd[0][0], 0, 0);
	X_k.change_data(prd[1][0], 1, 0);
	X_k.change_data(prd[2][0], 2, 0);
	X_k.change_data(prd[3][0], 3, 0);

	X_k.print();



}





