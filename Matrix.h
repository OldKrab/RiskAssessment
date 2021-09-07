#pragma once
#include <vector>
#include <algorithm>

template<class T>
class Matrix
{
public:
	Matrix(size_t rowsCount, size_t colsCount)
		:rowsCount(rowsCount),
		colsCount(colsCount),
		data_(rowsCount, std::vector<T>(colsCount))
	{}
	
	Matrix() :Matrix(0, 0) {}

	// Output matrix into stream with specific width
	void Print(std::ostream& out, std::streamsize width = 3)
	{
		for (const auto& row : data_) {
			for (const auto& elem : row)
			{
				out.width(width);
				out << elem << ' ';
			}
			out << std::endl;
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

	
	const size_t rowsCount, colsCount;
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


// Output vector to stream
template <class T>
void PrintVector(std::ostream& out, const std::vector<T>& vect, std::streamsize width)
{
	for (auto&& elem : vect) {
		out.width(width);
		out << elem << ' ';
	}
}



// Find all indexes of elem
template <class T>
std::vector<size_t> GetElementIndexes(const std::vector<T>& vect, T elem)
{
	std::vector<size_t> indexes;
	while(elem != vect.end())
	{
		indexes.push_back(std::distance(vect.begin(), elem));
		elem = std::find(std::next(elem), vect.end(), *elem);
	}
	return indexes;
}

// Find all max elements, returns indexes
template <class T>
std::vector<size_t> GetMaxElementIndexes(const std::vector<T>& vect)
{
	auto maxResIt = std::max_element(vect.begin(), vect.end());
	return GetElementIndexes(vect, maxResIt);
}

// Find all min elements, returns indexes
template <class T>
std::vector<size_t> GetMinElementIndexes(const std::vector<T>& vect)
{
	auto minResIt = std::min_element(vect.begin(), vect.end());
	return GetElementIndexes(vect, minResIt);
}