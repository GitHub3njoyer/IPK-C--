template <typename T1, typename T2, typename T3>
class Triplet {
    private:
        T1 firstValue;
        T2 secondValue;
        T3 thirdValue;
    public:
        Triplet (T1 firstValue, T2 secondValue, T3 thirdValue) {
            (*this).firstValue = firstValue;
            this -> secondValue = secondValue;
            this -> thirdValue = thirdValue;
        }    
        T1 first() {
            return this -> firstValue;
        }
        T2 second() {
            return this -> secondValue;
        }
        T3 third() {
            return this -> thirdValue;
        }
        void setFirst(T1 value) {
            this -> firstValue = value;
        }
        void setSecond(T2 value) {
            this -> secondValue = value;
        }
        void setThird(T1 value) {
            this -> thirdValue = value;
        }
};