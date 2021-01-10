//============================================================================
// Name        : CVMotionModel.h
// Author      : Bharadwaj
// Version     : -
// Copyright   : Your copyright notice
// Description : Class Declaration for a Constant Velocity Motion Model
//============================================================================

#ifndef APPLICATION_MOTION_MODELS_CVMOTIONMODEL_H_
#define APPLICATION_MOTION_MODELS_CVMOTIONMODEL_H_

#include "../../helper/Matrix.h"
#include "MotionModel.h"

class CVMotionModel : MotionModel
{

public:
	CVMotionModel();

	void predict(Matrix<float, 4, 1>& x, float deltaTime, Matrix<float, 4, 1>& outX, Matrix<float, 4, 4>& outP) override;

	void init() override;

	void update_F_and_Q(float deltaTime) override;

	Matrix<float, 4, 4>& getF() override;

	Matrix<float, 4, 4>& getQ() override;

};

#endif /* APPLICATION_MOTION_MODELS_CVMOTIONMODEL_H_ */
