/*
 * CRadarData.h
 *
 *  Created on: 22-Nov-2020
 *      Author: Bharadwaj
 */

#ifndef HELPER_CRADAR_H_
#define HELPER_CRADAR_H_

class CRadar
{
private:
	double m_rho;
	double m_phi;
	double m_rho_dot;
	long long m_timestamp;

public:
	CRadar(double r=0.0, double phi=0.0, double r_dot=0.0, long long timestamp=0.0);

	// Print object details
	void print();

	// Return's timestamp
	long long get_timestamp();

	// Update radar signals
	void update_data(CRadar data);


};

#endif /* HELPER_CRADAR_H_ */
