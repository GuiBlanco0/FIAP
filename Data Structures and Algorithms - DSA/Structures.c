#include <stdio.h>
#include <string.h>

//Untested
struct Owner {
  char firstName[30];
  char lastName[30];
};

struct Car {
  char brand[30];
  int year;
  struct Owner owner; // Nested structure
};

int main() {
  struct Owner person = {"John", "Doe"};
  struct Car car1 = {"Toyota", 2010, person};
  struct Car car2 = {"Audi", 2020, person};

  strcpy(person.firstName, "Dani");
  strcpy(person.lastName, "Dani");

  struct Car car3 = {"Fusca", 1969, person};

  printf("Car: %s (%d)\n", car1.brand, car1.year);
  printf("Owner: %s %s\n", car1.owner.firstName, car1.owner.lastName);


  printf("Car: %s (%d)\n", car2.brand, car2.year);
  printf("Owner: %s %s\n", car2.owner.firstName, car2.owner.lastName);

  printf("Car: %s (%d)\n", car3.brand, car3.year);
  printf("Owner: %s %s\n", car3.owner.firstName, car3.owner.lastName);

  struct Car car4 = {"Ford", 2019,{"Maykon", "Boy"}};

  printf("Car: %s (%d)\n", car4.brand, car4.year);
  printf("Owner: %s %s\n", car4.owner.firstName, car4.owner.lastName);


  return 0;
}