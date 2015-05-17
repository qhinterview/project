#include "qh_string.h"

#include <string.h>

namespace qh
{
	// TODO 将在这里写实现代码
	void* my_molloc(int size){
		void* p = malloc(size);
		if(NULL != p){
			return p;
		}
		else{
			printf("out of memory");
			exit(-1);
		}
	}

	string::string()
		: data_(NULL), len_(0)
	{
	}

	string::string( const char* s )
	{
		if(NULL != s){
			int len = strlen(s);
			data_ = (char*)my_molloc(sizeof(char) * len + 1);
			strcpy(data_, s);
			len_ = len;
		}
		else{
			data_ = NULL;
			len_ = 0;
		}
	}

	string::string( const char* s, size_t len )
	{
		if(NULL != s && len > 0){
			int s_len = strlen(s);
			if(s_len <= len){
				data_ = (char*)my_molloc(sizeof(char) * s_len + 1);
				strcpy(data_, s);
				len_ = s_len;
			}
			else{
				data_ = (char*)my_molloc(sizeof(char) * len + 1);
				for(int i = 0; i < len; i++){
					data_[i] = s[i];
				}
				data_[len] = 0;
				len_ = len;
			}
		}
		else{
			data_ = NULL;
			len_ = 0;
		}
	}

	string::string( const string& rhs )
	{
		if(rhs.size() > 0){
			data_ = (char*)my_molloc(sizeof(char) * rhs.size() + 1);
			strcpy(data_, rhs.data_);
			len_ = rhs.size();
		}
		else{
			data_ = NULL;
			len_ = 0;
		}
	}

	string& string::operator=( const string& rhs )
	{
		if (&rhs != this){
			free(this->data_);
			if(rhs.size() > 0){
				data_ = (char*)my_molloc(sizeof(char) * rhs.size() + 1);
				strcpy(data_, rhs.data_);
				len_ = rhs.size();
			}
			else{
				data_ = NULL;
				len_ = 0;
			}

		}
		return *this;
	}

	string::~string()
	{
		free(data_);
	}

	size_t string::size() const
	{
		return len_;
	}

	const char* string::data() const
	{
		return data_;
	}

	const char* string::c_str() const
	{
		return data_;
	}

	char* string::operator[]( size_t index )
	{
		if(len_ > index){
			return data_ + index;
		}

		return NULL;
	}
}
