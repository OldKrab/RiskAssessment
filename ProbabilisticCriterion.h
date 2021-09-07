#pragma once
#include "BaseCriterion.h"
class ProbabilisticCriterion:public BaseCriterion
{
	ProbabilisticCriterion(Matrix<int> matrix, std::vector<double> probabilities);
public:
	std::vector<size_t> Solve() const override;
protected:
	std::vector<double> probabilities_;
};
