#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class QuadrEquat {
private:

	vector <double> coeffs;
	vector <double> roots;
	double discr; //discriminant value

public:
	QuadrEquat(double a = 1, double b = 1, double c = 1) {
		coeffs.push_back(a);
		coeffs.push_back(b);
		coeffs.push_back(c);
		roots.push_back(0);
		roots.push_back(0);
	}

	void CountDiscriminant(void);
	void PrintSolution(void);
	vector<double> Solve(void);
	void PrintEquation(void);
	void ChangeCoeffs(double a, double b, double c);
};

vector<double> QuadrEquat::Solve(void) {
	if (coeffs[0] == 0) {
		roots[0] = -coeffs[2] / coeffs[1];
		roots[1] = -coeffs[2] / coeffs[1];
		discr = 0;
		return roots;
	}
	CountDiscriminant();
	if (discr < 0) {
		roots[0] = 0;
		roots[1] = 0;
		return roots;
	}
	if (discr == 0) {
		roots[0] = (coeffs[1] / (2 * coeffs[0]));
		roots[1] = (coeffs[1] / (2 * coeffs[0]));
		return roots;
	}
	roots[0] = ((-coeffs[1] + sqrt(discr)) / (2 * coeffs[0]));
	roots[1] = ((-coeffs[1] - sqrt(discr)) / (2 * coeffs[0]));
	return roots;
}

void QuadrEquat::PrintSolution(void) {
	if (discr < 0) {
		cout << "Equation cannot be solved in real numbers, discriminant < 0" << endl;
	}
	if (discr == 0) {
		cout << "Answer is " << roots[0] << endl;
	}
	if (discr > 0) {
		cout << "Answers are " << roots[0] << " and " << roots[1] << endl;
	}
}

void QuadrEquat::CountDiscriminant(void) {
	discr = coeffs[1] * coeffs[1] - 4 * coeffs[0] * coeffs[2];
}

void QuadrEquat::PrintEquation(void) {
	cout << coeffs[0] << "*x^2 + " << coeffs[1] << "*x + " << coeffs[2] << " = 0" << endl;
}

void QuadrEquat::ChangeCoeffs(double a, double b, double c) {
	coeffs[0] = a;
	coeffs[1] = b;
	coeffs[2] = c;
}

int main(void) {
	QuadrEquat res(4, 8, 1);
	
	res.PrintEquation();
	res.Solve();
	res.PrintSolution();

	res.ChangeCoeffs(6, 1, 9);
	res.PrintEquation();
	res.Solve();
	res.PrintSolution();

	res.ChangeCoeffs(0, 1, 3);
	res.PrintEquation();
	res.Solve();
	res.PrintSolution();

	res.ChangeCoeffs(100, 58749, 9275);
	res.PrintEquation();
	res.Solve();
	res.PrintSolution();
	return 0;
}