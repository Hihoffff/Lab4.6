#include "lib.h"
#include "lib.cpp"
int main()
{
	int a=0, b=0, c=0,ca=0,cb=0,cc=0,a2=0,b2=0,c2=0;
	double* A, * B, * C, * A2=NULL, * B2=NULL, * C2=NULL, v = 0.0;
	string answerTXT= "";
	setlocale(LC_ALL, "RUS");
	FILE* fA = fopen("A.txt", "r");
	FILE* fB = fopen("B.txt", "r");
	FILE* fC = fopen("C.txt", "r");
	FILE* out = fopen("answ.txt", "w");
	
	do {
		cout << "Введите размер A:" << endl;
		cin >> a;
	} while (a < 1 || a > 20);
	do {
		cout << "Введите размер B:" << endl;
		cin >> b;
	} while (b < 1 || b > 20);
	do {
		cout << "Введите размер C:" << endl;
		cin >> c;
	} while (c < 1 || c > 20);

	cout << "Введите заданное число: " << endl;
	cin >> v;
	if (fA != 0) {
		loadMassive(A, fA, a);
		releaseMassive(A, "A", a);
		a2 = createExtraMassve(A, v, a, A2);
		
		if (a2 > 0) {
			releaseMassive(A2, "A2", a2);
			if (out != 0) {
				if (a2 == 0) {
					fputs("Массив A не имеет подходящих элелементов!\n", out);
				}
				else {
					fputs("A:\n", out);
					answer(A2, a2, out);
				}
			}
		}
		else {
			cout << "Массив A2 не имеет подходящих элементов!" << endl;
		}
		fclose(fA);
	}
	else {
		cout << "Ошибка открытия файла A.txt!" << endl;
	}
	if (fB != 0) {
		loadMassive(B, fB, b);
		releaseMassive(B, "B", b);
		b2 = createExtraMassve(B, v, b, B2);
		
		if (b2 > 0) {
			releaseMassive(B2, "B2", b2);
			if (out != 0) {
				if (b2 == 0) {
					fputs("Массив B не имеет подходящих элелементов!\n", out);
				}
				else {
					fputs("B:\n", out);
					answer(B2, b2, out);
				}
			}
		}
		else {
			cout << "Массив B2 не имеет подходящих элементов!" << endl;
		}
		fclose(fB);
	}
	else {
		cout << "Ошибка открытия файла B.txt!" << endl;
	}
	if (fC != 0) {
		loadMassive(C, fC, c);
		releaseMassive(C, "C", c);
		c2 = createExtraMassve(C, v, c, C2);
		if (c2 > 0) {
			releaseMassive(C2, "C2", c2);
		}
		else {
			cout << "Массив C2 не имеет подходящих элементов!" << endl;
		}
		if (out != 0) {
			if (c2 == 0) {
				fputs("Массив C не имеет подходящих элелементов!\n", out);
			}
			else {
				fputs("C:\n", out);
				answer(C2, c2, out);
			}
		}
		fclose(fC);
	}
	else {
		cout << "Ошибка открытия файла C.txt!" << endl;
	}
	if (out != 0) {
		fclose(out);
	}
	clean(A);
	clean(B);
	clean(C);

}

