#include <algorithm> 
#include <iostream> 
#include <vector> 
using namespace std;

// Function to sort arr[] of size n using bucket sort 
void bucketSort(float arr[], int n)
{
	// 1) Create n empty buckets 
	vector<float>* bucket = new vector<float>[n];

	float maxVal = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > maxVal)
		{
			maxVal = arr[i];
		}

	}

	// 2) Put array elements in different buckets 
	for (int i = 0; i < n; i++) {
		int bi = (n * arr[i]) / (maxVal + 1); // Index in bucket 
		//cout << bi << " " << n <<" " << arr[i] << endl;
		bucket[bi].push_back(arr[i]);
	}

	// 3) Sort individual buckets 
	for (int i = 0; i < n; i++) {
		sort(bucket[i].begin(), bucket[i].end());
	}

	// 4) Concatenate all buckets into arr[] 
	int index = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < bucket[i].size(); j++)
			arr[index++] = bucket[i][j];
}

/* Driver program to test above function */
int main()
{
	float arr[] = { 0.873, 0.823, 0.23, 0.12, 0.78, 0.643 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "size of n = " << n << ", size of num/den " << sizeof(arr) << " / " << sizeof(arr[0]) << endl << endl;


	cout << "Before array before sort\n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl << endl;

	bucketSort(arr, n);

	cout << "Sorted array is \n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";

	cout << endl << endl;
	return 0;
	//
}

