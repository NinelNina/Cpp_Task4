#include "pch.h"
#include "SubjectComparator.h"

bool SubjectComparator::operator()(const Subject* lhs, const Subject* rhs) const
{
    return lhs->GetName() < rhs->GetName();
}