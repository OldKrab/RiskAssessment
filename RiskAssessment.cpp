#include <iostream>
#include <fstream>
#include <numeric>

#include "Matrix.h"
#include "HurwitzCriterion.h"
#include "HurwitzCriterionWithRisks.h"
#include "ProbabilisticCriterion.h"

Matrix<int> InputMatrixFrom(std::istream& in)
{
	size_t n, m;
	in >> n >> m;
	Matrix<int> matrix(n, m);
	in >> matrix;
	return matrix;
}

std::string AskForCriterion()
{
	std::vector<std::string> correctAnswers = { "p", "w", "s", "h", "hr" };
	std::string ans;
	while (true) {
		std::cout << "Выберите критерий (вероятностный [p], Вальда [w], Сэвиджа [s], Гурвица [h], Гурвица на основе рисков [hr]): ";
		std::cin >> ans;
		std::transform(ans.begin(), ans.end(), ans.begin(), [](auto c) { return std::tolower(c); });
		if (std::find(correctAnswers.begin(), correctAnswers.end(), ans) != correctAnswers.end())
			break;
		std::cout << "Неверный параметр!\n";
	}
	return ans;
}
std::vector<double> AskForProbabilities(int count)
{
	std::vector<double> probs(count);
	while (true) {
		std::cout << "Введите вероятности (" << count << " шт.): ";
		for(auto&& prob: probs)
			std::cin >> prob;
		double sum = std::accumulate(probs.begin(), probs.end(), 0.);
		if (std::abs(sum - 1.) < 1e-2)
			break;
		std::cout << "Сумма вероятностей отличается от 1!\n";
	}
	return probs;
}

double AskForCoef()
{
	double coef;
	while (true) {
		std::cout << "Введите коэффициент: ";
		std::cin >> coef;
		if (0. <= coef && coef <= 1.)
			break;
		std::cout << "Коэффициент не находится в пределах [0, 1]!\n";
	}
	return coef;
}

std::unique_ptr<BaseCriterion> SelectCriterion(const Matrix<int>& matrix)
{
	auto ans = AskForCriterion();
	if(ans == "p")
	{
		auto probs = AskForProbabilities(matrix.colsCount);
		return std::make_unique<ProbabilisticCriterion>(matrix, probs);
	}
	if(ans == "w")
		return std::make_unique<HurwitzCriterion>(matrix, 1.);
	if(ans=="s")
		return std::make_unique<HurwitzCriterionWithRisks>(matrix, 1);
	if(ans=="h" || ans == "hr")
	{
		auto coef = AskForCoef();
		if(ans == "h")
			return std::make_unique<HurwitzCriterion>(matrix, coef);
		return std::make_unique<HurwitzCriterionWithRisks>(matrix, coef);
	}
	return nullptr;
}


int main()
{
	setlocale(LC_ALL, "rus");
	std::ifstream fin("matrix.txt");
	
	auto matrix = InputMatrixFrom(fin);
	std::cout << "Введенная матрица выигрышей:\n";
	matrix.Print(std::cout, 5);
	std::cout << "Матрица рисков:\n";
	BaseCriterion::GetRisksMatrix(matrix).Print(std::cout, 5);
	
	auto criterion = SelectCriterion(matrix);
	auto strategies = criterion->Solve();
	std::cout << "Выгодные стратегии: ";
	for(auto index: strategies)
		std::cout << index + 1 << ' ';
}
