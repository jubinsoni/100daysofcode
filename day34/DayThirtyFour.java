import java.util.Queue;
import java.util.LinkedList;

public class DayThirtyFour
{
	public static void main(String args[])
	{
		DayThirtyFour stbas = new DayThirtyFour();
		int arr[] = {1,5,3,8,12};
		stbas.stockBuyAndSell(arr,arr.length);
	}

	int max(int a, int b)
	{
		if(a > b)
		{
			return a;
		}
		return b;
	}

	int min(int a,int b)
	{
		if(a < b)
		{
			return a;
		}
		return b;
	}

	void stockBuyAndSell(int arr[],int n)
	{
		Queue<Integer> qmin = new LinkedList<Integer>();
		Queue<Integer> qmax = new LinkedList<Integer>();
		
		createMinQueue(arr,n,qmin);
		createMaxQueue(arr,n,qmax);

		int buyingTotal = 0;
		System.out.print("buying numbers => ");
		while(qmin.isEmpty() == false)
		{
			int temp = qmin.peek();
			buyingTotal = buyingTotal + temp;
			System.out.print(temp + " ");
			qmin.remove();
		}
		System.out.println();

		int sellingTotal = 0;
		System.out.print("selling numbers => ");
		while(qmax.isEmpty() == false)
		{
			int temp = qmax.peek();
			sellingTotal = sellingTotal + temp;
			System.out.print(temp + " ");
			qmax.remove();
		}
		System.out.println();

		System.out.println("buyingTotal => " + buyingTotal);
		System.out.println("sellingTotal => " + sellingTotal);
		System.out.println("profitEarned => " + (sellingTotal - buyingTotal));
	}

	private void createMinQueue(int arr[],int n,Queue<Integer> qmin)
	{
		if(min(arr[0],arr[1]) == arr[0])
		{
			qmin.add(arr[0]);
		}

		for(int i=1;i<=n-2;i++)
		{
			if(min(arr[i-1],arr[i]) == arr[i] && min(arr[i],arr[i+1]) == arr[i])
			{
				qmin.add(arr[i]);
			}
		}

		if(min(arr[n-2],arr[n-1]) == arr[n-1])
		{
			qmin.add(arr[n-1]);
		}
	}

	private void createMaxQueue(int arr[],int n,Queue<Integer> qmax)
	{
		if(max(arr[0],arr[1]) == arr[0])
		{
			qmax.add(arr[0]);
		}

		for(int i=1;i<=n-2;i++)
		{
			if(max(arr[i-1],arr[i]) == arr[i] && max(arr[i],arr[i+1]) == arr[i])
			{
				qmax.add(arr[i]);
			}
		}

		if(max(arr[n-2],arr[n-1]) == arr[n-1])
		{
			qmax.add(arr[n-1]);
		}
	}

}