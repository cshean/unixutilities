#include <iostream>
#include <fstream>
#include <string>
#include <vector>

//function overloading for when the user does and does not specify a 
//command line argument
//------------------------------------------------------------------
void compareFiles(std::string file1Name, std::string file2Name){
	std::vector<std::string> file1Lines;
	std::ifstream file1(file1Name);
	if (file1.is_open()) {
		std::string fileLine;
		while (std::getline(file1, fileLine)) {

			file1Lines.push_back(fileLine);
		}
	} else {
		std::cout << "cmp: " << file1Name << ": No such file or directory" << std::endl;
	}
} 

void compareFiles(std::string file1, std::string file2, std::string option) {
	std::cout << "option" << std::endl;
}




int main(int argc, char * argv[]){
	if (argc < 3) {
		std::cout << "invalid number of files" << std::endl;  
		std::cout << "Try 'cmp --help' for more information" << std::endl;
	} else if (argc > 3 && std::string(argv[1]) != "-l" && std::string(argv[1]) != "-s") {
		std::cout << "invalid --ignore-initial value '" << argv[3] << "'" << std::endl; 
		std::cout << "Try 'cmp --help' for more information" << std::endl;
	} else {
		argc > 3 ? compareFiles(std::string(argv[2]), std::string(argv[3]), std::string(argv[1])) : compareFiles(std::string(argv[1]), std::string(argv[2]));
	}
	return 0;
}