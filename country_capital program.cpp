/* Write an interactive, menu-driven program C program that will
accept the name of a country as input and display the corresponding capital, and vice versa.
Design the program so that it executes repeatedly, until the word End is
entered as input */
#include <stdio.h>
#include <stdlib.h> // system() , exit()
#include <string.h> // strcmp()
#include <windows.h>

#define MAX 100

void menu();
void input(int);
void color(short x) {
    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x); // windows.h
}

void header() {
	color(7); printf("\t\t\t\t\t----------------");
	color(14); printf(" Welcome!");
	color(7); printf("----------------\t\t\t\t\t\n");
  	color(11); printf("\t\t\t\tMenu driven program: Accept the name of a country as input\n\t\t\t\t and display the corresponding capital, and vice versa.\n\n");
	color(7); printf("\t\t\t\t\t------------------------------------------\t\t\t\t\t\n");
}

int main() {
  struct world {
    char country[30];
    char capital[30];

  };

  struct world country_capital_list[] = {
    "afghanistan","kabul",
    "albania","tirana",
    "algeria","algiers",
    "angola","luanda",
    "argentina","buenos aires",
    "armenia","yerevan",
    "australia","canberra",
    "austria","vienna",
    "azerbaijan","baku",
    "bahamas","nassau",
    "bangladesh","dhaka",
    "barbados","bridgetown",
    "belgium","brussels",
    "belize","belmopan",
    "benin","porto-novo",
    "bhutan","thimphu",
    "bosnia and herzegovina","sarajevo",
    "botswana","gaborone",
    "brazil","brasilia",
    "brunei","bandar seri begawan",
    "bulgaria","sofia",
    "burkina faso","ouagadougou",
    "burundi","gitega",
    "cabo verde","praia",
    "cambodia","phnom penh",
    "cameroon","yaounde",
    "canada","ottawa",
    "central african republic","bangui",
    "chile","santiago",
    "costa rica","san jose",
    "croatia","zagreb",
    "cuba","havana",
    "cyprus","nicosia",
    "czechia","prague",
    "denmark","copenhagen",
    "egypt","cairo",
    "estonia","tallinn",
    "fiji","suva",
    "finland","helsinki",
    "france","paris",
    "germany","berlin",
    "greece","athens",
    "hungary","budapest",
    "india","new delhi",
    "israel","jerusalem",
    "italy","rome",
    "japan","tokyo",
    "kosovo","pristina",
    "laos","vientiane",
    "madagascar","antananarivo",
    "malaysia","kuala lumpur",
    "maldives","male",
    "mexico","mexico city",
    "nepal","kathmandu",
    "netherlands","amsterdam",
    "new zealand","wellington",
    "nigeria","abuja",
    "north korea","pyongyang",
    "norway","oslo",
    "pakistan","islamabad",
    "panama","panama city",
    "papua new guinea","port moresby",
    "peru","lima",
    "philippines","manila",
    "poland","warsaw",
    "portugal","lisbon",
    "qatar","doha",
    "republic of china","beijing",
    "romania","bucharest",
    "russia","moscow",
    "samoa","apia",
    "saudi arabia","riyadh",
    "singapore","singapore",
    "slovakia","bratislava",
    "south korea","seoul",
    "switzerland","bern",
    "taiwan","taipei",
    "tajikistan","dushanbe",
    "tanzania","dodoma",
    "thailand","bangkok",
    "timor leste","dili",
    "togo","lome",
    "tonga","nuku'alofa",
    "turkey","ankara",
    "turkmenistan","ashgabat",
    "tuvalu","funafuti",
    "uganda","kampala",
    "ukraine","kyiv",
    "united arab emirates","abu dhabi",
    "united kingdom","london",
    "united states of america","washington, d.c",
    "uruguay","montevideo",
    "uzbekistan","tashkent",
    "vanuatu","port vila",
    "vatican city", "vatican city",
    "venezuela","caracas",
    "vietnam","hanoi",
    "yemen","sana'a",
    "zambia","lusaka",
    "zimbabwe","harare",
  };
  
  int choice, pos;
  char user_input[25], ch;

  header();
  // string is terminated with a null character \0 by default
  for (int k = 0; country_capital_list[k].country[0] != '\0'; ++k) {
    menu();
    scanf("%d", &choice); {
      if (choice == 3) {
        system("cls");
        continue;
      } else if (choice == 4) {
        printf("\nBye!");
        exit(0); //
      } else if ((choice != 1) && (choice != 2) && (choice != 3) && (choice != 4)) {
        printf("\nInvalid choice!\n");
      }
    }
    input(choice);
    scanf(" %[^\n]%*c", &user_input); // scan country or capital entered by user
    pos = -1;
    if (choice == 1) {
      for (int i = 0; i < MAX; i++) {
        if (strcmp(user_input, country_capital_list[i].country) == 0) // compare between user input and the elements inside the array, if matches, returns 0
        {
          pos = i; // position of the elements inside array, for example if user enters japan, i = 46 = pos
          // printf("%d", pos);
          printf("\nCapital = %s\n", country_capital_list[pos].capital);
          printf("Capital of %s is ", user_input); color(14); printf("%s", country_capital_list[pos].capital); color(15); printf(".\n");
        }
      }
      if (pos > -1) {
        printf("\nPress enter to continue...");
        scanf("%c", &ch);
      } else {
        printf("Not in database\n");
      }
    } // End of choice 1
    else if (choice == 2) {
      for (int i = 0; i < MAX; i++) {
        if (strcmp(user_input, country_capital_list[i].capital) == 0) {
          pos = i;
          printf("\nCountry = %s\n", country_capital_list[pos].country);
          printf("%s is the capital of ", user_input); color(14); printf("%s", country_capital_list[pos].country); color(15); printf(".\n");
        }
      }
      if (pos > -1) {
	    printf("\nPress enter to continue...");
		scanf("%c", &ch);
      } else {
        printf("Not in database\n");
      }
    } // End of choice 2 
  } // End of the for loop
} // End of main function

void menu() {
  color(7); printf("\nChoices:\n\t1. Country\n\t2. Capital\n\t3. Clear Screen\n\t4. Exit the program\n");
  printf("\nEnter your choice: ");
}

void input(int user_choice) {
  if (user_choice == 1) {
    printf("\t|Please enter in lowercase|\n");
    printf("\t\tEnter the name of the country: ");
  } else if (user_choice == 2) {
    printf("\t|Please enter in lowercase|\n");
    printf("\t\tEnter the name of the capital: ");
  } else if (user_choice >= 5) {
    printf("\t|Please choose between 1 to 4|\n\t\tEnter any characters then press enter to continue...");
  }
}
