#pragma once
#include <iostream>
class  String {
private:
	int size;
	char* sym;
public:
	String() {
		size = 0;
		sym = new char[size];
	}
	String(const char* str) {
		size = strlen(str) + 1;
		sym = new char[size];
		for (int i = 0; i < size; ++i) {	//копируем в новую строку исходную
			sym[i] = str[i];
		}
	}

	void append(String);
	String* split(const char delim = ' ');
	size_t find(String str, size_t pos = 0);
	void change(String str1, String str2);

	void clean();
	size_t count_word(String str, size_t pos = 0);
	void print();
	void print_arr();
};
