#include <algorithm>
#include <cassert>

#include "vector.hpp"

vector_t::vector_t() {
	elements_ = nullptr;
	size_=0;
	capacity_ =0;
}

vector_t::vector_t(vector_t const & other)
{
	size_= other.size_;
	capacity_ = other.capacity_;
	elements_ = new int [capacity_];
	for (unsigned int i=0; i< size_; i++) {
		elements_[i] =other.elements_[i];
	}
}

vector_t & vector_t::operator =(vector_t const & other)
{
	if (this->elements_==other.elements_) return *this;
	else {
		delete [] elements_;
		size_= other.size_;
	capacity_ = other.capacity_;
	elements_ = new int [capacity_];
	for (unsigned int i=0; i< size_; i++) {
		elements_[i] =other.elements_[i];
	}
	}
	return *this;
}

bool vector_t::operator ==(vector_t const & other) const
{
	if (this->size_ == other.size_) {
		for (int i = 0; i < size_; i++) {
			if (this->elements_[i] != other.elements_[i]) {
        		return false;
        		break;
    		}
    	}
    	return true;
	} 
	else
    return false;
}

vector_t::~vector_t()
{
	if (elements_!= nullptr)
	delete [] elements_;
	size_=0;
	capacity_=0;
}

std::size_t vector_t::size() const
{
    return size_;
}

std::size_t vector_t::capacity() const
{
    return capacity_;
}

void vector_t::push_back(int value)
{
	if ((capacity_ == size_ ) && (size_ !=0))
	{ int *elements_copy= new int [capacity_*2];
	capacity_= capacity_*2;
	for (unsigned int i=0; i< size_; i++)
		elements_copy[i] =elements_[i];
	size_++;
	elements_copy[size_-1] = value;
	delete [] elements_;
	elements_ = new int [capacity_];
	for (unsigned int i=0; i< size_; i++)
		elements_[i] =elements_copy[i];
	delete [] elements_copy;
	return;
	};
	if (size_ == 0) {
		size_=1;
		elements_ = new int [1];
		capacity_=1;
		elements_[0]=value;
		return;
	}
	size_++;
	elements_ [size_-1] = value;
}

void vector_t::pop_back()
{
	if (size_==0) return;
	if (size_==1) {size_=0; capacity_=1; return;};
	size_--;
	if (capacity_==(4*size_)) {
		int *elements_copy= new int [capacity_/2];
	capacity_= capacity_/2;
	for (unsigned int i=0; i< size_; i++)
		elements_copy[i] =elements_[i];
		delete [] elements_;
		elements_= new int [capacity_];
		for (unsigned int i=0; i< size_; i++)
		elements_[i] =elements_copy[i];
	delete [] elements_copy;
	return; }
}

int & vector_t::operator [](std::size_t index)
{
	return elements_[index];
}

int vector_t::operator [](std::size_t index) const
{
	return elements_[index];
}

bool operator !=(vector_t const & lhs, vector_t const & rhs)
{
	if (lhs == rhs) return false;
	return true;
}
