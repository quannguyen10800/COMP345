//
// Created by Quan Nguyen on 2021-12-01.
//

#pragma once

#include "../map/Map.h"
#include "../Player/Player.h"
#include <iostream>
#include <vector>

class Player;

class PlayerStrategy {

public:
    virtual std::vector<Territory*> toAttack(const Player* player) const = 0;
    virtual std::vector<Territory*> toDefend(const Player* player) const = 0;
    friend std::ostream &operator<<(std::ostream &output, const PlayerStrategy &strategy);
    virtual void issueOrder(Player* player) = 0;
    virtual PlayerStrategy* clone() const = 0;

protected:
    virtual std::ostream &print_(std::ostream &output) const = 0;
};

//Quan Nguyen

class AggressivePlayerStrategy : public PlayerStrategy
{
public:
    PlayerStrategy* clone() const;
    std::vector<Territory*> toAttack(const Player* player) const;
    std::vector<Territory*> toDefend(const Player* player) const;
    void issueOrder(Player* player);

protected:
    std::ostream &print_(std::ostream &output) const;

private:
    bool deployToTopTerritory_(Player* player, std::vector<Territory*> territoriesToDefend);
    bool attackFromTopTerritory_(Player* player, Territory* attackFrom, std::vector<Territory*> territoriesToAttack);
    bool advanceToRandomTerritory_(Player* player, std::vector<Territory*> territoriesToDefend);
    bool playCard_(Player* player, std::vector<Territory*> territoriesToDefend);
};


class HumanPlayerStrategy : public PlayerStrategy
{
public:
    PlayerStrategy* clone() const;
    std::vector<Territory*> toAttack(const Player* player) const;
    std::vector<Territory*> toDefend(const Player* player) const;
    void issueOrder(Player* player);

protected:
    std::ostream &print_(std::ostream &output) const;

private:
    void deployReinforcements_(Player* player, std::vector<Territory*> territoriesToDefend);
    void issueAdvance_(Player* player, std::vector<Territory*> territoriesToDefend);
    void playCard_(Player* player, std::vector<Territory*> territoriesToDefend);
};



// Tam Nhu Tran
class BenevolentPlayerStrategy : public PlayerStrategy {
public:
    PlayerStrategy* clone() const;
    std::vector<Territory*> toAttack(const Player* player) const;
    std::vector<Territory*> toDefend(const Player* player) const;
    void issueOrder(Player* player);

protected:
    std::ostream &print_(std::ostream &output) const;

private:

};

class NeutralPLayerStrategy : public PlayerStrategy {
public:
    PlayerStrategy* clone() const;
    std::vector<Territory*> toAttack(const Player* player) const;
    std::vector<Territory*> toDefend(const Player* player) const;
    void issueOrder(Player* player);

protected:
    std::ostream &print_(std::ostream &output) const;

private:

};

class CheaterPlayerStrategy : public PlayerStrategy{
public:
    PlayerStrategy* clone() const;
    std::vector<Territory*> toAttack(const Player* player) const;
    std::vector<Territory*> toDefend(const Player* player) const;
    void issueOrder(Player* player);

protected:
    std::ostream &print_(std::ostream &output) const;


private:

};



