//
//  Calculator.cpp
//  冬奥会交易平台
//
//  Created by bb on 2022/2/22.
//

#include "calculator.h"

double Calculator::calculate(QString s){
    while(!operators.empty()){
        operators.pop();
    }
    while(!nums.empty()){
        nums.pop();
    }
    StandardFlag = true;
    auto isNum = [=](QChar c) -> bool{
        if((c >= '0' && c <= '9') || c == '.'){
            return 1;
        }
        return 0;
    };
    auto isOperator = [=](QChar c) -> bool{
        if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')' || c == ' '){
            return 1;
        }
        return 0;
    };
    QHash<QChar, int> levels;
    levels.insert('(',0);
    levels.insert('-',1);
    levels.insert('+',1);
    levels.insert('*',2);
    levels.insert('/',2);
   // {{'(',0},{'-',1},{'+',1},{'*',2},{'/',2}};
    int len = s.length();
    for(int i = 0; i < len; i++){
        if(!isNum(s[i]) && !isOperator(s[i])){
            StandardFlag = false;
            return 0;
        }
        double isMinus = 1;
        if((i == 0 || s[i-1] == '(') &&  s[i] == '-'){//deal with '-' value
            i++;
            isMinus = -1;
        }
        if(isNum(s[i])){
            QString num;
            while(isNum(s[i])){
                num += s[i];
                i++;
            }
            i--;
            nums.push(num.toDouble()*isMinus);
            continue;
        }
        QChar ch = s[i];
        if(ch == '('){
            operators.push(ch);
            continue;
        }else if(ch == ')'){
            if(operators.empty()){
                StandardFlag = false;
                return 0;
            }
            QChar sym = operators.top();
            operators.pop();
            while(sym != '('){
               if(sym == '+'){
                   if(nums.empty()){
                       StandardFlag = false;
                       return 0;
                   }
                   double num1 = nums.top();
                   nums.pop();
                   if(nums.empty()){
                       StandardFlag = false;
                       return 0;
                   }
                   double num2 = nums.top();
                   nums.pop();
                   nums.push(num1 + num2);
               }
               else if(sym == '-'){
                    if(nums.empty()){
                        StandardFlag = false;
                        return 0;
                    }
                    double num1 = nums.top();
                    nums.pop();
                    if(nums.empty()){
                        StandardFlag = false;
                        return 0;
                    }
                    double num2 = nums.top();
                    nums.pop();
                    nums.push(num2 - num1);
                }
                else if(sym == '*'){
                    if(nums.empty()){
                        StandardFlag = false;
                        return 0;
                    }
                    double num1 = nums.top();
                    nums.pop();
                    if(nums.empty()){
                        StandardFlag = false;
                        return 0;
                    }
                    double num2 = nums.top();
                    nums.pop();
                    nums.push(num2 * num1);

                }
                else if(sym == '/'){
                    if(nums.empty()){
                        StandardFlag = false;
                        return 0;
                    }
                    double num1 = nums.top();
                    nums.pop();
                    if(nums.empty()){
                        StandardFlag = false;
                        return 0;
                    }
                    double num2 = nums.top();
                    nums.pop();
                    if(fabs(num1 - 0) < 0.000001){
                        StandardFlag = false;
                        return 0;
                    }
                    nums.push(num2*1.0 / num1);
                }

                if(operators.empty()){//括号不匹配
                    StandardFlag = false;
                    return 0;
                }
                sym = operators.top();
                operators.pop();
            }
            continue;
        }else if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            while(!operators.empty() && levels[operators.top()] >= levels[ch]){
                QChar sym = operators.top();
                operators.pop();
                if(sym == '+'){
                    if(nums.empty()){
                        StandardFlag = false;
                        return 0;
                    }
                    double num1 = nums.top();
                    nums.pop();
                    if(nums.empty()){
                        StandardFlag = false;
                        return 0;
                    }
                    double num2 = nums.top();
                    nums.pop();
                    nums.push(num1 + num2);
                }
                else if(sym == '-'){
                     if(nums.empty()){
                         StandardFlag = false;
                         return 0;
                     }
                     double num1 = nums.top();
                     nums.pop();
                     if(nums.empty()){
                         StandardFlag = false;
                         return 0;
                     }
                     double num2 = nums.top();
                     nums.pop();
                     nums.push(num2 - num1);
                 }
                 else if(sym == '*'){
                     if(nums.empty()){
                         StandardFlag = false;
                         return 0;
                     }
                     double num1 = nums.top();
                     nums.pop();
                     if(nums.empty()){
                         StandardFlag = false;
                         return 0;
                     }
                     double num2 = nums.top();
                     nums.pop();
                     nums.push(num2 * num1);

                 }
                 else if(sym == '/'){
                     if(nums.empty()){
                         StandardFlag = false;
                         return 0;
                     }
                     double num1 = nums.top();
                     nums.pop();
                     if(nums.empty()){
                         StandardFlag = false;
                         return 0;
                     }
                     double num2 = nums.top();
                     nums.pop();
                     if(fabs(num1 - 0) < 0.000001){
                         StandardFlag = false;
                         return 0;
                     }
                     nums.push(num2*1.0 / num1);
                 }

            }
            operators.push(ch);
            continue;
        }


    }
    while(!operators.empty()){
        QChar sym = operators.top();
        operators.pop();
        if(sym == '+'){
            if(nums.empty()){
                StandardFlag = false;
                return 0;
            }
            double num1 = nums.top();
            nums.pop();
            if(nums.empty()){
                StandardFlag = false;
                return 0;
            }
            double num2 = nums.top();
            nums.pop();
            nums.push(num1 + num2);
        }
        else if(sym == '-'){
             if(nums.empty()){
                 StandardFlag = false;
                 return 0;
             }
             double num1 = nums.top();
             nums.pop();
             if(nums.empty()){
                 StandardFlag = false;
                 return 0;
             }
             double num2 = nums.top();
             nums.pop();
             nums.push(num2 - num1);
         }
         else if(sym == '*'){
             if(nums.empty()){
                 StandardFlag = false;
                 return 0;
             }
             double num1 = nums.top();
             nums.pop();
             if(nums.empty()){
                 StandardFlag = false;
                 return 0;
             }
             double num2 = nums.top();
             nums.pop();
             nums.push(num2 * num1);

         }
         else if(sym == '/'){
             if(nums.empty()){
                 StandardFlag = false;
                 return 0;
             }
             double num1 = nums.top();
             nums.pop();
             if(nums.empty()){
                 StandardFlag = false;
                 return 0;
             }
             double num2 = nums.top();
             nums.pop();
             if(fabs(num1 - 0) < 0.000001){
                 StandardFlag = false;
                 return 0;
             }
             nums.push(num2*1.0 / num1);
         }else{
            //有加减乘除外的符号
            StandardFlag = false;
            return 0;
         }


    }
    if(nums.size() != 1){
        StandardFlag = false;
        return 0;
    }
    return nums.top();
}
