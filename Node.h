#ifndef NODE_H_
#define NODE_H_

#include "Element.h"

/**
 * A node of the linked list for mergesort.
 */
class Node
{
public:
    /***** Complete this class. *****/

    Node();
    Node(Element obj);
    virtual ~Node();
    Element element;
    Node *next;

};

#endif /* NODE_H_ */
