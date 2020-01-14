# Project of Data Structure

# Find-Nemo-Maze-Solver-
In this project you will be implementing basic artificial intelligence (AI) for Nemo. Nemo
is lost in a large aquarium with a maze of coral. There are hungry sharks roaming the 
aquarium who will take a bite out of the poor fish if they encounter him.

# Maze.txt
Input files for the maze. The aquarium will build its maze based on what is in whichever maze file passed to it. This is to allow ease of modifying/creating mazes. The mazes in these text files must follow certain rules since there are no checks in the program itself to ensure format:
- Walls are marked by ‘X’ and open cells are spaces.
- Mazes must be rectangle and completely enclosed.
- There can be no whitespace after the rightmost wall/column.
- There must be one newline after the last row.
- There must be a cell marked ‘S’ to indicate the starting position for Nemo. There must be a cell marked with ‘E’ to indicated the ending point for the maze.


# Actor class
Base class for the Actors in the Aquarium. Notable members include the actors position in the Aquarium, the actor’s state and interaction, and also a pointer to the Aquarium itself. The actor does not create the Aquarium, it just points to it so it can obtain information about its surroundings.

# Player class
Derived from Actor, will be instantiated as the player Nemo.

# Shark class
Derived from Actor, non-player characters that randomly move around in the maze. They will take a bite at Nemo if they are in the same cell as Nemo at any step. They will greet each other if there are multiple sharks in the same cell and Nemo is not.

# Aquarium class
Creates the maze and Actors, manages the Actors, and draws everything on the console.

# Game class
Creates the Aquarium and manages the game loop

# Point class
A point class representing the (x,y) coordinates in the maze and Actors’ position

# List class
A template for linked list.

# Stack class
Templated Stack interface using the linked list implementation.

# Main class
Entry point of the program, you will use this to test the code you develop.

