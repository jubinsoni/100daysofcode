import java.util.Queue;
import java.util.LinkedList;

public class DayTwentyNine
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
	
	private Node createBtree(Node tree,int arr[])
	{
		Node newnode = new Node(arr[0]);
		if(tree == null)
		{
			tree = newnode;
		}

		newnode.left = new Node(arr[1]);
		newnode.right = new Node(arr[2]);

		newnode.left.left = new Node(arr[3]);
		newnode.left.right = new Node(arr[4]);

		newnode.right.left = new Node(arr[5]);
		newnode.right.right = new Node(arr[6]);

		return tree;
	}

	private void levelOrderTraversal(Node tree)
	{
		Node newnode = tree;
		Queue<Node> q = new LinkedList<Node>();
		q.add(newnode);

		while(q.isEmpty() == false)
		{
			Node temp = q.peek();
			System.out.print(temp.data + " ");
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
	}

	private boolean isChildrenSum(Node curr)
	{
		if(curr == null)
		{
			return true;
		}

		if(curr.left == null && curr.right == null)
		{
			return true;
		}

		int sum = 0;
		if(curr.left != null)
		{
			sum = sum + curr.left.data;
		}

		if(curr.right != null)
		{
			sum = sum + curr.right.data;
		}

		if(curr.data == sum && isChildrenSum(curr.left) == true && isChildrenSum(curr.right) == true)
		{
			return true;
		}

		return false;
	}

	public static void main(String args[])
	{
		DayTwentyNine treeMethod = new DayTwentyNine();
		Node tree1 = null;
		int arr1[] = {20,8,12,3,5,2,10};
		tree1 = treeMethod.createBtree(tree1,arr1);

		System.out.print("levelOrderTraversal => ");
		treeMethod.levelOrderTraversal(tree1);
		System.out.println();

		System.out.println("isChildrenSum => " + treeMethod.isChildrenSum(tree1));

		int arr2[] = {7,5,10,3,6,9,12};
		Node tree2 = null;
		tree2 = treeMethod.createBtree(tree2,arr2);

		System.out.print("levelOrderTraversal => ");
		treeMethod.levelOrderTraversal(tree2);
		System.out.println();

		System.out.println("isChildrenSum => " + treeMethod.isChildrenSum(tree2));
	}
}