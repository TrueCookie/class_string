#include "String.h"

void String::append(String str) {
	char* sym2 = new char[this->size + str.size - 1];	//размер суммы исходной и доп строки
	for (int i = 0; i < this->size; ++i) {	//копируем в новую строку исходную
		sym2[i] = this->sym[i];
	}
	for (int i = this->size-1; i < this->size + str.size-1; ++i) {	//добавляем в новую строку дополнительную
		sym2[i] = str.sym[i-(this->size)+1];
	}
	delete[] sym;
	this->sym = sym2;
	this->size = this->size + str.size - 1;
}

String* String::split(const char delim) {
	size_t count = 0;
	int i = 0;
	String* p_arr = new String[count];
	while (i < size) {
		char* word = new char;
		int j = 0;
		while (sym[i] != delim && i < size) {
			word[j] = sym[i];
			j++; i++;
		}word[j] = '\0';
		count++;
		String* tmp_arr = p_arr;
		p_arr = new String[count];
		for (int k = 0; k < count - 1; k++) {
			p_arr[k] = tmp_arr[k];
		}delete[] tmp_arr;
		p_arr[count-1].sym = word;
		p_arr[count - 1].size = j+1;
		i++;
	}
	return p_arr;
}

size_t String::find(String str, size_t pos) {
	int i = pos, j = 0;
	while (i < size) {
		while (sym[i] == str.sym[j] && j < str.size) {
			++i; ++j;
		}
		if (j == str.size) {
			return i - j;
		}
		++i;
	}
}

void String::change(String str1, String str2) {
	size_t first_end = this->find(str1);
	size_t arr_size = this->count_word(str1)+1;
	String* arr = new String[arr_size];
	arr = this->split(*str1.sym);
	this->clean();
	arr->print_arr(arr_size);
	for (int i = 0; i < arr_size; ++i) {
		this->append(arr[i]);
		this->append(str2);
	}this->append(arr[arr_size-1]);
	size = this->size;
	sym = this->sym;
}

void String::clean() {
	delete[] sym;
	sym = new char[0];
	size = 0;
}

size_t String::count_word(String str, size_t pos) {
	int i = pos, j = 0, count = 0;
	while (i < size) {
		while (sym[i] == str.sym[j] && j < str.size) {
			++i; ++j;
		}
		if (j == str.size) {
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

String String::substr(size_t begin, size_t end) {
	char* ch = new char[end - begin + 1];
	size_t j = 0;
		for(int i = begin; i < end; ++i){
			ch[j] = this->sym[i];
			j++;
		}ch[j] = '\0';
		String result(ch);
	return result;
}