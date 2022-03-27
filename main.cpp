#include <iostream>
#include <stack>
using namespace std;

void iterSwapStacks (stack<int>& stack1, stack<int>& stack2)
{
    size_t stackSize = stack1.size();

}

void recurSwapStacks (stack<int>& stack1, stack<int>& stack2)
{

}

void stlSwapStacks (stack<int>& stack1, stack<int>& stack2)
{
    stack1.swap(stack2);
}

void moveStacks (stack<int>& stack1, stack<int>& stack2)
{
    stack2 = stack1;
    stack1 = {};
}

void printStack (stack<int>& stack1)
{
    if (!stack1.empty())
    {
        size_t stackSize = stack1.size();
        while (stackSize)
        {
            cout << stack1.top();
            stack1.pop();
            --stackSize;
        }
        cout << endl;
    }
    else
    {
        cout << "Stack is empty\n" << endl;
    }
}

int main()
{
    stack<int> aStack;
    stack<int> bStack;

    for (int i = 5; i >= 1; --i)
    {
        aStack.push(i);
    }


//    stlSwapStacks(aStack, bStack);
//    moveStacks(aStack, bStack);

    cout << "Stack1:\n";
    printStack(aStack);
    cout << "Stack2:\n";
    printStack(bStack);
    return 0;
}
