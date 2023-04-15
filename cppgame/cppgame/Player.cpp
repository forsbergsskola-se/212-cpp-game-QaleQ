#include "Player.h"


bool Player::checkCollision(const Dot& targetDot) {
    float pLeft{ mPosX };
    float pRight{ mPosX + dotWidth };
    float pTop{ mPosY };
    float pBottom{ mPosY + dotHeight };
    float tLeft{ targetDot.mPosX };
    float tRight{ targetDot.mPosX + targetDot.dotWidth };
    float tTop{ targetDot.mPosY };
    float tBottom{ targetDot.mPosY + targetDot.dotHeight };

    if (pRight > tLeft && pLeft < tRight && pBottom > tTop && pTop < tBottom) return true;
    return false;
}
