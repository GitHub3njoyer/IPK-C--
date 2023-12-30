class Temperatur
{

private:

    double Kelvin;

public:

    Temperatur();
    Temperatur(double Kelvinwert);
    double getKelvin() const;
    double getCelsius() const;
    double getFahrenheit() const;
    double add(double kelvinWert);
};