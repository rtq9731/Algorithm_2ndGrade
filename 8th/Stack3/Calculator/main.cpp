//구글 쌤의 도움을 받았읍니다.
//20402 권성빈

#include <iostream>
#include <string>
#include <stack>
#include <sstream>

using namespace std;

struct oper {
    int p; // 우선순위 변수
    string o; // 연산자 ex) '+', '*' 등
};

stack<int> num; // 숫자 스택
stack<oper> op; // 연산자 스택

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

    // 연산자 우선순위에 따라 스택에 push
    // 0 : ( )
    // 1 : + -
    // 2 : * /

    string splitInt;
    while (input.size() != 0) { // input의 크기가 0이 아니면 한번 더 반복;

        splitInt = input[0];
        input.erase(0, 1);

        // 만약에 '(' 이 splitInt에 들어왔다면 
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

            while (!op.empty() && prior <= op.top().p) // op 즉 연산자 스택이 비거나 지금 연산자의 연산자 우선순위가 더 낮아질 때까지 계산
                calculate();

            op.push({ prior, splitInt }); // 지금 남은 SplitInt를 연산자 스택에 넣음.
        }
        else
            num.push(stoi(splitInt));
    }

    while (!op.empty())
        calculate();

    std::cout << num.top();

    return 0;
}
