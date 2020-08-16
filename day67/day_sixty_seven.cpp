# include <iostream>

using namespace std;

class petrolPump
{
public:
	int petrol;
	int distance;
};

int circularTour(petrolPump arr[],int n)
{
	int start_pointer = 0;
	int end_pointer = 1;

	int curr_petrol = arr[start_pointer].petrol - arr[start_pointer].distance;

	while(start_pointer != end_pointer || curr_petrol < 0)
	{
		// this means that we have to revert back the previous decision and start from this current end_pointer position
		// %n is done becoz circular tour...so if pointer reaches end then reset the pointer to start
		while(curr_petrol < 0 && start_pointer != end_pointer)
		{
			curr_petrol = curr_petrol - (arr[start_pointer].petrol - arr[start_pointer].distance);

			// start_pointer only moves when curr_petrol becomes -ve
			start_pointer = (start_pointer + 1)%n;

			// This is done becoz if we reach the 0th petrol pump again
			// then that means we already considered all the possibilty
			if(start_pointer == 0)
			{
				return -1;
			}
		}

		curr_petrol = curr_petrol + arr[end_pointer].petrol - arr[end_pointer].distance;

		// we move end_pointer in each iteration
		end_pointer = (end_pointer + 1)%n;
	}

	// cursor comes here if start_pointer was never equal
	return start_pointer;
}

int main()
{
	petrolPump arr[] = {{6, 4}, {3, 6}, {7, 3}};
	int n = sizeof(arr)/sizeof(arr[0]);

	cout << "starting index of circularTour => " << circularTour(arr,n) << endl;

	return 0;
}