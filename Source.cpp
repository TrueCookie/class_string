#include <iostream>
#include "conio.h"
#include "String.h"

int main() {
	String how("how that works");
	String question("?");
	how.append(question);

	how.print();
	String* arr1 = new String[how.count_word(" ")+1];
	arr1 = how.split();
	arr1->print_arr(3);
	std::cout << how.find("that");

	String who("I might be a sinner");
	who.substr(2, 7).print();
	who.change("sinner", "saint");
	who.print();

	_getch();
	return 0;
}

