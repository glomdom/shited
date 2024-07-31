#include "ui.hpp"

UI::UI() {
    initscr();
    raw();
    keypad(stdscr, true);
    noecho();
    initColors();
}

UI::~UI() {
    endwin();
}

void UI::draw(const std::vector<std::string>& lines, int cursorLine, int cursorCol) {
    clear();

    for (size_t i = 0; i < lines.size(); ++i) {
        mvprintw(i, 0, "%s", lines[i].c_str());
    }

    move(cursorLine, cursorCol);
}

void UI::refreshScreen() {
    refresh();
}

void UI::handleResize() { }

void UI::displayMessage(const std::string& message) {
    mvprintw(LINES - 1, 0, "%s", message.c_str());
}

void UI::initColors() {
    if (has_colors()) {
        start_color();
    }
}
