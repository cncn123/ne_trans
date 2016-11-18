/*
 * boost_regex_work.h
 *
 *  Created on: Nov 18, 2016
 *      Author: parallels
 */

#ifndef UTILS_BOOST_REGEX_WORK_H_
#define UTILS_BOOST_REGEX_WORK_H_

#include <iostream>
#include <boost/regex/config.hpp>
#include <string>
#include <boost/regex.hpp>
#include <boost/locale.hpp>
#include <boost/regex/icu.hpp>
#include <unistr.h>
#include <unicode/stringpiece.h>

using std::string;
using std::wstring;

class normal_regulation_regex{
public:
	normal_regulation_regex();
	virtual ~normal_regulation_regex();
	bool make_regex(const string& re);
	bool unicode_convert(const string& ws);
	UChar* regex_match();


private:
	char* ws_;
	char* re_
	boost::u32regex wr_;
	UnicodeString ustr_;
	int ws_len;
	int re_len;
};




#endif /* UTILS_BOOST_REGEX_WORK_H_ */
