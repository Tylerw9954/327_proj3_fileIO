
/*
 * FileReader.cpp
 *
 *  Created on: Oct 8, 2017
 *      Author: keith
 */
#include <iostream>
#include <fstream>
#include "../327_proj3_test/includes/FileIO.h"
#include "../327_proj3_test/includes/constants.h"

using namespace std;

//namespace KP_FileIO{
//trys to open filename, and return its contents in contents
//it will strip out only \n's (char return\line feed)
//returns:
//SUCCESS all worked, contents string contains all in the file
//COULD_NOT_OPEN_FILE_TO_READ contents string is cleared
int KP_FileIO::getFileContents(const std::string &filename, std::string &contents)
{
	fstream inS;
	contents = "";
	inS.open(filename.c_str());
	if(!inS.is_open())
		return COULD_NOT_OPEN_FILE_TO_READ;

	string curline = "";
	while(!inS.eof()){
		//pretty sure this follows requirements
		getline(inS, curline);
		contents += curline;
	}
	//close and exit successfully
	inS.close();
	return SUCCESS;
}


//trys to open filename, and serialize  myEntryVector contents to it
//returns:
//SUCCESS all worked, filename contains myEntryVector strings
//COULD_NOT_OPEN_FILE_TO_WRITE
int KP_FileIO::writeVectortoFile(const std::string filename,std::vector<std::string> &myEntryVector)
{
	fstream outS;
	outS.open(filename.c_str());

	//Shouldn't happen but ok?
	if(!outS.is_open())
		return COULD_NOT_OPEN_FILE_TO_WRITE;

	//adds all non "" to cout with each entry being its own line
	for(string add: myEntryVector){
		if(add != ""){
			outS << add << endl;
		}
	}
	//close and exit successfully
	outS.close();
	return SUCCESS;
}
//}






