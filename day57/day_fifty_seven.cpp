# include <iostream>
# include <stack>

using namespace std;

// algo explained => https://www.youtube.com/watch?v=vXPL6UavUeA

int priority(char ch)
{
	if(ch == '^')
	{
		return 3;
	}
	else if(ch == '*' || ch == '/')
	{
		return 2;
	}
	else if(ch == '+' || ch == '-')
	{
		return 1;
	}

	return -1;
}

string infixToPostFix(string str)
{
	stack<char> st;
	string postFix = "";
	for(int i=0;i<str.length();i++)
	{
		if(str[i] == '(')
		{
			st.push(str[i]);
		}
		else if(str[i] == ')')
		{
			while(st.top() != '(')
			{
				postFix = postFix + st.top();
				st.pop();
			}
			st.pop();
			//cout << "---" << postFix << " " << st.top() << " " << str[i] << endl;
		}
		else if(str[i] >= 'A' && str[i] <= 'Z')
		{
			postFix = postFix + str[i];
		}
		else if(str[i] == '^' || str[i] == '*' || str[i] == '/' || str[i] == '+' || str[i] == '-')
		{
				//cout << postFix << " " << st.top() << " " << str[i] << endl;
				if(priority(st.top()) < priority(str[i]))
				{
					st.push(str[i]);
				}
				else
				{
					//cout << st.top() << endl;
					while(priority(st.top()) >= priority(str[i]))
					{
						postFix = postFix + st.top();
						st.pop();
					}
					st.push(str[i]);
					//cout << st.top() << endl;
				}
			
		}
	}

	return postFix;
}

int main()
{
	string str = "(A+B/C*(D+E)-F)";
	cout << "infixToPostFix of " + str + " => " << infixToPostFix(str) << endl;


	return 0;
}