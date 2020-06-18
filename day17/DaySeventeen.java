public class DaySeventeen
{
	class Node
	{
		int data;
		Node next;
		private Node(int data)
		{
			this.data = data;
			this.next = null;
		}
	}

	private Node head = null;
	private Node last = null;
	private int itr = 0;
	private int arr[] = {10,78,34,12,54,88,55};

	private void createList()
	{
		for(int itr=0;itr<arr.length;itr++)
		{
			Node newnode = new Node(arr[itr]);
			if(head == null)
			{
				head = newnode;
				last = head;
			}
			else
			{
				last.next = newnode;
				last = last.next;
			}
		}
	}

	private void getMiddle()
	{
		Node slow = head;
		Node fast = head;
		while(fast.next != null && fast != null)
		{
			slow = slow.next;
			fast = fast.next.next;
		}
		System.out.println(slow.data);
	}

	private void printList()
	{
		Node temp = head;
		while(temp != null)
		{
			System.out.print(temp.data + " ");
			temp = temp.next;
		}
		System.out.println();
	}

	public static void main(String args[])
	{
		DaySeventeen list = new DaySeventeen();
		list.createList();
		list.printList();
		System.out.println("--------------");
		list.getMiddle();
		System.out.println("--------------");
	}
}