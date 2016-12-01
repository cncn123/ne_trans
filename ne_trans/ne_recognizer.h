/*
 * ne_recognizer.h
 *
 *  Created on: Nov 18, 2016
 *      Author: parallels
 */

#ifndef NE_TRANS_NE_RECOGNIZER_H_
#define NE_TRANS_NE_RECOGNIZER_H_
#include "ne_recognizer_resource.h"
#include <vector>

class ne_recognizer {
public:
	ne_recognizer(ne_recognizer_resource* _ne_res);
	virtual ~ne_recognizer();
	bool recognize_ne(wstring& _wstr, ne_non_trans** _output_buf, int& _output_buf_len_left);
private:
	ne_recognizer_resource* ne_res_;
};

#endif /* NE_TRANS_NE_RECOGNIZER_H_ */
