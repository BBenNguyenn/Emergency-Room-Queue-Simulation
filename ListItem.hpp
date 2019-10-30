// CLASS: ListItem
// REMARKS: What is the purpose of this class?
//	The abstract object which is what our Queues contain,
//  inherited by Event and Patient classes.
//-----------------------------------------
#ifndef LISTITEM_H
#define LISTITEM_H

using namespace std;

class ListItem
{
protected:
	int priority;

public:
	//ListItem is an abstract class!
	ListItem(int p); //default constructor
	ListItem();		 // empty constructor
	//and everybody below better have a print...
	virtual void print() = 0;
	virtual ~ListItem(); //avoids warning that we have no virtual destructor
	virtual int getPriority();
};
#endif
