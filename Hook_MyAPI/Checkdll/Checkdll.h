
class Checkdll
{
public:
    Checkdll();
    ~Checkdll();

    typedef int (WINAPI *AddProc)(int a,int b);
    AddProc add;

    void AddReal(int a,int b);
};

