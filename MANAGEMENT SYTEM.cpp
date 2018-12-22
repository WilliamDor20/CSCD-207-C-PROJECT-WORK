#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <iomanip>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

int main();
void MainMenu();
void  STD();
void coursegrading();

void enquiries(){
		int selnum;
		cout<<"	1.STUDENT\n\n 	2.STAFF\n\n	3.BACK\n\n";
		cout<<"ENTER YOUR CHOICE>>";
		cin>>selnum;
		
			switch(selnum){
		case 1: 
		system("cls");
		int s;
		cout<<"\t1.ACADEMIC RECORD\n	2.COUSRSES\n	3.BACK\n";
		cin>>s;
			switch(s){
				case 1:
					coursegrading();
					break;
				case 2:
				cout<<"COURSES: \n"<<endl;
			break;
			}
	break;
		case 2:
			system("cls");
		int sf;
	cout<<"1. PAYROLL\n";
		cin>>sf;
			switch(sf){
				case 1:
					system("cls");
					cout<<"COMING SOON!!!\n\n\n\n";
					enquiries();
				break;
				
			default:
				system("cls");
				cout<<"SELECT A VALID NUMBER";
				
				
			}
		
	break;		
		case 3:
			system("cls");
			MainMenu();
			break;
				default:
		cout<<"PLEASE SELECT A VALID NUMBER\n\n"<<endl;
		system("cls");
		MainMenu();
		
	};};


void STAFF(){
 FILE *fp, *ft;
    char another, choice;

    struct staff
    {
     char first_name[50];
		char  last_name[50];
        char department[50];
        char college[200];
        char gender[1];
       	int ID;
};
    struct staff e;
    char xfirst_name[100];
	char xlast_name[100];
	char xcollege[200];
	char xdepartment[50];
	char xgender[1];
	char xID;
    long int recsize;
    fp=fopen("staff.txt","rb+");

    if (fp == NULL)
    {
        fp = fopen("staff.txt","wb+");

        if (fp==NULL)
        {
            puts("CANNOT OPEN FILE");
            
        }
    }


    recsize = sizeof(e);

    while(1)
    {
        system("cls");
		cout<<"============================================================\n";
        cout << "\t\tSTAFF DATABASE MANAGEMENT SYSTEM\n";
        cout<<"============================================================\n\n";
        cout <<"\n\n                                          ";
        cout << "\n\n";
        cout << "\n \t\t\t 1. ADD	RECORDS";
        cout << "\n \t\t\t 2. DISPLAY	RECORDS";
        cout << "\n \t\t\t 3. MODIFY	RECORDS";
        cout << "\n \t\t\t 4. DELETE	RECORDS";
        cout << "\n \t\t\t 5. BACK 	TO	MAIN MENU";
        cout << "\n\n";
        cout << "\t\t\t SELECT YOUR CHOICE :=> ";
       
        choice = getchar();
        switch(choice)
        {
        case '1' :
            fseek(fp,0,SEEK_END);
            another ='Y';
            while(another == 'Y' || another == 'y')
            {
                system("cls");
                cout << "ENTER	THE	LAST NAME : ";
                cin >> e.last_name;
                cout << "ENTER OTHER NAME(S) : ";
                cin >> e.first_name;
                cout << "Enter the College    : ";
                cin >> e.college;
                cout << "Enter the Department   : ";
                cin >> e.department;
                fwrite(&e,recsize,1,fp);
                cout << "\n ADD ANOTHER RECORD?(Y/N) ";
                
                another = getchar();
            }
            break;
        case '2':
            system("cls");
            rewind(fp);
            cout << "=== RECORDS IN THE DATABASE ===";
            cout << "\n";
            while (fread(&e,recsize,1,fp) == 1)
            {
               cout << "\n";
                cout<<"STAFF ID: " <<e.ID<<endl;
                cout <<"STAFF NAME: " << e.first_name <<"	" << e.last_name;
                cout << "\n";
                cout<<"SEX: "<<e.gender<<endl;
                cout<<"COLLEGE: "<<e.college <<" "<<endl;
				cout<<"DEPARTMENT: "<<e.department<<endl;
				cout<<"---------------------------------------------------------\n";
            }
            cout << "\n\n";
            system("pause");
            break;

        case '3' :
            system("cls");
            another = 'Y';
            while (another == 'Y'|| another == 'y')
            {
                cout << "\n ENTER THE LAST NAME OF STAFF : ";
                cin >> xfirst_name;

                rewind(fp);
                while (fread(&e,recsize,1,fp) == 1)
                {
                    if (strcmp(e.last_name,xlast_name) == 0)
                    {
                        cout << "ENTER THE NEW LAST NAME : ";
                        cin >> e.last_name;
                        cout << "ENTER THE NEW OTHER NAME(S) : ";
                        cin >> e.first_name;
                        cout << "ENTER THE NEW COLLEGE    : ";
                        cin >> e.college;
                        cout << "ENTER THE NEW DEPARTMENT   : ";
                        cin >> e.department;
                        fseek(fp, - recsize, SEEK_CUR);
                        fwrite(&e,recsize,1,fp);
                        break;
                    }
                    else
                        cout<<"RECORD NOT FOUND!!!";
                }
                cout << "\n MODIFY ANOTHER RECORD? (Y/N) ";
                
                another = getchar();
            }
            break;


        case '4':
            system("cls");
            another = 'Y';
            while (another == 'Y'|| another == 'y')
            {
                cout << "\n ENTER THE LAST NAME OF STUDENT TO DELETE : ";
                cin >> xlast_name;

                ft = fopen("temp.dat", "wb");

                rewind(fp);
                while (fread (&e, recsize,1,fp) == 1)

                    if (strcmp(e.last_name,xlast_name) != 0)
                    {
                        fwrite(&e,recsize,1,ft);
                    }
                fclose(fp);
                fclose(ft);
                remove("staff.txt");
                rename("temp.dat","users.txt");

                fp=fopen("staff.txt","rb+");

                cout << "\n DELETE ANOTHER RECORD? (Y/N) ";
                
                another = getchar();
            }

            break;

        case '5':
            fclose(fp);
            cout << "\n\n";
            cout << "\t\t     THANK YOU FOR USING MY SOFTWARE";
            cout << "\n\n";
            system("cls");
            main();
            MainMenu();
            exit(0);
            
        }
    }

}
void courses(){
	
}
void coursegrading(){
struct course{
   char title;
   char code;
   double mark;
   char grade;
};

struct student{
   char name;
   int id;
   course courses[6];
};
		struct coursegrading ;
		double xmark;
		cout<<"ENTER STUDENT'S MARK HERE:  \n";
		cin>>xmark;
		double xGPT, xGPA;
		
	if (xmark <= 100 && xmark>=80){
	
		xGPT =12.0;
		cout<<"GRADE: A\n";
		cout<<"GPT:"<<xGPT;
		}
		else if(xmark >=75 && xmark <=79){
		
			xGPT = 10.50;
			cout<<"GRADE: B+\n";
			cout<<"GPT:"<<xGPT;
		}
		else if(xmark >= 70 && xmark <= 74){
		
			xGPT = 9.00;
			cout<<"GRADE: B\n";
			cout<<"GPT:"<<xGPT;
			}
		else if(xmark>=65 && xmark <= 69){
		
			xGPT=7.50;
			cout<<"GRADE: C+\n";
			cout<<"GPT:"<<xGPT;
			}
		else if(xmark >= 60 && xmark <= 64){
			
			xGPT=6.50;
			cout<<"GRADE: C\n";
			cout<<"GPT:"<<xGPT;	
			}
		else if(xmark>=55 && xmark<=59){
			
			xGPT=4.50;
			cout<<"GRADE: D+\n";
			cout<<"GPT:"<<xGPT;
			}
		else if(xmark>=50 && xmark<=54){
		
			xGPT=3.50;
			cout<<"GRADE: D\n";
			cout<<"GPT:"<<xGPT;
		}
		else if (xmark>=40 && xmark<=49){
			
			xGPT=0;
			cout<<"GRADE: E\n";
			cout<<"GPT:"<<xGPT;
		}
		else if(xmark<40){
			
			xGPT=0;
			cout<<"GRADE: F\n";
			cout<<"GPT:"<<xGPT;	
		}
		
		
		
		
		

}



	


void STD(){
	
    FILE *fp, *ft;
    char another, choice;

    struct student
    {
        char first_name[50];
		char  last_name[50];
        char degree[100];
        char programme[200];
        char gender[1];
        int age;
       	int ID;
       	char courses[6][1];
		
};
    

    struct student e;
    char xfirst_name[100];
	char xlast_name[100];
	char xprogramme[200];
	char xgender[1];
	int xage=0;
	char xcourses[6];
    long int recsize;

    fp=fopen("students.txt","rb+");

    if (fp == NULL)
    {
        fp = fopen("students.txt","wb+");

        if (fp==NULL)
        {
            puts("Cannot open file");
            
        }
    }


    recsize = sizeof(e);

    while(1)
    {
        system("cls");

        cout<<"============================================================\n";
		cout << "STUDENT DATABASE MANAGEMENT SYSTEM\n";
		cout<<"============================================================\n\n";
        cout <<"\n\n                                          ";
        cout << "\n\n";
           cout << "\n \t\t\t 1. ADD	RECORDS";
        cout << "\n \t\t\t 2. DISPLAY	RECORDS";
        cout << "\n \t\t\t 3. MODIFY	RECORDS";
        cout << "\n \t\t\t 4. DELETE	RECORDS";
        cout << "\n \t\t\t 5. BACK 	TO	MAIN MENU";
        cout << "\n\n";
        cout << "\t\t\t SELECT 	YOUR	CHOICE :=> ";
       
        choice = getchar();
        switch(choice)
        {
        case '1' :
            fseek(fp,0,SEEK_END);
            another ='Y';
            while(another == 'Y' || another == 'y')
            {
                system("cls");
                cout << "ENTER	THE	LAST	NAME : ";
                cin >> e.last_name;
                cout << "ENTER	THE	OTHER	NAME(S) : ";
                cin >> e.first_name;
                cout << "ENTER	THE	DEGREE	TYPE (BSc./BA/LLB etc)   : ";
                cin >> e.degree;
                cout << "ENTER	THE	PROGRAMME   : ";
                cin >> e.programme;
                cout<<"ENTER STUDENT'S GENDER:(M=MALE    F=FEMALE) "<<endl; 
				cin>>e.gender;
				cout<<"ENTER STUDENT'S AGE: "<<endl; 
				cin>>e.age;
                cout<<"ID	: "<<rand<<endl;
                cin>>e.ID;
                cout<<"ENTER COURSES: "<<endl;
				cout<<"1: \n"<<endl;	
				cin>>e.courses[0];
				cout<<"2: \n"<<endl;	
				cin>>e.courses[1];
				cout<<"3: \n"<<endl;	
				cin>>e.courses[2];
				cout<<"4: \n"<<endl;	
				cin>>e.courses[3];
				cout<<"5: \n"<<endl;	
				cin>>e.courses[4];
				cout<<"6: \n"<<endl;	
				cin>>e.courses[5]; 
                
                fwrite(&e,recsize,1,fp);
                cout << "\n ADD	ANOTHER	RECORD? (Y/N) ";
                
                another = getchar();
            }
            break;
        case '2':
            system("cls");
            rewind(fp);
            cout<<"============================================================\n";
			cout<<"RECORDS IN THE DATABASE\n";
			cout<<"============================================================\n";
            cout << "\n";
            while (fread(&e,recsize,1,fp) == 1)
            {
                cout << "\n";
                cout<<"STUDENT ID: " <<e.ID<<endl;
                cout <<"STUDENT NAME: " << e.first_name <<"	" << e.last_name;
                cout << "\n";
                cout<<"SEX: "<<e.gender<<endl;
                cout<<"PROGRAMME: "<<e.degree <<" "<<e.programme<<endl;
				cout<<"AGE: "<<e.age<<endl; cout<<"\n\n";
				cout<<"COURSES: \n"<<endl;
				cout<<" \n"<<e.courses[50]<<endl;
				cout<<" \n"<<e.courses[50]<<endl;
				cout<<" \n"<<e.courses[2]<<endl;
				cout<<" \n"<<e.courses[3]<<endl;
				cout<<" \n"<<e.courses[4]<<endl;
				cout<<" \n"<<e.courses[5]<<endl;
				
				cout<<"---------------------------------------------------------\n";
				
            }
            cout << "\n\n";
            system("pause");
            break;

        case '3' :
            system("cls");
            another = 'Y';
            while (another == 'Y'|| another == 'y')
            {
                cout << "\n ENTER THE LAST NAME OF STUDENT : ";
                cin >> xlast_name;

                rewind(fp);
                while (fread(&e,recsize,1,fp) == 1)
                {
                    if (strcmp(e.last_name,xlast_name) == 0)
                    {
                        cout << "ENTER THE NEW FIRST NAME : ";
                        cin >> e.first_name;
                        cout << "ENTER THE NEW LAST NAME : ";
                        cin >> e.last_name;
                        cout << "ENTER THE NEW DEGREE TYPE    : ";
                        cin >> e.degree;
                        cout << "ENTER THE NEW PROGRAMME   : ";
                        cin >> e.ID;
                        cout<<"ENTER NEW STUDENT'S GENDER:(M=MALE    F=FEMALE) "<<endl; 
						cin>>e.gender;
						cout<<"ENTER NEW STUDENT'S AGE: "<<endl; 
						cin>>e.age;
                		cout<<"ID	: "<<rand<<endl;
                		cin>>e.ID;
                		cout<<"ENTER NEW COURSES: "<<endl;
						cout<<"1: \n"<<endl;	
						cin>>e.courses[0];
						cout<<"2: \n"<<endl;	
						cin>>e.courses[1];
						cout<<"3: \n"<<endl;	
						cin>>e.courses[2];
						cout<<"4: \n"<<endl;	
						cin>>e.courses[3];
						cout<<"5: \n"<<endl;	
						cin>>e.courses[4];
						cout<<"6: \n"<<endl;	
						cin>>e.courses[5]; 
                        
						fseek(fp, - recsize, SEEK_CUR);
                        fwrite(&e,recsize,1,fp);
                        break;
                    }
                    else
                        cout<<"RECORD NOT FOUND!!!";
                }
                cout << "\n MODIFY ANOTHER RECORD? (Y/N) ";
                fflush(stdin);
                another = getchar();
            }
            break;


        case '4':
            system("cls");
            another = 'Y';
            while (another == 'Y'|| another == 'y')
            {
                cout << "\n ENTER THE LAST NAME OF STUDENT TO DELETE : ";
                cin >> xlast_name;

                ft = fopen("temp.dat", "wb");

                rewind(fp);
                while (fread (&e, recsize,1,fp) == 1)

                    if (strcmp(e.last_name,xlast_name) != 0)
                    {
                        fwrite(&e,recsize,1,ft);
                    }
                fclose(fp);
                fclose(ft);
                remove("students.txt");
                rename("temp.dat","users.txt");

                fp=fopen("students.txt","rb+");

                cout << "\n DELETE ANOTHER RECORD? (Y/N) ";
                fflush(stdin);
                another = getchar();
            }

            break;

        case '5':
            fclose(fp);
            cout << "\n\n";
            cout << "\t\t";
            cout << "\n\n";
            system("cls");
            main();
            MainMenu();
            exit(0);
            
        }
    }

}
void MainMenu(){
	int NumSel;
	cout<<"============================================================\n\n";
cout<<"	1.STUDENT MANAGEMENT\n\n 	2.STAFF MANAGEMENT\n\n	3.ENQUIRIES\n\n	4.EXIT PROGRAM\n\n";
cout<<"ENTER YOUR CHOICE>>";
cin>>NumSel;

	switch(NumSel){
		case 1: 
		system("cls");
		STD();
	break;
		case 2:
			system("cls");
		STAFF();
	break;
		case 3:
		system("cls");
		enquiries();
			break;		
		case 4:
			system("cls");
			system("exit");
			break;
				default:
		cout<<"PLEASE SELECT A VALID NUMBER\n\n"<<endl;
		system("cls");
		MainMenu();
		
	}}


int main()
{	
	cout<<"============================================================\n\n";
	cout<<"	THE NOBLE COLLEGE  \n\n	DATABASE MANAGEMENT SYSTEM\n";
	cout<<"============================================================\n\n";
	

	MainMenu();
    system("pause");
    return 0;
}
