//���� ���� ������ �޾����ϴ�.
//20402 �Ǽ���

#include <iostream>
#include <string>
#include <stack>
#include <sstream>

using namespace std;

struct oper {
    int p; // �켱���� ����
    string o; // ������ ex) '+', '*' ��
};

stack<int> num; // ���� ����
stack<oper> op; // ������ ����

void calculate() {
    int a, b, result;
    b = num.top();
    num.pop();
    a = num.top();
    num.pop();
    string oper = op.top().o;
    op.pop();

    if (oper == "*")
        result = a * b;
    else if (oper == "/")
        result = a / b;
    else if (oper == "+")
        result = a + b;
    else if (oper == "-")
        result = a - b;

    num.push(result);
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.tie(NULL);

    string input;
    cin >> input;

    // ������ �켱������ ���� ���ÿ� push
    // 0 : ( )
    // 1 : + -
    // 2 : * /

    string splitInt;
    while (input.size() != 0) { // input�� ũ�Ⱑ 0�� �ƴϸ� �ѹ� �� �ݺ�;

        splitInt = input[0];
        input.erase(0, 1);

        // ���࿡ '(' �� splitInt�� ���Դٸ� 
        if (splitInt == "(") {
            op.push({ 0, splitInt });
        }
        else if (splitInt == ")") {
            while (op.top().o != "(")
                calculate();
            op.pop();
        }

        else if (splitInt == "*" || splitInt == "/" || splitInt == "+" || splitInt == "-") {
            int prior;
            if (splitInt == "*")
                prior = 2;
            else if (splitInt == "/")
                prior = 2;
            else if (splitInt == "+")
                prior = 1;
            else if (splitInt == "-")
                prior = 1;

            while (!op.empty() && prior <= op.top().p) // op �� ������ ������ ��ų� ���� �������� ������ �켱������ �� ������ ������ ���
                calculate();

            op.push({ prior, splitInt }); // ���� ���� SplitInt�� ������ ���ÿ� ����.
        }
        else
            num.push(stoi(splitInt));
    }

    while (!op.empty())
        calculate();

    std::cout << num.top();

    return 0;
}
