#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QStack>
#include "datastructure.h"
#include <QHash>
class Calculator{
public:
    Calculator(){
        while(!operators.empty()){
            operators.pop();
        }
        while(!nums.empty()){
            nums.pop();
        }
        StandardFlag = true;
    }
    double calculate(QString s);//count the result
    bool isStandard(){
        return StandardFlag;
    }//judge if standard
private:
    QStack<QChar> operators;
    QStack<double> nums;
    bool StandardFlag;
};

#endif // CALCULATOR_H
