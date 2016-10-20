#include "stdafx.h"
#include "lottorad.h"
#include "multipleLotto.h"
#include <string>
#include <sstream>
#include <vector>	// Använder bara för att göra användar input smidigare.

#include "ragtest.h"

template <size_t N>
int searchArray(int(&arr)[N], int number){
	for (int i = 0; i < N; i++){
		if (arr[i] == number){
			return i;
		}
	}
	return -1;
}

template <size_t N>
int countOccurencesOf(int(&arr)[N], int number){
	int count = 0;
	for (int i = 0; i < N; i++){
		if (arr[i] == number){
			count++;
		}
	}
	return count;
}


Result lottoExperiment(int rad[7], int numberOfWeeks){
	Result res;
	int sum = 0;

	for (int i = 0; i < numberOfWeeks; i++) {
		int datorRad[7] = { 0 };
		getLotto((datorRad));
		int matches = 0;
		for (int j = 0; j < 7; j++){
			matches += countOccurencesOf(datorRad, rad[j]);
		}
		res.occurences[matches]++;
		sum += matches;

		if (matches < res.minResult){
			res.minResult = matches;
		}
		if (matches > res.maxResult){
			res.maxResult = matches;
			res.triesUntilMaxResult = i + 1;
		}
	}
	res.averageResult = (float)sum / numberOfWeeks;

	return res;
}

vector<string> split(const string &str, char delim) {
	stringstream ss;
	ss.str(str);
	string item;
	vector<string> splitVec;
	while (getline(ss, item, delim)) {
		splitVec.push_back(item);
	}
	return splitVec;
}

string stringRepeat(string str, int amount){
	string repeatedStr = "";
	for (int i = 0; i < amount; i++){
		repeatedStr += str;
	}
	return repeatedStr;
}


void multipleLotto(){
    bool ok = ragnarsTest2("Jonny 2472");

	const int numWeeks = 7000000;

	while (1){
		// Input 7 numbers and split into vector of strings.
		vector<string> splitStrings;
		string str = "";
		while (splitStrings.size() != 7){
			cout << "Enter \"lottorad\" (7 numbers separated by spaces): ";
			getline(cin, str);
			splitStrings = split(str, ' ');
		}

		// Convert to "rad" (array of ints)
		int rad[7] = { 0 };
		for (int i = 0; i < 7; i++){
			rad[i] = stoi(splitStrings[i]);
		}

		Result result = lottoExperiment(rad, numWeeks);

		cout << "Result" << endl;
		cout << "min matches: " << result.minResult << endl;
		cout << "max matches: " << result.maxResult << endl;
		cout << "avg matches: " << result.averageResult << endl;
		cout << "tries for max result: " << result.triesUntilMaxResult << endl << endl;
		cout << "Occurences" << "                     " << "Actual" << endl;
		for (int i = 0; i <= 7; i++){
			string str;
			str += to_string(result.occurences[i]);
			str += stringRepeat(" ", 12 - str.length());
			str += to_string((double)result.occurences[i] / numWeeks * 100);
			str += "%";
			str += stringRepeat(" ", 28 - str.length());
			double actual = 0;
			str += to_string(actual);
			str += "%";
			cout << i << "  " << str << endl;
		}
	}


}