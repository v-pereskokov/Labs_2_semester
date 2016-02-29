#include <iostream>
#include <cstring>

#define STUDENT_VARIANT 15

class IUVector
{
public:
	IUVector()
		: size_(0) {}

	explicit IUVector(size_t size)
	{
		size_ = size;
		vector_ = new double[size_];
		memset(vector_, 0, size_ * vector_[0]);
	}

	IUVector(const IUVector &copy)
		:size_(copy.size_)
	{
		vector_ = new double[size_];
		for (size_t i = 0; i < size_; i++)
			vector_[i] = copy.vector_[i];
	}

	IUVector(const double* massive, size_t size)
		:size_(size)
	{
		vector_ = new double[size_];
		for (size_t i = 0; i < size_; i++)
			vector_[i] = massive[i];
	}

	IUVector reSize(size_t size)
	{
		delete[] vector_;
		size_ = size;
		vector_ = new double[size_];
		memset(vector_, 0, size_ * vector_[0]);
		return *this;
	}

	size_t size() const
	{
		return size_;
	}

	operator double *()
	{
		return this->vector_;
	}

	IUVector &operator = (const IUVector &vector)
	{
		if (&vector == this)
			return *this;
		delete[] vector_;
		size_ = vector.size_;
		vector_ = new double[size_];
		for (size_t i = 0; i < size_; i++)
			vector_[i] = vector.vector_[i];
		return *this;
	}

	double * operator * (double number)
	{
		for (size_t i = 0; i < size_; i++)
			vector_[i] = vector_[i] * number;
		return vector_;
	}

	double * operator *= (double number)
	{
		for (size_t i = 0; i < size_; i++)
			vector_[i] = vector_[i] * number;
		return vector_;
	}

	double * operator / (double number)
	{
		for (size_t i = 0; i < size_; i++)
			vector_[i] = vector_[i] / number;
		return vector_;
	}

	double * operator /= (double number)
	{
		for (size_t i = 0; i < size_; i++)
			vector_[i] = vector_[i] / number;
		return vector_;
	}

	~IUVector()
	{
		delete[] vector_;
	}

	double &operator [] (size_t);

	friend std::ostream &operator << (std::ostream &, IUVector &);

private:
	double *vector_;
	size_t size_;
};

double &IUVector::operator [] (size_t index)
{
	return vector_[index];
}

std::ostream &operator << (std::ostream &out, IUVector &vector)
{
	out << "Vector: (";
	for (size_t i = 0; i < vector.size_; i++)
	{
		out << vector.vector_[i];
		if (i == vector.size_ - 1)
			out << ")" << std::endl;
		else
			out << ", ";
	}
	return out;
}
