//============================================================================
// Name        : MotionModel.h
// Author      : Bharadwaj
// Version     : -
// Copyright   : Your copyright notice
// Description : Abstract class for a Motion Model
//============================================================================

#ifndef APPLICATION_MOTION_MODELS_MOTIONMODEL_H_
#define APPLICATION_MOTION_MODELS_MOTIONMODEL_H_

#include "../../helper/Matrix.h"

class MotionModel
{
protected:
	Matrix<float, 4, 4> m_F;	// State Transition Matrix
	Matrix<float, 4, 4> m_F_T;	// Transpose of State Transition Matrix

	Matrix<float, 4, 4> m_Q;	// Process Noise Covariance Matrix

public:
	// Default Constructor
	MotionModel() = default;

	// Initialize the matrices
	virtual void init() = 0;

	// Update the matrix with deltaTime
	virtual void update_F_and_Q(float deltaTime) = 0;

	// Predict function for the Motion Model
	virtual void predict(Matrix<float, 4, 1>& x, float deltaTime, Matrix<float, 4, 1>& outX, Matrix<float, 4, 4>& outP) = 0;

	// Get State Transition Matrix
	virtual Matrix<float, 4, 4>& getF() = 0;

	// Get Process Noise Covariance Matrix
	virtual Matrix<float, 4, 4>& getQ() = 0;

};



#endif /* APPLICATION_MOTION_MODELS_MOTIONMODEL_H_ */
