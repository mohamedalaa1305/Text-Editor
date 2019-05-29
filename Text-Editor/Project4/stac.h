#pragma once
#include <ostream>
#include <string>
#include <string.h>
#include <stack>
#include <vector>
#include <deque>
#include <istream>
#include "node.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;
ref class stac
{
	node^ head;
	node^ tail;
	int size;
public:
	stac();
	void push(String^ val);
	void popp();
	bool len1();
	String^ top();
	void clear();
	bool empty();
};

