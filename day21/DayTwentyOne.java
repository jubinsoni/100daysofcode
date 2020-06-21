public class DayTwentyOne
{
	class Node
	{
		int data;
		Node left;
		Node right;
		private Node(int data)
		{
			this.data = data;
			this.left = null;
			this.right = null;
		}
	}

	private int itr = 0;
	private int arr[] = {7,5,10,3,6,9,12};

	private Node btree = null;
	
	private Node createBtree()
	{
		for(int itr=0;itr<arr.length;itr++)
		{
			Node newnode = new Node(arr[itr]);
			btree = insertNode(btree,newnode);
		}
		return btree;
	}

	private Node insertNode(Node btree,Node newnode)
	{
		if(btree == null)
		{
			return newnode;
		}
		else if(newnode.data < btree.data)
		{
			btree.left = insertNode(btree.left,newnode);
		}
		else if(newnode.data > btree.data)
		{
			btree.right = insertNode(btree.right,newnode);
		}
		else if(newnode.data == btree.data)
		{
			System.out.print("Data Already Present");
			return btree;
		}
		return btree;
	}

	private void inorder(Node newnode)
	{
		if(newnode != null)
		{
			inorder(newnode.left);
			System.out.print(newnode.data + " ");
			inorder(newnode.right);
		}
	}

	public static void main(String args[])
	{
		DayTwentyOne tree = new DayTwentyOne();
		Node btree = tree.createBtree();
		System.out.print("Inorder Traversal of given Tree => ");
		tree.inorder(btree);
		System.out.println();
	}
}