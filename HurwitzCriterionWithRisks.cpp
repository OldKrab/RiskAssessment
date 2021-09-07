#include "HurwitzCriterionWithRisks.h"

HurwitzCriterionWithRisks::HurwitzCriterionWithRisks(Matrix<int> matrix, double coef)
	:HurwitzCriterion(std::move(matrix), coef)
{
}

std::vector<size_t> HurwitzCriterionWithRisks::Solve() const
{
	auto risks = GetRisksMatrix();
	std::vector<double> result(risks.rowsCount);
	for(size_t i = 0; i < risks.rowsCount; i++){
		int min = *std::min_element(risks[i].begin(), risks[i].end());
		int max = *std::max_element(risks[i].begin(), risks[i].end());
		result[i] = coef_ * max + (1. - coef_) * min;
	}
	return GetMinElementIndexes(result);
}
