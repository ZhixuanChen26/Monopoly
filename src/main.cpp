#include <QtWidgets>

class BoardWidget : public QWidget {
public:
    BoardWidget(QWidget *parent = nullptr) : QWidget(parent) {
        // Set up the main layout
        QVBoxLayout *mainLayout = new QVBoxLayout(this);
        mainLayout->setContentsMargins(0, 0, 0, 0);

        // Create the board layout
        QGridLayout *boardLayout = new QGridLayout;
        mainLayout->addLayout(boardLayout);

        // Add properties and stations to the board
        QStringList properties = {"Mediterranean Avenue", "Baltic Avenue", "Oriental Avenue" , "Vermont Avenue", "Madison Avenue", "Wall St.","States Avenue", "Verginia St."};
        QStringList stations = {"Reading Railroad", "Pennsylvania Railroad","B. & O. Railroad","Short Line Railroad"};
        QStringList chanceCards = {"Chance 1", "Chance 2"};

        // Add spaces to the board in the specified order
        addSpace(boardLayout, 0, 0, 1, 1, "Go");
        addSpace(boardLayout, 0, 1, 1, 1, properties.at(0));
        addSpace(boardLayout, 0, 2, 1, 1, properties.at(1));
        addSpace(boardLayout, 0, 3, 1, 1, stations.at(0));
        addSpace(boardLayout, 0, 4, 1, 1, properties.at(2));
        addSpace(boardLayout, 0, 5, 1, 1, "Just Visiting");
        addSpace(boardLayout, 1, 5, 1, 1, properties.at(3));
        addSpace(boardLayout, 2, 5, 1, 1, chanceCards.at(0));
        addSpace(boardLayout, 3, 5, 1, 1, stations.at(1));
        addSpace(boardLayout, 4, 5, 1, 1, properties.at(4));
        addSpace(boardLayout, 5, 5, 1, 1, "Free Parking");
        addSpace(boardLayout, 5, 4, 1, 1, properties.at(5));
        addSpace(boardLayout, 5, 3, 1, 1, stations.at(2));
        addSpace(boardLayout, 5, 2, 1, 1, properties.at(6));
        addSpace(boardLayout, 5, 1, 1, 1, properties.at(7));
        addSpace(boardLayout, 5, 0, 1, 1, "Go to Jail");
        addSpace(boardLayout, 4, 0, 1, 1, chanceCards.at(1));
        addSpace(boardLayout, 3, 0, 1, 1, stations.at(3));
        addSpace(boardLayout, 2, 0, 1, 1, properties.at(0));
        addSpace(boardLayout, 1, 0, 1, 1, properties.at(1));

        // Add player tokens
        addPlayerToken(boardLayout, 0, 0); // Player 1

    }

    void addSpace(QGridLayout *layout, int row, int col, int rowSpan, int colSpan, const QString &text) {
        QLabel *spaceLabel = new QLabel(text, this);
        spaceLabel->setAlignment(Qt::AlignCenter);
        spaceLabel->setStyleSheet("border: 1px solid black;");
        layout->addWidget(spaceLabel, row, col, rowSpan, colSpan);
    }

    void addPlayerToken(QGridLayout *layout, int row, int col) {
        QLabel *tokenLabel = new QLabel("P", this);
        tokenLabel->setAlignment(Qt::AlignCenter);
        tokenLabel->setStyleSheet("background-color: red; border-radius: 10px; color: white;");
        layout->addWidget(tokenLabel, row, col);
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    BoardWidget boardWidget;
    boardWidget.setWindowTitle("Monopoly Board");
    boardWidget.show();

    return app.exec();
}

