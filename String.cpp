#include "String.h"

void String::append(String str) {
	char* sym2 = new char[this->size + str.size - 1];	//������ ����� �������� � ��� ������
	for (int i = 0; i < this->size; ++i) {	//�������� � ����� ������ ��������
		sym2[i] = this->sym[i];
	}
	for (int i = this->size-1; i < this->size + str.size-1; ++i) {	//��������� � ����� ������ ��������������
		sym2[i] = str.sym[i-(this->size)+1];
	}
	delete[] sym;
	this->sym = sym2;
	this->size = this->size + str.size - 1;
}

String* String::split(const char* delim) {
	String source = *this;
	size_t arr_size = source.count_word(delim) + 1;
	String* arr = new String[arr_size];
	size_t arr_count = 0;
	int begin = 0;
	int n = 0, m = 0;
	while (source.sym[n] == delim[m]) {
		++n; ++m;
	}
	if (m == strlen(delim)) {
		begin = m;	//if the first word is delim
	}
	int i = begin;
	int prev_begin = begin;
	while(i < source.size) {
		int j = 0;
		while (source.sym[i] == delim[j]) {
			++i; ++j;
		}
		if(j == strlen(delim)){
			arr[arr_count] = source.substr(prev_begin, i-j-prev_begin);	//from prev wordend to i
			arr_count++;
			prev_begin = i;
		}
		if (i == source.size - 1) {	//cut the last word
			arr[arr_count] = source.substr(prev_begin, i - prev_begin);
		}
		++i;
	}
	return arr;
}

//String* String::split(const char delim) {
//	size_t count = 0;
//	int i = 0;
//	String* p_arr = new String[count];
//	while (i < size) {
//		char* word = new char;
//		int j = 0;
//		while (sym[i] != delim && i < size) {
//			word[j] = sym[i];
//			j++; i++;
//		}word[j] = '\0';
//		count++;
//		String* tmp_arr = p_arr;
//		p_arr = new String[count];
//		for (int k = 0; k < count - 1; k++) {
//			p_arr[k] = tmp_arr[k];
//		}delete[] tmp_arr;
//		p_arr[count - 1].sym = word;
//		p_arr[count - 1].size = j + 1;
//		i++;
//	}
//	return p_arr;
//}

//String* String::split(const char* delim) {
//	size_t count = 0;
//	int i = 0;
//	String* p_arr = new String[count];
//	while (i < size) {
//		char* word = new char;
//		int j = 0, count_del = 0;
//		while (sym[i] != delim[j] && i < size) {
//			for (int k = i; k < i + strlen(delim); k++) {
//				if (sym[k] == delim[i - k]) {
//					count_del++;
//				}
//			}
//			if (count_del == strlen(delim)) {
//				break;
//			}
//			word[j] = sym[i];
//			j++; i++;
//		}word[j] = '\0';
//		count++;
//		String* tmp_arr = p_arr;
//		p_arr = new String[count];
//		for (int k = 0; k < count - 1; k++) {
//			p_arr[k] = tmp_arr[k];
//		}delete[] tmp_arr;
//		p_arr[count-1].sym = word;
//		p_arr[count - 1].size = j+1;
//		i++;
//	}
//	return p_arr;
//}

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

//void String::change(String str1, String str2) {
//	size_t first_end = this->find(str1);
//	size_t arr_size = this->count_word(str1)+1;
//	String* arr = new String[arr_size];
//	arr = this->split(str1.sym);	//or do split(char), it doesnt split
//	arr->print_arr(arr_size);
//	this->clean();
//	for (int i = 0; i < arr_size; ++i) {
//		this->append(arr[i]);
//		this->append(str2);
//	}this->append(arr[arr_size-1]);
//	size = this->size;
//	sym = this->sym;
//}

void String::format(String str1, String str2) {
	size_t arr_size = this->count_word(str1);
	String* arr = new String[arr_size];
	char* delim = str1.to_char();
	arr = this->split(delim);	//split string
	
	String result;
	if (substr(0, str1.size) == str1) {
		result.append(str2);
	}
	for (int i = 0; i < arr_size-1; ++i) {	//TODO: add case str1 in the begin and in the end of string
		result.append(arr[i]);
		result.append(str2);
	}result.append(arr[arr_size - 1]);
	if (substr(size - str1.size, str1.size) == str1) {
		result.append(str2);
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
		while (sym[i] == str.sym[j] && j < str.size) {
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
	for (int i = 0; i < size; ++i) {	//�������� � ����� ������ ��������
		result[i] = sym[i];
	}
	return result;
}

