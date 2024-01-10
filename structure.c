#include <stdio.h>
//A Structure is a user defined data type that can be used to group elements of different types into a single type.
// Define a structure
struct {
    char *name;
}car1,car2;


struct book{
    char *name;
    char *author;
    int price;
};

struct abc{
    int p;
    int q;
};
//Typedef gives freedom to the user by allowing them to create their own types.
// Define a typedef
typedef int INTEGER;

//Typedef can also be used with structure to simplify the syntax
// Define a structure with typedef
typedef struct car{
    char *name;
    char *color;
    int price;
}car;


//Designated Initialization of Structure Members.
//Designated initialization allows you to initialize any member of a structure individually.
// Define a structure
struct student{
    char *name;
    int age;
    int roll_no;
};

int main(){
    // Assign values to structure members
    car1.name = "BMW sedan car";
    car2.name = "Benz sedan car";
    printf("Car1 name: %s\n",car1.name);
    printf("Car2 name: %s\n",car2.name);

    // Assign values to structure members using dot operator
    struct book book1;
    book1.name = "C programming";
    book1.author = "Dennis Ritchie";
    book1.price = 100;
    printf("Book1 name: %s\n",book1.name);
    printf("Book1 author: %s\n",book1.author);
    printf("Book1 price: %d\n",book1.price);


    // Assign values to structure members using array notation
    struct abc x={10,20};

    // Assign values to typedef
    INTEGER a = 10;
    printf("a = %d\n",a);

    // Assign values to structure with typedef
    car car3;       // car is a new data type
    car3.name = "Audi sedan car";
    car3.color = "Black";
    car3.price = 100000;
    printf("Car3 name: %s\n",car3.name);
    printf("Car3 color: %s\n",car3.color);
    printf("Car3 price: %d\n",car3.price);

    //Designated Initialization of Structure Members.
    struct student s1 = {.name = "John", .age = 21, .roll_no = 101};
    printf("Student name: %s\n",s1.name);
    printf("Student age: %d\n",s1.age);
    printf("Student roll_no: %d\n",s1.roll_no);



    return 0;
}
