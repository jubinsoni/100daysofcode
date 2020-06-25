import java.util.Queue;
import java.util.LinkedList;

public class DayTwentyFive
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

	private int maxWidth(Node newnode)
	{
		Queue<Node> q = new LinkedList<Node>();
		q.add(newnode);
		int max_width = 0;
		while(q.isEmpty() == false)
		{
			if(max_width < q.size())
			{
				max_width = q.size();
			}

			Node temp = q.peek();
			q.remove();

			if(temp.left != null)
			{
				q.add(temp.left);
			}

			if(temp.right != null)
			{
				q.add(temp.right);
			}
		}
		return max_width;
	}

	public static void main(String args[])
	{
		DayTwentyFive tree = new DayTwentyFive();
		Node btree = tree.createBtree();

		System.out.print("maxWidth of given BianryTree => ");
		System.out.println(tree.maxWidth(btree));
	}
}