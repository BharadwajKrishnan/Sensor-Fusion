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
	Matrix<double, 4, 1> m_state_vector;
	Matrix<double, 4, 4> m_A;	// State Transition matrix
public:
	CKalmanFilter();

	void print_state_vector();

	// Predict operation
	void predict();

	void update_state_matrix(double data, int row, int col);

};



#endif /* APPLICATION_CKALMANFILTER_H_ */
