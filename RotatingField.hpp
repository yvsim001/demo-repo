#pragma once

class RotatingField {
    public:
        RotatingField();
        void setRightRotation();
        void setLeftRotation();
        void resetRotation();
        uint8_t getRotation() const;

    private:
        uint8_t rotation_;
};