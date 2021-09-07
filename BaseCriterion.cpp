#include "BaseCriterion.h"
#include <algorithm>


BaseCriterion::BaseCriterion(Matrix<int> matrix) : matrix_(std::move(matrix)) {}

Matrix<int> BaseCriterion::GetRisksMatrix(Matrix<int> matrix)
{
	Matrix<int> risks(matrix.rowsCount, matrix.colsCount);
	std::vector<int> maxInCols(matrix.colsCount);
	for(size_t j = 0; j < matrix.colsCount; j++){
		auto&& rowWithMaxEl = *std::max_element(matrix.begin(), matrix.end(),
			[j](auto&& row1, auto&& row2){return row1[j] < row2[j];});
		maxInCols[j] = rowWithMaxEl[j];
	}
	for(size_t i = 0; i < matrix.rowsCount; i++)
		for(size_t j = 0; j < matrix.colsCount; j++)
		{
			risks[i][j] = maxInCols[j] - matrix[i][j];
		}
	return risks;
}

