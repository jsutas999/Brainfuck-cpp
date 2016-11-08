#include <iostream>
#include <fstream>


using namespace std;

class BrainFuck
{
private:
    char* program;
    char*  line;
    char*  _pL;
    char* _pP;
    char* ptrLastPosition;

    int d;

    void ResetLine()
    {
        for(int i = 0 ; i < 1000; i++)
            line[i] = 0;
    }

    void ClearMemory()
    {
        delete[] this->program;
        delete[] this->line;
    }


    void InitialiseAndRun()
    {
        ResetLine();
        _pL = &line[0];
        _pP = &program[0];
        d = 0;
        Run();

    }

    void Run()
    {
        while(_pP !=  ptrLastPosition)
            Execute();
    }

    void ptl()
    {
        _pL--;
    }
    void ptr()
    {
        _pL++;
    }
    void inc()
    {
        ++*_pL;
    }
    void dec()
    {
        --*_pL;
    }
    void output()
    {
        cout << *_pL << " ";
    }
    void input()
    {
        cin >> *_pL;
    }
    void openB()
    {

        if(*_pL == 0)
        {

            _pP++;

            int pd = d - 1;
            while(d != pd)
            {
                if(*_pP == '[') d++;
                else if(*_pP == ']') d--;
                _pP++;
            }
            _pP--;
            return;
        }
        d++;
    }

    void closeB()
    {
        int pd = d+1;
        _pP--;
        while(pd != d)
        {
            if(*_pP == '[') d++;
            else if(*_pP == ']') d--;
            _pP--;
        }
        d--;

    }

    void Execute()
    {
        switch(*_pP)
        {
        case '>':
            ptr();
            break;
        case '<':
            ptl();
            break;
        case '+':
            inc();
            break;
        case '-':
            dec();
            break;
        case '.':
            output();
            break;
        case ',':
            input();
            break;
        case '[':
            openB();
            break;
        case ']':
            closeB();
            break;
        default:
            return;
        }
        _pP++;
    }

public:
    void  LoadAndRunFromFile(const char* filename)
    {
        ifstream in(filename);
        ptrLastPosition = &program[0];
        char* ptrStart = &program[0];

        while(!in.eof())
            in >> *ptrLastPosition++;

        ptrLastPosition--;

        in.close();
        InitialiseAndRun();

    }

    void LoadAndRunFromMemory(char* yes)
    {
        //TODO
    }

    BrainFuck()
    {
        this->program = new char[3000];
        this->line = new char[1000];
    }

    ~BrainFuck()
    {
        ClearMemory();
    }

};

int main()
{
    BrainFuck fk;
    fk.LoadAndRunFromFile("test.txt");
    return 0;

}
