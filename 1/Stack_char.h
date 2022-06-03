#pragma once

//��� char* ������ ��������� �����, ��������� �������, ��������� �������

#include "Stack_elem_char.h"
using namespace std;

class Stack_char
{
private:
	Stack_elem_char* top_ch = 0;
	int size; // ������ �����
protected:

public:
	Stack_char() : size(0) {};

	Stack_char(int size_st) : size(0)
	{
		for (int i = 0; i < size_st; i++)
		{
			int j;
			int str_size = 2 + rand() % 8;
			char* str = new char[str_size];
			for (j = 0; j < str_size; j++)
			{
				str[j] = 65 + rand() % 56;
			}
			str[--j] = '\0';
			this->push(str);
		}
	};

	~Stack_char()
	{
		while (this->size > 0) //���� ������ ����� ������ ����
		{
			if (top_ch == 0 || size == 0)
				break;
			this->pop();
		}
		system("cls");
	};

	void push(char* new_ch) // ���������� ��������� � ����� �����
	{
		Stack_elem_char* new_elem = new(Stack_elem_char); //�������� ������ ��� ����� �������
		new_elem->set_next(top_ch);
		new_elem->set_data(new_ch);
		top_ch = new_elem; // ��������� ������� ���������
		size++; // �������� ���� �������
	};

	void pop() // ��������� ���������(��������) ������� �� �����
	{
		try
		{
			if (!this)
				throw "���� ����, ������� ������!";

			char* deldata = 0; // ����������� �������
			deldata = top_ch->get_data(); //����������� �������� ���������� �������� 
			Stack_elem_char* temp = top_ch;
			if (top_ch == NULL)
				throw "������� ������, ���� � ��� ����!";
			top_ch = top_ch->get_next();
			delete temp;
			temp = nullptr;
			size--;
		}
		catch (const char* ex)
		{
			std::cout << ex << std::endl;
		}
	}

	void print() //����� ����� �� �����
	{
		try
		{
			if (!this)
				throw "���� ����, �������� ������.\n";

			Stack_elem_char* temp = top_ch;
			if (top_ch == 0)
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
	}

	Stack_char& operator = (const Stack_char& r) // ���������� ��������� ������������
	{
		while (this->size > 0) //������� ������ ��������
		{
			this->pop();
		}
		system("cls");

		char** buff = new char* [r.size]; //������ �������� ������, � ������� ����� ������� ���� ����� ������ �����
		Stack_elem_char* el_stack = r.top_ch; //����� ����������-������� �������� �����

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
	}

	void operator + (Stack_char& Stack_tmp) // �������� ���� ������
	{
		if (size != Stack_tmp.size) // ���� ������ �� ���������, ������ �������� �� �����
		{
			cout << "�������� ������ ����������" << endl;
		}
		else
		{
			int flag = 0;
			Stack_elem_char* current_top_tmp = top_ch; // ��������� �� ����� �������� �����
			Stack_elem_char* current_top_tmp2 = Stack_tmp.top_ch; // � �� ����� �������
			int razm = 0;

			while (razm < size)
			{
				if (strlen(current_top_tmp->get_data()) != strlen(current_top_tmp2->get_data()))
				{
					flag = 1;
				}
				current_top_tmp = current_top_tmp->get_next(); // ������� � ������ �������
				if (current_top_tmp == 0)
					break;
				current_top_tmp2 = current_top_tmp2->get_next(); // ������� � ������ ������
				if (current_top_tmp == 0)
					break;
				razm++;
			}

			if (flag == 0)
			{
				Stack_elem_char* current_top_tmp = top_ch; // ��������� �� ����� �������� �����
				Stack_elem_char* current_top_tmp2 = Stack_tmp.top_ch; // � �� ����� �������
				int i = 0;

				while (current_top_tmp->get_next() != 0) // ���� �� ������ �� ������� ��������
				{
					int size_s = strlen(current_top_tmp->get_data());
					char* mas_str = new char[size_s + 1];
					for (i = 0; i < size_s; i++)
					{
						mas_str[i] = current_top_tmp->get_data()[i];
						mas_str[i] += current_top_tmp2->get_data()[i];
					}
					mas_str[i] = '\0';
					current_top_tmp->set_data(mas_str);

					current_top_tmp = current_top_tmp->get_next(); // ������� � ������ �������
					if (current_top_tmp == 0)
						break;
					current_top_tmp2 = current_top_tmp2->get_next(); // ������� � ������ ������
					if (current_top_tmp2 == 0)
						break;
				}

				int size_s = strlen(current_top_tmp->get_data());
				char* mas_str = new char[size_s + 1];
				for (i = 0; i < size_s; i++)
				{
					mas_str[i] = current_top_tmp->get_data()[i];
					mas_str[i] += current_top_tmp2->get_data()[i];
				}
				mas_str[i] = '\0';
				current_top_tmp->set_data(mas_str);
				cout << "����� ����:" << endl; // ������� �� �����
				this->print();
			}
			else
			{
				cout << "��� ������ ������ ���� ����� �����" << endl; // ������� �� �����
			}
		}
	}

	void operator - (Stack_char& Stack_tmp) // �������� ���� ������
	{
		if (size != Stack_tmp.size) // ���� ������ �� ���������, ������ �������� �� �����
		{
			cout << "�������� ������ ����������" << endl;
		}
		else
		{
			int flag = 0;
			Stack_elem_char* current_top_tmp = top_ch; // ��������� �� ����� �������� �����
			Stack_elem_char* current_top_tmp2 = Stack_tmp.top_ch; // � �� ����� �������
			int razm = 0;

			while (razm < size)
			{
				if (strlen(current_top_tmp->get_data()) != strlen(current_top_tmp2->get_data()))
				{
					flag = 1;
				}
				current_top_tmp = current_top_tmp->get_next(); // ������� � ������ �������
				if (current_top_tmp == 0)
					break;
				current_top_tmp2 = current_top_tmp2->get_next(); // ������� � ������ ������
				if (current_top_tmp == 0)
					break;
				razm++;
			}

			if (flag == 0)
			{
				Stack_elem_char* current_top_tmp = top_ch; // ��������� �� ����� �������� �����
				Stack_elem_char* current_top_tmp2 = Stack_tmp.top_ch; // � �� ����� �������
				int i = 0;

				while (current_top_tmp->get_next() != 0) // ���� �� ������ �� ������� ��������
				{
					int size_s = strlen(current_top_tmp->get_data());
					char* mas_str = new char[size_s + 1];
					for (i = 0; i < size_s; i++)
					{
						mas_str[i] = current_top_tmp->get_data()[i];
						mas_str[i] += current_top_tmp2->get_data()[i];
					}
					mas_str[i] = '\0';
					current_top_tmp->set_data(mas_str);

					current_top_tmp = current_top_tmp->get_next(); // ������� � ������ �������
					if (current_top_tmp == 0)
						break;
					current_top_tmp2 = current_top_tmp2->get_next(); // ������� � ������ ������
					if (current_top_tmp2 == 0)
						break;
				}

				int size_s = strlen(current_top_tmp->get_data());
				char* mas_str = new char[size_s + 1];
				for (i = 0; i < size_s; i++)
				{
					mas_str[i] = current_top_tmp->get_data()[i];
					mas_str[i] -= current_top_tmp2->get_data()[i];
				}
				mas_str[i] = '\0';
				current_top_tmp->set_data(mas_str);
				cout << "����� ����:" << endl; // ������� �� �����
				this->print();
			}
			else
			{
				cout << "��� ������ ������ ���� ����� �����" << endl; // ������� �� �����
			}
		}
	}

	bool operator == (const Stack_char& tmp_stack)
	{
		int x = 1;
		if (this->size != tmp_stack.size) //���� �� ����� ������, ��..
		{
			cout << "����� ����� �� ������� � �� ���������" << endl;
			return false;
		}
		else // ���� ������ �����, ���������� �����������
		{
			Stack_elem_char* tmp_comprasion_1 = this->top_ch; //������� ����������-���������� � ����������� �� ��������� �� �������� � ������� �����, ������� ������ ���� ������������� ��������
			Stack_elem_char* tmp_comprasion_2 = tmp_stack.top_ch; // ��������� ���������� ���������
			int i = size;
			do
			{
				int k = strlen(tmp_comprasion_1->get_data());
				for (int j = 0; j < k; j++)
				{
					if (tmp_comprasion_1->get_data()[i] == tmp_comprasion_2->get_data()[i])
					{
						continue;
					}
					else
					{
						cout << "���� �� ��������� ����� �� ����� �������� ������� �����" << endl;
						return false;
					}
				}
				i--;
				tmp_comprasion_1 = tmp_comprasion_1->get_next(); //��������� �� ���������
				if (tmp_comprasion_1 == 0)
					break;
				tmp_comprasion_2 = tmp_comprasion_2->get_next();
				if (tmp_comprasion_2 == 0)
					break;
			} while (i != 0);
		}

		cout << "����� ����� �� ������� � �� ���������" << endl;
		return true;
	}

	bool operator! () const
	{
		if (size == 0)
			return true;
		else
			return false;
	}; //�������� �� �������
};
