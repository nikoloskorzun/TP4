#pragma once
#include <iostream>
#include <ctime>

template <typename T>
class Stack_elem //шаблон класса
{
private:
	T data = 0; //данные элемента стека
	Stack_elem<T>* next = 0; //указатель на следющий элемент стека
public:
	Stack_elem() : data(0) {};
	Stack_elem(T value) { data = value; };
	~Stack_elem() {};

	T get_data() { return data; };
	void set_data(T value) { data = value; };
	Stack_elem<T>*& get_next() { return next; };
	void set_next(Stack_elem<T>* new_next) { next = new_next; };

};
