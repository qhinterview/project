#include <stdlib.h>
#include <assert.h>
#include "qh_vector.h"


int main(int argc, char* argv[])
{
    //TODO 在这里添加单元测试，越多越好，代码路径覆盖率越全越好
    //TODO 单元测试写法请参考INIParser那个项目，不要写一堆printf，要用assert进行断言判断。

    qh::vector<int> num_vect;
    num_vect.push_back(1);
	num_vect.push_back(2);
	assert(num_vect.size() == 2);
	assert(num_vect[0] == 1);
	assert(num_vect[1] == 2);
	int test = 1;
	for(qh::vector<int>::iterator it = num_vect.begin(); it != num_vect.end(); ++it){
		assert(*it == test);
		test++;
	}
	
	qh::vector<int>::iterator num_it;
	num_vect.push_back(3);
	num_vect.push_back(4);
	assert(num_vect.size() == 4);
	num_it = num_vect.end();
	assert(*(--num_it) == 4);

	num_vect.pop_back();
	assert(num_vect.size() == 3);
	num_it = num_vect.end();
	assert(*(--num_it) == 3);

	assert(num_vect.empty() == false);

	num_vect.clear();
	assert(num_vect.size() == 0);
	for(qh::vector<int>::iterator it = num_vect.begin(); it != num_vect.end(); ++it){
		assert(false);
	}

	assert(num_vect.empty() == true);

	qh::vector<int> num_vect_1(20,3);
	assert(num_vect_1.empty() == false);
	assert(num_vect_1.size() == 20);
	for(qh::vector<int>::iterator it = num_vect_1.begin(); it != num_vect_1.end(); ++it){
		assert(*it == 3);
	}
	
	qh::vector<int> num_vect_2(0,3);
	assert(num_vect_2.size() == 0);
	assert(num_vect_2.empty() == true);

	num_vect_2 = num_vect_1;
	assert(num_vect_2.size() == 20);
	assert(num_vect_2.empty() == false);
	for(qh::vector<int>::iterator it = num_vect_2.begin(); it != num_vect_2.end(); ++it){
		assert(*it == 3);
	}

	num_vect_2 = num_vect_2;
	assert(num_vect_2.size() == 20);
	assert(num_vect_2.empty() == false);
	for(qh::vector<int>::iterator it = num_vect_2.begin(); it != num_vect_2.end(); ++it){
		assert(*it == 3);
	}
	
	num_vect_2.resize(10, 1);
	assert(num_vect_2.size() == 10);

	num_vect_2.resize(30,5);
	assert(num_vect_2.size() == 30);
	assert(num_vect_2[25] == 5);


	
	
#ifdef WIN32
    system("pause");
#endif

	return 0;
}

