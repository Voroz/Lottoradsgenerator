#pragma once

void multipleLotto();

struct Result{
	Result() :
	minResult(2147483647),
	maxResult(-2147483647),
	triesUntilMaxResult(0),
	averageResult(0){
		for (int i = 0; i < 8; i++){
			occurences[i] = 0;
		}
	}

	Result(int min, int max, int triesUntilMax, int avg) :
		minResult(min),
		maxResult(max),
		triesUntilMaxResult(triesUntilMax),
		averageResult(avg){
		for (int i = 0; i < 8; i++){
			occurences[i] = 0;
		}
	}

	int occurences[8];
	int minResult;
	int maxResult;
	int triesUntilMaxResult;
	float averageResult;
};

Result lottoExperiment(int rad[7], int numberOfWeeks);

