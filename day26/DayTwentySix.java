import java.util.Queue;
import java.util.LinkedList;

public class DayTwentySix
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

	private int heightOfTree(Node newnode)
	{
		if(newnode == null)
		{
			return 0;
		}

		int lh = heightOfTree(newnode.left);
		int rh = heightOfTree(newnode.right);

		return 1 + max(lh,rh);
	}

	private int diameterOfTree(Node newnode)
	{
		if(newnode == null)
		{
			return 0;
		}
		
		int lh = heightOfTree(newnode.left);
		int rh = heightOfTree(newnode.right);

		int ld = diameterOfTree(newnode.left);
		int rd = diameterOfTree(newnode.right);

		return max(1 + lh + rh,max(ld,rd));
	}

	public static void main(String args[])
	{
		DayTwentySix tree = new DayTwentySix();
		Node btree = tree.createBtree();

		System.out.print("Height of given BianryTree => ");
		System.out.println(tree.heightOfTree(btree));

		System.out.print("Diameter of given BianryTree => ");
		System.out.println(tree.diameterOfTree(btree));
	}
}