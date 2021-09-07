#pragma once
#include <iostream>
#include <utility>
#include "Matrix.h"

class BaseCriterion
{
public:
	BaseCriterion(Matrix<int> matrix);
	// Returns vector of strategy indexes
	virtual std::vector<size_t> Solve() const = 0;

	virtual ~BaseCriterion() = default;
protected:
	Matrix<int> GetRisksMatrix() const;

	Matrix<int> matrix_;
	
};


