/*
 * SmallBasicSet.cpp
 *
 *  Created on: 20-nov.-2013
 *      Author: Daan Seynaeve, Max Dekonick
 */
#include "SmallBasicSet.h"

string int_to_string(int a); // forward declaration

SmallBasicSet::SmallBasicSet() : numberofelem(0) {
	for (int i = 1 ; i < MAXELEMENT ; i++ ) {
		elements[i] = false;
	}
}

SmallBasicSet::SmallBasicSet(int a[], int asize) : numberofelem(asize) {
	for (int i = 1 ; i < MAXELEMENT ; i++ ) {
		elements[i] = false;
	}
	for (int i = 0 ; i < asize ; i++ ) {
		elements[a[i]] = true;
	}
}

SmallBasicSet::~SmallBasicSet() {
	// destructor
}

int SmallBasicSet::maxelement() {
	return MAXELEMENT;
}

string SmallBasicSet::toString() {
	stringstream ss;
	ss << "[";
	for (int i = 1 ; i < MAXELEMENT ; i++ ) {
		if (elements[i] ==  true) {
			ss << int_to_string(i);
		}
	}
	ss << "]";
	return ss.str();
}

SmallBasicSet SmallBasicSet::setunion(SmallBasicSet other) const {
	SmallBasicSet unie;
	for (int i = 0 ; i < MAXELEMENT ; i++ ) {
		unie.elements[i] = elements[i] || other.elements[i];
	}
	return unie;
}

SmallBasicSet SmallBasicSet::setdifference(SmallBasicSet other) const {
	SmallBasicSet difference;
	for (int i = 0 ; i < MAXELEMENT ; i++ ) {
		difference.elements[i] = elements[i] && !other.elements[i];
	}
	return difference;
}

SmallBasicSet SmallBasicSet::setintersect(SmallBasicSet other) const {
	SmallBasicSet intersect;
	for (int i = 0 ; i < MAXELEMENT ; i++ ) {
		intersect.elements[i] = elements[i] && other.elements[i];
	}
	return intersect;
}

bool SmallBasicSet::equals(SmallBasicSet other) const {
	bool equal = true;
	for (int i = 0 ; i < MAXELEMENT ; i++ ) {
		equal &= elements[i] == other.elements[i];
	}
	return equal;
}

bool SmallBasicSet::hasAsSubset(SmallBasicSet other) const {
	return equals(setunion(other));
}

bool SmallBasicSet::operator<(const SmallBasicSet& other) const {
   return id < other.id;
}

bool SmallBasicSet::operator==(const SmallBasicSet& other) const {
	return id == other.id;
}

string int_to_string(int a) {
	stringstream ss;
	ss << a;
	string str = ss.str();
	return str;
}
