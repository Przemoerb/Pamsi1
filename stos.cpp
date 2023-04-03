#include <iostream>

using namespace std;

struct Element
{
    int value;
    Element *next;
};

class Stack
{
    Element *listStack;
    int *arrayStack;
    int arraySize;
    int top;

public:
    Stack();
    ~Stack();

    void pushElementToList(int value);
    int popElementFromList();
    void clearList();
    void printList();

    void pushElementToArray(int value);
    int popElementFromArray();
    void clearArray();
    void printArray();
};
Stack::Stack()
{
    listStack = nullptr;
    arrayStack = new int[1];
    arraySize = 1;
    top = -1;
}
Stack::~Stack()
{
    if (arrayStack)
        delete[] arrayStack;
    while (listStack)
        popElementFromList();
}

void Stack::pushElementToList(int value)
{
    Element *newElement = new Element;
    newElement->value = value;
    newElement->next = listStack;
    listStack = newElement;
}
int Stack::popElementFromList()
{
    int returnValue;
    if (listStack)
    {
        returnValue = listStack->value;
        Element *tmp = listStack;
        listStack = listStack->next;
        delete tmp;
        
    }
    return returnValue;
}
void Stack::clearList()
{
    while (listStack)
        popElementFromList();
}
void Stack::printList()
{
    for (Element *tmp = listStack; tmp; tmp = tmp->next)
        cout << tmp->value;
}

void Stack::pushElementToArray(int value)
{
    if (top == arraySize - 1)
    {
        int *newData = new int[arraySize * 2];
        for (int i = 0; i <= top; i++)
        {
            newData[i] = arrayStack[i];
        }
        delete[] arrayStack;
        arrayStack = newData;
        arraySize *= 2;
    }
    top++;
    arrayStack[top] = value;
}
int Stack::popElementFromArray()
{
    if (top == -1)
    {
        cout << "Stos pusty" << endl;
        return -1;
    }
    int element = arrayStack[top];
    top--;
    if (top < arraySize / 2)
    {
        int *newData = new int[arraySize / 2];
        for (int i = 0; i <= top; i++)
        {
            newData[i] = arrayStack[i];
        }
        delete[] arrayStack;
        arrayStack = newData;
        arraySize /= 2;
    }
    return element;
}
void Stack::clearArray()
{
    delete[] arrayStack;
    arrayStack = new int[1];
    arraySize = 1;
    top = -1;
}
void Stack::printArray()
{
    for (int i = top; i >= 0; i--)
        cout << arrayStack[i];
}

/*int main()
{
    Stack ExampleStack;

    cout << "Stos jako lista:" << endl;
    int start = clock();
    for (int j = 0; j < 1000000; j++)
    {
        ExampleStack.pushElementToList(rand() % 100);
    }
    cout << "czas dla 1000000 danych to " << clock() - start << " milisekund" << endl;
    ExampleStack.clearList();

    cout << "Stos jako tablica:" << endl;
    start = clock();
    for (int j = 0; j < 1000000; j++)
    {
        ExampleStack.pushElementToArray(rand() % 100);
    }
    cout << "czas dla 1000000 danych to " << clock() - start << " milisekund" << endl;
    ExampleStack.clearArray();

    return 0;
}*/
