AM_CPPFLAGS=-O0 -I/home/parallels/mylibs/boost_1_53/include -I/home/parallels/mylibs/icu_50_1_2/include
AM_CXXFLAGS=-O0 -L/home/parallels/mylibs/boost_1_53/lib -L/home/parallels/mylibs/icu_50_1_2/lib
##bin_PROGRAMS=test_regex
##test_regex_SOURCES=testproject1.cpp
##test_regex_LDADD=-lboost_regex -licuuc -licui18n -licudata -licuio -licule -liculx


noinst_LTLIBRARIES=libwchar_converter.la
libwchar_converter_la_SOURCES=wchar_converter.cpp

bin_PROGRAMS=wchar_converter_test
wchar_converter_test_SOURCES=wchar_converter_test.cpp
wchar_converter_test_LDADD=libwchar_converter.la -lboost_regex -licuuc -licui18n -licudata
