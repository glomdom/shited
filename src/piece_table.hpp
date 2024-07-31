#pragma once

#include "piece.hpp"

#include <vector>
#include <string>

class PieceTable {
public:
    PieceTable(const std::string& initialText);

    void insert(std::size_t pos, const std::string& text);
    void remove(std::size_t pos, std::size_t length);

    std::string getText() const;

private:
    std::vector<Piece> pieces;
    std::string originalBuffer;
    std::string addBuffer;

    void splitPiece(std::size_t pieceIndex, std::size_t splitPos);
    std::size_t findPieceIndex(std::size_t pos, std::size_t& piecePos) const;
};
