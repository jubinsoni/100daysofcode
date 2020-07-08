import java.util.Stack;

public class DayThirtySeven
{
	public static void main(String args[])
	{
		DayThirtySeven leader = new DayThirtySeven();
		int arr[] = {5,3,20,15,8,3};
		leader.leadersInArray(arr);
	}

	private void leadersInArray(int arr[])
	{
		Stack<Integer> st = new Stack<Integer>();
		int maxz = -1000000;
		for(int i=arr.length-1;i>=0;i--)
		{
			if(maxz < arr[i])
			{
				maxz = arr[i];
				st.add(maxz);
			}
		}

		printStack(st);
	}

	private void printStack(Stack<Integer> st)
	{
		while(st.isEmpty() == false)
		{
			int temp = st.peek();
			System.out.print(temp + " ");
			st.pop();
		}
		System.out.println();	
	}
}