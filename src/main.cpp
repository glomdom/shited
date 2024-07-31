#include "buffer.hpp"
#include "editor.hpp"
#include "ui.hpp"

#include <memory>
#include <ncurses.h>

int main() {
    auto buffer = std::make_shared<Buffer>();
    auto ui = std::make_shared<UI>();

    Editor editor(buffer, ui);
    editor.run();

    return 0;
}