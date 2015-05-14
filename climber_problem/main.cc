#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

#define H_ARRAYSIZE(a) \
	((sizeof(a) / sizeof(*(a))) / \
	static_cast<size_t>(!(sizeof(a) % sizeof(*(a)))))

typedef struct Mountain{
	int start;
	int end;
	int height;
}Mountain, *MountainPoint;

//时间复杂度o(n2)
void sort_mountain(MountainPoint mountain_point, int count){//对山以起始点大小进行排序
	bool is_sorted = false;
	for(int i = 0; i < count; i++){
		if(is_sorted){
			is_sorted = true;
			for(int j = 0; j < count - i - 1; j++){
				if(mountain_point[j].start > mountain_point[j + 1].start){
					Mountain temp = mountain_point[j];
					mountain_point[j] = mountain_point[j + 1];
					mountain_point[j + 1] = temp;
					is_sorted = false;
				}
			}
		}
	}
}

//时间复杂度为o(n)
int calculate_length(MountainPoint mountain_point, int count) {
	int sum = 0;
	bool is_connect = false;//是否与上一个山连接
	for (int i = 0; i< count - 1; i++){
		if (is_connect){
			if (mountain_point[i].end >= mountain_point[i+1].start){//与下一座山连接
				is_connect = true;
				sum += abs(mountain_point[i].height - mountain_point[i+1].height);
			}
			else{
				sum += mountain_point[i].height;
				is_connect = false;
			}
		}
		else{
			if (mountain_point[i].end >= mountain_point[i+1].start){//与下一座山连接
				is_connect = true;
				sum += mountain_point[i].height + abs(mountain_point[i].height - mountain_point[i+1].height);
			}
			else{
				is_connect = false;
				sum += mountain_point[i].height * 2;
			}
		}
	}

	if (is_connect) {//处理最后一座山
		sum += mountain_point[count-1].height;
	}
	else{
		sum += mountain_point[count-1].height * 2;
	}

	sum += mountain_point[count-1].end; //加上横向长度

	return sum;
}


int resolve(const char* input)
{
	string buf(input);
	istringstream string_stream(buf);
	int mountain_count = 0;
	string_stream >> mountain_count;

	MountainPoint mountain_point = (MountainPoint)malloc(sizeof(Mountain) * mountain_count);
	for(int i = 0 ;i < mountain_count; i++){//initial the data of mountains;
		char temp;
		string_stream >> mountain_point[i].start;
		string_stream >> temp;
		string_stream >> mountain_point[i].end;
		string_stream >> temp;
		string_stream >> mountain_point[i].height;
	}

	sort_mountain(mountain_point, mountain_count);
	int length = calculate_length(mountain_point, mountain_count);

	free(mountain_point);
	return length;
}

int main(int argc, char* argv[]) 
{
	const char* input[] = {
		"3\n1,3,2\n2,4,4\n6,7,5\n", //The giving example
		"1\n1,2,1\n",
		"2\n1,2,1\n2,3,2",
		"3\n1,2,1\n2,3,2\n3,6,1",
		"4\n1,2,1\n2,3,2\n3,6,1\n5,8,2",
		"5\n1,2,1\n2,3,2\n3,6,1\n5,8,2\n7,9,1",
		"1\n0,1,1",
		"2\n0,1,1\n2,4,3",
		"3\n0,1,1\n2,4,3\n3,5,1",
		"4\n0,1,1\n2,4,3\n3,5,1\n5,6,1",
		"5\n0,1,1\n2,4,3\n3,5,1\n5,6,1\n6,8,3",
		//TODO please add more test case here
	};
	int expectedSteps[] = {25, 4, 7, 10, 14, 15, 3, 12, 13, 14, 20};
	for (size_t i = 0; i < H_ARRAYSIZE(input); ++i)
	{
		assert(resolve(input[i]) == expectedSteps[i]);
	}
	return 0;
}
