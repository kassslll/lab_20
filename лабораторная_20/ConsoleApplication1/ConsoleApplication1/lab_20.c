#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <Windows.h>


#define MAX_COL 10
#define MAX_ROW 10


int arr[MAX_COL][MAX_ROW];

int n = 0;
int m = 0;

void start_programm();
void print();
void fillIJ();
void fillZero();
void randFill();
void noteven();
void divizionTen();
void inputKeyboard();
void savefile();
void downloadFile();
void deleteRow();
void duplicateColumn();
void task_9();
void zeroColumn(int x);
void duplicateRow(int x);
void duplicateEven();


void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	start_programm();
}


void start_programm() {

	int input;

	print();
	printf("=====================================\n");
	printf("Выберите нужную вам оперцию:\n");
	printf("1: Заполните значениями i * 10 + j\n");
	printf("2: Заполнить нулями\n");
	printf("3: Заполнить случайными числами\n");
	printf("4: Все нечётные числа увеличить в 10 раз\n");
	printf("5: Все кратные 10 уменьшить в 10 раз\n");
	printf("6: Ввести массив с клавиатуры\n");
	printf("7: Сохранить массив в файл\n");
	printf("8: Загрузить массив из файла\n");
	printf("9: Удалить строку из массива\n");
	printf("10: Дублировать столбец из массива\n");
	printf("11: Вариант A10\n");
	printf("12: Вариант B10\n\n");
	printf("-1: EXIT\n\n");
	printf("Выбранная операция >>>>>>>>> ");

	scanf_s("%d", &input);

	printf("\n");

	switch (input)
	{
	case 1:
		fillIJ();
		return start_programm();
		break;
	case 2:
		fillZero();
		return start_programm();
		break;
	case 3:
		randFill();
		return start_programm();
		break;
	case 4:
		noteven();
		return start_programm();
		break;
	case 5:
		divizionTen();
		return start_programm();
		break;
	case 6:
		inputKeyboard();
		return start_programm();
		break;
	case 7:
		savefile();
		return start_programm();
		break;
	case 8:
		downloadFile();
		return start_programm();
		break;
	case 9:
		deleteRow();
		return start_programm();
		break;
	case 10:
		duplicateColumn();
		return start_programm();
		break;
	case 11:
		task_9();
		return start_programm();
		break;
	case 12:
		duplicateEven();
		return start_programm();
		break;
	case -1:
		printf("\nКонец!\n");
		break;
	default:
		return start_programm();
		break;
	}
}

void print() {
	printf("!!! printf() !!!\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%4d", arr[i][j]);
		}
		printf("\n");
	}
}

void fillIJ() {
	printf("!!! fillIJ() !!!\n");

	printf("Введите i: ");
	scanf_s("%d", &n);
	printf("\n");
	printf("Введите j: ");
	scanf_s("%d", &m);
	printf("\n");

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = i * 10 + j;
		}
	}
}

void fillZero() {

	printf("!!! fillZero() !!!\n");

	printf("Введите i: ");
	scanf_s("%d", &n);
	printf("\n");
	printf("Введите j: ");
	scanf_s("%d", &m);
	printf("\n");

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = 0;
		}
	}
}

void randFill() {

	printf("!!! randFill() !!!\n");

	n = rand() % 10;
	m = rand() % 10;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = rand() % 10;
		}
	}
}

void noteven() {

	printf("!!! noteven() !!!\n");

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] % 2 == 1) {
				arr[i][j] *= 10;
			}
		}
	}
}

void divizionTen() {

	printf("!!! divizionTen() !!!\n");

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] % 10 == 0) {
				arr[i][j] /= 10;
			}
		}
	}
}

void inputKeyboard() {
	printf("!!! inputKeyboard() !!!\n");

	printf("Введите i: ");
	scanf_s("%d", &n);
	printf("\n");
	printf("Введите j: ");
	scanf_s("%d", &m);
	printf("\n");

	printf("Input Massive:\n");

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf_s("%d ", &arr[i][j]);
		}
	}   
}

void savefile() {

	printf("!!! savefile() !!!\n");

	FILE* file = fopen("D:\\Учёба\\1 курс\\Основы алгоримизации и программирование (Власенко)\\лабораторная_20\\directory_files\\result.txt", "wt");

	printf("Start save\n");

	fprintf(file, "%d\n", n);
	fprintf(file, "%d\n", m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			fprintf(file, "%d ", arr[i][j]);
		}
		fprintf(file, "\n");
	}
	fclose(file);
	printf("End save\n");
}

void downloadFile() {

	printf("!!! downloadFile() !!!\n");

	FILE* file = fopen("D:\\Учёба\\1 курс\\Основы алгоримизации и программирование (Власенко)\\лабораторная_20\\directory_files\\input.txt", "rt");

	printf("Start download\n");

	fscanf(file, "%d", &n);
	fscanf(file, "%d", &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			fscanf(file, "%d", &arr[i][j]);
		}
	}

	fclose(file);
	printf("End download\n");
}

void deleteRow() {
	printf("!!! deleteRow() !!!\n");

	int s;

	printf("Введите номер строки которую хотите удалить: ");
	scanf_s("%d", &s);
	printf("\n");
	

	for (int i = s - 1; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = arr[i + 1][j];
		}
	}
	n -= 1;
}

void duplicateColumn() {
	printf("!!! duplicateColumn() !!!\n");

	int s;

	printf("Введите номер столбца которую хотите дублировать: ");
	scanf_s("%d", &s);
	printf("\n");

	for (int i = 0; i < n; i++) {
		for (int j = m; j > s-1; j--) {
			arr[i][j] = arr[i][j - 1];
		}
	}

	m += 1;
}

void task_9() {
	printf("!!! task_9() !!!\n");

	int s = 0;

	printf("Поиск начался!");
	printf("\n");

	for (int j = 0; j < n; j++) {
		s = 0;
		for (int i = 0; i < m; i++) {
			if (arr[i][j] % 2 == 0) {
				s++;
			}
			
		}
		if (s == 0) {
			zeroColumn(j);
		}
	}

	printf("Поиск закончился!");
	printf("\n");
}

void zeroColumn(int x) {
	for (int i = 0; i < n; i++) {
		arr[i][x] = 0;
	}
}

void duplicateEven() {
	printf("!!! duplicateEven() !!!\n");

	int s = 0;

	printf("Поиск начался!");
	printf("\n");

	for (int i = 0; i < n; i++) {
		s = 0;
		for (int j = 0; j < m; j++) {
			if (arr[i][j] % 2 == 0) {
				s++;
				break;
			}

		}
		if (s > 0) {
			duplicateRow(i);
			i++;
			s = 0;
		}
	}

	printf("Поиск закончился!");
	printf("\n");
}

void duplicateRow(int x) {

	for (int j = 0; j < n; j++) {
		for (int i = m; i > x - 1; i--) {
			arr[i][j] = arr[i][j - 1];
		}
	}

	n += 1;
}