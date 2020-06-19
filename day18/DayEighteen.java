public class DayEighteen
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

	private void createLoop()
	{
		Node last = head;
		while(last.next != null)
		{
			last = last.next;
		}
		last.next = head.next.next;
	}

	private void removeLoop()
	{
		Node slow = head;
		Node fast = head;
		while(1 == 1)
		{
			slow = slow.next;
			fast = fast.next.next;
			if(slow == fast)
			{
				break;
			}
		}

		fast = head;

		while(slow.next != fast.next)
		{
			slow = slow.next;
			fast = fast.next;
		}

		slow.next = null;
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
		DayEighteen list = new DayEighteen();
		list.createList();
		list.printList();
		System.out.println("--------------");
		list.createLoop();
		list.removeLoop();
		list.printList();
		System.out.println("--------------");
	}
}