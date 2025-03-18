#include <iostream>
#include <string>
using namespace std;


struct Node {
    string data;           
    Node* children[10];    
    int childCount;        

    
    Node(string value) {
        data = value;
        childCount = 0;
        for (int i = 0; i < 10; ++i) {
            children[i] = nullptr;
        }
    }
};


void addChild(Node* parent, const string& childData ) {
    if (parent->childCount < 10) { 
        parent->children[parent->childCount] = new Node(childData);
        parent->childCount++;
    } else {
        cout << "Error: Maximum child limit reached for \"" << parent->data << "\"." << endl;
    }
}
void printTree(Node* root, int level = 0) {
    if (!root) return;
    for (int i = 0; i < level; ++i) {
        cout << "  ";
    }
    cout << root->data << endl;
    for (int i = 0; i < root->childCount; ++i) {
        printTree(root->children[i], level + 1);
    }
}
void constructTree(Node* parent) {
    int numChildren;
    cout << "Enter the number of children for \"" << parent->data << "\" (max 10): ";
    cin >> numChildren;
    cin.ignore(); 

    if (numChildren > 10) {
        cout << "Error: Maximum of 10 children allowed. Adjusting to 10." << endl;
        numChildren = 10;
    }
    for (int i = 0; i < numChildren; ++i) {
        string childData;
        cout << "Enter the name of child " << i + 1 << " of \"" << parent->data << "\": ";
        getline(cin, childData);
        addChild(parent, childData);
        constructTree(parent->children[parent->childCount - 1]);
    }
}

int main() {
    string bookTitle;
    cout << "Enter the title of the book: ";
    getline(cin, bookTitle);
    Node* book = new Node(bookTitle);
    constructTree(book);
    cout << "\nBook Structure:" << endl;
    printTree(book);
    return 0;
}

