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

	// Update state transition matrix as Identity
	this->m_A.set_Identity();
	this->m_A_T.set_Identity();

	// Initialize process error covariance matrix, Measurement Noise Covariance matrix and Process Noise Covariance matrix
	this->initialize_process_noise_covariance_matrix();
	this->initialize_R();
	this->initialize_Q();

	// Update observation matrix
	this->m_H.set_Identity();
	this->m_H_T.set_Identity();
}

void CKalmanFilter::initialize_state_matrix(float x, float y, float vel_x, float vel_y)
{
	vector<vector <float> > state_matrix;
	vector <float> pos_x, pos_y, velocity_x, velocity_y;

	pos_x.push_back(x); pos_y.push_back(y); velocity_x.push_back(vel_x); velocity_y.push_back(vel_y);
	state_matrix.push_back(pos_x); state_matrix.push_back(pos_y); state_matrix.push_back(velocity_x); state_matrix.push_back(velocity_y);
	this->m_X.change_data(state_matrix);
}

void CKalmanFilter::initialize_process_noise_covariance_matrix()
{
	this->m_P.set_Identity();

	this->m_P.change_data(constants::init_var_pos_x, 0, 0);
	this->m_P.change_data(constants::init_var_pos_y, 1, 1);
	this->m_P.change_data(constants::init_var_vel_x, 2, 2);
	this->m_P.change_data(constants::init_var_vel_y, 3, 3);
}

void CKalmanFilter::initialize_R()
{
	this->m_R.set_Identity();

	this->m_R.change_data(constants::meas_var_pos_x, 0, 0);
	this->m_R.change_data(constants::meas_var_pos_y, 1, 1);
	this->m_R.change_data(constants::meas_var_vel_x, 2, 2);
	this->m_R.change_data(constants::meas_var_vel_y, 3, 3);
}

void CKalmanFilter::initialize_Q()
{
	this->m_Q.set_Identity();

	this->m_Q.change_data(constants::process_var_pos_x, 0, 0);
	this->m_Q.change_data(constants::process_var_pos_y, 1, 1);
	this->m_Q.change_data(constants::process_var_vel_x, 2, 2);
	this->m_Q.change_data(constants::process_var_vel_y, 3, 3);
}

void CKalmanFilter::print_state_vector()
{
	cout<< "State Vector" <<endl;
	this->m_X.print();
}

void CKalmanFilter::print_state_transition_vector()
{
	cout<< "State Transition Matrix" <<endl;
	this->m_A.print();
}

void CKalmanFilter::predict()
{
	// X(k) = A*X(k-1)
	// P(k) = A*P(k-1)*A.T

	// X(k) = A*X(k-1)

	vector<vector<float> > x = this->m_A * this->m_X;
	this->m_X_kp.change_data(x);

	// P(k) = A*P(k-1)*A.T

	Matrix<float, 4, 4> Prd;
	{
		vector<vector<float> > temp = this->m_A * this->m_P;
		Prd.change_data(temp);
	}

	{
		vector<vector<float> > prd_2 = Prd * this->m_A_T;
		this->m_P.change_data(prd_2);
	}

}

void CKalmanFilter::update()
{
	// Calculate the Kalman gain
	// K = P(k)*H * (H*P(k)*H.T + R)^-1
	vector<vector<float> > var_1 = this->m_P * this->m_H;

	Matrix<float, 4, 4> Temp;
	{
		vector<vector<float> > temp_1 = this->m_H * this->m_P;
		Temp.change_data(temp_1);
	}

	{
		vector<vector<float> > temp_2 = Temp * this->m_H_T;
		Temp.change_data(temp_2);
	}

	{
		vector<vector<float> > inv = Temp.inverse();
		Temp.change_data(inv);
	}



	Temp.print();

}







