public class DayTwentyFour
{
	private static int arr1[] = {7,5,14,12,11,9,4,3,1,54};
	private static int arr2[] = {7,5,14,12,11,9,4,3,1,54};

	public static void main(String args[])
	{
		DayTwentyFour sortFunc = new DayTwentyFour();
		sortFunc.bubbleSort(arr1);
		sortFunc.printArray(arr1);
		sortFunc.selectionSort(arr2);
		sortFunc.printArray(arr2);
	}
	
	// swap adjacent element for n2 if(arr[j > arr[j+1]])
	private void bubbleSort(int arr[])
	{
		for(int i=0;i<=arr.length-2;i++)
		{
			for(int j=0;j<=arr.length-2;j++)
			{
				if(arr[j] > arr[j+1])
				{
					int res[] = swap(arr[j],arr[j+1]);
					arr[j] = res[0];
					arr[j+1] = res[1];
				}
			}
		}
	}

	// find minimum in n and repalce for i in n
	private void selectionSort(int arr[])
	{
		for(int i=0;i<=arr.length-1;i++)
		{
			int minIndz = i;
			for(int j=i+1;j<=arr.length-1;j++)
			{
				if(arr[minIndz] > arr[j])
				{
					minIndz = j;
				}
			}
			int res[] = swap(arr[minIndz],arr[i]);
			arr[minIndz] = res[0];
			arr[i] = res[1];
		}
	}

	private int[] swap(int a,int b)
	{
		int res[] = new int[2];
		int temp = a;
		a = b;
		b = temp;
		res[0] = a;
		res[1] = b;
		return res;
	}

	private void printArray(int arr[])
	{
		for(int i=0;i<arr.length;i++)
		{
			System.out.print(arr[i] + " ");
		}
		System.out.println();
	}
}