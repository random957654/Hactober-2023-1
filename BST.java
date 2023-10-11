
//Importing necessary Packages
import java.util.Scanner;
import java.util.InputMismatchException;

class Node {
    int data;
    Node left;
    Node right;

    // constructor for class Node
    Node(int data) {
        this.data = data;
        left = null;
        right = null;
    }
}

class BST {
    Node root;

    // To initialize a Empty tree
    BST() {
        root = null;
    }

    // function to insert data in Tree
    void insert(int data) {
        root = insertRec(root, data);
    }

    Node insertRec(Node root, int data) {
        if (root == null) {
            root = new Node(data);
            return root;
        }

        if (data < root.data) {
            root.left = insertRec(root.left, data);
        } else if (data > root.data) {
            root.right = insertRec(root.right, data);
        }

        return root;
    }

    // function to delete the data from tree
    void delete(int data) {
        root = deleteRec(root, data);
    }

    Node deleteRec(Node root, int data) {
        if (root == null) {
            return root;
        }

        if (data < root.data) {
            root.left = deleteRec(root.left, data);
        } else if (data > root.data) {
            root.right = deleteRec(root.right, data);
        } else {
            if (root.left == null) {
                return root.right;
            } else if (root.right == null) {
                return root.left;
            }
            root.data = minValue(root.right);
            root.right = deleteRec(root.right, root.data);
        }
        return root;
    }

    // function to find the minimum value in a tree
    int minValue(Node root) {
        int minVal = root.data;
        while (root.left != null) {
            minVal = root.left.data;
            root = root.left;
        }
        return minVal;
    }

    void inorder() {
        inorderRec(root);
    }

    // function to perform inorder Traversal in tree
    void inorderRec(Node root) {
        if (root != null) {
            inorderRec(root.left);
            System.out.print(root.data + " ");
            inorderRec(root.right);
        }
    }

    // function to perform Preorder Traversal in tree
    void preorder() {
        preorderRec(root);
    }

    void preorderRec(Node root) {
        if (root != null) {
            System.out.print(root.data + " ");
            preorderRec(root.left);
            preorderRec(root.right);
        }
    }

    // function to perform postorder Traversal in tree
    void postorder() {
        postorderRec(root);
    }

    void postorderRec(Node root) {
        if (root != null) {
            postorderRec(root.left);
            postorderRec(root.right);
            System.out.print(root.data + " ");
        }
    }

    // function to search Node in tree
    boolean search(int data) {
        return searchRec(root, data);
    }

    boolean searchRec(Node root, int data) {
        if (root == null) {
            return false;
        }

        if (root.data == data) {
            return true;
        } else if (data < root.data) {
            return searchRec(root.left, data);
        } else {
            return searchRec(root.right, data);
        }
    }

    public static void main(String[] args) {
        try (Scanner input = new Scanner(System.in)) {
            BST bst = new BST();
            int choice;
            do {
                System.out.println("1. Insert");
                System.out.println("2. Delete");
                System.out.println("3. Inorder Traversal");
                System.out.println("4. Preorder Traversal");
                System.out.println("5. Postorder Traversal");
                System.out.println("6. Search");
                System.out.println("7. Exit");
                System.out.println("Enter your choice:");
                choice = input.nextInt();
                switch (choice) {
                    case 1:
                        System.out.println("Enter value to insert:");
                        int value = input.nextInt();
                        bst.insert(value);
                        break;
                    case 2:
                        System.out.println("Enter value to delete:");
                        int delVal = input.nextInt();
                        bst.delete(delVal);
                        break;
                    case 3:
                        System.out.println("Inorder Traversal:");
                        bst.inorder();
                        System.out.println();
                        break;
                    case 4:
                        System.out.println("Preorder Traversal:");
                        bst.preorder();
                        System.out.println();
                        break;
                    case 5:
                        System.out.println("Postorder Traversal:");
                        bst.postorder();
                        System.out.println();
                        break;
                    case 6:
                        System.out.println("Enter value to search:");
                        int searchVal = input.nextInt();
                        boolean found = bst.search(searchVal);
                        if (found) {
                            System.out.println("found in the tree.");
                        } else {
                            System.out.println("Not found");
                        }
                        break;
                    case 7:
                        System.out.println("Exit done");
                        break;
                    default:
                        System.out.println("Invalid choice");
                }
            } while (choice != 7);
        } catch (InputMismatchException exception) {
            System.out.println(exception);
        } catch (Exception exception) {
            System.out.println(exception);
        }
    }
}