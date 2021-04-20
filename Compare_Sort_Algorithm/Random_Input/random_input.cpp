#include<iostream>
#include <fstream>
#include<iomanip>
#include <ctime>
#include <string>
#include <algorithm>
using namespace std;

void writeFile(float[], const int, string);
void writeFile(int[], const int, string);
void createArray(float[], const int);
void createArray(int[], const int);
void createArray_equal(float[], const int);
void createArray_equal(int[], const int);

bool myfunction(float i, float j) { return (i < j); }

int main()
{
	int n = 1000000;
	string filename;

	int* p = new int[n];
	
	// create data 1 (random int, sorted - ascending order, range: -1000:1000)
	/*filename = "C:\\Data\\data structures & algorithms\\Compare_Sort_Algorithm\\Data 1.txt";
	createArray(p, n);
	sort(p, p + n);
	writeFile(p, n, filename);*/

	// create data 2 (randodm int, sorted - descending order, range: -1000:1000)
	/*filename = "C:\\Data\\data structures & algorithms\\Compare_Sort_Algorithm\\Data 2.txt";
	createArray(p, n);
	sort(p, p + n, greater<int>());
	writeFile(p, n, filename);*/

	// create data 3 (random int, all element equal,range: -1000:1000)
	/*filename = "C:\\Data\\data structures & algorithms\\Compare_Sort_Algorithm\\Data 3.txt";
	createArray_equal(p, n);
	writeFile(p, n, filename);*/

	// create data 4 (random int, range: -1000:1000)
	/*filename = "C:\\Data\\data structures & algorithms\\Compare_Sort_Algorithm\\Data 4.txt";
	createArray(p, n);
	writeFile(p, n, filename);*/

	// create data 5 (random int, range 0:10000)
	/*filename = "C:\\Data\\data structures & algorithms\\Compare_Sort_Algorithm\\Data 5.txt";
	createArray(p, n);
	writeFile(p, n, filename);*/

	delete[]p;

	float* q = new float[n];

	// create data 6 (random, float sorted - ascending order, range -1000:1000)
	/*filename = "C:\\Data\\data structures & algorithms\\Compare_Sort_Algorithm\\Data 6.txt";
	createArray(q, n);
	sort(q, q + n, myfunction);
	writeFile(q, n, filename);*/
	
	// create data 7 (randodm float, sorted - descending order, range: -1000:1000)
	/*filename = "C:\\Data\\data structures & algorithms\\Compare_Sort_Algorithm\\Data 7.txt";
	createArray(q, n);
	sort(q, q + n, greater<float>());
	writeFile(q, n, filename);*/

	// create data 8 (random float, all element equal, range: -1000:1000)
	/*filename = "C:\\Data\\data structures & algorithms\\Compare_Sort_Algorithm\\Data 8.txt";
	createArray_equal(q, n);
	writeFile(q, n, filename);*/

	// create data 9 (random float, range: -1000:1000)
	/*filename = "C:\\Data\\data structures & algorithms\\Compare_Sort_Algorithm\\Data 9.txt";
	createArray(q, n);
	writeFile(q, n, filename);*/

	// create data 10 (random float, range: 0:10000)
	filename = "C:\\Data\\data structures & algorithms\\Compare_Sort_Algorithm\\Data 10.txt";
	createArray(q, n);
	writeFile(q, n, filename);

	delete[]q;
	return 0;
}

void createArray(float a[], const int n)
{
	srand(std::time(nullptr));

	for (int i = 0; i < n; i++)
	{
		//random float between -1000 - 1000
		//float num = -1000 + rand() / (RAND_MAX / (2000.0 - (0)));

		//random float between 0 - 10000
		float num = 0 + rand() / (RAND_MAX / (10000.0 - (0)));

		a[i] = num;
	}
}

void createArray(int a[], const int n)
{
	srand(std::time(nullptr));

	for (int i = 0; i < n; i++)
	{
		//random int between -1000 - 1000
		int num = rand() % (2000 + 1) - 1000;
		
		//random int between 0 - 10000
		//int num = rand() % (10000 + 1) - 0;

		a[i] = num;
	}
}

void createArray_equal(float a[], const int n)
{
	srand(std::time(nullptr));
	//random float between -1000 - 1000
	float num = -1000 + rand() / (RAND_MAX / (2000.0 - (0)));
	for (int i = 0; i < n; i++)
	{
		a[i] = num;
	}
}

void createArray_equal(int a[], const int n)
{
	srand(std::time(nullptr));
	//random int between -1000 - 1000
	int num = rand() % (2000 + 1) - 1000;
	for (int i = 0; i < n; i++)
	{
		a[i] = num;
	}
}

void writeFile(float a[], const int n, string filename)
{
	ofstream fo(filename);

	fo << n << endl;
	for (int i = 0; i < n; i++)
		fo << setprecision(3) << fixed << a[i] << setw(10);
	cout << "Done!\n";
	fo.close();
}

void writeFile(int a[], const int n, string filename)
{
	ofstream fo(filename);

	fo << n << endl;
	for (int i = 0; i < n; i++)
		fo << setprecision(3) << fixed << a[i] << setw(10);
	cout << "Done!\n";
	fo.close();
}
