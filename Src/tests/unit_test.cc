#include <gtest/gtest.h>
#include <iostream>
#include <memory>
#include <vector>
#include "../model/Board.h"
#include "../model/Cell.h"
#include "../model/Player.h"
#include "../model/Game.h"
#include "../model/Dice.h"


TEST(TestCellNormal, Constructor) {
    gooseGameModel::Cell c;
    c.getType(); //Suppress warning
}


TEST(TestCellNormal, GetType) {
    gooseGameModel::Cell c;    
    EXPECT_EQ(gooseGameModel::CellType::NORMAL, c.getType());
}

TEST(TestCellNormal, ActionNormalBehavior){
    std::shared_ptr<gooseGameModel::Player> p = std::make_shared<gooseGameModel::Player>();
    std::shared_ptr<gooseGameModel::Player> p2 = std::make_shared<gooseGameModel::Player>();
    gooseGameModel::Cell c;

    c.action(p);
    //Ensures it does nothing
    EXPECT_EQ(p->getPosition(), p2->getPosition());
    EXPECT_EQ(p->getChar(), p2->getChar());
    EXPECT_EQ(p->getName(), p2->getName());
    EXPECT_EQ(p->getTimeout(), p2->getTimeout());
}

TEST(TestCellGoose, Constructor) {
    gooseGameModel::GooseCell c;
    c.getType(); //Suppress Warning
}

TEST(TestCellGoose, GetType) {
    gooseGameModel::GooseCell c;    
    EXPECT_EQ(gooseGameModel::CellType::GOOSE, c.getType());
}

TEST(TestCellGoose, ActionNormalBehavior){
    std::shared_ptr<gooseGameModel::Player> p = std::make_shared<gooseGameModel::Player>();
    std::shared_ptr<gooseGameModel::Player> p2 = std::make_shared<gooseGameModel::Player>();
    gooseGameModel::GooseCell c;

    c.action(p);
    //Ensures it does nothing
    EXPECT_EQ(p->getPosition(), p2->getPosition() + 9);
    EXPECT_EQ(p->getChar(), p2->getChar());
    EXPECT_EQ(p->getName(), p2->getName());
    EXPECT_EQ(p->getTimeout(), p2->getTimeout());
}

TEST(TestCellTeleport, Constructor) {
    gooseGameModel::TeleportCell c(1);
}

TEST(TestCellTeleport, GetType) {
    gooseGameModel::TeleportCell c(1);    
    EXPECT_EQ(gooseGameModel::CellType::TELEPORT, c.getType());
}

TEST(TestCellTeleport, ActionNormalBehavior){
    
    gooseGameModel::TeleportCell c(1);

    std::shared_ptr<gooseGameModel::Player> p = std::make_shared<gooseGameModel::Player>();
    std::shared_ptr<gooseGameModel::Player> p2 = std::make_shared<gooseGameModel::Player>();

    c.action(p);
    //Ensures it does nothing else 
    EXPECT_EQ(p->getPosition(), 1);
    EXPECT_EQ(p->getChar(), p2->getChar());
    EXPECT_EQ(p->getName(), p2->getName());
    EXPECT_EQ(p->getTimeout(), p2->getTimeout());
}

TEST(TestCellTeleport, BadArgsConstructorBehavior){
    
    gooseGameModel::TeleportCell c(-1);

    std::shared_ptr<gooseGameModel::Player> p = std::make_shared<gooseGameModel::Player>();
    std::shared_ptr<gooseGameModel::Player> p2 = std::make_shared<gooseGameModel::Player>();

    c.action(p);
    //Ensures it does nothing
    EXPECT_EQ(p->getPosition(), 0);
    EXPECT_EQ(p->getChar(), p2->getChar());
    EXPECT_EQ(p->getName(), p2->getName());
    EXPECT_EQ(p->getTimeout(), p2->getTimeout());
}

TEST(TestCellTeleport, BadArgsConstructorBehavior2){
   
    gooseGameModel::TeleportCell c(DEFAULT_SIZE_BOARD);
    std::shared_ptr<gooseGameModel::Player> p = std::make_shared<gooseGameModel::Player>();
    std::shared_ptr<gooseGameModel::Player> p2 = std::make_shared<gooseGameModel::Player>();

    c.action(p);
    //Ensures it does nothing
    EXPECT_EQ(p->getPosition(), DEFAULT_SIZE_BOARD-1);
    EXPECT_EQ(p->getChar(), p2->getChar());
    EXPECT_EQ(p->getName(), p2->getName());
    EXPECT_EQ(p->getTimeout(), p2->getTimeout());
}

TEST(TestCellTrap, Constructor) {
    gooseGameModel::TrapCell c(1);
}

TEST(TestCellTrap, GetType) {
    gooseGameModel::TrapCell c(1);    
    EXPECT_EQ(gooseGameModel::CellType::TRAP, c.getType());
}

TEST(TestCellTrap, ActionNormalBehavior){
    gooseGameModel::TrapCell c(1);

    std::shared_ptr<gooseGameModel::Player> p = std::make_shared<gooseGameModel::Player>();
    std::shared_ptr<gooseGameModel::Player> p2 = std::make_shared<gooseGameModel::Player>();
    c.action(p);
    //Ensures it does nothing
    EXPECT_EQ(p->getPosition(), p2->getPosition());
    EXPECT_EQ(p->getChar(), p2->getChar());
    EXPECT_EQ(p->getName(), p2->getName());
    EXPECT_EQ(p->getTimeout(), 1);
}

TEST(TestCellTrap, BadArgsConstructorBehavior){
    gooseGameModel::TrapCell c(-1);

    std::shared_ptr<gooseGameModel::Player> p = std::make_shared<gooseGameModel::Player>();
    std::shared_ptr<gooseGameModel::Player> p2 = std::make_shared<gooseGameModel::Player>();

    c.action(p);
    //Ensures it does nothing
    EXPECT_EQ(p->getPosition(), p2->getPosition());
    EXPECT_EQ(p->getChar(), p2->getChar());
    EXPECT_EQ(p->getName(), p2->getName());
    EXPECT_EQ(p->getTimeout(), 0);
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
        } else if (i == 6 || i == 31 || i == 38) {
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
    std::shared_ptr<gooseGameModel::Player> p = std::make_shared<gooseGameModel::Player>("AAA",'a');
    b.addPlayer(p);


    std::vector<std::shared_ptr<gooseGameModel::Player>> players = b.getPlayers();
    EXPECT_EQ(players[0]->getChar(), 'a');
    EXPECT_EQ(players[0]->getName(), "AAA");
}

TEST(TestBoard,getPlayers) {
    gooseGameModel::Board b;
    std::shared_ptr<gooseGameModel::Player> p1 = std::make_shared<gooseGameModel::Player>("AAA",'a');
    std::shared_ptr<gooseGameModel::Player> p2 = std::make_shared<gooseGameModel::Player>("BBB",'b');
    

    b.addPlayer(p1);
    b.addPlayer(p2);

    std::vector<std::shared_ptr<gooseGameModel::Player>> players = b.getPlayers();
    EXPECT_EQ(p1->getName(),players[0]->getName());
    EXPECT_EQ(p2->getName(), players[1]->getName());
}

TEST(TestBoard, GetCell) {
    gooseGameModel::Board b;
    std::shared_ptr<gooseGameModel::Cell> c = b.getCell(0);
    std::shared_ptr<gooseGameModel::Cell> c2 = b.getCell(0);

    EXPECT_EQ(c->getType(), c2->getType());
}

TEST(TestBoard, GetCellOutOfBounds) {
    gooseGameModel::Board b;
    std::shared_ptr<gooseGameModel::Cell> c = b.getCell(DEFAULT_SIZE_BOARD + 1);
    std::shared_ptr<gooseGameModel::Cell> c2 = b.getCell(DEFAULT_SIZE_BOARD + 1);

    EXPECT_EQ(c->getType(), c2->getType());
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

TEST(TestBoard,MovePlayer){
    gooseGameModel::Board b;
    std::shared_ptr<gooseGameModel::Player> p = std::make_shared<gooseGameModel::Player>("AAA",'a');
    b.addPlayer(p);
    b.movePlayer(0,1);
    std::vector<std::shared_ptr<gooseGameModel::Player>> players = b.getPlayers();
    EXPECT_EQ(players[0]->getPosition(),1);
}

TEST(TestBoard, ToString) {
    gooseGameModel::Board b;
    std::shared_ptr<gooseGameModel::Player> p = std::make_shared<gooseGameModel::Player>("AAA",'a');
    std::shared_ptr<gooseGameModel::Player> p2 = std::make_shared<gooseGameModel::Player>("AAA",'b');
    p2->setPosition(1);
    b.addPlayer(p);
    b.addPlayer(p2);
    b.toString();
}


TEST(TestDice, Constructor) {
    gooseGameModel::Dice d;
}

TEST(TestDice, ConstructorMaxValue) {
    gooseGameModel::Dice d(10);
}

TEST(TestDice, Roll) {
    gooseGameModel::Dice d;
    int r = d.roll();

    EXPECT_GE(r, 1);
    EXPECT_LE(r, 6);
}

TEST(TestDice, RollMaxValue) {
    gooseGameModel::Dice d(10);
    int r = d.roll();

    EXPECT_GE(r, 1);
    EXPECT_LE(r, 10);
}

TEST(TestGame, Constructor) {
    gooseGameModel::Game g;
    EXPECT_EQ(g.getState(), gooseGameModel::stateGame::WAITING);
}

TEST(TestGame, LaunchGame) {
    gooseGameModel::Game g;
    g.launchGame();
    EXPECT_EQ(g.getState(), gooseGameModel::stateGame::PLAYING);
}

TEST(TestGame, ResetGame) {
    gooseGameModel::Game g;
    g.launchGame();
    g.resetGame();
    EXPECT_EQ(g.getState(), gooseGameModel::stateGame::WAITING);
}
TEST(TestGame, GetBoard) {
    gooseGameModel::Game g;
    g.launchGame();
    EXPECT_EQ(g.getBoard().getSize(), DEFAULT_SIZE_BOARD);
}
TEST(TestGame, GetTurn) {
    gooseGameModel::Game g;
    g.launchGame();
    EXPECT_EQ(g.getTurn(), 0);
}

TEST(TestGame, GetTurnAfterNextTurn) {
    gooseGameModel::Game g;
    g.launchGame();
    g.nextTurn();
    EXPECT_EQ(g.getTurn(), 1);
}

TEST(TestGame, addPlayer) {
    gooseGameModel::Game g;
    g.launchGame();
    g.addPlayer("AAA", 'A');
    std::vector<std::shared_ptr<gooseGameModel::Player>> players = g.getBoard().getPlayers();
    EXPECT_EQ("AAA", players[0]->getName());
    EXPECT_EQ('A',players[0]->getChar());
}

TEST(TestGame, GetCurrentPlayer) {
    gooseGameModel::Game g;
    g.launchGame();
    EXPECT_EQ(g.getCurrentPlayer(), 0);
}

TEST(TestGame, NextTurnWaiting) {
    gooseGameModel::Game g;
    g.nextTurn();
    EXPECT_EQ(g.getState(), gooseGameModel::stateGame::WAITING);
}

TEST(TestGame, NextTurnPlaying) {
    gooseGameModel::Game g;
    g.launchGame();
    g.nextTurn();
    EXPECT_EQ(g.getState(), gooseGameModel::stateGame::PLAYING);
}

TEST(TestGame, PlayTurn) {
    gooseGameModel::Game g;
    g.launchGame();
    g.addPlayer("AAA", 'A');
    g.addPlayer("BBB", 'B');
    g.playTurn();
    EXPECT_EQ(g.getCurrentPlayer(), 1);
}

TEST(TestGame, VerifyEndConditions) {
    gooseGameModel::Game g;
    g.launchGame();
    g.addPlayer("AAA", 'A');
    g.addPlayer("BBB", 'B');
    g.addPlayer("CCC", 'C');
    g.addPlayer("DDD", 'D');
    

    while (g.getState() != gooseGameModel::stateGame::END) { 
        std::cout << "---------------------------------------------" << std::endl;
        if (g.getCurrentPlayer() == 0) std::cout << "Turn: " << g.getTurn() << std::endl;
        std::cout << "Current Player: " << g.getCurrentPlayer() << std::endl;
        std::cout << "---------------------------------------------" << std::endl;
        g.playTurn(); 
        for (auto p : g.getBoard().getPlayers()){
            std::cout << "Player " << p->getName() << " " << p->getPosition() << std::endl;
        }
        std::cout << "---------------------------------------------" << std::endl;
        if (g.getCurrentPlayer() == 0) g.getBoard().toString();
        std::cout << "---------------------------------------------" << std::endl;

    }
}






