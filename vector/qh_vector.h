#ifndef QIHOO_VECTOR_H_
#define QIHOO_VECTOR_H_
#include <stdio.h>
namespace qh
{
    template<class T>
    class vector {
    public:
		typedef T* iterator;
        //ctor
        vector()
            : size_(0), reserve_size_(10)
        {
			data_ = new T[10];
			begin_ = end_ = data_;
        }

        explicit vector( size_t n, const T& value = T())
        {
			if(n > 0){
				data_ = new T[n * 2];
				reserve_size_ = n * 2;
				size_ = n;
				for (size_t i = 0; i < n; i++)
				{
					data_[i] = value;
				}
				begin_ = data_;
				end_ = begin_ + size_;
			}
			else if(n == 0){
				data_ = new T[10];
				size_ = 0;
				reserve_size_ = 10;
				begin_ = end_ = data_;
			}
        }

        vector<T>& operator=(const vector<T>& rhs)
        {
			if(&rhs != this){
				if (data_)
				{
					delete []data_;
				}
				if(rhs.size_ > 0){
					data_ = new T[rhs.size_ * 2];
					for(size_t i = 0; i < rhs.size(); i++){
						data_[i] = rhs.data_[i];
					}
					size_ = rhs.size_;
					reserve_size_ = rhs.size_ * 2;
					begin_ = data_;
					end_ = data_ + size_;
				}
				else{
					data_ = new T[10];
					size_ = 0;
					reserve_size_ = 10;
					begin_ = end_ = data_;
				}
			}
			return *this;
        }

        //dtor
        ~vector()
        {
            if (data_)
            {
                delete []data_;
            }
        }

        //get
        size_t size() const
        {
            return size_;
        }

        // set & get
		T& operator[](size_t index){
			if(size_ > index){
				return data_[index];
			}
			else{
				fprintf(stderr, "out of vector range");
				exit(-1);
			}
		}

        // set
		void push_back(const T& element){
			if(reserve_size_ > size_){
				data_[size_++] = element;
				end_++;
			}
			else{
				T* temp_data = data_;
				data_ = new T[size_ * 2];
				for(size_t i = 0; i < size_; i++){
					data_[i] = temp_data[i];
				}
				reserve_size_ = size_ * 2;
				data_[size_++] = element;
				begin_ = data_;
				end_ = begin_ + size_;
			}
		}

		void pop_back(){
			if(size_ > 0){
				size_--;
				end_--;
			}
		}

		void resize(size_t n, const T& element){
			if(size_ < n){
				if(reserve_size_ < n){
					T* old_data = data_;
					data_ = new T[n * 2];
					reserve_size_ = n * 2;
					for(size_t i = 0; i < size_; i++){
						data_[i] = old_data[i];
					}
					for(size_t i = size_; i < n; i++){
						data_[i] = element;
					}
					size_ = n;
					begin_ = data_;
					end_ = begin_ + size_;
					delete []old_data;
				}
				else{
					for(size_t i = size_; i < n; i++){
						data_[i] = element;
					}
					size_ = n;
					end_ = begin_ + size_;
				}
			}
			else{
				size_ = n;
				end_ = begin_ + size_;
			}
		}

		void reserve(size_t n){
			if(reserve_size_ < n){
				T* old_data = data_;
				data_ = new T[n];
				for(size_t i = 0; i < size_; i++){
					data_[i] = old_data[i];
				}

				delete []old_data;
				begin_ = data_;
				end = begin_ + size_;
				reserve_size_ = n;
			}
		}
		void clear(){
			size_ = 0;
			end_ = begin_;
		}
		bool empty() const{
			return begin_ == end_;
		}

		T* begin(){
			return begin_;
		}

		T* end(){
			return end_;
		}

    private:
        T*      data_;
		T*      begin_;
		T*      end_;
        size_t  size_;
		size_t  reserve_size_;
    };
}

#endif


