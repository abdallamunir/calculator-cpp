/*
    Simple calculator
    requirements:
        - clear result
        -print result
        -add
        -substract
        -multiply
        -divide
*/
#include <iostream>
using namespace std;

class clsCalculator
{
private:
    float _Result;
    float _LastNumber;
    string _LastOperation = "Clear";
    float _PreviousResult = 0;

    bool _IsZero(float Number)
    {
        return (Number == 0);
    }

public:
    void Add(float Number)
    {
        _LastNumber = Number;
        _PreviousResult = _Result;
        _LastOperation = "Adding";
        _Result += Number;
    }

    void Substract(float Number)
    {
        _LastNumber = Number;
        _PreviousResult = _Result;
        _LastOperation = "Substracting";
        _Result -= Number;
    }

    void Multiply(float Number)
    {
        _LastNumber = Number;
        _PreviousResult = _Result;
        _LastOperation = "Multiplying";
        _Result *= Number;
    }

    void Divide(float Number)
    {
        _LastNumber = Number;
        if (-_IsZero(Number))
        {
            Number = 1;
        }
        _PreviousResult = _Result;
        _LastOperation = "Dividing";
        _Result /= Number;
    }

    float GetFinalResult()
    {
        return _Result;
    }

    void Clear()
    {
        _LastNumber = 0;
        _PreviousResult = 0;
        _LastOperation = "Clear";
        _Result = 0;
    }

    void CancelLastOperation()
    {
        _LastNumber = 0;
        _LastOperation = "Canceling Last Operation";
        _Result = _PreviousResult;
    }

    void PrintResult()
    {
        cout << "Result ";
        cout << "After " << _LastOperation << " " << _LastNumber << " is " << _Result << "\n";
    }
};


int main()
{
    clsCalculator Calculator1;

    Calculator1.Clear();

    Calculator1.Add(10);
    Calculator1.PrintResult();

    Calculator1.Add(100);
    Calculator1.PrintResult();

    Calculator1.Substract(20);
    Calculator1.PrintResult();

    Calculator1.Divide(0);
    Calculator1.PrintResult();

    Calculator1.Divide(2);
    Calculator1.PrintResult();

    Calculator1.Multiply(3);
    Calculator1.PrintResult();

    Calculator1.CancelLastOperation();
    Calculator1.PrintResult();

    Calculator1.Clear();
    Calculator1.PrintResult();
}

