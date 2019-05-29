#include "stac.h"

stac::stac()
{
	head = tail = nullptr;
	size = 0;
}

bool stac::empty()
{
	return (size == 0);
}

bool stac::len1()
{
	return (size > 0);
}

void stac::push(String^ val)
{
	node^ tmp = gcnew node(val);
	if (size == 0) {
		head = tail = tmp;
	}
	else {
		tail->pop = tmp;
		tail = tail->pop;
	}
	size++;
}

void stac::popp()
{
	if (size == 0) {
		return;
	}
	if (size == 1)
	{
		head = tail = nullptr;
		size = 0;
		return;
	}
	node^ tmp = head;
	while (tmp->pop != tail) {
		tmp = tmp->pop;
	}
	tail = tmp;
	tmp = tmp->pop;
	delete tmp;
	size--;
}

String^ stac::top()
{
	if (size > 0) {
		return (tail->run);
	}
}

void stac::clear() {
	node^ tmp = head;
	while (size > 0) {
		popp();
	}
}
