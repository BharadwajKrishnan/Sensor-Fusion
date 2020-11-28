//============================================================================
// Name        : Matrix.h
// Author      : Bharadwaj Krishnan
// Version     : -
// Copyright   : Your copyright notice
// Description : Template class for a Matrix
//============================================================================

#ifndef HELPER_MATRIX_H_
#define HELPER_MATRIX_H_

#include <iostream>

#include <vector>
using namespace std;

//============================================================================
// Name        : Matrix.h
// Author      : Bharadwaj
// Version     : -
// Copyright   : -
// Description : Template class definition of a Matrix
//============================================================================


template<class T, int ROWS, int COLUMNS>
class Matrix
{
private:
	vector<vector<T> > m_data;

public:
	Matrix()
	{
		vector<T> column;
		for(int i = 0; i < COLUMNS; i++)
		{
			column.push_back(i);
		}

		for(int i=0; i < ROWS; i++)
		{
			m_data.push_back(column);
		}
	}


	// Add data to the vector
	void add(T data)
	{
		// Add elements into the matrix
		m_data.push_back(data);
	}

	// Print the vector data
	void print()
	{
		typename vector<T>::iterator itr;
		cout<< "[" <<endl;

		for(int i = 0; i < ROWS; i++)
		{
			cout<< "[";
			for(itr = this->m_data[i].begin(); itr != this->m_data[i].end(); itr++)
			{
				cout << *itr;
			}

			cout<< "]" <<endl;
		}
		cout<< "]" <<endl;
	}
};



#endif /* HELPER_MATRIX_H_ */
