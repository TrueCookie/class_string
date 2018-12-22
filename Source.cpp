#include <iostream>
#include "conio.h"
#include "String.h"

int main() {
	String how("how that works");
	String question("?");
	how.append(question);

	how.print();
	size_t arr_size = how.count_word(" ") + 1;
	String* arr1 = new String[arr_size];
	arr1 = how.split();	
	arr1->print_arr(arr_size);
	std::cout << how.find("that") << std::endl;
	String work("work");
	std::cout << how.find(work) << std::endl;

	String who("I might be a sinner");
	who.substr(2, 7).print();
	//who.change("sinner", "saint");
	//who.print();

	_getch();
	return 0;
}

