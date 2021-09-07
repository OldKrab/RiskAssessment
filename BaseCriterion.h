#pragma once
#include "Matrix.h"

class BaseCriterion
{
public:
	BaseCriterion(Matrix<int> matrix);
	// Returns vector of strategy indexes
	virtual std::vector<size_t> Solve() const = 0;

	virtual ~BaseCriterion() = default;
	static Matrix<int> GetRisksMatrix(Matrix<int> matrix);
protected:
	Matrix<int> matrix_;
	
};


