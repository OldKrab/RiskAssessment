#include "HurwitzCriterion.h"

#include <utility>
#include <algorithm>

HurwitzCriterion::HurwitzCriterion(Matrix<int> matrix, double coef)
	:BaseCriterion(std::move(matrix)), coef_(coef)
{
}

std::vector<size_t> HurwitzCriterion::Solve() const
{
	std::vector<double> result(matrix_.rowsCount);
	for(size_t i = 0; i < matrix_.rowsCount; i++){
		int min = *std::min_element(matrix_[i].begin(), matrix_[i].end());
		int max = *std::max_element(matrix_[i].begin(), matrix_[i].end());
		result[i] = coef_ * min + (1. - coef_) * max;
	}
	return GetMaxElementIndexes(result);
}
