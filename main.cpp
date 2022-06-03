#include <iostream>
#include <cstdlib>
#include <random>
#include <ctime>


#include "VECTOR.h"

using namespace std;

template <typename T>
void d_array(T* array, size_t size) //шаблонная функция возведения в квадрат массива
{

	if (size == 17)
		throw "ERROR size = 17 hahahaha";

	int i = 0;
	cout << "size of arr: ";
	cout << size << endl; 
	T num;
	cout << "before:" << endl;
	for (i = 0; i < size - 1; i++) //выводим массив
		cout << array[i] << "  ";
	cout << array[i] << endl;
	cout << endl;

	cout << "after:" << endl;
	for (i = 0; i < size; i++)
	{
		
		array[i] *= array[i];
		
	}
	for (i = 0; i < size - 1; i++) //выводим массив
		cout << array[i] << "  ";
	cout << array[i] << endl;
	cout << endl;
}


template <typename T>
void randomize(T* array, size_t size)
{
	uint64_t n = 1;
	n <<=(sizeof(T) * 8 / 2 -1);


	for (size_t i = 0; i < size; i++) //выводим массив
		array[i] = rand() % n;

}


void work_with_Vector()
{
	Vector<Vector<int>> int_arr;
	Vector<Vector<char>> char_arr;
	Vector<Vector<float>> float_arr;
	Vector<Vector<double>> double_arr;

	Vector<int> i_a, i_b, i_c;
	Vector<char> c_a, c_b, c_c ;
	Vector<float> f_a, f_b, f_c;
	Vector<double> d_a, d_b, d_c;


	bool exit = true;
	int choice;
	int choice_;
	size_t index, index2;
	size_t last[6] = {0,0,0,0,0,0};
	while (exit)
	{
		cout << "\ninput number:\n1 - int\n2 - char\n3 - float\n4 - double\n0 - exit\n";

		cin >> choice;

		switch (choice)
		{
		case 0:
			exit = false;
			break;


		case 1:
			cout << "input number:\n1 - input new array\n2 - print all arrays\n3 - sum\n4 - mean\n5 - +\n6 - -\n7 - <\n8 - >\n9 - !=\n0 - exit\n";
			cin >> choice_;

			switch (choice_)
			{
			case 1:
				last[choice]++;

				cin >> i_a;
				int_arr.pushBack(i_a);
				break;
			case 2:

				cout << int_arr << endl;
				break;

			case 3:
				try {
					cout << "input index: \n";
					cin >> index;
					cout << int_arr[index].sum();
				}
				catch (const char* ex)
				{
					cout << ex << endl;
				}
				break;

			case 4:
				try {
					cout << "input index: \n";
					cin >> index;
					cout << int_arr[index].mean();
				}
				catch (const char* ex)
				{
					cout << ex << endl;
				}
				break;

			case 5:
				cout << "input index1, index2: \n";
				cin >> index >> index2;
				try {
					i_a = int_arr[index] + int_arr[index2];
					cout << i_a;
				}
				catch (const char* ex)
				{
					cout << ex << endl;
				}
				break;
			case 6:
				try {
					cout << "input index1, index2: \n";
					cin >> index >> index2;
					i_a = int_arr[index] - int_arr[index2];
					cout << i_a;
				}
				catch (const char* ex)
				{
					cout << ex << endl;
				}
				break;

			case 7:
				try {
					cout << "input index1, index2: \n";
					cin >> index >> index2;

					cout << (int_arr[index] < int_arr[index2]);
				}
				catch (const char* ex)
				{
					cout << ex << endl;
				}
				break;

			case 8:
				try {
					cout << "input index1, index2: \n";
					cin >> index >> index2;
					cout << (int_arr[index] > int_arr[index2]);
				}
				catch (const char* ex)
				{
					cout << ex << endl;
				}
				break;

			case 9:
				try {
					cout << "input index1, index2: \n";
					cin >> index >> index2;
					cout << (int_arr[index] != int_arr[index2]);
				}
				catch (const char* ex)
				{
					cout << ex << endl;
				}
				break;


			default:
				break;
			}

			break;

		case 2:
			cout << "input number:\n1 - input new array\n2 - print all arrays\n3 - sum\n4 - mean\n5 - +\n6 - -\n7 - <\n8 - >\n9 - !=\n0 - exit\n";
			cin >> choice_;

			switch (choice_)
			{
			case 1:
				last[choice]++;

				cin >> c_a;
				char_arr.pushBack(c_a);
				break;
			case 2:

				cout << char_arr << endl;
				break;

			case 3:
				try {
					cout << "input index: \n";
					cin >> index;
					cout << char_arr[index].sum();
				}
				catch (const char* ex)
				{
					cout << ex << endl;
				}
				break;

			case 4:
				try {
					cout << "input index: \n";
					cin >> index;
					cout << char_arr[index].mean();
				}
				catch (const char* ex)
				{
					cout << ex << endl;
				}
				break;

			case 5:
				cout << "input index1, index2: \n";
				cin >> index >> index2;
				try {
					c_a = char_arr[index] + char_arr[index2];
					cout << c_a;
				}
				catch (const char* ex)
				{
					cout << ex << endl;
				}
				break;
			case 6:
				try {
					cout << "input index1, index2: \n";
					cin >> index >> index2;
					c_a = char_arr[index] - char_arr[index2];
					cout << c_a;
				}
				catch (const char* ex)
				{
					cout << ex << endl;
				}
				break;

			case 7:
				try {
					cout << "input index1, index2: \n";
					cin >> index >> index2;

					cout << (char_arr[index] < char_arr[index2]);
				}
				catch (const char* ex)
				{
					cout << ex << endl;
				}
				break;

			case 8:
				try {
					cout << "input index1, index2: \n";
					cin >> index >> index2;
					cout << (char_arr[index] > char_arr[index2]);
				}
				catch (const char* ex)
				{
					cout << ex << endl;
				}
				break;

			case 9:
				try {
					cout << "input index1, index2: \n";
					cin >> index >> index2;
					cout << (char_arr[index] != char_arr[index2]);
				}
				catch (const char* ex)
				{
					cout << ex << endl;
				}
				break;


			default:
				break;
			}

			break;

		case 3:
			cout << "input number:\n1 - input new array\n2 - print all arrays\n3 - sum\n4 - mean\n5 - +\n6 - -\n7 - <\n8 - >\n9 - !=\n0 - exit\n";
			cin >> choice_;

			switch (choice_)
			{
			case 1:
				last[choice]++;

				cin >> i_a;
				float_arr.pushBack(f_a);
				break;
			case 2:

				cout << float_arr << endl;
				break;

			case 3:
				try {
					cout << "input index: \n";
					cin >> index;
					cout << float_arr[index].sum();
				}
				catch (const char* ex)
				{
					cout << ex << endl;
				}
				break;

			case 4:
				try {
					cout << "input index: \n";
					cin >> index;
					cout << float_arr[index].mean();
				}
				catch (const char* ex)
				{
					cout << ex << endl;
				}
				break;

			case 5:
				cout << "input index1, index2: \n";
				cin >> index >> index2;
				try {
					f_a = float_arr[index] + float_arr[index2];
					cout << f_a;
				}
				catch (const char* ex)
				{
					cout << ex << endl;
				}
				break;
			case 6:
				try {
					cout << "input index1, index2: \n";
					cin >> index >> index2;
					f_a = float_arr[index] - float_arr[index2];
					cout << f_a;
				}
				catch (const char* ex)
				{
					cout << ex << endl;
				}
				break;

			case 7:
				try {
					cout << "input index1, index2: \n";
					cin >> index >> index2;

					cout << (float_arr[index] < float_arr[index2]);
				}
				catch (const char* ex)
				{
					cout << ex << endl;
				}
				break;

			case 8:
				try {
					cout << "input index1, index2: \n";
					cin >> index >> index2;
					cout << (float_arr[index] > float_arr[index2]);
				}
				catch (const char* ex)
				{
					cout << ex << endl;
				}
				break;

			case 9:
				try {
					cout << "input index1, index2: \n";
					cin >> index >> index2;
					cout << (float_arr[index] != float_arr[index2]);
				}
				catch (const char* ex)
				{
					cout << ex << endl;
				}
				break;


			default:
				break;
			}

			break;


		case 4:
			cout << "input number:\n1 - input new array\n2 - print all arrays\n3 - sum\n4 - mean\n5 - +\n6 - -\n7 - <\n8 - >\n9 - !=\n0 - exit\n";
			cin >> choice_;

			switch (choice_)
			{
			case 1:
				last[choice]++;

				cin >> d_a;
				double_arr.pushBack(d_a);
				break;
			case 2:

				cout << double_arr << endl;
				break;

			case 3:
				try {
					cout << "input index: \n";
					cin >> index;
					cout << double_arr[index].sum();
				}
				catch (const char* ex)
				{
					cout << ex << endl;
				}
				break;

			case 4:
				try {
					cout << "input index: \n";
					cin >> index;
					cout << double_arr[index].mean();
				}
				catch (const char* ex)
				{
					cout << ex << endl;
				}
				break;

			case 5:
				cout << "input index1, index2: \n";
				cin >> index >> index2;
				try {
					d_a = double_arr[index] + double_arr[index2];
					cout << d_a;
				}
				catch (const char* ex)
				{
					cout << ex << endl;
				}
				break;
			case 6:
				try {
					cout << "input index1, index2: \n";
					cin >> index >> index2;
					d_a = double_arr[index] - double_arr[index2];
					cout << d_a;
				}
				catch (const char* ex)
				{
					cout << ex << endl;
				}
				break;

			case 7:
				try {
					cout << "input index1, index2: \n";
					cin >> index >> index2;

					cout << (double_arr[index] < double_arr[index2]);
				}
				catch (const char* ex)
				{
					cout << ex << endl;
				}
				break;

			case 8:
				try {
					cout << "input index1, index2: \n";
					cin >> index >> index2;
					cout << (double_arr[index] > double_arr[index2]);
				}
				catch (const char* ex)
				{
					cout << ex << endl;
				}
				break;

			case 9:
				try {
					cout << "input index1, index2: \n";
					cin >> index >> index2;
					cout << (double_arr[index] != double_arr[index2]);
				}
				catch (const char* ex)
				{
					cout << ex << endl;
				}
				break;


			default:
				break;
			}

			break;


		
		




		default:
			break;
		}

	}

	


}


void work_with_Func()
{
	srand(time(NULL));
	

	int* arr1;
	int* arr2;
	char* arr3;
	char* arr4;
	float* arr5;
	float* arr6;
	double* arr7;
	double* arr8;


	bool exit = true;
	int choice;
	int choice_;
	size_t index, index2;


	size_t err = 17;


	cout << "input size: \n";
	
	size_t s;
	cin >> s;
	while (exit)
	{
		cout << "1 - int no err\n";
		cout << "2 - int err\n";
		cout << "3 - char no err\n";
		cout << "4 - char err\n";
		cout << "5 - float no err\n";
		cout << "6 - float err\n";
		cout << "7 - double no err\n";
		cout << "8 - double err\n";
		cout << "0 - exit\n";
		cin >> choice;


		switch (choice)
		{
		case 1:
			 arr1 = new int[s];
			randomize<int>(arr1, s);
			
			
			try {
				d_array<int>(arr1, s);
			}
			catch (const char* ex)
			{
				cout << ex << endl;
			}

			break;
		case 2:
			 arr2 = new int[err];
			randomize<int>(arr2, err);
			
			
			try {
				d_array<int>(arr2, err);
			}
			catch (const char* ex)
			{
				cout << ex << endl;
			}

			break;
		case 3:
			 arr3 = new char[s];
			randomize<char>(arr3, s);
			
			
			try {
				d_array<char>(arr3, s);
			}
			catch (const char* ex)
			{
				cout << ex << endl;
			}

			break;
		case 4:
			 arr4 = new char[err];
			randomize<char>(arr4, err);
			
			
			try {
				d_array<char>(arr4, err);
			}
			catch (const char* ex)
			{
				cout << ex << endl;
			}

			break;
	case 5:
			 arr5 = new float[s];
			randomize<float>(arr5, s);
			
			
			try {
				d_array<float>(arr5, s);
			}
			catch (const char* ex)
			{
				cout << ex << endl;
			}

			break;
		case 6:
			 arr6 = new float[err];
			randomize<float>(arr6, err);
			
			
			try {
				d_array<float>(arr6, err);
			}
			catch (const char* ex)
			{
				cout << ex << endl;
			}

			break;
		case 7:
			 arr7 = new double[s];
			randomize<double>(arr7, s);
			
			
			try {
				d_array<double>(arr7, s);
			}
			catch (const char* ex)
			{
				cout << ex << endl;
			}

			break;
		case 8:
			 arr8 = new double[err];
			randomize<double>(arr8, err);
			
			
			try {
				d_array<double>(arr8, err);
			}
			catch (const char* ex)
			{
				cout << ex << endl;
			}

			break;
	

		case 0:
			exit = false;
		
		}


	}


}

int main()
{

	bool e = true;
	int i;
	while (e)
	{ 
		cout << "Func = 1, Vector = 2, exit = 0\n";
		cin >> i;
	if(i == 1)
	work_with_Func();
	if (i == 2)
	work_with_Vector();
	if (i == 0)
		e = false;
		
	}
	return 0;



}
