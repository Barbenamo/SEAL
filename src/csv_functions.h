#ifndef CSV_FUNCTIONS_H
#define CSV_FUNCTIONS_H

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

std::vector<std::vector<std::string>> read_csv(std::string fname);

void PrintContentFromCSV(std::string fileName);

void PrintContentFromNestedVector(std::vector<std::vector<std::string>> content);

#endif  //CSV_FUNCTIONS_H