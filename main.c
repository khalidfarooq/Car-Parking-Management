#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>


//keeps the track of no of cars presentm at
// any given moment
int cars_parked=0;
int count=0;

struct Node
{
    int data; // holds only 0 or 1 i.e FREE or Occupied
    struct Node* next;
};

//initialise all nodes to zero at first i.e. all are FREE
void CreateAndallZero(struct Node **first, int new_data)
{
    struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));


    newnode->data = new_data;


    newnode->next = *first;



    *first = newnode;
    count++;
}


void arrival(struct Node **head , int position)
{
    int tracker=1; // tracks the current node cur-> is pointing to
    int flag=0;


    struct Node *cur;


    if(*head == NULL){

        printf("list is empty");
        return;
    }


    if(position<1 || position > 10){

        printf("\n\nonly 10 Parking spot exist, enter anyone between them\n\n");
        return;

    }

    cur= *head;



    while(cur !=NULL && tracker != position){
            cur = cur->next;
            tracker++;
    }

    //if a spot is already occupied
    if(cur->data == 1){
            printf("This spot is already occupied\n");
            return ;
    }


    cur->data = 1;
    cars_parked++;
    flag++;
    printf("Car succesfully added at Spot no. %d\n", position);

}



void departure(struct Node **head, int position)
{
    struct Node *cur;
    int flag=0,tracker=1;

    if(*head == NULL){

        printf("list is empty");
        return;
    }

    cur= *head;

    if(position<1 || position >10)
    {
        printf("Invalid input choose between 1-10\n");
        return;
    }
     // if departing from first spot
    if(position == 1)
    {
        if(cur->data == 0){
                printf("The Spot is already Free\n\n");
                return ;
        }

        cur->data =0;
        flag++;
        cars_parked--;
        printf("Car succesfully departed from Spot no. %d\n", position);

        return;
    }

    else{
            while(cur !=NULL && tracker != position){

                cur = cur->next;
                tracker++;
            }
            if(cur->data == 0){
                    printf("The Spot is already Free\n\n");
            }

            else{
                    cur->data=0;
                    cars_parked--;
                    flag++;
            }
    }


    if(flag > 0){
            printf("Car succesfully departed from Spot no. %d\n", position);

    }

}



//status of every parking spot
void FreeOrNot(struct Node **head)
{

    struct Node *cur;
    int count=0;

    cur = *head;

    while(cur != NULL){

        count++;
        if(cur->data==0){
            printf("\nParking spot no %d : FREE\n",count);
        }

        else{
            printf("\nParking spot no %d : OCCUPIED\n",count);
        }

        cur = cur->next;
    }
}


int start()
{
	printf("\n\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
	printf("\t\t\xdb                                               \xdb\n");
	printf("\t\t\xdb       =============================           \xdb\n");
	printf("\t\t\xdb            CAR PARKING MANAGEMENT             \xdb\n");
	printf("\t\t\xdb       =============================           \xdb\n");
	printf("\t\t\xdb                                               \xdb\n");
	printf("\t\t\xdb       Brought To You By Khalid Farooq         \xdb\n");
    printf("\t\t\xdb                                               \xdb\n");
	printf("\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n\n");
	printf(" \n\t Press Any Key To Continue:");

	getch();
    system("cls");
    login();
}

void login()
{
	int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10]="user";
    char pass[10]="pass";
    do{

        printf("\n  \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb  LOGIN FIRST  \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb  ");
        printf(" \n\n                       ENTER USERNAME:-");
        scanf("%s", &uname);
        printf(" \n\n                       ENTER PASSWORD:-");

        while(i<10){

            pword[i]=getch();
            c=pword[i];

            if(c==13) break;

            else printf("*");

            i++;
        }

        pword[i]='\0';
	//char code=pword;
        i=0;
	//scanf("%s",&pword);
        if(strcmp(uname,"user")==0 && strcmp(pword,"pass")==0){

                printf("  \n\n\n       WELCOME !! YOUR LOGIN IS SUCCESSFUL");
                printf("\n\n\n\t\t\t\tPress any key to continue...");
                getch();//holds the screen
                break;
        }


        else{
                printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
                a++;

                getch();//holds the screen
        }
    }


	while(a<=2); //do nothing

	if (a>2){

	    printf("\nSorry you have entered the wrong username and password for four times!!!");

		getch();

    }

    system("cls");

}


int main()
{
    struct Node *first = NULL;
    int i,choice,pos;

    //clears the screen
    system ( "cls" ) ;

	start();

    //Initialising all nodes with zero

    for(i=0;i<10;i++){
        CreateAndallZero(&first,0);
    }


    while(1)
    {
        system("cls");
		 printf("\n  \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb  MAIN MENU  \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb  ");

        printf ( "\n\n\t1>> Current Status\n" );
		printf ( "\n\t2>> Adding a Car\n" );
		printf ( "\n\t3>> Total No. Of Cars Parked\n" );
		printf ( "\n\t4>> Departure Of Vehicle\n" );
		printf ( "\n\t5>> Exit\n" );
		printf ("\n\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb  \n");
		printf(" \n\n Enter Your Choice : ");
		scanf("%d", &choice);

		switch(choice)
		{

		    case 1:system("cls");
		    printf ( "\n\t\xdb\xdb\xdb\xdb\xdb\xdb STATUS \xdb\xdb\xdb\xdb\xdb\xdb \n" );
		        //Identify the free and occupied spots
		        FreeOrNot(&first);

                printf("\n\nPress any key to go back to main menu\n");
                getch();
                break;


		    case 2: system("cls");
				  printf ( "\n\t\xdb\xdb\xdb\xdb\xdb\xdb STATUS \xdb\xdb\xdb\xdb\xdb\xdb \n" );

                    //Identify the free and occupied spots
				  FreeOrNot(&first);


				  printf ( "\n\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb \n" );

				  printf("Enter the parking spot number to be occupied: \n");
				  scanf("%d",&pos);

				  //change data of the node at pos
				  //from zero to one
				  //where zero : Free
				  //One : Occupied

				  arrival(&first, pos);

				  printf("\n\nPress any key to go back to main menu\n");
				  getch();
				  break;

            case 3:
                system ( "cls" );
                printf ( "\n\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb \n" );

                printf("Number Cars parked : %d", cars_parked);
                printf("\n\nPress any key to go back to main menu\n");
                getch();
                break;


            case 4:

                system("cls");
                printf ( "\n\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb \n" );
                printf ( "\n\t\xdb\xdb\xdb\xdb\xdb\xdb STATUS \xdb\xdb\xdb\xdb\xdb\xdb \n" );


                 //Identify the free and occupied spots
                FreeOrNot(&first);

                printf("\n\nEnter the position of departed car: ");
                scanf("%d",&pos);

                //Change node->data from 1 to 0
                // that is from occupied to free
                departure(&first,pos);

                printf("\n\nPress any key to go back to main menu\n");
                getch();
                break;

            case 5: exit(0);

            default: printf("Invalid choice, Choose anyone from 1-5\n");
		}
    }
    return 0;
}




