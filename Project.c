#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<stdbool.h>
	int height=20;
	int width=50;
	bool gameover;
	int x,y,score;  //x,y are pacman's co-ortinates
	enum eDirection{STOP=0, LEFT,RIGHT,UP,DOWN};
	enum eDirection dir;


	void Setup(){
		gameover=false;
		dir=STOP;
		x = width / 2;
		y = height / 2;
		score=0;

	}

	void Draw(){
		int i,j;
		system("cls");
		for (i=0;i<width;i++)
		{
			if(i==0) printf("%c",201);
			else if(i==width-1) printf("%c",187);           //prints top border
			else printf("%c",205);
		}

		printf("\n");
		for(i=0;i<height;i++){
			for(j=0;j<width;j++){
				if(j==0 || j==width-1) printf("%c",186);        //prints side border, pacman(C), "dot(.)",,,
                                                                //add ghosts too
				else if(j==x && i==y) printf("C");

				else printf(".");

			}
			printf("\n");
		}

		for (i=0;i<width;i++)
		{
			if(i==0) printf("%c",200);
			else if(i==width-1) printf("%c",188);           //lower border
			else printf("%c",205);
		}

	}

	void Input(){
		if(_kbhit()){
			switch(_getch()){                           //if user presses stuff then only getch() activates and hence takes input
				case 'a':
					dir=LEFT;
					break;

				case 'd':
					dir=RIGHT;
					break;

				case 'w':
					dir=UP;
					break;


				case 's':
					dir=DOWN;
					break;

				case 'x':
					gameover=true;
					break;
			}
		}
	}

	void Logic(){

			switch(dir){                            //pacman's co-ordinate changes when corresponding key is pressed
				case LEFT:
					x--;
					break;
				case RIGHT:
					x++;
					break;
				case UP:
					y--;
					break;
				case DOWN:
					y++;
					break;
			}
		if(x>width) x=width-2;
		if(y>height) y=height-1;
		if(x<0) x=1;
		if(y<0)y=0;
	}
	int main(){
		Setup();
		while(!gameover){
			Draw();
			Input();
			Logic();
			Sleep(50);
		}
		if(score==300) printf("Congrats You won");                  //score not implemented.....yet
		else printf("Too bad.... try again");
		return 0;
	}
