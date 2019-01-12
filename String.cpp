#include "String.h"

void String::append(String str) {
	size_t res_size;
	if (this->size != 0) {
		res_size = this->size + str.size - 1;
		char* sym2 = new char[res_size];
		for (int i = 0; i < this->size - 1; ++i) {	//copy source str to the new
			sym2[i] = this->sym[i];
		}
		for (int i = this->size - 1; i < this->size + str.size - 1; ++i) {	//add the str into the new str
			sym2[i] = str.sym[i - (this->size) + 1];
		}
		delete[] sym;
		this->sym = sym2;
		this->size = this->size + str.size - 1;
	}else {
		delete[] sym;
		this->sym = str.sym;
		this->size = str.size;
	}
}

String* String::split(const char* delim) {

	bool begin_flag = false, end_flag = false;
	if (!strcmp(substr(0, strlen(delim)).sym, delim)) {	//check delim at the begin
		begin_flag = true;
	}
	if (!strcmp(substr(size - strlen(delim) - 1, strlen(delim)).sym,delim)) {	//check delim at the end
		end_flag = true;
	}
	size_t arr_size;
	if (begin_flag^end_flag) {			//define size of array
		arr_size = this->count_word(delim);
	}
	else if (!begin_flag && !end_flag) {
		arr_size = this->count_word(delim) + 1;
	}
	else if (begin_flag && end_flag) {
		arr_size = this->count_word(delim) - 1;
	}

	String source = *this;
	String* arr = new String[arr_size];
	size_t arr_count = 0;
	int i = 0;
	int prev_begin = 0;
	int n = 0, m = 0;
	if (begin_flag) {
		i = strlen(delim);	//if the first word is delim
		prev_begin = i;
	}
	
	while(i < source.size - strlen(delim)+1) {
		if (!strcmp((source.substr(i, strlen(delim))).sym, delim)) {	//if word after i is the delim
			arr[arr_count] = source.substr(prev_begin, i - prev_begin);	//put it to the array
			arr_count++;
			i += strlen(delim) - 1;
			prev_begin = i+1;
		}
		++i;
	}
	if (!end_flag) {	//if no delim in the end of string
		arr[arr_count] = source.substr(prev_begin, i - prev_begin + 1); //add leftover word to the end
	}

	return arr;
}

size_t String::find(String str, size_t pos) {
	int i = pos, j = 0;
	while (i < size) {
		while (sym[i] == str.sym[j] && j < str.size) {
			++i; ++j;
		}
		if ((str.sym[j] != '\0' && j == str.size-1) || (str.sym[j] == '\0' && j == str.size-1)) {
			return i - j;
		}
		else {
			j = 0;
		}
		++i;
	}
}

void String::format(String str1, String str2) {
	String result;
	bool begin_flag = false, end_flag = false;
	if (substr(0, str1.size - 1) == str1) {	//check str1 at the begin
		begin_flag = true;
	}
	if (substr(size - str1.size, str1.size) == str1) {	//check str1 at the end
		end_flag = true;
	}
	size_t arr_size;
	if (begin_flag ^ end_flag) {	//define size of array
		arr_size = this->count_word(str1);
	}else if (!begin_flag && !end_flag) {
		arr_size = this->count_word(str1) + 1;
	}else if (begin_flag && end_flag) {
		arr_size = this->count_word(str1) - 1;
	}
	String* arr = new String[arr_size];
	char* delim = str1.to_char();
	arr = this->split(delim);	//split string

	if (!begin_flag) {
		for (int i = 0; i < arr_size-1; ++i) {
			result.append(arr[i]);
			result.append(str2);
		}
		if (end_flag) {
			result.append(arr[arr_size - 1]);
			result.append(str2);
		}else {
			result.append(arr[arr_size - 1]);
		}
	}
	else if (begin_flag) {
		for (int i = 0; i < arr_size; ++i) {
			result.append(str2);
			result.append(arr[i]);
		}
	}
	*this = result;
}

void String::clean() {
	delete[] sym;
	sym = new char[0];
	size = 0;
}

size_t String::count_word(String str, size_t pos) {
	int i = pos, count = 0;
	while (i < size) {
		int j = 0;
		while (sym[i] == str.sym[j] && j < str.size - 1) {
			++i; ++j;
		}
		if (j == str.size - 1) {
			count++;
		}
		++i;
	}
	return count;
}

void String::print() {
	std::cout << sym << std::endl;
}

void String::print_arr(size_t size) {
	for (int i = 0; i < size; i++) {
		std::cout << this[i].sym << std::endl;
	}
}

String String::substr(size_t begin, size_t count) {
	char* ch = new char[count + 1];
	size_t j = 0;
		for(int i = begin; i < begin+count; ++i){
			ch[j] = this->sym[i];
			j++;
		}ch[j] = '\0';
		String result(ch);
	return result;
}

char* String::to_char() {
	char* result = new char[size];
	for (int i = 0; i < size; ++i) {
		result[i] = sym[i];
	}
	return result;
}

