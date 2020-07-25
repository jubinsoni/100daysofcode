# include <iostream>
# include <stack>

using namespace std;

bool parenthesesCheck(string str)
{
	stack<char> st;

	for(int i=0;i<str.length();i++)
	{
		if(str[i] == '[' || str[i] == '(' || str[i] == '{')
		{
			st.push(str[i]);
		}
		else if(str[i] == ']')
		{
			if(st.top() == '(' || st.top() == '{')
			{
				return false;
			}
			st.pop();
		}
		else if(str[i] == ')')
		{
			if(st.top() == '[' || st.top() == '{')
			{
				return false;
			}
			st.pop();
		}
		else if(str[i] == '}')
		{
			if(st.top() == '(' || st.top() == '[')
			{
				return false;
			}
			st.pop();
		}
	}

	if(st.empty() == true)
	{
		return true;
	}

	return false;
}

int main()
{
	string expression1 = "[](())";
	cout << "parentheses balanced for expression " << expression1;
	cout << " => "  << parenthesesCheck(expression1) << endl;

	string expression2 = "[]([(]))";
	cout << "parentheses balanced for expression " << expression2;
	cout << " => "  << parenthesesCheck(expression2) << endl;

	return 0;
}