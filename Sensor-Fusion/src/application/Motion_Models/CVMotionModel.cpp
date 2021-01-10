//============================================================================
// Name        : CVMotionModel.cpp
// Author      : Bharadwaj
// Version     : -
// Copyright   : Your copyright notice
// Description : Class Definition for a Constant Velocity Motion Model
//============================================================================

#include "CVMotionModel.h"
#include "../../helper/constants.h"

using namespace std;

/*
 * F = [[1, 0, dt, 0],
 * 		[0, 1, 0, dt],
 * 		[0, 0, 1, 0],
 * 		[0, 0, 0, 1]]
 */

CVMotionModel::CVMotionModel()
{
	// Initialize matrices
	init();
}

void CVMotionModel::predict(Matrix<float, 4, 1>& x, float deltaTime, Matrix<float, 4, 1>& outX, Matrix<float, 4, 4>& outP)
{
	this->update_F_and_Q(deltaTime);

	outX = this->m_F * x;

	Matrix<float, 4, 4> temp;
	temp = this->m_F * outP;

	outP = temp * this->m_F_T;

	outP = outP + this->m_Q;

}

void CVMotionModel::init()
{
	// Update state transition matrix as Identity
	this->m_F.set_Identity();
	this->m_F_T.set_Identity();

	this->m_F_T.transpose();
}

void CVMotionModel::update_F_and_Q(float deltaTime)
{
	// Update F
	this->m_F.set_data(deltaTime, 0, 2);
	this->m_F.set_data(deltaTime, 1, 3);

	this->m_F_T.set_data(deltaTime, 2, 0);
	this->m_F_T.set_data(deltaTime, 3, 1);

	// Update Q
	float dt_2 = deltaTime * deltaTime;
	float dt_3 = dt_2 * deltaTime;
	float dt_4 = dt_3 * deltaTime;

	this->m_Q.set_data(dt_4/4.0, 0, 0);
	this->m_Q.set_data(dt_3/2.0, 0, 2);
	this->m_Q.set_data(dt_4/4.0, 1, 1);
	this->m_Q.set_data(dt_3/2.0, 1, 3);
	this->m_Q.set_data(dt_3/2.0, 2, 0);
	this->m_Q.set_data(dt_2, 2, 2);
	this->m_Q.set_data(dt_3/2.0, 3, 1);
	this->m_Q.set_data(dt_2, 3, 3);
}

Matrix<float, 4, 4>& CVMotionModel::getF()
{
	return m_F;
}

Matrix<float, 4, 4>& CVMotionModel::getQ()
{
	return m_Q;
}

