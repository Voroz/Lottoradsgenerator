#pragma once

void multipleLotto();

struct Result{
	int   minResult;
	int   maxResult;
	float averageResult;
};

Result lottoExperiment(int rad[7], int numberOfWeeks);

