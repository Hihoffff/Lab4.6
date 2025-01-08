void loadMassive(double* &A, FILE* file, int curSize) {
	A = new double [curSize];
	for (int i1 = 0; i1 < curSize; i1++) {
		fscanf(file, "%lf", &A[i1]);
	}
	
}

void releaseMassive(double* A, string name, int curSize) {
	cout << "Массив " << name << ":" << endl;
	for (int i = 0; i < curSize; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
	
}

int createExtraMassve(double* A1, double v, int firstMSize, double *&A2) {
	int i2 = 0;
	A2 = new double[firstMSize];
	for (int i = 0; i < firstMSize; i++) {
		if (fabs(A1[i]) < v) {
			A2[i2] = A1[i];
			i2++;
		}
	}
	return i2;
}
void answer(double* A2, int a2, FILE* file) {
	for (int i = 0; i < a2; i++) {
		fprintf(file, "|%.2lf|", A2[i]);
	}
	fputs("\n", file);
	
}
void clean(double* &A) {
	delete[] A;
}

