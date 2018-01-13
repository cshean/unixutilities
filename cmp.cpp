#include <iostream>
#include <string>
#include <vector>

int main(int argc, char * argv[]){
	std::cout << argv[1] << std::endl;
	std::cout << argc << std::endl;
	if (argc < 3) {
		return 0;
	} else if ((argc > 3 && argv[1] != "-l") || (argc > 3 && argv[1] != "-s") ) {
		std::cout << "invalid --ignore-intial value '" << argv[3] << "'" << std::endl; 
		std::cout << "Try 'cmp --help' for more information" << std::endl;
	} else {
		std::cout << "ok" << std::endl;
	}
	return 0;
}