//============================================================================
// Name        : CKalmanFilter.cpp
// Author      : Bharadwaj
// Version     : -
// Copyright   : Your copyright notice
// Description : Class Definition for a Linear Kalman filter
//============================================================================

#include "CKalmanFilter.h"

CKalmanFilter::CKalmanFilter(float x, float y, float vel_x, float vel_y)
{
	// Update state vector with initial measurement
	this->initialize_state_matrix(x, y, vel_x, vel_y);

	// Initialize process error covariance matrix
	this->initialize_process_noise_covariance_matrix();
	this->initialize_R();

	// Update observation matrix
	this->m_H.set_Identity();
	this->m_H_T.set_Identity();

	// this->m_X.print();
}

void CKalmanFilter::initialize_state_matrix(float x, float y, float vel_x, float vel_y)
{
	this->m_X.set_data(x, 0, 0);
	this->m_X.set_data(y, 1, 0);
	this->m_X.set_data(vel_x, 2, 0);
	this->m_X.set_data(vel_y, 3, 0);
}

void CKalmanFilter::initialize_process_noise_covariance_matrix()
{

	this->m_P.set_data(constants::init_var_pos_x, 0, 0);
	this->m_P.set_data(constants::init_var_pos_y, 1, 1);
	this->m_P.set_data(constants::init_var_vel_x, 2, 2);
	this->m_P.set_data(constants::init_var_vel_y, 3, 3);
}

void CKalmanFilter::initialize_R()
{
	this->m_R.set_data(constants::meas_var_pos_x, 0, 0);
	this->m_R.set_data(constants::meas_var_pos_y, 1, 1);
	this->m_R.set_data(constants::meas_var_vel_x, 2, 2);
	this->m_R.set_data(constants::meas_var_vel_y, 3, 3);
}

void CKalmanFilter::calculate_kalman_gain()
{
	// K = P(k)*H * (H*P(k)*H.T + R)^-1
//	Matrix<float, 4, 4> Prd_1, Prd_2;

//	Prd_1 = this->m_P * this->m_H;
//
//	Prd_2 = this->m_H * this->m_P;
//	Prd_2 = Prd_2 * this->m_H_T;
//
//	Prd_2 = Prd_2 + this->m_R;
//
//	this->m_K = Prd_1 * Prd_2;

	Matrix<float, 4, 4> out;
	out = this->m_P + this->m_R;

	out = out.inverse();

	this->m_K = this->m_P * out;

	this->m_K.print();
}

void CKalmanFilter::predict(float deltaTime)
{
	// X_p(k) = A*X(k-1)
	// P(k) = A*P(k-1)*A.T
	model.predict(this->m_X, deltaTime, this->m_X_kp, this->m_P);

	//this->m_X.print();
}

void CKalmanFilter::update(float pos_x, float pos_y, float vel_x, float vel_y)
{
	// Calculate the Kalman gain
	this->calculate_kalman_gain();

	// Correct the predicted state
	// X(k) = X_p(k) + K(Z - X_p(k))
	this->m_Z.set_data(pos_x, 0, 0);
	this->m_Z.set_data(pos_y, 1, 0);
	this->m_Z.set_data(vel_x, 2, 0);
	this->m_Z.set_data(vel_y, 3, 0);

	Matrix<float, 4, 1> innovation;
	innovation = this->m_Z - this->m_X_kp;

	Matrix<float, 4, 1> Prd;
	Prd = this->m_K * innovation;

	this->m_X = this->m_X_kp + Prd;

	//this->m_Z.print();

	// P(k) = (I - K*H)*P(k)
	Matrix<float, 4, 4> Identity;
	Identity.set_Identity();

	Matrix<float, 4, 4> temp;
	temp = Identity - this->m_K;

	this->m_P = temp * this->m_P;

}

Matrix<float, 4, 1> CKalmanFilter::get_estimate()
{
	return m_X;
}








