#pragma once
#include "BaseCriterion.h"
class ProbabilisticCriterion:public BaseCriterion
{
public:
	ProbabilisticCriterion(Matrix<int> matrix, std::vector<double> probabilities);
	std::vector<size_t> Solve() const override;

protected:
	std::vector<double> probabilities_;
};
