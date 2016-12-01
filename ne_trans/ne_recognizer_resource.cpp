/*
 * ne_recognizer_resource.cpp
 *
 *  Created on: Nov 18, 2016
 *      Author: parallels
 */

#include "ne_recognizer_resource.h"

ne_recognizer_resource::ne_recognizer_resource() {
	// TODO Auto-generated constructor stub

}

ne_recognizer_resource::~ne_recognizer_resource() {
	// TODO Auto-generated destructor stub
}

ne_non_trans* recognizer_date::do_recognize(wstring& _wstr, int& start) {

	//from start to the end of _wstr
	for (int i = 0; i < regex.size(); ++i)
	{

	}

	ne_date* ne_date = new ne_date();

	return ne_date;
}

bool ne_recognizer_resource::load_regexes(const char* _file) {


	/*boost::wregex reg()
	recognizer_date rec_date;
	rec_date.formatter.push_back(reg);
	recognizers.push_back(rec_date);*/

	ifstream fin(_file);
	if(!fin.is_open()){
		std::clog << ("Fail to open file\n");
		return 0;

	}
	string line;

	//recognizer_date rec_date;
	// array indicating the type of regex
	// read file line by line

	while (getline(fin,line)){
		formatter_traits ft;

		// regex \t format
		split_vector_type SplitVec_first;
		boost::split(SplitVec_first, line, is_any_of("\t"), token_compress_on);

		boost::wregex reg(SplitVec_first[0]);
		ft.pattern_ = reg;

		// type : description
		split_vector_type SplitVec_second;
		boost::split(SplitVec_second, SplitVec_first[1], is_any_of(":"), token_compress_on);

		split_vector_type SplitVec_third;
		boost::split(SplitVec_third, SplitVec_second[1], is_any_of(";"), token_compress_on);

		//the index of rule
		//int index;

		// judge the type "DATE"
		int valid_rule = 0;
		if(!SplitVec_second[0].compare("DATE")){
			//specify formatter type
			ft.type = "DATE";
			valid_rule = Date_partition(SplitVec_third,ft);
		}
		//num of valid rule
		ft.format_rule_len_ = valid_rule;
	}
	return true;
}

int Date_partition(split_vector_type SplitVec_third, formatter_traits ft){
	int index;
	int valid_rule = 0;

	for (int i = 1; i<SplitVec_third.size(); i++){
		// find index of "Year"
		if ( std::find(SplitVec_third[i].begin(), SplitVec_third[i].end(), "Year") != SplitVec_third[i].end() ){
			split_vector_type SplitVec_fourth;
			boost::split(SplitVec_fourth, SplitVec_third[i], is_any_of("="), token_compress_on);
			//index=atoi(SplitVec_third[i].substr(SplitVec_third[i].size()-1).c_str());
			index=atoi(SplitVec_fourth[1].c_str());
			ft.format_rule_[YEAR_IDX]=1;
			valid_rule++;
		}

		// find index of "Mon"
		if ( std::find(SplitVec_third[i].begin(), SplitVec_third[i].end(), "Mon") != SplitVec_third[i].end() ){
			split_vector_type SplitVec_fourth;
			boost::split(SplitVec_fourth, SplitVec_third[i], is_any_of("="), token_compress_on);
			//index=atoi(SplitVec_third[i].substr(SplitVec_third[i].size()-1).c_str());
			index=atoi(SplitVec_fourth[1].c_str());
			ft.format_rule_[MON_IDX]=1;
			valid_rule++;
		}

		// find index of "Day"
		if ( std::find(SplitVec_third[i].begin(), SplitVec_third[i].end(), "Day") != SplitVec_third[i].end() ){
			split_vector_type SplitVec_fourth;
			boost::split(SplitVec_fourth, SplitVec_third[i], is_any_of("="), token_compress_on);
			//index=atoi(SplitVec_third[i].substr(SplitVec_third[i].size()-1).c_str());
			index=atoi(SplitVec_fourth[1].c_str());
			ft.format_rule_[DAY_IDX]=1;
			valid_rule++;
		}
	}
	return valid_rule;

}



