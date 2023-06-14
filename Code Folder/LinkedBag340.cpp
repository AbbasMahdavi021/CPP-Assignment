//	LinkedBag340.cpp
//	Created by: Abbas And Melisa
#include "LinkedBag.h"
#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>


//Deletes the second node in the Linked Bag
template<typename ItemType>
bool LinkedBag<ItemType>::removeSecondNode340()
{
    bool removed = false;
    if(itemCount < 2)
        return removed;
    else
    {
        //get to second node
        Node<ItemType>* currPtr = headPtr->getNext();
        headPtr->setNext(currPtr->getNext());
        currPtr->setNext(nullptr);
        delete currPtr;
        currPtr = nullptr;
        removed = true;
        itemCount--;
    }
    return removed;
}


//Inserts the new node at the end of the Linked Bag
template<typename ItemType>
bool LinkedBag<ItemType>::addEnd340(const ItemType& item)
{
    bool inserted = false;
    auto* newNode = new Node<ItemType>();
    newNode->setItem(item);
    newNode->setNext(nullptr);
    Node<ItemType>* currPtr = headPtr;
    while(currPtr->getNext() != nullptr)
    {
        currPtr = currPtr->getNext();
    }
    currPtr->setNext(newNode);
    itemCount++;
    inserted = true;

    currPtr = nullptr;
    return inserted;
}

//Counts the number of nodes in the Linked Bag iteratively
template<typename ItemType>
int LinkedBag<ItemType>:: getCurrentSize340Iterative() const
{
    int numItems = 0;
    int counter = 0;
    auto* currPtr = headPtr;
    while(currPtr != nullptr && counter < itemCount)
    {
        numItems++;
        currPtr = currPtr->getNext();
        counter++;
    }
    currPtr = nullptr;
    return numItems;
}

//Recursively counts how many items are in the LinkedBag. Helper function to getCurrentSize340Recursive()
template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveHelper(Node<ItemType>* currPtr) const {
    if (currPtr->getNext() == nullptr) {
        currPtr = nullptr;
        return 1;
    }
    else
        return 1 + getCurrentSize340RecursiveHelper(currPtr->getNext());
}

//counts the number of nodes in the Linked Bag recursively. Uses Helper Function getCurrentSize340RecursiveHelper()
template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Recursive() const
{
    return getCurrentSize340RecursiveHelper(headPtr);
}

//Counts the number of nodes in the Linked Bag recursively. This recursive function DOES NOT use any helper functions
template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveNoHelper() const {
     static auto* currPtr = headPtr;
     if(currPtr->getNext() == nullptr) {
         return 1;
     } else{
         currPtr = currPtr->getNext();
         return 1 + getCurrentSize340RecursiveNoHelper();
     }
}

//Recursively counts the number of times an entry appears in the Linked Bag. Helper function to getFrequencyOf340Recursive()
template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveHelper(Node<ItemType>* currPtr, const ItemType& item) const {
    if(currPtr->getNext() == nullptr) {
        if (typeid(currPtr->getItem()) == typeid(item)) {
            if (currPtr->getItem().compare(item) == 0) {
                currPtr = nullptr;
                return 1;
            } else {
                currPtr = nullptr;
                return 0;
            }
        }
    } else{
        if (typeid(currPtr->getItem()) == typeid(item)) {
            if (currPtr->getItem().compare(item) == 0)
            {
                return 1 + getFrequencyOf340RecursiveHelper(currPtr->getNext(), item);
            } else
                return getFrequencyOf340RecursiveHelper(currPtr->getNext(), item);
        }
    }
}

//Recursively counts the number of times an entry appears in the Linked Bag. Uses helper function getFrequencyOf340RecursiveHelper()
template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340Recursive(const ItemType & item) const {
    return getFrequencyOf340RecursiveHelper(headPtr, item);
}

//Recursively counts the number of times an entry appears in the Linked Bag. This recursive function DOES NOT use any helper functions
template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveNoHelper(const ItemType & item) const {
    static auto* currPtr = headPtr;
    if(currPtr->getNext() == nullptr)
    {
        if(typeid(currPtr->getItem()) == typeid(item)){
            if (currPtr->getItem().compare(item) == 0) {
                currPtr = headPtr;
                return 1;
            } else {
                currPtr = headPtr;
                return 0;
            }
        }
    } else{
        if(typeid(currPtr->getItem()) == typeid(item))
        {
            if (currPtr->getItem().compare(item) == 0) {
                currPtr = currPtr->getNext();
                return 1 + getFrequencyOf340RecursiveNoHelper(item);
            } else {
                currPtr = currPtr->getNext();
                return 0 + getFrequencyOf340RecursiveNoHelper(item);
            }
        }
    }
}

//Removes a random entry from the Linked Bag
template<typename ItemType>
ItemType LinkedBag<ItemType>::removeRandom340() {
    srand(time(nullptr));
    int rando = rand() % itemCount;
    auto* currPtr = headPtr;
    string item;
    if(rando == 0)
    {
        headPtr = headPtr->getNext();
        item = currPtr->getItem();
        currPtr->setNext(nullptr);
        delete currPtr;
        currPtr = nullptr;
        itemCount--;
        return item;
    }
    else {
        auto *prevPtr = headPtr;
        int counter = 0;
        while (currPtr != nullptr && counter < rando) {
            currPtr = currPtr->getNext();
            if (counter > 0)
                prevPtr = prevPtr->getNext();
            counter++;
        }
        if (currPtr != nullptr) {
            item = currPtr->getItem();
            if (currPtr->getNext() != nullptr) {
                prevPtr->setNext(currPtr->getNext());
                currPtr->setNext(nullptr);
            } else
            {
                prevPtr->setNext(nullptr);

            }
            delete currPtr;
        }
        else
            item = "NULL";

        currPtr = nullptr;
        prevPtr = nullptr;
        itemCount--;
        return item;
    }
}

//template<typename ItemType>
//void LinkedBag<ItemType>::printNodes() const
//{
//    auto* currPtr = headPtr;
//    //for(int i = 0; i < itemCount; i++)
//    while(currPtr != nullptr)
//    {
//        cout << "Node Item: " << currPtr->getItem() << " | ";
//        if(currPtr->getNext() != nullptr)
//            cout << "Next Node: " << currPtr->getNext()->getItem() << endl;
//        else
//            cout << "Next Node: nullptr" << endl;
//        currPtr = currPtr->getNext();
//    }
//    cout << currPtr << endl;
//}

