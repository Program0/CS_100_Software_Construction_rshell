#ifndef TEST_H
#define TEST_H
#include <iostream>
using namespace std;

int main() {
    Command* ls = new Command("ls -l");
    Command* cd = new Command("cd ~/marlo");
    Command* cat = new Command("cat myfile.txt");

    Or_Connector* && = new And_Connector(ls, cd);
    And_Connector* || = new And_Connector(&&, cat);

    cout << ||->execute() << endl;

    return 0;
}