#include "editor.hpp"

Editor::Editor(std::shared_ptr<Buffer> buffer, std::shared_ptr<UI> ui)
    : buffer(buffer), ui(ui), cursorLine(0), cursorCol(0) {}

void Editor::run() {
    while (true) {
        ui->draw(buffer->getLines(), cursorLine, cursorCol);
        ui->refreshScreen();

        int ch = getch();
        if (ch == KEY_F(1)) {
            break;
        } else {
            handleInput(ch);
        }
    }
}

void Editor::handleInput(int ch) {
    switch (ch) {
        case KEY_LEFT: {
            if (cursorCol > 0) --cursorCol;
        } break;

        case KEY_RIGHT: {
            if (cursorCol < buffer->getLines()[cursorLine].size()) ++cursorCol;
        } break;
        
        case KEY_UP: {
            if (cursorLine > 0) --cursorLine;
        } break;
        
        case KEY_DOWN: {
            if (cursorLine < buffer->getLineCount() - 1) ++cursorLine;
        } break;
        
        case KEY_BACKSPACE:
        case 127: {
            if (cursorCol > 0) {
                buffer->deleteChar(cursorLine, --cursorCol);
            } else if (cursorLine > 0) {
                cursorCol = buffer->getLines()[cursorLine - 1].size();
                buffer->newLine(cursorLine - 1, cursorCol);
                buffer->deleteChar(cursorLine - 1, cursorCol);
                cursorLine--;
            }

        } break;
        
        case '\n': {
            buffer->newLine(cursorLine, cursorCol);
            cursorLine++;
            cursorCol = 0;
        } break;

        default: {
            if (isprint(ch)) {
                buffer->insertChar(cursorLine, cursorCol++, ch);
            }
        } break;
    }
}

void Editor::updateUI() {
    ui->draw(buffer->getLines(), cursorLine, cursorCol);
    ui->refreshScreen();
}