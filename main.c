#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
int enrolmentID;
char name[50];
char department[50];
struct Student *left;
struct Student *right;
};

int comparisons = 0;

// Create a new student node
struct Student* createStudent(int id, char name[], char department[])
{
struct Student *newNode = (struct Student*)malloc(sizeof(struct Student));

if (newNode == NULL)
{
    printf("Memory allocation failed!\n");
    exit(1);
}

newNode->enrolmentID = id;
strcpy(newNode->name, name);
strcpy(newNode->department, department);
newNode->left = NULL;
newNode->right = NULL;

return newNode;

}

// Search for a student
struct Student* search(struct Student *root, int id)
{
while (root != NULL)
{
comparisons++;

    if (id == root->enrolmentID)
        return root;
    else if (id < root->enrolmentID)
        root = root->left;
    else
        root = root->right;
}

return NULL;

}

// Insert a student into the BST
struct Student* insert(struct Student *root, int id, char name[], char department[])
{
if (root == NULL)
return createStudent(id, name, department);

comparisons++;

if (id < root->enrolmentID)
    root->left = insert(root->left, id, name, department);
else if (id > root->enrolmentID)
    root->right = insert(root->right, id, name, department);
else
    printf("Duplicate enrolment ID! Record not inserted.\n");

return root;


}

// Inorder traversal: Left, Root, Right
void inorder(struct Student *root)
{
if (root != NULL)
{
inorder(root->left);

    printf("ID: %d | Name: %s | Department: %s\n",
           root->enrolmentID, root->name, root->department);

    inorder(root->right);
}

}

// Preorder traversal: Root, Left, Right
void preorder(struct Student *root)
{
if (root != NULL)
{
printf("ID: %d | Name: %s | Department: %s\n",
root->enrolmentID, root->name, root->department);


    preorder(root->left);
    preorder(root->right);
}

}

// Postorder traversal: Left, Right, Root
void postorder(struct Student *root)
{
if (root != NULL)
{
postorder(root->left);
postorder(root->right);

    printf("ID: %d | Name: %s | Department: %s\n",
           root->enrolmentID, root->name, root->department);
}

}

// Find the smallest node in a subtree
struct Student* findMin(struct Student *root)
{
while (root != NULL && root->left != NULL)
root = root->left;

return root;


}

// Delete a student from the BST
struct Student* deleteStudent(struct Student *root, int id)
{
struct Student *temp;

if (root == NULL)
    return NULL;

comparisons++;

if (id < root->enrolmentID)
    root->left = deleteStudent(root->left, id);
else if (id > root->enrolmentID)
    root->right = deleteStudent(root->right, id);
else
{
    // Case 1: Leaf node
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }

    // Case 2: Node has only a right child
    else if (root->left == NULL)
    {
        temp = root->right;
        free(root);
        return temp;
    }

    // Case 2: Node has only a left child
    else if (root->right == NULL)
    {
        temp = root->left;
        free(root);
        return temp;
    }

    // Case 3: Node has two children
    else
    {
        temp = findMin(root->right);

        root->enrolmentID = temp->enrolmentID;
        strcpy(root->name, temp->name);
        strcpy(root->department, temp->department);

        root->right = deleteStudent(root->right, temp->enrolmentID);
    }
}

return root;

}

// Insert 10 sample student records
struct Student* loadSampleRecords(struct Student *root)
{
int ids[] = {50, 30, 70, 20, 40, 60, 80, 10, 35, 65};

char names[10][50] = {
    "Aman", "Priya", "Rahul", "Simran", "Karan",
    "Neha", "Rohit", "Anjali", "Vikas", "Pooja"
};

char departments[10][50] = {
    "CSE", "ECE", "IT", "CSE", "IT",
    "ECE", "CSE", "IT", "ECE", "CSE"
};

int i;
int inserted = 0;

for (i = 0; i < 10; i++)
{
    if (search(root, ids[i]) == NULL)
    {
        root = insert(root, ids[i], names[i], departments[i]);
        inserted++;
    }
}

printf("%d sample records inserted successfully.\n", inserted);

return root;

}

// Free all nodes in a tree
void freeTree(struct Student *root)
{
if (root != NULL)
{
freeTree(root->left);
freeTree(root->right);
free(root);
}
}

// Compare balanced-looking and sorted insertion orders
void compareInsertionOrders()
{
int balancedOrder[] = {40, 20, 60, 10, 30, 50, 70};
int sortedOrder[] = {10, 20, 30, 40, 50, 60, 70};

struct Student *tree1 = NULL;
struct Student *tree2 = NULL;

char name[] = "Student";
char department[] = "CSE";

int i;
int balancedComparisons;
int sortedComparisons;

comparisons = 0;

for (i = 0; i < 7; i++)
    tree1 = insert(tree1, balancedOrder[i], name, department);

balancedComparisons = comparisons;

comparisons = 0;

for (i = 0; i < 7; i++)
    tree2 = insert(tree2, sortedOrder[i], name, department);

sortedComparisons = comparisons;

printf("\n--- Insertion Order Comparison ---\n");
printf("Balanced-looking order comparisons: %d\n", balancedComparisons);
printf("Sorted order comparisons: %d\n", sortedComparisons);

printf("\nBalanced-looking order creates a shorter tree.\n");
printf("Sorted order creates a skewed tree.\n");

freeTree(tree1);
freeTree(tree2);


}

int main()
{
struct Student *root = NULL;
struct Student *result;

int choice;
int id;

char name[50];
char department[50];

do
{
    printf("\n===== STUDENT RECORD SEARCH SYSTEM =====\n");
    printf("1. Insert Student\n");
    printf("2. Search Student\n");
    printf("3. Delete Student\n");
    printf("4. Inorder Traversal (Sorted Records)\n");
    printf("5. Preorder Traversal\n");
    printf("6. Postorder Traversal\n");
    printf("7. Insert 10 Sample Records\n");
    printf("8. Compare Insertion Orders\n");
    printf("9. Exit\n");

    printf("Enter your choice: ");

    if (scanf("%d", &choice) != 1)
    {
        printf("Invalid input!\n");
        while (getchar() != '\n');
        continue;
    }

    switch (choice)
    {
        case 1:
            printf("Enter enrolment ID: ");

            if (scanf("%d", &id) != 1)
            {
                printf("Invalid enrolment ID!\n");
                while (getchar() != '\n');
                break;
            }

            result = search(root, id);

            if (result != NULL)
            {
                printf("Duplicate enrolment ID! Record not inserted.\n");
                break;
            }

            printf("Enter student name: ");
            scanf(" %49[^\n]", name);

            printf("Enter department: ");
            scanf(" %49[^\n]", department);

            root = insert(root, id, name, department);
            printf("Student inserted successfully.\n");
            break;

        case 2:
            printf("Enter enrolment ID to search: ");

            if (scanf("%d", &id) != 1)
            {
                printf("Invalid enrolment ID!\n");
                while (getchar() != '\n');
                break;
            }

            comparisons = 0;
            result = search(root, id);

            if (result != NULL)
            {
                printf("\nStudent Found!\n");
                printf("Enrolment ID: %d\n", result->enrolmentID);
                printf("Name: %s\n", result->name);
                printf("Department: %s\n", result->department);
            }
            else
                printf("Student record not found.\n");

            printf("Search comparisons: %d\n", comparisons);
            break;

        case 3:
            printf("Enter enrolment ID to delete: ");

            if (scanf("%d", &id) != 1)
            {
                printf("Invalid enrolment ID!\n");
                while (getchar() != '\n');
                break;
            }

            result = search(root, id);

            if (result == NULL)
                printf("Student record not found.\n");
            else
            {
                root = deleteStudent(root, id);
                printf("Student deleted successfully.\n");
            }

            break;

        case 4:
            if (root == NULL)
                printf("No student records available.\n");
            else
            {
                printf("\n--- Inorder Traversal ---\n");
                inorder(root);
            }
            break;

        case 5:
            if (root == NULL)
                printf("No student records available.\n");
            else
            {
                printf("\n--- Preorder Traversal ---\n");
                preorder(root);
            }
            break;

        case 6:
            if (root == NULL)
                printf("No student records available.\n");
            else
            {
                printf("\n--- Postorder Traversal ---\n");
                postorder(root);
            }
            break;

        case 7:
            root = loadSampleRecords(root);
            break;

        case 8:
            compareInsertionOrders();
            break;

        case 9:
            freeTree(root);
            printf("Program exited successfully.\n");
            break;

        default:
            printf("Invalid choice! Please try again.\n");
    }

} while (choice != 9);

return 0;

}
