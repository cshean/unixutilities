#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Options {
	vector<std::string> fileNames;
	bool lOption = false;
	bool sOption = false;

	public: 
		Options(int argc, char * argv[]){

			//if there are less than two command line args, print error message
			if (argc < 3) {
				std::cout << "invalid number of files" << std::endl;  
				std::cout << "Try 'cmp --help' for more information" << std::endl;
			//if the option used was invalid, print error message 
			} else if ((argc > 3 && argc < 5) && (std::string(argv[1]) != "-l" && std::string(argv[1]) != "-s")) {
				std::cout << "invalid --ignore-initial value '" << argv[3] << "'" << std::endl; 
				std::cout << "Try 'cmp --help' for more information" << std::endl;
			// if the number of files is correct
			} else {
				//check for command line options, and set the flag based on whether or not the option is selected
				fileNames.push_back(std::string(argv[2]));
				fileNames.push_back(std::string(argv[3]));
				(std::string(argv[1]) == "-l") ? lOption = true : sOption = true; 
			}
		}

		//accessor methods for classes' variables
		vector<std::string> getFileNames() { return fileNames; }
		bool getLOption() { return lOption; }
		bool getSOption() { return sOption; }
	
};

void findByte(int index, int numbytes, Options option, string file1Line, string file2Line){
	for(int i = 0; i < file1Line.size(); ++i){
		if (file1Line.at(i) != file2Line.at(i)) {
			cout << option.getFileNames().at(0) << " " << option.getFileNames().at(1) << "differ: byte " << (numbytes + i) << ", line " << index << endl; 
		}
	}
}

//function that takes an Options argument and checks whether or not the two files
//contained in that options object's vector of file names are equal
void compareFiles(Options option){
	
	vector<std::string> file1Lines;
	std::ifstream file1(option.getFileNames().at(0));

	//if the file exists
	if (file1.is_open()) {
		std::string fileLine;

		//insert all the lines in the file into a vector
		while (std::getline(file1, fileLine)) {
			file1Lines.push_back(fileLine);
		}
		//close the file and create a new stream for the second file
		file1.close();
		std::ifstream file2(option.getFileNames().at(1));

		//if opening the file worked
		if (file2.is_open()) {
			int index = 0;
			int numbytes = 0;
			//while there is a new line in the file, compare it to the old file
			while (std::getline(file2, fileLine)) {
			
				//if the second file is longer than the first, print that and close file
				if (index >= file1Lines.size()) {
					findByte(index, numbytes, option, "", "");
					file2.close();
					return;
				//ignore if the lines are equal
				} else if (fileLine == file1Lines.at(index)){
					numbytes+=fileLine.size();
					index++;
					continue;
				//if the lines are different, use separate method to find the first character that is different
				} else {
					findByte(index, numbytes, option, file1Lines.at(index), fileLine);
					file2.close();
					return;
				}
			}
		} else {
			std::cout << "cmp: " << option.getFileNames().at(1) << ": No such file or directory" << std::endl;
		}
	//if the first file does not exist, print that fact along with the name
	} else {
		std::cout << "cmp: " << option.getFileNames().at(0) << ": No such file or directory" << std::endl;
	}
} 





int main(int argc, char * argv[]){
	Options option(argc, argv);
	compareFiles(option);
	return 0;
}