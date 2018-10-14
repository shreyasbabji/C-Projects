#include <iostream>
#include "Element.h"

using namespace std;
 long Element::storeCopyCount;
long Element::storeDestCount;

/***** Complete this class. *****/



Element::Element() : value(0)
{

}


Element::Element(long val) : value(val)
{

}


Element::Element(const Element& other)
{
    /***** Complete this class. *****/
    value = other.value;
    storeCopyCount++;
}


Element::~Element()
{
    /***** Complete this class. *****/
    storeDestCount++;
}


long Element::get_value() const
{
	return value;
}

long Element::get_copy_count()
{
	return storeCopyCount;
}

long Element::get_destructor_count()
{
	return storeDestCount;
}

bool operator ==( Element& obj1, Element& obj2)
{
	if(obj1.value == obj2.value)
	{
		return true;
	}
	else return false;

}

bool operator > (const Element& obj1, const Element& obj2)
{
	if(obj1.value > obj2.value)
		{
			return true;
		}
		else return false;

}

bool operator < (const Element& obj1, const Element& obj2)
{
	if(obj1.value < obj2.value)
		{
			return true;
		}
		else return false;
}

ostream& operator <<(ostream& outs, const Element& object)
{
   outs << object.get_value();
   return outs;
}

void Element::reset()
{
    storeDestCount=0;
    storeCopyCount=0;
}
