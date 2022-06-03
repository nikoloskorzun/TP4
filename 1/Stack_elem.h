#pragma once
#include <iostream>
#include <ctime>

template <typename T>
class Stack_elem //������ ������
{
private:
	T data = 0; //������ �������� �����
	Stack_elem<T>* next = 0; //��������� �� �������� ������� �����
public:
	Stack_elem() : data(0) {};
	Stack_elem(T value) { data = value; };
	~Stack_elem() {};

	T get_data() { return data; };
	void set_data(T value) { data = value; };
	Stack_elem<T>*& get_next() { return next; };
	void set_next(Stack_elem<T>* new_next) { next = new_next; };

};
