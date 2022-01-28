#include "ActionSwitchDraw.h"
#include "../ApplicationManager.h"
#include "../GUI/GUI.h"

ActionSwitchDraw::ActionSwitchDraw(ApplicationManager* pApp) :Action(pApp)
{
}

void ActionSwitchDraw::Execute()
{
	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();
	pGUI->PrintMessage("You are in Draw Mode XD");
	// to create New ToolBar
	pGUI->CreateDrawToolBar();
}
