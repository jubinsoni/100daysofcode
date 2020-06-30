import java.util.Queue;
import java.util.LinkedList;

public class DayTwentyEight
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

	private void printKthLevel(Node root,int K)
	{
		if(root == null)
		{
			return;
		}

		if(K == 0)
		{
			System.out.print(root.data + " " );
		}

		K = K - 1;
		printKthLevel(root.left,K);
		printKthLevel(root.right,K);
	}

	public static void main(String args[])
	{
		DayTwentyEight tree = new DayTwentyEight();
		Node btree = tree.createBtree();

		int K = 1;
		System.out.print("Node at K = " + K + " level => ");
		tree.printKthLevel(btree,K);
		System.out.println();
	}
}