/*
 * tests.cpp
 *
 *  Created on: 19-nov.-2013
 *      Author: Daan Seynaeve, Max Dekonick
 *
 * Deze file is bedoeld als een soort 'script' die de
 * testen (en later ook het algoritme) zal bevatten.
 * De parallelisering zal hier ook gebeuren.
 */

#include <iostream>
using namespace std;
#include "SmallBasicSet.h"
#include "AMFunction.h"
#include "parser.h"

/**
 * Testmodule om simpele tests uit te voeren op klassen,
 * later testen in afzonderlijke files steken.
 */
void test_smallbasicset() {
	cout << "# TESTS - SMALLBASICSET #" << endl;
	Parser p;
	SmallBasicSet s1 = p.parse("[1234]", 4);
	SmallBasicSet s2 = p.parse("[4657]", 3);
	cout << s1.toString() << endl;
	cout << s2.toString() << endl;
	SmallBasicSet s3 = s1.setunion(s2);
	cout << s3.toString() << endl;
	SmallBasicSet s4 = s1.setdifference(s2);
	cout << s4.toString() << endl;
	SmallBasicSet s5 = s1.setintersect(s2);
	cout << s5.toString() << endl;

	cout << s1.hasAsSubset(s5) << endl; // expected: 1
	cout << s1.hasAsSubset(s3) << endl; // expected: 0
}

void test_amfunction() {
	cout << "# TESTS - AMFUNCTION #" << endl;
	Parser p;
	SmallBasicSet s1 = p.parse("[1]", 1);
	SmallBasicSet s2 = p.parse("[23]", 2);

	AMFunction a1;
	a1.addSet(s1);
	a1.addSet(s2);

	for ( SmallBasicSet s : a1.getSets() ) {
		cout << s.toString() << endl;
	}

	cout << "antimonotonic:" << a1.isAntiMonotonic() << endl; // expected: 1
}

/**
 * Testmodule om een beetje in te experimenteren
 */
void test_general() {
	// do some stuff
}

int main() {
	// run the tests
	test_smallbasicset();
	test_amfunction();
	test_general();
	return 0;
}
