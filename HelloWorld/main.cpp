//
//  main.cpp
//  HelloWorld
//
//  Created by Mikael Hermansson on 2014-01-01.
//  Copyright (c) 2014 Mikael Hermansson. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <map>
#include "Shared.h"
#include "Calculate.h"
#include "FirstClass.h"

using namespace std;

// Method definitions
int add(int x, int y);


struct Coodinate{
    int xCoord;
    int yCoord;
    string name;
};

void pr(string printString){
    cout << printString << '\n';
}

void pr(char printSChar){
    cout << printSChar << '\n';
}

void pr(int printItem){
    cout << printItem << '\n';
}

void pr(long printItem){
    cout << printItem << '\n';
}

void printMenuItem(int itemNr, string menuItem){
    cout << itemNr << ". " << menuItem << endl;
}

void printMenu() {
    cout << "Please chose a menu item:\n";
    printMenuItem(1, "Val 1");
    printMenuItem(2, "Val 2");
    printMenuItem(3, "Val 3");
    printMenuItem(4, "Val 4");
    printMenuItem(5, "Val 5");
    printMenuItem(6, "Val 6");
}

char takeMenuInput() {
    string menuChoice = "0";
    cout << (menuChoice < "1");
    while (menuChoice < "1" || menuChoice > "6") {
        printMenu();
        getline(cin, menuChoice, '\n');
    }
    
    return menuChoice[0];
}


/********************* pointers ************************/
void pointerTesting(){
    int x = 1;
    int x2 = 10;
    int *p_x = & x; // vid initiering fungerar det att tilldela adressen för x då vi använder * i pointer
    // cout << "*p_x=" << *p_x << '\n';
    *p_x = 55; // after initiation we can set the value of x
    
    p_x = & x2; // Då vi vill att p_x skall peka på en annan variabel ancänder vi inte *, endast vi initiering av pointer
    
    cout << "x=" << x << endl;
    cout << "p_x=" << p_x << endl;
    cout << "*p_x=" << *p_x << endl;
    cout << "& x=" << & x << endl;
    
    
    int y;
    int *p_pointer_to_integer = & y;
    *p_pointer_to_integer = 5;  //y is now 5!
    cout << "y=" << y << endl;
    cout << "*p_pointer_to_integer=" << *p_pointer_to_integer << endl;
    
    int *p_z = NULL;
    p_z = NULL;
    int z = 5;
    p_z = & z;
    cout << "*p_z=" << *p_z << endl;
    cout << "p_z=" << p_z << endl;
    // Minnesadress till där själva pointern ligger i minnet.
    // Sedan innehåller pointern adressen till själva integern. Lurigt!!!
    cout << "& p_z=" << & p_z << endl;

}

void functionThatTakesPointers(int *x, int *y) {
    // Byt värde på x och y
    int mem = *x;
    *x = *y;
    *y = mem;
}

void functionThatTakeReferences(int& x, int& y) {
    // Byt värde på x och y
    int mem = x;
    x = y;
    y = mem;
}


/**************** random Numbers ******************/

long getRandomNumber(int range){
    map<int,int> statsMap;
    // initialize map
    for (int i = 0; i < range; i++) {
        statsMap[i] = 0;
    }
    // add random number to map and count up hits
    for (int i=0; i < 10000; i++){
        int randomTal = arc4random_uniform(range);
        // cout << randomTal << endl;
        statsMap[randomTal] = statsMap[randomTal] + 1;
    }
    
    for (auto it = statsMap.begin(); it!=statsMap.end(); it++) {
        cout << it->first << "=>" << it->second << '\n';
    }
    
    /*
     long theTime = time(NULL);
     srand(theTime);*/
    return 0;
}

/******************** Use referenxe to return many values of function ***********************/

// Multiply and add to ints and return answers via references
void multiplyAndAdd(int x, int y, int& product, int& sum) {
    product = x*y;
    sum = x + y;
}

/************************** Allocate memory on heap *************************/

// allocate memory on heap (free memory)
void allocateAndDestroy() {
    int *p_int = new int;
    *p_int = 2;
    cout << *p_int << '\n';
    delete p_int;
    p_int = NULL; // hindrar anrop till *p_int som annars möjligen kan fungera

}


/**************************** Linked lists ******************************/
// Example of linked lists
struct EnemySpaceShip
{
    int x_coordinate;
    int y_coordinate;
    int weapon_power;
    EnemySpaceShip* p_next_enemy;
};


// Add new node last and return last (new node)
EnemySpaceShip* addNodeAfterNode(EnemySpaceShip *lastShip, EnemySpaceShip *nodeToAdd){
    lastShip->p_next_enemy = nodeToAdd;
    return nodeToAdd;
}

// Add new node first and return new node
EnemySpaceShip* addNewNodeFirst(EnemySpaceShip *oldNode, EnemySpaceShip *nodeToAdd){
    nodeToAdd->p_next_enemy = oldNode;
    return nodeToAdd;
}


void printLinkedList(EnemySpaceShip *shipToPrint) {
    
    do {
        cout << "x-coord=" << shipToPrint->x_coordinate << '\n';
        cout << "y-coord=" << shipToPrint->y_coordinate << '\n';
        cout << "weaponp=" << shipToPrint->weapon_power << '\n';
        cout << "next ship " << (shipToPrint->p_next_enemy != NULL?"EXIST":"NOT EXIST") << '\n';
        
        shipToPrint = shipToPrint->p_next_enemy;
        
    } while (shipToPrint != NULL);
}

EnemySpaceShip* getNewShip(int x, int y, int weaponp) {
    EnemySpaceShip *newShip = new EnemySpaceShip;
    newShip->x_coordinate=x;
    newShip->y_coordinate=y;
    newShip->weapon_power=weaponp;
    newShip->p_next_enemy=NULL;
    return newShip;
}

void linkedList() {
    EnemySpaceShip* firstShip =  getNewShip(1, 1, 10);
    EnemySpaceShip* lastShip = firstShip;
    lastShip = addNodeAfterNode(lastShip, getNewShip(2, 2, 20));
    lastShip = addNodeAfterNode(lastShip, getNewShip(3, 3, 30));
    lastShip = addNodeAfterNode(lastShip, getNewShip(4, 4, 40));
    
    printLinkedList(firstShip);

}

void upgradeWeapons(EnemySpaceShip* ship) {
    ship->weapon_power+=10;
}

/************* Recursive programming ***************/
// Recursive function that prints out 12345678987654321 if 1 is the argument
void printNum (int num)
{
    // the two calls in this function to cout will sandwich an inner
    // sequence containing the numbers (num+1)...99...(num+1)
    cout << num;
    // While begin is less than 9, we need to recursively print
    // the sequence for (num+1) ... 99 ... (num+1)
    if ( num < 9 ) {
        printNum( num + 1 );
    }
    cout << num;
}

// Linked list recursive search
struct node {
    int x;
    string name;
    node *nextNode;
};

node* createNewNodes(int number, node *p_Node){
    
    if(p_Node==NULL) {
        p_Node = new node;
        p_Node->nextNode=NULL;
        p_Node->x=number;
        ostringstream oss;
        oss << "NodeNr" << number;
        p_Node->name = oss.str();
        return createNewNodes(number + 1, p_Node);
    }
    if(p_Node->x == 9){
        return p_Node;
    }
    
    node* newNode = new node;
    newNode->x = number;
    string name = "NodeNr" + to_string( number );

    /* alternativt sätt att slå ihop string med int
    ostringstream oss;
    oss << "NodeNr" << number;
    */
    
    newNode->name = name; // oss.str();
    newNode->nextNode=p_Node;
    
    return createNewNodes(number + 1, newNode);
}

node* searchFor(node* p_node, int x) {
    if (p_node->x == x) {
        cout << "Node match found with name=" << p_node->name << '\n';
        cout << "searched for x=" << x << '\n';
        return p_node;
    } else if (p_node->nextNode == NULL) {
        return NULL;
    } else {
        return searchFor((*p_node).nextNode, x);
    }
}

// Prints out what node (name) point to what node
void visualizeNodes(node* inNode) {
    if (inNode != NULL) {
        cout << inNode->name << " -> ";
        visualizeNodes(inNode->nextNode);
    } else {
        cout << "NULL" << '\n';
    }
}

// Stack overflow test
void recurse (int count) // Each call gets its own count
{
    cout << count << "\n";
    // It is not necessary to increment count since each function's
    // variables are separate (so the count in each stack frame will
    // be initialized one greater than the last count)
    recurse( count + 1 );
}

/************** MAIN METHOD *****************/

int main(int argc, const char * argv[]) {

    pointerTesting();
    
    MyFirstClass fc;
    fc.sayHello();

    // Constructor with an argument syntax
    MyFirstClass fc2("constructor argument");
    fc2.sayHello();

    // Constructor with two arguments
    MyFirstClass fc3("constructor", "argument");
    fc3.sayHello();

    /*
    cout << "1 + 2 = " << addInt(1,2) <<'\n';

    cout << "1 / 2 = " << divideInt(1, 2) <<'\n';

    nonExistingMethod();
    
    
    // Create error when stack gets out of mem through to many recurive calls
    recurse(1);
    
    // Create a linked list of 10 and then search recursive for int
    node* nodeList = createNewNodes(0, NULL);
    cout << "last node x value=" << nodeList->x << '\n';
    searchFor(nodeList, 5);
    visualizeNodes(nodeList);
    
    // Recursive emapmles
    printNum(1);cout << '\n';
    
    
    // Linked list and structures exmaple
    linkedList();
    
    // Allocate memoru and delete (return) memory
    allocateAndDestroy();
    
    
    // Call function with answer as reference
    int product = 0;
    int sum = 0;
    int x1 = 5, y1=6;
    multiplyAndAdd(x1, y1, product, sum);
    cout << x1 << "*" << y1 << "=" << product << ", " << x1 << "+" << y1 << "=" << sum << '\n';
    
    // Swap value of argument variables
    int x = 1;
    int y = 2;
    functionThatTakesPointers(& x,& y);
    cout << "x=" << x << ", y=" << y << '\n';
    
    // Swap value of argument variables
    functionThatTakeReferences(x,y);
    cout << "x=" << x << ", y=" << y << '\n';
    
    // Test av pointer hur man skapar och använder
    pointerTesting();
    
    
    // Test av Stuctures
    Coodinate myCoordTest;
    myCoordTest.xCoord = 10;
    myCoordTest.yCoord = 20;
    myCoordTest.name = "My name";
    
    Coodinate myCoords[2];
    myCoords[0].xCoord = 10;
    myCoords[0].yCoord = 20;
    myCoords[0].name = "Stjärna 1";
    
    getRandomNumber(2);
    
     long theTime = time(NULL);
     pr(theTime);
     */
    
    
    /*
     char menuItemChosen = takeMenuInput();
     switch (menuItemChosen) {
     case '1':
     cout << "Numbero uno\n";
     break;
     case '2':
     cout << "Nummer två\n";
     break;
     case '3':
     cout << "Nummer tre\n";
     break;
     case '4':
     case '5':
     case '6':
     cout << "4, 5 eller 6\n";
     
     default:
     break;
     }
     
     cout << add(1,2) << endl;
     cout << "Write number1: ";
     double numberOne;
     cin >> numberOne;
     cout << "Write number2: ";
     double numberTwo;
     cin >> numberTwo;
     cout << numberOne << "/" << numberTwo << "=" << numberOne/numberTwo << endl;
     
     cout << "Input password:\n";
     string inputString = "";
     while (true) {
     // getline(cin, inputString, '\n');
     cin >> inputString;
     if (inputString == "pass") {
     cout << "correct password\n";
     return 0;
     } else {
     cout << "wrong password\n";
     }
     }
     */
    return 0;
}

int add(int x, int y){
    return x + y;
}

