#include <iostream>
#include <cstdlib>
#include <random>
#include <ctime>
#include "Stack.h"
#include "Stack_elem.h"
#include "Stack_char.h"
#include "Stack_elem_char.h"

#include "VECTOR.h"

using namespace std;

template <typename T>
void inversion_array(T* array, int size) //��������� ������� ���������� � ������� �������
{
	int i = 0;
	cout << "size of arr: ";
	cout << size << endl; 
	T num;
	cout << "before:" << endl;
	for (i = 0; i < size - 1; i++) //������� ������
		cout << array[i] << "  ";
	cout << array[i] << endl;
	cout << endl;

	cout << "after:" << endl;
	for (i = 0; i < size - 1; i++)
	{
		
		array[i] *= array[i];
		
	}
	for (i = 0; i < size - 1; i++) //������� ������
		cout << array[i] << "  ";
	cout << array[i] << endl;
	cout << endl;
}

template <class T, typename TT>
void workwithstack(T* stptr, TT x)
{
	int choise, size, exit = 1;
	TT element;

	try
	{
		cout << "������� ������ �����:\n--> ";
		cin >> size;
		if (size <= 0)
			throw "������ ����� �� ����� ���� ������� ��� �������������!";
		if (size > 30)
			throw "������ ����� ������ 30 - ��� �����������!";
	}
	catch (const char* ex) { cout << ex << endl; }

	T st1(size);
	stptr = new T[1]; //� ����� �� �������� ��������� �� ���� ������� ����, ����� �� ������� ��� ���� � ������ ������ ������ � ������� ������������ ���������
	stptr[0] = st1; //� ����� ������ ������ ������� ����� ������� ������ ��� ����������� ����
	T* sttmp = 0; //���������� ��� �������� ����� ������
	int num_of_stack = 0; //���-�� ������
	int stacks = 1; //� ��� ������ ���� ���� �� ���� ����

	system("cls");

	while (exit == 1)
	{
		cout << "�������� ��������� ��������. ��������, ��� ��� ����������: " << endl;
		cout << "1 - �������� ������� � �������� �����" << endl;
		cout << "2 - ������� ������� �� �������� �����" << endl;
		cout << "3 - ���������� ����" << endl;
		cout << "4 - ������� ����� ����" << endl;
		cout << "5 - ������� ������ ����" << endl;
		cout << "6 - �������� �������� �����" << endl;
		cout << "7 - ��������� �������� �����" << endl;
		cout << "8 - ��������� ������� ���� �������" << endl;
		cout << "9 - �������� ������� ���� � ������" << endl;
		cout << "0 - ����� � ������ �������" << endl;
		cout << "�� ����������� ���� � " << num_of_stack << endl;
		cin >> choise;

		system("cls");

		switch (choise)
		{
		case 1:
			cout << "������� ������� �����: ";
			cin >> element;
			stptr[num_of_stack].push(element); //��������� ����� �������
			system("pause");
			cout << "\n";
			break;
		case 2:
			try
			{
				if (!stptr[num_of_stack] == false)
					throw "���� ����, ��������� ������!";
				stptr[num_of_stack].pop();
			}
			catch (const char* ex) { cout << ex << endl; }
			system("pause");
			break;
		case 3:
			cout << "���� � " << num_of_stack << ": " << endl;
			stptr[num_of_stack].print();
			cout << "\n";
			system("pause");
			break;
		case 4:
			num_of_stack = stacks;
			sttmp = new T[stacks]; //������� ��������� ������ ������ �������� � ���������� ��������� ������

			for (int i = 0; i < stacks; i++) //�������� ��� ����� �� ��������� ������
				sttmp[i] = stptr[i];
			delete[] stptr;

			stptr = new T[++stacks]; //�������� ������ � ������ ������� ������ ��� ����� ���������� ������
			for (int i = 0; i < stacks - 1; i++) // �������� ��� ����� �� ���������� ������� ������ � ������ ������ ������
				stptr[i] = sttmp[i];
			delete[] sttmp; // ��������� ������ �� �����

			cout << "������� ������ ������ �����: ";
			cin >> size;
			cout << "\n";

			for (int i = 0; i < size; i++)
				stptr[num_of_stack].push((130.0 + rand() % 56) / (2.0 + rand() % 2)); //��������� ���������� ����������

			cout << "���� �����. ����� �������� �����: " << num_of_stack << endl;
			break;
		case 5:
			try
			{
				if (stacks == 1)
					throw "���������� ������ ���� ����";

				cout << "�������� ���� (�� 0 �� " << stacks - 1 << ")" << endl;
				cin >> choise;
				if (choise == num_of_stack)
					throw "�� �� ������ ������� ����, � ������� ���������!";
				system("cls");

				if ((choise < 0) || (choise == num_of_stack) || (choise >= stacks))
					throw "������������ ��������. ������������ �� ���������";

				num_of_stack = choise;
				cout << "������������ ���������!" << endl;
			}
			catch (const char* ex) { cout << ex << endl; }
			system("pause");
			break;
		case 6:
			try
			{
				if (stacks == 1)
					throw "���������� ������ ���� ����";

				cout << "�������� ���� (�� 0 �� " << stacks - 1 << ")" << endl;
				cin >> choise;
				if (choise == num_of_stack)
					throw "�� �� ������ ������� ����, � ������� ���������!";
				system("cls");

				if ((choise < 0) || (choise == num_of_stack) || (choise >= stacks))
					throw "������������ ��������. ������������ �� ���������";

				stptr[num_of_stack] + stptr[choise];
				cout << "�������� �������� ���������! ������������ ����: " << endl;
				stptr[num_of_stack].print();
			}
			catch (const char* ex) { cout << ex << endl; }
			system("pause");
			break;
		case 7:
			try
			{
				if (stacks == 1)
					throw "���������� ������ ���� ����";

				cout << "�������� ���� (�� 0 �� " << stacks - 1 << ")" << endl;
				cin >> choise;
				if (choise == num_of_stack)
					throw "�� �� ������ ������� ����, � ������� ���������!";
				system("cls");

				if ((choise < 0) || (choise == num_of_stack) || (choise >= stacks))
					throw "������������ ��������. ������������ �� ���������";

				stptr[num_of_stack] - stptr[choise];
				cout << "�������� ��������� ���������! ������������ ����: " << endl;
				stptr[num_of_stack].print();
			}
			catch (const char* ex) { cout << ex << endl; }
			system("pause");
			break;
		case 8:
			try
			{
				if (stacks == 1)
					throw "���������� ������ ���� ����";

				cout << "�������� ���� (�� 0 �� " << stacks - 1 << ")" << endl;
				cin >> choise;
				if (choise == num_of_stack)
					throw "�� �� ������ ������� ����, � ������� ���������!";
				system("cls");

				if ((choise < 0) || (choise == num_of_stack) || (choise >= stacks))
					throw "������������ ��������. ������������ �� ���������";

				stptr[num_of_stack] = stptr[choise];
				cout << "�������� ���������� ���������! ������������ ����: " << endl;
				stptr[num_of_stack].print();
			}
			catch (const char* ex) { cout << ex << endl; }
			system("pause");
			break;
		case 9:
			try
			{
				if (stacks == 1)
					throw "���������� ������ ���� ����";

				cout << "�������� ���� (�� 0 �� " << stacks - 1 << ")" << endl;
				cin >> choise;
				if (choise == num_of_stack)
					throw "�� �� ������ ������� ����, � ������� ���������!";
				system("cls");

				if ((choise < 0) || (choise == num_of_stack) || (choise >= stacks))
					throw "������������ ��������. ������������ �� ���������";

				if (stptr[num_of_stack] == stptr[choise])
					cout << "������� ���� � �������� �����!" << endl;
				else
					cout << "������� ���� � �������� �������!" << endl;
			}
			catch (const char* ex) { cout << ex << endl; }
			system("pause");
			break;
		case 0:
			delete[] stptr;
			exit = 0;
			break;
		}
	}
}

void workwithstack_char(Stack_char* stptr)
{
	int choise, size, exit = 1;
	char* val_ch = 0; //������
	char* val_ch_tmp = 0; //��������� ������
	int ind = 0;
	char ch = 0;

	try
	{
		cout << "������� ������ �����:\n--> ";
		cin >> size;
		if (size <= 0)
			throw "������ ����� �� ����� ���� ������� ��� �������������!";
		if (size > 30)
			throw "������ ����� ������ 30 - ��� �����������!";
	}
	catch (const char* ex) { cout << ex << endl; }

	Stack_char st1(size);
	stptr = new Stack_char[1]; //� ����� �� �������� ��������� �� ���� ������� ����, ����� �� ������� ��� ���� � ������ ������ ������ � ������� ������������ ���������
	stptr[0] = st1; //� ����� ������ ������ ������� ����� ������� ������ ��� ����������� ����
	Stack_char* sttmp = 0; //���������� ��� �������� ����� ������
	int num_of_stack = 0; //���-�� ������
	int stacks = 1; //� ��� ������ ���� ���� �� ���� ����

	system("cls");

	while (exit == 1)
	{
		cout << "�������� ��������� ��������. ��������, ��� ��� ����������: " << endl;
		cout << "1 - �������� ������� � �������� �����" << endl;
		cout << "2 - ������� ������� �� �������� �����" << endl;
		cout << "3 - ���������� ����" << endl;
		cout << "4 - ������� ����� ����" << endl;
		cout << "5 - ������� ������ ����" << endl;
		cout << "6 - �������� �������� �����" << endl;
		cout << "7 - ��������� �������� �����" << endl;
		cout << "8 - ��������� ������� ���� �������" << endl;
		cout << "9 - �������� ������� ���� � ������" << endl;
		cout << "0 - ����� � ������ �������" << endl;
		cout << "�� ����������� ���� � " << num_of_stack << endl;
		cin >> choise;

		system("cls");

		switch (choise)
		{
		case 1:
			ind = 0;
			cout << "������� ������� �����: ";

			cin.get(ch); //����� ���������� ������
			cin.get(ch); //��������� ����� ������
			val_ch = new char[1]; //�������� ������ ��� ������ ����� �������

			while (ch != '\n')
			{
				val_ch_tmp = new char[ind]; //�������� ������ ��� ������� ���������� ���������
				for (int j = 0; j < ind; j++)
					val_ch_tmp[j] = val_ch[j];

				val_ch = new char[ind + 2]; //�������� ������ ��� ����� ������� ���� ��� \0

				for (int j = 0; j < ind; j++)
					val_ch[j] = val_ch_tmp[j];

				val_ch[ind] = ch;
				ind++;
				cin.get(ch);
			}
			val_ch[ind] = '\0';

			delete[] val_ch_tmp;
			stptr[num_of_stack].push(val_ch); // ��������� ����� �������
			system("pause");
			cout << "\n";
			break;
		case 2:
			try
			{
				if (!stptr[num_of_stack] == false)
					throw "���������� ������� ������� �� ������� �����";
				stptr[num_of_stack].pop();
			}
			catch (const char* ex)
			{
				cout << ex << endl;
			}

			system("pause");
			break;
		case 3:
			cout << "���� � " << num_of_stack << ": " << endl;
			stptr[num_of_stack].print();
			cout << "\n";
			system("pause");
			break;
		case 4:
			num_of_stack = stacks;

			sttmp = new Stack_char[stacks];

			for (int i = 0; i < stacks; i++)
				sttmp[i] = stptr[i];

			delete[] stptr;

			stptr = new Stack_char[++stacks];

			for (int i = 0; i < stacks - 1; i++)
				stptr[i] = sttmp[i];

			delete[] sttmp; // ��������� ������ �� �����

			cout << "������� ������ ������ �����: ";
			cin >> size;

			for (int i = 0; i < size; i++)
			{
				int size_str = (2 + rand() % 10);

				val_ch = new char[size_str];
				for (int j = 0; j < size_str; j++)
				{

					val_ch[j] = 65 + rand() % 56;
				}
				val_ch[size_str - 1] = '\0';
				stptr[num_of_stack].push(val_ch);
			}

			cout << "���� �����. ����� �������� �����: " << num_of_stack << endl;
			break;
		case 5:
			try
			{
				if (stacks == 1)
					throw "���������� ������ ���� ����";

				cout << "�������� ���� (�� 0 �� " << stacks - 1 << ")" << endl;
				cin >> choise;
				if (choise == num_of_stack)
					throw "�� �� ������ ������� ����, � ������� ���������!";
				system("cls");

				if ((choise < 0) || (choise == num_of_stack) || (choise >= stacks))
					throw "������������ ��������. ������������ �� ���������";

				num_of_stack = choise;
				cout << "������������ ���������!" << endl;
			}
			catch (const char* ex) { cout << ex << endl; }
			system("pause");
			break;
		case 6:
			try
			{
				if (stacks == 1)
					throw "���������� ������ ���� ����";

				cout << "�������� ���� (�� 0 �� " << stacks - 1 << ")" << endl;
				cin >> choise;
				if (choise == num_of_stack)
					throw "�� �� ������ ������� ����, � ������� ���������!";
				system("cls");

				if ((choise < 0) || (choise == num_of_stack) || (choise >= stacks))
					throw "������������ ��������. ������������ �� ���������";

				stptr[num_of_stack] + stptr[choise];
				cout << "�������� �������� ���������! ������������ ����: " << endl;
				stptr[num_of_stack].print();
			}
			catch (const char* ex) { cout << ex << endl; }
			system("pause");
			break;
		case 7:
			try
			{
				if (stacks == 1)
					throw "���������� ������ ���� ����";

				cout << "�������� ���� (�� 0 �� " << stacks - 1 << ")" << endl;
				cin >> choise;
				if (choise == num_of_stack)
					throw "�� �� ������ ������� ����, � ������� ���������!";
				system("cls");

				if ((choise < 0) || (choise == num_of_stack) || (choise >= stacks))
					throw "������������ ��������. ������������ �� ���������";

				stptr[num_of_stack] - stptr[choise];
				cout << "�������� ��������� ���������! ������������ ����: " << endl;
				stptr[num_of_stack].print();
			}
			catch (const char* ex) { cout << ex << endl; }
			system("pause");
			break;
		case 8:
			try
			{
				if (stacks == 1)
					throw "���������� ������ ���� ����";

				cout << "�������� ���� (�� 0 �� " << stacks - 1 << ")" << endl;
				cin >> choise;
				if (choise == num_of_stack)
					throw "�� �� ������ ������� ����, � ������� ���������!";
				system("cls");

				if ((choise < 0) || (choise == num_of_stack) || (choise >= stacks))
					throw "������������ ��������. ������������ �� ���������";

				stptr[num_of_stack] = stptr[choise];
				cout << "�������� ���������� ���������! ������������ ����: " << endl;
				stptr[num_of_stack].print();
			}
			catch (const char* ex) { cout << ex << endl; }
			system("pause");
			break;
		case 9:
			try
			{
				if (stacks == 1)
					throw "���������� ������ ���� ����";

				cout << "�������� ���� (�� 0 �� " << stacks - 1 << ")" << endl;
				cin >> choise;
				if (choise == num_of_stack)
					throw "�� �� ������ ������� ����, � ������� ���������!";
				system("cls");

				if ((choise < 0) || (choise == num_of_stack) || (choise >= stacks))
					throw "������������ ��������. ������������ �� ���������";

				if ((stptr[num_of_stack] == stptr[choise]) == true)
					cout << "������� ���� � �������� �����!" << endl;
				else
					cout << "������� ���� � �������� �������!" << endl;
			}
			catch (const char* ex) { cout << ex << endl; }
			system("pause");
			break;
		case 0:
			delete[] stptr;
			exit = 0;
			break;
		}
	}
}

int main()
{
	
		Vector<int> a;
		Vector<int> b;
		a[3] = 3;
		b[3] = 7;
		a = a + b;
	
		a.print();

		
		
		return 0;



}

int _main()
{

	int size_array;
	int size_stack;
	int choice, choice_type, exit = 1, exit1 = 1;
	srand(time(NULL));

	int* mass1 = 0;
	char* mass2 = 0;
	float* mass3 = 0;
	double* mass4 = 0;
	char** mass5 = 0;
	Stack<int>* stack1 = nullptr;
	int x1 = 0;
	Stack<float>* stack2 = nullptr;
	float x2 = 0;
	Stack<double>* stack3 = nullptr;
	double x3 = 0;
	Stack<char>* stack4 = nullptr;
	char x4 = 0;
	Stack_char* stack5 = nullptr;
	//char** x5 = 0;

	while (exit == 1)
	{
		cout << "choose task: " << endl;
		cout << "1 - arr[i] = arr[i]*arr[i]\n2 - \n0 - exit\n>>> ";
		cin >> choice;
		system("cls");

		switch (choice)
		{
		case 1: /////////////////////////////////////////////////////////////////////////////////////////////////������
			while (exit1 == 1)
			{
				cout << "type: " << endl;
				cout << "1 - int\n2 - char\n3 - float\n4 - double\n5 - char*\n0 - return\n--> " << endl;
				cin >> choice_type;
				size_array = 1 + rand() % 30;
				switch (choice_type)
				{
				case 1:
					
					mass1 = new int[size_array]; 

					for (int i = 0; i < size_array; i++) 
						mass1[i] = -30 + rand() % 60;

					inversion_array(mass1, size_array); 
					delete[] mass1;
					system("pause");
					system("cls");
					break;
				case 2:
					mass2 = new char[size_array]; 

					for (int i = 0; i < size_array; i++) 
						mass2[i] = 65 + rand() % 56; 

					inversion_array(mass2, size_array); 
					delete[] mass2;
					system("pause");
					system("cls");
					break;
				case 3:
					mass3 = new float[size_array]; 

					for (int i = 0; i < size_array; i++) 
						mass3[i] = (-60.0 + rand() % 119) / (2.0 + rand() % 2); 

					inversion_array(mass3, size_array); 
					delete[] mass3;
					system("pause");
					system("cls");
					break;
				case 4:
					mass4 = new double[size_array]; 

					for (int i = 0; i < size_array; i++) 
						mass4[i] = (-60.0 + rand() % 119) / (2.0 + rand() % 2); 

					inversion_array(mass4, size_array); 
					delete[] mass4;
					system("pause");
					system("cls");
					break;
				case 5:
					cout << "Can`t mult pointers!\n";
					break;
				case 0:
					exit1 = 0;
					break;
				default:
					break;
				}
			}
			break;




		case 2: //
			system("cls");

			cout << "�������� �������� ��� ������ �������: " << endl;
			cout << "1 - int\n2 - float\n3 - double\n4 - char\n5 - char*\n0 - ����� � ������ �������\n-->" << endl;
			cin >> choice_type;
			switch (choice_type)
			{
			case 1:
				workwithstack(stack1, x1);
				system("pause");
				system("cls");
				break;
			case 2:
				workwithstack(stack2, x2);
				system("pause");
				system("cls");
				break;
			case 3:
				workwithstack(stack3, x3);
				system("pause");
				system("cls");
				break;
			case 4:
				workwithstack(stack4, x4);
				system("pause");
				system("cls");
				break;
			case 5:
				workwithstack_char(stack5);
				system("pause");
				system("cls");
				break;
			case 0:
				break;
			default:
				break;
			}
			break;
		case 0:
			exit = 0;
			break;
		default:
			exit = 0;
			break;
		}
	}
	return 0;
}
