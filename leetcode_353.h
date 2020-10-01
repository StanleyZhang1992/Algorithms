#pragma once
/*
353. Design Snake Game
Medium

403

174

Add to List

Share
Design a Snake game that is played on a device with screen size = width x height. Play the game online if you are not familiar with the game.

The snake is initially positioned at the top left corner (0,0) with length = 1 unit.

You are given a list of food's positions in row-column order. When a snake eats the food, its length and the game's score both increase by 1.

Each food appears one by one on the screen. For example, the second food will not appear until the first food was eaten by the snake.

When a food does appear on the screen, it is guaranteed that it will not appear on a block occupied by the snake.

Example:

Given width = 3, height = 2, and food = [[1,2],[0,1]].

Snake snake = new Snake(width, height, food);

Initially the snake appears at position (0,0) and the food at (1,2).

|S| | |
| | |F|

snake.move("R"); -> Returns 0

| |S| |
| | |F|

snake.move("D"); -> Returns 0

| | | |
| |S|F|

snake.move("R"); -> Returns 1 (Snake eats the first food and right after that, the second food appears at (0,1) )

| |F| |
| |S|S|

snake.move("U"); -> Returns 1

| |F|S|
| | |S|

snake.move("L"); -> Returns 2 (Snake eats the second food)

| |S|S|
| | |S|

snake.move("U"); -> Returns -1 (Game over because snake collides with border)
*/

class SnakeGame {
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    queue<vector<int> > food;
    deque<vector<int> > snake;
    set<vector<int> > body;
    int width;
    int height;
    int score;

    SnakeGame(int width, int height, vector<vector<int>>& food) {
        this->width = width;
        this->height = height;
        for (vector<int> f : food) {
            this->food.push(f);
        }
        snake.push_back(vector<int>{0, 0});
        body.insert(vector<int>{0, 0});
        score = 0;
    }

    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down
        @return The game's score after the move. Return -1 if game over.
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        vector<int> curFood;
        if (!food.empty())
            curFood = food.front();
        else
            curFood = { -1, -1 };
        vector<int> curHead = snake.front();
        vector<int> newHead = curHead;
        if (direction == "U") {
            newHead[0] -= 1;
        }
        else if (direction == "D") {
            newHead[0] += 1;
        }
        else if (direction == "L") {
            newHead[1] -= 1;
        }
        else {
            newHead[1] += 1;
        }

        vector<int> tail = snake.back();
        snake.pop_back();
        body.erase(tail);
        if (newHead[0] < 0 || newHead[1] < 0 || newHead[0] >= height || newHead[1] >= width)
            return -1;
        if (body.count(newHead))
            return -1;

        if (newHead == curFood) {
            snake.push_back(tail);
            body.insert(tail);
            snake.push_front(newHead);
            body.insert(newHead);
            food.pop();
            score += 1;
        }
        else {
            snake.push_front(newHead);
            body.insert(newHead);
        }

        return score;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */