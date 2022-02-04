#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contais some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_SQUARE,	//Draw a Square
	DRAW_ELPS,		//Draw an Ellipse
	DRAW_HEX,		//Draw a Hexagon
	DRAW_SHAPES,

	MUL_SELECT,    //multiselect

	//Coloring
	COLOR_WHITE,
	COLOR_BLACK,
	COLOR_TOMATO,
	COLOR_LIGHTGREEN,
	COLOR_DEEPSKYBLUE,
	COLOR_ORANGE,
	
	CHNG_DRAW_CLR,	//Change the drawing color
	CHNG_FILL_CLR,	//Change the filling color
	CHNG_BK_CLR,	//Change background color

	DEL,			//Delete a figure(s)
	MOVE,			//Move a figure(s)
	RESIZE,			//Resize a figure(s)
	ROTATE,			//Rotate a figure(s)
	SEND_BACK,		//Send a figure to the back of all figures
	BRNG_FRNT,		//Bring a figure to the front of all figures
	SAVE,			//Save the whole graph to a file
	LOAD,			//Load a graph from a file
	EXIT,			//Exit the application

	RESIZE_QUARTER,
	RESIZE_HALF,
	RESIZE_DOUBLE,
	RESIZE_QUADRUPLE,

	DRAWING_AREA,	//A click on the drawing area
	STATUS,			//A click on the status bar
	EMPTY,			//A click on empty place in the toolbar
	TO_PICK_IMAGE,        //to pick Image Edit By 'Mahmoud'
	TO_PICK_COLOR,  //to pick fill color Edit By 'Mahmoud' 
	TO_PICK_IMAGE_COLOR,  // to Pick Image And Color Edit By 'Mahmoud'
	RESTART,			//Restart Play Edit By 'Mahmoud'
	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY			//Switch interface to Play mode

	///TODO: Add more action types (if needed)
};

struct Point	//To be used for figures points
{ int x,y; };

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth = 3;	//Width of figure borders
};

#endif
