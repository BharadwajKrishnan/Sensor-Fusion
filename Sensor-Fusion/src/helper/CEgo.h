/*
 * CEgo.h
 *
 *  Created on: 10-Jan-2021
 *      Author: Bharadwaj
 */

#ifndef HELPER_CEGO_H_
#define HELPER_CEGO_H_

class CEgo
{
private:
	float m_pos_x;
	float m_pos_y;

	float m_vel_x;
	float m_vel_y;

	float m_acc_x;
	float m_acc_y;

	long long m_timestamp;
public:
	CEgo(float x=0.0, float y=0.0, float v_x=0.0, float v_y=0.0, float a_x=0.0, float a_y=0.0, long long t=0);

	void print();

	float get_pos_x();

	float get_pos_y();

	float get_vel_x();

	float get_vel_y();

	long long get_timestamp();
};

#endif /* HELPER_CEGO_H_ */
