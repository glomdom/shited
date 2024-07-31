#pragma once

#include <cstddef>

enum class BufferType {
    Original,
    Add,
};

struct Piece {
    BufferType buffer;
    std::size_t start;
    std::size_t length;

    Piece(BufferType bufferType, std::size_t startPos, std::size_t len)
        : buffer(bufferType), start(startPos), length(len) {}
};
