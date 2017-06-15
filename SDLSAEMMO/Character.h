#pragma once
#include <vector>
#include <SDL_image.h>
#include <string>
#include <functional>
#include "Box2D\Box2D.h"
#include "RPGSAEMMOApp.h"
#include "fVector2.h"

class Character
{
public:
	Character(std::string _name = "");
	Character(fVector2 _pos, fVector2 _size,
		std::string _name = "");
	Character(fVector2 _pos, fVector2 _size, int _life,
		std::string _name = "");
	Character(fVector2 _pos, fVector2 _size, int _life,
		std::string _spritePath, std::string _name = "");
	~Character();
	inline bool isAlive() { return life > 0; }

	void ChangeSprites(int s);
	void flipX(bool x);
	void draw(const int frames = 1);
	void Move(fVector2& _newPos );
	void EnablePhysics2D(const bool& enable,
		const b2BodyDef& bodydef = b2BodyDef(),
		const b2PolygonShape& shape = b2PolygonShape(),
		b2FixtureDef& def = b2FixtureDef(),
		const bool& isTrigger = false);
	void AddForce(fVector2& _force);
	void AddLinearImpulse(fVector2& _force);
	void SetAlphaColor(uint8_t r, uint8_t g, uint8_t b);
	virtual void Update();
	inline fVector2 getCenter() { return (size) / 2; }
	std::string name;
	std::vector<std::vector<SDL_Surface*>> spriteSheets;
	float rotAngle = 0;
	float angle = 0;
	fVector2 pos;
	fVector2 size;
	b2Body* charBody = nullptr;
	b2PolygonShape bodyShape;

protected:
	virtual void OnCollisionEnter();
	virtual void OnCollisionExit();
	virtual void OnCollisionStay();
	bool isFlipped = false;
	int life;
	int currentSpriteSheet = 0;
	int currentSpriteIndex = 0;
	bool justCollisioned = false;
	SDL_Rect* posValues = NULL;
	SDL_Rect* clipping = NULL;
	SDL_RendererFlip flip;
	SDL_Point* center;
	int counter = 0;
private:
	void EnablePhys2D(const bool& enable,
		const b2BodyDef& bodydef = b2BodyDef(),
		const b2PolygonShape& shape = b2PolygonShape(),
		b2FixtureDef& def = b2FixtureDef(),
		const bool& isTrigger = false);
	void SetTransform();
	void MoveBase(fVector2& _newPos);
	void AddLinearImpulseBase(fVector2& _force);
	void AddForceBase(fVector2& _newPos);

};

