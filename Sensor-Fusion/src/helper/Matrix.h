//============================================================================
// Name        : Matrix.h
// Author      : Bharadwaj Krishnan
// Version     : -
// Copyright   : Your copyright notice
// Description : Template class for a Matrix
//============================================================================

#ifndef HELPER_MATRIX_H_
#define HELPER_MATRIX_H_

#include <vector>
using namespace std;

/*
 * Matrix Representation
 *
 * m_data = [a, b, c ......]
 * Size = (N*1)
 */


template<class T>
class Matrix
{
private:
	vector<T> m_data;

public:
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
		cout<< "[" ;
		for(itr = m_data.begin(); itr != m_data.end(); itr++)
		{

			cout << *itr << " ";
		}
		cout<< "]" <<endl;
	}
};



#endif /* HELPER_MATRIX_H_ */
