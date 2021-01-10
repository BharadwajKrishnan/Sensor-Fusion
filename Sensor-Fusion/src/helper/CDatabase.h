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
#include "CLidar.h"
#include "CEgo.h"

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
};

#endif /* HELPER_CDATABASE_H_ */
