#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//creating a structure to store contact details
struct contact{
    char name[50];
    char designation[25];
    long int mobile_number;
    
    char email[50];
    

    

};
//creating function protostypes

void main_menu();
void add_contact();
void list_contact();
void edit_contact();
void search_contact();
void delete_contact();
// void got(char *name);


void main_menu() {
    printf("WELCOME TO PHONEBOOK\n");
    printf("Created by Irvin Cardoza\n");
    printf("Enter the number to choose from the following options\n");
    printf("1. Add Contact\n2. List Contacts\n3. Quit App\n4. Edit Contact\n5. Search Contact\n6. Delete contact\n");
    
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    // Consume any remaining characters in the input buffer
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    switch(choice) {
        case 1:
            add_contact();
            break;
        case 2:
            list_contact();
            break;
        case 3:
            exit(0);
            break;
        case 4:
            edit_contact();
            break;
        case 5:
            search_contact();
            break;
        case 6:
            delete_contact();
            break;
        default:
            printf("Enter number from 1 to 6\n");
            main_menu();
    }
}
void add_contact() {
    FILE* file;
    struct contact add;
    file = fopen("record.txt", "ab+");
    if (file == NULL) {
        printf("Error, record file not found!\n");
        return;
    }

    printf("\nEnter name: ");
    fgets(add.name, sizeof(add.name), stdin);
    add.name[strcspn(add.name, "\n")] = '\0';  // Remove newline character

    printf("\nEnter designation: ");
    fgets(add.designation, sizeof(add.designation), stdin);
    add.designation[strcspn(add.designation, "\n")] = '\0';  // Remove newline character

    printf("\nEnter mobile number: ");
    scanf("%ld", &add.mobile_number);
    // Consume newline character left by scanf
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    printf("\nEnter email: ");
    fgets(add.email, sizeof(add.email), stdin);
    add.email[strcspn(add.email, "\n")] = '\0';  // Remove newline character

    fwrite(&add, sizeof(add), 1, file);
    printf("\nSuccess!");
    fclose(file);
    printf("\nEnter any key to continue");
    getchar();
    main_menu();
}

//creating a function to list record of contacts

void list_contact(){
    struct contact add;
    FILE*file;
    file=fopen("record.txt","rb");
    if(file==NULL){
        printf("ERROR\n");
        return;
    }
    while(fread(&add,sizeof(add),1,file)==1){
        printf("Name=%s\nDesignation=%s\nMobile Number=%ld\nEmail=%s",add.name,add.designation,add.mobile_number,add.email);


    }
    fclose(file);
    printf("\nEnter any key to continue");
    getchar();
    getchar();
    main_menu();

}
void edit_contact(){
    NULL;

}
void search_contact(){
    NULL;

}
void delete_contact(){
    NULL;

}

int main() {
    main_menu();
    return 0;
}
