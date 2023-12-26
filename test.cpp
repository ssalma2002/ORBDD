#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
class BDDNode {
public:
    BDDNode(char variable, BDDNode* low = nullptr, BDDNode* high = nullptr, BDDNode* parent = nullptr)
        : variable(variable), low(low), high(high) {
        if (parent != nullptr) {
            parents.push_back(parent);
        }
    }

    char getVariable() const {
        return variable; //Allows retrieving the variable associated with the node.
    }

private:
    char variable;
    BDDNode* low;
    BDDNode* high;
    vector<BDDNode*> parents; //A vector of pointers to parent nodes
};

class BDDUtil {
public:
    static std::vector<char> extractVariables(const string& stringExpression) { //Takes a string expression as input.
        istringstream iss(stringExpression);//Uses a istringstream (iss) to tokenize the input string.
        vector<char> variables;//
        string token;

        while (iss >> token) {//Iterates through the tokens, checking if each token is a single alphabetic character.If it is, and the character is not already in the variables vector, it adds it.
            if (token.size() == 1 && isalpha(token[0]) && find(variables.begin(), variables.end(), token[0]) == variables.end()) {
                variables.push_back(token[0]);
            }
        }

        sort(variables.begin(), variables.end());//After the loop, it sorts the variables vector to ensure a consistent order.
        return variables;//Returns the resulting vector of unique variables.
    }
    
};

int main() {
    string expression = "NOT A AND NOT B OR NOT A AND B OR A AND NOT B OR C OR A AND B";
    vector<char> result = BDDUtil::extractVariables(expression);

    cout << "Variables: ";
    for (char variable : result) {
        cout << variable << " ";
    }
    std::cout << std::endl;

    return 0;
}
