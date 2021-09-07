#include "ProbabilisticCriterion.h"

#include <algorithm>

ProbabilisticCriterion::ProbabilisticCriterion(Matrix<int> matrix, std::vector<double> probabilities)
	: BaseCriterion(matrix),
	probabilities_(probabilities)
{
}

std::vector<size_t> ProbabilisticCriterion::Solve() const
{
	auto risks = GetRisksMatrix();
	std::vector<int> result;
	for(size_t i = 0; i < matrix_.rowsCount; i++)
		for(size_t j =0; j < matrix_.colsCount; j++)
		result[i] += probabilities_[j] * risks[i][j];
	return GetMinElementIndexes(result);
}
