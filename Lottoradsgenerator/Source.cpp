#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


using namespace std;

template <size_t N>
int searchArray(int(&arr)[N], int number){
	for (int i = 0; i < N; i++){
		if (arr[i] == number){
			return i;
		}
	}
	return -1;
}

// Fyller i tal[…] med 7 OLIKA tal mellan 1 och 35
void getLotto(int(&tal)[7]){
	for (auto &t : tal){
		int randNum = 1 + rand() % 35;
		while (searchArray(tal, randNum) != -1){
			randNum = 1 + rand() % 35;
		}
		t = randNum;
	}
}


// Skriver ut en lottorad
void main(){
	srand(time(NULL));
	//ragnarsTest(”Jonny 2472”);
	int row[7];
	getLotto((row));
	cout << "Lottorad: ";
	for (auto r : row){
		cout << r << " ";
	}
	cout << endl;
	while (1){
		
	}
}