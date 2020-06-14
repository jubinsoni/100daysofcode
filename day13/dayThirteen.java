public class dayThirteen{

	class Node
	{
		int data;
		Node next;
		public Node(int data)
		{
			this.data = data;
			this.next = null;
		}
	}

	public Node head = null;
	public Node last = null;

	public void addNode(int data)
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

	public void createList()
	{
		for(int i=0;i<5;i++)
		{
			addNode(i*10);
		}
	}

	public void printList()
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