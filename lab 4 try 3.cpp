/*Дано рядок. Дописати до нього мінімальну кількість символів так, щоб він став
паліндромом.*/

#include "pch.h"
#include <iostream>
using namespace std;
void proverka_pal(char str[], int *pk);// если к = 0 , конец,если к =1, идем дальше 
void add(char*row, int num)
{
	int n = strlen(row);
	for (int k = 0; k < num; k++)
		row[n + k] = row[num - 1 - k];
	row[n + num] = '\0';
}
bool is_palindropme(char*row) {
	int n = strlen(row);
	for (int i = 0; i < n / 2; i++)
		if (row[i] != row[n - 1 - i])
			return false;
	return true;
}
int count(char str2[], char str[])
{
	int cnt=0;
	int n = strlen(str);
	int k = strlen(str2);
	cnt = k - n;
	return cnt;
}


int main()
{
	setlocale(LC_ALL, "rus");
	char str[80];
	char str2[200];
	gets_s(str);
	int k = 0; // если к = 0, конец, если к = 1, идем дальше
	proverka_pal(str, &k);
	if (k == 0)
	{
		cout << " we don't need to do anything as the string is already a palindrom";
	}
	else
	{
		int n = strlen(str);
		for (int num = 1; num < n; num++) {
			strcpy_s(str2, str);
			add(str2, num);

			if (is_palindropme(str2)) break;
		}
		cout << str2 << endl;
		cout<<"we need to add "<<count(str2, str)<<" symbols";//посчитать сколько символов нужно дописать чтоб он стал палиндромом
	}



}
void proverka_pal(char str[], int *pk)// если к = 0 , конец,если к =1, идем дальше 
{
	int i, j;
	int identify = 1;// проверка палиндром или нет
	int len = strlen(str) - 1;

	for (i = 0, j = len; i <= strlen(str) / 2; ++i, --j)
	{

		if (str[j] != str[i])
		{
			identify = 0; break;
		}
	}
	if (identify == 1)
	{
		cout << "string is a palindrom" << endl;
		*pk = 0;
	}
	else
	{
		cout << "string is not a palindrom" << endl;
		*pk = 1;
	}

}