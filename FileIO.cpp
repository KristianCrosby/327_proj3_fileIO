/*
 * FileReader.cpp
 *
 *  Created on: 4/11/2020
 *      Author: Kristian Crosby
 */
#include <iostream>
#include <fstream>
#include "../327_proj3_test/includes/FileIO.h"
#include "../327_proj3_test/includes/constants.h"
#include <vector>
#include <iterator>

using namespace std;

const int ERROR_COULD_NOT_OPEN_FILE = -1;

int KP_FileIO::getFileContents(const std::string &filename, std::string &contents)
{
	contents.clear();

	ifstream inFile;
	inFile.open(filename, ios::in);
	if( !inFile.is_open()){
		std::string line;

		while(!inFile.eof()){
			getline(inFile, line);
			contents = contents + "" + line;
	}
	inFile.close();
	}else {
		return ERROR_COULD_NOT_OPEN_FILE;
	}
	inFile.close();
	return SUCCESS;
}


int KP_FileIO::writeVectortoFile(const std::string filename,std::vector<std::string> &myEntryVector)
{
	ofstream outFile;
	outFile.open(filename, ios::out);

	if(outFile.is_open()){

		for(vector<string>::iterator vec = myEntryVector.begin(); vec != myEntryVector.end(); vec++) {
			outFile << *vec << ' ';
		}
		outFile <<'\n';
		outFile.close();
	} else {
		return ERROR_COULD_NOT_OPEN_FILE;
	}
	return SUCCESS;

}


