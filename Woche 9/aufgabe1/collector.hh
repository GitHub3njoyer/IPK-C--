template <typename T>
class Collector
{
private:
    T betrag;
    T adder;

public:
    Collector(T betrag, T adder)
    {
        (*this).betrag = betrag;
        (*this).adder = adder;
    }
    void add(T x)
    {
        (*this).betrag = (*this).betrag + (*this).adder + x; 
    }
    T digest()
    {
        return (*this).betrag;
    }
};