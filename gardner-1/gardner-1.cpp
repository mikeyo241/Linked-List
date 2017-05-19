// Program Name:	Asgn 1 - Sorted List
// Chapter:			Chapter 3  - Linked Lists
// Pg. / Ex.:		63 / P3.3
// Programmer:		Michael A Gardner
// Date:			18 June 2016
// Description:		This program askes the user to enter a series of characters followed by 0.
//					The program then places the characters in a node in alphabetical order.
//					Then prints the list to the console and asks if the user wants to do another list.


//  ** Header Files  **
#include "stdafx.h"
#include <iostream>

using namespace std;



//  ** Node Structure **
typedef struct node {
	char letter;
	struct node *next;
}Node, *NodePtr;


// ** Function Prototypes **
NodePtr getcharacters();
NodePtr addNodeInOrder(NodePtr top, char l);
NodePtr createNode(char l);
void printList(NodePtr np);



int main() {
	//  ** Structures **
	NodePtr top;
	char contin = 'y';
	
	do {  
		// Get the characters from user and store them in the correct node.
		top = getcharacters();
		// Print the sorted list on screen.
		printList(top);
	
		cout << "\nWould you like to enter another list to sort? (y or n): ";
		cin >> contin;
	
	} while (contin == 'y' || contin == 'Y');  // Finds if the user wants to sort another list.



	cout << endl << endl;  //2 Blank Lines
	return 0;
}// End of Main Program



//  **  FUNCTIONS  **

NodePtr getcharacters() {

	// ** Varables **
	char l;
	NodePtr top = NULL;


	// ** Input from user **
	cout << "Pleas enter characters below: (enter 0 to exit)\n";
	cin >> l;

	while (l != '0') {
		top = addNodeInOrder(top, l);
		cin >> l;
	}
	return top;
} // End of getcharacters()





NodePtr addNodeInOrder(NodePtr top, char l) {

	// **  Structures  **
	NodePtr
		np,
		curr,
		prev;

	// Create a new node
	np = createNode(l);
	// Set Prevous node to NULL
	prev = NULL;
	// Set Current Node to top
	curr = top;

	// Place the New node in the correct location in alphabetical order
	while (curr != NULL && l > curr -> letter) {
		prev = curr;
		curr = curr->next;
	}
	
	if (prev == NULL) {
		np->next = top;
		return np;
	}
	np->next = curr;
	prev->next = np;
	return top;
} // END of addNodeInOrder()




// This function allocates memory to create a new node
NodePtr createNode(char l) {
	NodePtr np = (NodePtr)malloc(sizeof(Node));
	np->letter = l;
	np->next = NULL;
	return np;
} // END of createNode()





// This function prints out the data payload of each node saved.
void printList(NodePtr np) {

	//  **  Output  **
	cout << "The list entered in alphabetical order: \n";

	while (np != NULL) {
		cout << np->letter << endl; // Display the letters to the console
		np = np->next; // Next Node
	}

} // END of printList()



//  END OF PROGRAM
