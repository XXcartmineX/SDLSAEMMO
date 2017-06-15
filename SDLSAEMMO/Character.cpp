#include "Character.h"
#include <iostream>
//http://lazyfoo.net/tutorials/SDL/06_extension_libraries_and_loading_other_image_formats/index2.php
//https://www.libsdl.org/projects/SDL_image/docs/SDL_image_frame.html
//https://docs.google.com/document/d/1U9dTzY36119WHmrGLuYvK0dadx5YTFP99Ml_BgNm71s/edit

Character::Character(std::string _name) : name(_name)
{
}

Character::Character(fVector2 _pos, fVector2 _size, std::string _name) : Character(_name)
{
	pos = _pos;
	size = _size;
}

Character::Character(fVector2 _pos, fVector2 _size, int _life,
	std::string _name) : Character(_pos,_size,_name)
{
	life = _life;
}

Character::Character(fVector2 _pos, fVector2 _size, int _life,
	std::string _spritePath, std::string _name) :
	Character(_pos,_size,_life)
{
	name = _name;
}

Character::~Character()
{
}

void Character::ChangeSprites(int s)
{
	if (currentSpriteSheet == s)
		return;
	currentSpriteIndex = 0;
	currentSpriteSheet = s;

}

void Character::flipX(bool x)
{
	if (isFlipped == x)
		return;
	isFlipped = x;
	RPGSAEMMOApp::LockDrawMutex();
	for (auto sprites : spriteSheets)
	{
		for (auto surface : sprites)
		{
			SDL_Surface* flippedImage = SDL_CreateRGBSurface(surface->flags, surface->w,
				surface->h, surface->format->BitsPerPixel, surface->format->Rmask, surface->format->Gmask,
				surface->format->Bmask, surface->format->Amask);
			Uint32 *pixels = (Uint32 *)surface->pixels;
			Uint32 *dstpixels = (Uint32 *)flippedImage->pixels;
			if (SDL_MUSTLOCK(surface))
				SDL_LockSurface(surface);
			for (int x = 0, rx = flippedImage->w - 1; x < flippedImage->w; x++, rx--)
			{
				for (int y = 0, ry = flippedImage->h - 1; y < flippedImage->h; y++, ry--)
				{
					dstpixels[(y * surface->w) + rx] = pixels[(y * surface->w) + x];
				}
			}
			if (SDL_MUSTLOCK(surface))
			{
				SDL_UnlockSurface(surface);
			}
			for (int x = 0; x < flippedImage->w; x++)
			{
				for (int y = 0; y < flippedImage->h; y++)
				{
					pixels[(y * surface->w) + x] = dstpixels[(y * surface->w) + x];
				}
			}
			SDL_FreeSurface(flippedImage);
		}
	}
	RPGSAEMMOApp::UnlockDrawMutex();
}

void Character::draw(const int frames)
{
	if (spriteSheets.size() == 0 || spriteSheets.at(currentSpriteSheet).size() == 0)
		return;
	posValues = new SDL_Rect{ (int)round(pos.x)-(int)RPGSAEMMOApp::camera.x,(int)round(pos.y) - (int)RPGSAEMMOApp::camera.y,(int)round(size.x),(int)round(size.y) };
	//if (pos.x + size.x >= RPGSAEMMOApp::getWidth())
	//	posValues->w = (int)round((pos.x + size.x)) - RPGSAEMMOApp::getWidth();
	//if (pos.y + size.y >= RPGSAEMMOApp::getHeight())
	//	posValues->h = (int)round((pos.y + size.y)) - RPGSAEMMOApp::getHeight();
	//if (pos.x < 0)
	//{
	//	if (clipping == NULL) {
	//		clipping = new SDL_Rect{ (int)round(- pos.x),0, (int)round(size.x + pos.x), (int)round(size.y) };
	//	}
	//	else
	//	{
	//		clipping->x = (int)round(-pos.x);
	//		clipping->w = (int)round(size.x + pos.x);
	//	}
	//}
	//if (pos.y < 0)
	//{
	//	if (clipping == NULL) {
	//		clipping = new SDL_Rect{ 0, (int)round(-pos.y), (int)round(size.x), (int)round(size.y + pos.y) };
	//	}
	//	else
	//	{
	//		clipping->y = (int)(-pos.y);
	//		clipping->h = (int)round(size.y + pos.y);
	//	}
	//}
	SDL_Texture* renderTexture = 
		SDL_CreateTextureFromSurface(RPGSAEMMOApp::getRenderer(),spriteSheets.at(currentSpriteSheet).at(currentSpriteIndex));
	SDL_RenderCopyEx(RPGSAEMMOApp::getRenderer(), renderTexture, NULL, posValues, rotAngle, center, flip);
	SDL_DestroyTexture(renderTexture);
	delete posValues;
	if(!(++counter %= frames))
		++currentSpriteIndex %= spriteSheets.at(currentSpriteSheet).size();

}

void Character::Move(fVector2 & _newPos)
{
	RPGSAEMMOApp::AddToPhysicsQueue(std::bind(&Character::MoveBase, this, _newPos));
}

void Character::EnablePhysics2D(const bool & enable,
	const b2BodyDef & bodydef,
	const b2PolygonShape & shape,
	b2FixtureDef & def,
	const bool & isTrigger)
{
	RPGSAEMMOApp::AddToPhysicsQueue(std::bind(&Character::EnablePhys2D, this, enable, bodydef, shape, def, isTrigger));
}

void Character::AddForce(fVector2 & _force)
{
	RPGSAEMMOApp::AddToPhysicsQueue(std::bind(&Character::AddForceBase, this, _force));
}

void Character::AddLinearImpulse(fVector2 & _force)
{
	RPGSAEMMOApp::AddToPhysicsQueue(std::bind(&Character::AddForceBase, this, _force));
}

void Character::Update()
{
	if (charBody != nullptr) {
		if (justCollisioned && charBody->GetContactList() == nullptr)
		{
			justCollisioned = false;
			OnCollisionExit();
		}
		else if (!justCollisioned && charBody->GetContactList() != nullptr)
		{
			justCollisioned = true;
			OnCollisionEnter();
		}
		else if (charBody->GetContactList() != nullptr)
			OnCollisionStay();
		pos = charBody->GetPosition();
		rotAngle = charBody->GetAngle() * radToDeg;
	}
	rotAngle += angle;
	//RPGSAEMMOApp::AddToPhysicsQueue(std::bind(&Character::SetTransform, this));
	angle = 0;
}

void Character::OnCollisionEnter()
{
	std::cout << "Entre!"<<std::endl;
}

void Character::OnCollisionExit()
{
	std::cout << "Sali!"<<std::endl;
}

void Character::OnCollisionStay()
{
}

void Character::EnablePhys2D(const bool & enable,
	const b2BodyDef & bodydef,
	const b2PolygonShape & shape,
	b2FixtureDef & def,
	const bool & isTrigger)
{
	if (enable)
	{
		charBody = RPGSAEMMOApp::getWorld()->CreateBody(&bodydef);
		def.shape = &shape;
		if (isTrigger)
		{
			//charBody->SetActive(false);
			def.isSensor = true;
		}
		b2Fixture* charFixture = charBody->CreateFixture(&def);
		bodyShape = shape;

	}
	else
		RPGSAEMMOApp::getWorld()->DestroyBody(charBody);
}

void Character::SetTransform()
{
	if (charBody != nullptr)
		charBody->SetTransform(charBody->GetPosition(), rotAngle);
}

void Character::MoveBase(fVector2& _newPos)
{
	if (charBody != nullptr)
		charBody->SetLinearVelocity(_newPos.tobVec2());
}

void Character::AddLinearImpulseBase(fVector2 & _force)
{
	if (charBody != nullptr)
		charBody->ApplyLinearImpulseToCenter(_force.tobVec2(), true);
}

void Character::AddForceBase(fVector2 & _newPos)
{
	if (charBody != nullptr)
		charBody->ApplyForceToCenter(_newPos.tobVec2(), true);
}

void Character::SetAlphaColor(uint8_t r, uint8_t g, uint8_t b)
{
	for (auto spriteSheet : spriteSheets)
	{
		for (auto sprite : spriteSheet)
		{
			SDL_SetColorKey(sprite, SDL_TRUE, SDL_MapRGB(sprite->format, 0, 0, 0));
		}
	}
}

