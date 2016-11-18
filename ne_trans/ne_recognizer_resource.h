/*
 * ne_recognizer_resource.h
 *
 *  Created on: Nov 18, 2016
 *      Author: parallels
 */

#ifndef NE_TRANS_NE_RECOGNIZER_RESOURCE_H_
#define NE_TRANS_NE_RECOGNIZER_RESOURCE_H_
#include <string>
#include <vector>
#include <boost/regex.hpp>
using std::wstring;
using std::vector;
struct ne_non_trans
{
	uint16_t start;
	uint16_t length;
};

struct ne_date : public ne_non_trans
{
	uint16_t year;
	uint16_t month;
	uint16_t day;
};

class recognizer_traits
{
public:
	recognizer_traits(){};
	virtual ~recognizer_traits(){};
	virtual ne_non_trans* do_recognize(wstring& _wstr, int& start)=0;
};

class recognizer_date : public recognizer_traits
{
public:
	ne_non_trans* do_recognize(wstring& _wstr, int& start);
private:
	vector<boost::wregex>
};

class ne_recognizer_resource {
public:
	ne_recognizer_resource();
	virtual ~ne_recognizer_resource();

};

#endif /* NE_TRANS_NE_RECOGNIZER_RESOURCE_H_ */
