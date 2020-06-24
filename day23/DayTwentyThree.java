import java.util.Queue;
import java.util.LinkedList;
import java.util.Stack;

public class DayTwentyThree
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

	private void swap(Stack<Node> currentLevel,Stack<Node> nextLevel)
	{
		Stack<Node> tempLevel = new Stack<Node>();
		while(nextLevel.empty() == false)
		{
			Node temp = nextLevel.peek();
			nextLevel.pop();
			tempLevel.push(temp);
		}

		while(tempLevel.empty() == false)
		{
			Node temp = tempLevel.peek();
			tempLevel.pop();
			currentLevel.push(temp);
		}
	}

	private void zigzagTraversal(Node newnode)
	{
		Stack<Node> currentLevel = new Stack<Node>();
		Stack<Node> nextLevel = new Stack<Node>();

		currentLevel.push(newnode);
		boolean leftToRight = true;
		while(currentLevel.empty() == false)
		{
			Node temp = currentLevel.peek();
			currentLevel.pop();
			if(temp != null)
			{
				System.out.print(temp.data + " ");
				if(leftToRight == true)
				{
					if(temp.left != null)
					{
						nextLevel.push(temp.left);
					}

					if(temp.right != null)
					{
						nextLevel.push(temp.right);
					}
				}
				else
				{
					if(temp.right != null)
					{
						nextLevel.push(temp.right);
					}

					if(temp.left != null)
					{
						nextLevel.push(temp.left);
					}
				}
			}

			if(currentLevel.empty() == true)
			{
				leftToRight = !leftToRight;
				swap(currentLevel,nextLevel);
			}
		}
	}

	public static void main(String args[])
	{
		DayTwentyThree tree = new DayTwentyThree();
		Node btree = tree.createBtree();
		System.out.print("zigzagTraversal of given Tree => ");
		tree.zigzagTraversal(btree);
		System.out.println();
	}
}