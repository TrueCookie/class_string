#include <iostream>
#include "conio.h"
#include "String.h"

int main() {
	String how("how that works");
	String how1(" how ");
	String that2(" that");
	String works3("works ");
	String question("?");
	how.append(question);

	how.print();

	size_t arr_size = how.count_word(" ") + 1;
	String* arr = new String[arr_size];
	arr = how.split(" ");	
	std::cout << "split check: "; arr->print_arr(arr_size);

	String who("I might be a sinner");
	who.substr(2, 5).print();
	who.format("sinner", "saint");
	who.print();

	who.format("I", "You");
	who.print();

	how.format(" ", "_");
	how.print();


	_getch();
	return 0;
}


