#include<iostream>
#include <fstream>
#include<iomanip>
#include <ctime>
using namespace std;

void sort(float[], int);
void readFile(float*&, int&, string);
void writeFile(float[], int, string);
void heapify(float[], int, int);
void heapSort(float[], int);

void sort(int[], int);
void readFile(int*&, int&, string);
void writeFile(int[], int, string);
void heapify(int[], int, int);
void heapSort(int[], int);

int main()
{
	int n;
    //int* p;
	float* p;
	string filename = "C:\\Data\\data structures & algorithms\\Compare_Sort_Algorithm\\Data 10.txt";
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

    heapSort(a, n);

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

void heapify(float arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// main function to do heap sort
void heapSort(float arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
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

void sort(int a[], int n)
{
    clock_t start, end;
    start = clock();

    heapSort(a, n);

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

void heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// main function to do heap sort
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}