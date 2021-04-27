#include <string>
#include "tstack.h"

int priority(char prior) {
switch (prior) {
case '(':
return 0;
break;
case ')':
return 1;
break;
case '+':
return 2;
break;
case '-':
return 2;
break;
case '/':
return 3;
break;
case '*':
return 3;
break;
default:
return -1;
}
}
int calculate(int first, int second, char chis) {
switch (chis) {
case '-':
return first - second;
break;
case '+':
return first + second;
break;
case '/':
return first / second;
break;
case '*':
return first * second;
break;	
default:
return -1;
}
}
std::string infx2pstfx(std::string inf) {
Tstack <char> steck;
char t = 0;
char ch;
int a;
std::string str;
for (int i = 0; i < inf.length(); i++) {
ch = inf[i];
a = priority(ch);
if (a > -1) {
if ((a == 0 || a > priority(t) || steck.isEmpty()) && ch != ')') {
if (steck.isEmpty())
t = ch;
steck.push(ch);
}
else if (ch == ')') {
while (stack.get() != '(') {
str.push_back(stack.get());
str.push_back(' ');
stack.pop();
}
stack.pop();
if (stack.isEmpty())
t = 0;
}
else {
while (!stack.isEmpty() && priority(stack.get()) >= a) {
str.push_back(stack.get());
str.push_back(' ');
stack.pop();
}
if (stack.isEmpty())
t = inf[i];
stack.push(inf[i]);
}
}
else {
str.push_back(ch);
str.push_back(' ');
}
}
while (!stack.isEmpty()) {
str.push_back(stack.get());
str.push_back(' ');
stack.pop();
}
str.erase(str.end() - 1, str.end());
return str;
}
int eval(std::string pst) {
TStack <int> stack;
int s;
int f;
int d;
int otv;
for (int i = 0; i < pst.size(); i++)
{
s = priority(pst[i]);
if (s == -1) stack.push(pst[i] - 48);
else {
f = stack.get();
stack.pop();
d = stack.get();
stack.pop();
otv = calculate(f, d, pst[i]);
stack.push(otv);
}
}
return stack.get();
}
