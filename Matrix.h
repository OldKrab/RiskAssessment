#pragma once
#include <vector>

template<class T>
class Matrix
{
public:
	Matrix(size_t rows_count, size_t cols_count)
		:rows_count(rows_count),
		cols_count(cols_count),
		data_(rows_count, std::vector<T>(cols_count))
	{}
	
	Matrix() :Matrix(0, 0) {}

	// Output matrix into stream with specific width
	void Print(std::ostream& in, std::streamsize width = 3)
	{
		for (const auto& row : data_) {
			for (const auto& elem : row)
			{
				in.width(width);
				in << elem;
			}
			in << std::endl;
		}
	}

	//Indexing
	std::vector<T>& operator[](size_t i)
	{
		return data_[i];
	}

	const std::vector<T>& operator[](size_t i) const
	{
		return data_[i];
	}

	// Iterators methods
	typename std::vector<std::vector<T>>::iterator begin() noexcept
	{
		return data_.begin();
	}
	typename std::vector<std::vector<T>>::const_iterator begin() const noexcept
	{
		return data_.begin();
	}
	typename std::vector<std::vector<T>>::iterator end() noexcept
	{
		return data_.end();
	}
	typename std::vector<std::vector<T>>::const_iterator end() const noexcept
	{
		return data_.end();
	}

	
	const size_t rows_count, cols_count;
private:
	std::vector<std::vector<T>> data_;
};

// Input matrix from stream
template <class T>
std::istream& operator>>(std::istream& in, Matrix<T>& matrix)
{
	for (auto&& row : matrix)
		for (auto&& elem : row)
			in >> elem;
	return in;
}


