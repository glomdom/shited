#include "piece_table.hpp"
#include "piece.hpp"

PieceTable::PieceTable(const std::string& initialText)
    : originalBuffer(initialText) {
    pieces.emplace_back(BufferType::Original, 0, initialText.size());
}

void PieceTable::insert(std::size_t pos, const std::string& text) {
    std::size_t piecePos;
    std::size_t pieceIndex = findPieceIndex(pos, piecePos);

    if (piecePos != pos) {
        splitPiece(pieceIndex, piecePos);
        pieceIndex++;
    }

    addBuffer.append(text);
    pieces.emplace(pieces.begin() + pieceIndex + 1, BufferType::Add, addBuffer.size() - text.size(), text.size());
}

void PieceTable::remove(std::size_t pos, std::size_t length) {
    std::size_t piecePos;
    std::size_t pieceIndex = findPieceIndex(pos, piecePos);

    while (length > 0 && pieceIndex < pieces.size()) {
        Piece& piece = pieces[pieceIndex];
        std::size_t endPos = piecePos + length;
        std::size_t pieceLength = piece.length;

        if (endPos < pieceLength) {
            piece.length -= length;

            break;
        } else {
            length -= (pieceLength - piecePos);

            pieces.erase(pieces.begin() + pieceIndex);
        }

        pieceIndex++;
        piecePos = 0;
    }
}

std::string PieceTable::getText() const {
    std::string result;

    for (const auto& piece : pieces) {
        const std::string& buffer = (piece.buffer == BufferType::Original) ? originalBuffer : addBuffer;

        result.append(buffer.substr(piece.start, piece.length));
    }

    return result;
}

void PieceTable::splitPiece(std::size_t pieceIndex, std::size_t splitPos) {
    Piece& piece = pieces[pieceIndex];

    if (splitPos < piece.length) {
        pieces.insert(pieces.begin() + pieceIndex + 1, piece);
        piece.length = splitPos;
        pieces[pieceIndex + 1].start += splitPos;
        pieces[pieceIndex + 1].length -= splitPos;
    }
}

std::size_t PieceTable::findPieceIndex(std::size_t pos, std::size_t& piecePos) const {
    std::size_t currentPos = 0;

    for (std::size_t i = 0; i < pieces.size(); ++i) {
        std::size_t nextPos = currentPos + pieces[i].length;

        if (pos < nextPos) {
            piecePos = pos - currentPos;
            return i;
        }

        currentPos = nextPos;
    }

    piecePos = 0;

    return pieces.size();
}
