#pragma once
#include <iostream>
/*
�������� ������ ������ �������, � ������� ���� ������ ��� ���������� ����� � ��������
�������� �������� � ������� �����. ����������� ��������� ����/�����, �������� + ��� ��������
���� ��������, - ��� ��������� ��������, != ��� ��������� ��������, < ��� ��������� ��������.

*/


template <typename T>
class Vector //������ ������
{
private:
	T* arr = NULL;
	size_t size;
public:
	//������������
	Vector() : size(0) {}; //����������� ��� ���������� (���. ������ �������������); 

	Vector(size_t size_arr)
	{
		this->arr = new T[size_arr];
		for (size_t i = 0; i < size_arr; i++)
			this->arr[i] = NULL;


		this->size = size_arr;
	}; //����������� � ����������� 



	~Vector()
	{
		delete[] arr;
	}; //����������

	Vector(const Vector<T>& vector_copy) //����������� �����������
	{

		this->arr = new T[vector_copy.size];
		this->size = vector_copy.size;
		for (size_t i = 0; i < vector_copy.size; i++)
			this->arr[i] = vector_copy[i];
	}


	T& operator[](size_t index)
	{

		
		this->increase_size(index + 1);

		return arr[index];

	}

	Vector<T>& operator+ (Vector<T>& r) {

		Vector<T> res;

		size_t max = this->size > r.size ? this->size : r.size;
		this->increase_size(max);
		r.increase_size(max);
		res.increase_size(max);



		for (size_t i = 0; i < max; i++)
			res.arr[i] = this->arr[i] + r.arr[i];
		return res;
	}

	
	ostream& operator<<(ostream& out)
	{
		out << "123";
		return out;
	}
	istream& operator>>(istream& in)
	{
		int i;
		in >> i;
		return in;
	}

	void increase_size(size_t new_size)
	{
		if (new_size < this->size)
			return;

		T* temp = new T[new_size];

		for (size_t i = 0; i < this->size; i++)
			temp[i] = this->arr[i];

		delete[] this->arr;

		this->arr = temp;
		this->size = new_size;
	}

	T sum()
	{
		T s = NULL;
		for (size_t i = 0; i < this->size; i++)
			s+= this->arr[i];
		return s;

	}	
	
	T mean()
	{
		T s = NULL;
		for (size_t i = 0; i < this->size; i++)
			s+= this->arr[i];
		return (s/this->size);

	}

	

	void print()
	{
		cout << "arr: ";
		for (size_t i = 0; i < this->size; i++)
			cout << this->arr[i]<< " ";
		cout << endl;

	}

};
