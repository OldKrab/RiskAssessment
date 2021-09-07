#pragma once
#include "HurwitzCriterion.h"
class HurwitzCriterionWithRisks:HurwitzCriterion
{
public:
	HurwitzCriterionWithRisks(Matrix<int> matrix, double coef);
	std::vector<size_t> Solve() const override;
};

