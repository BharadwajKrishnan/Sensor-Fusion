//============================================================================
// Name        : CKalmanFilter.h
// Author      : Bharadwaj
// Version     : -
// Copyright   : Your copyright notice
// Description : Class Declaration for a Linear Kalman filter
//============================================================================

#ifndef APPLICATION_CKALMANFILTER_H_
#define APPLICATION_CKALMANFILTER_H_

#include "../helper/constants.h"
#include "../helper/Matrix.h"
#include "Motion_Models/CVMotionModel.h"

class CKalmanFilter
{
private:
	Matrix<float, 4, 1> m_X;
	Matrix<float, 4, 1> m_X_kp;

	Matrix<float, 4, 4> m_P;	// Process Noise Co-variance matrix

	Matrix<float, 4, 4> m_H;	// Observation matrix
	Matrix<float, 4, 4> m_H_T;	// Transpose of Observation matrix

	Matrix<float, 4, 4> m_R;	// Measurement Noise Covariance Matrix

	Matrix<float, 4, 4> m_K;	// Kalman gain

	Matrix<float, 4, 1> m_Z;	// Measurement Input

	CVMotionModel model;

	// Init Methods
	void initialize_state_matrix(float x, float y, float vel_x, float vel_y);
	void initialize_process_noise_covariance_matrix();
	void initialize_R();

	void calculate_kalman_gain();




public:
	CKalmanFilter(float x=0.0, float y=0.0, float vel_x=0.0, float vel_y=0.0);

	// Predict operation
	void predict(float deltaTime);

	// Update operation
	void update(float pos_x, float pos_y, float vel_x, float vel_y);

	// Update X_k and X_kp
	void update_state_transition_matrix(float data, int row, int col);

	void update_observation_matrix(float data, int row, int col);

	Matrix<float, 4, 1> get_estimate();

};



#endif /* APPLICATION_CKALMANFILTER_H_ */
