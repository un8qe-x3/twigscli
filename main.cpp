#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Node {
public:
    string name;
    bool isFile;
    Node* parent;
    vector<Node*> children;
    Node(string name, bool isFile=false, Node* parent=nullptr)
        : name(name), isFile(isFile), parent(parent) {}
    Node* addChild(const string& childName, bool file=false) {
        Node* child = new Node(childName, file, this);
        children.push_back(child);
        return child;
    }
    void listChildren() {
        for (Node* child : children) {
            cout << (child->isFile ? "[F] " : "[D] ") << child->name << endl;
        }
    }
    ~Node() {
        for (Node* child : children)
            delete child;
    }
};
int main() {
    Node* root = new Node("root");
    Node* current = root;
    char inp;

    while (true) {
        cout << "\nCommands: (m) add, (l) list, (e) exit, (v) cout version then exit\n> ";
        cin >> inp;

        switch(inp) {
			case 'v':
				cout << "alpha 0.0.1\npatches: 0";
            case 'e':
                delete root;
                exit(0);
                break;

            case 'm': {
                string name;
                char type;
                cout << "Enter name: ";
                cin >> name;
                cout << "Is it a file? (y/n): ";
                cin >> type;
                bool isFile = (type == 'y' || type == 'Y');
                current->addChild(name, isFile);
                cout << "Added: " << name << (isFile ? " [mem]" : " [dir]") << endl;
                break;
            }
            case 'l':
                current->listChildren();
                break;
            default:
                cout << "Unknown command.\n";
        }
    }

    return 0;
}
