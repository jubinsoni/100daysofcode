# include <iostream>
# include <stack>

using namespace std;

int charToInt(string str)
{
	int val = 0;
	for(int i=0;i<str.length();i++)
	{
		val = 10*val + str[i] - '0';
	}
	return val;
}

string doOperation(char op,string A,string B)
{
	if(op =='+')
	{
		return to_string(stoi(A) + stoi(B));
	}
	else if(op =='-')
	{
		return to_string(stoi(A) - stoi(B));
	}
	else if(op =='/')
	{
		return to_string(stoi(A) / stoi(B));
	}
	//if(op =='*')
	return to_string(stoi(A) * stoi(B));
}

bool isOperator(char ch)
{
	if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
	{
		return true;
	}
	return false;
}

string postFixEvaluation(string expr)
{
	stack<string> st;
	for(int i=0;i<expr.length();i++)
	{
		if(isOperator(expr[i]) == false)
		{
			st.push(string(1,expr[i]));
		}
		else
		{
			string B = st.top();
			st.pop();
			string A = st.top();
			st.pop();
			st.push(doOperation(expr[i],A,B));
		}
	}

	return st.top();
}

int main()
{
	string expr = "231*+9-";
	cout << "postFixEvaluation of (" << expr << ") => ";
	cout << postFixEvaluation(expr) << endl;

	return 0;
}