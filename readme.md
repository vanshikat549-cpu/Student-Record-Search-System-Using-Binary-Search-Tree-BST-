# Student Record Search System Using Binary Search Tree (BST)

## 1. Project Overview

The Student Record Search System is a menu-driven application developed using the C programming language and a Binary Search Tree (BST).

The system stores student records containing:

* Enrolment ID
* Student Name
* Department

The enrolment ID is used as the key to organize student records in the BST.

The project demonstrates insertion, searching, deletion, tree traversals, duplicate ID handling, and the effect of insertion order on tree efficiency.

## 2. Objectives

* To understand the Binary Search Tree data structure.
* To insert student records into a BST.
* To search for students using enrolment IDs.
* To delete student records while maintaining BST properties.
* To reject duplicate enrolment IDs.
* To display records in sorted order using inorder traversal.
* To implement inorder, preorder, and postorder traversals.
* To compare balanced-looking and sorted insertion orders.
* To understand average-case and worst-case time complexity.

## 3. Technologies Used

* Programming Language: C
* Data Structure: Binary Search Tree
* Compiler: GCC
* Code Editor: Visual Studio Code

## 4. Features

1. Insert a student record.
2. Search for a student using an enrolment ID.
3. Delete a student record.
4. Display records in ascending enrolment-ID order.
5. Perform preorder traversal.
6. Perform postorder traversal.
7. Insert ten sample student records.
8. Compare insertion orders using key comparisons.
9. Reject duplicate enrolment IDs.

## 5. Binary Search Tree Property

A Binary Search Tree follows these rules:

* Values smaller than a node's key are stored in its left subtree.
* Values larger than a node's key are stored in its right subtree.
* Duplicate keys are not allowed.

These properties allow the system to organize and search student records.

## 6. Algorithms Used

### Insertion

The program compares the enrolment ID with existing nodes and inserts the new record at the correct position.

### Searching

The program compares the required enrolment ID with the current node and moves left or right until the record is found or the search fails.

### Deletion

The program handles three cases:

* Deleting a leaf node.
* Deleting a node with one child.
* Deleting a node with two children.

### Tree Traversals

* Inorder: Left, Root, Right.
* Preorder: Root, Left, Right.
* Postorder: Left, Right, Root.

Inorder traversal displays records in ascending enrolment-ID order.

## 7. Menu Options

| Option | Description              |
| ------ | ------------------------ |
| 1      | Insert Student           |
| 2      | Search Student           |
| 3      | Delete Student           |
| 4      | Inorder Traversal        |
| 5      | Preorder Traversal       |
| 6      | Postorder Traversal      |
| 7      | Insert 10 Sample Records |
| 8      | Compare Insertion Orders |
| 9      | Exit                     |

## 8. Time Complexity

Let n be the number of nodes in the BST.

| Operation           | Average Case | Worst Case |
| ------------------- | ------------ | ---------- |
| Insertion           | O(log n)     | O(n)       |
| Searching           | O(log n)     | O(n)       |
| Deletion            | O(log n)     | O(n)       |
| Inorder Traversal   | O(n)         | O(n)       |
| Preorder Traversal  | O(n)         | O(n)       |
| Postorder Traversal | O(n)         | O(n)       |

A regular BST may become skewed if records are inserted in sorted order. In that situation, searching, insertion, and deletion may take O(n) time.

A self-balancing tree, such as an AVL tree, maintains a balanced structure and supports these operations in O(log n) time.

## 9. Space Complexity

The BST requires O(n) space to store n student records.

Recursive operations require additional stack space proportional to the height of the tree, O(h).

## 10. Limitations

* Student records are stored in memory.
* Records are not permanently saved after the program exits.
* The BST does not automatically balance itself.
* Performance may decrease when the tree becomes skewed.

## 11. Future Improvements

* Add file handling to save records permanently.
* Implement an AVL tree.
* Add an update-student-record option.
* Display the height of the BST.
* Compare BST performance with AVL trees.
* Add a graphical user interface.

## 12. Conclusion

This project demonstrates the implementation of a Binary Search Tree for managing student records in C.

It provides practical experience with insertion, searching, deletion, recursion, tree traversals, pointers, dynamic memory allocation, and algorithmic complexity.

The comparison of insertion orders demonstrates how the shape of a BST affects its efficiency.
