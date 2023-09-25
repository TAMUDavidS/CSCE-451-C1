#include<iostream>
#include<unistd.h>   
#include "doSomething0.h"

using namespace std;

void loadingBar()
{
	system("clear");
	doSomething(); // hidden functionality
	char a = 177, b = 219;
	cout<<"\n\n\n\n\n\t\t\t\t\tStudent's Data Management System";
	cout<<"\n\t\t\t\t\tProject By Ajay Singh";
	cout<<"\n\t\t\t\t\tForked by Table 11 for CSCE 451, Educational purposes";
	cout<<"\n\n\n\t\t\t\t\tLoading...\n";
	cout<<endl;
	cout<<"\t\t\t\t\t";

	for(int i = 0; i < 5; i++)
	{
		sleep(1);
	}
	
}

