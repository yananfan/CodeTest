//#define _InterpreterPattern_
#ifdef _InterpreterPattern_

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Context;
class AbstractExpression
{
public:
	virtual void Interpreter(Context* context) = 0;
};
class Expression :public AbstractExpression
{
public:
	virtual void Interpreter(Context* context) {
		cout << "Terminal interpreter." << endl;
	}
};
class NonTerminalExpression :public AbstractExpression
{
public:
	virtual void Interpreter(Context* context) {
		cout << "NonTerminal interpreter." << endl;
	}
};
class Context
{
public:
	string input;
	string output;
};

int main()
{
	Context* context = new Context();
	vector<AbstractExpression*> express;
	express.push_back(new Expression());
	express.push_back(new NonTerminalExpression());
	express.push_back(new NonTerminalExpression());
	vector<AbstractExpression*>::iterator p = express.begin();
	while (p != express.end()) {
		(*p)->Interpreter(context);
		p++;
	}
	return 0; 
}

#endif // _InterpreterPattern_
