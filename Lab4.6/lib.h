#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstdio>
#include<string>

using namespace std;

void releaseMassive(double* A, string name, int curSize);
void loadMassive(double*& A, FILE* file, int curSize);
int createExtraMassve(double* A1, double v, int firstMSize, double*& A2);
void answer(double* A2, int a2, FILE* file);
void clean(double* &A);