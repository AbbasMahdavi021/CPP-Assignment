                                                                                                                                  //
// Created by Abbas And Melisa
//

#include <memory>
#include <iostream>
using namespace std;
#include <string>
#include <cstdlib>
#include <ctime>
#include "SPLinkedBag.h"

template <typename ItemType>
bool SPLinkedBag<ItemType>::removeSecondNode340()
{
    shared_ptr<SPNode<ItemType>> head{ make_shared<SPNode<ItemType>>( headPtr->getItem(), headPtr->getNext()) };
    bool removed = false;
    if(itemCount < 2)
        return removed;
    else{
        shared_ptr<SPNode<ItemType>> currPtr{ make_shared<SPNode<ItemType>>( headPtr->getNext()->getItem(), headPtr->getNext()->getNext() )};
        cout << endl << "currPtr: " << currPtr->getItem() << endl;
        head->setNext({currPtr->getNext()});
        cout << "head: " << head->getItem() << endl;
        cout << "head->setNext(): " << head->getNext()->getItem() << endl;
        currPtr.reset();
        removed = true;
        itemCount--;
    }
    return removed;
}