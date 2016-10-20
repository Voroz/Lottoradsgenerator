// lottorad.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "stdafx.h"

#include "lottorad.h"
#include "ragtest.h"
#include "multipleLotto.h"

int searchArray(int arr[9], int number){
	for (int i = 0; i < 9; i++){
		if (arr[i] == number){
			return i;
		}
	}
	return -1;
}

// Fyller i tal[…] med 7 OLIKA tal mellan 1 och 35
void getLotto(int tal[7]){
	// Nollställ array
	for (int i = 0; i < 7; i++){
		tal[i] = 0;
	}
	for (int i = 0; i < 7; i++){
		int randNum = 1 + rand() % 35;
		while (searchArray(tal, randNum) != -1){
			randNum = 1 + rand() % 35;
		}
		tal[i] = randNum;
	}
}




void main()
{
	setlocale(LC_ALL, "swedish");
	ragnarsTest("Jonny 2472");
	srand(time(NULL));

	int rad[7] = { 0 };
	getLotto((rad));

	cout << "Lottorad: ";
	for (int i = 0; i<7; ++i)
		cout << rad[i] << " ";
	cout << endl;

	multipleLotto();
	system("pause");
}
