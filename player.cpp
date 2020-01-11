#include "stdafx.h"
#include"player.h"
#include"actor.h"
#include"stack.h"
#include"list.h"
#include"point.h"
#include"aquarium.h"

#include<iostream>

// 1. Player( ... )
//		Constructs and initializes the Player/Actor and its member variables
//		Remembers and discovers the starting point.
Player::Player(Aquarium* aquarium, Point p, std::string name, char sprite)
	:Actor(aquarium, p, name, sprite), m_brain(), m_discovered() {
	// Discover the starting point
	m_discovered.addToFront(p);
	m_brain.push(p);
}

// 2. stuck()
bool Player::stuck() const {
	return getState() == State::STUCK;
}

// 3. update() 
//		This function implements an algorithm to look through the maze
//      for places to move (STATE::LOOKING). update also handles moving the 
//		player as well, if there is an open undiscovered cell to move to the  
//		player just moves there.  However, there will be cases in which there 
//		are no open or undiscovered cells, at this point the player must 
//		backtrack (State::BACKTRACK) to a point that is adjacent to the next
//		point the player was planning to visit
//
//		Backtracking is challenging, save it for the very very very last thing.
//		Make sure the Looking aspect compiles and works first.
void Player::update() {
	Point currPos;
	Point endPos = getAquarium()->getEndPoint();
	bool pause = false;
	int faullSurrounded;
	int x;
	int y;
	m_brain.push(getCurr());                     //push the starting point
	m_discovered.addToRear(getCurr());           //mark the starting point as discoverd

	if (m_brain.isEmpty())
	{
		std::cout << "There is No Solution.";
		return;
	}
	else
	{
		
		while (!m_brain.isEmpty())
		{

			if (m_brain.isEmpty())
			{
				std::cout << "There is No Solution.";
				return;
			}
			
			setCurr(m_brain.peek());             //no!!!!!!!!!!!
			currPos = getCurr();
			x = currPos.getX();
			y = currPos.getY();
		
			
			if(m_backTrack.isEmpty() || !(m_backTrack.peek() == getCurr()))
				m_backTrack.push(getCurr());

			m_brain.pop();                                      //pop the top point off
			
			if (pause)
			{
				//m_discovered.deleteRear();
				return;
			}

			if (currPos.operator==(endPos))                             //when it at end point
			{
				std::cout << "You Win!!!!";
				return;
			}
			
			faullSurrounded = 4;

			currPos.set(x - 1, y);                            //check the WEST direction
			if (getAquarium()->isCellOpen(currPos) && !_discovered(currPos))
			{
				m_discovered.addToRear(currPos);                      //mark it as discoverd
				m_brain.push(currPos);                               //push onto stack
				currPos = getCurr();
				faullSurrounded--;
			}

			currPos.set(x + 1, y);                            //check the EAST direction
			if (getAquarium()->isCellOpen(currPos) && !_discovered(currPos))
			{
				m_discovered.addToRear(currPos);                      //mark it as discoverd
				m_brain.push(currPos);                               //push onto stack
				currPos = getCurr();
				faullSurrounded--;
			}

			currPos.set(x, y - 1);                       //check the NORTH direction
			if (getAquarium()->isCellOpen(currPos) && !_discovered(currPos))
			{
				m_discovered.addToRear(currPos);                      //mark it as discoverd
				m_brain.push(currPos);                               //push onto stack
				currPos = getCurr();
				faullSurrounded--;
			}

			currPos.set(x, y + 1);                            //check the SOUTH direction
			if (getAquarium()->isCellOpen(currPos) && !_discovered(currPos))
			{
				m_discovered.addToRear(currPos);                      //mark it as discoverd
				m_brain.push(currPos);                               //push onto stack
				currPos = getCurr();
				faullSurrounded--;
			}

			
			
			if (faullSurrounded == 4)                   //be stucked, need to do back track
			{
				m_backTrack.pop();
				if (!m_backTrack.isEmpty())
				{
					m_brain.push(m_backTrack.peek());
					m_backTrack.pop();
				}
			}

			pause = true;
		}
	}  
	



}

// 4. say()
//		Already Implemented, nothing to do here
void Player::say() {

	// Freedom supercedes being eaten
	if (getState() == State::FREEDOM) {
		std::cout << getName() << ": WEEEEEEEEEEEEEEE!";
		return;
	}

	// Being eaten supercedes being lost
	switch (getInteract()) {
	case Interact::ATTACK:
		std::cout << getName() << ": OUCH!";
		break;
	case Interact::GREET:
		break;
	case Interact::ALONE:
	default:
		switch (getState()) {
		case State::LOOKING:
			std::cout << getName() << ": Where's the exit?";
			break;
		case State::STUCK:
			std::cout << getName() << ": Oh no! I'm Trapped!";
			break;
		case State::BACKTRACK:
			std::cout << getName() << ": Argh, all walls or discovered, gotta backtrack...";
			break;
		default:
			break;
		}

		break;
	}
}

// _discovered
//		returns true if the item is in the list
bool Player::_discovered(Point p) {
	return (m_discovered.findItem(p) != -1);
}