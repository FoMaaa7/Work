#include "stdafx.h"
void DrawShip( HDC hDC,RECT rect,POINT beg)
{
	const int yCl=(rect.bottom	- rect.top);
	const int xCl=(rect.right	- rect.left);
	
	const double dXPix	= xCl/18;
	const double dYPix	= yCl/17;
	
	SetMapMode(hDC,MM_ISOTROPIC);
	SetWindowExtEx(hDC,xCl,yCl,NULL);
	SetViewportExtEx(hDC,xCl,-yCl,NULL);
	SetViewportOrgEx(hDC,beg.x,yCl-beg.y,  NULL);
	
	POINT pl[]	=          {{2*dXPix,0},
{0,4*dYPix},
{18*dXPix,4*dYPix},
{16*dXPix,0},
{2*dXPix,0}};

	HPEN hPen	= CreatePen(PS_SOLID,2,RGB(160,0,0));
	HPEN hOldPen	= (HPEN)SelectObject(hDC,hPen);
	
Polyline(hDC, pl,sizeof(pl)/sizeof(POINT));
	//
	POINT po[]	= {	{3*dXPix,3*dYPix},
{5*dXPix,1*dYPix},
{5*dXPix,2*dYPix}};
	for(int i = 0, dL = 5*dXPix; i < 3; i++)
			Arc(hDC,po[0].x + i * dL, po[0].y ,
					po[1].x + i * dL, po[1].y,
					po[2].x + i * dL, po[2].y,
					po[2].x + i * dL, po[2].y);
     
	 hPen	= 	CreatePen(PS_SOLID,1,RGB(0,0,200));
	 		DeleteObject(SelectObject(hDC,hPen));
	// ïðàâûé ïàðóñ
	POINT pp[]	= {		{9*dXPix,4*dYPix},
{9*dXPix,15*dYPix},
{16*dXPix,7*dYPix}};

	MoveToEx(hDC,pp[0].x,pp[0].y,NULL);
	for(int i = 0,n=sizeof(po)/sizeof(POINT); i < n; i++)
		LineTo(hDC,pp[i].x,pp[i].y);
	// äóãà ïðàâîãî ïàðóñà
	Arc(hDC, 	9*dXPix,7*dYPix,	23*dXPix,1*dYPix,
16*dXPix,7*dYPix,	9*dXPix,4*dYPix);
	
	//	ëåâûé ïàðóñ
	HRGN hRgnEl		= CreateEllipticRgn(	-6*dXPix,	23*dYPix,
9*dXPix,	4*dYPix);
	HRGN hRgnLeftParus = CreateRectRgn(		5*dXPix,	14*dYPix,
9*dXPix,	6*dYPix);
//CombineRgn(hRgnLeftParus,hRgnRect,hRgnEl,RGN_AND);
	//CombineRgn(hRgnLeftParus,hRgnRect,hRgnEl,RGN_OR);
	//CombineRgn(hRgnLeftParus,hRgnRect,hRgnEl,RGN_XOR);
 	//CombineRgn(hRgnLeftParus,hRgnRect,hRgnEl,RGN_DIFF);
	//CombineRgn(hRgnLeftParus,hRgnRect,hRgnEl,RGN_COPY);
	CombineRgn(hRgnLeftParus,	hRgnLeftParus,	hRgnEl,	RGN_DIFF);
	LOGBRUSH lbPar;
	lbPar.lbColor	= RGB(100,100,200);
	lbPar.lbStyle	= BS_SOLID;
	//lbPar.lbHatch	= 0;
	HBRUSH hBrush	= CreateBrushIndirect(&lbPar);
	HBRUSH hOldBrush	= (HBRUSH)SelectObject(hDC,hBrush);
	FillRgn(hDC,hRgnLeftParus,hBrush);
	
	//	ôëàæîê
	LOGBRUSH lb;
	lb.lbColor	= RGB(255,255,0);
	lb.lbStyle	= BS_SOLID;
	//lb.lbHatch	= 0;
	hBrush	= CreateBrushIndirect(&lb);
	DeleteObject(SelectObject(hDC,hBrush));
	POINT pf[]	= {	{9*dXPix,	15*dYPix}, 	{9*dXPix,	16*dYPix},
{11*dXPix,	16*dYPix},	{10*dXPix,	LONG(15.5*dYPix)},
{11*dXPix,	15*dYPix}};
	Polygon(hDC,pf,sizeof(pf)/sizeof(POINT));
	//	ìà÷òà                    style   width
	hPen	= CreatePen(PS_SOLID,5,RGB(0x80,0x80,0x80));
	DeleteObject(SelectObject(hDC,hPen));
	MoveToEx(hDC,9*dXPix,4*dYPix+3,NULL);
	LineTo(hDC,9*dXPix,17*dYPix);

	DeleteObject(SelectObject(hDC,hOldPen));
	DeleteObject(SelectObject(hDC,hOldBrush));
	
DeleteObject(hRgnEl);
	DeleteObject(hRgnLeftParus);
}
//////////////////////////////////////////
/*	case WM_PAINT:
		{
		hDC = BeginPaint(hWnd,&ps);
		RECT rect;
		//rect.top=300;
		//rect.right=300;
		//rect.bottom =450;
		//rect.left= 10;
		//POINT beg={100,-100};
	    GetClientRect(hWnd,&rect);
	    POINT beg={0,0};
		DrawShip(hWnd,hDC,rect,beg);
	
		EndPaint(hWnd,&ps);
		break;
		}
*/