#ifndef CLASS_CARD_SPEC
#define CLASS_CARD_SPEC

class Card {
public:
  enum Card_rank { RANKNONE = 0, TWO = 1, THREE = 2, FOUR = 3, FIVE = 4, SIX = 5, SEVEN = 6, EIGHT = 7, NINE = 8, TEN = 9, JACK = 10, QUEEN = 11, KING = 12, ACE = 13 };
  enum Card_suit { SUITNONE = 0, SPADES = 1, CLUBS = 2, DIAMONDS = 3, HEARTS = 4 };
  Card();
  void set_rank(Card_rank);          
  void set_suit(Card_suit);           
  Card_rank get_rank() const;           // Returns cards rank
  Card_suit get_suit() const;           // Returns cards suit
private:
  Card_suit the_suit;               	// The cards suit
  Card_rank the_rank;               	// The cards rank
};

#endif
