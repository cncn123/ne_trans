/*
 * wchar_converter_test.cpp
 *
 *  Created on: Nov 17, 2016
 *      Author: parallels
 */
#include "wchar_converter.h"
#include<iostream>
int main(int argc, char *argv[])
{
	using namespace std;
	wchar_converter wc;
	string instr = "fsfdadfa";
	string utf8_;
	wstring outstr;
	if (!wc.utf8_to_wchar(instr, outstr))
	{
		return -1;
	}
	wchar_t* outstr_1=L"nihao";
	if (!wc.wchar_to_utf8(outstr_1,utf8_))
	{
		return -1;
	}
	//std::cout<<utf8_<<std::endl;
	fprintf(stderr,"out: %s\n",utf8_.c_str());

	return 0;
}
