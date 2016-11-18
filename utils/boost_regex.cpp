#include <iostream>
#include <boost/regex/config.hpp>
#include <string>
#include <boost/regex.hpp>
#include <boost/locale.hpp>
#include <boost/regex/icu.hpp>
#include <unistr.h>
#include <unicode/stringpiece.h>
using namespace std;
int main(void) {

	//wchar_t *ws=L"aaAaZsvfBsX8erwer";
    std::string ws="ABCA";
    boost::u16match oResults;
    boost::u32regex wr=boost::make_u32regex("(A)");
    icu::StringPiece wq(ws);
    UnicodeString ustr=UnicodeString::fromUTF8(wq);
    // get the address of first elements
    const UChar* pstart = ustr.getBuffer();
    std::cout << std::hex << pstart << std::endl;

    boost::u32regex_token_iterator<const UChar*> i(boost::make_u32regex_token_iterator(ustr,wr,1)),j;



    while(i!=j){
//    	std::cout<< (*i) << std::endl
    	const UChar * px = (*i).first;
    	std::cout << std::hex << px << std::endl;
//    	std::basic_string<UChar> x = (*i).str();
    	std::cout << "length = " << (*i).length() << std::endl;
    	std::cout << "content = ";
    	for (int idx = 0; idx < (*i).length(); ++idx)
    	{
    		std::cout << std::hex << px[idx] << " " ;
    	}
    	std::cout << std::endl;
    	++i;
    }


    return 0;

}
