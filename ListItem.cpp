// CLASS: ListItem
// REMARKS: What is the purpose of this class?
//	The abstract object which is what our Queues contain,
//  inherited by Event and Patient classes.
//-----------------------------------------
#include "ListItem.hpp"

ListItem::ListItem(int p) : priority(p) {}
ListItem::ListItem() : priority(-1) {}
ListItem::~ListItem() {}
void print() {}

int ListItem::getPriority() { return priority; }
