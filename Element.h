#ifndef DATA_H_
#define DATA_H_

#include <iostream>
using namespace std;

/**
 * The class for the data elements that will be sorted.
 */
class Element
{
public:
    Element();
    Element(long val);
    Element(const Element& other);
    virtual ~Element();

    long get_value() const;

    /***** Complete this class. *****/

    static long get_copy_count();
    static long get_destructor_count();
    friend bool operator ==( Element& obj1, Element& obj2);
    friend bool operator > (const Element& obj1, const Element& obj2);
    friend bool operator < (const Element& obj1, const Element& obj2);
    friend ostream& operator <<(ostream& outs, const Element& object);
    static void reset();


private:
   static long storeCopyCount;
   static long storeDestCount;
   long value;
};

#endif /* DATA_H_ */
