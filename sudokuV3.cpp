#include<iostream>
#include<graphics.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

using namespace std;
	
bool numSelected = false;
bool eraseSelected = false;
int selectedNum = 0;
int preSelectedNum = 0;
int preSelectedNumx;
int preSelectedNumy;

int mainArr[9][9] = {   7,3,5,6,1,4,8,9,2,
						8,4,2,9,7,3,5,6,1,
						9,6,1,2,8,5,3,7,4,
						2,8,6,3,4,9,1,5,7,
						4,1,3,8,5,7,9,2,6,
						5,7,9,1,2,6,4,3,8,
						1,5,7,4,9,2,6,8,3,
						6,9,4,7,3,8,2,1,5,
						3,2,8,5,6,1,7,4,9 };

int problemArr[9][9] = {
						0,0,0,0,0,4,0,9,0,
						8,0,2,9,7,0,0,0,0,
						9,0,1,2,0,0,3,0,0,
						0,0,0,0,4,9,1,5,7,
						0,1,3,0,5,0,9,2,0,
						5,7,9,1,2,0,0,0,0,
						0,0,7,0,0,2,6,0,3,
						0,0,0,0,3,8,2,0,5,
						0,2,0,5,0,0,0,0,0};

int solArr[9][9] = {
						0,0,0,0,0,4,0,9,0,
						8,0,2,9,7,0,0,0,0,
						9,0,1,2,0,0,3,0,0,
						0,0,0,0,4,9,1,5,7,
						0,1,3,0,5,0,9,2,0,
						5,7,9,1,2,0,0,0,0,
						0,0,7,0,0,2,6,0,3,
						0,0,0,0,3,8,2,0,5,
						0,2,0,5,0,0,0,0,0};
												
void gameWindow(){
	setcolor(15);
	rectangle(50,50,500,500);
	
		for(int i=1;i<10;i++){
	line(50*i,50,50*i,500);
	line(50,50*i,500,50*i);
	rectangle(50*i,550,50*(i+1),600);
	}
	
	
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			if((j==3 || j==4 || j==5 || i==3 || i==4 || i==5)&&!((j==3 || j==4 || j==5 )&&(i==3 || i==4 || i==5)))
			setfillstyle(1,2);
			else
			setfillstyle(1,10);
			floodfill(75+(j*50),75+(i*50),15);
		}
	}
	settextstyle(8,0,3);
	outtextxy(25,65,"1");
	outtextxy(25,115,"2");
	outtextxy(25,165,"3");
	outtextxy(25,215,"4");
	outtextxy(25,265,"5");
	outtextxy(25,315,"6");
	outtextxy(25,365,"7");
	outtextxy(25,415,"8");
	outtextxy(25,465,"9");
	
	settextstyle(8,0,3);
	outtextxy(65,25,"1");
	outtextxy(115,25,"2");
	outtextxy(165,25,"3");
	outtextxy(215,25,"4");
	outtextxy(265,25,"5");
	outtextxy(315,25,"6");
	outtextxy(365,25,"7");
	outtextxy(415,25,"8");
	outtextxy(465,25,"9");
	
	settextstyle(8,0,5);
	outtextxy(65,555,"1");
	outtextxy(115,555,"2");
	outtextxy(165,555,"3");
	outtextxy(215,555,"4");
	outtextxy(265,555,"5");
	outtextxy(315,555,"6");
	outtextxy(365,555,"7");
	outtextxy(415,555,"8");
	outtextxy(465,555,"9");	
	
	setbkcolor(0);
		setcolor(15);
		settextstyle(8,0,2);
		outtextxy(50,525,"select a number to enter :");
	
	//buttons
	settextstyle(10,0,5);
	outtextxy(550,100,"SUDOKU");
	rectangle(550,150,700,190);
	rectangle(550,200,700,240);
	rectangle(550,250,700,290);
	rectangle(550,300,700,340);
	rectangle(550,400,700,440);

	settextstyle(8,0,3);
	outtextxy(565,160,"NEW GAME");
	settextstyle(8,0,4);
	outtextxy(575,205,"ERASE");
	outtextxy(575,255,"RESET");
	outtextxy(585,305,"HELP");
	outtextxy(585,405,"QUIT");
}


void dispArr(){
char str[4];
settextstyle(10,0,5);
setcolor(4);
for(int i=0; i<9; i++){
	for(int j=0; j<9; j++){
	sprintf(str, "%d", problemArr[i][j]);
	if(problemArr[i][j]!=0){
	setbkcolor(getpixel(65+(j*50),65+(i*50)));
	outtextxy(65+(j*50),57+(i*50),str);	
	}
}}
}


void dispSolArr(){
char str[4];
settextstyle(10,0,5);
setcolor(1);
for(int i=0; i<9; i++){
	for(int j=0; j<9; j++){
	sprintf(str, "%d", solArr[i][j]);
	if(solArr[i][j]!=0 && problemArr[i][j]==0){
	setbkcolor(getpixel(65+(j*50),65+(i*50)));
	outtextxy(65+(j*50),57+(i*50),str);	
	}
}}
}

bool check(int x, int y, int num){
	int found=0;
	
	for(int i=0; i<9; i++){					//horizontal matching check
		if(solArr[x][i] == num){
		found++; 
		break;}
	}
	if(found==0){
	for(int i=0; i<9; i++){					//vertical matching check
		if(solArr[i][y] == num){
		found++;  break;}
	}
	}
	
	if(found==0){
	int i,j,endx, endy;
	if(y<=2 && x<=2) { i=0; j=0;}
	else if(y<=5 && x<=2) {i=0; j=3;}
	else if(y<=8 && x<=2) {i=0; j=6;}
	else if(y<=2 && x<=5) {i=3; j=0;}
	else if(y<=5 && x<=5) {i=3; j=3;}
	else if(y<=8 && x<=5) {i=3; j=6;}
	else if(y<=2 && x<=8) {i=6; j=0;}
	else if(y<=5 && x<=8) {i=6; j=3;}
	else if(y<=8 && x<=8) {i=6; j=6;}
	
	endx = i+3;
	endy = j+3;
	
	for(;i<endx;i++){						//box matching check
		for(j=endy-3 ;j<endy;j++){
			if(solArr[i][j]==num){
				found++; break;	}
		}
	}
	}
	
if(found==0)
	return true;
else 
	return false; 
}

void reset(){									//RESET function
	setbkcolor(0);
	cleardevice();
	numSelected = false;
	selectedNum = 0;
	preSelectedNum = 0;
	
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			solArr[i][j]=problemArr[i][j];
		}
	}				
	gameWindow();
	dispArr();
}

void click_handler(int x, int y)
{

    
	if (y>500 && y<600 && x>50 && x<500)
	{	
		numSelected = true;
		
		if(numSelected && preSelectedNum!=0){
		setfillstyle(1,0);
		floodfill(preSelectedNumx,preSelectedNumy,15);}
		
		if(x<100) selectedNum = 1;
		else if(x<150) selectedNum = 2;
		else if(x<200) selectedNum = 3;
		else if(x<250) selectedNum = 4;
		else if(x<300) selectedNum = 5;
		else if(x<350) selectedNum = 6;
		else if(x<400) selectedNum = 7;
		else if(x<450) selectedNum = 8;
		else if(x<500) selectedNum = 9;
			
		setfillstyle(1,3);
		floodfill(x,y,15);				//problem with floodfill if clicked on number.
		
		preSelectedNum = selectedNum;
		preSelectedNumx = x;
		preSelectedNumy = y;
	}

	else if(y>50 && y<500 && x>50 && x<500){
		int i,j;
		if(y<100) i=0;
		else if(y<150) i=1; 
		else if(y<200) i=2 ;
		else if(y<250) i=3 ;
		else if(y<300) i=4 ;
		else if(y<350) i=5 ;
		else if(y<400) i=6 ;
		else if(y<450) i=7 ;
		else if(y<500) i=8 ;
	
		if(x<100) j=0;
		else if(x<150) j=1; 
		else if(x<200) j=2 ;
		else if(x<250) j=3 ;
		else if(x<300) j=4 ;
		else if(x<350) j=5 ;
		else if(x<400) j=6 ;
		else if(x<450) j=7 ;
		else if(x<500) j=8;
	
		if(eraseSelected){
			solArr[i][j]=0;
			numSelected = false;
			selectedNum = 0;
			preSelectedNum = 0;
	
			setbkcolor(0);
			cleardevice();
			gameWindow();
			dispArr();
			dispSolArr();
			eraseSelected = false;
			setfillstyle(1,0);
			floodfill(560,210,15);
			
		}
		else if(check(i,j,selectedNum)){
			solArr[i][j]=selectedNum;
			dispSolArr();
		}
		else Beep(523,500);
	}
	
	else if(x>550 && x<700){
		
		if(y>150 && y<190){				//NEW GAME
		}
		else if(y>200 && y<240){		//ERASE
			eraseSelected = true;
			setfillstyle(1,3);
			floodfill(560,210,15);
		}
		else if(y>250 && y<290){		//RESET
			reset();
		}
		else if(y>300 && y<340){		//HELP
		}
		else if(y>400 && y<440){		//QUIT
			closegraph();
		}		
	}
}


int main(){
	initwindow(750,650,"SUDOKU");
	registermousehandler(WM_LBUTTONDOWN, click_handler);

	gameWindow();
	dispArr();
	getch();
	closegraph();
	return 0;
}
