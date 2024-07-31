#pragma once

#include <cstddef>
#include <string>
#include <vector>

class Buffer {
public:
    Buffer();

    void insertChar(std::size_t line, std::size_t col, char ch);
    void deleteChar(std::size_t line, std::size_t col);
    void newLine(std::size_t line, std::size_t col);

    const std::vector<std::string>& getLines() const;
    std::size_t getLineCount() const;

private:
    std::vector<std::string> lines;
};
