Extensions to game

1. Player class has a method called keyPressEvent which deals with events when the
user triggers a new one.
There are two events which could be triggered:
	i) If user presses the up key on the keyboard, the player in the game 
	will fire to the left. This will be further developed to kill enemies 
	on later stages. For now, a fire is displayed and moves to the left
	as soon as user pressed up key, with an additional sound to let user
	know every time they fire.
	
	
	ii) If user presses space bar, a jump sound will be player. Which will be
	further developed in Stage 2 to actually make the player jump

2. There is a background music played as soon as the game is started


Design Pattern

The Player Design Pattern: Builder
* Object: the player
This class will have mandatory arguments such as initial x position, speed and size. However, it will also have optional arguments which the user does not need to specify. These could be color of player for example. If no color is specified, the original default color will de be applied to the player. 


Coding style

Coding style used: Google C++

* Headers: .h extension, can compile on their own, #define Guards, inline function
* Comments: Function comments immediately preceding function declaration, implementation comments of logic behind parts of a code
* Classes: all declarations are within namespace scope in the .h files and definitions are in the .cc file within scope of namespace
* Formatting: within max 80 characters per line, space before and after IF in conditional statements
* etc,
