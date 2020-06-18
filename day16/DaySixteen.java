public class DaySixteen
{

	class Node
	{
		int data;
		Node next;
		Node(int data)
		{
			this.data = data;
			this.next = null;
		}
	}

	private Node head = null;
	private Node last = null;

	int itr = 0;
	int arr[] = {10,78,34,12,54,88,55};
	int size = arr.length;

	private void createList()
	{
		for(int itr=0;itr<size;itr++)
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

	private void reverseList()
	{
		Node curr = head;
		Node last = null;
		Node temp = head;

		while(curr != null)
		{
			temp = curr.next;
			curr.next = last;
			last = curr;
			curr = temp;
		}
		head = last;
	}

	private void printList()
	{
		Node newnode = head;
		while(newnode != null)
		{
			System.out.print(newnode.data + " ");
			newnode = newnode.next;
		}
		System.out.println();
	}

	public static void main(String args[])
	{
		DaySixteen singlyLinkedList = new DaySixteen();
		singlyLinkedList.createList();
		singlyLinkedList.printList();
		System.out.println("------------------");
		singlyLinkedList.reverseList();
		singlyLinkedList.printList();
		System.out.println("------------------");
	}
}