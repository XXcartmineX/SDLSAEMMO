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
	void Move(fVector2& _newPos);
	void EnablePhysics2D(const bool& enable,
		const b2BodyDef& bodydef = b2BodyDef(),
		const b2PolygonShape& shape = b2PolygonShape(),
		b2FixtureDef& def = b2FixtureDef(),
		const bool& isTrigger = false);
	void AddForce(fVector2& _force);
	void AddLinearImpulse(fVector2& _force);
	void KeepAwake(const bool& _val);
	void SetAlphaColor(uint8_t r, uint8_t g, uint8_t b);
	void SetType(b2BodyType type);
	void SetGravity(const float& gravity);
	void SetPosition(const fVector2& _pos);
	bool isCollisioningWithother(Character* const& other);
	inline bool getFlip() { return isFlipped; }
	virtual void Update();
	inline fVector2 getCenter() { return (size) / 2; }
	inline bool getIsRendering() { return isRendering; }
	std::string name;
	std::vector<std::vector<SDL_Surface*>> spriteSheets;
	int ID = 0,
		ctMap = 0,
		matricula = 0,
		lvl = 0,
		Exp = 0,
		maxLife = 0,
		life = 0,
		currWeap = 0,
		armour = 0,
		logic = 0,
		luck = 0,
		art = 0,
		imagination = 0,
		maxAttack = 0,
		health = 0;
	float rotAngle = 0;
	float angle = 0;
	fVector2 pos;
	fVector2 size;
	std::string spriteFileName = "",
				clss = "",
				pwd = "";
	b2Body* charBody = nullptr;
	b2PolygonShape bodyShape;
	Character* parent = nullptr;

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
	void KeepAwakeBase(const bool& _val);
	void SetTypeBase(b2BodyType type);
	void SetGravityBase(const float& gravity);
	void SetPositionBase(fVector2& _pos);
	bool isRendering = false;

};

