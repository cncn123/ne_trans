/*
 * boost_regex_work.cpp
 *
 *  Created on: Nov 18, 2016
 *      Author: parallels
 */
#include "boost_regex_work.h"
#include "wchar_converter.h"
#define INIT_ws_LEN 200
#define INIT_re_LEN 100

normal_regulation_regex::normal_regulation_regex{
	ws_ = (char*) calloc(INIT_ws_LEN, sizeof(char));
	ws_len_ = INIT_ws_LEN;
	re_= (char*) calloc(INIT_re_LEN, sizeof(char));
	re_len_=INIT_re_LEN;
}

normal_regulation_regex::~normal_regulation_regex(){
	if (NULL == ws_)
		{
			free (ws_);
			ws_ = NULL;
		}
	if (NULL == re_){
		free(re_);
		re_=NULL;
	}
}

bool normal_regulation_regex::make_regex(const string& input_re){
	if(!(wchar_converter::utf8_to_wchar(input_re, s))){
		return false;
	}
	return true;
	/*boost::u32regex wr=boost::make_u32regex(input_re);
	if(wr==NULL){
		return false;
	}
	return true;*/
}

bool normal_regulation_regex::unicode_convert(const string& input_ws){
	 icu::StringPiece wq(input_ws);
	 ustr=UnicodeString::fromUTF8(wq);
	 if(ustr==NULL){
		 return false;
	 }
	 return true;

}

UChar* normal_regulation_regex::regex_match(){
	boost::u32regex_token_iterator<const UChar*> i(boost::make_u32regex_token_iterator(ustr,wr,1)),j;
	while(i!=j){
	//  std::cout<< (*i) << std::endl
	    const UChar * px = (*i).first;
	    std::cout << std::hex << px << std::endl;
	//  std::basic_string<UChar> x = (*i).str();
	    std::cout << "length = " << (*i).length() << std::endl;
	    std::cout << "content = ";
	    for (int idx = 0; idx < (*i).length(); ++idx)
	    {
	    	std::cout << std::hex << px[idx] << " " ;
	    }
	    std::cout << std::endl;
	    ++i;
	    }
	return px;
}

bool boost_regex_work::realloc_buf(const int _new_ws_len) {
	if (_new_ws_len > ws_len_)
	{
		ws_len_ = _new_ws_len;//
	}
	wr = (char*) calloc(_new_ws_len, sizeof(char));
	if (NULL == buf_)
	{
		ws_len_ = 0;
		return false;
	}
	buf_len_ = _new_buf_len;
	return true;
}
