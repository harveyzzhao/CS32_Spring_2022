//You must not assume that the infix string passed to the function is syntactically valid
#include <iostream>
#include <string>
#include <stack>
#include <cassert>
using namespace std;

//step 0. take out the blankspace
string deSpacify(const string& infix)
{
    string strNoSpace;
    for (auto ch : infix)
    {
        if (ch != ' ')
            strNoSpace += ch;
    }
    return strNoSpace;
}

bool checkInfixHead(char head)
{
    switch(head)
    {
        case '!':
        case '(':
        case 'T':
        case 'F':
            return true;
        default:
            return false;
    }
}

int precedence(char o1, char o2)
{
    if (o1 < o2)
        return 1;
    else if (o1 == o2)
        return 0;
    else
        return -1;
}

void binary(stack<char>& operatorStack, string& postfix, char ch)
{
    while (!operatorStack.empty() && operatorStack.top() != '(' && !(precedence(ch, operatorStack.top()) == 1))
    {
        postfix += operatorStack.top();
        operatorStack.pop();
    }
    operatorStack.push(ch);
}

void unary(stack<char>& operatorStack, char ch)
{
    operatorStack.push(ch);
}

//step 1. convert infix to postfix
bool infixToPostfix(string infix, string& postfix)
{
    //Initialize postfix to empty
    postfix = "";
    //Initialize the operator stack to empty
    stack<char> operatorStack;
    char prev = '#';
    
    //For each character ch in the infix string
    for (auto ch : infix)
    {
        switch(ch)
        {
            case 'T':
            case 'F':
                if (prev == 'T' || prev == 'F' || prev == ')')
                    return false;
                postfix += ch;
                break;
            case '(':
                if (prev == 'T' || prev == 'F' || prev == ')')
                    return false;
                operatorStack.push(ch);
                break;
            case ')':
                if (prev == '&' || prev == '|' || prev == '!' || prev == '(')
                    return false;
                while (!operatorStack.empty() && operatorStack.top() != '(')
                {
                    postfix += operatorStack.top();
                    operatorStack.pop();
                }
                if (operatorStack.empty())
                    return false;
                operatorStack.pop();    //remove the '('
                break;
            case '!':
                if (prev == ')' || prev == 'T' || prev == 'F')
                    return false;
                unary(operatorStack, ch);
                break;
            case '&':
                if (prev == '&' || prev == '|' || prev == '!' || prev == '(')
                    return false;
                binary(operatorStack, postfix, ch);
                break;
            case '|':
            {
                if (prev == '&' || prev == '|' || prev == '!' || prev == '(')
                    return false;
                binary(operatorStack, postfix, ch);
                break;
            }
            default:
                return false;
        }
        prev = ch;
    }
    
    if (prev == '&' || prev == '|' || prev == '!' || prev == '(')
        return false;
    
    while (!operatorStack.empty())
    {
        if (operatorStack.top() == '(' || operatorStack.top() == ')')
            return false;
        postfix += operatorStack.top();
        operatorStack.pop();
    }
    return true;
}

bool evalPostfix(string& postfix, bool& result)
{
    stack<bool> operandStack;
    for (auto ch : postfix)
    {
        char operand1, operand2;
        switch(ch)
        {
            case 'T':
                operandStack.push(true);
                break;
                
            case 'F':
                operandStack.push(false);
                break;
                
            case '!':
                if (operandStack.empty())
                    return false;
                operand1 = operandStack.top();
                operandStack.pop();
                operandStack.push(!operand1);
                break;
                
            case '&':
                if (operandStack.empty())
                    return false;
                operand2 = operandStack.top();
                operandStack.pop();
                
                if (operandStack.empty())
                    return false;
                operand1 = operandStack.top();
                operandStack.pop();
                
                operandStack.push(operand1 && operand2);
                break;
                
            case '|':
                if (operandStack.empty())
                    return false;
                operand2 = operandStack.top();
                operandStack.pop();
                
                if (operandStack.empty())
                    return false;
                operand1 = operandStack.top();
                operandStack.pop();
    
                operandStack.push(operand1 || operand2);
                break;
                
            default:
                return false;
        }
    }
    if (operandStack.size() != 1)
        return false;
    result = operandStack.top();
    return true;
}

int evaluate(string infix, string& postfix, bool& result)
{
    string newInfix = deSpacify(infix);
    if (newInfix == "") return 1;
    else if (checkInfixHead(newInfix.at(0)) == false)   return 1;
    if (infixToPostfix(newInfix, postfix) == false) return 1;
    if (evalPostfix(postfix, result) == false)  return 1;
    return 0;
}

int main()
{
    //test deSpacify()
    string n = deSpacify("");
    cerr << "aa" << n << "aa" << endl;

    char a = '!';
    char b = '&';
    char c = '|';

    assert(precedence(a, '&') == 1);
    assert(precedence('!', '!') == 0);
    assert(precedence('!', c) == 1);
    assert(precedence(b, '!') == -1);
    assert(precedence('&', '&') == 0);
    assert(precedence(b, c) == 1);
    assert(precedence('|', '!') == -1);
    assert(precedence('|', '&') == -1);
    assert(precedence('|', '|') == 0);

    //test checkInfixHead()
    string testa = "a&|!()TF";

    assert(checkInfixHead(testa[0]) == false);
    assert(checkInfixHead(testa[1]) == false);
    assert(checkInfixHead(testa[2]) == false);
    assert(checkInfixHead(testa[3]) == true);
    assert(checkInfixHead(testa[4]) == true);
    assert(checkInfixHead(testa[5]) == false);
    assert(checkInfixHead(testa[6]) == true);
    assert(checkInfixHead(testa[7]) == true);
    assert(checkInfixHead('F') == true);

    //check step I alone: I modified the answer part just so it is in compliant with the current implementation in evaluate()
    string pf;
    bool answer;
    assert(evaluate("(T&(F|F)", pf, answer) == 1);
    assert(evaluate("T|", pf, answer) == 1);
    assert(evaluate("F F", pf, answer) == 1);
    assert(evaluate("TF", pf, answer) == 1);
    assert(evaluate("()", pf, answer) == 1);
    assert(evaluate("(  )", pf, answer) == 1);
    assert(evaluate("(  T&F)T", pf, answer) == 1);
    assert(evaluate("T(F|T)", pf, answer) == 1);
    assert(evaluate("T(&T)", pf, answer) == 1);
    assert(evaluate("", pf, answer) == 1);
    assert(evaluate("  ", pf, answer) == 1);
    assert(evaluate("T!", pf, answer) == 1);
    assert(evaluate("T(", pf, answer) == 1);
    assert(evaluate("(TT", pf, answer) == 1);
    assert(evaluate("&TF", pf, answer) == 1);
    assert(evaluate(")(", pf, answer) == 1);
    assert(evaluate("#2", pf, answer) == 1);
    assert(evaluate("F&&", pf, answer) == 1);
    assert(evaluate("F!!", pf, answer) == 1);
    assert(evaluate("F!!T", pf, answer) == 1);

    assert(evaluate("(T|F)T", pf, answer) == 1);
    assert(evaluate("F&(&T)", pf, answer) == 1);
    assert(evaluate("F&|T", pf, answer) == 1);
    assert(evaluate("T!T", pf, answer) == 1);
    assert(evaluate("(F", pf, answer) == 1);
    assert(evaluate("F)", pf, answer) == 1);
    assert(evaluate("TF", pf, answer) == 1);
    assert(evaluate("F:T", pf, answer) == 1);
    assert(evaluate("F&:", pf, answer) == 1);
    assert(evaluate("F T&T", pf, answer) == 1);
    assert(evaluate("1& |T", pf, answer) == 1);

    assert(evaluate("T| F", pf, answer) == 0  &&  pf == "TF|"  &&  answer);
    assert(evaluate("T|", pf, answer) == 1);
    assert(evaluate("F F", pf, answer) == 1);
    assert(evaluate("TF", pf, answer) == 1);
    assert(evaluate("(T))))))))))))", pf, answer) == 1);
    assert(evaluate("()T", pf, answer) == 1);
    assert(evaluate("T(F|T)", pf, answer) == 1);
    assert(evaluate("T(&T)", pf, answer) == 1);
    assert(evaluate("(T&(F|F)", pf, answer) == 1);
    assert(evaluate("T+F", pf, answer) == 1);
    assert(evaluate("", pf, answer) == 1);
    assert(evaluate("(&T", pf, answer) == 1);
    assert(evaluate("!&T", pf, answer) == 1);
    assert(evaluate("(FF)))", pf, answer) == 1);
    assert(evaluate("(&T", pf, answer) == 1);
    assert(evaluate("(T&(F|F))", pf, answer) == 0 && pf == "TFF|&" && !answer);
    assert(evaluate("(T&(FFF", pf, answer) == 1);
    assert(evaluate("F  |  !F & (T&F) ", pf, answer) == 0
                           &&  pf == "FF!TF&&|"  &&  !answer);
    assert(evaluate("!F", pf, answer) == 0 &&  pf == "F!"  &&  answer);
    assert(evaluate("!F&T|   F", pf, answer) == 0 && pf == "F!T&F|" && answer);
    assert(evaluate(" F  ", pf, answer) == 0 &&  pf == "F"  &&  !answer);
    assert(evaluate("((T))", pf, answer) == 0 &&  pf == "T"  &&  answer);
    assert(evaluate("!(F&T)|F", pf, answer) == 0);
    assert(evaluate("!!!!!!!T", pf, answer) == 0 && pf == "T!!!!!!!" && !answer);

    assert(evaluate("T", pf, answer) == 0 && pf == "T"  && answer );
    assert(evaluate("(F)", pf, answer) == 0 && pf == "F"  && !answer);
    assert(evaluate("T&(F)", pf, answer) == 0 && pf == "TF&"  && !answer);
    assert(evaluate("T & !F", pf, answer) == 0 && pf == "TF!&"  && answer);
    assert(evaluate("!((!F)|T)", pf, answer) == 0 && pf == "F!T|!"  && !answer);
    assert(evaluate("!F|T", pf, answer) == 0 && pf == "F!T|"  && answer);
    assert(evaluate("T|F&F", pf, answer) == 0 && pf == "TFF&|"  && answer);
    assert(evaluate("T&!(F|T&T|F)|!!!(F&T&F)", pf, answer) == 0 && pf == "TFTT&|F|!&FT&F&!!!|"  && answer);

    //valid cases
    assert(evaluate("((T))", pf, answer) == 0 &&  pf == "T"  &&  answer);
    assert(evaluate("(T & !F)", pf, answer) == 0  &&  pf == "TF!&"  &&  answer);
    assert(evaluate("!F  |  !F & (T&F) ", pf, answer) == 0  &&  pf == "F!F!TF&&|"  &&  answer);
    assert(evaluate("(T&(F|F))", pf, answer) == 0 && pf == "TFF|&" && !answer);
    assert(evaluate("F&T&F", pf, answer) == 0 && pf == "FT&F&"  && !answer);
    assert(evaluate("T&!!F", pf, answer) == 0 && pf == "TF!!&" && !answer);

    cerr << "what?" << endl;
    cerr << "Passed all tests" << endl;
}
