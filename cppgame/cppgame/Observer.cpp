#include "Observer.h"

bool Observer::checkCollision(const Dot& playerDot, const Dot& targetDot) {
	float pLeft = playerDot.mPosX;
	float pRight = playerDot.mPosX + playerDot.dotWidth;
	float pTop = playerDot.mPosY;
	float pBottom = playerDot.mPosY + playerDot.dotHeight;
	float tLeft = targetDot.mPosX;
	float tRight = targetDot.mPosX + targetDot.dotWidth;
	float tTop = targetDot.mPosY;
	float tBottom = targetDot.mPosY + targetDot.dotHeight;

	if (pRight > tLeft && pLeft < tRight && pBottom > tTop && pTop < tBottom) return true;
	return false;
}
