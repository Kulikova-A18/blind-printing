#define _CRT_SECURE_NO_WARNINS

#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <stdio.h>
#include <cstdio>
#include <cstring>
#include <string.h>
#include <wchar.h>
#include <ctime>
#include <clocale>

#include "print.h"

using namespace std;

char a;

bool _bool = false;

int main()
{
	srand((unsigned int)time(0));
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	size_t length = sizeof(data_print) / sizeof(*data_print);
	for (int i = 0; i < length; i++) {
		int random = rand() % length + 1;

		char* char_arr;
		string str_obj(data_print[random]);
		char_arr = &str_obj[0];
		cout << char_arr << endl;

		for (int k = 0; k < str_obj.length(); k++) {
			while (_bool == false) {

				char _a = '\0';
				while (_a == '\0') {
					if (_kbhit()) {
						a = _getch();
						if (a == char_arr[k]) {
							cout << a;
						}
						else {
							SetConsoleTextAttribute(hConsole, 12);
							cout << a;
						}
						_a = a;
						a = '\0';
					}
					SetConsoleTextAttribute(hConsole, 7);
				}
				_bool = !_bool;
				_a = '\0';
			}
			_bool = false;
		}
		system("cls");
	}
	return 0;
}
