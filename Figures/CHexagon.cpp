#include "CHexagon.h"
#include<fstream>

int CHexagon::HexCnt = 0;  //static variable to determine the number of objects

CHexagon::CHexagon(){}

CHexagon::CHexagon(Point C, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo)
{
	Center = C;
	HexCnt++;
	P.x = 80; P.y = 30;
}

void CHexagon::DrawMe(GUI* pOut) const
{
	//Call Output::DrawEllipse to draw a ellipse on the screen	
	pOut->DrawHex(Center, FigGfxInfo, Selected);
}

void CHexagon::Load(ifstream& loadedFile, GUI* pGUI)
{
	string drawColor, fillColor;
	loadedFile >> ID >> Center.x >> Center.y >> P.x >> P.y >> drawColor >> fillColor;
	FigGfxInfo.DrawClr = pGUI->StringToColor(drawColor);
	if (fillColor == "NO_FILL")
	{
		FigGfxInfo.isFilled = false;
	}
	else
	{
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = pGUI->StringToColor(fillColor);
	}
	CHexagon::SetSelected(false);
}


// khaled
double area1(int x1, int y1, int x2, int y2, int x3, int y3)
{
	return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}

// khaled 
// InFig return boolian to check point inside Figure 
bool CHexagon::InFig(int x, int y)
{
	int y1 = Center.y - P.x, y2 = Center.y + P.y, x1 = Center.x - P.x, x2 = Center.x + P.y;
	double A = .5 * abs(P.x) * 2 * abs(P.y) * 2;
	double A1 = area1(x, y, x2, Center.y, Center.x, y1);
	double A2 = area1(x, y, x2, Center.y, Center.x, y2);
	double A3 = area1(x, y, Center.x, y2, x1, Center.y);
	double A4 = area1(x, y, x1, Center.y, Center.x, y1);
	if (A == A1 + A2 + A3 + A4)
	{
		return true;
	}
	return false;
}

// khaled
// Print to return all info about figure
string CHexagon::PrintInfo()
{
	string id = to_string(ID);
	string x = to_string(Center.x);
	string y = to_string(Center.y);
	/*string clr = getColor(this->FigGfxInfo.DrawClr);

	if (FigGfxInfo.isFilled)
	{
		pOut->PrintMessage(" - FillColor: ");
		string clrF = getColor(this->FigGfxInfo.FillClr);
		return ("Ellipse -ID: " + id + " Center: (" + x + ", " + y + ") DrawColor:" + clr + " FillColor: " + clrF);
	}
	else*/
		return ("Ellipse -ID: " + id + " Center: (" + x + ", " + y + ") DrawColor:");
}


