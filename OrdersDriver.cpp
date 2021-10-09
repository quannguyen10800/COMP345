//
// Created by Quan Nguyen on 2021-09-26.
//

#include "../game_engine/GameEngine.h"
#include "Orders.h"

int main()
{
    // Setup
    Territory* t1 = new Territory("Quebec");
    Territory* t2 = new Territory("BC");
    Territory* t3 = new Territory("Ontario");
    t1->addArmies(10);
    t2->addArmies(5);
    t3->addArmies(10);

    Player* player = new Player("Bob");
    Player* enemy = new Player("Alice");
    player->addOwnedTerritory(t1);
    player->addOwnedTerritory(t2);
    enemy->addOwnedTerritory(t3);

    GameEngine::setPlayers({ player, enemy });

    OrdersList ordersList;
    ordersList.add(new DeployOrder(player, 5, t1));
    ordersList.add(new AdvanceOrder(player, 5, t1, t3));
    ordersList.add(new BombOrder(player, t3));
    ordersList.add(new AirliftOrder(player, 5, t1, t2));
    ordersList.add(new BlockadeOrder(player, t1));
    ordersList.add(new NegotiateOrder(player, enemy));



    // Show the OrderList
    std::cout << "===== " << "Original orders list: " << ordersList << " =====" << std::endl;
    for (const auto &order : ordersList.getOrders())
    {
        std::cout << *order << std::endl;
        std::cout << std::boolalpha << "Order is valid: " << order->validate() << std::endl;
        order->execute();
        std::cout << std::endl;
    }

    // Show the OrderList after moving an order from index 1 to index 4
    ordersList.move(1, 4);
    std::cout << "===== " << "Orders list after moving an order: " << ordersList << " =====" << std::endl;
    for (const auto &order : ordersList.getOrders())
    {
        std::cout << *order << std::endl;
    }

    // Show the OrderList after deleting an order at index 5
    ordersList.remove(5);
    std::cout << "\n===== " << "Orders list after deleting an order: " << ordersList << " =====" << std::endl;
    for (const auto &order : ordersList.getOrders())
    {
        std::cout << *order << std::endl;
    }

    delete t1;
    delete t2;
    delete t3;
    GameEngine::resetGameEngine();

    return 0;
}