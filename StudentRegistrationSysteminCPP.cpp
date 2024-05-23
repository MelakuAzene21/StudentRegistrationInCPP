#include <iostream>
#include <fstream> // for file handling
using namespace std;
int MAX_USERS;
struct Student
{
    int id;
    string name;
    char gender;
    Student() {}
   Student(int id, string name, char gender) : id(id), name(name), gender(gender) {}
};

struct Node
{
    Student data;
    Node *left;
    Node *right;
};

// Function to insert a student into the binary search tree
Node *insert(Node *root, Student student)
{
    if (root == nullptr)
    {
        root = new Node;
        root->data = student;
        root->left = root->right = nullptr;
    }
    else if (student.id < root->data.id)
    {
        root->left = insert(root->left, student);
    }
    else
    {
        root->right = insert(root->right, student);
    }
    return root;
}

// Function to search for a student by ID
Node *searchById(Node *root, int id)
{
    if (root == nullptr || root->data.id == id)
    {
        return root;
    }
    if (id < root->data.id)
    {
        return searchById(root->left, id);
    }
    else
    {
        return searchById(root->right,id);
    }
}

// Function to search for a student by name
Node *searchByName(Node *root, string name)
{
    if (root == nullptr || root->data.name == name)
    {
        return root;
    }
    Node *leftResult = searchByName(root->left, name);
    Node *rightResult = searchByName(root->right, name);
    if (leftResult != nullptr)
        return leftResult;
    return rightResult;
}

// Function to search for a student by all attributes
Node *searchByAttributes(Node *root, int id, string name, char gender)
{
    if (root == nullptr || (root->data.id == id && root->data.name == name && root->data.gender == gender))
    {
        return root;
    }
    Node *leftResult = searchByAttributes(root->left, id, name, gender);
    Node *rightResult = searchByAttributes(root->right, id, name, gender);
    if (leftResult != nullptr)
        return leftResult;
    return rightResult;
}

// Function to display all students
void displayAll(Node *root)
{
    if (root != nullptr)
    {
        displayAll(root->left);
        cout << "ID: " << root->data.id << ", Name: " << root->data.name << ", Gender: " << root->data.gender << endl;
        displayAll(root->right);
    }
}

// Function to display all male students
void displayMale(Node *root)
{
    if (root != nullptr)
    {
        displayMale(root->left);
        if (root->data.gender == 'M')
            cout << "ID: " << root->data.id << ", Name: " << root->data.name << ", Gender: " << root->data.gender << endl;
        displayMale(root->right);
    }
}

// Function to display all female students
void displayFemale(Node *root)
{
    if (root != nullptr)
    {
        displayFemale(root->left);
        if (root->data.gender == 'F')
            cout << "ID: " << root->data.id << ", Name: " << root->data.name << ", Gender: " << root->data.gender << endl;
        displayFemale(root->right);
    }
}

// Function to display the binary search tree in preorder
void displayPreorder(Node *root)
{
    if (root != nullptr)
    {
        cout << "ID: " << root->data.id << ", Name: " << root->data.name << ", Gender: " << root->data.gender << endl;
        displayPreorder(root->left);
        displayPreorder(root->right);
    }
}

// Function to display the binary search tree in inorder
void displayInorder(Node *root)
{
    if (root != nullptr)
    {
        displayInorder(root->left);
        cout << "ID: " << root->data.id << ", Name: " << root->data.name << ", Gender: " << root->data.gender << endl;
        displayInorder(root->right);
    }

}

// Function to display the binary search tree in postorder
void displayPostorder(Node *root)
{
    if (root != nullptr)
    {
        displayPostorder(root->left);
        displayPostorder(root->right);
        cout << "ID: " << root->data.id << ", Name: " << root->data.name << ", Gender: " << root->data.gender << endl;
    }
}

// Function to display the total number of students non-recursively
// Function to display the total number of students
int displayTotal(Node *root)
{
    int count = 0;
    if (root == nullptr)
        return count;

    Node *current = root;
    Node *temp;

    while (current != nullptr) {
        if (current->left == nullptr) {
            count++;
            current = current->right;
        } else {
            // Find the inorder predecessor of current node
            temp = current->left;
            while (temp->right != nullptr && temp->right != current) {
                temp = temp->right;
            }

            if (temp->right == nullptr) {
                temp->right = current;
                current = current->left;
            } else {
                temp->right = nullptr;
                count++;
                current = current->right;
            }
        }
    }

    return count;
}
// Function to find the maximum ID number
int findMaxId(Node *root)
{
    while (root->right != nullptr)
    {
        root = root->right;
    }
    return root->data.id;
}

// Function to find the minimum ID number
int findMinId(Node *root)
{
    while (root->left != nullptr)
    {
        root = root->left;
    }
    return root->data.id;
}


bool addUser(const Student& newUser) {
    for (int i = 0; i<MAX_USERS; ++i) {
        if (Student[i].id == newUser.id) {
           cout << "Please enter a unique ID." << endl;
            return false;
        }
    }
    Student[MAX_USERS++] = newUser;
    cout << "User added successfully." << endl;
    return true;
}

int main()
{
    Node *root = nullptr;

    int choice;
    int id;
    string name;
    char gender;
int MAX_USERS;
    do
    {
        // Main menu
        cout << "\nMain Menu:\n";
        cout << "1. Add New Student\n";
        cout << "2. Search Student\n";
        cout << "3. Display Information\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout<<"How Many Studentdo you want to Add";
        cin>>MAX_USERS;
Student stud[MAX_USERS];
int numUsers = 0;
        switch (choice)
        {
        case 1:
        {

    while (true) {
        Student newUser;
        cout << "Enter user ID: ";
        cin >> newUser.id;
        cout << "Enter user name: ";
        cin >> newUser.name;
        cout << "Enter user age: ";
        cin >> newUser.age;

        if (addUser(newUser)) {
            char choice;
            cout << "Do you want to add another user? (y/n): ";
            cin >> choice;
            if (choice != 'y' && choice != 'Y') {
                break;
            }
        }
    }


            /*// Add New Student
            cout << "\nEnter student ID: ";
            cin >> id;
            cout << "Enter student name: ";
            cin >> name;
            cout << "Enter student gender (M/F): ";
            cin >> gender;
            root = insert(root, Student(id, name, gender));
*/
            // File handling: append the new student data to the file
            ofstream file("students.txt", ios::app);
            if (file.is_open())
            {
                file << id << " " << name << " " << gender << endl;
                file.close();
            }
            else
            {
                cout << "Unable to open file.";
            }

            break;
        }
        case 2:
        {
            // Search Student Sub-menu
            do
            {
                cout << "\nSearch Student:\n";
                cout << "1. By ID\n";
                cout << "2.By Name\n";
                cout << "3. By All Attributes\n";
                cout << "4. Back to Main Menu\n";
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice)
                {

                case 1:
                {
                    // Search by ID
                    cout << "\nEnter student ID: ";
                    cin >> id;
                    Node *result = searchById(root, id);
                    system("cls");
                    if (result != nullptr)
                    {
                        cout << "Student found. Name: " << result->data.name << ", Gender: " << result->data.gender << endl;
                    }
                    else
                    {
                        cout << "Student not found." << endl;
                    }
                    break;
                }
                case 2:
                {
                    // Search by Name
                    cout << "\nEnter student Name: ";
                    cin >> name;
                    Node *result = searchByName(root, name);
                    system("cls");
                    if (result != nullptr)
                    {
                        cout << "Student found. ID: " << result->data.id << ", Gender: " << result->data.gender << endl;
                    }
                    else
                    {
                        cout << "Student not found." << endl;
                    }
                    break;
                }
                case 3:
                {
                    // Search by All Attributes
                    cout << "\nEnter student ID: ";
                    cin >> id;
                    cout << "Enter student name: ";
                    cin >> name;
                    cout << "Enter student gender (M/F): ";
                    cin >> gender;
                    Node *result = searchByAttributes(root, id, name, gender);
                    system("cls");
                    if (result != nullptr)
                    {
                        cout << "Student found. ID: " << result->data.id << ", Name: " << result->data.name << ", Gender: " << result->data.gender << endl;
                    }
                    else
                    {
                        cout << "Student not found." << endl;
                    }
                    break;
                }
                case 4:
                    break;
                default:
                    cout << "Invalid choice.\n";
                }
            } while (choice != 4);
            break;
        }
        case 3:
        {
            // Display Information Sub-menu

            do
            {
                cout << "\nDisplay Information:\n";
                cout << "1. All Students\n";
                cout << "2. All Male Students\n";
                cout << "3. All Female Students\n";
                cout << "4. Display in Preorder\n";
                cout << "5. Display in Inorder\n";
                cout << "6. Display in Postorder\n";
                cout << "7. Total Number of Students\n";
                cout << "8. Maximum ID Number\n";
                cout << "9. Minimum ID Number\n";
                cout << "10. Back to Main Menu\n";
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice)
                {
                case 1:
                    cout << "\nAll Students:\n";
                    displayAll(root);
                    break;
                case 2:
                    cout << "\nAll Male Students:\n";
                    displayMale(root);
                    break;
                case 3:
                    cout << "\nAll Female Students:\n";
                    displayFemale(root);
                    break;
                case 4:
                    cout << "\nDisplaying in Preorder:\n";
                    displayPreorder(root);
                    break;
                case 5:
                    cout << "\nDisplaying in Inorder:\n";
                    displayInorder(root);
                    break;
                case 6:
                    cout << "\nDisplaying in Postorder:\n";
                    displayPostorder(root);
                    break;
                case 7:
                    cout << "\nTotal number of students: " << displayTotal(root) << endl;
                    break;
                case 8:
                    cout << "\nMaximum ID number: " << findMaxId(root) << endl;
                    break;
                case 9:
                    cout << "\nMinimum ID number: " << findMinId(root) << endl;
                    break;
                case 10:
                    break;
                default:
                    cout << "Invalid choice.\n";
                }
            } while (choice != 10);
            break;
        }
        case 4:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}

