#pragma once
#include <string.h>
#include <stack>
#include <vector>
#include <deque>
#include <istream>
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;
ref class node
{
public:
	String^ run;
	node^ pop;
	node(String^ val);
};

