# include <iostream>
# include <queue>

using namespace std;

struct key
{
	int freq;
	char ch;

	bool operator<(const key &k) const
    { 
        return freq < k.freq; 
    }
};

void reArrangeString(string str)
{
	int count[26] = {0};

	// creating a hashArray
	for(int i=0;i<str.length();i++)
	{
		count[str[i]-'a'] = count[str[i]-'a'] + 1;
	}

	priority_queue<key> pq;

	key temp;

	for(char c = 'a';c <= 'z';c++ )
	{
		if(count[c-'a'] > 0)
		{
			temp.freq = count[c-'a'];
			temp.ch = c;
			pq.push(temp);
		}
	}

	string res = "";
	key previous;
	previous.freq = -1;
	previous.ch = '$';

	while(pq.empty() == false)
	{
		key k = pq.top();
		pq.pop();
		res = res + k.ch;

		if(previous.freq > 0)
		{
			pq.push(previous);
		}

		k.freq = k.freq - 1;
		previous = k;
	}

	if(str.length() != res.length())
	{
		cout << "Invalid String" << endl;
	}
	else
	{
		cout << "result => " << res << endl;
	}

}

int main()
{
	string str = "bbbaa";
	reArrangeString(str);
	return 0;
}