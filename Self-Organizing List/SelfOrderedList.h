#include "SelfOrderedListADT.h"
#include "book.h"
#include "llist.h"

template <class E>
class SelfOrderedList : public SelfOrderedListADT<E> {
private:
	int compares;
	char mode;
	LList<E> list;

public:
	//Default constructor/destructor
	SelfOrderedList() 
	{
		mode = 'c';
	} //initialize list?
	~SelfOrderedList() {}

	//Look for 'it'.  If found return true and execute the self-ordering
	//heuristic used for ordering the list: count, move-to-front, or transpose.
	//Increments the compare instance variable every time it compares 'it' to
	//other members of the list. Returns true if 'it' is found.
	bool find(const E& it)
	{
		bool found = false;
		list.moveToStart();

		for (int i = 0; i < list.length(); i++)
		{
			if (list.getValue() == it)
			{
				found = true;
				list.incrementFrequency();
				switch (mode)
				{
				case 'c':
					reorderC();
					break;
				case 'm':
					reorderM();
					break;
				case 't':
					reorderT();
					break;
				default:
					break;
				}

				return true;
			}
			list.next(); //make sure isn't running out of list!
			compares++;
		}

		if (found == false)
		{
			if (mode == 'm') // move to front if accessed 
			{
				list.moveToStart();
				list.insert(it, 0);
			}
			else {
				add(it);
			}
			return false;
		}
	}

	//Called by find if 'it' is not in the list. Adds the new 'it' to the list
	//Can also be called independently when initially loading the list with
	//unique values and when you want to load the list in the order 'it' is 
	//read without your re-order method being called (or the number of compares
	//being incremented.
	void add(const E& it) {
		list.append(it);
	}
		//Add new 'it' to the list


	int getCompares() const {
		return compares;
	}   //Returns the number of accumulated compares
	int size() const {
		return list.length();
	}//Returns the size of the list

	//Print the list
	//In order print of the list.  printlist() prints the entire list
	//whereas printlist(n) prints n nodes.
	void printlist() const {
		list.print();
	}
	void printlist(int n) const {
		list.print(n);
	}

	void reorderC() {
		int frequency = list.getFrequency();
		E temp = list.remove();

		list.moveToStart();
		for (int i = 0; i < list.length(); i++)
		{
			if (frequency > list.getFrequency())
			{
				list.insert(temp, frequency);
				compares++;
				break;
			}
			list.next();
		}
	}

	void reorderM() {
		int frequency = list.getFrequency();
		E temp = list.remove();
		list.moveToStart();
		list.insert(temp, frequency);
	}

	void reorderT() {
		int frequency = list.getFrequency();
		E temp = list.remove();
		list.prev();
		list.insert(temp, frequency);
	}

	void setMode(char m) {
		mode = m;
	}

};


//Test against char array and against string