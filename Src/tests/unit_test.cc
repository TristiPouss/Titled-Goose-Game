#include <gtest/gtest.h>
#include <vector>
#include "../model/Board.h"
#include "../model/Cell.h"
#include "../model/Player.h"
#include "../model/Game.h"
#include "../model/Dice.h"


TEST(TestCellNormal, Constructor) {
    gooseGameModel::Cell c;
}


TEST(TestCellNormal, GetType) {
    gooseGameModel::Cell c;    
    EXPECT_EQ(gooseGameModel::CellType::NORMAL, c.getType());
}

TEST(TestCellNormal, ActionNormalBehavior){
    gooseGameModel::Player p;
    gooseGameModel::Player p2 = p;
    gooseGameModel::Cell c;

    c.action(p);
    //Ensures it does nothing
    EXPECT_EQ(p.getPosition(), p2.getPosition());
    EXPECT_EQ(p.getChar(), p2.getChar());
    EXPECT_EQ(p.getName(), p2.getName());
    EXPECT_EQ(p.getTimeout(), p2.getTimeout());
}

TEST(TestCellGoose, Constructor) {
    gooseGameModel::GooseCell c;
}

TEST(TestCellGoose, GetType) {
    gooseGameModel::GooseCell c;    
    EXPECT_EQ(gooseGameModel::CellType::GOOSE, c.getType());
}

TEST(TestCellGoose, ActionNormalBehavior){
    gooseGameModel::Player p;
    gooseGameModel::Player p2 = p;
    gooseGameModel::GooseCell c;

    c.action(p);
    //Ensures it moves the player 9 steps
    EXPECT_EQ(p.getPosition(), p2.getPosition() + 9);
    EXPECT_EQ(p.getChar(), p2.getChar());
    EXPECT_EQ(p.getName(), p2.getName());
    EXPECT_EQ(p.getTimeout(), p2.getTimeout());
}

TEST(TestCellTeleport, Constructor) {
    gooseGameModel::TeleportCell c(1);
}

TEST(TestCellTeleport, GetType) {
    gooseGameModel::TeleportCell c(1);    
    EXPECT_EQ(gooseGameModel::CellType::TELEPORT, c.getType());
}

TEST(TestCellTeleport, ActionNormalBehavior){
    gooseGameModel::Player p;
    gooseGameModel::Player p2 = p;
    gooseGameModel::TeleportCell c(1);

    c.action(p);
    //Ensures it moves the player to position 1
    EXPECT_EQ(p.getPosition(), 1);
    EXPECT_EQ(p.getChar(), p2.getChar());
    EXPECT_EQ(p.getName(), p2.getName());
    EXPECT_EQ(p.getTimeout(), p2.getTimeout());
}

TEST(TestCellTeleport, BadArgsConstructorBehavior){
    gooseGameModel::Player p;
    gooseGameModel::Player p2 = p;
    gooseGameModel::TeleportCell c(-1);

    c.action(p);
    //Ensures it moves the player to position 0
    EXPECT_EQ(p.getPosition(), 0);
    EXPECT_EQ(p.getChar(), p2.getChar());
    EXPECT_EQ(p.getName(), p2.getName());
    EXPECT_EQ(p.getTimeout(), p2.getTimeout());
}

TEST(TestCellTeleport, BadArgsConstructorBehavior2){
    gooseGameModel::Player p;
    gooseGameModel::Player p2 = p;
    gooseGameModel::TeleportCell c(DEFAULT_SIZE_BOARD);

    c.action(p);
    //Ensures it moves the player to position 39
    EXPECT_EQ(p.getPosition(), DEFAULT_SIZE_BOARD - 1);
    EXPECT_EQ(p.getChar(), p2.getChar());
    EXPECT_EQ(p.getName(), p2.getName());
    EXPECT_EQ(p.getTimeout(), p2.getTimeout());
}

TEST(TestCellTrap, Constructor) {
    gooseGameModel::TrapCell c(1);
}

TEST(TestCellTrap, GetType) {
    gooseGameModel::TrapCell c(1);    
    EXPECT_EQ(gooseGameModel::CellType::TRAP, c.getType());
}

TEST(TestCellTrap, ActionNormalBehavior){
    gooseGameModel::Player p;
    gooseGameModel::Player p2 = p;
    gooseGameModel::TrapCell c(1);

    c.action(p);
    //Ensures it sets the player timeout to 1
    EXPECT_EQ(p.getPosition(), p2.getPosition());
    EXPECT_EQ(p.getChar(), p2.getChar());
    EXPECT_EQ(p.getName(), p2.getName());
    EXPECT_EQ(p.getTimeout(), 1);
}

TEST(TestCellTrap, BadArgsConstructorBehavior){
    gooseGameModel::Player p;
    gooseGameModel::Player p2 = p;
    gooseGameModel::TrapCell c(-1);

    c.action(p);
    //Ensures it sets the player timeout to 0
    EXPECT_EQ(p.getPosition(), p2.getPosition());
    EXPECT_EQ(p.getChar(), p2.getChar());
    EXPECT_EQ(p.getName(), p2.getName());
    EXPECT_EQ(p.getTimeout(), 0);
}

TEST(TestPlayer, Constructor) {
    gooseGameModel::Player p;

    EXPECT_EQ(p.getName(), "[]");
    EXPECT_EQ(p.getChar(), '!');
    EXPECT_EQ(p.getPosition(), 0);
    EXPECT_EQ(p.getTimeout(), 0);
}

TEST(TestPlayer, ConstructorWithName) {
    gooseGameModel::Player p("Test", 'T');

    EXPECT_EQ(p.getName(), "Test");
    EXPECT_EQ(p.getChar(), 'T');
    EXPECT_EQ(p.getPosition(), 0);
    EXPECT_EQ(p.getTimeout(), 0);
}

TEST(TestPlayer, MoveNormalBehavior) {
    gooseGameModel::Player p;
    p.move(1);

    EXPECT_EQ(p.getPosition(), 1);
}

TEST(TestPlayer, MoveNegative) {
    gooseGameModel::Player p;
    p.move(-1);

    EXPECT_EQ(p.getPosition(), 0);
}

TEST(TestPlayer, MoveNegative2) {
    gooseGameModel::Player p;
    p.setPosition(5);
    p.move(-10);

    EXPECT_EQ(p.getPosition(), 0);
}

TEST(TestPlayer, MoveNegative3) {
    gooseGameModel::Player p;
    p.setPosition(6);
    p.move(-5);

    EXPECT_EQ(p.getPosition(), 1);
}

TEST(TestPlayer, MoveNegative4) {
    gooseGameModel::Player p;
    p.setPosition(6);
    p.move(-6);

    EXPECT_EQ(p.getPosition(), 0);
}

TEST(TestPlayer, MoveBounce) {
    gooseGameModel::Player p;
    p.setPosition(DEFAULT_SIZE_BOARD - 1);
    p.move(1);

    EXPECT_EQ(p.getPosition(), DEFAULT_SIZE_BOARD - 2);
}

TEST(TestPlayer,MoveBounce2) {
    gooseGameModel::Player p;
    p.setPosition(DEFAULT_SIZE_BOARD - 1);
    p.move(2);

    EXPECT_EQ(p.getPosition(), DEFAULT_SIZE_BOARD - 3);
}

TEST(TestPlayer, MoveBounce3) {
    gooseGameModel::Player p;
    p.setPosition(DEFAULT_SIZE_BOARD - 4);
    p.move(10);

    EXPECT_EQ(p.getPosition(), DEFAULT_SIZE_BOARD - 8);
}

TEST(TestPlayer, SetPositionNormal) {
    gooseGameModel::Player p;
    p.setPosition(1);

    EXPECT_EQ(p.getPosition(), 1);
}

TEST(TestPlayer, SetPositionNegative) {
    gooseGameModel::Player p;
    p.setPosition(-1);

    EXPECT_EQ(p.getPosition(), 0);
}

TEST(TestPlayer, SetPositionBounce) {
    gooseGameModel::Player p;
    p.setPosition(DEFAULT_SIZE_BOARD);

    EXPECT_EQ(p.getPosition(), DEFAULT_SIZE_BOARD - 1);
}

TEST(TestPlayer, SetTimeout) {
    gooseGameModel::Player p;
    p.setTimeout(1);

    EXPECT_EQ(p.getTimeout(), 1);
}

TEST(TestPlayer, SetTimeoutNegative) {
    gooseGameModel::Player p;
    p.setTimeout(-1);

    EXPECT_EQ(p.getTimeout(), 0);
}

TEST(TestBoard, ConstructorInit) {
    gooseGameModel::Board b;

    b.init();
    std::vector<std::shared_ptr<gooseGameModel::Cell>> cells = b.getCellsTab();

    EXPECT_EQ(cells.size(), DEFAULT_SIZE_BOARD);
    EXPECT_EQ(b.getSize(), cells.size());

    for (unsigned long i = 0; i < cells.size(); i++) {
        if (i == 5 || i == 9 || i == 14 || i == 18 || i == 23 || i == 27 || i == 32 || i == 36) {
            EXPECT_EQ(cells[i]->getType(), gooseGameModel::CellType::GOOSE);
        } else if (i == 6 || i == 31 || i == 39) {
            EXPECT_EQ(cells[i]->getType(), gooseGameModel::CellType::TELEPORT);
        } else if (i == 19) {
            EXPECT_EQ(cells[i]->getType(), gooseGameModel::CellType::TRAP);
        } else {
            EXPECT_EQ(cells[i]->getType(), gooseGameModel::CellType::NORMAL);
        } 
    }
}

TEST(TestBoard, AddPlayer) {
    gooseGameModel::Board b;
    gooseGameModel::Player p("AAA",'a');
    b.addPlayer(p);

    std::vector<gooseGameModel::Player> players = b.getPlayers();
    EXPECT_EQ(players[0].getChar(), 'a');
    EXPECT_EQ(players[0].getName(), "AAA");
}

TEST(TestBoard,getPlayers) {
    gooseGameModel::Board b;
    gooseGameModel::Player p1("AAA",'a');
    gooseGameModel::Player p2("BBB",'b');
    

    b.addPlayer(p1);
    b.addPlayer(p2);

    std::vector<gooseGameModel::Player> players = b.getPlayers();
    EXPECT_EQ(p1.getName(),players[0].getName());
    EXPECT_EQ(p2.getName(), players[1].getName());
}

TEST(TestBoard, GetSize) {
    gooseGameModel::Board b;
    EXPECT_EQ(b.getSize(), DEFAULT_SIZE_BOARD);
}

TEST(TestBoard, GetCellsTab) {
    gooseGameModel::Board b;
    std::vector<std::shared_ptr<gooseGameModel::Cell>> cells = b.getCellsTab();
    std::vector<std::shared_ptr<gooseGameModel::Cell>> cells2= b.getCellsTab();

    EXPECT_EQ(cells.size(), cells2.size());
    for (unsigned long i = 0; i<cells.size();i++){
        EXPECT_EQ(cells[i]->getType(), cells2[i]->getType());
    }
}



