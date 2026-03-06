#include <stdio.h>
#include <string.h>

struct myStructure {
    int myNum; char myLetter; char myString[30];
};
int main(){
    struct myStructure s1;
    s1.myNum = 15;
    s1.myLetter = "A";
    strcpy(s1.myString, "Some text");

    struct myStructure s2;
    s2 = s1;

    printf("%d %c %s", s2.myNum, s2.myLetter, s2.myString)






    return 0;
}



