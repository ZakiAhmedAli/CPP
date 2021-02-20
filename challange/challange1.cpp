#include <stdio.h>
#include <vector>
#include <string>

typedef struct
{
	 char * title;
	 char * author;
	 char * publisher;
	 char * subject;
	 char * isbn;
	 char * oclc;
	 short int ddc1;
	 short int ddc2;
	 short int year_pub;
	 short int year_acq;
	 short int quantity;

}Libirary_c;
int main()
{

Libirary_c card={"C++ Book","Zaki","New Riders","CGI (Computer network protocol)",
				 "1562055712 9781562055714", "477166381",510, 78, 1996, 1997, 2};


printf("Title: %s\n", card.title);
printf("Author: %s\n", card.author);
printf("Publisher: %s\n", card.publisher);
printf("Subject: %s\n", card.subject);
printf("ISBN: %s\n", card.isbn);
printf("WorldCat (OCLC): %s\n", card.oclc);
printf("Dewey Decimal: %d.%d\n", card.ddc1, card.ddc2);
printf("Year published: %d\n", card.year_pub);
printf("Year acquired: %d\n", card.year_acq);
printf("Quantity: %d\n", card.quantity);
return(0);
}



