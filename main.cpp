#include "Func.h"

int main() {
    pNode tree = nullptr;
    char data[] = "(1+(2+3)*(4+5/6))+2*3*(4-6)";
    int n = strlen(data)-1;
    cout << data;
    tree = makeTree(data , 0 , n);
    cout << '=' << calcTree(tree) << endl;
    return 0;
}
