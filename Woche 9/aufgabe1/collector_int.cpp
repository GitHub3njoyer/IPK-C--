class Collector
{

private:
    int betrag;
    int adder;

public:
    Collector(int betrag, int adder)
    {
        (*this).betrag = betrag;
        (*this).adder = adder;
    }
    void add(int x)
    {
        (*this).betrag = (*this).betrag + (*this).adder + x;
    }
    
};