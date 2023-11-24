#include <bits/stdc++.h>
using namespace std;

bool IsOperator(char c) {
    return c == '+' || c == '-' || c == '*';
}

class Calulator
{
private:
    string expression;

public:
    Calulator(string str) : expression(str) {}
    void preprocessing()
    {
        expression.erase(remove_if(expression.begin(), expression.end(), [](char c)
                                   { return c == ' '; }),
                         expression.end());
        while (expression.find("abs") != string::npos)
        {
            int loc = expression.find("abs");

            expression.erase(loc, 4);
            if(expression[loc]=='-') expression.erase(loc, 1);
            expression.erase(expression.find(')',loc), 1);
        }
        //cout<<expression<<endl;
    }
    string infixToPostfix()
    {
        string postfix;
        stack<char> stack;
        string operators = "+-*";
        for (int i = 0; i < expression.length(); ++i)
        {
            char c = expression[i];

            if (isdigit(c))
            {
                postfix += c;
                while (i + 1 < expression.length() && isdigit(expression[i + 1]))
                {
                    postfix += expression[++i];
                }
                postfix += ' '; // Thêm dấu cách để phân biệt các số
            }
            else if (operators.find(c) != string::npos)
            {
                while (!stack.empty() && operators.find(stack.top()) != string::npos &&
                       operators.find(stack.top()) >= operators.find(c))
                {
                    postfix += stack.top();
                    stack.pop();
                }
                stack.push(c);
            }
            else if (c == '(')
            {
                stack.push(c);
            }
            else if (c == ')')
            {
                while (!stack.empty() && stack.top() != '(')
                {
                    postfix += stack.top();
                    stack.pop();
                }
                if (!stack.empty())
                    stack.pop();
            }
        }

        while (!stack.empty())
        {
            postfix += stack.top();
            stack.pop();
        }

        return postfix;
    }

    float EvaluatePostfix(const std::string &postfix)
    {
        std::stack<float> stack;
        std::string number;

        for (char c : postfix)
        {
            if (c == ' ')
            {
                if (!number.empty())
                {
                    stack.push(stof(number));
                    number.clear();
                }
            }
            else if (isdigit(c))
            {
                number += c;
            }
            else if (IsOperator(c) && stack.size() >= 2)
            {
                float x = stack.top();
                stack.pop();
                float y = stack.top();
                stack.pop();

                switch (c)
                {
                case '+':
y += x;
                    break;
                case '-':
                    y -= x;
                    break;
                case '*':
                    y *= x;
                    break;

                }
                stack.push(y);
            }
        }

        return stack.empty() ? 0 : stack.top();
    }
};

int main()
{
    string str;
    getline(cin, str);
    if (str[0] == '-') str = "0" + str;
    Calulator ex(str);
    ex.preprocessing();
    string postfix = ex.infixToPostfix();
    //cout << postfix << endl;
    cout << ex.EvaluatePostfix(postfix) << endl;

    return 0;
}