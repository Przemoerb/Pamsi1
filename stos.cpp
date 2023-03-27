#include <iostream>

using namespace std;

struct Element
{
    int value;
    Element *next;
};

class Stack
{
    int *arrayStack;
    Element *listStack;
    int arraySize;

public:
    Stack();
    ~Stack();

    void pushElementToList(int value);
    void popElementFromList();
    void clearList();
    void printList();

    void pushElementToArray(int value);
    void popElementFromArray();
    void clearArray();
    void printArray();
    
};
Stack::Stack()
{
    listStack = nullptr;
    arrayStack = nullptr;
    arraySize = 0;
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
void Stack::popElementFromList()
{
    if (listStack)
    {
        Element *tmp = listStack;
        listStack = listStack->next;
        delete tmp;
    }
}
void Stack::clearList()
{
    while (listStack)
        popElementFromList();
}
void Stack::printList()
{
    for (Element *tmp = listStack; tmp; tmp = tmp->next)
        cout << tmp->value << endl;
    cout << endl;
}



void Stack::pushElementToArray(int value)
{
    arraySize++;
    int *tmpArrayStack = new int[arraySize];
    for (int i = 0; i < arraySize - 1; i++)
        tmpArrayStack[i] = arrayStack[i];
    if (arrayStack)
        delete[] arrayStack;
    arrayStack = new int[arraySize];
    for (int i = 0; i < arraySize - 1; i++)
        arrayStack[i] = tmpArrayStack[i];
    delete[] tmpArrayStack;
    arrayStack[arraySize - 1] = value;
}
void Stack::popElementFromArray()
{
    arraySize--;
    if (arraySize > 0)
    {
        int *tmpArrayStack = new int[arraySize];
        for (int i = 0; i < arraySize; i++)
            tmpArrayStack[i] = arrayStack[i];
        delete[] arrayStack;
        arrayStack = new int[arraySize];
        for (int i = 0; i < arraySize; i++)
            arrayStack[i] = tmpArrayStack[i];
        delete[] tmpArrayStack;
    }
    else
    {
        delete[] arrayStack;
    }
}
void Stack::clearArray()
{
    //delete[] arrayStack;
    arraySize = 0;
}
void Stack::printArray()
{
    for (int i = arraySize - 1; i >= 0; i--)
        cout << arrayStack[i] << endl;
    cout << endl;
}

void checkTimeArray(Stack s, int numberOfOccurrences)
{
    int start = clock();
    for (int j = 0; j < numberOfOccurrences; j++)
    {
        s.pushElementToArray(rand() % 100);
    }
    cout << "czas dla "<< numberOfOccurrences <<" danych to " << clock() - start << " milisekund" << endl;
    s.clearArray();
}

void checkTimeList(Stack s, int numberOfOccurrences)
{
    int start = clock();
    for (int j = 0; j < numberOfOccurrences; j++)
    {
        s.pushElementToList(rand() % 100);
    }
    cout << "czas dla "<< numberOfOccurrences <<" danych to " << clock() - start << " milisekund" << endl;
    s.clearList();
}
int main()
{
    Stack ExampleStack;

    cout << "Stos jako lista:" << endl;
    checkTimeList(ExampleStack,10);
    checkTimeList(ExampleStack,100);
    checkTimeList(ExampleStack,1000);
    checkTimeList(ExampleStack,10000);
    checkTimeList(ExampleStack,100000);
    checkTimeList(ExampleStack,1000000);

    cout << "Stos jako tablica:" << endl;
    checkTimeArray(ExampleStack,10);
    checkTimeArray(ExampleStack,100);
    checkTimeArray(ExampleStack,1000);
    checkTimeArray(ExampleStack,10000);
    checkTimeArray(ExampleStack,100000);

    return 0;
}
