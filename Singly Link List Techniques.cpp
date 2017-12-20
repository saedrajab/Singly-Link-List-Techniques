// Link List Techniques.cpp : Defines the entry point for the console application.
//Author: Saed El Dine Rajab
//ID#12140099

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;

struct Link_1
{
	int data;
	Link_1 *next;
};

struct Link_2
{
	int data;
	Link_2*next;
};

int link1count = 0;
int link2count = 0;

char menu();
void fillList1(Link_1*&head, Link_1*&last);
void printList(Link_1*&head);//recursion
void fillList2(Link_2*&head, Link_2*&last);
void printList(Link_2*&head);


void reverseLink1Recursion(Link_1 *&head);

void reverseLink2_Iterative_Method(Link_2*&head);

bool compareLists(Link_1*&head, Link_2*&head2);

void sortLink(Link_1*&head);
void sortLink(Link_2*&head);

void RemoveDuplicates(Link_1*&head);
void RemoveDuplicates(Link_2*&head);

void mergerLists(Link_1*&head, Link_2*&head2);

void mergerLists_AtCertain_commanPoint(Link_1*&head, Link_2*&head2);

int main()
{
	Link_1 *head = NULL;
	Link_1 *last = NULL;

	Link_2*head2 = NULL;
	Link_2*last2 = NULL;
	char choice;
	
	do {
		choice = menu();
		switch (choice)
		{
		case'a':
			fillList1(*&head, *&last); cout << endl << endl;
			break;
		case'b':
			fillList2(*&head2, *&last2); cout << endl << endl;
			break;
		case'c':
			if (head == NULL)
				cout << "The list is empty" << endl;
			else
				cout << "The list in reverse order using recursion: " << endl;
			reverseLink1Recursion(*&head);

			break;
		case'd':
			
			reverseLink2_Iterative_Method(*&head2); cout << endl << endl;

			break;
		case'e':
			if (link1count == link2count)
				cout << "Both lists are same size" << endl;
			else
				cout << "Not same size: list 1 has " << link1count << " nodes and list 2 has " << link2count << endl;
			if (compareLists(*&head, *&head2))
				cout << "Bothe list has same data" << endl;
			else
				cout << "Bothe list has not same data" << endl;
			break;
		case'f':
			sortLink(*&head); cout << endl << endl;

			break;
		case'g':
			sortLink(*&head2); cout << endl << endl;
			break;
		case'h':
			RemoveDuplicates(*&head); cout << endl << endl;
			break;
		case'i':
			RemoveDuplicates(*&head2); cout << endl << endl;
			break;
		case'j'://This will not work properly. I explained in the function
			mergerLists(*&head, *&head2);
			break;
		case'k'://This will not work properly. I explained in the function
			mergerLists_AtCertain_commanPoint(*&head, *&head2);
			break;
		default:
			break;
		}
	} while (choice != '0');

    return 0;
}

char menu()
{
	char choice;
	cout << "Choose form the menu:\n\n"
		<< "a.Fill link 1\n"
		<< "b.Fill link 2\n"
		<< "c.Reverse Link 1 using Recursion\n"
		<< "d.Reverse Link 2 using Iterative method\n"
		<< "e.Compare two link list\n"
		<< "f.Sort list 1\n"
		<< "g.sort list 2\n"
		<< "h.Remove duplicates from link 1\n"
		<< "i.Remove duplicates from link 2\n"
		<< "j.Merge two sorted linked lists using recursion to form 1 list\n"
		<< "k.Merge two linked lists after some nodes\n"
		<< "0. quit\n\n";
	cout << "Enter your choice here: ";
	cin >> choice;

	return choice;
}

void fillList1(Link_1*&head, Link_1*&last)
{
	cout << "Fill list 1,when done press y" << endl;
	char ch = 'n';
	int data;

	while (ch != 'y')
	{
		Link_1*temp = new Link_1;
		cout << "Enter Data for node #" << link1count + 1 << " : ";
		cin >> data;
		temp->data = data;
		temp->next = NULL;
		if (link1count == 0 || head == NULL)
		{
			head = temp;
			last = temp;
			head->next = NULL;

		}
		else
		{
			last->next = temp;
			last = temp;
		}
		link1count++;
		cout << "Done ?(y/n): ";
		cin >> ch;
	}
		Link_1 *printer = head;
		if (printer == NULL)
			cout << "The list is empty";
		else
		printList(printer);
		cout << "\nNumber of nodes is: " << link1count << endl;

	
}


void printList(Link_1*&head)
{
	if (head == NULL)
		return;
	
	cout << head->data << endl;
	printList(head->next);
	/*else
	{
		cout << "Data of list 1:\n";
		while (head != NULL)
		{
			cout << head->data << endl;
			head = head->next;
		}
	}*/
}


void fillList2(Link_2*&head, Link_2*&last)
{
	cout << "Fill list 2,when done press y" << endl;
	char ch = 'n';
	int data;

	while (ch != 'y')
	{
		Link_2*temp = new Link_2;
		cout << "Enter Data for node #" << link2count + 1 << " : ";
		cin >> data;
		temp->data = data;
		temp->next = NULL;
		if (link2count == 0 || head == NULL)
		{
			head = temp;
			last = temp;
			head->next = NULL;

		}
		else
		{
			last->next = temp;
			last = temp;
		}
		link2count++;
		cout << "Done ?(y/n): ";
		cin >> ch;
	}
	Link_2 *printer = head;
	printList(printer);
	cout << "\nNumber of nodes is: " << link2count << endl;
}


void printList(Link_2*&head)
{
	if (head == NULL)
		cout << "The List is empty" << endl;
	else
	{
		cout << "Data of list 1:\n";
		while (head != NULL)
		{
			cout << head->data << endl;
			head = head->next;
		}
	}
}


void reverseLink1Recursion(Link_1 *&head)
{
	if (head == NULL)//base case which is important for every recursion.Without it the compiler a handler exception error
		//Once the base case is encountered, it implies no more recursive calls are allowed
		return;

	reverseLink1Recursion(head->next);//recursive call to print the next node in the list
	cout << head->data << endl;

	//Note if put the recursive call after the output then it will print the elemnts and it's original order same as the funtion printList1()
	/*Like this:
	cout << head->data << endl;
	reverseLink1Recursion(head->next);*/
}


void reverseLink2_Iterative_Method(Link_2*&head)
{
	/*The method is basicly changing the pointer of the element to the previous instead of next.
	Exmaple the head is pointing to next element (A) with memory address 7 and element A is pointing to the next element (B) with memory address 8
	so what i do is brake the link between A and B and making A pointing to NULL so now the head has been replaced with NULL
	however head is still exist but in the method we use a loop to shift all nodes pointers to previous mem address untill the head become last one pointing to the previous element and so on*/
	/*The List will become like this:
	NULL<- A <-B <-C <-D <-head*/

	if (head == NULL)
		cout << "The List is empty\n" << endl;

	Link_2 *current = head; // Keeps track of the current Node
	Link_2 *prev = NULL;
	Link_2 *nextNode;

	while (current != NULL)
	{
		nextNode = current->next;// Next Node in the list
		current->next = prev;// change the current node with the previous node pointer
		prev = current;
		current = nextNode;//traverse forward

	}
	head = prev;//the last node is now the new head
	while (head != NULL)
	{
		cout << head->data << endl;
		head = head->next;//now head is point to next which is previous
	}
	
	
}

bool compareLists(Link_1*&head, Link_2*&head2)
{
	bool check = false;
	if (head != NULL&&head2 == NULL || head2 != NULL&&head == NULL)
		return false;
	
	while (head != NULL&&head2 != NULL)
	{
		check = false;
		if (head->data == head2->data)
		{
			check = true;
			head = head->next;
			head2 = head2->next;
			
			continue;
		}
		if (check)
			return true;
	}
	return false;
}

void sortLink(Link_1*&head)
{
	if (head == NULL)
	cout << "The list is empty" << endl;
	else
	{
		Link_1 *temp1 = new Link_1;
		Link_1*temp2 = new Link_1;
		int temp = 0;
		for (temp1 = head; temp1 != NULL; temp1 = temp1->next)
		{
			for (temp2 = temp1->next; temp2 != NULL; temp2 = temp2->next)
			{
				if (temp1->data > temp2->data)
				{
					temp = temp1->data;
					temp1->data = temp2->data;
					temp2->data = temp;
				}
			}
		}
		temp1 = head;
		cout << "\nThe sorted list is: " << endl;
		while (temp1 != NULL)
		{
			cout << temp1->data << endl;
			temp1 = temp1->next;
		}
	}
}
void sortLink(Link_2*&head)
{
	if (head == NULL)
		cout << "The list is empty" << endl;
	else
	{
		Link_2 *temp1 = new Link_2;
		Link_2*temp2 = new Link_2;
		int temp = 0;
		for (temp1 = head; temp1 != NULL; temp1 = temp1->next)
		{
			for (temp2 = temp1->next; temp2 != NULL; temp2 = temp2->next)
			{
				if (temp1->data > temp2->data)
				{
					temp = temp1->data;
					temp1->data = temp2->data;
					temp2->data = temp;
				}
			}
		}
		temp1 = head;
		cout << "\nThe sorted list is: " << endl;
		while (temp1 != NULL)
		{
			cout << temp1->data << endl;
			temp1 = temp1->next;
		}
	}
}

void RemoveDuplicates(Link_1*&head)
{	
	Link_1 *temp = head;
	while (head->next != NULL) 
	{
		//If the data in the current node is equal to the data
		//in the next node, then we delete the next node and remain in
		//the same node.
		if (head->data == (head->next)->data)
		{
			head->next = (head->next)->next;
			continue;
		}
		head = head->next;
	}
	cout << "The new list without duplicates: " << endl;
	
	printList(temp);
}

void RemoveDuplicates(Link_2*&head)
{
	Link_2 *temp = head;
	while (head->next != NULL) {
		//If the data in the current node is equal to the data
		//in the next node, then we delete the next node and remain in
		//the same node.
		if (head->data == (head->next)->data)
		{
			head->next = (head->next)->next;
			continue;
		}
		head = head->next;
	}
	cout << "The new list without duplicates: " << endl;
	
	printList(temp);
}

void mergerLists(Link_1*&head, Link_2*&head2)
{
	Link_1* temp;
	Link_2* temp2;
	if (head == NULL && head2 == NULL)//base cases for recursion
		return;
	else if (head == NULL&&head2 != NULL)
		temp2 = head2;
	else if (head != NULL && head2 == NULL)
		temp = head;
	else if (head->data < head2->data)
	{
		//I put this following line in comments because i cannot assign void to Link_1. However this is the algo i'm trying to implement. The best way is to make 1 struct with 2 lists and creat a function pointer of type list. but i want it to work on 2 differnet structs


		//head->next = mergerLists(head->next, head2); //
		temp = head;
	}
	else if(head2->data < head->data)
	{
		//head2->next = mergerLists(head->next, head2);
		temp2 = head2;
	}

}

void mergerLists_AtCertain_commanPoint(Link_1*&head, Link_2*&head2)
{
	/*This method is to merge 2 lists at a certain comman point and make the comman node as 1 list to reach NULL
	example:
	
	LIST1: head->1->2->3->4->8->10->NULL
	LIST2: head->6->11->15->10->5->7->NULL

	As you can see the comman elements have int 10 so we need to combine the comman node to forme the 1 list or we say a Junction.
	but first we need to know the size of list1 and size of list2 and if their is extra nodes we must substract.
		
	the 2 lists at the end should look like:
	LIST1: head->1->2->3->4->8
							   \
								->10 ->5->7->NULL	                            
	     LIST2: head->6->11->15/          


	*/
	Link_1 *temp;
	Link_2* temp2;
	int extra;
	if (link1count > link2count)
	{
		extra = link1count - link2count;
		while (extra--)
		{
			head = head->next; //traverse extra elements
		}
	}
	else if(link1count < link2count)
	{
		extra = link2count - link1count;
		while (extra--)
		{
			head2 = head2->next; //traverse extra elements
		}
	}
	// Now check for a Junction

	/* If at some time the address of both the pointers
	gets Equal or becomes Same Then it is a Junction
	Only the First Meeting Point is a Junction */

	while (head->next!=NULL &&head2->next!=NULL)//however the best condition is head!=head2 but sonce both are from different struct we can't i did not now how to link them, the other way is to make 2 lists from 1 struct
	{

		head = head->next;  //travers Simultaneously
		head2 = head2->next;

	}

}