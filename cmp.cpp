#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
//takes two strings, line1 and line2, and prints the first byte where they are different
void findAndPrintByte(std::string line1, std::string line2, std::string file1Name, std::string file2Name, int index){
	if (line1 == "") {
		std::cout << file1Name << " " << file2Name << " differ at byte 0 on line " << index << std::endl;
	} else if (line1.size() != line2.size()){
		int shorterLength = line1.size() > line2.size() ? line2.size() : line1.size();
		std::cout << file1Name << " " << file2Name << " differ at byte " << shorterLength << " on line " << index << std::endl;
	} else {

		for (int i = 0; i < line1.size(); ++i){
			if (line1.at(i) != line2.at(i)){
				std::cout << file1Name << " " << file2Name << " differ at byte " << i << " on line " << index << std::endl;
				return;
			}
		}
	}
}


//function overloading for when the user does and does not specify a 
//command line argument
void compareFiles(std::string file1Name, std::string file2Name){
	std::vector<std::string> file1Lines;
	std::ifstream file1(file1Name);

	//if the file exists
	if (file1.is_open()) {
		std::string fileLine;

		//insert all the lines in the file into a vector
		while (std::getline(file1, fileLine)) {
			file1Lines.push_back(fileLine);
		}
		//close the file and create a new stream for the second file
		file1.close();
		std::ifstream file2(file2Name);

		//if opening the file worked
		if (file2.is_open()) {
			int index = 0;
			int numbytes = 0;
			//while there is a new line in the file, compare it to the old file
			while (std::getline(file2, fileLine)) {
				numbytes+=fileLine.size();
				//if the second file is longer than the first, print that and close file
				if (index >= file1Lines.size()) {
					findAndPrintByte("", fileLine, file1Name, file2Name, index);
					file2.close();
					return;
				//ignore if the lines are equal
				} else if (fileLine == file1Lines.at(index)){
					index++;
					continue;
				//if the lines are different, use separate method to find the first character that is different
				} else {
					findAndPrintByte(file1Lines.at(index), fileLine, file1Name, file2Name, index);
					file2.close();
					return;
				}
			}
		} else {
			std::cout << "cmp: " << file2Name << ": No such file or directory" << std::endl;
		}
	//if the first file does not exist, print that fact along with the name
	} else {
		std::cout << "cmp: " << file1Name << ": No such file or directory" << std::endl;
	}
} 

void compareFiles(std::string file1, std::string file2, std::string option) {
	std::cout << "option" << std::endl;
}




int main(int argc, char * argv[]){
	//if there are less than two command line args, print error message
	if (argc < 3) {
		std::cout << "invalid number of files" << std::endl;  
		std::cout << "Try 'cmp --help' for more information" << std::endl;
	//if the option used was invalid, print error message 
	} else if (argc > 3 && std::string(argv[1]) != "-l" && std::string(argv[1]) != "-s") {
		std::cout << "invalid --ignore-initial value '" << argv[3] << "'" << std::endl; 
		std::cout << "Try 'cmp --help' for more information" << std::endl;
	// if the number of files is correct
	} else {
		//check for command line options, and use the appropriate logic based on whether or not one exists
		argc > 3 ? compareFiles(std::string(argv[2]), std::string(argv[3]), std::string(argv[1])) : compareFiles(std::string(argv[1]), std::string(argv[2]));
	}
	return 0;
}