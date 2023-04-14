#include "Observer.h"

bool Observer::checkCollision(const Dot& playerDot, const Dot& targetDot) {
	float pLeft = playerDot.mPosX;
	float pRight = playerDot.mPosX + playerDot.DOT_WIDTH;
	float pTop = playerDot.mPosY;
	float pBottom = playerDot.mPosY + playerDot.DOT_HEIGHT;
	float tLeft = targetDot.mPosX;
	float tRight = targetDot.mPosX + targetDot.DOT_WIDTH;
	float tTop = targetDot.mPosY;
	float tBottom = targetDot.mPosY + targetDot.DOT_HEIGHT;

	if (pRight > tLeft && pLeft < tRight && pBottom > tTop && pTop < tBottom) return true;
	return false;
}
