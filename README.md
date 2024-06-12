# Phonebook Project 📞📖

Welcome to the Phonebook Project! This C-based application allows users to manage contacts efficiently. With functionalities like adding, listing, editing, searching, and deleting contacts, it's a comprehensive tool for handling contact information.

## Features

- **Add Contact**: Save new contact details.
- **List Contacts**: Display all saved contacts.
- **Edit Contact**: Modify existing contact details (functionality to be implemented).
- **Search Contact**: Find a contact by name (functionality to be implemented).
- **Delete Contact**: Remove a contact from the list (functionality to be implemented).

## Getting Started

Follow these steps to set up and run the Phonebook project on your local machine.

### Prerequisites

Ensure you have the following installed:

- GCC (GNU Compiler Collection)
- Make (optional, for automated build process)

### Installation

1. **Clone the repository**:
    ```sh
    git clone https://github.com/yourusername/phonebook.git
    cd phonebook
    ```

2. **Compile the program**:
    ```sh
    gcc -o phonebook phonebook.c
    ```

3. **Run the program**:
    ```sh
    ./phonebook
    ```

### Usage

Upon running the program, you will be presented with a menu:

WELCOME TO PHONEBOOK
Created by Irvin Cardoza
Enter the number to choose from the following options:

Add Contact
List Contacts
Quit App
Edit Contact
Search Contact
Delete Contact


Select the desired option by entering the corresponding number.

### File Structure

```plaintext
phonebook/
├── phonebook.c     # Main source code file
├── record.txt      # File to store contacts (created at runtime)
├── README.md       # Project documentation
```

Contact Structure
Each contact has the following details:

Name: The contact's name
Designation: The contact's job title or role
Mobile Number: The contact's phone number
Email: The contact's email address
Functions
main_menu(): Displays the main menu and handles user input.
add_contact(): Adds a new contact to the record file.
list_contact(): Lists all contacts from the record file.
edit_contact(): Edits an existing contact (to be implemented).
search_contact(): Searches for a contact by name (to be implemented).
delete_contact(): Deletes a contact from the record file (to be implemented).

Contributing
Contributions are welcome! Please follow these steps to contribute:

Fork the repository.
Create a new branch (git checkout -b feature-branch).
Make your changes and commit them (git commit -m 'Add new feature').
Push to the branch (git push origin feature-branch).
Open a pull request.

Acknowledgments
Thanks to Irvin Cardoza for creating this project.
