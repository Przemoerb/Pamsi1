#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "stos.cpp"

TEST_CASE("Dodawanie i usuwanie elementu z tablicy"){
    Stack ExampleStack;
    ExampleStack.pushElementToArray(6);
    CHECK(ExampleStack.popElementFromArray()==6);
}
TEST_CASE("Dodawanie i usuwanie elementu z listy"){
    Stack ExampleStack;
    ExampleStack.pushElementToList(6);
    CHECK(ExampleStack.popElementFromList()==6);
}
TEST_CASE("Usuwanie listy"){
    Stack ExampleStack;
    ExampleStack.pushElementToList(0);
    for (int j = 0; j < 10; j++)
    {
        ExampleStack.pushElementToList(rand() % 100);
    }
    ExampleStack.clearList();
    CHECK(ExampleStack.popElementFromList()==0);
}
TEST_CASE("Usuwanie listy"){
    Stack ExampleStack;
    ExampleStack.pushElementToArray(0);
    for (int j = 0; j < 10; j++)
    {
        ExampleStack.pushElementToArray(rand() % 100);
    }
    ExampleStack.clearArray();
    CHECK(ExampleStack.popElementFromArray()==-1);
}
TEST_CASE("Test wypisywania wartosci przy pustej liscie")
{
    Stack ExampleStack;
    std::ostringstream stream;
    ExampleStack.printList();
    CHECK(stream.str() == "");
}
TEST_CASE("Test wypisywania wartosci przy pelnej liscie")
{
    Stack ExampleStack;
    ExampleStack.pushElementToList(1);
    ExampleStack.pushElementToList(2);
    ExampleStack.pushElementToList(3);

    ExampleStack.printList();
    std::cout<<endl;

    CHECK(ExampleStack.popElementFromList()==3);
}
TEST_CASE("Test wypisywania wartosci przy pustej tablicy")
{
    Stack ExampleStack;
    std::ostringstream stream;
    ExampleStack.printArray();
    CHECK(stream.str() == "");
}

TEST_CASE("Test wypisywania wartosci przy pelnej liscie")
{
    Stack ExampleStack;
    ExampleStack.pushElementToArray(1);
    ExampleStack.pushElementToArray(2);
    ExampleStack.pushElementToArray(3);

    ExampleStack.printArray();
    std::cout<<endl;

    CHECK(ExampleStack.popElementFromArray()==3);
}
TEST_CASE("Badanie czasu dla dodawania 100000 elementow na stos wykonany za pomoca tablicy")
{
    Stack ExampleStack;

    int start = clock();
    for (int j = 0; j < 1000000; j++)
    {
        ExampleStack.pushElementToArray(rand() % 100);
    }
    cout << "Czas pushowania dla 1000000 danych to (tablica): " << clock() - start << " milisekund" << endl;
    ExampleStack.clearArray();
}
TEST_CASE("Badanie czasu dla dodawania 100000 elementow na stos wykonany za pomoca tablicy")
{
    Stack ExampleStack;

    int start = clock();
    for (int j = 0; j < 1000000; j++)
    {
        ExampleStack.pushElementToList(rand() % 100);
    }
    cout << "Czas pushowania dla 1000000 danych to (lista): " << clock() - start << " milisekund" << endl;
    ExampleStack.clearList();
}
TEST_CASE("Badanie czasu dla popowania 100000 elementow na stos wykonany za pomoca tablicy")
{
    Stack ExampleStack;

    for (int j = 0; j < 1000000; j++)
    {
        ExampleStack.pushElementToArray(rand() % 100);
    }

    int start = clock();
    for (int j = 0; j < 1000000; j++)
    {
        ExampleStack.popElementFromArray();
    }
    cout << "Czas popowania dla 1000000 danych to (tablica): " << clock() - start << " milisekund" << endl;
    ExampleStack.clearArray();
}
TEST_CASE("Badanie czasu dla popowania 100000 elementow na stos wykonany za pomoca tablicy")
{
    Stack ExampleStack;

    for (int j = 0; j < 1000000; j++)
    {
        ExampleStack.pushElementToList(rand() % 100);
    }
    
    int start = clock();
    for (int j = 0; j < 1000000; j++)
    {
        ExampleStack.popElementFromList();
    }
    cout << "Czas popowania dla 1000000 danych to (lista): " << clock() - start << " milisekund" << endl;
    ExampleStack.clearArray();
}