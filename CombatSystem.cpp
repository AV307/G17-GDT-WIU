#include "CombatSystem.h"
#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

CombatSystem::CombatSystem() {

}

CombatSystem::~CombatSystem() {

}

// +----------------------------------------------------------------------------------+ //
// Function Name: printCombatScreen
// Description: Used to print the combat screen when player enters combat with an enemy
// Parameter(s): None
// Return(s): None
// +----------------------------------------------------------------------------------+ //

void CombatSystem::printCombatScreen() {
	string csBorderT1 = "// +----------------------------------------------+ //";
	string csBorderT2 = "// +---------------------+  +---------------------+ //";

	cout << csBorderT1 << endl;
	cout << csBorderT2 << endl;
	cout << "// +      Fight 'F'      +  +      Item 'I'       + //" << endl;
	cout << csBorderT2 << endl;
	cout << csBorderT1 << endl;
	cout << "// +                   Run 'R'                    + //" << endl;
	cout << csBorderT1 << endl;
	cout << csBorderT1 << endl;

	// Hard-Code Combat Screen Design
	// cout << "// +----------------------------------------------+ //" << endl;
	// cout << "// +---------------------+  +---------------------+ //" << endl;
	// cout << "// +      Fight 'F'      +  +      Item 'I'       + //" << endl;
	// cout << "// +---------------------+  +---------------------+ //" << endl;
	// cout << "// +----------------------------------------------+ //" << endl;
	// cout << "// +                   Run 'R'                    + //" << endl;
	// cout << "// +----------------------------------------------+ //" << endl;
	// cout << "// +----------------------------------------------+ //" << endl;
}

void CombatSystem::fightPVE() {

}