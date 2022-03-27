#include <iostream>
#include <stack>

using namespace std;

void iterSwapStacks(stack<int> &aStack, stack<int> &bStack)
{
    size_t stackSize = aStack.size();
    int i{0};
    int temp;

    while (i < stackSize - 1)
    {
        temp = aStack.top();
        aStack.pop();

        while (i < aStack.size())
        {
            bStack.push(aStack.top());
            aStack.pop();
        }
        aStack.push(temp);
        while (!bStack.empty())
        {
            aStack.push(bStack.top());
            bStack.pop();
        }

        ++i;
    }

    while (!aStack.empty())
    {
        bStack.push(aStack.top());
        aStack.pop();
    }


}

void recurSwapStacks(stack<int> &aStack, stack<int> &bStack)
{
    if(!aStack.empty())
    {
        int temp = aStack.top();
        aStack.pop();

        recurSwapStacks(aStack,bStack);
        bStack.push(temp);
    }
}

void stlSwapStacks(stack<int> &aStack, stack<int> &bStack)
{
    aStack.swap(bStack);
}

void moveStacks(stack<int> &aStack, stack<int> &bStack)
{
    bStack = aStack;
    aStack = {};
}

void printStack(stack<int> &aStack)
{
    if (!aStack.empty())
    {
        size_t stackSize = aStack.size();
        while (stackSize)
        {
            cout << aStack.top();
            aStack.pop();
            --stackSize;
        }
        cout << endl;
    } else
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

    iterSwapStacks(aStack, bStack);
//    recurSwapStacks(aStack, bStack);
//    stlSwapStacks(aStack, bStack);
//    moveStacks(aStack, bStack);

    cout << "Stack1:\n";
    printStack(aStack);
    cout << "Stack2:\n";
    printStack(bStack);
    return 0;
}
