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

template<class T, int ROWS, int COLUMNS>
class Matrix
{
private:
	vector<vector<T> > m_data;
	vector<vector<T> > m_transpose;

public:
	Matrix()
	{
		vector<T> column;
		for(int i = 0; i < COLUMNS; i++)
		{
			column.push_back(0);
		}

		for(int i=0; i < ROWS; i++)
		{
			m_data.push_back(column);
		}
	}

	// Add data to the vector
	void change_data(T data, int row, int col)
	{
		// Add elements into the matrix
		m_data[row][col] = data;
	}

	T get_data(int row, int col)
	{
		return m_data[row][col];
	}

	// Get number of rows
	int get_number_of_rows()
	{
		return ROWS;
	}

	// Get number of columns
	int get_number_of_columns()
	{
		return COLUMNS;
	}

	void transpose()
	{
		vector<T> transpose_data;

		for(int j = 0; j < this->get_number_of_columns(); j++)
		{
			for(int i = 0; i < this->get_number_of_rows(); i++)
			{
				transpose_data.push_back(m_data[i][j]);
			}

			m_transpose.push_back(transpose_data);

			transpose_data.clear();
		}
	}

	// Print the vector data
	void print()
	{
		typename vector<T>::iterator itr;

		for(int i = 0; i < ROWS; i++)
		{
			cout<< "[";
			for(itr = this->m_data[i].begin(); itr != this->m_data[i].end(); itr++)
			{
				cout << *itr <<" ";
			}

			cout<< "]" <<endl;
		}
	}

	// Print the vector data
	void print_transposed()
	{
		typename vector<T>::iterator itr;

		for(int i = 0; i < ROWS; i++)
		{
			cout<< "[";
			for(itr = this->m_transpose[i].begin(); itr != this->m_transpose[i].end(); itr++)
			{
				cout << *itr <<" ";
			}

			cout<< "]" <<endl;
		}
	}

	vector<vector<T> > operator*(Matrix<float, 4, 1> matrix)
	{
		vector<vector<T> > prod;
		vector<T> row;
		if(this->get_number_of_columns() == matrix.get_number_of_rows())
		{
			typename vector<T>::iterator itr;

			for(int j = 0; j < this->get_number_of_rows(); j++)
			{
				for(itr = this->m_data[j].begin(); itr != this->m_data[j].end(); itr++)
				{
					float sum = 0;
					for(int i = 0; i < this->get_number_of_rows(); i++)
					{
						sum += itr[i] * matrix.get_data(i, 0);
					}
					row.push_back(sum);
				}
				prod.push_back(row);
				row.clear();
			}
		}
		else
		{
			// Do nothing
		}

		return prod;
	}
};



#endif /* HELPER_MATRIX_H_ */
