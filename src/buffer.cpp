#include "buffer.hpp"

Buffer::Buffer() {
    lines.emplace_back("");
}

void Buffer::insertChar(std::size_t line, std::size_t col, char ch) {
    if (line < lines.size() && col <= lines[line].size()) {
        lines[line].insert(col, 1, ch);
    }
}

void Buffer::deleteChar(std::size_t line, std::size_t col) {
    if (line < lines.size() && col < lines[line].size()) {
        lines[line].erase(col, 1);
    }
}

void Buffer::newLine(std::size_t line, std::size_t col) {
    if (line < lines.size()) {
        std::string remainder = lines[line].substr(col);
        lines[line] = lines[line].substr(0, col);
        lines.insert(lines.begin() + line + 1, remainder);
    }
}

const std::vector<std::string>& Buffer::getLines() const {
    return lines;
}

std::size_t Buffer::getLineCount() const {
    return lines.size();
}
