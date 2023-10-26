class Dice {
  public:
    Dice(int sides) {
      _sides = sides;
    }

   void doThrow() {
      _value = random(1, _sides);  // add throw
      
    }

    int getValue() {
      return _value;
    }

    int getSides() {
      return _sides;
    }

  private:
    int _sides;
    int _value;
};