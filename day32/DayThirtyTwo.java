import java.util.Queue;
import java.util.LinkedList;

public class DayThirtyTwo
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

	private int max(int a,int b)
	{
		if(a > b)
		{
			return a;
		}
		return b;
	}

	private int heightOfTree(Node root)
	{
		if(root == null)
		{
			return 0;
		}

		int lh = heightOfTree(root.left);
		int rh = heightOfTree(root.right);

		return 1 + max(lh,rh);
	}

	private int abs(int a)
	{
		if(a < 0)
		{
			return -a;
		}

		return a;
	}

	private boolean isBalanced(Node root)
	{
		if(root == null)
		{
			return true;
		}

		int lh = heightOfTree(root.left);
		int rh = heightOfTree(root.right);

		if(abs(lh-rh) <= 1 && isBalanced(root.left) == true && isBalanced(root.right) == true)
		{
			return true;
		}

		return false;
	}

	public static void main(String args[])
	{
		DayThirtyTwo tree = new DayThirtyTwo();
		Node btree = tree.createBtree();

		System.out.println("height of tree => " + tree.heightOfTree(btree));
		System.out.println("isBalanced tree => " + tree.isBalanced(btree));
	}
}