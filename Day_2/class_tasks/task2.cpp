#include <iostream>
#include <map>

int main(){

	std::map<std::string,int> map1;

	map1["one"] = 1;
	map1["two"] = 2;
	map1["three"] = 3;
	map1["four"] = 4;
	map1["five"] = 5;
	map1["six"] = 6;
	map1["seven"] = 7;
	map1["eight"] = 8;
	map1["nine"] = 9;


	std::cout << "Test " << map1["three"] << std::endl;

}

int LookUp (const std::map c, std::string) {
}
