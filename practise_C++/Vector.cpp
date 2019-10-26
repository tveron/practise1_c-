#include "Vector.h"
namespace mat_vec 
{
	Vector::Vector(size_t size, double value) 
	{
		this->_size = size;
		_vec = new double* [_size];
		for (int i = 0; i < _size; i++)
		{
			_vec[i] = value;
		}
	}
	Vector::~Vector(size_t size, double value) 
	{
		delete []_vec ;
	}
	Vector::Vector(const Vector& src)
	{
		Vector _vecCopy(size);


		for (int i = 0; i < _size; i++)
		{
			_vecCopy._vec[i] = src._vec[i];
		}
	}
	/*Vector::&Vector(const Vector& rhs)
	{
		Vector _vecAssign(size);
		_vecAssign.
		)
	}
}*/