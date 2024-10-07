#include "SelfOrderedList.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

int main() {

	SelfOrderedList<char> listC;
	SelfOrderedList<char> listM;
	SelfOrderedList<char> listT;

	listC.setMode('c');
	listM.setMode('m');
	listT.setMode('t');

	listC.add('A');
	listC.add('B');
	listC.add('C');
	listC.add('D');
	listC.add('E');
	listC.add('F');
	listC.add('G');
	listC.add('H');

	listM.add('A');
	listM.add('B');
	listM.add('C');
	listM.add('D');
	listM.add('E');
	listM.add('F');
	listM.add('G');
	listM.add('H');

	listT.add('A');
	listT.add('B');
	listT.add('C');
	listT.add('D');
	listT.add('E');
	listT.add('F');
	listT.add('G');
	listT.add('H');

	cout << "Starting List Structure (Char):" << endl;
	listC.printlist();

	listC.find('D');
	listC.find('H');
	listC.find('H');
	listC.find('G');
	listC.find('H');
	listC.find('E');
	listC.find('G');
	listC.find('H');
	listC.find('G');
	listC.find('H');
	listC.find('E');
	listC.find('C');
	listC.find('E');
	listC.find('H');
	listC.find('G');

	listM.find('D');
	listM.find('H');
	listM.find('H');
	listM.find('G');
	listM.find('H');
	listM.find('E');
	listM.find('G');
	listM.find('H');
	listM.find('G');
	listM.find('H');
	listM.find('E');
	listM.find('C');
	listM.find('E');
	listM.find('H');
	listM.find('G');

	listT.find('D');
	listT.find('H');
	listT.find('H');
	listT.find('G');
	listT.find('H');
	listT.find('E');
	listT.find('G');
	listT.find('H');
	listT.find('G');
	listT.find('H');
	listT.find('E');
	listT.find('C');
	listT.find('E');
	listT.find('H');
	listT.find('G');

	cout << endl;
	cout << "Count Heuristic (Char)" << endl;
	cout << "Number of compares: " << listC.getCompares() << endl;
	listC.printlist();
	cout << endl << "List size: " << listC.size();
	
	cout << endl << endl;
	cout << "Move-To-Front Heuristic (Char)" << endl;
	cout << "Number of compares: " << listM.getCompares() << endl;
	listM.printlist();
	cout << endl << "List size: " << listM.size();

	cout << endl << endl;
	cout << "Transpose Heuristic (Char)" << endl;
	cout << "Number of compares: " << listT.getCompares() << endl;
	listT.printlist();
	cout << endl << "List size: " << listT.size();

	SelfOrderedList<string> stringC;
	SelfOrderedList<string> stringM;
	SelfOrderedList<string> stringT;

	stringC.setMode('c');
	stringM.setMode('m');
	stringT.setMode('t');

	ifstream input;
	string word;
	input.open("test.txt");
	while (input)
	{
		input >> word;
		stringC.find(word);
	}
	input.close();

	cout << endl << endl;
	cout << "Count Heuristic (String)" << endl;
	cout << "Number of compares: " << stringC.getCompares() << endl;
	stringC.printlist(10);
	cout << endl << "List size: " << stringC.size();

	input.open("test.txt");
	while (input)
	{
		input >> word;
		stringM.find(word);
	}
	input.close();

	cout << endl << endl;
	cout << "Move-To-Front Heuristic (String)" << endl;
	cout << "Number of compares: " << stringM.getCompares() << endl;
	stringM.printlist(10);
	cout << endl << "List size: " << stringM.size();

	input.open("test.txt");
	while (input)
	{
		input >> word;
		stringT.find(word);
	}
	input.close();

	cout << endl << endl;
	cout << "Transpose Heuristic (String)" << endl;
	cout << "Number of compares: " << stringT.getCompares() << endl;
	stringT.printlist(10);
	cout << endl << "List size: " << stringT.size() << endl << endl << endl;


}