#include <iostream>
#include <vector>
 

using namespace std;

class Company {
	public: 
		double currentRevenue = 0;
		double growthRate = 0;
		double years = 0;
		
		double get_current_revenue() {
			return currentRevenue;
		}
		double get_growth_rate() {
			return growthRate;
		}
		double get_years() {
			return years;
		}
		
		Company(double CurrentRevenue, double GrowthRate, double Years) {
		currentRevenue = CurrentRevenue;
		growthRate = GrowthRate;
		years = Years;
	}
};

Company gather_company_info() {
	cout << "Enter the current revenue for a company: ";
	double currentRevenue;
	cin >> currentRevenue;
	cout << "Enter the average growth rate: ";
	double growthRate;
	cin >> growthRate;
	cout << "Enter the numbers of years that you want to measure: ";
	double years;
	cin >> years;
	
	Company company(currentRevenue, growthRate, years);

	return company;
}

vector <double> calculate_growth_rate() {
	Company company = gather_company_info();
	double currentRevenue = company.get_current_revenue();
	double growthRate = company.get_growth_rate();
	double years = company.get_years();
	double newRevenue = 0;
	vector <double> results;
	
	for (int i = 0; i < years; i++ ) {
		newRevenue = currentRevenue * growthRate;
		results.push_back(newRevenue);
		currentRevenue = newRevenue;
	}

	return results;
}

void print_results() {
	vector <double> results = calculate_growth_rate();
	for (double result : results) {
		cout << result << " ";
	}
	cout << endl << endl;
}

int main() {
	
	bool viewResults = true;
	char viewAnother = 'N';
	
	while (viewResults) {
		print_results();
		
		cout << "Do you want to view another result? Enter Y or N: ";
		cin >> viewAnother;
		viewAnother = tolower(viewAnother);
		
		if (viewAnother != 'y') {
			viewResults = false;
		}
	}
	
	return 0;
}