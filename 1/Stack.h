#pragma once
#include <iostream>
#include "Stack_elem.h"

template <typename T>
class Stack //������ ������
{
private:
	Stack_elem<T>* top = 0; //������� �����
	int size; //������
public:
	//������������
	Stack() : size(0) {}; //����������� ��� ���������� (���. ������ �������������); 

	Stack(int size_st) : size(0)
	{
		for (int i = 0; i < size_st; i++)
			this->push((130.0 + rand() % 56) / (2.0 + rand() % 2));
	}; //����������� � ����������� (������ ������ ����� � ��������� ��������� � ����)

	~Stack()
	{
		while (this->size > 0)
		{
			if (top == 0 || size == 0)
				break;
			this->pop();
		}
		system("cls");
	}; //����������

	Stack(const Stack<T>& st_copy) //����������� �����������
	{
		T* buff = new T[st_copy.size]; //������ �������� ������, � ������� ����� ������� ���� ����� ������ �����
		Stack_elem<T>* el_stack = st_copy.top; //����� ����������-������� �������� �����

		for (int i = 0; i <= st_copy.size - 1; i++)
		{	//���� ������� �� ������ �� ����� �����
			if (el_stack == NULL)
				break;
			buff[i] = el_stack->get_data(); //������� � ������ �������� �� �����
			el_stack = el_stack->get_next(); //������ ��������� �� ��������� ������� �����
		}

		for (int i = 0; i < st_copy.size; i++)
			this->push(buff[i]); //������ � ����� ���� �������� �� �������

		delete[] buff; //������� �����
	}

	//������� �����
	void push(T value)
	{
		Stack_elem<T>* new_elem = new(Stack_elem<T>); //�������������� ����� ���� ����� � �������� ��� ���� ������
		new_elem->set_next(top); //������ ����� ���� ���� ��������
		new_elem->set_data(value);
		top = new_elem; //� ������� ��������� �� ����� ����
		size++;
	}; //���������� �������� � ����

	void pop()
	{
		try
		{
			if (!this)
				throw "���� ����, ������� ������!";

			T deldata = 0; // ����������� �������
			deldata = top->get_data(); //����������� �������� ���������� �������� 
			Stack_elem<T>* temp = top;
			if (top == NULL)
				throw "������� ������, ���� � ��� ����!";
			top = top->get_next();
			delete temp;
			temp = nullptr;
			size--;
		}
		catch (const char* ex)
		{
			std::cout << ex << std::endl;
		}
	}; //���������� �������

	void print()
	{
		try
		{
			if (!this)
				throw "���� ����, �������� ������.\n";

			Stack_elem<T>* temp = top;
			if (top == 0)
				throw "������� ������, ���� � ��� ����!";
			while (temp->get_next() != nullptr)
			{
				std::cout << temp->get_data() << " <-- ";
				temp = temp->get_next();
			}
			std::cout << temp->get_data() << std::endl;
		}
		catch (const char* ex)
		{
			std::cout << ex << std::endl;
		}
	}; //����� ����� �� �����

	//������� � �������
	int get_size() const //����� ������ �����
	{
		return size;
	};

	bool operator! () const
	{
		if (size == 0)
			return true;
		else
			return false;
	}; //�������� �� �������

	bool operator== (const Stack& r)
	{
		if (this->size != r.size)
		{
			std::cout << "����� �������, ��� ��� �� ������ ������" << std::endl;
			return false;
		}
		else
		{
			int i = size; //������ ������ �������
			Stack_elem<T>* tmp_cmp = this->top; //��������� ������� ������ ��������
			Stack_elem<T>* tmp_cmp_r = r.top; //��������� ������� ������� ��������
			while (i != 0)
			{
				if (tmp_cmp->get_data() == tmp_cmp_r->get_data())
					i--;
				else
				{
					std::cout << "���� �� ��������� ����� �� ����� �������� ������� �����" << std::endl;
					return false;
				}
				tmp_cmp = tmp_cmp->get_next();
				if (tmp_cmp == 0)
					break;
				tmp_cmp_r = tmp_cmp_r->get_next();
				if (tmp_cmp_r == 0)
					break;
			}

			std::cout << "����� ����� �� ������� � �� ���������" << std::endl;
			return true;
		}
	}; //��������� ���� ������ �� �������

	Stack& operator= (const Stack& r)
	{
		while (this->size > 0) //������� ������ ��������
		{
			this->pop();
		}
		system("cls");

		T* buff = new T[r.size]; //������ �������� ������, � ������� ����� ������� ���� ����� ������ �����
		Stack_elem<T>* el_stack = r.top; //����� ����������-������� �������� �����

		for (int i = r.size - 1; i >= 0; i--)
		{	//���� ������� �� ������ �� ����� �����
			if (el_stack == 0)
				break;
			buff[i] = el_stack->get_data(); //������� � ������ �������� �� �����
			el_stack = el_stack->get_next(); //������ ��������� �� ��������� ������� �����
		}

		for (int i = 0; i < r.size; i++)
			this->push(buff[i]); //������ � ����� ���� �������� �� �������

		delete[] buff; //������� �����
		return *this;
	}; //������������ ���� ������

	void operator+ (Stack<T>& r)
	{
		if (this->size != r.size)
			std::cout << "������� ��� ����� ����������, ��� ��� �� ������� �������!" << std::endl;

		T* buff_l = new T[this->size]; //������ �������� ������, � ������� ����� ������� ���� ����� ������ �����
		Stack_elem<T>* el_stack_l = this->top; //����� ����������-������� �������� �����

		for (int i = this->size - 1; i >= 0; i--)
		{	//���� ������� �� ������ �� ����� �����
			if (el_stack_l == 0)
				break;
			buff_l[i] = el_stack_l->get_data(); //������� � ������ �������� �� �����
			el_stack_l = el_stack_l->get_next(); //������ ��������� �� ��������� ������� �����
		}

		T* buff_r = new T[r.size]; //������ �������� ������, � ������� ����� ������� ���� ����� ������ �����
		Stack_elem<T>* el_stack_r = r.top; //����� ����������-������� �������� �����

		for (int i = r.size - 1; i >= 0; i--)
		{	//���� ������� �� ������ �� ����� �����
			if (el_stack_r == 0)
				break;
			buff_r[i] = el_stack_r->get_data(); //������� � ������ �������� �� �����
			el_stack_r = el_stack_r->get_next(); //������ ��������� �� ��������� ������� �����
		}

		while (this->size > 0) //������� ������ ��������
		{
			this->pop();
		}
		system("cls");

		for (int i = 0; i < r.size; i++) //���������� ��������, ���������� �� � ����� ������� � ������� � ����� �������-����
		{
			buff_l[i] += buff_r[i];
			this->push(buff_l[i]);
		}

		delete[] buff_l; //������� �����
		delete[] buff_r;
	}; //�������� ���� ������

	void operator- (Stack<T>& r)
	{
		if (this->size != r.size)
			std::cout << "������� ��� ����� ����������, ��� ��� �� ������� �������!" << std::endl;

		T* buff_l = new T[this->size]; //������ �������� ������, � ������� ����� ������� ���� ����� ������ �����
		Stack_elem<T>* el_stack_l = this->top; //����� ����������-������� �������� �����

		for (int i = this->size - 1; i >= 0; i--)
		{	//���� ������� �� ������ �� ����� �����
			if (el_stack_l == 0)
				break;
			buff_l[i] = el_stack_l->get_data(); //������� � ������ �������� �� �����
			el_stack_l = el_stack_l->get_next(); //������ ��������� �� ��������� ������� �����
		}

		T* buff_r = new T[r.size]; //������ �������� ������, � ������� ����� ������� ���� ����� ������ �����
		Stack_elem<T>* el_stack_r = r.top; //����� ����������-������� �������� �����

		for (int i = r.size - 1; i >= 0; i--)
		{	//���� ������� �� ������ �� ����� �����
			if (el_stack_r == 0)
				break;
			buff_r[i] = el_stack_r->get_data(); //������� � ������ �������� �� �����
			el_stack_r = el_stack_r->get_next(); //������ ��������� �� ��������� ������� �����
		}

		while (this->size > 0) //������� ������ ��������
		{
			this->pop();
		}
		system("cls");

		for (int i = 0; i < r.size; i++) //�������� ��������, ���������� �� � ����� ������� � ������� � ����� �������-����
		{
			buff_l[i] -= buff_r[i];
			this->push(buff_l[i]);
		}

		delete[] buff_l; //������� �����
		delete[] buff_r;
	}; //��������� ���� ������
};
