// File:        main.cpp
// Author:      Geoff T
// Date:        2017-09-18
// Description: Test driver for CPSC 221 PA1
//              Only basic cases are included. You are responsible
//              for adding your own code to thoroughly test all functions of the
//              classes implemented in this assignment.

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

#include "kebab.h"
#include "linkedlist.h"
#include "grill.h"

using namespace std;

// forward function declarations
void runScriptedTests();
void runInteractiveTest();
void displayMenu();
void handleQueryShowGrill(Grill& grill);
void handleQueryBuyX(Grill& grill);
void handleQueryBuyList(Grill& grill);
void handleQueryNewKebab(Grill& grill);
void handleQuerySwap(Grill& grill);
void handleQuerySort(Grill& grill);

int main()
{
//runScriptedTests();
runInteractiveTest();
        cout << "k1 :" << endl;
  return 0;
}

void runScriptedTests()
{
  /*
  Kebab k;
  k.buildKebab("btmpsbt");
    Kebab* k2 = new Kebab();
     k2->buildKebab("tmPssB");

    Kebab* k3 = new Kebab();
      k3->buildKebab("btmp");
      Kebab* k4 = new Kebab();
       k4->buildKebab("spmtbbbb");
           Kebab* k5 = new Kebab();
       k5->buildKebab("sp");
             Kebab* k6 = new Kebab();
      k6-> buildKebab("B 3%#SN,M[PM TBSB54M,ZDROB8RTZ3 564 /][98Z3");

  LinkedList *l2 = new LinkedList();
  l2->insertFront(k2);
    l2->insertFront(k3);
    l2->insertAt(k4,1);
  cout << "at 1 :" << l2->elementAt(0)->listIngredients()<< endl;
  cout << "at 1 :" << l2->elementAt(1)->listIngredients()<< endl;
    cout << "at 1 :" << l2->elementAt(2)->listIngredients()<< endl;
  LinkedList* l1=new LinkedList(*l2);
        l1->insertAt(k5,3);
      cout << "at 1 :" << l1->elementAt(0)->listIngredients()<< endl;
    cout << "at 1 :" << l1->elementAt(1)->listIngredients()<< endl;
       cout << "at 1 :" << l1->elementAt(2)->listIngredients()<< endl;

    cout << "at 1 :" << l1->elementAt(3)->listIngredients()<< endl;
    cout << "at 1 :" << l1->removeAt(3)->listIngredients()<< endl;
cout << "l222222 k4 :" << l2->elementAt(1)->listIngredients()<< endl;
cout << "l222222 k2 :" << l2->elementAt(2)->listIngredients()<< endl;
    LinkedList* l3=new LinkedList(*l1);
      cout << "at 2 :" << l3->removeAt(2)->listIngredients()<< endl;
                  cout << "at 1 :" << l3->size()<< endl;
 cout << "at 1 :" << l3->elementAt(1)->listIngredients()<< endl;
   l3->insertAt(k5,2);
    cout << "at k5 :" << l3->elementAt(2)->listIngredients()<< endl;
          cout << "at 2 :" << l3->removeAt(2)->listIngredients()<< endl;
            cout << "at k4 :" << l3->elementAt(1)->listIngredients()<< endl;
LinkedList* l4=new LinkedList();
l4->insertFront(k2);
*l4=*l2;
 cout << "size of :" << l4->size()<< endl;
  cout << "k3 :" << l4->elementAt(0)->listIngredients()<< endl;
  cout << "k4 :" << l4->elementAt(1)->listIngredients()<< endl;
    cout << "k2 :" << l4->elementAt(2)->listIngredients()<< endl;
     cout << "k2 :" << l4->removeAt(2)->listIngredients()<< endl; 
     cout << "k2 :" << l2->elementAt(2)->listIngredients()<< endl;
      cout << "size of l4 :" << l4->size()<< endl;
      cout << "size of l2 :" << l2->size()<< endl;
      l4->insertFront(k6);
           Kebab* k2 = new Kebab();
     k2->buildKebab("tMPsspB");

    Kebab* k3 = new Kebab();
      k3->buildKebab("baaaA[aa");
      cout << "k6 :" << k2->listIngredients()<< endl;
 
  */


  Kebab* freshkebab;
//          cout << "reach 00 " << endl;
  freshkebab = new Kebab();
     Kebab* k = new Kebab();
    Kebab* k1 = new Kebab();
      k1->buildKebab("B[tMbbT]BS");
//          cout << "reach 000 " << endl;
  freshkebab->buildKebab("TMTBPP");
     k->buildKebab("BTMTBPP");
  LinkedList *l2 = new LinkedList();
  l2->insertFront(k);
    l2->insertBack(k1);
    cout << "at 0 k: " << l2->elementAt(0)->listIngredients()<<endl;
        cout << "at 0 k: " << l2->elementAt(0)->numMeats()<<endl;
    cout << "at 1  : " << l2->elementAt(1)->listIngredients()<<endl;
      cout << "at 11   " << l2->elementAt(1)->numMeats()<<endl;



  
}

void runInteractiveTest()
{
  // create a Grill and populate it with some Kebabs
  Grill g;
  Kebab* freshkebab;
  freshkebab = new Kebab();
  freshkebab->buildKebab("TMTBPP");
  g.addKebab(*freshkebab);
  freshkebab = new Kebab();
  freshkebab->buildKebab("B 3%#SN,M[PM TBSB54M,ZDROB8RTZ3 564 /][98Z3");
  g.addKebab(*freshkebab);
  freshkebab = new Kebab();
  freshkebab->buildKebab("BMB");
  g.addKebab(*freshkebab);

  string inputchoice = "";
  int choice = 0;

  while (choice != 8)
  {
    displayMenu();
    // get the menu choice from standard input
    getline(cin, inputchoice);
    choice = atoi(inputchoice.c_str());

    switch (choice)
    {
    case 1: // See the kebabs
      handleQueryShowGrill(g);
      break;
    case 2: // Buy a kebab by pointing
      handleQueryBuyX(g);
      break;
    case 3: // Buy a kebab by listing ingredients
      handleQueryBuyList(g);
      break;
    case 4: // Make a new kebab
      handleQueryNewKebab(g);
      break;
    case 5: // Swap two kebabs on the grill
      handleQuerySwap(g);
      break;
    case 6: // Descending sort the kebabs by meat amount
      handleQuerySort(g);
      break;
    case 8: // End
      cout << "Thank you, come again!" << endl;
      break;
    default: // invalid option
      cout << "Invalid choice." << endl;
      break;
    }
  }
}

// prints the options menu to screen
void displayMenu()
{
  cout << "*****************************************\n"
       << "* Welcome to Speedy Kebab terminal      *\n"
       << "* What would you like to do?            *\n"
       << "*                                       *\n"
       << "* Customer operations:                  *\n"
       << "* 1. See the kebabs on the grill        *\n"
       << "* 2. Buy a kebab by number              *\n"
       << "* 3. Buy a kebab by listing ingredients *\n"
       << "*                                       *\n"
       << "* Staff operations:                     *\n"
       << "* 4. Make a new kebab                   *\n"
       << "* 5. Swap two kebabs                    *\n"
       << "* 6. Sort by meat amounts               *\n"
       << "*                                       *\n"
       << "* 8. End                                *\n"
       << "*****************************************" << endl;
  cout << "Please enter your choice: ";
}

void handleQueryShowGrill(Grill& grill)
{
  vector<string> kebabs = grill.showKebabs();
  int numkebabs = kebabs.size();
  // pad all kebab strings with " " to make them SKEWER_SIZE
  for (int i = 0; i < numkebabs; i++)
  {
    if (kebabs[i].length() < SKEWER_SIZE)
    {
      while (kebabs[i].length() < SKEWER_SIZE)
        kebabs[i] = kebabs[i] + " ";
    }
    cout << i + 1 << "\t";
  }
  cout << endl;
  for (int i = 0; i < numkebabs; i++)
    cout << "~~~\t";
  cout << endl;
  for (int chars = 0; chars < SKEWER_SIZE; chars++)
  {
    for (int k = 0; k < numkebabs; k++)
    {
      cout << kebabs[k][chars] << "\t";
    }
    cout << endl;
  }
}

void handleQueryBuyX(Grill& grill)
{
  string inputchoice = "";
  int choice = 0;
  cout << "Enter the number of the kebab: ";
  getline(cin, inputchoice);
  choice = atoi(inputchoice.c_str());
  Kebab* purchased = grill.request((unsigned int)choice);
  if (purchased != NULL)
    cout << "Thank you, enjoy!\n" << endl;
  else
    cout << "Sorry, I cannot help you with that.\n" << endl;
  delete purchased;
}

void handleQueryBuyList(Grill& grill)
{
  string wanted;
  cout << "Enter the first character of each ingredient you want: ";
  getline(cin, wanted);
  Kebab wantedkebab;
  wantedkebab.buildKebab(wanted);
  Kebab* purchased = grill.request(wantedkebab);
  if (purchased != NULL)
    cout << "Thank you, enjoy!\n" << endl;
  else
    cout << "Sorry, I cannot help you with that.\n" << endl;
  delete purchased;
}

void handleQueryNewKebab(Grill& grill)
{
  string ilist;
  cout << "Enter the first character of each ingredient to use: ";
  getline(cin, ilist);
  Kebab* freshkebab = new Kebab();
  freshkebab->buildKebab(ilist);
  grill.addKebab(*freshkebab);
  cout << "A fresh kebab is on the grill!\n" << endl;
}

void handleQuerySwap(Grill& grill)
{
  string inputchoice = "";
  int k1 = 0;
  cout << "Enter the number of the first kebab: ";
  getline(cin, inputchoice);
  k1 = atoi(inputchoice.c_str());
  int k2 = 0;
  cout << "Enter the number of the second kebab: ";
  getline(cin, inputchoice);
  k2 = atoi(inputchoice.c_str());
  if (grill.swap((unsigned int)k1, (unsigned int)k2))
    cout << "Kebabs swapped.\n" << endl;
  else
    cout << "Sorry, you cannot do that.\n" << endl;
}

void handleQuerySort(Grill& grill)
{
  grill.sortByMeat();
  cout << "More meat on the left!\n" << endl;
}
