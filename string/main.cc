#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "qh_string.h"

int main(int argc, char* argv[])
{
	//TODO ��������ӵ�Ԫ���ԣ�Խ��Խ�ã�����·��������ԽȫԽ��
	//TODO ��Ԫ����д����ο�INIParser�Ǹ���Ŀ����Ҫдһ��printf��Ҫ��assert���ж����жϡ�
	qh::string test1;
	assert(NULL == test1.c_str());
	assert(0 == test1.size());

	char *p_test = "hello world"; 

	qh::string test2(p_test);
	assert(0 == strcmp(p_test, test2.c_str()));
	assert(11 == test2.size());

	qh::string test3(p_test, 5);
	assert(0 == strcmp("hello", test3.c_str()));
	assert(5 == test3.size());

	qh::string test4(p_test, 20);
	assert(0 == strcmp(p_test, test4.c_str()));
	assert(11 == test4.size());

	qh::string test5(test4);
	assert(0 == strcmp(p_test, test5.c_str()));
	assert(11 == test5.size());

	test5 = test3;
	assert(0 == strcmp("hello", test3.c_str()));
	assert(5 == test3.size());

	test5 = test5;
	assert(0 == strcmp("hello", test3.c_str()));
	assert(5 == test3.size());

	assert(NULL == test5[20]);
	assert('h' == *test5[0]);

	qh::string test6(NULL);
	assert(NULL == test6.data());
	assert(0 == test6.size());

	qh::string test7(test6);
	assert(NULL == test7.data());
	assert(0 == test7.size());

	test7 = test6;
	assert(NULL == test7.data());
	assert(0 == test7.size());


#ifdef WIN32
	system("pause");
#endif

	return 0;
}

