class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> result;
        for(string exp: tokens){
            if(exp=="*"){
                int secondNumber=result.top();
                result.pop();
                int firstNumber=result.top();
                result.pop();

                int res=firstNumber*secondNumber;
                result.push(res);
            }
            else if(exp=="/"){
                int secondNumber=result.top();
                result.pop();
                int firstNumber=result.top();
                result.pop();

                int res=firstNumber/secondNumber;
                result.push(res);

            }
            else if(exp=="+"){
                int secondNumber=result.top();
                result.pop();
                int firstNumber=result.top();
                result.pop();

                int res=firstNumber+secondNumber;
                result.push(res);

            }
            else if(exp=="-"){
                int secondNumber=result.top();
                result.pop();
                int firstNumber=result.top();
                result.pop();

                int res=firstNumber-secondNumber;
                result.push(res);

            }
            else {
                int num=stoi(exp);
                result.push(num);
            }

        }
        return result.top();
    }
};