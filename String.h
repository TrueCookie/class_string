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
		for (int i = 0; i < size; ++i) {
			sym[i] = str[i];
		}
	}

	void append(String);
	String* split(const char*);
	size_t find(String str, size_t pos = 0);
	void format(String str1, String str2);
	String substr(size_t begin, size_t end);
	char* to_char();

	void clean();
	size_t count_word(String str, size_t pos = 0);
	void print();
	void print_arr(size_t);

	bool operator==(String const & str) {
		int i = 0;
		while(sym[i] == str.sym[i] && i < size){
			++i;
		}
		return i == size;
	}

};
