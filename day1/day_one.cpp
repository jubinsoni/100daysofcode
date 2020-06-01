# include <iostream>

using namespace std;

int main()
{
	// Array => contiguous memory allocation

	// size of integer variable is 4byte
	int arr1[10]; // 10*4(size of int) = 40 bytes of contiguous memory is allocated

	cout << "size of arr1(expected 40) => "<< sizeof(arr1) << endl;
	cout << "size of int(expected 4) => "<< sizeof(int) << endl;	

	int arr2[] = {7,88,91,23,6,5,23,89}; // Declaration of array

	int size = sizeof(arr2)/sizeof(arr2[0]);

	// traversing array from start to end
	// Note : index starts from 0
	cout << "traversing array from start to end => ";
	for(int i=0;i<size;i++)
	{
		cout << arr2[i] << " ";
	}
	cout << endl;

	cout << "traversing array from end to start => ";
	// traversing array from end to start
	for(int i=size-1;i>=0;i--)
	{
		cout << arr2[i] << " ";
	}
	cout << endl;

	// using break in loops
	// it is used to stop iteration if a particular condition is met
	cout << "using break in loops => ";
	for(int i=0;i<size;i++)
	{
		if(i == 2)
		{
			break;
		}
		cout << arr2[i] << " ";
	}
	cout << endl;

	// using continue in loops
	// it is used to skip an iteration if a particular condition is met
	cout << "using continue in loops => ";
	for(int i =0;i<size;i++)
	{
		if(i == 2)
		{
			continue;
		}
		cout << arr2[i] << " ";
	}
	cout << endl;

	return 0;
}