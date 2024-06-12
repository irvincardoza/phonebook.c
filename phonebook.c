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
    while (fread(&add, sizeof(add), 1, file) == 1) {
        printf("Name: %s\nDesignation: %s\nMobile Number: %ld\nEmail: %s\n\n",
               add.name, add.designation, add.mobile_number, add.email);
    }
    fclose(file);
    printf("\nEnter any key to continue");
    getchar();
    getchar();
    main_menu();

}
void edit_contact() {
    FILE *file;
    struct contact add, edit;
    int flag = 0;
    char name[50];
    file = fopen("record.txt", "rb+");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    printf("\nEnter contact name to edit: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';  // using fgets to avoid tab/space error
    
    while(fread(&add,sizeof(add),1,file)==1) {
        if(strcmp(name, add.name)==0){
            printf("\nEnter new name: ");
            fgets(edit.name, sizeof(edit.name),stdin);
            edit.name[strcspn(edit.name,"\n")] ='\0';// removes newline

            printf("\nEnter new designation: ");
            fgets(edit.designation,sizeof(edit.designation),stdin);
            edit.designation[strcspn(edit.designation,"\n")]='\0';  // removes newline

        printf("\nEnter new mobile number: ");
        scanf("%ld", &edit.mobile_number);
            // Consume newline char
            int c;
            while((c=getchar())!='\n'&& c!= EOF);

     printf("\nEnter new email: ");
            fgets(edit.email, sizeof(edit.email), stdin);
            edit.email[strcspn(edit.email, "\n")] = '\0';  // Remove newline character

        fseek(file, -sizeof(add), SEEK_CUR);
      fwrite(&edit, sizeof(edit), 1, file);
         flag = 1;
          printf("\nContact edited successfully!\n");
            break;
        }
    }
    if (!flag) {
        printf("Contact not found.\n");
    }
    fclose(file);
    printf("\nEnter any key to continue");
    getchar();
    main_menu();
}

void search_contact(){
    FILE*file;
    struct contact p;
    char name[100];
    file=fopen("record.txt","rb");
    if (file==NULL){
        printf("Error opening file\n");
        return;
    }
    printf("\nEnter name of contact to search...");
        fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';  // using fgets to avoid tab/space error
    int found=0;
    while(fread(&p,sizeof(p),1,file)==1){
        if(strcmp(p.name,name)==0){
            printf("\nHere's information about %s\n",name);
            printf("Name: %s\n Designation: %s\n Mobile number %ld\nEmail: %s\n",p.name,p.designation,p.mobile_number,p.email);
            found=1;
            break;
        }
    }
    fclose(file);
    if(!found){
        printf("Contact not found.\n");
    }
    printf("\n Enter any key to continue");
    getchar();
    getchar();
    main_menu();




}
void delete_contact() {
    FILE *file, *temp_file;
    struct contact current_contact;
    int found = 0;
    char name[50];
    
    file = fopen("record.txt", "rb");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    
    temp_file = fopen("temp.txt", "wb");
    if (temp_file == NULL) {
        printf("Error creating temporary file.\n");
        fclose(file);
        return;
    }
    
    printf("Enter the name of the contact you want to delete: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';  // Removing any trailing newline character
    
    while (fread(&current_contact, sizeof(current_contact), 1, file) == 1) {
        if (strcmp(name, current_contact.name) != 0) {
            fwrite(&current_contact, sizeof(current_contact), 1, temp_file);
        } else {
            found = 1;
        }
    }
    
    fclose(file);
    fclose(temp_file);
    
    if (!found) {
        printf("Contact not found.\n");
        remove("temp.txt");  // Deleting the temporary file
    } else {
        remove("record.txt");
        rename("temp.txt", "record.txt");
        printf("Contact deleted successfully.\n");
    }
    
    printf("\nEnter any key to continue...");
    getchar();
    getchar();
    main_menu();
}


int main() {
    main_menu();
    return 0;
}
