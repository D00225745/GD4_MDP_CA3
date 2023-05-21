#include "RoboCatClientPCH.hpp"
//Berk D00225745
MouseClient::MouseClient()
{
	mSpriteComponent.reset(new SpriteComponent(this));
	mSpriteComponent->SetTexture(TextureManager::sInstance->GetTexture("mouse"));
}
