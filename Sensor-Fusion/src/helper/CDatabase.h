//============================================================================
// Name        : CDatabase.h
// Author      : Bharadwaj Krishnan
// Version     : -
// Copyright   : Your copyright notice
// Description : Template database to hold sensor data
//============================================================================

#ifndef HELPER_CDATABASE_H_
#define HELPER_CDATABASE_H_

#include <iostream>
#include <list>
#include <vector>
#include "CLidar.h"
#include "CRadar.h"

using namespace std;

template<class T>
class CDatabase
{
private:
	list<T> m_database;

public:
	CDatabase()
	{

	}

	// Add sensor data to database
	void addSensorData(T data)
	{
		m_database.push_back(data);
	}

	// Print database
	void print()
	{
		typename list<T>::iterator itr;

		for(itr = m_database.begin(); itr != m_database.end(); itr++)
		{
			itr->print();
		}
	}

	void operator=(CRadar data)
	{
		this->update_data(data);
	}

	// Get corresponding data from a timestamp
	T get_from_timestamp(long long timestamp)
	{
		T data;

		typename list<T>::iterator itr;
		for(itr = m_database.begin(); itr != m_database.end(); itr++)
		{
			// Check if we have data with corresponding timestamp
			if(itr->get_timestamp() == timestamp)
			{
				data = *itr;

				return data;
			}
		}

		cout<< "Timstamp " << timestamp << " does not exist" <<endl;
	}

	// Get all timestamps recorded
	vector<long long> get_timestamps()
	{
		vector<long long> timestamps;

		typename list<T>::iterator itr;

		for(itr = m_database.begin(); itr != m_database.end(); itr++)
		{
			timestamps.push_back(itr->get_timestamp());
		}

		return timestamps;
	}
};

#endif /* HELPER_CDATABASE_H_ */
