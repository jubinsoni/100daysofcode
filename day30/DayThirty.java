import java.util.Queue;
import java.util.LinkedList;

public class DayThirty
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

	private int distanceFromRoot(Node newnode,int x)
	{
		if(x > newnode.data)
		{
			return 1 + distanceFromRoot(newnode.right,x);
		}
		else if(x < newnode.data)
		{
			return 1 + distanceFromRoot(newnode.left,x);
		}

		return 0;
	}

	private int distanceFrom2Nodes(Node root,int x,int y)
	{
		if(root == null)
		{
			return 0;
		}

		if(x > y)
		{
			int temp = x;
			x = y;
			y = temp;
		}

		if(x > root.data && y > root.data)
		{
			return distanceFrom2Nodes(root.right,x,y);
		}

		if(x < root.data && y < root.data)
		{
			return distanceFrom2Nodes(root.left,x,y);
		}

		if(x <= root.data && y >= root.data)
		{
			return distanceFromRoot(root,x) + distanceFromRoot(root,y);
		}

		return 0;
	}

	public static void main(String args[])
	{
		DayThirty tree = new DayThirty();
		Node btree = tree.createBtree();

		int x,y;

		x = 3;y = 9;
		System.out.println("distanceBetween2Node(" + x + "," + y + ") => " + tree.distanceFrom2Nodes(btree,x,y));
		x = 3;y = 6;
		System.out.println("distanceBetween2Node(" + x + "," + y + ") => " + tree.distanceFrom2Nodes(btree,x,y));
	}
}