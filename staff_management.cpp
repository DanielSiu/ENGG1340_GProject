#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Employee {// the structure of type 'Employee' which carries the data the employee  and also two pointers pointing to the previous and next employee
  string name;
  string id;
  string age;
  string role;
  char sex;
  int salary;
  Employee * next;
  Employee * previous;
};

void printinfo(Employee * current){// The input is the pointer which corresponds to the pointer of Employee that we have to print the data of
  cout<<setfill(' ');              // print the data of employee in a stadardised format
  cout<<setw(15)<<current->name<<setw(15)<<current->id<<setw(15)<<current->age<<setw(15)<<current->role<<setw(15)<<current->sex<<setw(20)<<current->salary<<endl;
}

void print_all(Employee * head) {// The input is the pointer head , which is the first node of the doubly-linked list
  Employee * current = head;     // This function prints all the data of the Employee inputed into the databse in a standardised format
  cout<<setfill(' ');            // pointer 'current' is used to transverse from the linked list holding all the data
  cout<<setw(15)<<"Name"<<setw(15)<<"id"<<setw(15)<<"Age"<<setw(15)<<"Role"<<setw(15)<<"Sex"<<setw(20)<<"Salary"<<endl;
  cout<<setfill('-');
  cout<<setw(96)<<""<<endl;
  while (current != NULL) {      // keep printing data until the end of the linked list is reached
    printinfo(current);
    cout<<endl;
    current = current->next;    // Proceed to the next pointer available
  }
}

void printmessage() {// print the Menu of the staff-management system
  cout << setfill('*');
  cout<<setw(46)<<""<<endl;
  cout<<setw(46)<<""<<endl;
  cout<<endl;
  cout<<"Menu is listed below: "<<endl;
  cout<<endl;
  cout<<" Please choose the coresponding number "<<endl;
  cout<<endl;
  cout<<" Please choose your actions: "<<endl;// show all the availbale commands to user
  cout<<endl;
  cout<<"   1. create "<<endl;
  cout<<"   2. search "<<endl;
  cout<<"   3. delete "<<endl;
  cout<<"   4. edit "<<endl;
  cout<<"   5. search_salary "<<endl;
  cout<<"   6. print_all "<<endl;
  cout<<"   7. exit "<<endl;
  cout<<endl;

}

void create (Employee * &head, Employee * &tail) {// This function accepts the head and tail of the linked list to build the list of Employee continuously
  Employee * current = new Employee;// create an empty 'Employee' for data input
  cout<<endl;
  cout<<"  Please insert name: ";// Let user input all the data
  cin>>current->name;
  cout<<"  Please insert id: ";
  cin>>current->id;
  cout<<"  Please insert age: ";
  cin>>current->age;
  cout<<"  Please insert role: ";
  cin>>current->role;
  cout<<"  Please insert sex: ";
  cin>>current->sex;
  cout<<"  Please insert salary: ";
  cin>>current->salary;

  current->next = NULL;// set both ends of the newly created Employee to NULL type
  current->previous = NULL;

  if (head == NULL) {// condition when this is the first Employee created
    head = current;
    tail = current;
  }

  else {
    tail->next = current;// link the tail of the newly created Employee to the linked list
    current->previous = tail;// link the previous pointer of the employee to the employee beforehand
    tail = current;
  }
  cout<<endl;
  cout<<"  New Employee created !"<<endl;//notify the user that the new 'Employee' is created

}

Employee * search(Employee * &head, Employee *current) {// This function accept the head and a temporary part of the linked list to search through all the items of the linked list until the search target is reached
  current = head;                                       // And this function returns a pointer that is being searched for
  int choice;//temparary variable to store which action the user choose
  string item;// temporary variable to store a string type
  int object;// temporary variable to store a int type
  char subject;// temporary variable to store a charactor type
  cout<<endl;
  cout<<" Catergories that can be searched: "<<endl;// print out the menu for search function
  cout<<endl;
  cout<<"  1. name "<<endl;
  cout<<"  2. id "<<endl;
  cout<<"  3. age "<<endl;
  cout<<"  4. role "<<endl;
  cout<<"  5. sex "<<endl;
  cout<<"  6. salary"<<endl;
  cout<<endl;
  cout<<"  Please choose type: ";
  cin >> choice;
  cout<<"  Item to be searched: ";

  if (choice == 1 || choice == 2 || choice == 3 || choice == 4 ) {// for string type variable input
    cin>>item;

    if (choice == 1) {// search in for member 'name'
      while ( current != NULL) {
        if (current->name == item) {
          return current;

        }
        current->previous = current;// proceed to the next item in the linked list
        current = current->next;
      }
    }

    if (choice == 2) {// search in for member 'id'
      while ( current != NULL) {
        if (current->id == item) {
          return current;

        }
        current->previous = current;
        current = current->next;
      }
    }

    if (choice == 3) {// search in for member 'age'
      while ( current != NULL) {
        if (current->age == item) {
          return  current;

        }
        current->previous = current;
        current = current->next;
      }
    }

    if (choice == 4) {// search in for member 'role'
      while ( current != NULL) {
        if (current->role == item) {
          return current;

        }
        current->previous = current;
        current = current->next;
      }
    }

   }

    else if (choice == 5) {// search in for member 'sex'
      cin>>subject;
      while ( current != NULL) {
        if (current->sex == subject) {
          return current;

        }
        current->previous = current;
        current = current->next;
      }
    }

  else if (choice == 6) {// search in for member 'salary'
    cin>>object;
    while ( current != NULL) {
      if (current->salary == object) {
        return  current;
      }
      current->previous = current;
      current = current->next;
    }

  }

  current = nullptr;// if no item that is to be searched is satisfied, set the pointer to a NULL pointer
  return current;// and return it

}

void del(Employee * &head, Employee * current) {// This function delete a pointer from the linked-list by receiving the head pointer as well as a variable pointer 'current'

  Employee *buffer, * target;// buffer refers to the pointer that is before the item to be deleted, target is the pointer to be deleted
  target = search(head,current);// find the pointer to be deleted bt reusing the search function
  if (target == head && head != NULL) {// check if the pointer to be deleted is head or is the first pointer in the linked list
    cout<<endl;
    head = head->next;// point the head pointer to the next item in the linked list
    cout<<"  Item successfully deleted!"<<endl;
    delete(target);
  }

  else if (target == NULL) {// If the target is not found output error message
    cout<<endl;
    cout<<"  Invalid Input!"<<endl;

  }
  else {// when the pointer is neither a head nor the first item in the linked list nor is not found
    cout<<endl;
    buffer = target->previous;//locate the position of the previous pointer
    buffer->next = target->next;//link the previous ponter to the pointer that comes next to the target
    cout<<"  Item successfully deleted!"<<endl;// output successful message
    delete (target);
  }

}

void edit(Employee * &head, Employee * current) {// This function accepts head pointer and the pointer to be edited
  Employee * target;                             // target is to find the item in the linked list to be edited
  int command;//temparary variable to store the user command
  string item;// temporary variable to store a string type
  int object;// temporary variable to store a int type
  char subject;// temporary variable to store a charactor type

  target = search (head,current);// search for the desired target to be edited
  cout<<endl;
  if (target != NULL) {// if target is found
    cout<<"  Which type would you like to edit:"<<endl;// output menu options
    cout<<endl;
    cout<<"  1. name"<<endl;
    cout<<"  2. id"<<endl;
    cout<<"  3. age"<<endl;
    cout<<"  4. role"<<endl;
    cout<<"  5. sex"<<endl;
    cout<<"  6. salary"<<endl;
    cout<<"  7. exit"<<endl;
    cout<<endl;
    cout<<"  What is your command: ";
    cin>>command;
    cout<<endl;
    while (command != 7) {

      if (command == 1) {//edit name

        cout<<"  New Name: ";
        cin>>item;
        cout<<endl;
        cout<<"  Name is being changed from "<<target->name;
        target->name = item;
        cout<<" to "<<target->name<<endl;
        cout<<endl;
      }

      if (command == 2) {//edit id
        cout<<endl;
        cout<<"  New id: ";
        cin>>item;
        cout<<endl;
        cout<<"  id is being changed from "<<target->id;
        target->id = item;
        cout<<" to "<<target->id<<endl;
        cout<<endl;
      }

      if (command == 3) {//edit age
        cout<<endl;
        cout<<"  New age: ";
        cin>>item;
        cout<<endl;
        cout<<"  Age is being changed from "<<target->age;
        target->age = item;
        cout<<" to "<<target->age<<endl;
        cout<<endl;
      }

      if (command == 4) {//edit role
        cout<<endl;
        cout<<"  New role: ";
        cin>>item;
        cout<<endl;
        cout<<"  Role is being changed from "<<target->role;
        target->role = item;
        cout<<" to "<<target->role<<endl;
        cout<<endl;
      }

      if (command == 5) {//edit sex
        cout<<endl;
        cout<<"  New sex: ";
        cin>>subject;
        cout<<endl;
        cout<<"  Sex is being changed from "<<target->sex;
        target->sex = subject;
        cout<<" to "<<target->sex<<endl;
        cout<<endl;
      }

      if (command == 6) {//edit salary
        cout<<endl;
        cout<<"  New salary: ";
        cin>>object;
        cout<<endl;
        cout<<"  Salary is being changed from "<<target->salary;
        target->salary = object;
        cout<<" to "<<target->salary<<endl;
        cout<<endl;
      }

    cout<<"  What more data would u like to edit:"<<endl;// give to option to continuously edit data as long as the exit command is not executed
    cout<<endl;
    cout<<"  1. name"<<endl;
    cout<<"  2. id"<<endl;
    cout<<"  3. age"<<endl;
    cout<<"  4. role"<<endl;
    cout<<"  5. sex"<<endl;
    cout<<"  6. salary"<<endl;
    cout<<"  7. exit"<<endl;
    cout<<endl;
    cout<<"  What is your command: ";
    cin>>command;
   }
  }

  else {
    cout<<"  No valid item to be edited"<<endl;// output error message if the item to be edited is not found
  }

}

void search_salary(Employee * &head) {// this function accepts the head pointer of the linked list and search for salary with conditions set by the user
  Employee * current = head;//set a pointer that helps transverse through the linked list
  int amount,command;// amount is the salary the user inputed to set as a condition, command store the command user choose
  cout<<endl;
  cout<<"  Search for salary that is: "<<endl;// print out the menu
  cout<<endl;
  cout<<"    1. Lower"<<endl;
  cout<<"    2. Higher"<<endl;
  cout<<"    3. The Same"<<endl;
  cout<<"    4. exit"<<endl;
  cout<<endl;
  cout<<"  What is your command: ";
  cin>>command;
  cout<<endl;
  while (command != 4) {//keep looping until exit command is executed
    cout<<" Amount of salary to be search: ";
    cin>>amount;
    cout<<endl;
    cout<<setfill(' ');
    cout<<setw(15)<<"Name"<<setw(15)<<"id"<<setw(15)<<"Age"<<setw(15)<<"Role"<<setw(15)<<"Sex"<<setw(20)<<"Salary"<<endl;//print out a table shaped thingy
    cout<<setfill('-');
    cout<<setw(96)<<""<<endl;
    if (command == 1) {// search by salary that is lower
      while (current != NULL) {// keep on printing out data of desired salary
        if ((current->salary) < amount ) {
          printinfo(current);
        }
        current = current->next;
      }
    }

    if (command == 2) {// search by salary that is higher
      while (current != NULL) {
        if ((current->salary) > amount ) {
          printinfo(current);
        }
        current = current->next;
      }
    }

    if (command == 3) {// search by salary that is the same
      while (current != NULL) {
        if (current->salary == amount ) {
          printinfo(current);
        }
        current = current->next;
      }
    }
    cout<<endl;
    cout<<setfill('-');
    cout<<setw(96)<<""<<endl;
    cout<<endl;
    cout<<"  Continue to search for salary that is: "<<endl;// give the option to continuously search for salary until exit command is encountered
    cout<<endl;
    cout<<"    1. Lower"<<endl;
    cout<<"    2. Higher"<<endl;
    cout<<"    3. The Same"<<endl;
    cout<<"    4. exit"<<endl;
    cout<<endl;
    cout<<"  What is your command: ";
    cin>>command;
    current = head;// reset the current pointer for the next iteration


  }

}

int main() {
  Employee * head = NULL, * tail = NULL, * current;// initalise the head tail of the linked list, current pointer is just a temporary pointer for transversing
  int command=0;//initialize command variable
  cout << setfill('*');// print out welcoming message
  cout << setw(46) <<""<<endl;
  cout << setw(46) <<""<<endl;
  cout << "*****" <<" Welcome to staff-management system " << "*****"<<endl;
  cout << setw(46) <<""<<endl;
  cout << setw(46) <<""<<endl;
  cout<<endl;
  cout<<"Instruction is listed below: "<<endl;// print out instructions
  cout<<endl;
  cout<<"  1. create     --  Create an employee"<<endl;
  cout<<"  2. search     --  Search for an employee with given data"<<endl;
  cout<<"  3. delete     --  Delete data of an employee"<<endl;
  cout<<"  4. edit       --  Edit information of an employee"<<endl;
  cout<<"  5. search_all --  Search for Employee based on given salary amount"<<endl;
  cout<<"  6. print_all  --  Print all data of employee from data-base"<<endl;
  cout<<"  7. exit       --  Exit from staff-management system"<<endl;
  cout<<endl;
  printmessage();
  cout<<" What is your command: ";// get command input
  cin>>command;
  while (command != 7) {//keep looping until exit command is executed


    if (command < 1 || command > 7) {//check if the command is valid or not
      cout<<endl;
      cout<<"  Invalid input !"<<endl;//print out error message
      cout<<"  Please choose a number between 1 to 7 and try again"<<endl;
      cout<<endl;
      printmessage();
      cout<<" What is your command: ";
      cin>>command;
      continue;//restart the input process
    }

    else {
      if (command == 1) {// create command
      create(head,tail);
      }

      else if (command == 2) {//search command
        current = search(head,current);
        if (current != NULL) {
          cout<<setfill(' ');
          cout<<setw(15)<<"Name"<<setw(15)<<"id"<<setw(15)<<"Age"<<setw(15)<<"Role"<<setw(15)<<"Sex"<<setw(20)<<"Salary"<<endl;
          cout<<setfill('-');
          cout<<setw(96)<<""<<endl;
          printinfo(current);
        }
        else {//print that item is not found
          cout<<endl;
          cout<<"  Item not Found! "<<endl;
        }
      }

      else if (command == 3) {//delete command
        del(head,current);
      }

      else if (command == 4) {// edit command
        edit(head,current);
      }

      else if (command == 5) {// search salary command
        search_salary(head);
      }

      else if (command == 6) {// print all command
        print_all(head);
      }
    }

    cout<<endl;
    printmessage();
    cout<<" What is your command: ";
    cin>>command;

 }
 cout<<endl;
 cout<<"  Bye Bye! Have a nice Day :)"<<endl;//output message after termination execution

}
