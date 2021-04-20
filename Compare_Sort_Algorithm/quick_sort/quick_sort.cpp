#include<iostream>
#include <fstream>
#include<iomanip>
#include <ctime>
using namespace std;

void sort(float[], int);
void readFile(float*&, int&, string);
void writeFile(float[], int, string);
void swap(float*, float*);
int partition(float[], int, int);
void quickSort(float[], int, int);

void sort(int[], int);
void readFile(int*&, int&, string);
void writeFile(int[], int, string);
void swap(int*, int*);
int partition(int[], int, int);
void quickSort(int[], int, int);

int main()
{
	int n;
	int* p;
	//float* p;
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

void readFile(int*& a, int& n, string filename)
{
	ifstream fi(filename);

	fi >> n;
	a = new int[n];
	for (int i = 0; i < n; i++)
		fi >> a[i];

	fi.close();
}

void sort(float a[], int n)
{
	clock_t start, end;
	start = clock();

	quickSort(a, 0, n - 1);

	end = clock();
	cout << "CLOCKS_PER_SEC " << CLOCKS_PER_SEC << "\n";
	cout << "CPU-TIME START " << start << "\n";
	cout << "CPU-TIME END " << end << "\n";
	cout << "CPU-TIME END - START " << end - start << "\n";
	cout << "TIME(SEC) " << static_cast<double>(end - start) / CLOCKS_PER_SEC << "\n";
}

void sort(int a[], int n)
{
	clock_t start, end;
	start = clock();

	quickSort(a, 0, n - 1);

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

void writeFile(int a[], int n, string filename)
{
	ofstream fo(filename);

	fo << n << endl;
	for (int i = 0; i < n; i++)
		fo << setprecision(3) << fixed << a[i] << setw(10);
	cout << "Done!\n";
	fo.close();
}

void swap(float* a, float* b)
{
	float t = *a;
	*a = *b;
	*b = t;
}

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(float arr[], int low, int high)
{
	float pivot = arr[high]; // pivot
	int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than the pivot
		if (arr[j] < pivot)
		{
			i++; // increment index of smaller element
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

int partition(int arr[], int low, int high)
{
	int pivot = arr[high]; // pivot
	int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than the pivot
		if (arr[j] < pivot)
		{
			i++; // increment index of smaller element
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(float arr[], int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}