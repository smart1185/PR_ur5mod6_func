#include <stdio.h>
#include <iostream>
#include <locale.h>

using namespace std;
void fillArr(int *arr, int length);
void printArr(int * arr, int countEl);
string Sum(const string s1, const string s2);
void smooth(int arr[], int N);
int f(int h, int m, int s);
int f(int m, int d);
int IsLeapYear(int year);
int Day(int M, int D);
int F(int M, int D);
int f(int N);
int F(int m1, int m2, int m3);
int V(int m1, int m2, int m3);
int min(int m1, int m2, int m3);
bool even(int n);
void D(int m, int n);

int main()
{
	setlocale(LC_ALL, "Russian");
	int  N;
	do
	{
		cout << "\t\t----Введите номер задания: ";
		cin >> N;
		cout << endl;
		switch (N)
		{
		case 1:
			
		{
			Sum("100111111", "1");
			cout << Sum << endl;
		}
		cout << endl;
		break;

		case 2:
			
		{
			int N;
			cout << "Ââåäèòå ðàçìåðíîñòü ìàññèâà:" << endl;
			cin >> N;


			int arr[] = { 0 };
			int length = N;
			fillArr(arr, N);
			int countEl = N;
			printArr(arr, N);
			smooth(arr, N);
		}
		cout << endl;
		break;

		case 3:
			
		{
			int h = 0, m = 0, s = 0;
			cout << "Point the current time " << endl;
			cin >> h >> m >> s;

			cout << "It had been taken: " << f(h, m, s) << " seconds" << endl;

		}
		cout << endl;
		break;

		case 4:
			
		{
			int d, m;

			cout << "Point the current date " << endl;
			cin >> d >> m;

			cout << "It had been taken: " << f(m, d) << " days" << endl;
		}
		cout << endl;
		break;

		case 5:
			
		{
			int D = 0, M = 0;

			cout << "Point the current date " << endl;
			cin >> D >> M;

			cout << "It had been taken: " << F(M, D) << " days" << endl;
		}
		cout << endl;
		break;

		case 6:
			
		{
			int N = 0;
			cout << "Print the number " << endl;
			cin >> N;

			if (N < 99)
				f(N);
			else
				cout << "Number is wrong " << endl;
		}
		cout << endl;
		break;

		case 8:
			
		{

			int m1 = 0, m2 = 0, m3 = 0;
			cout << "Print the number " << endl;
			cin >> m1;

			cout << "Print the number " << endl;
			cin >> m2;

			cout << "Print the number " << endl;
			cin >> m3;

			F(m1, m2, m3);

		}
		cout << endl;
		break;

		case 9:
			
		{
			int m1 = 0, m2 = 0, m3 = 0;
			cout << "Print the number " << endl;
			cin >> m1;

			cout << "Print the number " << endl;
			cin >> m2;

			cout << "Print the number " << endl;
			cin >> m3;

			V(m1, m2, m3);
		}
		cout << endl;
		break;

		case 10:
			
		{
			int m1 = 0, m2 = 0, m3 = 0;
			cout << "Print the number " << endl;
			cin >> m1;

			cout << "Print the number " << endl;
			cin >> m2;

			cout << "Print the number " << endl;
			cin >> m3;

			min(m1, m2, m3);
		}

		case 11:
		{
			int n = 0;
			cout << "Print the number " << endl;
			cin >> n;

			even(n);
		}
		cout << endl;
		break;

		case 12:
			
		{
			int n = 0;
			int m = 0;
			cout << "Print the number " << endl;
			cin >> m;

			cout << "Print the number " << endl;
			cin >> n;

			D(m, n);
		}
		break;
		default: {cout << "Задания с таким номером не существует" << endl; }
		}
	} while (N > 0 && N < 13);
	cout << "\t\t\t\t\tКОНЕЦ." << endl;
	system("pause");
}



void fillArr(int *arr, int length)
{

	for (int i = 0; i < length; i++)
		arr[i] = 1 + rand() % 100;

}

void printArr(int * arr, int countEl)
{
	for (int i = 0; i < countEl; i++)
		cout << "arr[" << i << "]=" << arr[i] << endl;
}

string Sum(const string s1, const string s2)
{
	int len1 = s1.size();
	int len2 = s2.size();	
	string ls1 = len1<len2 ? s1 : s2;
	string ls2 = len1<len2 ? s2 : s1;
	for (int i = ls1.size(); i < ls2.size(); ++i) ls1 = '0' + ls1;

	string result;
	int carry = 0;
	for (int i = ls2.size() - 1; i >= 0; --i) {
		int bit1 = ls1.at(i) - '0'; 
		int bit2 = ls2.at(i) - '0';
		char sum = (bit1 ^ bit2 ^ carry) + '0';
		result = sum + result;
		carry = (bit1&carry) | (bit2&carry) | (bit1&bit2);
	}
	if (carry) result = '1' + result;
	return result;

}

void smooth(int arr[], int N)
{
	cout << "Ñãëàæåííûé ìàññèâ:" << endl;
	for (int i = 0; i < N - 1; i++)
		arr[i] = (arr[i] + arr[i + 1] + arr[i - 1]) / 3;


	for (int i = 0; i < N; i++)
		cout << arr[i] << endl;
}

int f(int h, int m, int s)
{

	return ((h >= 12 ? h - 12 : h) * 3600 + m * 60 + s);
}

int f(int m, int d)
{
	return (d + ((m - 1) * 30));

}

int IsLeapYear(int year)
{
	if ((year % 100 == 0 && year % 400 != 0) || year % 4 == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int Day(int M, int D)
{
	switch (M)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
		break;
	case 2:
		if (IsLeapYear == 0)
		{
			return 28;
		}
		else
		{
			return 29;
		}
		break;
	}
}

int F(int M, int D)
{
	return (D + ((M - 1) * Day(M, D)));
}

int f(int N)
{
	int x = 0, y = 0;

	x = N / 10;
	y = N % 10;

	cout << "First number is " << x << endl;
	cout << "Second number is " << y << endl;
	return x, y;
}

int F(int m1, int m2, int m3)
{
	int min = 0;
	if (m1 < m2 && m3 > m1)
	{
		min = m1;
		cout << min << " - is the min" << endl;
	}

	else if (m1 > m2 && m3 > m2)
	{
		min = m2;
		cout << min << " - is the min" << endl;
	}

	else if (m1 > m3 && m3 < m2)
	{
		min = m3;
		cout << min << " - is the min" << endl;
	}
	return min;
}

int V(int m1, int m2, int m3)
{
	int sum;

	if ((m1 > 1 && m1 < 999) && (m2 > 1 && m2 < 999) && (m3 > 1 && m3 < 999))
	{
		sum = m1 + m2 + m3;
		cout << "Summa ravna = " << sum << endl;
	}

	else if ((m1 < 1 || m1 > 999) && (m2 > 1 && m2 < 999) && (m3 > 1 && m3 < 999))
	{
		sum = m2 + m3;
		cout << "Summa ravna = " << sum << endl;
	}

	else if ((m2 < 1 || m2 > 999) && (m1 > 1 && m1 < 999) && (m3 > 1 && m3 < 999))
	{
		sum = m1 + m3;
		cout << "Summa ravna = " << sum << endl;
	}
	else if ((m3 < 1 || m3 > 999) && (m2 > 1 && m2 < 999) && (m1 > 1 && m1 < 999))
	{
		sum = m1 + m2;
		cout << "Summa ravna = " << sum << endl;
	}

	else if ((m3 < 1 || m3 > 999) && (m2 < 1 || m2 > 999) && (m1 > 1 && m1 < 999))
	{
		sum = m1;
		cout << "Summa ravna = " << sum << endl;
	}

	else if ((m3 < 1 || m3 > 999) && (m1 < 1 || m1 > 999) && (m2 > 1 && m2 < 999))
	{
		sum = m2;
		cout << "Summa ravna = " << sum << endl;
	}

	else if ((m1 < 1 || m1 > 999) && (m2 < 1 || m2 > 999) && (m3 > 1 && m3 < 999))
	{
		sum = m3;
		cout << "Summa ravna = " << sum << endl;
	}

	return sum;

}

int min(int m1, int m2, int m3)
{
	int min;

	if (m1 < m2 && m3 > m1)
	{
		min = m1;
		cout << min << " - is the min" << endl;
	}

	else if (m1 > m2 && m3 > m2)
	{
		min = m2;
		cout << min << " - is the min" << endl;
	}

	else if (m1 > m3 && m3 < m2)
	{
		min = m3;
		cout << min << " - is the min" << endl;
	}
	return min;

}

bool even(int n)
{
	int result;
	if (n % 2 == 0)
	{
		result = 1;
		cout << "True " << endl;
	}

	else
	{
		result = 0;
		cout << "False " << endl;
	}

	return result;
}

void D(int m, int n)
{
	if (n % m == 0)
	{
		cout << "×èñëî " << n << " êðàòíî ÷èñëó " << m << endl;
	}
	else
	{
		cout << "×èñëî " << n << " íåêðàòíî ÷èñëó " << m << endl;
	}

}