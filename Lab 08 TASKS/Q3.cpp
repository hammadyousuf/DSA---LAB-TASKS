#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

struct Student
{
    string name;
    int roll;
    int score;

    Student(string n = "", int r = 0, int s = 0)
    {
        name = n;
        roll = r;
        score = s;
    }
};

struct Node
{
    Student data;
    Node *left;
    Node *right;

    Node(Student s)
    {
        data = s;
        left = right = NULL;
    }
};

Node *insert(Node *root, Student s)
{
    if (root == NULL)
    {
        return new Node(s);
    }
    else
    {
        if (s.name < root->data.name)
        {
            root->left = insert(root->left, s);
        }
        else if (s.name > root->data.name)
        {
            root->right = insert(root->right, s);
        }
    }
    return root;
}

Node *findMin(Node *root)
{
    while (root != NULL && root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

Node *deleteByName(Node *root, string name)
{
    if (root == NULL)
    {
        return root;
    }
    else
    {
        if (name < root->data.name)
        {
            root->left = deleteByName(root->left, name);
        }
        else if (name > root->data.name)
        {
            root->right = deleteByName(root->right, name);
        }
        else
        {
            if (root->left == NULL)
            {
                return root->right;
            }
            else if (root->right == NULL)
            {
                return root->left;
            }
            else
            {
                Node *temp = findMin(root->right);
                root->data = temp->data;
                root->right = deleteByName(root->right, temp->data.name);
            }
        }
    }
    return root;
}

Node *deleteLowScores(Node *root, int minScore)
{
    if (root == NULL)
    {
        return NULL;
    }
    root->left = deleteLowScores(root->left, minScore);
    root->right = deleteLowScores(root->right, minScore);
    if (root->data.score < minScore)
    {
        root = deleteByName(root, root->data.name);
    }
    return root;
}

Node *search(Node *root, string name)
{
    if (root == NULL)
    {
        return NULL;
    }
    else
    {
        if (root->data.name == name)
        {
            return root;
        }
        else if (name < root->data.name)
        {
            return search(root->left, name);
        }
        else
        {
            return search(root->right, name);
        }
    }
}

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data.name << " (Roll: " << root->data.roll << ", Score: " << root->data.score << ")  ";
        inorder(root->right);
    }
}

void findmaximum_scorecore(Node *root, Student &maximum_score)
{
    if (root != NULL)
    {
        if (root->data.score > maximum_score.score)
        {
            maximum_score = root->data;
        }
        findmaximum_scorecore(root->left, maximum_score);
        findmaximum_scorecore(root->right, maximum_score);
    }
}

int main()
{
    Node *root = NULL;
    Student students[10] = {
        {"Hammad", 1, 12},
        {"Umer", 2, 8},
        {"Hamza", 3, 15},
        {"Ahmed", 4, 20},
        {"Zain", 5, 7},
        {"Musab", 6, 18},
        {"Shayan", 7, 25},
        {"Ali", 8, 5},
        {"Sufiyan", 9, 30},
        {"Usman", 10, 9}};

    for (int i = 0; i < 7; i++)
    {
        int index = rand() % 10;
        root = insert(root, students[index]);
    }

    cout << "\nStudents in BST (Inorder):\n";
    inorder(root);
    cout << endl;

    cout << "\nEnter name to search: ";
    string searchName;
    cin >> searchName;
    Node *result = search(root, searchName);
    if (result != NULL)
    {
        cout << "Found: " << result->data.name << " (Roll: " << result->data.roll << ", Score: " << result->data.score << ")" << endl;
    }
    else
    {
        cout << "Student not found." << endl;
    }

    root = deleteLowScores(root, 10);
    cout << "\nBST after deleting students with score < 10:\n";
    inorder(root);
    cout << endl;

    Student maximum_score("", 0, -1);
    findmaximum_scorecore(root, maximum_score);
    cout << "\nStudent with max score: " << maximum_score.name << " (Score: " << maximum_score.score << ")" << endl;

    return 0;
}
