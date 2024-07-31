#pragma once

#include <ncurses.h>
#include <string>
#include <vector>

class UI {
public:
    UI();
    ~UI();
    void draw(const std::vector<std::string>& lines, int cursorLine, int cursorCol);
    void refreshScreen();
    void handleResize();
    void displayMessage(const std::string& message);

private:
    void initColors();
};
