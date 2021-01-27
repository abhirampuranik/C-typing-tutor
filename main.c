#include<time.h>
#include<conio.h>
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>

static int x=1;//used for x cursor co-ordinate
#define pos gotoxy(33,x++) /*for cursor movement*/
#define ln  printf(".......................");

COORD coord={0,0};
void gotoxy(int x,int y);


void gotoxy(int x,int y)//function to set the cursor position
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void delay(unsigned int mseconds)//function for delay for the player getting set for any action in the game, **takes input in milli second**
{
	clock_t goal=mseconds+clock();
	while(goal>clock());
}

int t=30;
int c=0; //so as the player dosen't be asked his/her name everytime he comes to the main menu

char name[15];
void sett();//sets time limit
void getscore(int score,int speed,int level);
void starttutor();  
void sentence();
void check(char *, char *, int , double );
void scorecard();  
void About_us();
void help();



//			main function
int main()
{       
	int ch;
	x=1;
	system("cls");
	pos;
	printf("Welcome to Typing Tutor");
	pos;
    ln pos;
	if(c==0)
	   {	
	   	printf("Enter Your name: ");
		gets(name);
	   }
	   c++;
		pos;ln pos;
		printf("       MAIN MENU   ");pos;
		ln
		pos;
		printf("1.Start Tutor");
		pos;
		printf("2.Scorecard");
		pos;
		printf("3.Set the time limit");
		pos;
		printf("4.Help");
		pos;
		printf("5.About Us");
		pos;
		printf("0.Exit");
		pos;
		printf("Enter your choice: ");
		scanf("%d",&ch);
		pos;
		switch(ch)
		{       
			case 1:starttutor();break;
			case 2:scorecard();break;
			case 3:sett();main();
			case 4:help();break;
			case 5:About_us();break;
			case 0:system("cls");gotoxy(17,10);printf("Thank You for using Typing Tutor");delay(2000);exit(1);
			default:main();
		}

	getch();
}



void starttutor()
{       
	int score=0,level=1,mode=100,count=0;
	clock_t begin;
	int time_spent,speed,initial = 0,i; //initial for terminating if there is wrong enrty in the first choice, i for difficult mode

	int r,letter,ch;
	delay(500);

	system("cls");
	x=2;
	pos;
	
	printf("select the Mode");pos;
	ln
	pos;
	printf("1.Easy mode");
	pos;
	printf("2.Normal mode");
	pos;
	printf("3.Difficult mode");
	pos;
	printf("4.Sentence");
	pos;
	printf("5.Back to main menu");
	pos;
	scanf("%d",&level);
	if(level==5)
		main();
	else if(level==4)
		sentence();
	else
	{     
		if(level==1)    //for lowercase alphabet
	    	mode=97;
	    if(level==2)    //for uppercase
			mode=65;
	     if(level==3)    //condition for mixed case
			mode=65;
		begin=clock();
		while(1)
		{       
			system("cls");
			time_spent=(int)(clock()-begin)/CLOCKS_PER_SEC;

			if(time_spent>=t)
				break;
			r=rand();
			
			if(level==1 || level==2)
				{
					r=(r%26)+mode;	// gives only ascii values of letter between a-z or A-Z depending on the mode
				}

			if(level == 3 )
			{
				i = rand()%2;
					if(i==0)
						mode = 65;
					else
						mode = 97;
				r=(r%26)+mode;
			}
				
			gotoxy(20,8);
			printf("....Type the following character....");
			gotoxy(36,11) ;
			printf(" %c",r); 
			
			letter=getch();

			if(letter!=r)
				break;
			else
			{       
				count++;
				score=score+10;
				gotoxy(28,9);
				printf("score=%d",score);
				gotoxy(37,9);
				printf("Time spent=%d sec",time_spent);//prints time spent during game
				initial = 1;
				delay(500);
			} 
		}
		gotoxy(26,x);

		delay(400);

		
		++x;
		pos;
		if(initial!=0)
			speed=(count*60)/time_spent ;
	      
		if(time_spent<t || initial == 0)
			printf("Wrong Entry");
		else
		{      
			printf("Times up !Game over!");
			pos;
			
			if((speed>=40)&&(speed<=50))
			{	
				printf("Good Work !Keep it up!");
				pos;

				printf("You got silver medal");
			}
			else
			if(speed>50)
			{
				printf("Nice work! You got Gold medal");
			}
			else
			printf("Sorry no medal !you need practise..");
		}
		pos;
		
		printf("Total score is : %d and your time spent is %d seconds",score,time_spent);
		pos;
		
		if(initial!=0)
		printf("Your speed is %d letters per minute",speed);

		getscore(score,speed,level);//saves data to file
		++x;
		pos;
		printf("1. Play again ");
		pos;
		printf("2. Main menu ");
		pos;
		printf("3. Exit"); 
		pos;
		printf("Enter your choice: ");
		pos;
		scanf("%d",&ch);
		switch(ch)
		{
		      case 1:starttutor();break;//recursive call
		      case 2:main();break;
		      case 3:system("cls");gotoxy(17,10);printf("Thank You for using our typing tutor");delay(600);exit(1);
		      default:pos;printf("Select a correct option");pos;
				main();
		}

	}

}


void sett()  //set time limit
{
	int ch;
	system("cls");
	x=5;
	pos;
	printf("Set the time limit for game in minute: ");
	pos;
	ln
	pos;
	printf("press 0 for half minute") ;pos;
	printf("press 1 for 1 minute"); pos;
	printf("press 2 for 2 minute");pos;
	scanf("%d",&ch);
	switch(ch)
	{
		case 0:t=30;break;
		case 1:t=60;break;
		case 2:t=120;break;
		default:main();
	}
}




void help() // help for user to use the tutor
{
	system("cls");
	gotoxy(7,5);

	printf("Rules to use our typing tutor");gotoxy(7,6);
	printf("=>Enter your name which helps you to track your score");gotoxy(7,7);
	printf("=>Set the time limit under option 3 in main menu(default limit is 30 sec)");gotoxy(7,8);
	printf("=>select the level, we have 4 levels");gotoxy(7,9);
	printf("=>Characters are displayed and you have to type them as fast as you can..");gotoxy(7,10);
	printf("=>3 Sentence option is given and you can choose any of them and type and practice..");gotoxy(7,11);
	printf("=>Avoid incorrect typing otherwise game will be over..");
	getch();main();
}


void About_us() // people in our team
{       system("cls");
	gotoxy(7,7);
		printf("Hello Everyone! Our Team\n");
	gotoxy(7,8);
       	printf("Abhiram Puranik\n");
	gotoxy(7,9);
		printf("Ashlesh Upadhyaya\n");
	gotoxy(7,10);
       	printf("Rishab S\n");
	gotoxy(7,11);
       	printf("Yogesh Gowda");
       
       getch();
       main();
}

void check(char s[], char ch[], int n, double time_taken){   // used for sentence input validation
	if(!strcmp(s,ch)) 
	{
		double WPM;
		gotoxy(7,10);
		printf("The sentence was typed correct");
		gotoxy(7,11);
		printf("The Statements took %f seconds to execute \n", time_taken); 
		
		time_taken=time_taken/60;
		WPM=n/time_taken;
		gotoxy(7,12);
		printf("The words per minute is %.1f",WPM);
	}
	else
	{
		gotoxy(7,10);
		printf("Oops! There was a mistake in the Statement you typed.");
		gotoxy(7,11);
		printf("Try again");
	}
	getch();
	
}	


void sentence() // used to take sentence input from the user
{
	system("cls");
	int u;
	char s1[]="The quick brown fox jumps over the lazy dog.";
	
	char s2[]="What a beautiful day it is on the beach, here in beautiful and sunny Hawaii.";
	
	char ch1[100];char ch2[100];char ch3[100];
	char s3[]="Xavier Puvre counted eighty large boxes and sixteen small boxes stacked outside.";
	clock_t t1; double WPM;
    int choice;
    gotoxy(7,2);
    printf("Choose your sentence to practice\n");
    gotoxy(7,3);
    printf("1. %s\n", s1);
    gotoxy(7,4);
    printf("2. %s\n", s2);
    gotoxy(7,5);
    printf("3. %s\n", s3);
    gotoxy(7,6);
    scanf("%d",&choice);
	switch(choice)
    {
    	case 1:{
	    		t1 = clock();
	    		gotoxy(7,7);
	    		printf("Type this Exactly");
	    		gotoxy(7,8);
	    		printf("%s\n",s1);
	    		gotoxy(7,9);
				scanf("\n", ch1);
				gets(ch1);
				t1 = clock() - t1; 
	    		double time_taken = ((double)t1)/CLOCKS_PER_SEC;
	    		check(s1,ch1,9,time_taken);
				break;
    		}
    	case 2:{
    			t1 = clock();
	    		gotoxy(7,7);
	    		printf("Type this Exactly");
	    		gotoxy(7,8);
	    		printf("%s\n",s2);
	    		gotoxy(7,9);
				scanf("\n", ch2);
				gets(ch2);
				t1 = clock() - t1; 
	    		double time_taken = ((double)t1)/CLOCKS_PER_SEC;
	    		check(s2,ch2,16,time_taken);
				break;
    		}
    	case 3:{
    			t1 = clock();
	    		gotoxy(7,7);
	    		printf("Type this Exactly");
	    		gotoxy(7,8);
	    		printf("%s\n",s3);
	    		gotoxy(7,9);
				scanf("\n", ch3);
				gets(ch3);
				t1 = clock() - t1; 
	    		double time_taken = ((double)t1)/CLOCKS_PER_SEC;
	    		check(s3,ch3,12,time_taken);
				break;
    		}
    		default:{
    			gotoxy(7,7);
    			printf("Select correct option\n");
    			getch();
    			sentence();
    		}

    }

	system("cls");
	++x;
		pos;
		printf("1. Play again ");
		pos;
		printf("2. Main menu ");
		pos;
		printf("3. Exit"); 
		pos;
		printf("Enter your choice: ");
		pos;
		scanf("%d",&u);
		switch(u)
		{
		      case 1:starttutor();break;//recursive call
		      case 2:main();break;
		      case 3:system("cls");gotoxy(17,10);printf("Thank You for using our typing tutor");delay(600);exit(1);
		      default:pos;printf("Select a correct option");pos;
				main();
		}
}



void getscore(int score,int speed,int level)    // append a new record to the file
{
	FILE *fp;
	fp=fopen("file.txt","a");
	pos;
	if(fp==NULL)
	printf("error in opening file");
	fprintf(fp,"\nName: %s   Score: %d    Speed: %d    Level: %d",name,score,speed,level);
	fclose(fp);
	pos;
	printf("Scorecard updated");
}



void scorecard() // outputs the record in the file.txt
{       
	int ch;
	FILE *fp;
	system("cls");
	printf("\t\t\tTHE SCORES ARE\n");

	fp=fopen("file.txt","r");
	while((ch=fgetc(fp))!=EOF)
	{	
		printf("%c",ch);
	}
	getch();
	main();
}