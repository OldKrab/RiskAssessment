#include "ProbabilisticCriterion.h"

ProbabilisticCriterion::ProbabilisticCriterion(Matrix<int> matrix, std::vector<double> probabilities)
	: BaseCriterion(matrix),
	probabilities_(probabilities)
{
}

std::vector<size_t> ProbabilisticCriterion::Solve() const
{
	auto risks = GetRisksMatrix(matrix_);
	std::vector<double> result(matrix_.rowsCount);
	for(size_t i = 0; i < matrix_.rowsCount; i++)
		for(size_t j =0; j < matrix_.colsCount; j++)
		result[i] += probabilities_[j] * risks[i][j];
	return GetMinElementIndexes(result);
}
