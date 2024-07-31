#pragma once

#include "buffer.hpp"
#include "ui.hpp"

#include <cstddef>
#include <memory>

class Editor {
public:
    Editor(std::shared_ptr<Buffer> buffer, std::shared_ptr<UI> ui);

    void run();

private:
    void handleInput(int ch);
    void updateUI();

    std::shared_ptr<Buffer> buffer;
    std::shared_ptr<UI> ui;

    std::size_t cursorLine;
    std::size_t cursorCol;
};