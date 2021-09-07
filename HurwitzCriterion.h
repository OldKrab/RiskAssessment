#pragma once
#include "BaseCriterion.h"

class HurwitzCriterion:public BaseCriterion
{
public:
	HurwitzCriterion(Matrix<int> matrix, double coef);
	std::vector<size_t> Solve() const override;

protected:
	double coef_;
};
