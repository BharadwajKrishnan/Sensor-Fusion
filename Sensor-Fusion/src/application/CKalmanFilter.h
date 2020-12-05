/*
 * CKalmanFilter.h
 *
 *  Created on: 27-Nov-2020
 *      Author: Bharadwaj
 */

#ifndef APPLICATION_CKALMANFILTER_H_
#define APPLICATION_CKALMANFILTER_H_

#include "../helper/Matrix.h"

class CKalmanFilter
{
private:
	Matrix<float, 4, 1> m_state_vector;
	Matrix<float, 4, 4> m_A;	// State Transition matrix
	Matrix<float, 4, 4> m_A_T;	// Transpose of State Transition matrix
	Matrix<float, 4, 4> m_P;	// Process Noise Co-variance matrix

	float m_deltaTime;
public:
	CKalmanFilter(float x=0.0, float y=0.0, float vel_x=0.0, float vel_y=0.0);

	void print_state_vector();

	void print_state_transition_vector();

	// Predict operation
	void predict();

	void update_state_matrix(float data, int row, int col);

	void update_state_transition_matrix(float data, int row, int col);

	void update_process_noise_covariance_matrix(float data, int row, int col);

};



#endif /* APPLICATION_CKALMANFILTER_H_ */
