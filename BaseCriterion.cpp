#include "BaseCriterion.h"

#include <algorithm>


BaseCriterion::BaseCriterion(Matrix<int> matrix): matrix_(std::move(matrix))
{
}

Matrix<int> BaseCriterion::GetRisksMatrix() const
{
	Matrix<int> risks(matrix_.rowsCount, matrix_.colsCount);
	std::vector<int> maxInCols(matrix_.colsCount);
	for(size_t j = 0; j < matrix_.colsCount; j++){
		auto&& rowWithMaxEl = *std::max_element(matrix_.begin(), matrix_.end(),
			[j](auto&& row1, auto&& row2){return row1[j] < row2[j];});
		maxInCols[j] = rowWithMaxEl[j];
	}
	for(size_t i = 0; i < matrix_.rowsCount; i++)
		for(size_t j = 0; j < matrix_.colsCount; j++)
		{
			risks[i][j] = maxInCols[j] - matrix_[i][j];
		}
	return risks;
}
