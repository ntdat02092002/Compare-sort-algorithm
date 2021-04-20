#include<iostream>
#include <fstream>
#include<iomanip>
#include <ctime>
using namespace std;

void sort(float[], int);
void readFile(float*&, int&, string);
void writeFile(float[], int, string);
int cmpfunc(const void*, const void*);

void sort(int[], int);
void readFile(int*&, int&, string);
void writeFile(int[], int, string);

int main()
{
	int n;
	//int* p;
	float* p;
	string filename = "C:\\Data\\data structures & algorithms\\Compare_Sort_Algorithm\\Data 4.txt";
	string filename_output = "C:\\Data\\data structures & algorithms\\Compare_Sort_Algorithm\\Output.txt";
	readFile(p, n, filename);
	sort(p, n);
	writeFile(p, n, filename_output);

	return 0;
}

void readFile(float*& a, int& n, string filename)
{
	ifstream fi(filename);

	fi >> n;
	a = new float[n];
	for (int i = 0; i < n; i++)
		fi >> a[i];

	fi.close();
}

void sort(float a[], int n)
{
	clock_t start, end;
	start = clock();

	qsort(a, n, sizeof(float), cmpfunc);

	end = clock();
	cout << "CLOCKS_PER_SEC " << CLOCKS_PER_SEC << "\n";
	cout << "CPU-TIME START " << start << "\n";
	cout << "CPU-TIME END " << end << "\n";
	cout << "CPU-TIME END - START " << end - start << "\n";
	cout << "TIME(SEC) " << static_cast<double>(end - start) / CLOCKS_PER_SEC << "\n";
}

void writeFile(float a[], int n, string filename)
{
	ofstream fo(filename);

	fo << n << endl;
	for (int i = 0; i < n; i++)
		fo << setprecision(3) << fixed << a[i] << setw(10);
	cout << "Done!\n";
	fo.close();
}

//int cmpfunc(const void* a, const void* b)
//{
//	float result = (*(float*)a - *(float*)b);
//	if (result > 0)
//		return 1;
//	else if (result < 0)
//		return -1;
//	else return 0;
//
//}

void readFile(int*& a, int& n, string filename)
{
	ifstream fi(filename);

	fi >> n;
	a = new int[n];
	for (int i = 0; i < n; i++)
		fi >> a[i];

	fi.close();
}

void sort(int a[], int n)
{
	clock_t start, end;
	start = clock();

	qsort(a, n, sizeof(float), cmpfunc);

	end = clock();
	cout << "CLOCKS_PER_SEC " << CLOCKS_PER_SEC << "\n";
	cout << "CPU-TIME START " << start << "\n";
	cout << "CPU-TIME END " << end << "\n";
	cout << "CPU-TIME END - START " << end - start << "\n";
	cout << "TIME(SEC) " << static_cast<double>(end - start) / CLOCKS_PER_SEC << "\n";
}

void writeFile(int a[], int n, string filename)
{
	ofstream fo(filename);

	fo << n << endl;
	for (int i = 0; i < n; i++)
		fo << setprecision(3) << fixed << a[i] << setw(10);
	cout << "Done!\n";
	fo.close();
}

int cmpfunc(const void* a, const void* b)
{
	int result = (*(int*)a - *(int*)b);
	if (result > 0)
		return 1;
	else if (result < 0)
		return -1;
	else return 0;

}

