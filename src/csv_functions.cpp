#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <interactive_icp.h>
#include <vector>

std::vector<std::vector<std::string>> read_csv(std::string fname){
	std::vector<std::vector<std::string>> content;
	std::vector<std::string> row;
	std::string line, word;
	std::fstream file (fname, ios::in);
	if(file.is_open())
	{
		while(getline(file, line))
		{
			row.clear();
			std::stringstream str(line);
			while(getline(str, word, ','))
				row.push_back(word);
			content.push_back(row);
		}
	}
	else
		std::cout<<"Could not open the file\n";
	// printing option - for self check
	// for(int i=0;i<content.size();i++)
	// {
	// 	for(int j=0;j<content[i].size();j++)
	// 	{
	// 		std::cout<<content[i][j]<<" ";
	// 	}
	// 	std::cout<<"\n";
	// }
	return content;

}

void PrintContentFromCSV(std::string fileName){

    std::string fname = "output0.csv";

    std::vector<std::vector<std::string>> content = read_csv(fname);  

        // Access and print the elements of the nested vector

    for (const std::vector<std::string>& innerVector : content) {

        for (const std::string& str : innerVector) {

            std::cout << str << " ";

        }

        std::cout << std::endl;

    }

}

void PrintContentFromNestedVector(std::vector<std::vector<std::string>> content){

        // Access and print the elements of the nested vector

    for (const std::vector<std::string>& innerVector : content) {

        for (const std::string& str : innerVector) {

            std::cout << str << " ";

        }

        std::cout << std::endl;

    }

}
