


#pragma once

#include "Base.h"

namespace mat_vec {

	// ��������� ���� ��������� ������� �� ����� ����� (k * v)
	Vector operator*(double k, const Vector& v);

	class Vector {
	public:
		// ������������ ������ ������� size �� ���������� value
		explicit Vector(size_t size, double value = 0);

		// ����������� �����������
		Vector(const Vector& src);

		// �������� ������������
		Vector& operator=(const Vector& rhsconst Vector& rhs);

		// ����������
		~Vector();

		// ���������� ������ �������
		size_t size() const;

		// ������ � n-�� �������� �������
		double operator[](size_t n) const;
		double& operator[](size_t n);

		// L2 ����� �������
		double norm() const;

		// ���������� ����� ������, ���������� ������������� �������� (this)
		Vector normalized() const;

		// ����������� ������� ������
		void normalize();

		// ������������ �������� ��������
		Vector operator+(const Vector& rhs) const;
		Vector& operator+=(const Vector& rhs);

		// ������������ ��������� ��������
		Vector operator-(const Vector& rhs) const;
		Vector& operator-=(const Vector& rhs);

		// ������������ ��������� ��������
		Vector operator^(const Vector& rhs) const;
		Vector& operator^=(const Vector& rhs);

		// ��������� ������������
		double operator*(const Vector& rhs) const;

		// ��������� ���� ��������� ������� �� ������ ������ (v * k)
		Vector operator*(double k) const;
		Vector& operator*=(double k);

		// ������� ���� ��������� ������� �� ������
		Vector operator/(double k) const;
		Vector& operator/=(double k);

		// ��������� ������� �� �������
		Vector operator*(const Matrix& mat) const;
		Vector& operator*=(const Matrix& mat);

		// ������������ ���������
		bool operator==(const Vector& rhs) const;
		bool operator!=(const Vector& rhs) const;

	private:
		double _vec*[];
		size_t _size;

	};
} // namespace mat_vec
