#include <iostream>
#include <stack>
#include <string>
#include <map>
using namespace std;

bool PolishNotation(char*, string&);

void main()
{   
    char str[100];
    string result;

    cout << "Enter the line: ";
    cin.getline(str, 100);

    if (PolishNotation(str, result))
    {
        cout << endl << "The conversion was completed successfully!" << endl;
        cout << "Source string: " << str << endl;
        cout << "Converted String: " << result << endl;
    }
    else
    {
        cout << endl << "Conversion failed" << endl;
    }
}

map <char, int> priority = {
	{'(', 1},
	{')', 1},
	{'+', 2},
	{'-', 2},
	{'*', 3},
	{'/', 3}
};

bool PolishNotation(char* str, string& result)
{
	stack<char> st;
	for (int i = 0; i < strlen(str); i++)
	{
		char s = str[i];
		if (s == ' ' || s == '\t')
		{
			continue;
		}
		if (s == '(')
		{
			st.push(s);
		}
		else if (s == ')')
		{
			if (st.empty())
			{
				return false;
			}
			while (st.top() != '(')
			{
				s = st.top();
				st.pop();
				result.push_back(s);

				if (st.empty())
				{
					return false;
				}
			}
			st.pop();
		}
		else if (s == '+' || s == '-' || s == '*' || s == '/')
		{
			while (!st.empty() && priority[s] <= priority[st.top()])
			{
				result.push_back(st.top());
				st.pop();
			}
			st.push(s);
		}
		else
		{
			result.push_back(s);
		}
	}
	while (!st.empty())
	{
		char s = st.top();
		st.pop();
		if (s == '(')
		{
			return false;
		}
		while (!st.empty() && priority[s] <= priority[st.top()])
		{
			result.push_back(st.top());
			st.pop();
		}
		result.push_back(s);
	}
	return true;
}
