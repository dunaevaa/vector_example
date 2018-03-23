#include <algorithm>
#include <cassert>

#include "vector.hpp"

vector_t::vector_t() {
	elements_ = nullptr;
	size_ = 0;
	capacity_ = 0;
}

vector_t::vector_t(vector_t const & other) {
	size_ = other.size_;
	capacity_ = other.capacity_;
	elements_ =  new int [capacity_];
	for (unsigned int i=0; i<size_; i++)
		elements_[i] = other.elements_[i];
}

vector_t & vector_t::operator =(vector_t const & other) {
	if (this != &other) {
		if (elements_ != nullptr)
			delete [] elements_
		elements_ = new int [other.capacity_];
		for (unsigned int i=0; i<other.size_; i++)
			elements_[i] = other.elements_[i];
		capacity_ = other.capacity_;
		size_ = other.size_;
	}
	return *this;
}

bool vector_t::operator ==(vector_t const & other) const {
	return false;
}

vector_t::~vector_t() {
	if (elements_ != nullptr)
	delete [] elements_;
}

std::size_t vector_t::size() const
{
    return size_;
}

std::size_t vector_t::capacity() const
{
    return capacity_;
}

void vector_t::push_back(int value) {
	if (elements_ == nullptr) {
		int capacity_ = 1;
		elements_ = new int [capacity_];
		elements_[0] = value;
	}
	else {
		int elements_1 = new int [capacity_];
		for (unsigned int i=0; i<size; i++)
			elements_1[i] = elements_[i];
		elements_[size_] = value;
		delete [] elements_;
		elements_ = elements_1;
		size_ ++;
		if (capacity_ == size_)
			capacity_ *= 2;
	}
}

void vector_t::pop_back() {
	if (elements_ != nullptr) {
		if (capacity_/4 >= size_) {
			capacity_/=2;
			int elements_1 = new elements [capacity_];
			for (unsigned int i=0; i< size_-1; i++)
				elements_1[i] = elements_[i];
			delete [] elements_;
			elements_ = elements_1;
			size_ --;
		} else {
			int elements_1 = new elements [capacity_];
			for (unsigned int i=0; i<size_-1; i++)
				elements_1[i] = elements_[i];
			delete[] elements_;
			elements_ = elements_1;
			size_ --;
		}
	}
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
	return !(lhs == rhs);
}
