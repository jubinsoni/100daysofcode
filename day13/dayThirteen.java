public class dayThirteen{

	private class Node
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

	private void addNode(int data)
	{
		Node newnode = new Node(data);
		if(head == null)
		{
			head = newnode;
			last = newnode;
		}
		else
		{
			last.next = newnode;
			last = last.next;
		}
	}

	private void createList()
	{
		for(int i=0;i<5;i++)
		{
			addNode(i*10);
		}
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
		dayThirteen singlyLinkedList = new dayThirteen();
		singlyLinkedList.createList();
		singlyLinkedList.printList();
	}
}