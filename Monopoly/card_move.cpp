#include "card_move.h"

CardMove::CardMove() : Card(){
    cardText = "Card Name";
    locationNum = -1;
}

void CardMove::setAmount(int num){
    locationNum = num;
}

void CardMove::setCardText(std::string text1){
    cardText = text1;
}

void CardMove::cardAction(Bank* bank1, Player* player1){
    player1->setLocation(locationNum);
}

std::string CardMove::getCardText(int num){
    return cardText;
}
