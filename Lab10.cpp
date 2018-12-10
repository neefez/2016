//------------------------------------------------------------------------
// DO_1: fill in your name and section
//
// Name:    Zack Neefe,  Fall 2016
//
// Course:  CS 1430, Section 2
//
// Purpose: Write a program to manage a shopping cart, including A (Add),    
//          D (Delete), P (Print), and C (Checkout) items. The program    
//          processes commands until end-of-file.
//
// Input:   List of commands, some with arguments, terminated by 
//          end-of-file.
//
// Output:  A message is printed when an item was added to the cart, 
//          deleted from the cart, and sales amount, sales tax, total
//          amount was printed after checkout.  
//------------------------------------------------------------------------
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int MAX_ITEM = 6;
const float SALES_TAX = .055f;

class Cart
{
   // DO_2: write the keyword to determine the scope for data members.
   //       data members are only accessible within the class.	
private:
   string itemNames[MAX_ITEM];
   int    quantities[MAX_ITEM];
   float  unitPrice[MAX_ITEM];
   int    numItems;
   
   //---------------------------------------------------------------------
   // DO_3: This is a helper function that is only accessible within the 
   // class. This function finds a given item in the list; it returns the
   // the index if the item is found, otherwise returns -1;
   // Params: (in)
   //---------------------------------------------------------------------
   int Find(string item) const
   {
      int index = -1;
      for (int i = 0; i < numItems; i++)
	  { 
         if(itemNames[i] == item)
            index = i;
      }

	  return index;
   }
   
// Member functions declared after the public keyword are accessible
// outside of the class.
public:
   // DO_4: finish the default constructor that creates an empty cart.
   Cart()
   {
      numItems = 0;
   }
   
   //---------------------------------------------------------------------
   // Add an item to the shopping cart if the cart is not full, and the
   // item is not in the cart.
   // If the item exists already, add the new quantity to the original 
   // quantity.
   // Params: (none)
   //---------------------------------------------------------------------
   void Add()
   {
      string item;
      int quantity;
      float price;
      cin >> item >> quantity >> price;

      int index = Find(item);
      if (index >= 0)
      {
         // DO_5: if the given item exists in the cart, update the 
         //      quantity. 
         quantities[index] = quantities[index] + quantity;

         cout << itemNames[index] << " quantity updated to "
              << quantities[index] << endl;
      }
      else if (numItems >= MAX_ITEM)
      {
         cout << "Shopping cart is full! Item "
              << item << " was not added!" << endl;
      }
      else
      {
         // DO_6: add the item to the end of the list, and increase 
         //       the size by 1.
         itemNames[numItems] = item;
		 quantities[numItems] = quantity;
		 unitPrice[numItems] = price;
		 numItems++;

         cout << item << " was added to the cart!" << endl;
      }
   } // end of Add()
   
   //---------------------------------------------------------------------
   // Remove an item from the cart if the item is in the cart.
   // Params: (none)
   //---------------------------------------------------------------------
   void Delete()
   {
      string item;
      cin >> item;

      int index = Find(item);
      if (index < 0)
      {
         cout << item << " is not in the cart!" << endl;
      }
      else
      {
         // DO_7: delete the item by replacing the item by the last item
         //       in the list, and decrease the size by 1.
         numItems--;
         itemNames[index] = itemNames[numItems];
		 quantities[index] = quantities[numItems];
		 unitPrice[index] = unitPrice[numItems];

         cout << item << " was removed!" << endl;
      }
   } // end of Delete()

   //---------------------------------------------------------------------
   // Print out all items in the cart.
   // Params: (none)
   //---------------------------------------------------------------------
   void Print() const
   {
      if (numItems == 0)
      {
         cout << "Shopping cart is empty!" << endl;
      }
      else
      {
         cout << endl;
         cout << "Item Name        Quantity     Unit Price" << endl;
         cout << "----------------------------------------" << endl;
         for (int i = 0; i < numItems; i++)
            cout << setw(17) << itemNames[i]
                 << setw(13) << quantities[i]
                 << setw(10) << unitPrice[i] << endl;
      }
      cout << endl;
   }

   //---------------------------------------------------------------------
   // This function performs checkout of the shopping cart.
   // First, calculate the sales amount, sales tax and the toal 
   // transaction amount. Next, print all the amounts and empty the cart.  
   // Params: (none)
   //---------------------------------------------------------------------
   void Checkout()
   {
      if (numItems == 0)
      {
         cout << "Shopping cart is empty!" << endl;
         return;
      }

      // DO_8: Add up the sales amount of all items in the cart.
      //       sales amount = quantity * unitPrice;
      //       sales tax = sales amount * SALES_TAX;
      //       total amount = sales amount + sales tax;
	  float total = 0;
	  float tax = 0;
      for (int i = 0; i < numItems; i++)
         total = total + quantities[i] * unitPrice[i];
	  tax = total * SALES_TAX;

      cout << "Subtotal: " << total << ", Tax: " << tax
           << ", Total: $" << total + tax << endl;
      // DO_9: Empty the cart.	
	  numItems = 0;

   }
};

//---------------------------------------------------------------------
// main() creates an instance of shopping cart and handles the input
// commands. It calls the proper functions to manage the cart.
//---------------------------------------------------------------------
int main()
{
   Cart mycart;
   cout << left << fixed << showpoint << setprecision(2);

   char command;
   cin >> command;
   while (cin)
   {
      //DO_10: finish the switch case statement by making the proper
      //       function calls.	  
      switch (command)
      {
         case 'A': mycart.Add();
                   break;
		 case 'D': mycart.Delete();
                   break;
		 case 'P': mycart.Print();
                   break;
		 case 'C': mycart.Checkout();
                   break;

      }
      cin >> command;
   }

   true;

   return 0;
}

