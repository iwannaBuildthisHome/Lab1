#include "INTEGERLIST.hpp"
#include <iostream>
//    IntegerList l;
//    IntegerListInit(l);
//
//    std::cout<<"inputs integeres stopo with Alt + Z";
//    IntegerListReadTillZero(l, std::cin);
//
//    std::cout<<"input position to stay: ";
//    int beginIndex;
//
//    std::cin>>beginIndex;
//    if(beginIndex < 0 || IntegerListIsEmpty(l) )
//    {
//        reportPositionError();
//    }
//    std::cout<<"input how many elements you want to delete: ";
//    int countToDelete;
//    std::cin>>countToDelete;

//    IntegerList::Node * pBeginNode = nullptr;
//    IntegerList::Node * pEndDelete = nullptr;
//    do
//    {
//    IntegerList::Node * pNextDelete = pBeginNode->m_pNext;
//    pBeginNode = pNextDelete;
//    IntegerListDeleteNode(l, pBeginNode);
//    }while(pBeginNode!= pEndDelete);


//    IntegerList::Node * nodeBeg =  indexToStay;
//    IntegerList::Node * nodeEnd = countToDelete;
//
//    IntegerList::Node * iToBeg = nodeBeg;
//    IntegerList::Node * cToDel = nodeEnd;

//    if(countToDelete < 0 || IntegerListIsEmpty(l))
//    {
//        reportPositionError();
//        IntegerListDeleteNode(l, <#IntegerList::Node *_pNode#>)
//    }
void testFindByIndex();
// Функция сообщения о некорректной позиции
void reportPositionError ()
{
    std::cout << "Error: invalid position specified." << std::endl;
}

// Функция распечатки результата программы
void printResult ( const IntegerList & _l )
{
    std::cout << "Result: ";
    IntegerListPrint( _l, std::cout );
    std::cout << std::endl;
}
IntegerList::Node * findNodeByValue(IntegerList & _l, int value)
{
    IntegerList::Node * pBeginNode = _l.m_pFirst;
    while(pBeginNode)
    {
        if(pBeginNode->m_value == value)
            return pBeginNode;
        pBeginNode = pBeginNode->m_pNext;
    }
    return nullptr;
}
IntegerList::Node * findNodeByIndex(IntegerList & _l, const int index)
{
    IntegerList::Node * pBeginNode = _l.m_pFirst;
    int i =0;
    while (pBeginNode!=NULL)
    {
        if(i == index )
        {
            return pBeginNode;
        }
        else
            pBeginNode= pBeginNode ->m_pNext;
        i++;
    }
    return nullptr;
}

int main()
{
   
    IntegerList l;
    IntegerListInit(l);
    //findNodeByIndex(l, 4)
    std::cout<<"inputs integeres stop with Alt + Z, enter";
    IntegerListReadTillZero(l, std::cin);
    std::cout<<"input position to stay: ";
    int beginIndex;
    std::cin>>beginIndex;
    if(beginIndex < 0 || IntegerListIsEmpty(l) )
    {
        reportPositionError();
    }
    else if (beginIndex!=0);
    {
        findNodeByIndex(l,beginIndex);
    }
    std::cout<<"input how many elements you want to delete: ";
    int countToDelete;
    std::cin>>countToDelete;
    int pEndIndex = beginIndex + countToDelete;
    IntegerList::Node * pBeginDelete = findNodeByIndex(l, beginIndex);

    IntegerList::Node * pEndDelete = findNodeByIndex(l, pEndIndex);
    do
    {
        IntegerList::Node * pNextDelete = pBeginDelete->m_pNext;
        IntegerListDeleteNode(l, pBeginDelete);
        pBeginDelete = pNextDelete;
    }while(pBeginDelete!= pEndDelete);

   
    std::cout<<"Result: ";
    IntegerListPrint( l, std::cout);
    std::cout<<std::endl;
    
 
    testFindByIndex();
}

void testFindByIndex() {
    IntegerList list;
    IntegerListInit(list);
    
    const int size = 6;
    int numbers [size] = {4, 5, 6, 7, 8, 9};
    for (int i = 0; i< size; i++) {
        IntegerListPushBack(list, numbers[i]);
    }
    
    int findIndex = 4;
    int findValue = 8;
    int nextFindValue = 9;
    
    IntegerList::Node * pFindNode = findNodeByIndex(list, findIndex);
    
    assert(pFindNode->m_value == findValue);
    assert(pFindNode->m_pNext->m_value == nextFindValue);
    assert(pFindNode->m_pNext->m_pNext == nullptr);
}
