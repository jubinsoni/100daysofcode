import java.util.Queue;
import java.util.LinkedList;

public class DayTwentyTwo
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


	private void preorder(Node newnode)
	{
		if(newnode != null)
		{
			System.out.print(newnode.data + " ");
			preorder(newnode.left);
			preorder(newnode.right);
		}
	}

	private void postorder(Node newnode)
	{
		if(newnode != null)
		{
			postorder(newnode.left);
			postorder(newnode.right);
			System.out.print(newnode.data + " ");
		}
	}

	private void levelorderTraversal(Node newnode)
	{
		Queue<Node> q = new LinkedList<Node>();
		q.add(newnode);
		while(q.size() != 0)
		{
			Node curr = q.peek();
			System.out.print(curr.data + " ");
			q.remove();
			if(curr.left != null)
			{
				q.add(curr.left);
			}

			if(curr.right != null)
			{
				q.add(curr.right);
			}
		}
	}

	public static void main(String args[])
	{
		DayTwentyTwo tree = new DayTwentyTwo();
		Node btree = tree.createBtree();
		System.out.print("Inorder Traversal of given Tree => ");
		tree.inorder(btree);
		System.out.println();
		System.out.print("Preorder Traversal of given Tree => ");
		tree.preorder(btree);
		System.out.println();
		System.out.print("Postorder Traversal of given Tree => ");
		tree.postorder(btree);
		System.out.println();
		System.out.print("levelorderTraversal of given Tree => ");
		tree.levelorderTraversal(btree);
		System.out.println();
	}
}