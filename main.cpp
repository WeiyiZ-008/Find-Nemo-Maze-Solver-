// Project3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;

/**
// DEFINE YOUR TEST
#define TEST1

#ifdef TEST1
//		What single specific paricular uno ein one-thing is being tested?:
//		What is expected?:
//		What happens?:
#include"list.h"
int main() {

	int a;
	List<int> l;

	l.addToRear(3);
	l.addToFront(-1);
	l.addToFront(9000);
	l.addToFront(2);
	//l.deleteItem(1);
	l.printItems();
	l.deleteRear();
	l.printItems();
	cin >> a;
	return 0;
}
  *//**
#define TEST2
#ifdef TEST2
//		What single specific paricular uno ein one-thing is being tested?:
//		What is expected?:
//		What happens?:
#include"stack.h"
int main() {
	int c;
	Stack<std::string> s;

	s.push("Harry");
	s.push("Ron");
	s.push("Hermione");
	cout << s.peek() << endl;
	s.pop();
	cout << s.peek() << endl;
	cin >> c;
	return 0;
}  */   /*
#define TEST3
#ifdef TEST3 //Test the maze in lecture slides
//		What single specific paricular uno ein one-thing is being tested?:
//		What is expected?:
//		What happens?:
#include"game.h"
int main() {
	Game g("maze_lecture.txt", 4);
	g.play();
	return 0;
}   
*/

#define TEST4
#ifdef TEST4  //Test a custom maze.
//		What single specific paricular uno ein one-thing is being tested?:
//		What is expected?:
//		What happens?:
#include"game.h"
int main() {
	Game g("maze.txt", 6);
	g.play();
	return 0;
}  
#elif defined(TEST5) //Test too many sharks
//		What single specific paricular uno ein one-thing is being tested?:
//		What is expected?:
//		What happens?:
#include"game.h"
int main() {
	Game g("maze.txt", 800);
	g.play();
	return 0;
}
#else
int main() {
	cout << "Hello World!" << endl;
	return 0;
}
#endif