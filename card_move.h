#ifndef CARD_MOVE_H
#define CARD_MOVE_H
#include "card.h"
    class CardMove : public Card {
private:
    std::string cardText;
    int locationNum = 0;
public:
    CardMove();
    void setAmount(int num);
    void setCardText(std::string text1);
    void cardAction(Bank* bank1, Player* player1);
    std::string getCardText(int num);
};
#endif
