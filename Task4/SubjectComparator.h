#pragma once
#include "pch.h"

class SubjectComparator
{
public: 
	bool operator()(const Subject* lhs, const Subject* rhs) const;
};

