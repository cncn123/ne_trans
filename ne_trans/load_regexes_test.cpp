/*
 * load_regexes_test.cpp
 *
 *  Created on: Nov 24, 2016
 *      Author: parallels
 */

#include "ne_recognizer_resource.h"
#include "boost/algorithm/string.hpp"
#include <vector>
#include <string>
#include <iostream>
using namespace std;
using namespace boost;

int main(int argc,  char* argv[]){
	const char* file_path="/home/parallels/mars_workspace/ne_trans/ne_trans/DATA.txt";

	bool value = ne_recognizer_resource::load_regexes(file_path);
	std::cout << "ALL DONE"<<"\t"<< value << endl;

	return 0;
}
