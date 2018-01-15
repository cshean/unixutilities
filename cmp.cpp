#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void findAndPrintByte(std::string line1, std::string line2, std::string file1Name, std::string file2Name, int index){
	if (line1 == "") {
		std::cout << file1Name << " " << file2Name << " differ at byte 0 on line " << index << std::endl;
	}

	for (int i = 0; i < line1.size(); ++i){
		if (line1.at(i) != line2.at(i)){
			std::cout << file1Name << " " << file2Name << " differ at byte " << i << " on line " << index << std::endl;
			return;
		}
	}
}


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
		file1.close();
		std::ifstream file2(file2Name);

		if (file2.is_open()) {
			int index = 0;
			
			while (std::getline(file2, fileLine)) {
				if (index >= file1Lines.size()) {
					findAndPrintByte("", fileLine, file1Name, file2Name, index);
					file2.close();
					return;
				} else if (fileLine == file1Lines[index]){
					continue;
				} else {
					findAndPrintByte(file1Lines[index], fileLine, file1Name, file2Name, index);
					file2.close();
					return;
				}
			}
		} else {
			std::cout << "cmp: " << file2Name << ": No such file or directory" << std::endl;
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